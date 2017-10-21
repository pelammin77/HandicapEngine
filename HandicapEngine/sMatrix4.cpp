#include"sMatrix4.h"

sMatrix4::sMatrix4()
{
	

	for (int i = 0; i < 4 * 4; i++)
		items[i] = 0.0f;

	
}

sMatrix4::sMatrix4(float diagonal)
{
	for (int i = 0; i < 4 * 4; i++)
		items[i] = 0.0f;
		
	items[0 + 0 * 4] = diagonal;
	items[1 + 1 * 4] = diagonal;
	items[2 + 2 * 4] = diagonal;
	items[3 + 3 * 4] = diagonal;

}

sMatrix4 sMatrix4::identity()
{
	return sMatrix4(1.0f);
}

sMatrix4 sMatrix4::orthogonal(float left, float right, float bottom, float top, float near, float far)
{
	sMatrix4 result(1);
	result.items[0 + 0 * 4 ] =  2.0f / (right - left);					
	result.items[1 + 1 * 4 ] = 2.0f / (top - bottom);                 
	result.items[2 + 2 * 4] = 2.0f / (near - far);						

	result.items[0 + 3 * 4] = (left + right) / (left - right);         
	result.items[1 + 3 * 4] = (bottom + top) / (bottom - top);         
	result.items[2 + 3 * 4] = (far + near) / (far - near);            
	
   //result.items[3 + 3 * 4] = 1;

	return result;
}

sMatrix4 sMatrix4::perspective(float fov, float aspectRatio, float near, float far )
{   
	sMatrix4 result(1);
	float q = 1.0f / tan(to_Radian(0.5f * fov));
	float a = q / aspectRatio;
	float b = (near + far) / (near - far);
	float c = (2.0f * near * far) / (near - far);
	
	result.items[0 + 0 * 4] =  a;
	result.items[1 + 1 * 4] =  q;
	result.items[2 + 2 * 4] =  b;
	result.items[3 + 2 * 4] = -1;
	result.items[2 + 3 * 4] =  c;

	return result;
}

sMatrix4 sMatrix4::transilation(const sVector3 & trans)
{
	sMatrix4 result(1);

	result.items[0 + 3 * 4] = trans.x;
	result.items[1 + 3 * 4] = trans.y;
	result.items[2 + 3 * 4] = trans.z;
	return result;
}

sMatrix4 sMatrix4::rotation(float angle, const sVector3 & axs)
{
	sMatrix4 result(1);
	float r = to_Radian(angle);
	float c = cos(r);
	float s = sin(r); 
	float omc = 1.0f - c; 

	float x = axs.x;
	float y = axs.y;
	float z = axs.z;

	result.items[0 + 0 * 4] = x * omc + c;
	result.items[1 + 0 * 4] = y * x * omc + z * s;
	result.items[2 + 0 * 4] = x * z * omc - y * s;

	result.items[0 + 1 * 4] = x * y + omc - z * s;
	result.items[1 + 1 * 4] = y * omc + c;
	result.items[2 + 1 * 4] = y * z * omc + x *s;

	result.items[0 + 2 * 4] = x * z * omc + y * s ;
	result.items[1 + 2 * 4] = y * z * omc - x * s;
	result.items[2 + 2 * 4] = z * omc + c;
	
		

	return result;
}

sMatrix4 sMatrix4::scale(const sVector3 & scale)
{
	sMatrix4 result(1);
	result.items[0 + 0 * 4] = scale.x;
	result.items[1 + 1 * 4] = scale.y;
	result.items[2 + 2 * 4] = scale.z;

	return result;
}

sMatrix4 & sMatrix4::multifly(const sMatrix4 & mat)
{
	for(int row = 0; row < 4; row++)
	{
		for (int col = 0; col < 4; col++)
		{
			float sum = 0.0f;
			for (int item = 0; item < 4; item++)
			{

				sum += items[col + item * 4] * mat.items[item + row * 4];
			}
			items[col + row * 4] = sum;
		}
	}
	return *this;
}


sMatrix4 & sMatrix4::operator*=(const sMatrix4 & secomdMat)
{
	return multifly(secomdMat);
}

sMatrix4 operator*(sMatrix4 left, const sMatrix4 & right)
{
	return left.multifly(right);
}

std::ostream & operator<<(std::ostream & out, const sMatrix4 & mat)
{

	out << "MAT 4:{"<<std::endl;
	   
	for (int i = 0; i < 4 * 4; i++)
	{
		
			if (i == 4||i==8||i==12||i==16) out <<std::endl;
		out << mat.items[i] << ", ";
	}
	

	out << "}";
	return out;
}

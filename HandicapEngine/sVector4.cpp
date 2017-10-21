#include"sVector4.h"

#include"sVector4.h"

sVector4::sVector4()
{
	x = 0;
	y = 0;
	z = 0;
	w = 0;
}

sVector4::sVector4(const float & aX, const float & aY, const float & aZ, const float& aW)
{
	x = aX;
	y = aY;
	z = aZ;
	w = aW;
}

sVector4 & sVector4::add(const sVector4 & secondVec)
{
	this->x += secondVec.x;
	this->y += secondVec.y;
	this->z += secondVec.z;
	this->w += secondVec.w;
	return *this;
}

sVector4 & sVector4::subtract(const sVector4 & secondVec)
{
	this->x -= secondVec.x;
	this->y -= secondVec.y;
	this->z -= secondVec.z;
	this->w -= secondVec.w;
	return *this;
}

sVector4 & sVector4::multiply(const sVector4 & secondVec)
{
	this->x *= secondVec.x;
	this->y *= secondVec.y;
	this->z *= secondVec.z;
	this->w *= secondVec.w;
	return *this;
}

sVector4 & sVector4::devide(const sVector4 & secondVec)
{
	this->x /= secondVec.x;
	this->y /= secondVec.y;
	this->z /= secondVec.z;
	this->w /= secondVec.w;
	return *this;
}

sVector4 & sVector4::operator+=(const sVector4 & secomdVec)
{
	return add(secomdVec);
}

sVector4 & sVector4::operator-=(const sVector4 & secomdVec)
{
	return devide(secomdVec);
}

sVector4 & sVector4::operator*=(const sVector4 & secomdVec)
{
	return multiply(secomdVec);
}

sVector4 & sVector4::operator/=(const sVector4 & secomdVec)
{
	return devide(secomdVec);
}

bool sVector4::operator==(const sVector4 & secondVec)
{
	return x == secondVec.x && y == secondVec.y && z == secondVec.z && w ==secondVec.w;

}

bool sVector4::operator!=(const sVector4 & secondVec)
{
	return !(*this == secondVec);
}





sVector4  operator+(sVector4  left, const sVector4 & right)
{
	return left.add(right);
}

sVector4  operator-(sVector4  left, const sVector4 & right)
{
	return left.subtract(right);
}

sVector4  operator*(sVector4  left, const sVector4 & right)
{
	return left.multiply(right);
}

sVector4  operator/(sVector4  left, const sVector4 & right)
{
	return left.devide(right);
}

std::ostream & operator<<(std::ostream & out, const sVector4 & vector)
{
	out << "vector4(" << vector.x << ",  " << vector.y << ", " << vector.z << ", " << vector.w <<")";
	return out;
}

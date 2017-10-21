#include"sVector3.h"

sVector3::sVector3()
{
	x = 0;
	y = 0;
	z = 0;

}

sVector3::sVector3(const float & aX, const float & aY, const float & aZ)
{
	x = aX;
	y = aY;
	z = aZ;
}

sVector3 & sVector3::add(const sVector3 & secondVec)
{
	this->x += secondVec.x;
	this->y += secondVec.y;
	this->z += secondVec.z;
	return *this;
}

sVector3 & sVector3::subtract(const sVector3 & secondVec)
{
	this->x -= secondVec.x;
	this->y -= secondVec.y;
	this->z -= secondVec.z;
	return *this;
}

sVector3 & sVector3::multiply(const sVector3 & secondVec)
{
	this->x *= secondVec.x;
	this->y *= secondVec.y;
	this->z *= secondVec.z;
	return *this;
}

sVector3 & sVector3::devide(const sVector3 & secondVec)
{
	this->x /= secondVec.x;
	this->y /= secondVec.y;
	this->z /= secondVec.z;
	return *this;
}

sVector3 & sVector3::operator+=(const sVector3 & secomdVec)
{
	return add(secomdVec);
}

sVector3 & sVector3::operator-=(const sVector3 & secomdVec)
{
	return devide(secomdVec);
}

sVector3 & sVector3::operator*=(const sVector3 & secomdVec)
{
	return multiply(secomdVec);
}

sVector3 & sVector3::operator/=(const sVector3 & secomdVec)
{
   return devide(secomdVec);
}

bool sVector3::operator==(const sVector3 & secondVec)
{
	return x == secondVec.x && y == secondVec.y && z == secondVec.z;

}

bool sVector3::operator!=(const sVector3 & secondVec)
{
	return !(*this == secondVec);
}





sVector3  operator+(sVector3  left, const sVector3 & right)
{
	return left.add(right);
}

sVector3  operator-(sVector3  left, const sVector3 & right)
{
	return left.subtract(right);
}

sVector3  operator*(sVector3  left, const sVector3 & right)
{
	return left.multiply(right);
}

sVector3  operator/(sVector3  left, const sVector3 & right)
{
	return left.devide(right);
}

std::ostream & operator<<(std::ostream & out, const sVector3 & vector)
{
	out << "vector3(" << vector.x << ",  " << vector.y << ", "<<vector.z<<  ")";
	return out;
}

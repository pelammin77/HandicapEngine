#include"sVector2.h"

sVector2::sVector2()
{
	x = 0.0f;
	y = 0.0f;
}

sVector2::sVector2(const float & aX, const float & aY)
{
	this->x = aX;
	this->y = aY;
}

sVector2 & sVector2::add(const sVector2 & secondVec)
{
	this-> x += secondVec.x;
	this-> y += secondVec.y;
	return *this;
}

sVector2 & sVector2::subtract(const sVector2 & secondVec)
{
	this-> x -= secondVec.x;
	this-> y -= secondVec.y;
	return *this;
}

sVector2 & sVector2::multiply(const sVector2 & secondVec)
{
	this->x *= secondVec.x;
	this->y *= secondVec.y;
	return *this;
}

sVector2 & sVector2::devide(const sVector2 & secondVec)
{
	this->x /= secondVec.x;
	this->y /= secondVec.y;
	return *this;
}

sVector2 & sVector2::operator+=(const sVector2 & secomdVec)
{
	return add(secomdVec);
}

sVector2 & sVector2::operator-=(const sVector2 & secomdVec)
{
	return devide(secomdVec);
}

sVector2 & sVector2::operator*=(const sVector2 & secomdVec)
{
	return multiply(secomdVec);
}

sVector2 & sVector2::operator/=(const sVector2 & secomdVec)
{
	return devide(secomdVec);
}

bool sVector2::operator==(const sVector2 & secondVec)
{
	return x == secondVec.x && y == secondVec.y;		
	/*
	Old if version:
	if (x == secondVec.x && y == secondVec.y)
	{return true;}
	return false;
	*/
}

bool sVector2::operator!=(const sVector2 & secondVec)
{
	return x != secondVec.x && y != secondVec.y;
}




sVector2  operator+(sVector2  left, const sVector2 & right)
{
	return left.add(right);
}

sVector2  operator-(sVector2  left, const sVector2 & right)
{
	return left.subtract(right);

}

sVector2  operator*(sVector2  left, const sVector2 & right)
{
	return left.multiply(right);
}

sVector2  operator/(sVector2  left, const sVector2 & right)
{
	return left.devide(right);
}

std::ostream & operator<<(std::ostream & out, const sVector2 & vector)
{
	out << "vector2(" << vector.x << ", " << vector.y << ")";
	return out; 
}

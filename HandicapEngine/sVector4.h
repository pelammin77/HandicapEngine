#pragma once

#include<iostream>

struct  sVector4
{

	float x;
	float y;
	float z;
	float w;

	sVector4();
	sVector4(const float& aX, const  float& aY, const float& aZ, const float& aW);
	sVector4& add(const sVector4& secondVec);
	sVector4& subtract(const sVector4& secondVec);
	sVector4& multiply(const sVector4& secondVec);
	sVector4& devide(const sVector4& secondVec);


	sVector4& operator +=(const sVector4& secomdVec);
	sVector4& operator -=(const sVector4& secomdVec);
	sVector4& operator *=(const sVector4& secomdVec);
	sVector4& operator /=(const sVector4& secomdVec);

	bool operator ==(const sVector4& secondVec);
	bool operator !=(const sVector4& secondVec);



	friend sVector4 operator +(sVector4 left, const sVector4& right);
	friend sVector4 operator -(sVector4 left, const sVector4& right);
	friend sVector4 operator *(sVector4 left, const sVector4& right);
	friend sVector4 operator /(sVector4 left, const sVector4& right);

	//stream operator 
	friend std::ostream& operator<<(std::ostream& out, const sVector4& vector);



};

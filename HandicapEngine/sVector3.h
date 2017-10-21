#pragma once
#include<iostream>

struct  sVector3
{

	float x;
	float y;
	float z;

	sVector3();
	sVector3(const float& aX, const  float& aY, const float& aZ);
	sVector3& add(const sVector3& secondVec);
	sVector3& subtract(const sVector3& secondVec);
	sVector3& multiply(const sVector3& secondVec);
	sVector3& devide(const sVector3& secondVec);


	sVector3& operator +=(const sVector3& secomdVec);
	sVector3& operator -=(const sVector3& secomdVec);
	sVector3& operator *=(const sVector3& secomdVec);
	sVector3& operator /=(const sVector3& secomdVec);

	bool operator ==(const sVector3& secondVec);
	bool operator !=(const sVector3& secondVec);



	friend sVector3 operator +(sVector3 left, const sVector3& right);
	friend sVector3 operator -(sVector3 left, const sVector3& right);
	friend sVector3 operator *(sVector3 left, const sVector3& right);
	friend sVector3 operator /(sVector3 left, const sVector3& right);

	//stream operator 
	friend std::ostream& operator<<(std::ostream& out, const sVector3& vector);



};


//Operators 


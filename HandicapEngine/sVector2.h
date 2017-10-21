#pragma once
#include<iostream>
struct sVector2
{
	
	float x;
	float y;

	sVector2();
	sVector2( const float& aX, const  float& aY);
	sVector2& add(const sVector2& secondVec);
	sVector2& subtract(const sVector2& secondVec);
	sVector2& multiply(const sVector2& secondVec);
	sVector2& devide(const sVector2& secondVec);
	
	//Operators 


	sVector2& operator +=(const sVector2& secomdVec);
	sVector2& operator -=(const sVector2& secomdVec);
	sVector2& operator *=(const sVector2& secomdVec);
	sVector2& operator /=(const sVector2& secomdVec);
	bool operator ==(const sVector2& secondVec);
	bool operator !=(const sVector2& secondVec);

    //outside the class friends
	friend sVector2 operator +(sVector2 left, const sVector2& right);
	friend sVector2 operator -(sVector2 left, const sVector2& right); 
	friend sVector2 operator *(sVector2 left, const sVector2& right);
	friend sVector2 operator /(sVector2 left, const sVector2& right);
    
	//stream operator 
	friend std::ostream& operator<<(std::ostream& out, const sVector2& vector);
	

		

};
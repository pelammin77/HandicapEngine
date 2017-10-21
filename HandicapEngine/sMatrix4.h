#pragma once
#include"Maths.h"

struct sMatrix4
{
	float items[4 * 4];

	sMatrix4();
	sMatrix4(float diagonal);
	
	static sMatrix4 identity();
	static sMatrix4 orthogonal(float left, float right, float bottom, float top, float near, float far );  // creates orthogonal matrix 
	static sMatrix4 perspective(float fov, float aspectRatio, float near, float far);
	
	static sMatrix4 transilation(const sVector3& trans);
	static sMatrix4 rotation(float angle, const sVector3& axs);
	static sMatrix4 scale(const sVector3& scale);



	sMatrix4& multifly( const sMatrix4 &mat);
	friend sMatrix4 operator *(sMatrix4 left, const sMatrix4& right);
	sMatrix4& operator *=(const sMatrix4& secomdMat);

	friend std::ostream& operator<<(std::ostream& out, const sMatrix4& mat);
};
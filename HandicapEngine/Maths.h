#pragma once

#include"sVector2.h"
#include"sVector3.h"
#include"sVector4.h"
#include"sMatrix4.h"
#include<math.h>
const double pi = 3.14159265358;


inline float to_Radian( const float degree)
{

	return degree * (pi / 180.0f);
	 
}
#include "pch.h"
#include "HEMMath.h"

using namespace lib;

bool CHEMMath::IsZero(double val, double epsilon)
{
	return fabs(val) < epsilon;
}

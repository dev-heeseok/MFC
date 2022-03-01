#include "pch.h"
#include "HEMath.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

using namespace lib;

bool CHEMath::IsZero(double val, double epsilon)
{
	return fabs(val) < epsilon;
}

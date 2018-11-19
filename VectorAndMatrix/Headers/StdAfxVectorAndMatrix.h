#pragma once

#ifdef _CLI_
	#ifdef WIN32
		#define _DLLEXPORT_  __declspec(dllexport)
	#endif // WIN32
#else
	#define _DLLEXPORT_
#endif // _CLI_

#include "StdAfxError.h"
#include "cGSLVector.h"
#include "cGSLMatrix.h"

#define WIN32_LEAN_AND_MEAN             // Exclure les en-têtes Windows rarement utilisés


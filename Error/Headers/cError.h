#ifndef _CERROR_H_
#define _CERROR_H_
/*!
	\file cError.h
	\brief Header for error class declarations
*/
#include "StdAfxError.h"
using namespace std ;


namespace ErrorNameSpace
{
#ifndef NULL
	#define NULL 0
#endif // NULL



	/*!
		\class cError
		\brief Only used to exit program with an output message
	*/

	class cError
	{
		public :
		cError(const char* theMess) ;
		cError(const string& theMess) ;
	} ;
	}
#endif //_CERROR_H_


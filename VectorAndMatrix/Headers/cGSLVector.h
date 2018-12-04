#pragma once
#ifndef _cGSLVector_H_
#define _cGSLVector_H_
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cfloat>
#include <iostream>
#include <ostream>
#include <gsl/gsl_vector.h>
#include <gsl/gsl_linalg.h> 

/*!
	\file cGSLVector.h
	\brief header for C++ encapsulation of GSL vectors definitions and functions.
	\author Ollivier TARAMASCO 
	\date oct-09-2008
*/


// POUR DEBOGUER
#ifdef _MESS_CREAT
	#ifdef _DEBUG
		#define MESS_CREAT(p)  std::cout << "creation de " << p << std::endl ; 
		#define MESS_DESTR(p)  std::cout << "destruction de " << p << std::endl ; 
	#else
		#define MESS_CREAT(p) ///< used for debugging 
		#define MESS_DESTR(p) ///< used for debugging
	#endif //_DEBUG
#else
	#define MESS_CREAT(p) ///< used for debugging
	#define MESS_DESTR(p) ///< used for debugging
#endif //MESS_CREAT

#ifndef _WIN32
	#include <sys/types.h>
#endif // Pour avoir le type uint sous autre chose que MSVS

using namespace ErrorNameSpace ;

namespace VectorAndMatrixNameSpace{
	#ifdef _WIN32
		typedef unsigned int uint ;
	#endif

		class cGSLMatrix ;

		/*!
			\brief class cGSLVector
			\par
			1) Encapsulation of the "C" gsl structure gsl_vector
			2) Standard and usefull vector operations declarations
		*/	

		class _DLLEXPORT_ cGSLVector
		{
		private :
				gsl_vector* mvVect ; ///< data
		public :
			cGSLVector(int theSize = 0, double theVal = 0.0) ; ///< standard constructor
			cGSLVector(int theSize, double* theVect) ;///< mVect := theVect
			cGSLVector(const gsl_vector* theVect) ;///< mVect := theVect
			cGSLVector(const cGSLVector& theVect) ;///< mVect := theVect
			virtual ~cGSLVector() ;///< std destructor
			double& operator[](int theIndex) const ;///< returns mvect[theIndex]
			uint GetSize(void) const ;///< size of mVect
			gsl_vector* GetGSLVector(void) const ;///< returns mVect
			gsl_vector* GetVector(void) const ; ///< returns mVect
			void Delete(void) ;///< Destructor
			void ReAlloc(int theSize, double theVal=0.0) ;///< Reallocation and initialisation of mVect
			void ReAlloc(int theSize, double* theVect) ;///< Reallocation and initialisation of mVect
			void ReAlloc(const cGSLVector& theVect) ;///< Reallocation and initialisation of mVect
			void ReAlloc(const gsl_vector* theVect) ;///< Reallocation and initialisation of mVect
			cGSLVector& operator =(const cGSLVector& theSrcVect) ; ///< *this = theSrcVect
			cGSLVector& operator =(double theVal) ;///< *this[i] = theVal for all i 
			cGSLVector& operator =(double* theSrcVect) ;///< *this = theSrcVect
			cGSLVector& operator =(const cGSLMatrix& theMatrix) ;///< *this = theSrcVect
			cGSLVector& operator +=(const cGSLVector& theSrcVect) ;///< *this += theSrcVect
			cGSLVector& operator +=(double theVal) ;///< *this[i] += theVal for all i 
			cGSLVector& operator +=(double* theSrcVect) ;///<*this[i] += theSrcVect[i] for all i 
			cGSLVector& operator -=(const cGSLVector& theSrcVect) ;///< *this -= theSrcVect
			cGSLVector& operator -=(double theVal) ;///< *this[i] -= theVal for all i 
			cGSLVector& operator -=(double* theSrcVect) ;///< *this -= theSrcVect
			cGSLVector& operator *=(double theVal) ;///< *this *= theVal
			cGSLVector& operator /=(double theVal) ;///< *this /= theVal
			void SetThisWithSubVector(const cGSLVector& theSrcVect, uint theBegIndex) ;///< *this[i] = theSrcVect[i+theBegIndex] for all i
			void SetSubVectorWithThis(cGSLVector& theDestVect, uint theBegIndex) ;///< theDestVect[i+theBegIndex]=*this[i] for all i
			cGSLVector& operator +(double theVal) ;///< returns *this[i]+theVal for all i
			cGSLVector& operator +(const cGSLVector& theVect) ;///< returns *this[i]+theVect[i] for all i
			cGSLVector& operator +(double* theVect2) ;///< returns *this + theVect2
			cGSLVector& operator -(double theVal) ;///< returns theVect[i]-theVal for all i
			cGSLVector& operator -(const cGSLVector& theVect) ;///< returns *this[i]-theVect[i] for all i
			cGSLVector& operator -(double* theVect2) ;///< returns *this - theVect2
			cGSLVector& operator *(double theVal) ;///< returns theVal*theVect
			cGSLVector& operator /(double theVal) ;/// returns theVal/theVect[i] for all i
			void Print(std::ostream& theStream=std::cout) ;
			friend double _DLLEXPORT_ Norm (const cGSLVector& theVect) ;///< euclidian norm
			friend double _DLLEXPORT_ Sum(const cGSLVector& theVect) ; ///< sum
			friend _DLLEXPORT_ std::ostream& operator <<(std::ostream& theStream, const cGSLVector& theVect) ; ///< prints mVect	
			friend _DLLEXPORT_ cGSLVector operator +(double theVal, const cGSLVector& theVect) ;///< returns theVect[i]+theVal for all i
			friend _DLLEXPORT_ cGSLVector operator +(const cGSLVector& theVect1, double* theVect2) ;///< returns theVect1 + theVect2
			friend _DLLEXPORT_ cGSLVector operator -(double theVal, const cGSLVector& theVect) ;///< returns theVal-theVect[i] for all i
			friend _DLLEXPORT_ cGSLVector operator -(double* theVect1, const cGSLVector& theVect2) ;///< returns theVect1 - theVect2
			friend _DLLEXPORT_ cGSLVector operator *(double theVal, const cGSLVector& theVect) ;///< returns theVal*theVect
			friend _DLLEXPORT_ cGSLVector operator /(double theVal, const cGSLVector& theVect) ;/// returns theVal/theVect[i] for all i
		} ;
}

#endif //_cGSLVector_H_

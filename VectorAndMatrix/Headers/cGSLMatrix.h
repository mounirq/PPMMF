#pragma once 
#ifndef _cGSLMatrix_H_
#define _cGSLMatrix_H_
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cfloat>
#include <iostream>
#include <gsl/gsl_matrix.h>
#include <gsl/gsl_linalg.h> 

/*!
	\file cGSLMatrix.h
	\brief Header fo C++ encapsulation of GSL matrix definitions and functions.
	
	\par Details.
	\par uses gsl_matrix.
	\author Ollivier TARAMASCO 
	\date oct-09-2008
*/

#ifndef MIN_DBLE
	#define MIN_DBLE DBL_EPSILON
#endif //MIN_DBLE


namespace VectorAndMatrixNameSpace
{

		/*!
			\brief class cGSLMatrix
			\par
			1) Encapsulation of the "C" gsl structure gsl_matrix \par
			2) Standard and usefull matrix operations declarations
		*/	

		using namespace ErrorNameSpace ;
		class cGSLVector ;
		class _DLLEXPORT_ cGSLMatrix
		{
		private :
			gsl_matrix*		mvMat ; ///< data
		public :
			cGSLMatrix(int theNRow=0, int theNCol=0, double theVal = 0.0L) ; ///< standard constructor
			cGSLMatrix(const cGSLVector& theVect) ; ///< constructor
			cGSLMatrix(const cGSLMatrix& theMat) ; ///< constructor
			virtual ~cGSLMatrix() ; ///< standard destructor
			uint GetNRow(void) const ; ///< returns matrix number of rows
			uint GetNCol(void) const ; ///< returns matrix number of columns
			gsl_matrix* GetMat(void) {return mvMat ;}
			void Delete(void) ; ///< Deletes matrix
			void ReAlloc(uint theNRow, uint theNCol, double theVal = 0.0L) ; ///< Reallocates matrix
			void ReAlloc(const cGSLVector& theVect) ; ///< Reallocates matrix
			void ReAlloc(const cGSLMatrix& theMat) ; ///< Reallocates matrix
			double* operator[](int theNRow) const ; ///< Returns address of matrix[theNRow]
			cGSLMatrix& operator =(const cGSLMatrix& theSrcMat) ; ///< Standard matrix affectation
			cGSLMatrix& operator =(const cGSLVector& theVect) ; ///< one column matrix affectation
			cGSLMatrix& operator =(double theVal) ; ///< matrix[i,j] = theVal
			cGSLMatrix& operator +=(const cGSLMatrix& theMatrix) ; ///< Standard += operation
			cGSLMatrix& operator +=(double theVal) ; ///< matrix[i,j] += theVal
			cGSLMatrix& operator -=(const cGSLMatrix& theMatrix) ; ///< Standard -= operation
			cGSLMatrix& operator -=(double theVal) ; ///< matrix[i,j] -= theVal
			cGSLMatrix& operator *=(const cGSLMatrix& theRight) ; ///< Standard *= operation
			cGSLMatrix& operator *=(double theLambda) ; ///< matrix[i,j] *= theVal
			cGSLMatrix& operator /=(double theLambda) ; ///< matrix[i,j] /= theVal
			void Print(std::ostream& theStream=std::cout) ;
			friend _DLLEXPORT_ cGSLMatrix operator +(const cGSLMatrix& theLeft, const cGSLMatrix &theRight) ; ///< Standard + operation
			friend _DLLEXPORT_ cGSLMatrix operator +(double theVal, const cGSLMatrix &theRight) ;
			friend _DLLEXPORT_ cGSLMatrix operator +(const cGSLMatrix &theLeft, double theVal) ;
			friend _DLLEXPORT_ cGSLMatrix operator -(const cGSLMatrix& theLeft, const cGSLMatrix &theRight) ;
			friend _DLLEXPORT_ cGSLMatrix operator -(double theVal, const cGSLMatrix &theRight) ;
			friend _DLLEXPORT_ cGSLMatrix operator -(const cGSLMatrix &theLeft, double theVal) ;
			friend _DLLEXPORT_ cGSLMatrix operator *(const cGSLMatrix& theLeft, const cGSLMatrix &theRight) ;
			friend _DLLEXPORT_ cGSLVector operator *(const cGSLMatrix& theLeft, const cGSLVector& theVect) ;
			friend _DLLEXPORT_ cGSLMatrix operator *(const cGSLVector& theVect, const cGSLMatrix& theRight) ;
			friend _DLLEXPORT_ cGSLMatrix operator *(const cGSLMatrix& theMat, double theLambda) ;
			friend _DLLEXPORT_ cGSLMatrix operator *(double theLambda, const cGSLMatrix& theMat) ;
			friend _DLLEXPORT_ cGSLMatrix operator /(const cGSLMatrix& theMat, double theLambda) ;
			friend _DLLEXPORT_ cGSLMatrix Zeros(uint theN, uint theP) ;
			friend _DLLEXPORT_ cGSLMatrix Identity(uint theN) ;
			friend _DLLEXPORT_ cGSLMatrix Diag(const cGSLVector& theVect) ;
		#ifdef _RDLL_
			friend void _DLLEXPORT_ LapackInvAndDet(const cGSLMatrix &theMatrix, cGSLMatrix &theInvMatrix, double& theDet) ;
		#else
			friend void _DLLEXPORT_ Svd(const cGSLMatrix& theMatrix, cGSLMatrix& theU, cGSLVector& theS, cGSLMatrix& theV) ;
		#endif // _RDLL_
			friend _DLLEXPORT_ cGSLMatrix Inv(const cGSLMatrix &theMatrix) ;
			friend _DLLEXPORT_ void ClearMatrix(cGSLMatrix& theMatrix) ;
			friend _DLLEXPORT_ std::ostream& operator <<(std::ostream& theStream, const cGSLMatrix& theMat) ;
			friend _DLLEXPORT_ cGSLMatrix Transpose(const cGSLMatrix& theMatrix) ;
			friend _DLLEXPORT_ cGSLMatrix Transpose(const cGSLVector& theVector) ;
		} ;

}
#endif // _cGSLMatrix_H_


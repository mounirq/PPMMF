#pragma once 
#ifndef _CMA_H_
#define _CMA_H_

#include "cAbstCondMean.h"
#include "cRegArchValue.h"
#include "cRegArchGradient.h"

/*!
	\file cMa.h
	\brief header for class cMa.
	\author Jean-Baptiste DURAND, Ollivier TARAMASCO
	\date dec-18-2006 - Last change feb-18-2011
*/
namespace RegArchLib {
	/*! 
	 * \class cMa
	 * \brief  Class to implement an MA model
	 */
	class _DLLEXPORT_ cMa: public cAbstCondMean
	{
	private :
		cDVector mvMa ;
	public :
		cMa(uint theNMa = 0) ; ///< A simple constructor
		cMa(const cDVector& theMa) ; ///< Another constructor
		virtual ~cMa() ;  ///< A simple destructor
		virtual cAbstCondMean* PtrCopy() const ; /// < Return a copy of *this
		void Delete(void) ; ///< Free memory
		void Print(ostream& theOut=cout) const ; ///< Print the parameters
		void ReAlloc(uint theSize, uint theNumParam=0) ; ///< Allocation of the model parameters
		void ReAlloc(const cDVector& theVectParam, uint theNumParam=0) ; ///< Allocation of the model parameters
		void Set(double theValue, uint theIndex=0, uint theNumParam=0) ; ///< Set model parameters.
		void Set(const cDVector& theVectParam, uint theNumParam=0) ; ///< Set model parameters.
		double Get(uint theIndex=0, uint theNumParam=0) ;
		cAbstCondMean& operator=(cAbstCondMean& theSrc) ; ///< Standard affectation
		double ComputeMean(uint theDate, const cRegArchValue& theData) const ; /// Compute the conditional mean value
		uint GetNParam(void) const ;
		uint GetNLags(void) const ;
		void ComputeGrad(uint theDate, const cRegArchValue& theData, cRegArchGradient& theGradData, uint theBegIndex, cAbstResiduals* theResiduals) ;
		void RegArchParamToVector(cDVector& theDestVect, uint theIndex) ;
		void VectorToRegArchParam(const cDVector& theSrcVect, uint theIndex = 0) ;
	protected :
		void copy(const cMa& theMa) ; /// < Copy attribute from instance
	} ;

}

#endif // _CMA_H_

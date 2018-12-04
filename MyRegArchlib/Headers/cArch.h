#pragma once 
#ifndef _CARCH_H_
#define _CARCH_H_

#include "cAbstCondVar.h"
#include "cRegArchValue.h"
#include "cRegArchGradient.h"

	/*!
		\file cArch.h
		\brief Definition of the ARCH(p) class
	
		\author Jean-Baptiste DURAND, Ollivier TARAMASCO 
		\date dec-18-2006 - last change nov-10-2009
	*/
namespace RegArchLib {
	/*! 
	 * \class cArch
	 * \brief Class to implement a 'pure' ARCH model
	 */
	class _DLLEXPORT_ cArch: public cAbstCondVar
	{
	private :
		double mvConst ; ///< Constant part of ARCH(p) variance model.
		cDVector mvArch ; ///< Vector of ARCH coefficients. 
	public :
		cArch(uint theNArch = 0) ; ///< A simple constructor
		virtual ~cArch() ; ///< A simple destructor
		virtual cAbstCondVar* PtrCopy() const ; /// < Return a copy of *this		
		void Delete(void) ; ///< Free memory
		void Print(ostream& theOut=cout) const ; ///< Print the ARCH(p) parameters
		void Set(double theValue, uint theIndex=0, uint theNumParam=0) ; ///< Set model parameters.
		void Set(const cDVector& theVectParam, uint theNumParam=0) ; ///< Set model parameters.
		double Get(uint theIndex=0, uint theNumParam=0) ;
		void ReAlloc(uint theSize, uint theNumParam=0) ; ///< Allocation of the model parameters
		void ReAlloc(const cDVector& theVectParam, uint theNumParam=0) ; ///< Allocation of the model parameters
		cAbstCondVar& operator=(cAbstCondVar& theSrc) ; ///< affectation operator for cArch
		double ComputeVar(uint theDate, const cRegArchValue& theData) const ; ///< Return conditional variance.
		uint GetNParam(void) const ;
		uint GetNLags(void) const ;
		void ComputeGrad(uint theDate, const cRegArchValue& theData, cRegArchGradient& theGradData, cAbstResiduals* theResiduals) ;
		void RegArchParamToVector(cDVector& theDestVect, uint theIndex) ;
		void VectorToRegArchParam(const cDVector& theSrcVect, uint theIndex = 0) ;
	private :
		void copy(const cArch& theArch) ; /// < Copy attribute from instance
		
	} ;
}

#endif // _CARCH_H_

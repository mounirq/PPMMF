#pragma once 
#ifndef _CCONSTCONDVAR_H_
#define _CCONSTCONDVAR_H_

#include "cAbstCondVar.h"
#include "cRegArchValue.h"
#include "cRegArchGradient.h"

/*!
	\file cConstCondVar.h
	\brief Definition of the constant variance class
	
	\author Jean-Baptiste DURAND, Ollivier TARAMASCO 
	\date dec-18-2006 - Last change feb-18-2011
*/
namespace RegArchLib {
	/*! 
	 * \class cConstCondVar
	 * \brief Class to implement a constant conditional variance model
	 */
	class _DLLEXPORT_ cConstCondVar: public cAbstCondVar
	{
	private :
		double mvCste ; //< Value of constant variance
	public :
		cConstCondVar(double theValue=1.0) ; ///< A simple constructor
		virtual ~cConstCondVar() ; ///< A simple destructor
		virtual cAbstCondVar* PtrCopy() const ; /// < Return a copy of *this		
		void Print(ostream& theOut) const ; ///< Print the parameters
		void Delete(void) ; ///< Delete
		void Set(double theValue, uint theIndex=0, uint theNumParam=0) ; ///< Set model parameters.
		void Set(const cDVector& theVectParam, uint theNumParam=0) ; ///< Set model parameters.
		double Get(uint theIndex=0, uint theNumParam=0) ;
		void ReAlloc(uint theSize, uint theNumParam=0) ; ///< Allocation of the model parameters
		void ReAlloc(const cDVector& theVectParam, uint theNumParam=0) ; ///< Allocation of the model parameters
		cAbstCondVar& operator=(cAbstCondVar& theSrc) ; ///< affectation operator for cConstCondVar
	
		double ComputeVar(uint theDate, const cRegArchValue& theData) const ; ///< Return conditional variance.
		uint GetNParam(void) const ;
		uint GetNLags(void) const ;
		void ComputeGrad(uint theDate, const cRegArchValue& theData, cRegArchGradient& theGradData, cAbstResiduals* theResiduals) ;
		void RegArchParamToVector(cDVector& theDestVect, uint theIndex) ;
		void VectorToRegArchParam(const cDVector& theSrcVect, uint theIndex = 0) ;
	private :
		void copy(const cConstCondVar& theCondVar) ; /// < Copy attribute from instance
	
	} ;
}
#endif //_CCONSTCONDVAR_H_

#pragma once 
#ifndef _CARCH_H_
#define _CARCH_H_

#include "cAbstCondVar.h"
#include "cRegArchValue.h"

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
		cDVector mvArch ; ///< Vector of ARCH coefficients. 
	public :
		cArch(uint theNArch = 0) ; ///< A simple constructor
		virtual ~cArch() ; ///< A simple destructor
		// Complete
		// PtrCopy() const ; /// < Return a copy of *this
		void Delete(void) ; ///< Free memory
		void Print(ostream& theOut=cout) const ; ///< Print the ARCH(p) parameters
		void Set(double theValue, uint theIndex=0, uint theNumParam=0) ; ///< Set model parameters.
		void Set(const cDVector& theVectParam, uint theNumParam=0) ; ///< Set model parameters.
		double Get(uint theIndex=0, uint theNumParam=0) ;
		void ReAlloc(uint theSize, uint theNumParam=0) ; ///< Allocation of the model parameters
		void ReAlloc(const cDVector& theVectParam, uint theNumParam=0) ; ///< Allocation of the model parameters
		// Complete source		
		double ComputeVar(uint theDate, const cRegArchValue& theData) const ; ///< Return conditional variance.
		uint GetNParam(void) const ; ///< Number of parameters in that model part
	private :
		void copy(const cArch& theArch) ; /// < Copy attribute from instance
	} ;
}

#endif // _CARCH_H_

#pragma once 
#ifndef _CCONDVAR_H_
#define _CCONDVAR_H_

#include "RegArchDef.h"
#include "cAbstCondVar.h"
#include "cRegArchValue.h"
#include <vector>

/*!
	\file cCondVar.h
	\brief Definition of conditional variance class model
	
	\author Jean-Baptiste DURAND, Ollivier TARAMASCO 
	\date dec-18-2006 - Last change nov-17-2014
*/


namespace RegArchLib {
	/*! 
	 * \class cCondVar
	 * \brief Class definition of a conditional variance model
	 * \details Conditional variance model is assumed to be a sum of 'elementary' conditional variance components.
	 * \f$ h(t,\,\theta) = \sum_{i=1}^{NVar}{h_i(t,\,\theta)}\f$
	 */
	class _DLLEXPORT_ cCondVar
	{
	private :
		uint			mvNCondVar	;  ///< Number of variance components
		std::vector<cAbstCondVar*>	mvCondVar ; ///< Vector of the mvNCondVar conditional variance components
	public :
		cCondVar(uint theNCondVar = 0) ; ///< A simple constructor
		cCondVar(const cCondVar& theCondVar) ;
		virtual ~cCondVar() ; ///< A simple destructor
		void Delete(void) ; ///< Free memory.
		uint GetNVar(void) const ; ///< Return the number of variance components.
		std::vector<cAbstCondVar*> GetCondVar(void) const ; ///< Return mvCondVar
		void SetOneVar(uint theWhatVar, eCondVarEnum theCode) ; ///< Set the type of a given variance component.
		void SetOneVar(uint theWhatVar, cAbstCondVar& theAbstCondVar) ; ///< Set theWhatVar th component of the conditional variance model
		cAbstCondVar* GetOneVar(uint theIndex) const ; ///< Return a pointer to the given variance component  (no object is allocated)
		void Print(ostream& theOut=cout) const ; ///< Print the conditional variance model
		friend ostream& operator <<(ostream& theOut, const cCondVar& theCondVar) ; ///< Print the conditional variance model
		void GetCondVarType(eCondVarEnum* theCodeType) const ; ///< Return the type of each variance component
		cCondVar& operator =(cCondVar& theSrc) ; ///< affectation operator
		// Complete source		
		double ComputeVar(uint theDate, const cRegArchValue& theData) const ; ///< Return conditional variance.
		/** Number of parameters in CondVar */
		uint GetNParam(void) const ;
		double Get(uint theNumVar=0, uint theIndex=0, uint theNumParam=0) ;
	} ;
}

#endif // _CCONDVAR_H_


#include "StdAfxRegArchLib.h"

/*!
 \file cNormResiduals.cpp
 \brief implementation of the class for N(0, 1) conditional distribution.

 \author Jean-Baptiste DURAND, Ollivier TARAMASCO
 \date dec-18-2006 - Last change feb-18-2011
*/
namespace RegArchLib {
	/*!
	 * \fn cNormResiduals::cNormResiduals(const cDVector* theDistrParameter, bool theSimulFlag):cAbstResiduals(eNormal, NULL, theSimulFlag)
	 * \param bool theSimulFlag: true if created for simulation
	 * \details: mvBool is initialised by cAbstResiduals constructor and theDistrParameter is never used.
	 */
	cNormResiduals::cNormResiduals(const cDVector* theDistrParameter, bool theSimulFlag):cAbstResiduals(eNormal, NULL, theSimulFlag)
	{
		MESS_CREAT("cNormResiduals")
	}

	/*!
	 * \fn cNormResiduals::~cNormResiduals
	 * \details: nothing to do here
	 */
	cNormResiduals::~cNormResiduals()
	{
		MESS_DESTR("cNormResiduals")
	}

	/*!
	 * \fn cAbstResiduals* cNormResiduals::::PtrCopy()
	 */

	cAbstResiduals* cNormResiduals::PtrCopy() const
	{
		// Complete
            bool theSimulFlag = this->mtR == NULL ? false : true;
            return new cNormResiduals(NULL, theSimulFlag);
	}

	/*!
	 * \fn void cNormResiduals::Print(ostream& theOut) const
	 * \param ostream& theOut: the output stream, default cout.
	 */
	void cNormResiduals::Print(ostream& theOut) const
	{
		theOut << "Conditional standardized normal distribution" << endl ;

	}
	/*!
	 * \fn void cNormResiduals::Generate(uint theNSample, cDVector& theYt) const 
	 * \brief Draw a sample of N(0, 1) residuals.
	 * \param uint theNSample: the sample size.
	 * \param cDVector& theYt: output parameter
	 * \details: theYt is reallocated to size theNSample here.
	 */
	
	void cNormResiduals::Generate(uint theNSample, cDVector& theYt) const 
	{
		// Completed	
            theYt.ReAlloc(theNSample, 0.);
            for (int i=0; i<theNSample; i++){
                theYt[i] = gsl_ran_gaussian(this->mtR, 1);
            }   
	}

	/*!
	 * \fn double cNormResiduals::LogDensity(double theX) const
	 * \param double theX: the point where density is computed.
	 * \brief Compute the log density of N(0, 1)
	 */
	double cNormResiduals::LogDensity(double theX) const
	{
		// Completed	
            return std::log(gsl_ran_gaussian_pdf(theX, 1));
	}

	/*!
	 * \fn double cNormResiduals::GetNParam(void)
	 * \param void.
	 * \brief return 0: no parameter for N(0,1) residuals.
	 */
	uint cNormResiduals::GetNParam(void) const
	{
		return 0 ;
	}


}//namespace

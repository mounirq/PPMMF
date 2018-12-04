#include "StdAfxRegArchLib.h"
/*!
 \file cStudentResiduals.cpp
 \brief implementation of the class for Student conditional distribution.

 \author Jean-Baptiste DURAND, Ollivier TARAMASCO
 \date dec-18-2006 - Last change feb-18-2011
*/
namespace RegArchLib {
	/*!
	 * \fn cStudentResiduals::cStudentResiduals(double theDof, bool theSimulFlag)
	 * \param double theDof: number of degrees of freedom 
	 * \param bool theSimulFlag: true if created for simulation
	 * \details: mvBool is initialised by ce cAbstResiduals constructor
	 */
	cStudentResiduals::cStudentResiduals(double theDof, bool theSimulFlag): cAbstResiduals(eStudent, NULL, theSimulFlag)
	{
		mDistrParameter.ReAlloc(1) ;
		mDistrParameter[0] = theDof ;
		MESS_CREAT("cStudentResiduals")
	}

	/*!
	 * \fn cStudentResiduals::cStudentResiduals(const cDVector* theDistrParameter, bool theSimulFlag): cAbstResiduals(eStudent, theDistrParameter, theSimulFlag)
	 * \param const cDVector* theDistrParameter: theDistrParameter[0] = d.o.f.
	 * \param bool theSimulFlag: true if created for simulation
	 * \details: mvBool is initialised by ce cAbstResiduals constructor
	 */
	cStudentResiduals::cStudentResiduals(cDVector* theDistrParameter, bool theSimulFlag): cAbstResiduals(eStudent, theDistrParameter, theSimulFlag)
	{
		MESS_CREAT("cStudentResiduals")
	}

	/*!
	 * \fn cStudentResiduals::~cStudentResiduals()
	 */
	cStudentResiduals::~cStudentResiduals() 
	{
		MESS_DESTR("cStudentResiduals")
	}

	/*!
	 * \fn cAbstCondVar* cNormResiduals::::PtrCopy()
	 */

	cAbstResiduals* cStudentResiduals::PtrCopy() const
	{
		cStudentResiduals *mycStudentResiduals = NULL ;
		cDVector* myDistrParameter = new cDVector(mDistrParameter) ;

		bool mySimulFlag = false ;

		if (mtR != NULL)
			mySimulFlag = true ;

		mycStudentResiduals = new cStudentResiduals(myDistrParameter, mySimulFlag);

		delete myDistrParameter ;

		return mycStudentResiduals ;
	}

	/*!
	 * \fn void cStudentResiduals::Generate(uint theNSample, cDVector& theYt) const
	 * \param uint theNSample: the sample size
	 * \param cDVector& theYt: the output vector
	 */
	void cStudentResiduals::Generate(uint theNSample, cDVector& theYt) const
	{
	}

	/*!
	 * \fn void cStudentResiduals::Print(ostream& theOut) const
	 * \param ostream& theOut: the output stream, default cout.
	 */
	void cStudentResiduals::Print(ostream& theOut) const
	{
		theOut << "Conditional Student Distribution with " << mDistrParameter[0] << " d. o. f." << endl ;
	}

	static double StudentLogDensity(double theX, double theDof)
	{
		return log(gsl_ran_tdist_pdf(theX, theDof)) ;
	}

	double cStudentResiduals::LogDensity(double theX) const
	{
	double myStd = sqrt(mDistrParameter[0]/(mDistrParameter[0]-2.0)) ;
		return StudentLogDensity(theX*myStd, mDistrParameter[0]) + log(myStd) ;

	}


	/*!
	 * \fn double cStudentResiduals::GetNParam(void) const
	 * \param void.
	 * \brief return 1: One parameter for St(n) residuals.
	 */
	uint cStudentResiduals::GetNParam(void) const
	{
		return 1 ;
	}
	
	/*!
	 * \fn static void StudentGradLogDensity(double theX, double theDof, cDVector& theGrad)
	 * \brief Compute the derivative of log density of a Student distribution (unstandardized)
	 * with respect to the random variable (theGrad[0]) \e and the gradient
	 * of log density with respect to the model parameters (other components in theGrad)
	 * \param theX double: value of the random variable
	 * \param theDof double: value of the distribution parameter
	 * \param theGrad cDVector&: concatenation of derivatives with respect to the random variable and the model parameters
	 */
	static void StudentGradLogDensity(double theX, double theDof, cDVector& theGrad)
	{
	}

	/*!
	 * \fn static void GradLogDensity(double theX, cDVector& theGrad, cDVector& theDistrParam)
	 * \brief Compute the derivative of standardized Student log density with respect to the random variable (theGrad[0]) 
	 * \e and the gradient of log density with respect to the model parameters (other components in theGrad)
	 * \param theX double: value of the random variable
	 * \param theGrad cDVector&: concatenation of derivatives with respect to the random variable and the model parameters
	 * \param theDistrParam cDVector&: value of the distribution parameters
	 */
	static void GradLogDensity(double theX, cDVector& theGrad, cDVector& theDistrParam)
	{
	}
	
	/*!
	 * \fn void cStudentResiduals::ComputeGrad(uint theDate, const cRegArchValue& theValue, cRegArchGradient& theGradData)
	 * \brief Compute the derivative of log density with respect to the random variable (theGradData[0]) \e and the gradient
	 * of log density with respect to the model parameters (other components in theGradData)
	 * \param theDate uint: time at which gradient is computed
	 * \param theValue const cRegArchValue&: value of the random variable
	 * \param theGradData cRegArchGradient&: concatenation of derivatives with respect to the random variable and the model parameters
	 */
	void cStudentResiduals::ComputeGrad(uint theDate, const cRegArchValue& theValue, cRegArchGradient& theGradData)
	{
		GradLogDensity(theValue.mEpst[theDate], theGradData.mCurrentGradDens, mDistrParameter) ;
	}

	void cStudentResiduals::RegArchParamToVector(cDVector& theDestVect, uint theIndex) const
	{
		if (theDestVect.GetSize() < theIndex - 1)
			throw cError("Wrong size") ;
		theDestVect[theIndex] = mDistrParameter[0] ;
	}

	void cStudentResiduals::VectorToRegArchParam(const cDVector& theSrcVect, uint theIndex)
	{
		if (1 + theIndex > theSrcVect.GetSize())
			throw cError("Wrong size") ;
		mDistrParameter[0] = theSrcVect[theIndex] ;
	}


}//namespace

#include "StdAfxRegArchLib.h"
/*!
 \file cAbstCondVar.cpp
 \brief sources for abstract class cAbstCondVar methods.

 \author Jean-Baptiste DURAND, Ollivier TARAMASCO 
 \date dec-18-2006 - Last change feb-18-2011
*/

namespace RegArchLib {
	/*!
	 * \fn cCondMean::cCondMean(uint theNCondMean)
	 * \param uint theNCondMean: number of conditional means
	 * \details mvCondMean = theNCondMean
	 */
	cCondMean::cCondMean(uint theNCondMean)
	: mvCondMean()
	{	mvNCondMean = theNCondMean ;

		MESS_CREAT("cCondMean") ;
	}

	/*!
	 * \fn cCondMean::cCondMean(const cCondMean& theCondMean)
	 * \param cCondMean& theCondMean: conditional mean
	 * \details Recopy constructor
	 */
	cCondMean::cCondMean(const cCondMean& theCondMean)
	: mvNCondMean(theCondMean.GetNMean()),
	  mvCondMean(theCondMean.GetNMean())
	{
		std::vector<cAbstCondMean*> myCondMean = theCondMean.GetCondMean() ;
		for (register uint i = 0 ; i < mvNCondMean ; i++)
			mvCondMean[i] = myCondMean[i]->PtrCopy() ;
		MESS_CREAT("cCondMean") ;
	}

	/*!
	 * \fn cCondMean::~cCondMean()
	 * \param None
	 * \details simple destructor
	 */
	cCondMean::~cCondMean()
	{	Delete() ;
		MESS_DESTR("cCondMean") ;
	}

	/*!
	 * \fn void cCondMean::Delete(void)
	 * \param void
	 * \details free memory used par the cCondMean class
	 */
	void cCondMean::Delete(void)
	{	if (mvNCondMean > 0)
		{	for (register uint i = 0 ; i < mvNCondMean ; i++)
				if (mvCondMean[i] != NULL)
				{	mvCondMean[i]->Delete() ;
					delete mvCondMean[i] ;
					mvCondMean[i] = (cAbstCondMean *)NULL ;
				}
		}
		mvNCondMean = 0 ;
	}

	/*!
	 * \fn inline uint cCondMean::GetNMean(void) const
	 * \param void
	 * \brief return mvNCondMean
	 */
	uint cCondMean::GetNMean(void) const
	{
		return mvNCondMean ;
	}

	/*!
	 * \fn  void cCondMean::SetOneMean(uint theWhatMean, cAbstCondMean* theAbstCondMean)
	 * \param uint theWhatMean: index of the conditional mean component
	 * \param cAbstCondMean* theAbstCondMean: conditional mean component to be copied in the mCondMean array.
	 * \brief *mvCondMean[theWhatMean] = *theAbstCondMean
	 */
	void cCondMean::SetOneMean(uint theWhatMean, cAbstCondMean& theAbstCondMean)
	{
		if (theWhatMean > mvNCondMean)
			throw cError("cCondMean::GetOneMean bad index") ;
		else
		{
			if (theWhatMean < mvNCondMean)
			{
				if (mvCondMean[theWhatMean] != NULL)
					delete mvCondMean[theWhatMean] ;
				mvCondMean[theWhatMean] = theAbstCondMean.PtrCopy();
			}
			else
			{
				mvCondMean.push_back(theAbstCondMean.PtrCopy()) ;
				mvNCondMean += 1 ;
			}
		}
	}

	/*!
	 * \fn cAbstCondMean** cCondMean::GetCondMean(void)
	 * \\details return mvCondMean
	 */
	std::vector<cAbstCondMean*> cCondMean::GetCondMean(void) const
	{	return mvCondMean ;
		
	}
	/*!
	 * \fn cAbstCondMean* cCondMean::GetOneMean(uint theIndex) const
	 * \param uint theIndex: index of component to be returned
	 * \\details return mvCondMean[theWhateMean] 
	 */
	cAbstCondMean* cCondMean::GetOneMean(uint theIndex) const
	{
		if (theIndex < mvNCondMean)
			return mvCondMean[theIndex] ;
		else
			throw cError("cCondMean::GetOneMean bad index") ;
	}

	/*!
	 * \fn void cCondMean::GetCondMeanType(eCondMeanEnum* theCodeType) const
	 * \param eCondMeanEnum* theCodeType: array of all conditional mean component codes
	 * \details fill theCodeType array
	 */
	void cCondMean::GetCondMeanType(eCondMeanEnum* theCodeType) const
	{	for (register uint i = 0 ; i < mvNCondMean ; i++)
			theCodeType[i] = mvCondMean[i]->GetCondMeanType()  ;
	}

	/*!
	 * \fn void cCondMean::Print(ostream& theOut) const
	 * \param ostream& theOut: output stream (file or screen). Default cout.
	 */
	void cCondMean::Print(ostream& theOut) const
	{	theOut << "Conditional mean parameters:" << endl ;
		theOut << "----------------------------" << endl ;
		for (register uint i = 0 ; i < mvNCondMean ; i++)
			mvCondMean[i]->Print(theOut) ;
	}

	/*!
	 * \fn double cCondMean::Get(uint theNumMean, uint theIndex, uint theNumParam)
	 * \param uint theNumMean: index of 
	 * \param ostream& theOut: output stream (file or screen). Default cout.
	 */
	double cCondMean::Get(uint theNumMean, uint theIndex, uint theNumParam)
	{
		return mvCondMean[theNumMean]->Get(theIndex, theNumParam) ;
	}
	
	/*!
	 * \fn ostream& operator <<(ostream& theOut, const cCondMean& theCondMean)
	 * \param ostream& theOut: output (file or screen).
	 * \param const cCondMean& theCondMean: the conditional mean class to be printed.
	 */
	ostream& operator <<(ostream& theOut, const cCondMean& theCondMean)
	{	theOut << "Conditional mean parameters:" << endl ;
		theOut << "----------------------------" << endl ;
		for (register uint i = 0 ; i < theCondMean.mvNCondMean ; i++)
		{	theCondMean.mvCondMean[i]->Print(theOut) ;
			theOut << endl ;
		}
		return theOut ;
	}

	/*!
	 * \fn cCondMean& cCondMean::operator =(cCondMean& theSrc)
	 * \param cCondMean& theSrc: source class
	 */
	cCondMean& cCondMean::operator =(cCondMean& theSrc)
	{	// Complete
	}

	/*!
	 * \fn double cCondMean::ComputeMean(uint theDate, const cRegArchValue& theData) const
	 * \param int theDate: date of computation
	 * \param const cRegArchValue& theData: past datas.
	 * \details Compute the value of the conditional mean at date theDate. 
	 * theData is not updated here.
	 */
	double cCondMean::ComputeMean(uint theDate, const cRegArchValue& theData) const
	{
		// Complete	
	}

	uint cCondMean::GetNParam(void) const
	{
	uint myNParam = 0 ;
		for (register uint i = 0 ; i < mvNCondMean ; i++)
			myNParam += mvCondMean[i]->GetNParam() ;
		return myNParam ;
	}


}//namespace

#pragma once

/*+
________________________________________________________________________

 (C) dGB Beheer B.V.; (LICENSE) http://opendtect.org/OpendTect_license.txt
 Author:	Bert
 Date:		Nov 2006
________________________________________________________________________


-*/

#include "prestackprocessingmod.h"
#include "dbkey.h"
#include "offsetazimuth.h"
#include "prestackprocessor.h"

namespace PreStack
{

/*!
\brief Lateral stack
*/

mExpClass(PreStackProcessing) LateralStack : public Processor
{ mODTextTranslationClass(LateralStack);
public:
			mDefaultFactoryInstantiationBase(
				"LateralStack", tr("Super Gather") );
    static Processor*	createInstance();

			LateralStack();
			~LateralStack();

    bool		reset(bool force=true);

    bool		wantsInput(const BinID&) const;
    bool		setPattern(const BinID& stepout,bool cross);
			//If cross if false, it will be a rectangle
    bool		isCross() const	{ return iscross_; }
    const BinID&	getPatternStepout() const { return patternstepout_; }
    const BinID&	getInputStepout() const { return inputstepout_; }
    bool		setOutputInterest(const BinID& relbid,bool);

    bool		prepareWork();
    uiString		errMsg() const		{ return errmsg_; }

    void		fillPar(IOPar&) const;
    bool		usePar(const IOPar&);

protected:
    bool		isInPattern(const BinID&) const;
    bool		processOutput( const OffsetAzimuth&,const BinID&);
    static const char*	sKeyStepout()		{ return "Stepout"; }
    static const char*	sKeyCross()		{ return "Is cross"; }

    uiString		errmsg_;
    bool		doWork(od_int64,od_int64,int);
    od_int64		nrIterations() const	{ return offsetazi_.size(); }

    BinID		inputstepout_;
    BinID		patternstepout_;
    bool		iscross_;

    TypeSet<OffsetAzimuth>	offsetazi_;
};

} // namespace PreStack

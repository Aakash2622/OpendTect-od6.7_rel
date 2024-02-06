#pragma once

/*+
________________________________________________________________________

 (C) dGB Beheer B.V.; (LICENSE) http://opendtect.org/OpendTect_license.txt
 Author:        Bert
 Date:          Aug 2008
________________________________________________________________________

-*/

#include "emcommon.h"
class TaskRunnerProvider;
namespace Pick	{ class Set; }
namespace EM	{ class Horizon3D; }

/*!\brief Calculate volume between horizon and polygon. */

mExpClass(EarthModel) Poly2HorVol
{
public:

			Poly2HorVol( const Pick::Set* ps=0, EM::Horizon3D* h=0 )
			    : ps_(ps), hor_(0)	{ setHorizon(h); }
			~Poly2HorVol();

    const Pick::Set*	pickSet() const		{ return ps_; }
    EM::Horizon3D*	horizon()		{ return hor_; }
    void		setPickSet( const Pick::Set* ps )	{ ps_ = ps; }
    void		setHorizon(EM::Horizon3D*);

    bool		setHorizon(const DBKey&,const TaskRunnerProvider&);

    float		getM3(float,bool upward,bool usenegvals);
    const char*		dispText(float m3,bool inft);

protected:

    const Pick::Set*	ps_;
    EM::Horizon3D*	hor_;

};

#pragma once

/*+
________________________________________________________________________

 (C) dGB Beheer B.V.; (LICENSE) http://opendtect.org/OpendTect_license.txt
 Author:	J.C Glas
 Date:		November 2008
________________________________________________________________________


-*/

#include "emfault.h"

namespace Geometry { class FaultStickSet; }
namespace Pos { class Filter; }

namespace EM
{

/*!\brief FaultStickSet geometry. */

mExpClass(EarthModel) FaultStickSetGeometry : public FaultGeometry
{
public:
			FaultStickSetGeometry(Surface&);
			~FaultStickSetGeometry();

    int			nrSticks() const;
    int			nrKnots(int sticknr) const;

    bool		insertStick(int sticknr,int firstcol,
				    const Coord3& pos,const Coord3& editnormal,
				    bool addtohistory);
    bool		insertStick(int sticknr,int firstcol,
				    const Coord3& pos,const Coord3& editnormal,
				    const DBKey* pickeddbkey,
				    const char* pickednm,bool addtohistory);
    bool		insertStick(int sticknr,int firstcol,
				    const Coord3& pos,const Coord3& editnormal,
				    Pos::GeomID pickedgeomid,bool addtohistory);
    bool		removeStick(int sticknr,
				    bool addtohistory);
    bool		insertKnot(const PosID&,
				   const Coord3& pos,bool addtohistory);
    bool		removeKnot(const PosID&,
				   bool addtohistory);

    bool		pickedOnPlane(int sticknr) const;
    bool		pickedOn2DLine(int sticknr) const;
    bool		pickedOnHorizon(int sticknr) const;

    const DBKey*	pickedDBKey(int sticknr) const;
    const char*		pickedName(int sticknr) const;
    Pos::GeomID		pickedGeomID(int sticknr)const;

    Geometry::FaultStickSet*		geometryElement();
    const Geometry::FaultStickSet*	geometryElement() const;

    ObjectIterator*	createIterator(const TrcKeyZSampling* =0) const;

    void		fillPar(IOPar&) const;
    bool		usePar(const IOPar&);

protected:
    Geometry::FaultStickSet*	createGeometryElement() const;

    int			indexOf(int stricnr) const;

    struct StickInfo
    {
				StickInfo();

	int			sid;
	int			sticknr;
	Pos::GeomID		pickedgeomid;
	DBKey			pickeddbkey;
	BufferString		pickednm;
    };

    ObjectSet<StickInfo>	 stickinfo_;

};


/*!
\brief Fault stick set.
*/

mExpClass(EarthModel) FaultStickSet: public Fault
{   mDefineEMObjFuncs( FaultStickSet );
    mODTextTranslationClass( FaultStickSet );
public:
				mDeclMonitorableAssignment(FaultStickSet);

    FaultStickSetGeometry&		geometry();
    const FaultStickSetGeometry&	geometry() const;
    void				apply(const Pos::Filter&);
    uiString				getUserTypeStr() const;

    bool				pickedOnPlane(int sticknr) const;
    bool				pickedOn2DLine(int row) const;
    Pos::GeomID				pickedGeomID(int row) const;
    const DBKey*			pickedDBKey(int sticknr) const;
    const char*				pickedName(int sticknr) const;

protected:

    const IOObjContext&			getIOObjContext() const;

    FaultStickSetGeometry		geometry_;
};

} // namespace EM

/*+
________________________________________________________________________

 (C) dGB Beheer B.V.; (LICENSE) http://opendtect.org/OpendTect_license.txt
 Author:        Kristofer
 Date:          Mar 2008
________________________________________________________________________

-*/

#include "moddepmgr.h"
#include "uiosgfont.h"

mDefModInitFn(uiOSG)
{
    mIfNotFirstTime( return );

    uiOsgFontCreator::initClass();
}

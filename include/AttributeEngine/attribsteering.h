#pragma once

/*+
________________________________________________________________________

 (C) dGB Beheer B.V.; (LICENSE) http://opendtect.org/OpendTect_license.txt
 Author:        Kristofer Tingdahl
 Date:          07-10-1999
________________________________________________________________________

-*/

#include "attributeenginecommon.h"
#include "binid.h"

namespace Attrib
{

mGlobal(AttributeEngine) BinID getSteeringPosition( int );
mGlobal(AttributeEngine) int getSteeringIndex( const BinID& );


}; //Namespace

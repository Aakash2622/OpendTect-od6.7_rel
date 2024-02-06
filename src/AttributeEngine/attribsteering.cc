/*+
 * (C) dGB Beheer B.V.; (LICENSE) http://opendtect.org/OpendTect_license.txt
 * AUTHOR   : Bert
 * DATE     : Sep 2003
-*/


#include "attribsteering.h"


namespace Attrib
{


BinID getSteeringPosition( int targetidx )
{
    if ( !targetidx ) return BinID(0,0);

    int radius = 1;
    int idx = 0;

    while ( true )
    {
	int inl, crl;

	inl = -radius;

	for ( crl=-radius; crl<radius; crl++ )
	{
	    idx++;
	    if ( idx==targetidx ) return BinID( inl, crl );
	}

	for ( ; inl<radius; inl++ )
	{
	    idx++;
	    if ( idx==targetidx ) return BinID( inl, crl );
	}

	for ( ; crl>-radius; crl-- )
	{
	    idx++;
	    if ( idx==targetidx ) return BinID( inl, crl );
	}

	for ( ; inl>-radius; inl-- )
	{
	    idx++;
	    if ( idx==targetidx ) return BinID( inl, crl );
	}

	radius++;
    }

    return BinID(0,0);
}


int getSteeringIndex( const BinID& bid )
{
    int res = 0;
    while ( bid!=getSteeringPosition(res) ) res++;
    return res;
}



}; //namespace

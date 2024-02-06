/*+
________________________________________________________________________

 (C) dGB Beheer B.V.; (LICENSE) http://opendtect.org/OpendTect_license.txt
 Author:        Helene / Bruno
 Date:          July 2007 / Sept 2010
________________________________________________________________________

-*/

#include "uistratlvllist.h"

#include "bufstringset.h"
#include "randcolor.h"
#include "stratlevel.h"

#include "uibuttongroup.h"
#include "uilabel.h"
#include "uimenu.h"
#include "uimsg.h"
#include "uistratutildlgs.h"
#include "uitoolbutton.h"


uiStratLvlList::uiStratLvlList( uiParent* p )
    : uiListBox(p,Setup(OD::ChooseOnlyOne,tr("Regional markers"),
			uiListBox::AboveMid))
    , islocked_(false)
    , anychange_(false)
{
    setStretch( 2, 2 );
    setFieldWidth( 15 );
    doubleClicked.notify( mCB(this,uiStratLvlList,editCB) );

    uiButtonGroup* grp = new uiButtonGroup( this, "Tools", OD::Vertical );
    grp->attach( rightTo, box() );
    new uiToolButton( grp, "create", uiStrings::phrCreate(uiStrings::sNew()),
		      mCB(this,uiStratLvlList,addCB) );
    new uiToolButton( grp, "edit", uiStrings::sEdit(),
                      mCB(this,uiStratLvlList,editCB) );
    new uiToolButton( grp, "remove", uiStrings::sRemove(),
		      mCB(this,uiStratLvlList,removeCB) );
    new uiToolButton( grp, "clear", uiStrings::phrRemove(uiStrings::sAll()),
		      mCB(this,uiStratLvlList,removeAllCB) );

    setLevels();
    setHAlignObj( box() );
    setHCenterObj( box() );
}


void uiStratLvlList::setLevels()
{
    Strat::LevelSet& levelset = Strat::eLVLS();
    mAttachCB( levelset.objectChanged(), uiStratLvlList::lvlSetChgCB );
    fill();
}


uiStratLvlList::~uiStratLvlList()
{
    detachAllNotifiers();
}


#define mCheckLocked            if ( checkLocked() ) return;

#define mCheckEmptyList \
    if ( isPresent(sNoLevelTxt()) ) \
	return;


bool uiStratLvlList::checkLocked() const
{
    if ( islocked_ )
    {
	uiMSG().error( tr("Cannot change Stratigraphy because it is locked") );
	return true;
    }

    return false;
}


void uiStratLvlList::editCB( CallBacker* )
{ mCheckLocked; mCheckEmptyList; editLevel( false );  }

void uiStratLvlList::addCB( CallBacker* )
{ mCheckLocked; editLevel( true ); }


void uiStratLvlList::removeCB( CallBacker* )
{
    mCheckLocked; mCheckEmptyList;
    uiString msg = tr("This will remove the selected Level.");
    if ( !uiMSG().askRemove(msg) ) return;

    Strat::LevelSet& levelset = Strat::eLVLS();
    const char* lvlnm = getText();
    if ( !levelset.isPresent(lvlnm) )
	return;

    const Strat::Level lvl = levelset.getByName( lvlnm );
    levelset.remove( lvl.id() ) ;
    anychange_ = true;
}


void uiStratLvlList::removeAllCB( CallBacker* )
{
    mCheckLocked; mCheckEmptyList;
    uiString msg = tr("This will remove all the markers present in the list,"
		      " do you want to continue ?");
    if ( !uiMSG().askRemove(msg) )
	return;

    Strat::eLVLS().setEmpty();
    anychange_ = true;
}


void uiStratLvlList::lvlSetChgCB( CallBacker* )
{
    //TODO merge edits with new situation
    fill();
}


void uiStratLvlList::fill()
{
    setEmpty();

    const Strat::LevelSet& lvls = Strat::LVLS();
    BufferStringSet lvlnms;
    TypeSet<Color> lvlcolors;

    MonitorLock ml( lvls );
    for ( int idx=0; idx<lvls.size(); idx++ )
    {
	const Strat::Level lvl = lvls.getByIdx( idx );
	lvlnms.add( lvl.name() );
	lvlcolors += lvl.color();
    }
    ml.unlockNow();

    for ( int idx=0; idx<lvlnms.size(); idx++ )
	addItem( toUiString(lvlnms[idx]->buf()), lvlcolors[idx] );

    if ( isEmpty() )
	addItem( toUiString("--- %1 ---").arg(uiStrings::sNone()) );
}


void uiStratLvlList::editLevel( bool create )
{
    Strat::LevelSet& lvls = Strat::eLVLS();
    BufferString oldnm;

    uiStratLevelDlg lvldlg( this );
    lvldlg.setCaption( create ? tr("Create level") : tr("Edit level") );
    Strat::Level lvl = Strat::Level::undef();
    if ( !create )
    {
	oldnm = getText();
	lvl = lvls.getByName( oldnm );
	lvldlg.setLvlInfo( oldnm, lvl.color() );
    }

    if ( lvldlg.go() )
    {
	BufferString nm; Color col;
	lvldlg.getLvlInfo( nm, col );
	if ( !nm.isEmpty() && oldnm != nm && lvls.isPresent( nm ) )
	    { uiMSG().error(tr("Level name is empty or already exists"));
              return; }

	lvl.setName( nm.buf() );
	lvl.setColor( col );
	lvls.set( lvl );
	anychange_ = true;
    }
}
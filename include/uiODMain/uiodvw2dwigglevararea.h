#pragma once

/*+
________________________________________________________________________

 CopyRight:	(C) dGB Beheer B.V.
 Author:	Umesh Sinha
 Date:		June 2010
________________________________________________________________________

-*/

#include "uiodmainmod.h"
#include "uiodvw2dtreeitem.h"

#include "datapack.h"
#include "menuhandler.h"

class uiMenuHandler;
class VW2DSeis;
class AttribProbeLayer;


mExpClass(uiODMain) uiODVW2DWiggleVarAreaTreeItem : public uiODVw2DTreeItem
{ mODTextTranslationClass(uiODVW2DWiggleVarAreaTreeItem);
public:

				uiODVW2DWiggleVarAreaTreeItem();
				~uiODVW2DWiggleVarAreaTreeItem();

    bool			select();
    bool                        showSubMenu();
    void			setAttribProbeLayer(AttribProbeLayer*);

protected:

    bool			init();
    const char*			iconName() const;
    const char*			parentType() const
				{ return typeid(uiODVw2DTreeTop).name(); }
    bool                        isSelectable() const            { return true; }

    VW2DSeis*			dummyview_;
    uiMenuHandler*              menu_;
    MenuItem                    selattrmnuitem_;
    RefMan<AttribProbeLayer>	attrlayer_;

    void                        createSelMenu(MenuItem&);
    bool			handleSelMenu(int mnuid);

    void			checkCB(CallBacker*);
    void			dataChangedCB(CallBacker*);
    void			attrLayerChangedCB(CallBacker*);
    void                        createMenuCB(CallBacker*);
    void                        handleMenuCB(CallBacker*);

};


mExpClass(uiODMain) uiODVW2DWiggleVarAreaTreeItemFactory
				: public uiODVw2DTreeItemFactory
{
public:

    const char*		name() const		{ return typeid(*this).name(); }
    uiTreeItem*		create() const
			{ return new uiODVW2DWiggleVarAreaTreeItem(); }
    uiTreeItem*         createForVis(const uiODViewer2D&,int visid) const;

};

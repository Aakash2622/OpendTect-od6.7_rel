#_______________________Pmake___________________________________________________
#
#	Makefile: 	uiODMain
# 	Nov 2005:	Nanne Hemstra
#_______________________________________________________________________________

set(OD_MODULE_DEPS
	uiVis
	uiVolumeProcessing
	uiNLA
	uiWellAttrib
	uiEMAttrib
	uiViewer2D
)
set(OD_MODULE_SOURCES
	inituiodmain.cc
	measuretoolman.cc
	odsession.cc
	uiautosaverestore.cc
	uiodannottreeitem.cc
	uiodannotarrowtreeitem.cc
	uiodannotimagetreeitem.cc
	uiodannotscalebaritem.cc
	uiodapplmgr.cc
	uiodapplmgraux.cc
	uiodapplmgrattrvis.cc
	uiodattribtreeitem.cc
	uiodcontourtreeitem.cc
	uioddatatreeitem.cc
	uioddisplaytreeitem.cc
	uiodfaulttoolman.cc
	uiodfaulttreeitem.cc
	uiodeditattribcolordlg.cc
	uiodhelpmenumgr.cc
	uiodhorattribmgr.cc
	uiodhostiddlg.cc
	uiodlangmenumgr.cc
	uiodmain.cc
	uiodmenumgr.cc
	uiodscenemgr.cc
	uiodscenetreeitem.cc
	uiodsceneparenttreeitem.cc
	uiodemsurftreeitem.cc
	uiodhortreeitem.cc
	uiodpicksettreeitem.cc
	uiodplanedatatreeitem.cc
	uiodprobeparenttreeitem.cc
	uiodpseventstreeitem.cc
	uiodrandlinetreeitem.cc
	uiodbodydisplaytreeitem.cc
	uiodseis2dtreeitem.cc
	uiodstratlayermodelmgr.cc
	uiodusrinteractionsettings.cc
	uiodviewer2d.cc
	uiodviewer2dmgr.cc
	uiodviewer2dposgrp.cc
	uiodviewer2dposdlg.cc
	uiodvw2dtreeitem.cc
	uiodvw2demtreeitem.cc
	uiodvw2dfaulttreeitem.cc
	uiodvw2dfaultsstreeitem.cc
	uiodvw2dfaultss2dtreeitem.cc
	uiodvw2dhor2dtreeitem.cc
	uiodvw2dhor3dtreeitem.cc
	uiodvw2dpicksettreeitem.cc
	uiodvw2dwigglevararea.cc
	uiodvw2dvariabledensity.cc
	uiodvolproctreeitem.cc
	uiodvolumetreeitem.cc
	uiodwelltreeitem.cc
	uiserviceclientmgr.cc
)

set( OD_MODULE_GUI_PROGS od_main.cc  )
if ( WIN32 )
    set( OD_MODULE_PROGS od_main_console.cc )
    set( OD_od_main_RESOURCE  resources/od_main.rc )
endif()

OD_ADD_SOURCE_FILES( resources/od_main.rc resources/resource.h resources/icon1.ico scene.xpm )

OD_INIT_MODULE()

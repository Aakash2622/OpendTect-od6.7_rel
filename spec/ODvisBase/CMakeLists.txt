#_______________________Pmake___________________________________________________
#
#	Makefile : 	visBase
# 	May 2012 :	Nageswara
#_______________________________________________________________________________

if ( UNIX )
  set( OpenGL_GL_PREFERENCE "LEGACY" )
endif()
find_package( OpenGL REQUIRED )
if ( WIN32 )
    set( EXTRA_LIBS ${OPENGL_gl_LIBRARY} ${OPENGL_glu_LIBRARY} )
    set( OD_MODULE_PROGS od_glxinfo.c ) 
elseif ( UNIX AND NOT APPLE )
    find_package( X11 )
    set( EXTRA_LIBS ${OPENGL_gl_LIBRARY} ${OPENGL_glu_LIBRARY} ${X11_LIBRARIES} )
    set( OD_MODULE_PROGS od_glxinfo.c )
endif( )

OD_INIT_MODULE()

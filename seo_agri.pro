#--------------------------------------------------------------------------------------------------------
#If you want to create a visual studio project, use the commmand "qmake -t vclib -spec win32-msvc.net".
#For debug version add the expression "TE_PROJECT_TYPE=DEBUG" to previous command.
#--------------------------------------------------------------------------------------------------------
TARGET = seo_agri
include( ../base/base.pro )
TRANSLATIONS = seo_agri_pt.ts \
		seo_agri_sp.ts
INCLUDEPATH += ./include
HEADERS +=  ./include/seo_agriplugin.h \
	./include/seo_agriPluginCode.h
SOURCES +=  ./src/seo_agriplugin.cpp \
	./src/seo_agriPluginCode.cpp
FORMS += ./ui/Frm_Principal.ui
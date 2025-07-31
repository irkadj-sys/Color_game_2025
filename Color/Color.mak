# Microsoft Developer Studio Generated NMAKE File, Based on Color.dsp
!IF "$(CFG)" == ""
CFG=Color - Win32 Debug
!MESSAGE No configuration specified. Defaulting to Color - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "Color - Win32 Release" && "$(CFG)" != "Color - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "Color.mak" CFG="Color - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Color - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "Color - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "Color - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

ALL : "$(OUTDIR)\Color.exe"


CLEAN :
	-@erase "$(INTDIR)\Color.obj"
	-@erase "$(INTDIR)\Color.pch"
	-@erase "$(INTDIR)\Color.res"
	-@erase "$(INTDIR)\ColorDoc.obj"
	-@erase "$(INTDIR)\ColorView.obj"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\OptDlg.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\Color.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\Color.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\Color.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\Color.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\Color.pdb" /machine:I386 /out:"$(OUTDIR)\Color.exe" 
LINK32_OBJS= \
	"$(INTDIR)\Color.obj" \
	"$(INTDIR)\ColorDoc.obj" \
	"$(INTDIR)\ColorView.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\OptDlg.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\Color.res"

"$(OUTDIR)\Color.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "Color - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\Color.exe" "$(OUTDIR)\Color.bsc"


CLEAN :
	-@erase "$(INTDIR)\Color.obj"
	-@erase "$(INTDIR)\Color.pch"
	-@erase "$(INTDIR)\Color.res"
	-@erase "$(INTDIR)\Color.sbr"
	-@erase "$(INTDIR)\ColorDoc.obj"
	-@erase "$(INTDIR)\ColorDoc.sbr"
	-@erase "$(INTDIR)\ColorView.obj"
	-@erase "$(INTDIR)\ColorView.sbr"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\MainFrm.sbr"
	-@erase "$(INTDIR)\OptDlg.obj"
	-@erase "$(INTDIR)\OptDlg.sbr"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\StdAfx.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\Color.bsc"
	-@erase "$(OUTDIR)\Color.exe"
	-@erase "$(OUTDIR)\Color.ilk"
	-@erase "$(OUTDIR)\Color.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\Color.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\Color.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\Color.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\Color.sbr" \
	"$(INTDIR)\ColorDoc.sbr" \
	"$(INTDIR)\ColorView.sbr" \
	"$(INTDIR)\MainFrm.sbr" \
	"$(INTDIR)\OptDlg.sbr" \
	"$(INTDIR)\StdAfx.sbr"

"$(OUTDIR)\Color.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\Color.pdb" /debug /machine:I386 /out:"$(OUTDIR)\Color.exe" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\Color.obj" \
	"$(INTDIR)\ColorDoc.obj" \
	"$(INTDIR)\ColorView.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\OptDlg.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\Color.res"

"$(OUTDIR)\Color.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 

.c{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<


!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("Color.dep")
!INCLUDE "Color.dep"
!ELSE 
!MESSAGE Warning: cannot find "Color.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "Color - Win32 Release" || "$(CFG)" == "Color - Win32 Debug"
SOURCE=.\Color.cpp

!IF  "$(CFG)" == "Color - Win32 Release"


"$(INTDIR)\Color.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Color.pch"


!ELSEIF  "$(CFG)" == "Color - Win32 Debug"


"$(INTDIR)\Color.obj"	"$(INTDIR)\Color.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Color.pch"


!ENDIF 

SOURCE=.\Color.rc

"$(INTDIR)\Color.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\ColorDoc.cpp

!IF  "$(CFG)" == "Color - Win32 Release"


"$(INTDIR)\ColorDoc.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Color.pch"


!ELSEIF  "$(CFG)" == "Color - Win32 Debug"


"$(INTDIR)\ColorDoc.obj"	"$(INTDIR)\ColorDoc.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Color.pch"


!ENDIF 

SOURCE=.\ColorView.cpp

!IF  "$(CFG)" == "Color - Win32 Release"


"$(INTDIR)\ColorView.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Color.pch"


!ELSEIF  "$(CFG)" == "Color - Win32 Debug"


"$(INTDIR)\ColorView.obj"	"$(INTDIR)\ColorView.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Color.pch"


!ENDIF 

SOURCE=.\MainFrm.cpp

!IF  "$(CFG)" == "Color - Win32 Release"


"$(INTDIR)\MainFrm.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Color.pch"


!ELSEIF  "$(CFG)" == "Color - Win32 Debug"


"$(INTDIR)\MainFrm.obj"	"$(INTDIR)\MainFrm.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Color.pch"


!ENDIF 

SOURCE=.\OptDlg.cpp

!IF  "$(CFG)" == "Color - Win32 Release"


"$(INTDIR)\OptDlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Color.pch"


!ELSEIF  "$(CFG)" == "Color - Win32 Debug"


"$(INTDIR)\OptDlg.obj"	"$(INTDIR)\OptDlg.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Color.pch"


!ENDIF 

SOURCE=.\StdAfx.cpp

!IF  "$(CFG)" == "Color - Win32 Release"

CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\Color.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\Color.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "Color - Win32 Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\Color.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\StdAfx.sbr"	"$(INTDIR)\Color.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 


!ENDIF 


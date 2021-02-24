##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Lab9a
ConfigurationName      :=Debug
WorkspacePath          :="D:/Documents/Workspaces/CodeLite Workspace/C-Space"
ProjectPath            :="D:/Documents/Workspaces/CodeLite Workspace/C-Space/Lab9a"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Abd
Date                   :=18/05/2017
CodeLitePath           :="C:/Program Files/CodeLite"
LinkerName             :=C:/MinGW/bin/g++.exe
SharedObjectLinkerName :=C:/MinGW/bin/g++.exe -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="Lab9a.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=C:/MinGW/bin/windres.exe
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := C:/MinGW/bin/ar.exe rcu
CXX      := C:/MinGW/bin/g++.exe
CC       := C:/MinGW/bin/gcc.exe
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := C:/MinGW/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
Objects0=$(IntermediateDirectory)/hashquad.c$(ObjectSuffix) $(IntermediateDirectory)/hashsep.c$(ObjectSuffix) $(IntermediateDirectory)/Lab9-1.c$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@$(MakeDirCommand) "./Debug"


$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "./Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/hashquad.c$(ObjectSuffix): hashquad.c $(IntermediateDirectory)/hashquad.c$(DependSuffix)
	$(CC) $(SourceSwitch) "D:/Documents/Workspaces/CodeLite Workspace/C-Space/Lab9a/hashquad.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/hashquad.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/hashquad.c$(DependSuffix): hashquad.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/hashquad.c$(ObjectSuffix) -MF$(IntermediateDirectory)/hashquad.c$(DependSuffix) -MM hashquad.c

$(IntermediateDirectory)/hashquad.c$(PreprocessSuffix): hashquad.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/hashquad.c$(PreprocessSuffix) hashquad.c

$(IntermediateDirectory)/hashsep.c$(ObjectSuffix): hashsep.c $(IntermediateDirectory)/hashsep.c$(DependSuffix)
	$(CC) $(SourceSwitch) "D:/Documents/Workspaces/CodeLite Workspace/C-Space/Lab9a/hashsep.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/hashsep.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/hashsep.c$(DependSuffix): hashsep.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/hashsep.c$(ObjectSuffix) -MF$(IntermediateDirectory)/hashsep.c$(DependSuffix) -MM hashsep.c

$(IntermediateDirectory)/hashsep.c$(PreprocessSuffix): hashsep.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/hashsep.c$(PreprocessSuffix) hashsep.c

$(IntermediateDirectory)/Lab9-1.c$(ObjectSuffix): Lab9-1.c $(IntermediateDirectory)/Lab9-1.c$(DependSuffix)
	$(CC) $(SourceSwitch) "D:/Documents/Workspaces/CodeLite Workspace/C-Space/Lab9a/Lab9-1.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Lab9-1.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Lab9-1.c$(DependSuffix): Lab9-1.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Lab9-1.c$(ObjectSuffix) -MF$(IntermediateDirectory)/Lab9-1.c$(DependSuffix) -MM Lab9-1.c

$(IntermediateDirectory)/Lab9-1.c$(PreprocessSuffix): Lab9-1.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Lab9-1.c$(PreprocessSuffix) Lab9-1.c


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/



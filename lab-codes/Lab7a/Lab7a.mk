##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Lab7a
ConfigurationName      :=Debug
WorkspacePath          :="D:/Documents/Workspaces/CodeLite Workspace/C-Space"
ProjectPath            :="D:/Documents/Workspaces/CodeLite Workspace/C-Space/Lab7a"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Abd
Date                   :=17/04/2017
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
ObjectsFileList        :="Lab7a.txt"
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
Objects0=$(IntermediateDirectory)/stackar.c$(ObjectSuffix) $(IntermediateDirectory)/tree.c$(ObjectSuffix) $(IntermediateDirectory)/Lab7-1.c$(ObjectSuffix) 



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
$(IntermediateDirectory)/stackar.c$(ObjectSuffix): stackar.c $(IntermediateDirectory)/stackar.c$(DependSuffix)
	$(CC) $(SourceSwitch) "D:/Documents/Workspaces/CodeLite Workspace/C-Space/Lab7a/stackar.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/stackar.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/stackar.c$(DependSuffix): stackar.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/stackar.c$(ObjectSuffix) -MF$(IntermediateDirectory)/stackar.c$(DependSuffix) -MM stackar.c

$(IntermediateDirectory)/stackar.c$(PreprocessSuffix): stackar.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/stackar.c$(PreprocessSuffix) stackar.c

$(IntermediateDirectory)/tree.c$(ObjectSuffix): tree.c $(IntermediateDirectory)/tree.c$(DependSuffix)
	$(CC) $(SourceSwitch) "D:/Documents/Workspaces/CodeLite Workspace/C-Space/Lab7a/tree.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/tree.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/tree.c$(DependSuffix): tree.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/tree.c$(ObjectSuffix) -MF$(IntermediateDirectory)/tree.c$(DependSuffix) -MM tree.c

$(IntermediateDirectory)/tree.c$(PreprocessSuffix): tree.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/tree.c$(PreprocessSuffix) tree.c

$(IntermediateDirectory)/Lab7-1.c$(ObjectSuffix): Lab7-1.c $(IntermediateDirectory)/Lab7-1.c$(DependSuffix)
	$(CC) $(SourceSwitch) "D:/Documents/Workspaces/CodeLite Workspace/C-Space/Lab7a/Lab7-1.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Lab7-1.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Lab7-1.c$(DependSuffix): Lab7-1.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Lab7-1.c$(ObjectSuffix) -MF$(IntermediateDirectory)/Lab7-1.c$(DependSuffix) -MM Lab7-1.c

$(IntermediateDirectory)/Lab7-1.c$(PreprocessSuffix): Lab7-1.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Lab7-1.c$(PreprocessSuffix) Lab7-1.c


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/



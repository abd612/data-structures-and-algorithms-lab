##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Lab11a
ConfigurationName      :=Debug
WorkspacePath          :="D:/Documents/Workspaces/CodeLite Workspace/C-Space"
ProjectPath            :="D:/Documents/Workspaces/CodeLite Workspace/C-Space/Lab11a"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Abd
Date                   :=11/05/2017
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
ObjectsFileList        :="Lab11a.txt"
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
Objects0=$(IntermediateDirectory)/binheap.c$(ObjectSuffix) $(IntermediateDirectory)/Lab11-1.c$(ObjectSuffix) 



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
$(IntermediateDirectory)/binheap.c$(ObjectSuffix): binheap.c $(IntermediateDirectory)/binheap.c$(DependSuffix)
	$(CC) $(SourceSwitch) "D:/Documents/Workspaces/CodeLite Workspace/C-Space/Lab11a/binheap.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/binheap.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/binheap.c$(DependSuffix): binheap.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/binheap.c$(ObjectSuffix) -MF$(IntermediateDirectory)/binheap.c$(DependSuffix) -MM binheap.c

$(IntermediateDirectory)/binheap.c$(PreprocessSuffix): binheap.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/binheap.c$(PreprocessSuffix) binheap.c

$(IntermediateDirectory)/Lab11-1.c$(ObjectSuffix): Lab11-1.c $(IntermediateDirectory)/Lab11-1.c$(DependSuffix)
	$(CC) $(SourceSwitch) "D:/Documents/Workspaces/CodeLite Workspace/C-Space/Lab11a/Lab11-1.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Lab11-1.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Lab11-1.c$(DependSuffix): Lab11-1.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Lab11-1.c$(ObjectSuffix) -MF$(IntermediateDirectory)/Lab11-1.c$(DependSuffix) -MM Lab11-1.c

$(IntermediateDirectory)/Lab11-1.c$(PreprocessSuffix): Lab11-1.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Lab11-1.c$(PreprocessSuffix) Lab11-1.c


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/



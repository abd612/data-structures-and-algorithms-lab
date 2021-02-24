##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=MidEvalPrep
ConfigurationName      :=Debug
WorkspacePath          :="D:/Documents/Workspaces/CodeLite Workspace/C-Space"
ProjectPath            :="D:/Documents/Workspaces/CodeLite Workspace/C-Space/MidEvalPrep"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Abd
Date                   :=06/04/2017
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
ObjectsFileList        :="MidEvalPrep.txt"
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
Objects0=$(IntermediateDirectory)/up_up_up_up_Studies_4th Semester_Data Structures and Algorithms Lab_Source Codes_DSAAC2eCode_PostEval.c$(ObjectSuffix) $(IntermediateDirectory)/stackli.c$(ObjectSuffix) 



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
$(IntermediateDirectory)/up_up_up_up_Studies_4th Semester_Data Structures and Algorithms Lab_Source Codes_DSAAC2eCode_PostEval.c$(ObjectSuffix): ../../../../Studies/4th Semester/Data Structures and Algorithms Lab/Source Codes/DSAAC2eCode/PostEval.c $(IntermediateDirectory)/up_up_up_up_Studies_4th Semester_Data Structures and Algorithms Lab_Source Codes_DSAAC2eCode_PostEval.c$(DependSuffix)
	$(CC) $(SourceSwitch) "D:/Documents/Studies/4th Semester/Data Structures and Algorithms Lab/Source Codes/DSAAC2eCode/PostEval.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_up_up_up_Studies_4th Semester_Data Structures and Algorithms Lab_Source Codes_DSAAC2eCode_PostEval.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_up_up_up_Studies_4th Semester_Data Structures and Algorithms Lab_Source Codes_DSAAC2eCode_PostEval.c$(DependSuffix): ../../../../Studies/4th Semester/Data Structures and Algorithms Lab/Source Codes/DSAAC2eCode/PostEval.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_up_up_up_Studies_4th Semester_Data Structures and Algorithms Lab_Source Codes_DSAAC2eCode_PostEval.c$(ObjectSuffix) -MF$(IntermediateDirectory)/up_up_up_up_Studies_4th Semester_Data Structures and Algorithms Lab_Source Codes_DSAAC2eCode_PostEval.c$(DependSuffix) -MM "../../../../Studies/4th Semester/Data Structures and Algorithms Lab/Source Codes/DSAAC2eCode/PostEval.c"

$(IntermediateDirectory)/up_up_up_up_Studies_4th Semester_Data Structures and Algorithms Lab_Source Codes_DSAAC2eCode_PostEval.c$(PreprocessSuffix): ../../../../Studies/4th Semester/Data Structures and Algorithms Lab/Source Codes/DSAAC2eCode/PostEval.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_up_up_up_Studies_4th Semester_Data Structures and Algorithms Lab_Source Codes_DSAAC2eCode_PostEval.c$(PreprocessSuffix) "../../../../Studies/4th Semester/Data Structures and Algorithms Lab/Source Codes/DSAAC2eCode/PostEval.c"

$(IntermediateDirectory)/stackli.c$(ObjectSuffix): stackli.c $(IntermediateDirectory)/stackli.c$(DependSuffix)
	$(CC) $(SourceSwitch) "D:/Documents/Workspaces/CodeLite Workspace/C-Space/MidEvalPrep/stackli.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/stackli.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/stackli.c$(DependSuffix): stackli.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/stackli.c$(ObjectSuffix) -MF$(IntermediateDirectory)/stackli.c$(DependSuffix) -MM stackli.c

$(IntermediateDirectory)/stackli.c$(PreprocessSuffix): stackli.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/stackli.c$(PreprocessSuffix) stackli.c


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/



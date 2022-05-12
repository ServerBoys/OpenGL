CXX = g++
#CXX = clang++

EXE = main
MAJOR = App
IMGUI_DIR = ./Dependencies/Imgui
GLFW_DIR = ./Dependencies/GLFW
MODELS_DIR = ./Models
# SOURCES = App.cpp
# SOURCES += $(IMGUI_DIR)/imgui.cpp $(IMGUI_DIR)/imgui_demo.cpp $(IMGUI_DIR)/imgui_draw.cpp $(IMGUI_DIR)/imgui_tables.cpp $(IMGUI_DIR)/imgui_widgets.cpp
# SOURCES += $(IMGUI_DIR)/backends/imgui_impl_glfw.cpp $(IMGUI_DIR)/backends/imgui_impl_opengl2.cpp
OBJS = $(addsuffix .o, $(basename $(notdir $(SOURCES))))
UNAME_S := $(shell uname -s)
LIB = 
SRC_FILES = $(MAJOR).cpp
OBJ_FILES = $(MAJOR).o

OBJ_DIR = ./obj
SRC_DIR = ./src
INCLUDE_DIR = ./include

SRC_DIRS = $(wildcard $(SRC_DIR)/*)
SRC_DIRS += $(SRC_DIR)
SRC_FILE := $(foreach d,$(SRC_DIRS),$(wildcard $d/*.cpp))
OBJ_FILE := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILE))
SRC_FILES += $(SRC_FILE)
OBJ_FILES += $(OBJ_FILE)
SRC_C_FILES := $(foreach d,$(SRC_DIRS),$(wildcard $d/*.c))
OBJ_C_FILES := $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_C_FILES))

INCLUDE_DIRS = $(wildcard $(INCLUDE_DIR)/*)

CXXFLAGS = -std=c++20 -I./ $(foreach d, $(INCLUDE_DIRS), -I$d)
CXXFLAGS += -g -Wall -Wformat #-mwindows

LIBS += -L./lib
LIBS += -lglfw3 -lgdi32 -lopengl32 -lkernel32 -lUser32 -lshell32
CFLAGS = $(CXXFLAGS)

##---------------------------------------------------------------------
## BUILD RULES
##---------------------------------------------------------------------

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) -c $(CFLAGS) -o $@ $<

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CXX) -c $(CFLAGS) -o $@ $<

$(EXE): $(OBJ_FILES)
	$(CXX) -o $(EXE).exe $(OBJ_FILES) $(OBJ_C_FILES) $(CXXFLAGS) $(LIBS) 

all: $(EXE)
	@echo Build complete for $(ECHO_MESSAGE)

# clean:
# 	rm -f $(EXE) $(OBJS)
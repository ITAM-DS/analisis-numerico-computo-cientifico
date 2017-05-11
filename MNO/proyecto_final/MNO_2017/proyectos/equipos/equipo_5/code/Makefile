USE_SDL := 0

# This will likely need to be changed to suit your installation.
ALE := ../../../../../../../../../c/Arcade-Learning-Environment/

FLAGS := -I$(ALE)/src -I$(ALE)/src/controllers -I$(ALE)/src/os_dependent -I$(ALE)/src/environment -I$(ALE)/src/external -L$(ALE)
CXX := nvcc
FILE := pong
CUDAFILE := matrixVectorMult
LDFLAGS := -lale -lz
CXXFLAGS := -std=c++11

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
    FLAGS += -Xcompiler \"-Wl,-rpath,$(ALE)\"
endif
ifeq ($(UNAME_S),Darwin)
 #   FLAGS += -framework Cocoa
endif

ifeq ($(strip $(USE_SDL)), 1)
  DEFINES += -D__USE_SDL -DSOUND_SUPPORT
  FLAGS += $(shell sdl-config --cflags)
  LDFLAGS += $(shell sdl-config --libs)
endif

all: sharedLibraryInterfaceExample

sharedLibraryInterfaceExample:
	$(CXX) $(DEFINES) $(FLAGS) $(FILE).cpp $(CUDAFILE).cu $(LDFLAGS) -o $(FILE) $(CXXFLAGS)

clean:
	rm -rf sharedLibraryInterfaceExample *.o

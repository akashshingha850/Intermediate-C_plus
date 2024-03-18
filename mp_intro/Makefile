# Define compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++11 -O2

# Define any directories containing header files other than /usr/include
INCLUDES = -I./RGB

# Define the C++ source files
SRCS = main.cpp intro.cpp RGB/rgbapixel.cpp

# Define the C++ header files
HDRS = intro.h RGB/rgbapixel.h

# Define the executable file 
MAIN = intro

# The following part of the makefile is generic; it can be used to 
# build any executable just by changing the definitions above 
# and by deleting dependencies in clean

all:    $(MAIN)
	@echo  Simple compiler named $(MAIN) has been compiled

$(MAIN): $(SRCS) $(HDRS)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $(MAIN) $(SRCS)

clean:
	$(RM) *.o *~ $(MAIN)

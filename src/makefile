# Compiler
CXX := g++
CXXFLAGS := -std=c++11 -Wall

# Include directories
INCLUDES := -I/usr/local/include

# Library directories
LDFLAGS := -L/usr/local/lib

# Libraries to link
LIBS := -lmma_8451_pi

# Source files
SOURCES := main.cpp 
OBJECTS := $(SOURCES:.cpp=.o)
EXECUTABLE := tester_notBuild

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(LDFLAGS) $^ $(LIBS) -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

DEPS := $(SOURCES:.cpp=.d)

-include $(DEPS)

%.d: %.cpp
	@$(CXX) $(CXXFLAGS) $(INCLUDES) -MM -MP $< -MT "$(@:.d=.o) $@" > $@

.PHONY: clean

clean:
	rm -f $(EXECUTABLE) $(OBJECTS) $(DEPS)
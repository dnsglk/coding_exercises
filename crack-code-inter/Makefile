GCC_BIN=g++
GCC_FLAGS=-ggdb -O0 --std=c++14 -Wall
GCC=$(GCC_BIN) $(GCC_FLAGS)

sources=$(shell ls *.cpp)
targets=$(sources:.cpp=)

all: 
	@echo "Available targets: \n$(targets)"

$(targets) : 
	$(GCC) -Iinclude $(@).cpp


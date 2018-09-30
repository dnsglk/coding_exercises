GCC_BIN=g++
GCC_FLAGS=-ggdb -O0 --std=c++14 -Wall
GCC=$(GCC_BIN) $(GCC_FLAGS)

sources=$(shell ls *.cpp)
targets1=$(sources:%.cpp=%)
targets=$(targets1:$(wildcard '-'*)=)

all: 
	echo $(targets)

$(targets) : 
	$(GCC) $(shell $($(@)*.cpp))


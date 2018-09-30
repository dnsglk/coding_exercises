GCC_BIN=g++
GCC_FLAGS=-ggdb -O0 --std=c++14 -Wall
GCC=$(GCC_BIN) $(GCC_FLAGS)

1.6: 1.6-rotate-matrix.cpp
	$(GCC) $?

1.8: 1.8-string-rotation.cpp
	$(GCC) $?
2.4: 2.4-partition.cpp
	$(GCC) $?
2.5: 2.5-list-sum.cpp
	$(GCC) $?

.PHONY: 1.6 \
    1.8 \
    2.4

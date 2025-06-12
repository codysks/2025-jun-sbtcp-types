CXX = c++
CXXFLAGS = -std=c++17 -Wall -Werror -Wextra
BASEDIR = ../../
INCLUDES = -I $(BASEDIR)/include -I $(BASEDIR)/external_libs

TARGETS = unpack
.PHONY: all
all: $(TARGETS)

unpack.cpp.o: unpack.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $< $(INCLUDES)
unpack: unpack.cpp.o
	$(CXX) $(CXXFLAGS) -o $@ $< $(INCLUDES)
clean:
	rm -vf *.o
	rm -vf $(TARGETS)

CXX=g++
CXXFLAGS=-lgmp -lgmpxx

SRC = hello.cpp

main: $(SRC)
	$(CXX) $(SRC) $(CXXFLAGS) -o $@

.PHONY: clean
 
clean:
	$(RM) main
	

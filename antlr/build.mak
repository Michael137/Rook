####################
#################### Targets below currently not working from non-interactive 
#################### shell due to alias expansion issues 
####################

.PHONY:
build:
	# Lexer/parser cpp files that can be included into project
	antlr4 -Dlanguage=Cpp RookParser.g4 RookLexer.g4 -listener -visitor -o generated/
	# To test with grun on command line need to generate and java target
	antlr4 RookParser.g4 RookLexer.g4 -listener -visitor -o generated/
	javac generated/Rook*.java

.PHONY:
run:
	cd generated && grun Rook game -tokens -gui ../test.in

####################
####################
####################
####################

.PHONY:
cmake_build:
	mkdir build && cd build && cmake .. && make -j4

.PHONY:
clean:
	rm -f *.out
	rm -f *.o
	rm -rf generated
	# Delete files generated through CMake
	rm -rf build

all: clean cmake_build

OBJECTS = BSTree.o Node.o 

main: main.o $(OBJECTS)
	g++ -o main main.o $(OBJECTS)
tests: tests.o $(OBJECTS)
	g++ -o tests tests.o $(OBJECTS)

BSTree.o: BSTree.cpp BSTree.h Node.h
Node.o: Node.cpp Node.h
tests.o: tests.cpp doctest.h BSTree.h Node.h
main.o: main.cpp BSTree.h Node.h

clean: 
	rm -f *.o

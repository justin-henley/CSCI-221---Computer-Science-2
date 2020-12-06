# Requires all files to be in the same directory

# Variable to store the compiler used
CC = g++
# Variable to save some typing
OBJECTS = testsMain.o GenericSet-Tests.o

# The executable
main-HenleyJProj8: $(OBJECTS)
	$(CC) $(OBJECTS) -o main-HenleyJProj8

# The object files
testsMain.o: testsMain.cpp catch.hpp
	$(CC) -c testsMain.cpp

GenericSet-Tests.o: GenericSet-Tests.cpp catch.hpp GenericSet.h
	$(CC) -c GenericSet-Tests.cpp

# Cleanup all object files and executable
clean:
	rm *.o main-HenleyJProj8

# Variable to store the compiler used
CC = g++
# Variable to save some typing
OBJECTS = HenleyJProj5.o CSCI221Proj5Grader.o

# The executable
main-HenleyJProj5: $(OBJECTS)
	$(CC) $(OBJECTS) -o main-HenleyJProj5

# The object files
HenleyJProj5.o: HenleyJProj5.cpp CSCI221Proj5.h
	$(CC) -c HenleyJProj5.cpp

CSCI221Proj5Grader.o: CSCI221Proj5Grader.cpp CSCI221Proj5.h
	$(CC) -c CSCI221Proj5Grader.cpp

# Cleanup all object files and executable
clean:
	rm *.o main-HenleyJProj5

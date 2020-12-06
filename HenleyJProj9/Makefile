# Requires all files to be in the same directory

# Variable to store the compiler used
CC = g++
# Variable to save some typing
OBJECTS = HenleyJProj9.o Book.o

# The executable
main-HenleyJProj9: $(OBJECTS)
	$(CC) $(OBJECTS) -o main-HenleyJProj9

# The object files
HenleyJProj9.o: HenleyJProj9.cpp Book.h
	$(CC) -c HenleyJProj9.cpp

Book.o: Book.cpp Book.h
	$(CC) -c Book.cpp

# Cleanup all object files and executable
clean:
	rm *.o main-HenleyJProj9

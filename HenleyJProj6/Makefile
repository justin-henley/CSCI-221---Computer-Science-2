# Requires all files to be in the same directory

# Variable to store the compiler used
CC = g++
# Variable to save some typing
OBJECTS = HenleyJProj6.o Shape.o Circle.o Rectangle.o

# The executable
main-HenleyJProj6: $(OBJECTS)
	$(CC) $(OBJECTS) -o main-HenleyJProj6

# The object files
HenleyJProj6.o: HenleyJProj6.cpp Shape.h Circle.h Rectangle.h
	$(CC) -c HenleyJProj6.cpp

Shape.o: Shape.cpp Shape.h
	$(CC) -c Shape.cpp

Circle.o: Circle.cpp Circle.h
	$(CC) -c Circle.cpp

Rectangle.o: Rectangle.cpp Rectangle.h
	$(CC) -c Rectangle.cpp

# Cleanup all object files and executable
clean:
	rm *.o main-HenleyJProj6

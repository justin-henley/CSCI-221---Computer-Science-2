# Variable to store the compiler used
CC = g++
# Variable to save some typing
OBJECTS = HenleyJProj4.o HenleyJMoney.o

# The executable
main-HenleyJProj4: $(OBJECTS)
	$(CC) $(OBJECTS) -o main-HenleyJProj4

# The object files
HenleyJProj4.o: HenleyJProj4.cpp HenleyJMoney.h
	$(CC) -c HenleyJProj4.cpp

HenleyJMoney.o: HenleyJMoney.cpp HenleyJMoney.h
	$(CC) -c HenleyJMoney.cpp

# Cleanup all object files and executable
clean:
	rm *.o main-HenleyJProj4

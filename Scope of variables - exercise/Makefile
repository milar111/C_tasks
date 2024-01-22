all: taskmanager.out

processes.o: processes.h processes.c taskmanager.c
	gcc -c processes.c -o processes.o 

taskmanager.out: taskmanager.c processes.h processes.o
	gcc taskmanager.c processes.o -o taskmanager.out

clean:
	rm -f *.o taskmanager.out

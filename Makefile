#global ↓
# remove files end with extension ".o"
clean:
	rm -f *.o
#global ↑

# Makefile demo and question 1 factorial ↓
main.o: factorial/main.c factorial/factorial.h
	gcc -c factorial/main.c

factorial.o: factorial/factorial.c factorial/factorial.h
	gcc -c factorial/factorial.c

question_1_factorial: main.o factorial.o
	gcc main.o factorial.o -o question_1_factorial

question_1_run: question_1_factorial
	./question_1_factorial
	clean
# Makefile demo and question 1 factorial ↑
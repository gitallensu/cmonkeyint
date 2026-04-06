interpreter: main.c
	gcc main.c -o monkey -Wall -Wextra -pedantic
run: interpreter
	./monkey

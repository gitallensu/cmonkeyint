SRCDIR = src
BUILDDIR = build

interpreter: $(SRCDIR)/main.c
	gcc $(SRCDIR)/main.c -o $(BUILDDIR)/main -Wall -Wextra -pedantic
run: interpreter
	./$(BUILDDIR)/main

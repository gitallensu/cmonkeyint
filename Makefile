SRCDIR = src
BUILDDIR = build

interpreter: $(SRCDIR)/main.c
	gcc $(SRCDIR)/token.c $(SRCDIR)/main.c -o $(BUILDDIR)/main -Wall -Wextra -pedantic -g
run: interpreter
	./$(BUILDDIR)/main

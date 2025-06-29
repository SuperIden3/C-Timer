CC = gcc
CFLAGS = -Wall -Wextra -pedantic -std=c99 -O3 -s -I ./code_deps/

SRCDIR = src
OUTDIR = out
DEPENDS = $(SRCDIR)/stopwatch.c
OUTFILE = $(OUTDIR)/cstopwatch

.PHONY: all build run clean

all: build

build: $(DEPENDS)
	mkdir -p $(OUTDIR)
	$(CC) $(CFLAGS) -o $(OUTFILE) $^

run:
	@if [ ! -e $(OUTFILE) ]; then make -f stopwatch.Makefile build; fi
	./$(OUTFILE) $(ARG1) $(ARG2) $(ARG3)

clean:
	rm -rf $(OUTDIR)

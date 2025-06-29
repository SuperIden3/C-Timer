CC = gcc
CFLAGS = -Wall -Wextra -pedantic -std=c99 -O3 -s -I ./code_deps/

SRCDIR = src
OUTDIR = out
DEPENDS = $(SRCDIR)/timer.c
OUTFILE = $(OUTDIR)/ctimer

.PHONY: all build run clean

all: build

build: $(DEPENDS)
	mkdir -p $(OUTDIR)
	$(CC) $(CFLAGS) -o $(OUTFILE) $^

run:
	@if [ ! -e $(OUTFILE) ]; then make -f timer.Makefile build; fi
	./$(OUTFILE) $(ARG1) $(ARG2) $(ARG3)

clean:
	rm -rf $(OUTDIR)

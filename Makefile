CC = gcc
CFLAGS = -Wall -Wextra -pedantic -std=c99
CFLAGS_DEBUG = $(CFLAGS) -g -O0
CFLAGS_RELEASE = $(CFLAGS) -O2 -s

SRCDIR = src
OUTDIR = out
DEPENDS = $(SRCDIR)/*.c
OUTFILE = $(OUTDIR)/ctimer

.PHONY: all build build-debug run clean

all: build

build: $(DEPENDS)
	mkdir -p $(OUTDIR)
	$(CC) $(CFLAGS_RELEASE) -o $(OUTFILE) $^

build-debug: $(DEPENDS)
	mkdir -p $(OUTDIR)
	$(CC) $(CFLAGS_DEBUG) -o $(OUTFILE) $^

run:
	@if [ ! -e $(OUTFILE) ]; then make build; fi
	./$(OUTFILE) $(ARG1) $(ARG2) $(ARG3)

clean:
	rm -rf $(OUTDIR)

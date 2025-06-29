MAKEFILES = stopwatch.Makefile timer.Makefile

.PHONY: all build run clean
all: build

build: $(MAKEFILES)
	make -f stopwatch.Makefile build
	make -f timer.Makefile build

run:
	make -f stopwatch.Makefile run
	make -f timer.Makefile run

clean:
	make -f stopwatch.Makefile clean
	make -f timer.Makefile clean
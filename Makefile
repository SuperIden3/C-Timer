SRCS = $(wildcard ./src/*.c)
SHARED = ./src/shared/
OUT_DIR = ./out/
OUTS = $(addprefix $(OUT_DIR), $(notdir $(SRCS:.c=)))

CC = gcc
CFLAGS = -s -O2 -Wall -Wextra -Wpedantic -Werror -I $(SHARED)

.PHONY: all clean

all: $(OUTS)

$(OUT_DIR): $(SRCS)
	mkdir -p $(OUT_DIR)

$(OUTS): $(SRCS) $(OUT_DIR)
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf $(OUT_DIR)


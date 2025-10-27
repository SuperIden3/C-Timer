SRCS = $(wildcard ./src/*.c)
SHARED = ./src/shared/
OUT_DIR = ./out/
OUTS = $(addprefix $(OUT_DIR), $(notdir $(SRCS:.c=)))

CC = gcc
CFLAGS = -s -O2 -Wall -Wextra -Wpedantic -Werror -I $(SHARED)

.PHONY: all clean

all: $(OUTS)
.PHONY: run_timer run_stopwatch clean

$(OUT_DIR): $(SRCS)
	@echo "Making \"$(OUT_DIR)\"..."
	mkdir -p $(OUT_DIR)
	@echo "Successfully made \"$(OUT_DIR)\"."

$(OUT_DIR)%: ./src/%.c $(OUT_DIR)
	$(CC) $(CFLAGS) $< -o $@
	@echo "Compiled $< into $@"

run_timer: $(OUTS)
	./$(OUT_DIR)/timer $(ARG1) $(ARG2) $(ARG3)

run_stopwatch: $(OUTS)
	./$(OUT_DIR)/stopwatch

clean:
	rm -rf $(OUT_DIR)
	@echo "Removed $(OUT_DIR)"


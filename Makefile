.SILENT:

# Name of the executable file to be generated
NAME        = push_swap
CHECKER     = checker

# Compiler
CC          = cc -g
FLAGS       = -Wall -Wextra -Werror -fsanitize=address

RM          = /bin/rm -rf

# Directory to store object files
OBJS_DIR    = objs/

# Color codes for terminal output
RESET       = \033[0m
GREEN       = \033[1;32m

# Directories containing source files
SRC_DIRS := srcs

# Find all .c files recursively within SRC_DIRS
SRCS := $(shell find $(SRC_DIRS) -name '*.c')

# Generate object file paths from source file paths
OBJS := $(patsubst $(SRC_DIRS)/%.c,$(OBJS_DIR)%.o,$(SRCS))

# Compilation output
COMPILE_COUNT = 0
NUM_SRCS    = $(words $(SRCS))

# Default target
all: $(NAME)

bonus: $(CHECKER)

$(NAME): EXEC_NAME = $(NAME)


$(CHECKER): EXEC_NAME = $(CHECKER)

$(CHECKER) $(NAME): $(OBJS)
	@$(CC) $(FLAGS) $(OBJS) -o $(EXEC_NAME)

# Rule to compile each source file into an object file
# Also prints a progress bar
$(OBJS_DIR)%.o: $(SRC_DIRS)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(FLAGS) -c $< -o $@
	@$(eval COMPILE_COUNT=$(shell echo $$(($(COMPILE_COUNT)+1))))
	@printf "\r[$(GREEN)%3d%%$(RESET)] Compiling: $<" $$(($(COMPILE_COUNT) * 100 / $(NUM_SRCS)))

# Rule to clean object files
clean:
	$(RM) $(OBJS_DIR)

# Rule to clean object files and the executables
fclean: clean
	$(RM) $(NAME) $(CHECKER)

# Rule to clean object files, the executables, and recompile
re: fclean all

# Phony targets
.PHONY: all clean fclean re bonus

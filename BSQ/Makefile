CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS_DIR = srcs
OBJ_DIR = obj
INC_DIR = includes

SRCS =	char_utils.c \
	check_utils.c \
	content_filter.c \
	files.c \
	finder.c \
	main.c \
	nbr_utils.c \
	solver.c

OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)

NAME = bsq

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

$(OBJ_DIR)/%.o: $(SRCS_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I $(INC_DIR) -o $@ -c $< -g

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

$(OBJ_DIR)/char_utils.o: $(INC_DIR)/bsq.h
$(OBJ_DIR)/check_utils.o: $(INC_DIR)/bsq.h
$(OBJ_DIR)/content_filter.o: $(INC_DIR)/bsq.h
$(OBJ_DIR)/files.o: $(INC_DIR)/bsq.h
$(OBJ_DIR)/finder.o: $(INC_DIR)/bsq.h
$(OBJ_DIR)/main.o: $(INC_DIR)/bsq.h
$(OBJ_DIR)/nbr_utils.o: $(INC_DIR)/bsq.h
$(OBJ_DIR)/solver.o: $(INC_DIR)/bsq.h

.PHONY: all clean fclean re

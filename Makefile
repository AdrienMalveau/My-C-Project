CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c99 -I.
EXEC = project

OBJ_DIR = compile_FILE

SRC = project.c list.c delete.c \
      Forms/circle.c Forms/line.c Forms/square.c Forms/rectangle.c Forms/ellipse.c \
      Modification/color.c Modification/resize.c

OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Nettoyage : on supprim simplement le dossier OBJ_DIR
clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(EXEC)

re: fclean all

.PHONY: all clean fclean re
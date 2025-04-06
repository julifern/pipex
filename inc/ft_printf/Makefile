NAME = ft_printf.a

INCLUDES = inc/

AR = ar rcs

CFLAGS = -I$(INCLUDES) -Wall -Werror -Wextra
CC = cc

SRC_DIR = src/
SRC_NAME =	ft_printf.c \
			ft_printf_utils.c \
			ft_printf_options.c

OBJ_DIR = obj/
OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ = $(patsubst %, $(OBJ_DIR)%, $(OBJ_NAME))
$(OBJ_DIR)%.o:$(SRC_DIR)%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $< -c -o $@

$(NAME): $(OBJ)
	@$(AR) $(NAME) $(OBJ)

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)
	@echo "\033[1;31m Deleted $(NAME)"

all: $(NAME)

re: fclean all
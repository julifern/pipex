NAME = libft.a

INCLUDES = inc/

AR = ar rcs

CFLAGS = -I$(INCLUDES) -Wall -Werror -Wextra
CC = cc

SRC_DIR = src/
SRC_NAME =	ft_count_array.c ft_free_array.c ft_strjoin_free.c ft_memcmp.c ft_memchr.c ft_split.c ft_itoa.c ft_striteri.c ft_strmapi.c ft_strtrim.c ft_putchar_fd.c ft_putnbr_fd.c ft_putendl_fd.c ft_putstr_fd.c ft_strjoin.c ft_substr.c ft_strdup.c ft_calloc.c ft_memmove.c ft_memcpy.c ft_bzero.c ft_atoi.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_memset.c ft_strchr.c ft_strlcat.c ft_strlcpy.c ft_strnstr.c ft_strlen.c ft_strncmp.c ft_strrchr.c ft_tolower.c ft_toupper.c ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c ft_lstclear_bonus.c ft_lstdelone_bonus.c ft_lstiter_bonus.c ft_lstlast_bonus.c ft_lstmap_bonus.c ft_lstnew_bonus.c ft_lstsize_bonus.c

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

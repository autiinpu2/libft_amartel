CC = cc

CFLAGS = -Wall -Wextra -Werror

BUILD_DIR = build/

OBJ = $(patsubst $(SRC_DIR)%.c,$(BUILD_DIR)%.o,$(SRC))


SRC_DIR = src/

SRC = \
	$(SRC_DIR)ft_atoi.c \
	$(SRC_DIR)ft_bzero.c \
	$(SRC_DIR)ft_calloc.c \
	$(SRC_DIR)ft_isalnum.c \
	$(SRC_DIR)ft_isalpha.c \
	$(SRC_DIR)ft_isascii.c \
	$(SRC_DIR)ft_isdigit.c \
	$(SRC_DIR)ft_isprint.c \
	$(SRC_DIR)ft_memchr.c \
	$(SRC_DIR)ft_memcmp.c \
	$(SRC_DIR)ft_memcpy.c \
	$(SRC_DIR)ft_memmove.c \
	$(SRC_DIR)ft_memset.c \
	$(SRC_DIR)ft_strchr.c \
	$(SRC_DIR)ft_strdup.c \
	$(SRC_DIR)ft_strlcat.c \
	$(SRC_DIR)ft_strlcpy.c \
	$(SRC_DIR)ft_strlen.c \
	$(SRC_DIR)ft_strncmp.c \
	$(SRC_DIR)ft_strnstr.c \
	$(SRC_DIR)ft_strrchr.c \
	$(SRC_DIR)ft_substr.c \
	$(SRC_DIR)ft_tolower.c \
	$(SRC_DIR)ft_toupper.c \
	$(SRC_DIR)ft_strjoin.c \
	$(SRC_DIR)ft_split.c \
	$(SRC_DIR)ft_strtrim.c \
	$(SRC_DIR)ft_itoa.c \
	$(SRC_DIR)ft_strmapi.c \
	$(SRC_DIR)ft_striteri.c \
	$(SRC_DIR)ft_putchar_fd.c \
	$(SRC_DIR)ft_putendl_fd.c \
	$(SRC_DIR)ft_putnbr_fd.c \
	$(SRC_DIR)ft_putstr_fd.c \
	$(SRC_DIR)ft_lstadd_front.c \
	$(SRC_DIR)ft_lstlast.c \
	$(SRC_DIR)ft_lstnew.c \
	$(SRC_DIR)ft_lstsize.c \
	$(SRC_DIR)ft_lstdelone.c \
	$(SRC_DIR)ft_lstadd_back.c \
	$(SRC_DIR)ft_lstclear.c \
	$(SRC_DIR)ft_lstiter.c \
	$(SRC_DIR)ft_lstmap.c \
	$(SRC_DIR)get_next_line.c \
	$(SRC_DIR)get_next_line_utils.c

INCLUDE = -Iincludes

NAME = libft.a

all: $(NAME)

bonus: $(BUILD_DIR) $(OBJ)
	ar rcs $(NAME) $(OBJ)

$(BUILD_DIR):
	@mkdir -p $@

$(NAME): $(BUILD_DIR) $(OBJ)
	ar rcs $(NAME) $(OBJ)
$(BUILD_DIR)%.o : $(SRC_DIR)%.c
	$(CC) $(CFLAGS) $(INCLUDE) $^ -o $@ -c

fclean: clean
	rm -f $(NAME)

clean:
	rm -rf $(BUILD_DIR)

re: fclean $(NAME)
.PHONY: all clean fclean re bonus

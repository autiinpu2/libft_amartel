CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror -g -MP -MMD
AR			:= ar rcs
SOURCES := \
	src/ft_abs.c \
	src/ft_atoi.c \
	src/ft_bzero.c \
	src/ft_calloc.c \
	src/ft_isalnum.c \
	src/ft_isalpha.c \
	src/ft_isascii.c \
	src/ft_isdigit.c \
	src/ft_isspace.c \
	src/ft_isprint.c \
	src/ft_memchr.c \
	src/ft_memcmp.c \
	src/ft_memcpy.c \
	src/ft_memmove.c \
	src/ft_memset.c \
	src/ft_strchr.c \
	src/ft_strdup.c \
	src/ft_strlcat.c \
	src/ft_strlcpy.c \
	src/ft_strncmp.c \
	src/ft_strlen.c \
	src/ft_strcmp.c \
	src/ft_strnstr.c \
	src/ft_strrchr.c \
	src/ft_substr.c \
	src/ft_tolower.c \
	src/ft_toupper.c \
	src/ft_strjoin.c \
	src/ft_split.c \
	src/ft_strtrim.c \
	src/ft_itoa.c \
	src/ft_strmapi.c \
	src/ft_striteri.c \
	src/ft_putchar_fd.c \
	src/ft_putendl_fd.c \
	src/ft_putnbr_fd.c \
	src/ft_putnbr.c \
	src/ft_putstr_fd.c \
	src/ft_lstadd_back.c \
	src/ft_lstadd_front.c \
	src/ft_lstlast.c \
	src/ft_lstnew.c \
	src/ft_lstdelone.c \
	src/ft_lstsize.c \
	src/ft_lstclear.c \
	src/ft_lstiter.c \
	src/ft_lstmap.c \
	src/ft_atol.c \
	src/ft_atoll.c \
	src/ft_atoi_base.c \
	src/ft_strndup.c \
	src/get_next_line.c \
	src/ft_dprintf/ft_dprintf.c \
	src/ft_dprintf/type_handler/basic_type.c \

INCLUDE	:= -Iincludes
NAME	:= libft.a
OBJS	:= $(SOURCES:.c=.o)
DEPS	:= $(SOURCES:.c=.d)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o : %.c
	$(CC) $(CFLAGS) $(INCLUDE) $< -o $@ -c

fclean: clean
	rm -f $(NAME)

clean:
	rm -f $(OBJS) $(DEPS)

re: fclean
	$(MAKE) all

-include $(DEPS)

.PHONY: all clean fclean re

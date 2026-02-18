CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror -g -MP -MMD
AR			:= ar rcs
SRC			:= ft_atoi.c ft_bzero.c ft_calloc.c	\
	ft_isalnum.c ft_isalpha.c ft_isascii.c		\
	ft_isdigit.c ft_isspace.c ft_isprint.c		\
	ft_memchr.c ft_memcmp.c ft_memcpy.c			\
	ft_memmove.c ft_memset.c ft_strchr.c		\
	ft_strdup.c ft_strlcat.c ft_strlcpy.c		\
	ft_strncmp.c ft_strlen.c ft_strcmp.c		\
	ft_strnstr.c ft_strrchr.c ft_substr.c		\
	ft_tolower.c ft_toupper.c ft_strjoin.c		\
	ft_split.c ft_strtrim.c ft_itoa.c			\
	ft_strmapi.c ft_striteri.c ft_putchar_fd.c	\
	ft_putendl_fd.c ft_putnbr_fd.c ft_putnbr.c	\
	ft_putstr_fd.c ft_lstadd_back.c				\
	ft_lstadd_front.c ft_lstlast.c ft_lstnew.c	\
	ft_lstdelone.c ft_lstsize.c ft_lstclear.c	\
	ft_lstiter.c ft_lstmap.c ft_atol.c			\
	ft_atoll.c ft_atoi_base.c ft_strndup.c		\

FT_DPRINFT	:= ft_dprintf.c type_handler/basic_type.c
GNL			:= get_next_line.c
SOURCES		:=									\
	$(addprefix src/, $(SRC))					\
	$(addprefix src/, $(GNL))					\
	$(addprefix src/ft_dprintf/, $(FT_DPRINFT))	\

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

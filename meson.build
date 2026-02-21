project(
  'libft',
  'c',
  meson_version : '>= 0.63.0',
  version : '0.1.1',
  default_options : [
    'warning_level=3',
    'optimization=3'
  ],
)

sources = files(
  'src/ft_atoi.c',
  'src/ft_atoi_base.c',
  'src/ft_atol.c',
  'src/ft_atoll.c',
  'src/ft_bzero.c',
  'src/ft_calloc.c',
  'src/ft_isalnum.c',
  'src/ft_isalpha.c',
  'src/ft_isascii.c',
  'src/ft_isdigit.c',
  'src/ft_isprint.c',
  'src/ft_isspace.c',
  'src/ft_itoa.c',
  'src/ft_lstadd_back.c',
  'src/ft_lstadd_front.c',
  'src/ft_lstclear.c',
  'src/ft_lstdelone.c',
  'src/ft_lstiter.c',
  'src/ft_lstlast.c',
  'src/ft_lstmap.c',
  'src/ft_lstnew.c',
  'src/ft_lstsize.c',
  'src/ft_memchr.c',
  'src/ft_memcmp.c',
  'src/ft_memcpy.c',
  'src/ft_memmove.c',
  'src/ft_memset.c',
  'src/ft_putchar_fd.c',
  'src/ft_putendl_fd.c',
  'src/ft_putnbr_fd.c',
  'src/ft_putstr_fd.c',
  'src/ft_split.c',
  'src/ft_strchr.c',
  'src/ft_strdup.c',
  'src/ft_striteri.c',
  'src/ft_strjoin.c',
  'src/ft_strlcat.c',
  'src/ft_strlcpy.c',
  'src/ft_strlen.c',
  'src/ft_strmapi.c',
  'src/ft_strncmp.c',
  'src/ft_strndup.c',
  'src/ft_strnstr.c',
  'src/ft_strrchr.c',
  'src/ft_strtrim.c',
  'src/ft_substr.c',
  'src/ft_tolower.c',
  'src/ft_toupper.c',
  'src/ft_strcmp.c',
  'src/get_next_line.c',
  'src/ft_putnbr.c',
  'src/ft_dprintf/ft_dprintf.c',
  'src/ft_dprintf/type_handler/basic_type.c'
)

includes = include_directories('includes')
# Install header 'libft.h'
subdir('includes')

libft = both_libraries(
  'ft',
  sources,
  install : true,
  include_directories : includes,
)

libft_dep = declare_dependency(include_directories : includes, link_with: libft)
meson.override_dependency('libft', libft_dep)

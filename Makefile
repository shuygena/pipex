NAME = pipex
INC = pipex.h
INC_BONUS = pipex_bonus/pipex_bonus.h
DEFS = 		ft_calloc.c \
            ft_strcat.c \
            ft_strncmp.c \
            ft_substr.c \
            ft_split.c \
            pipex.c \
            pipex_utils.c \
            main.c

BONUS_DEFS = pipex_bonus/ft_calloc_bonus.c \
            pipex_bonus/ft_strcat_bonus.c \
            pipex_bonus/ft_strncmp_bonus.c \
            pipex_bonus/ft_substr_bonus.c \
            pipex_bonus/ft_split_bonus.c \
            pipex_bonus/pipex_bonus.c \
            pipex_bonus/pipex_utils_bonus.c \
            pipex_bonus/get_next_line_bonus.c \
            pipex_bonus/get_next_line_utils_bonus.c \
            pipex_bonus/redirects_bonus.c \
            pipex_bonus/main_bonus.c


OBJS = $(DEFS:.c=.o)
BONUS_OBJ = $(BONUS_DEFS:.c=.o)

all: $(NAME)

%.o: %.c $(INC)
	gcc -Wall -Werror -Wextra -c $< -o $@

$(NAME): $(OBJS) $(INC)
	gcc -Wall -Werror -Wextra $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS) $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME)

bonus: $(BONUS_OBJ) $(INC_BONUS)
	gcc -Wall -Werror -Wextra $(BONUS_OBJ) -o $(NAME)

re: fclean all

NAME = so_long

CC = gcc

AR	= ar -rcs

CFLAGS	= -Wall -Wextra -Werror

MLX =  -lmlx -framework OpenGL -framework AppKit

FILES = error_game.c ft_itoa.c ft_split.c hole_move.c destroy.c\
	move.c respone_obj.c respone.c so_long.c

objets = $(FILES:.c=.o)

$(NAME):$(objets)
	$(CC) $(CFLAGS) $(MLX) -o $(NAME) $(FILES) -g3

all :$(NAME)

clean :
	$(RM) $(objets) $(objets_b)

fclean : clean
	$(RM) $(NAME)

re : fclean all

#  github bigin
# system("leaks a.out");

ADD = git add .

read :=	@echo "${C_GREEN}Add Commit Plz !!${C_RES}" && read -p "-> " enter \
		&& git commit -m $${enter}

PU = git push origin master

commit = git log --graph --oneline --decorate HEAD^..HEAD

push :
	@$(commit)
	@$(ADD)
	$(read)
	$(PU)
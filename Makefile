mlx = gcc -lmlx -framework OpenGL -framework AppKit so_long.c ft_split.c move.c error_game.c respone.c respone_obj.c hole_move.c ft_itoa.c
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
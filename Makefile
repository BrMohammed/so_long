mlx = gcc -lmlx -framework OpenGL -framework AppKit so_long.c
#  github bigin

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
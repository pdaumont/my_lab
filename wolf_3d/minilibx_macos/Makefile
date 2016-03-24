#
#

NOM=libmlx.a
SRC= mlx_shaders.c mlx_new_window.m mlx_init_loop.m mlx_new_image.m mlx_xpm.c mlx_int_str_to_wordtab.c
OBJ1=$(SRC:.c=.o)
OBJ=$(OBJ1:.m=.o)
CFLAGS+=-O2

LBLUE	= \033[1;34m
LGREEN	= \033[1;32m
NC		= \033[0m

all: $(NOM)

$(NOM):	prefix $(OBJ) suffix
	@ar -r $(NOM) $(OBJ) > /dev/null
	@ranlib $(NOM) > /dev/null

%.o: %.c
	@echo "-\c"
	@cc -O2   -c -o $@ $^

%.o: %.m
	@echo "-\c"
	@cc -O2   -c -o $@ $^

clean:
	@rm -f $(NOM) $(OBJ) *~
	@rm -f mlx_app

re: clean all

prefix:
	@echo "$(LBLUE)Compilation de la mlx$(NC) ... [$(LGREEN)\c"

suffix:
	@echo "$(NC)]\t[$(LGREEN)OK$(NC)]"
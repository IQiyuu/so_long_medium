NAME = so_long
LIB = slime_attak.a
LIBFT = libft/libft.a

FILES = map_manager\
		moves\
		pathfinder\
		reef\
		struct_init\
		struct_init_bis\
		utils\
		window_manager\
		graph_moves\
		ennemy_manager\
		end_game\
		animation\
		key_manager\
		error_manager\
		menumoves\
		hook_manager\
		end_game_bis\
		window_game\
		window_menu\
		utils2\
		utils3


S = $(foreach f, $(FILES), srcs/$(f).c)

OBJ = $(S:.c=.o)

CFLAGS = -Wall -Wextra -Werror -I headers/ -I minilibx/include
G_FLG = minilibx/libmlx42.a -lglfw -L "/Users/$(shell echo $(USER))/.brew/opt/glfw/lib/"

C1			= $(shell bc <<< "((($(CMP_COUNT)*100)/($(CMP_TOTAL) / 2))*255)/200")
C2			= $(shell bc <<< "((($(CMP_COUNT)*100)/($(CMP_TOTAL) / 2))*255)/100")
C4			= $(shell bc <<< "255 - (((($(CMP_COUNT) - ($(CMP_TOTAL) / 2))*100)/($(CMP_TOTAL) / 2))*255)/100")
C5			= $(shell bc <<< "255 - $(C1)")
CMP_TOTAL	= $(shell awk -F' ' '{printf NF}' <<< "$(S) $(S_BON)")
CMP_COUNT	= $(shell ls | grep -c '\.o')

CLEAR		= "\x1b\2K\r
GREEN		= \x1b[38;2;0;255;0m
L_GREEN		= \x1b[38;2;100;255;100m
WHITE		= \x1b[0m
CMP_OK		= has been successfully compiled!                                                    \n
CMP_DELETE	= has been successfully deleted!													 \n

RBW_P1		= \x1b[38;2;$(C4);255;$(C5)m $(CMP_COUNT) / $(CMP_TOTAL) » $<                                                    
RBW_P2		= \x1b[38;2;255;$(C2);$(C1)m $(CMP_COUNT) / $(CMP_TOTAL) » $<                                                    


all: $(NAME)

run: all
	./so_long

norminette:
	@printf $(CLEAR)$(L_GREEN)"
	@norminette $(S) headers/*.h libft/*.c

$(NAME): minilibx/libmlx42.a $(LIBFT) $(OBJ)
	@ar -rcs $(LIB) $(OBJ)
	gcc -o $(NAME) srcs/main.c $(LIB) $(CFLAGS) $(G_FLG)
	@printf "\n$(WHITE)> $(GREEN)$@ $(CMP_OK)$(WHITE)"

.c.o:
	gcc $(CFLAGS) -o $@ -c $<
	@$(eval CMP_COUNT = $(shell expr $(CMP_COUNT) + 1))
	@if [ $(CMP_COUNT) -gt $(shell expr $(CMP_TOTAL) / 2) ]; \
		then printf $(CLEAR)>$(RBW_P1)";\
		else printf $(CLEAR)>$(RBW_P2)";\
	fi

$(LIBFT):
	@make -C libft/
	@cp $(LIBFT) $(LIB)

minilibx/libmlx42.a:
	@make -C minilibx

clean:
	@make -C libft/ clean
	@rm -rf $(OBJ) srcs/main.o
	@printf "> $(GREEN)all .o $(CMP_DELETE)$(WHITE)"

fclean: clean
	@rm -rf $(LIB) $(LIBFT) $(NAME)
	@printf "> $(GREEN)$(LIB), $(LIBFT) and $(NAME) $(CMP_DELETE)$(WHITE)"

re: fclean all

.PHONY: all bonus clean fclean re

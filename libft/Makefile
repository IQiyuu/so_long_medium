NAME = libft.a

CUR_DIR = libft/ 

FILES = ft_isalpha\
	  ft_isdigit\
	  ft_isalnum\
	  ft_isascii\
	  ft_isprint\
	  ft_strlen\
	  ft_bzero\
	  ft_memset\
	  ft_memcpy\
	  ft_memmove\
	  ft_strlcpy\
	  ft_strlcat\
	  ft_toupper\
	  ft_tolower\
	  ft_strchr\
	  ft_strrchr\
	  ft_strncmp\
	  ft_memchr\
	  ft_memcmp\
	  ft_strnstr\
	  ft_atoi\
	  ft_calloc\
	  ft_strdup\
	  ft_substr\
	  ft_strjoin\
	  ft_itoa\
	  ft_strmapi\
	  ft_striteri\
	  ft_putchar_fd\
	  ft_putstr_fd\
	  ft_putendl_fd\
	  ft_putnbr_fd\
	  ft_split\
	  ft_min\
	  ft_max\
	  get_next_line\
	  get_next_line_utils\
	  ft_lstadd_back\
	  ft_lstnew\
	  ft_lstlast\
	  ft_nbr_of\
	  ft_printf\
	  conversions\
	  ft_convertbase\
	  ft_lstclear\
	  ft_lstdelone\
	  ft_umax\
	  ft_lstsize

S = $(foreach f, $(FILES), $(f).c)
OBJ = $(S:.c=.o)

CFLAGS = -Wall -Wextra -Werror -I ../headers

C1			= $(shell bc <<< "((($(CMP_COUNT)*100)/($(CMP_TOTAL) / 2))*255)/200")
C2			= $(shell bc <<< "((($(CMP_COUNT)*100)/($(CMP_TOTAL) / 2))*255)/100")
C4			= $(shell bc <<< "255 - (((($(CMP_COUNT) - ($(CMP_TOTAL) / 2))*100)/($(CMP_TOTAL) / 2))*255)/100")
C5			= $(shell bc <<< "255 - $(C1)")
CMP_TOTAL	= $(shell awk -F' ' '{printf NF}' <<< "$(S) $(S_BON)")
CMP_COUNT	= $(shell ls | grep -c '\.o')

CLEAR		= "\x1b\2K\r
GREEN		= \x1b[38;2;0;255;0m
WHITE		= \x1b[0m
CMP_OK		= has been successfully compiled!                                                    \n
CMP_DELETE	= has been successfully deleted!													 \n

RBW_P1		= \x1b[38;2;$(C4);255;$(C5)m $(CMP_COUNT) / $(CMP_TOTAL) » $<                                                     
RBW_P2		= \x1b[38;2;255;$(C2);$(C1)m $(CMP_COUNT) / $(CMP_TOTAL) » $<                                                     

all: $(NAME)

$(NAME): $(OBJ)
	@ar -rc $(NAME) $(OBJ)
	@printf "\n$(WHITE)> $(GREEN)$(NAME) $(CMP_OK)"

.c.o:
	@gcc $(CFLAGS) -o $@ -c $<
	@$(eval CMP_COUNT = $(shell expr $(CMP_COUNT) + 1))
	@if [ $(CMP_COUNT) -gt $(shell expr $(CMP_TOTAL) / 2) ]; \
		then printf $(CLEAR)>$(RBW_P1)";\
		else printf $(CLEAR)>$(RBW_P2)";\
	fi

clean:
	@rm -rf $(OBJ)
	@printf "$(WHITE)>$(GREEN) all .o in $(CUR_DIR)$(CMP_DELETE)$(WHITE)"

re: fclean all

.PHONY: all bonus clean fclean re

NAME = minishell
CC = gcc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror -g


SRCS =	./main.c \
		./parsing.c \
		./init_parse.c \
		./parse_redir.c \
		./parse_redir_utils.c

LIBFT = libft.a
LIBFT_DIR = ./libft
LIBS = -lreadline -L$(HOME)/.brew/opt/readline/lib
OBJS_DIR = ./objs
INC_DIR1 =	./headers
INC_DIR2 = ./libft
READLINE_DIR = $(HOME)/.brew/opt/readline/include

SRCS_DIR =	srcs \
			srcs/parsing

OBJS = $(addprefix $(OBJS_DIR)/, $(notdir $(SRCS:.c=.o)))

SAN =	-fsanitize=address -fsanitize=undefined -fno-sanitize-recover=all \
		-fsanitize=float-divide-by-zero -fsanitize=float-cast-overflow \
		-fno-sanitize=null -fno-sanitize=alignment

vpath %.c $(SRCS_DIR)

all : $(NAME)
$(NAME) : $(OBJS)
	@make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(SAN) $(LIBS) -o $@ $^ -L$(LIBFT_DIR) -lft

$(OBJS_DIR) :
	@mkdir -p $(OBJS_DIR)

$(OBJS_DIR)/%.o : %.c | $(OBJS_DIR)
	@$(CC) $(CFLAGS) -I$(READLINE_DIR) -o $@  -I$(INC_DIR1) -I$(INC_DIR2) -I$(LIBFT_DIR) -c $^

san:
	@ all $(ADD_SAN)

debug:
	@$(MAKE) -n $(NAME)

clean :
	@$(RM) $(OBJS_DIR)
	@$(RM) minishell
	@$(MAKE) -C $(LIBFT_DIR) fclean

fclean : clean
	@$(RM) $(NAME)
	@make -C libft fclean

echo:
	$(CC) srcs/Builtins/echo.c

re : fclean all
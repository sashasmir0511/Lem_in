GCC = gcc
CFLAGS = -Wall -Werror -Wextra

NAME = lem-in
INC_DIR = include
SRC_DIR = src
OBJ_DIR = obj

SRC = main.c get_ants.c error.c debug.c\
	rooms_new.c rooms_add.c rooms_del.c \
	room_new.c room_add.c room_del.c \
	path_add.c path_new.c paths_del.c solver.c \
	ant_add.c ant_new.c ants_del.c \
	dijkstra.c print_solver.c path_del.c\
	add_links.c
OBJ = $(SRC:.c=.o)

SRCS=$(addprefix $(SRC_DIR)/,$(SRC))
OBJS=$(addprefix $(OBJ_DIR)/,$(OBJ))

all: $(NAME)

$(NAME): $(OBJS)
	@make -C ft_printf
	@$(GCC) $(CFLAGS) -o $(NAME) $(OBJS) -L ft_printf -lftprintf

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c $(INC_DIR)/lem_in.h
	@mkdir -p $(OBJ_DIR)
	$(GCC) $(CFLAGS) -I $(INC_DIR) -g -c $< -o $@

clean:
	@make clean -C ft_printf
	@/bin/rm -rf $(OBJ_DIR)

fclean: clean
	@/bin/rm -f $(NAME)
	@make fclean -C ft_printf

re: fclean all

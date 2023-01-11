NAME = cub3D

# SOURCE :	https://www.playfuljs.com/a-first-person-engine-in-265-lines/
# 			https://lodev.org/cgtutor/raycasting.html

SRCS =	src/main.c 

ENGINE =	src/engine/camera.c \
			src/engine/draw.c \
			src/engine/move_utils.c \
			src/engine/move.c \
			src/engine/raycast.c \
			src/engine/screen.c \
			src/engine/speed.c \
			src/engine/textures.c \
			src/engine/wall.c 

PARSING =	src/parsing/parsing.c \
			src/parsing/check_file.c \
			src/parsing/utils.c \
			src/parsing/init.c \
			src/parsing/error.c \
			src/parsing/check_map.c \
			src/parsing/make_map.c \
			src/parsing/check_map_wall.c

GENERAL =	src/general/error.c \
			src/general/loop.c 

UTILS =		src/utils/get_pos_player.c \
			src/utils/map_utils.c \
			src/utils/set_natif.c \
			src/utils/set_struct.c 

KEY = 		src/engine/key/handle_key.c \
			src/engine/key/key_pressed.c \
			src/engine/key/key_released.c

STRING =	src/string/string_manip.c \
			src/string/matrice_manip.c 

OBJS = ${SRCS:.c=.o} ${ENGINE:.c=.o} ${PARSING:.c=.o} ${GENERAL:.c=.o} ${KEY:.c=.o} ${UTILS:.c=.o} ${STRING:.c=.o}

CC		= gcc
RM		= rm -f

CFLAGS =  -Wall -Wextra -Werror 

HEADER = -I./includes -I./minilibx -I./gnl

BUFFER_SIZE = -D BUFFER_SIZE=1024

MLX_FLAGS = -framework OpenGL -framework AppKit -lmlx

MLX = libmlx.a

BUFFER_SIZE = -D BUFFER_SIZE=1024

.c.o:
		${CC} ${CFLAGS} ${HEADER} ${BUFFER_SIZE} -c $< -o ${<:.c=.o}

$(NAME): $(MLX) ${OBJS}
		@printf "\n$(CY)Generating cub3d...$(RC)\n"
		@${CC} ${CFLAGS} ${HEADER} ${BUFFER_SIZE} ${OBJS} -o ${NAME} ${MLX_FLAGS}
		@printf "$(GR)Generating done $(RC)\n"

$(MLX):
		@$(MAKE) -C minilibx
		@mv minilibx/$(MLX) .

all:	${NAME}

clean:
		@printf "$(PP)Deleting the objects...$(RC)\n"
		@$(MAKE) -C minilibx clean
		@${RM} ${OBJS} ./libmlx.a
		@printf "$(PP)Objects deleted...$(RC)\n"

fclean:	clean
		@printf "$(PP)Deleting all files...$(RC)\n"
		@${RM} ${NAME}
		@printf "$(PP)All were deleted...$(RC)\n"

re:		fclean all

run:	all
		./${NAME} map.cub

re_run: re
		./${NAME} test.cub

run_coll: all
		./${NAME} maps/collision.cub
		
.PHONY : all clean fclean re run re_run

GR	= \033[32;1m
CY	= \033[36;1m
RC	= \033[0m
PP = \033[0;35m

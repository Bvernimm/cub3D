NAME = cub3D

# SOURCE :	https://www.playfuljs.com/a-first-person-engine-in-265-lines/
# 			https://lodev.org/cgtutor/raycasting.html

SRCS =	src/main.c 

ENGINE =	src/engine/camera.c \
			src/engine/cutscene.c \
			src/engine/change_map.c \
			src/engine/da_door.c \
			src/engine/display_menu.c \
			src/engine/draw.c \
			src/engine/ending.c \
			src/engine/minimap.c \
			src/engine/move_utils.c \
			src/engine/move.c \
			src/engine/raycast.c \
			src/engine/raycast_utils.c \
			src/engine/screen.c \
			src/engine/shader.c \
			src/engine/floor_sky.c \
			src/engine/speed.c \
			src/engine/textures.c \
			src/engine/move_mouse.c \
			src/engine/wall.c 

ENGINE_M =	src/engine/mouse_move.m

PARSING =	src/parsing/parsing.c \
			src/parsing/utils.c \
			src/parsing/init.c \
			src/parsing/error.c \
			src/parsing/check_map.c \
			src/parsing/make_map.c \
			src/parsing/check_map_wall.c \
			src/parsing/parsing_sprites.c \
			src/parsing/check_caracter.c 

GENERAL =	src/general/destroy.c \
			src/general/error.c \
			src/general/loop.c 

UTILS =		src/utils/get_pos_player.c \
			src/utils/ft_split.c \
			src/utils/map_utils.c \
			src/utils/set_natif.c \
			src/utils/set_struct.c 

KEY =		src/engine/key/action_key.c \
	 		src/engine/key/handle_key.c \
			src/engine/key/key_pressed.c \
			src/engine/key/key_released.c

STRING =	src/string/string_manip.c \
			src/string/matrice_manip.c 

SPRITE =	src/engine/sprite/enemy.c \
			src/engine/sprite/enemy_move.c \
			src/engine/sprite/enemy_move_utils.c \
			src/engine/sprite/sprite_draw.c \
			src/engine/sprite/sprite_load.c \
			src/engine/sprite/sprite_utils.c \
			src/engine/sprite/sprite_utils2.c 

SD_PLAYER = src/engine/sound_player/controler.c \
			src/engine/sound_player/player_utils.c \
			src/engine/sound_player/routine.c \
			src/engine/sound_player/wait_player.c

DOC =		src/engine/document/check_doc.c \
			src/engine/document/document_game.c \
			src/engine/document/document_game2.c \
			src/engine/document/document_tuto.c \
			src/engine/document/draw_document.c 

OBJS = ${SRCS:.c=.o} ${ENGINE:.c=.o} ${ENGINE_M:.m=.o} ${PARSING:.c=.o} ${GENERAL:.c=.o} \
		${KEY:.c=.o} ${UTILS:.c=.o} ${STRING:.c=.o} ${SPRITE:.c=.o} ${SD_PLAYER:.c=.o} ${DOC:.c=.o}

CC		= gcc
RM		= rm -f

CFLAGS = -O3 -Wall -Wextra -Werror

HEADER = -I./includes -I./minilibx -I./gnl

BUFFER_SIZE = -D BUFFER_SIZE=1024

MLX_FLAGS =  -lmlx -framework OpenGL -framework AppKit -lpthread 

MLX = libmlx.a

BUFFER_SIZE = -D BUFFER_SIZE=1024

.c.o:
		${CC} ${CFLAGS} ${HEADER} ${BUFFER_SIZE} -c $< -o ${<:.c=.o}

.m.o:
		@${CC} ${CFLAGS} ${HEADER} -c $< -o ${<:.m=.o}

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
		@./${NAME} ./maps/tutorial.cub

re_run: re
		./${NAME} ./maps/tutorial.cub
		
.PHONY : all clean fclean re run re_run

GR	= \033[32;1m
CY	= \033[36;1m
RC	= \033[0m
PP = \033[0;35m

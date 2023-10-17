# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fpereira <fpereira@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/13 12:06:25 by lleiria-          #+#    #+#              #
#    Updated: 2023/10/17 16:59:30 by fpereira         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -g #-fsanitize=address 
RM			=	rm -f

NAME		=	cub3D

INCLUDE		=	-I ./ mlx_linux/libmlx_Linux.a

SRCS_		=	libft/ft_bzero.c\
				libft/ft_calloc.c\
				libft/ft_isalnum.c\
				libft/ft_isalpha.c\
				libft/ft_isascii.c\
				libft/ft_isdigit.c\
				libft/ft_isprint.c\
				libft/ft_memchr.c\
				libft/ft_memcmp.c\
				libft/ft_memcpy.c\
				libft/ft_memmove.c\
				libft/ft_memset.c\
				libft/ft_strchr.c\
				libft/ft_strlcat.c\
				libft/ft_strlcpy.c\
				libft/ft_strlen.c\
				libft/ft_strncmp.c\
				libft/ft_strnstr.c\
				libft/ft_strrchr.c\
				libft/ft_tolower.c\
				libft/ft_toupper.c\
				libft/ft_atoi.c\
				libft/ft_strdup.c\
				libft/ft_substr.c\
				libft/ft_putchar_fd.c\
				libft/ft_putstr_fd.c\
				libft/ft_putnbr_fd.c\
				libft/ft_putendl_fd.c\
				libft/ft_strjoin.c\
				libft/ft_strtrim.c\
				libft/ft_split.c\
				libft/ft_itoa.c\
				libft/ft_striteri.c\
				libft/ft_strmapi.c\
				main.c \
				exit.c \
				sort_data.c \
				sort_data2.c \
				sort_data3.c \
				get_color.c \
				mlx_init.c\
				init_play.c \
				init_vars.c \
				error.c \
				get_next_line.c \
				get_next_line_utils.c \
				movement/keys.c movement/wasd.c \
				raycasting/raycast.c raycasting/draw_simple.c raycasting/draw_tex.c raycasting/draw_tex_utils.c\
				checks/check_map.c checks/parsing_utils.c checks/check_map_utils.c

SRCS		=	$(addprefix $(_SRC), $(SRCS_))

DEPS		=	./mlx_linux/libmlx_Linux.a

_SRC		=	./src/
_MLX		=	./mlx_linux

OBJS		=	$(patsubst %.c, %.o, $(SRCS))
all:	$(NAME)

$(_OBJ)%.o: $(_SRC)%.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(NAME): $(DEPS) $(OBJS)
	$(CC) $(CFLAGS) -Lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz $(OBJS) -o $(NAME) $(INCLUDE) -L $(_MLX)

./mlx_linux/libmlx_Linux.a:
	cd mlx_linux;./configure

$(_OBJ):
	mkdir $@

clean:
	$(RM) -r $(OBJS)
	cd mlx_linux; make clean

fclean:	clean
	$(RM) -r $(NAME)
	$(RM) -r $(_MLX)libmlx_Linux.a

re:	fclean all
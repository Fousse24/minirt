# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/09 15:31:26 by sfournie          #+#    #+#              #
#    Updated: 2022/02/10 14:25:56 by sfournie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compilation
# INCS_FLAGS has all the -I that are needed. (-Imlx, -Ilibft, etc.)
CC				= gcc
CFLAGS			= -Wall -Wextra
C_ALL			= $(CC) $(CFLAGS) $(INCS_FLAGS) $(INC_MLX)
C_OBJS			= $(C_ALL) -g
C_MAIN			= $(C_ALL) -g $(MAIN) $(OBJS) -lmlx $(C_FWRK) $(LIB_LFT) -o $(NAME)
C_FWRK			= -framework OpenGL -framework AppKit
#

# Program
NAME	= minirt
#

# Directories
DIR_SRCS	= srcs
DIR_OBJS	= objs
DIR_INCS	= includes
DIR_MAINS	= mains
DIR_LFT		= libft
#

# Libraries and Includes
LIB_LFT		= $(DIR_LFT)/libft.a
INC_MLX		= -Imlx
INC_LFT		= $(DIR_LFT)/includes

INCS_ALL	= $(DIR_LFT) $(DIR_INCS) $(INC_LFT)
INCS_FLAGS	= $(patsubst %,-I%,$(INCS_ALL))
#

# Makefiles
MK_LFT		= make -C $(DIR_LFT)
#

# Mains
MAIN		= $(DIR_MAINS)/main.c
#

# Headers
_HEADS	=	minirt.h minirt_struct.h
HEADS		= $(patsubst %,$(DIR_INCS)/%,$(_HEADS))
#

# Sources and Objects
SRCS	=	mlx.c scene.c\
			image.c\
			color.c color_utils.c color_trgb.c\
			input.c\
			object.c\
			shape.c shape_bound.c\
			light.c\
			vector3.c vector3_math.c math_utils.c\
			raytracing.c

_OBJS	= $(SRCS:.c=.o)
OBJS	= $(patsubst %,$(DIR_OBJS)/%,$(_OBJS))

$(DIR_OBJS)/%.o :  %.c
		$(C_OBJS) -c $< -o $@

vpath %.c $(DIR_SRCS)
#

all		: $(NAME)

$(NAME)	: $(HEADS) $(DIR_INCS) $(LIB_LFT) $(SRCS) $(MAIN) $(DIR_OBJS) $(OBJS)
		@ $(C_MAIN)
		# $(shell echo "Compiling minirt done!")
		# $(shell echo "Executable is : $(NAME)")

$(DIR_OBJS)	: 
		@ mkdir objs

$(LIB_LFT)	:
		@ $(MK_LFT) all

clean	: 
		@ rm -rf $(DIR_OBJS)
		@ $(MK_LFT) clean
		# $(shell echo "cub3d cleaned!")

fclean	: clean
		@ $(MK_LFT) fclean
		@ rm -rf $(NAME)

re		: fclean all

.PHONY	: all re clean fclean bonus

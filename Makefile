# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgendel <sgendel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/11 16:21:28 by sgendel           #+#    #+#              #
#    Updated: 2022/04/22 23:14:32 by sgendel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	./so_long

PATHSRCS	=	srcs/

PATHUTILS	=	utils/

LIST		=	./$(PATHSRCS)main.c\
				./$(PATHSRCS)handler_of_errors.c\
				./$(PATHSRCS)parse_map.c\
				./$(PATHSRCS)draw_game.c\
				./$(PATHSRCS)menu.c\
				./$(PATHSRCS)movement.c\
				./$(PATHSRCS)animations.c\
				./$(PATHSRCS)exit.c\
				./$(PATHUTILS)ft_itoa.c\
				./$(PATHUTILS)get_next_line/get_next_line.c\
				./$(PATHUTILS)get_next_line/get_next_line_utils.c\

OBJ			=	$(patsubst %.c, %.o, $(LIST))

HEADER		=	includes/so_long.h

# FLAGS		=	-Wall -Werror -Wextra

LIBXF		=	-lmlx -framework OpenGL -framework AppKit

GREEN = \033[0;32m

RESET = \033[0m

.PHONY:		all clean fclean re

all:		$(NAME)

$(NAME):	$(OBJ) $(HEADER)
	@echo "\nso_long: $(GREEN)object files were created$(RESET)"
	$(CC) $(OBJ)  $(LIBXF) -o $(NAME)
	@echo "so_long: $(GREEN)so long was created$(RESET)"
# $(FLAGS)
%.o: %.c	$(HEADER)
	$(CC) $(FLAGS) -Imlx -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean:		clean
	@rm -f $(NAME)

re:			fclean all


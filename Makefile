# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rsibiet <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/22 17:59:05 by rsibiet           #+#    #+#              #
#    Updated: 2016/02/01 13:25:02 by rsibiet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

FTC = ft_init_fdf.c \
	  ft_calc_coord.c \
	  fdf_up_down.c \
	  fdf_trace_lines.c \
	  fdf_legend.c \
	  fdf_error.c

FTO = $(subst .c,.o,$(FTC))

MLX = -L./minilibX/ -lmlx -framework OpenGL -framework AppKit

.PHONY: all re clean fclean

all: $(NAME)

$(NAME): $(FTO)
	@echo ""
	@make -C ./libft
	@make -C ./MinilibX
	@gcc -o $(NAME) $(FTO) ./libft/libft.a $(MLX)
	@echo "\033[32m$(NAME) created!\033[0m"

%.o: %.c
	@gcc -Wall -Wextra -Werror -I./libft/ -c $<
	@echo "\033[33m.\033[0m\c"

clean:
	@make -C ./libft clean
	@make -C ./MinilibX clean
	@rm -rf $(FTO)
	@echo "\033[33m$(NAME) object deleted!\033[0m"

fclean: clean
	@make -C ./libft fcleana
	@rm -rf $(NAME)
	@echo "\033[31m$(NAME) deleted!\033[0m"

re: fclean all

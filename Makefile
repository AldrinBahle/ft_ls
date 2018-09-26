# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agama <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/28 18:36:22 by angavrel          #+#    #+#              #
#    Updated: 2018/08/30 18:19:36 by agama            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= ft_ls

SRCS_PATH 	= ls/
OBJ_PATH  	= obj/
LIBFT_PATH 	= libft/

FLAGS 		= -Wall -Werror -Wextra
INC 		= -I ./includes/ -I ./$(LIBFT_PATH)includes/

SRCS_NAME = main.c parsing.c analyze_options.c ls_error.c add_new_file.c \
			ft_reverse_lst.c sort_list.c display_all.c lst_blocks_len.c \
			display_list.c display_name.c display_list_details.c get_row_size.c \
			integer_len.c display_list_contents.c lst_swap.c lst_maxlen.c \
			free_list_content.c ft_sort_tab.c init_files_list.c

SRCS = $(addprefix $(SRCS_PATH), $(SRCS_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(SRCS_NAME:.c=.o))

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBFT_PATH)
	@gcc $(FLAGS) $(OBJ) $(INC) -L $(LIBFT_PATH) -lft -o $(NAME)
	@echo "\033[32mBinary \033[1;32m$(NAME)\033[1;0m\033[32m created.\033[0m"

$(OBJ_PATH)%.o: $(SRCS_PATH)%.c
	@mkdir -p obj
	@gcc -c $(FLAGS) $(INC) $< -o $@
	@echo "\033[34m\033[1mCompilation of \033[0m\033[36m$(notdir $<)\033[1m\033[34m done.\033[0m"

clean:
	@make -C $(LIBFT_PATH)/ clean
	@/bin/rm -rf $(OBJ_PATH)
	@echo "\033[31mObjects files \033[1;31m$(OBJS_LIST)\033[1;0m\033[31m removed.\033[0m"

fclean: clean
	@make -C $(LIBFT_PATH)/ fclean
	@/bin/rm -rf $(NAME)
	@echo "\033[31mBin \033[1;31m$(NAME)\033[1;0m\033[31m removed.\033[0m"

re: fclean all

.PHONY: all, clean, fclean, re

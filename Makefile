# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thabeck- <thabeck-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/10 00:17:56 by thabeck-          #+#    #+#              #
#    Updated: 2022/10/12 20:46:56 by thabeck-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	minitalk
CLIENT	=	client
SERVER	=	server

LIBFT		=	./libft/libft.a
LIBFT_DIR	=	./libft

SRC_CLIENT	=	./src/client.c
SRC_SERVER	=	./src/server.c

SRC_DIR			=	./src/
HDR_DIR			=	./inc/

OBJS_CLIENT=$(SRC_CLIENT:.c=.o)
OBJS_SERVER=$(SRC_SERVER:.c=.o)

INC		=	-L $(LIBFT_DIR) -lft

CC			=	gcc
CFLAG		=	-Wall -Wextra -Werror
RM			=	rm -rf

GREEN		=	\e[38;5;118m
BLUE		=	\e[38;5;75m
RESET		=	\e[0m
_SUCCESS	=	[$(GREEN)== SUCCESS ==$(RESET)]
_INFO		=	[$(BLUE)== INFO ==$(RESET)]

all: $(SERVER) $(CLIENT)

$(NAME): all

.c.o:
	@${CC} ${FLAGS} -c $< -o ${<:.c=.o}

$(SERVER): $(OBJS_SERVER) $(LIBFT)
	@ $(CC) $(CFLAG) -o $(SERVER) $(OBJS_SERVER) $(INC)
	@echo "$(_SUCCESS) Server is ready."

$(CLIENT): $(OBJS_CLIENT) $(LIBFT)
	@ $(CC) $(CFLAG) -o $(CLIENT) $(OBJS_CLIENT) $(INC)
	@echo "$(_SUCCESS) Client is ready."

$(LIBFT):
	@ $(MAKE) -C ./libft

bonus: $(CLIENT) $(SERVER)

norm:
	@ norminette $(SRC_DIR) $(HDR_DIR)

clean:	
	@ $(RM) $(OBJS_CLIENT) $(OBJS_SERVER)

fclean: clean
	@ make fclean -C $(LIBFT_DIR)
	@ $(RM) $(CLIENT) $(SERVER)
	@echo "$(_INFO) Client was removed."
	@echo "$(_INFO) Server was removed."

re: fclean all

rebonus: fclean bonus

.PHONY: all clean fclean re minitalk bonus norm

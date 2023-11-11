# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thabeck- <thabeck-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/21 19:09:59 by thabeck-          #+#    #+#              #
#    Updated: 2022/10/12 20:49:32 by thabeck-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a
GREEN		= \033[0;32m
RESET		= \033[0m
CC 			= gcc
CFLAGS 		= -Wall -Werror -Wextra
RM 			= rm -f
HDR			= libft.h
SRCS 		= ft_isalpha.c 			\
			ft_isdigit.c 			\
			ft_isalnum.c 			\
			ft_isascii.c 			\
			ft_isprint.c 			\
			ft_strlen.c 			\
			ft_memset.c 			\
			ft_bzero.c 				\
			ft_memcpy.c 			\
			ft_memmove.c 			\
			ft_strlcpy.c 			\
			ft_strlcat.c 			\
			ft_toupper.c 			\
			ft_tolower.c 			\
			ft_strchr.c 			\
			ft_strrchr.c 			\
			ft_strncmp.c			\
			ft_memchr.c				\
			ft_memcmp.c				\
			ft_strnstr.c			\
			ft_atoi.c 				\
			ft_strdup.c 			\
			ft_calloc.c 			\
			ft_substr.c				\
			ft_strjoin.c			\
			ft_strtrim.c			\
			ft_split.c				\
			ft_itoa.c				\
			ft_strmapi.c			\
			ft_striteri.c			\
			ft_putchar_fd.c			\
			ft_putstr_fd.c			\
			ft_putendl_fd.c			\
			ft_putnbr_fd.c			\
			ft_putstr_color_fd.c	\
			ft_straddchar.c			\
			ft_str_isnumeric.c		\
			

BONUS_SRCS  = ft_lstnew.c			\
			ft_lstadd_front.c  		\
			ft_lstsize.c 			\
			ft_lstlast.c			\
			ft_lstadd_back.c		\
			ft_lstdelone.c 			\
			ft_lstclear.c			\
			ft_lstiter.c			\
			ft_lstmap.c				\
		
OBJS 		= $(SRCS:.c=.o)
BONUS_OBJS 	= $(BONUS_SRCS:.c=.o)

GREEN		=	\e[38;5;118m
BLUE		=	\e[38;5;75m
RESET		=	\e[0m
_SUCCESS	=	[$(GREEN)== SUCCESS ==$(RESET)]
_INFO		=	[$(BLUE)== INFO ==$(RESET)]


all:		$(NAME)

$(NAME): 	$(OBJS) $(HDR)
	@ ar -rcs $(NAME) $(OBJS)
	@echo "$(_SUCCESS) Libft is ready."

bonus:		$(NAME) $(BONUS_OBJS)
	@ ar -rcs $(NAME) $(BONUS_OBJS)
	
.c.o:
	@ $(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

clean:
	@ $(RM) $(OBJS) $(BONUS_OBJS)

fclean:		clean
	@ $(RM) $(NAME)
	@echo "$(_INFO) Libft was removed."

re :		fclean all

.PHONY:		all clean fclean re bonus

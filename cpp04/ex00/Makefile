# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rakman <rakman@student.42istanbul.com.t    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/11 13:28:26 by rakman            #+#    #+#              #
#    Updated: 2026/03/11 13:29:14 by rakman           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = polymorphism

CXX         = c++
CXXFLAGS    = -Wall -Wextra -Werror -std=c++98

RM          = rm -f

SRCS        = main.cpp \
              Animal.cpp \
              Dog.cpp \
              Cat.cpp \
              WrongAnimal.cpp \
              WrongCat.cpp

OBJS        = $(SRCS:.cpp=.o)

all:        $(NAME)

$(NAME):    $(OBJS)
			$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
			$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
			$(RM) $(OBJS)

fclean:     clean
			$(RM) $(NAME)

re:         fclean all

.PHONY:     all clean fclean re

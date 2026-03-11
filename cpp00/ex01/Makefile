# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rakman <rakman@student.42istanbul.com.tr>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/09 15:44:05 by rakman            #+#    #+#              #
#    Updated: 2025/11/12 16:48:39 by rakman           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX 		= c++
CXXFLAGS 	= -Wall -Wextra -Werror -std=c++98
CPPFLAGS	= -Iinc
NAME 		= phonebook
SRCS 		= src/Contact.cpp \
			  src/PhoneBook.cpp \
			  src/PhoneBookSearch.cpp \
			  src/main.cpp

OBJS 		= src/Contact.o \
			  src/PhoneBook.o \
			  src/PhoneBookSearch.o \
			  src/main.o

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -o $(NAME) $(OBJS)
%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

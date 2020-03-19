NAME    =   printf
SRC     =   ./functions/my_printf.c

NAMEM	=	$(shell uname -m)
NAMES	=	$(shell uname -s)
CC      =   gcc
CPPFLAGS	+= -I./include
CFLAGS  +=   -Wall -Wextra
OBJ     =   $(SRC:.c=.o)
RM      =   rm -f

$(NAME) :   my_printf_static my_printf_dynamic

all     :   $(NAME)

my_printf_static	:	$(OBJ)
			ar rc ./lib/libmy_printfs$(NAMEM)-$(NAMES).a ./functions/*.o
			ranlib ./lib/libmy_printfs$(NAMEM)-$(NAMES).a
			$(CC) main.c -L./lib -lmy_printfs$(NAMEM)-$(NAMES) -o s_printf


my_printf_dynamic	:	$(OBJ)
			$(CC) -shared $(CFLAGS) -fpic -o ./lib/libmy_printfd$(NAMEM)-$(NAMES).so $(OBJ)
			$(CC) main.c -L./lib -Wl,-rpath=./lib -lmy_printfd$(NAMEM)-$(NAMES)  -o d_printf

clean   :
			$(RM) $(OBJ)
			$(RM) ./functions/*~*
			$(RM) *~*

fclean  :   clean
			$(RM) d_printf s_printf
			$(RM) ./lib/*

re      :   fclean all

.PHONY  :   all my_printf_static my_printf_dynamic clean fclean re 

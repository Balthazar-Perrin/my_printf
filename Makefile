NAME    =   printf
SRC     =   ./functions/my_printf.c

CC      =   gcc
CPPFLAGS	+= -I./include
CFLAGS  +=   -Wall -Wextra
OBJ     =   $(SRC:.c=.o)
RM      =   rm -f

$(NAME) :   my_printf_static my_printf_dynamic

all     :   $(NAME)

my_printf_static	:	$(OBJ)
#           ar rc libmy_printf_uname -m-uname -s.a ./functions/*.o
			ar rc ./lib/libmy_printfs.a ./functions/*.o
#           ranlib libmy_printf_uname -m-uname -s.a
			ranlib ./lib/libmy_printfs.a
			$(CC) main.c -L./lib -lmy_printfs -o s_printf


my_printf_dynamic	:	$(OBJ)
#           $(CC) -shared $(CFLAGS) -fpic -o libmy_printf_uname -m_uname -s.so $(OBJ)
			$(CC) -shared $(CFLAGS) -fpic -o ./lib/libmy_printfd.so $(OBJ)
			$(CC) main.c -L./lib -lmy_printfd -o d_printf

clean   :
			$(RM) $(OBJ)
			$(RM) ./functions/*~*
			$(RM) *~*

fclean  :   clean
			$(RM) d_printf s_printf
			$(RM) ./lib/*

re      :   fclean all

.PHONY  :   all my_printf_static my_printf_dynamic clean fclean re 

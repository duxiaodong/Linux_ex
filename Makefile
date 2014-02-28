IDIR = ../include
LIBS = -I ${IDIR}
LIBS_1 = -lerror
#OBJS = error.o lstat.o 
#OBJS = lstat.o 
#OBJS = umask.o
#OBJS = unlink.o
#OBJS = utime.o
#OBJS = getc_putc.o
#OBJS = gets_puts.o
#OBJS = tempname_file.o
#OBJS = type_structure.o
#OBJS = fork.o
#OBJS = vfork.o
#OBJS = re_stdin_ex.o
OBJS = re_stdin_ex_2.o





#lstat : ${OBJS}
#umast : ${OBJS}
#unlinke :${OBJS}
#utime :${OBJS}
#getc_putc :${OBJS}
#gets_puts :${OBJS}
#tempname_file :${OBJS}
#type_structure:${OBJS}
#fork:${OBJS}
#vfork:${OBJS}
#re_stdin_ex:${OBJS}
re_stdin_ex_2:${OBJS}




	gcc -o $@ ${OBJS} ${LIBS} ${LIBS_1}

clean :
	rm -f lstat ${OBJS} error.o 

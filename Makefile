IDIR = ../include
LIBS = -I ${IDIR}
LIBS_1 = -lerror
#OBJS = error.o lstat.o 
#OBJS = lstat.o 
#OBJS = umask.o
#OBJS = unlink.o
#OBJS = utime.o
OBJS = getc_putc.o




#lstat : ${OBJS}
#umast : ${OBJS}
#unlinke :${OBJS}
#utime :${OBJS}
getc_putc :${OBJS}
	gcc -o $@ ${OBJS} ${LIBS} ${LIBS_1}

clean :
	rm -f lstat ${OBJS} error.o 

CC      =  cc
CFLAGS  =  -v
EXEC    =  a.out
INCLS   =  
LIBS    =  

OBJS    =  main.o  str_to_list.o

$(EXEC): $(OBJS)
		@echo "linking ..."
		@$(CC)  $(CFLAGS)  -o $(EXEC)  $(OBJS)  $(LIBS)

$(OBJS): list.h
		$(CC)  $(CFLAGS)  $(INCLS)  -c  $*.c

relink:
		@echo "relinking ..."
		@$(CC)  $(CFLAGS)  -o $(EXEC)  $(OBJS)  $(LIBS)

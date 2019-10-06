PGNAME = mainapp

mainapp : 15sub3.o 15main3.o
	gcc -o mainapp 15sub3.o 15main3.o

15sub3.o : 15sub3.c
	gcc -c -o 15sub3.o 15sub3.c

15main3.o : 15main3.c
	gcc -c -o 15main3.o 15main3.c

.PHONY : clean
clean :
	rm -f Message sub.o

.PHONY : check
check :
	check--enable=all /home/flairlink/work/SukkiriC/SC,C15 >checkresult.txt 2>&1 

.PHONY : doc
doc :
	doxygen

.PHONY : all
all :	 clean $(PGNAME) doc


OBJECT = main.o print.o input.o
SRCS = main.c print.c input.c

CFLAGS = -g
TARGET = test
#CC 컴파일러 명령어 매트로
$(TARGET)	: $(OBJECT)
	$(CC) -o $(TARGET) $(OBJECT)
clean :
	rm -f $(OBJECT) $(TARGET) core
ps : 
	ps
main.o : main.o
print.o : print.o
input.o : input.o
#main.o	: main.c
#	gcc -c main.c
#input.o : input.c
#	gcc -c input.c
#print.o : print.o
#	gcc -c print.c
#remove : remove
#	ls 
#	ps


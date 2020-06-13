SRC = ${wildcard *.c}
OBJ = ${patsubst %.c, %.o, $(SRC)}
CFLAGS = -g -Wall

all:$(OBJ) move

$(OBJ): %.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@ 

move:
	mv $(OBJ)  ../

clean:
	$(RM) $(OBJ)

.PHONY:all clean
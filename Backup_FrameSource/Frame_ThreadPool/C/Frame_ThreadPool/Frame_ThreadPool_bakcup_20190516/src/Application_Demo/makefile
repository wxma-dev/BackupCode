SRC = ${wildcard *.c}
OBJ = ${patsubst %.c,%.o, $(SRC)}
CFLAGS = -g -Wall

TARGET = bin_ThreadPool_Frame_Demo

all:$(OBJ) move $(TARGET)

$(OBJ): %.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@ 

move:
	mv $(OBJ)  ../

clean:
	$(RM) $(APPOBJ) $(TARGET) 

OBJLIST = ../Main_Thread_Pool.o \
    ../AddWork_Frame.o \
    ../DoWork_Frame.o \
    ../Common.o

APPOBJ = ../${OBJ}

PATH_LIB_ZJ=/mnt/winFile/5技术理论与实践/Frame_Lib/lib
${TARGET}:${OBJLIST}
	gcc  ${OBJLIST} ${APPOBJ}  ${CFLAGS} -o ${TARGET} -lpthread  -L${PATH_LIB_ZJ} -lPUB -Wl,-rpath=${PATH_LIB_ZJ}

.PHONY:all clean


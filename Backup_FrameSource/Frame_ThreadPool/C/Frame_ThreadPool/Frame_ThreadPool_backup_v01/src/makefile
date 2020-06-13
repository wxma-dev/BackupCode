ThreadPool_Frame:Thread_Pool.o AddWork_Frame.o DoWork_Frame.o Application.o Common.o
	gcc Thread_Pool.o AddWork_Frame.o DoWork_Frame.o Application.o Common.o -o ThreadPool_Frame -lpthread -g
Thread_Pool.o:Thread_Pool.c Struct_Frame.h Log_Frame.h
	gcc -o Thread_Pool.o -c Thread_Pool.c -g
AddWork_Frame.o:AddWork_Frame.c AddWork_Frame.h Struct_Frame.h Log_Frame.h
	gcc -c AddWork_Frame.c -g
DoWork_Frame.o:DoWork_Frame.c DoWork_Frame.h Struct_Frame.h Log_Frame.h
	gcc -c DoWork_Frame.c -g
Application.o:Application.c Application.h
	gcc -c Application.c -g
Common.o:Common.c Common.h
	gcc -c Common.c -g

clean:
	rm -rf DoWork_Frame.o AddWork_Frame.o Thread_Pool.o Application.o Common.o ThreadPool_Frame

install:
	chmod a+x ../manager/menu
	cp ThreadPool_Frame ../bin

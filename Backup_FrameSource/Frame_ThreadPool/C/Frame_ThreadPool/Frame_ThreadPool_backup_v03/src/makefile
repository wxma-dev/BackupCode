#最终的目标文件
TARGET = ThreadPool_Frame

CFLAGS = -g -Wall


#子目录中的对象文件
SUBDIR_OBJLIST = lib_string.o \
    lib_file.o \
    lib_conf_file.o

#子目录应用层的对象文件
APP_OBJLIST = Application.o

#本工程需要的所有对象文件
OBJLIST = Thread_Pool.o \
    AddWork_Frame.o \
    DoWork_Frame.o \
    Common.o \
    ${SUBDIR_OBJLIST} \
    ${APP_OBJLIST}


#编译所有子目录
SUBDIRS=`ls -d */ | grep -v 'bin' | grep -v 'lib' | grep -v 'include'`
#编译指定子目录
#SUBDIRS=dir1 dir2 dir3

#编译子目录
define make_subdir
 @for subdir in $(SUBDIRS) ; do \
 ( cd $$subdir && make $1) \
 done;
 make $(join project_ , $1 )
endef


all:
	$(call make_subdir , all)

project_all:${TARGET}

debug:
	$(call make_subdir , debug)

clean:
	$(call make_subdir , clean)

project_clean:
	rm -rf ${OBJLIST}


${TARGET}:${OBJLIST}
	gcc ${OBJLIST} -o ${TARGET} -lpthread ${CFLAGS}

Thread_Pool.o:Thread_Pool.c Struct_Frame.h Log_Frame.h
	gcc -o Thread_Pool.o -c Thread_Pool.c ${CFLAGS}
AddWork_Frame.o:AddWork_Frame.c AddWork_Frame.h Struct_Frame.h Log_Frame.h
	gcc -c AddWork_Frame.c ${CFLAGS}
DoWork_Frame.o:DoWork_Frame.c DoWork_Frame.h Struct_Frame.h Log_Frame.h
	gcc -c DoWork_Frame.c ${CFLAGS}
Common.o:Common.c Common.h
	gcc -c Common.c ${CFLAGS}

install:
	chmod a+x ../manager/menu
	mv ThreadPool_Frame ../bin

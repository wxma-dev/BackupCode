#ifndef __ADDWORK_FRAME_H__
#define __ADDWORK_FRAME_H__

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <fcntl.h>

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <pthread.h>

#include <sys/types.h>
#include <sys/stat.h>

#include "Struct_Frame.h"
#include "Log_Frame.h"


/* 负责向工作链表中添加工作 */
void *Call_Addwork_Thread( void *arg );

#endif

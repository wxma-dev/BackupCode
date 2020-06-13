#ifndef __DOWORK_FRAME_H__
#define __DOWORK_FRAME_H__

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

#include <pthread.h>
#include "Struct_Frame.h"
#include "Log_Frame.h"

#include "Application.h"

void *Call_Dowork_Thread( void *arg );


#endif

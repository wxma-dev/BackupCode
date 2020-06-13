/************************************************************
* Copyright (c)   2011 xxxxxxxxxxxxxxxxxxxxxx               *
* Source File:    Application.c                             *
* Description:    应用开发                                  *
*           (1)寻找任务，并将任务添加到管道中               *
*           (2)解析任务，执行任务                           *
*           (3)以上2个部分的，使用的任务的结构体在此文件中定义*
*           比如，在epoll解析网络上的任务，添加到管道中；   *
            网络上的任务，在本机上需要进行的操作            *
* Author:         mawx                                      *
* Create Date:    2017.06.30                                *
*-----------------------------------------------------------*
* Modify Date:    YYYY-MM-DD                                *
* Modifier:                                                 *
* Modify Note:    XXXXXXXXXXXXXX                            *
* **********************************************************/
#include "Application.h"

/*
获取的任务的地址，执行具体的业务操作
只需要在此函数中，自行定义相关的业务操作即可，本文件中的其他地方不需要改动
*/
int DoWork( void * const pPoint_Addr )
{
	char * p2;
	p2 = (char* )pPoint_Addr;
	printf( "%s\n", p2 );
}

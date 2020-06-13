/************************************************************
* Copyright (c)                                             *
* Source File:    Application.c                             *
* Description:    应用开发文件                              *
*           应用层的代码，均在此代码中实现                  *
*           (1)分配内存，将该内存的地址插入队列             *
*           (2)得到内存的地址，进行解析，执行任务           *
* Author:         mawx                                      *
* Create Date:    2017.06.30                                *
*-----------------------------------------------------------*
* Modify Date:    YYYY-MM-DD                                *
* Modifier:                                                 *
* Modify Note:    XXXXXXXXXXXXXX                            *
* **********************************************************/
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "../Common.h"

#include "Application.h"

int __REPLACE__AddWork( void *arg )
{
	int iCount = 0;
	
	while ( 1 )
	{
		iCount++;
		void *pPoint_Task_Addr;
		void *pPoint_Buf;

		pPoint_Task_Addr = NULL;
		pPoint_Buf = NULL;

		pPoint_Task_Addr = malloc( POINT_SIZE );
		pPoint_Buf = (char *)malloc( 1024 );

		memset( pPoint_Task_Addr, 0x00, POINT_SIZE );
		memset( pPoint_Buf, 0x00, 1024 );

		strcat( pPoint_Buf, "1234567890" );

		memcpy( pPoint_Task_Addr, &pPoint_Buf, POINT_SIZE );

		sleep( 1 );

		Into_Queue( pPoint_Task_Addr );
	}
}


int AddWork( void *arg )
{
	return __REPLACE__AddWork( arg );
}



/*
获取的任务的地址，执行具体的业务操作
只需要在此函数中，自行定义相关的业务操作即可，本文件中的其他地方不需要改动
*/
int __REPLACE__DoWork( void * const pPoint_Task_Addr )
{
	char * p2;
	p2 = (char* )pPoint_Task_Addr;
	printf( "%s\n", p2 );
}


int DoWork( void * const pPoint_Task_Addr )
{
	return __REPLACE__DoWork( pPoint_Task_Addr );
}

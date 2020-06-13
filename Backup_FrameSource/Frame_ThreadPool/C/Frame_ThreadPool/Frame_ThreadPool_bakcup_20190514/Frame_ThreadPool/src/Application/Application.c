/************************************************************
* Copyright (c)                                             *
* Source File:    Application.c                             *
* Description:    Ӧ�ÿ���Դ�ļ�                            *
*           Ӧ�ò�Ĵ��룬���ڴ˴�����ʵ��                  *
*           (1)�����ڴ棬�����ڴ�ĵ�ַ�������             *
*           (2)�õ��ڴ�ĵ�ַ�����н�����ִ������           *
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
��ȡ������ĵ�ַ��ִ�о����ҵ�����
ֻ��Ҫ�ڴ˺����У����ж�����ص�ҵ��������ɣ����ļ��е������ط�����Ҫ�Ķ�
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

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

#include "Threads_Socket_Client.h"

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>



/*
	�̳߳صĿ�ܵ�Ӧ�ò��֣��ڸ��ļ��б�д�书Ч��
	��ɫ��
		�����ߣ�__REPLACE__AddWork ����������������,malloc(new) �ķ�ʽ�����ݷ������У�
			�������̵߳���������Ϊ0��ֱ����������߳� ִ������
		�����ߣ�__REPLACE__DoWork  ���������ִ������,ֱ���õ���Ӧ���ڴ棬ִ��������free(delete)�ڴ�
		��Ҫһ�� ����2�����������Ͽɵ� ����ṹ�壬�����ж���
*/



/************************start Ӧ�ñ���******����Ϊʾ����˵��********************************/
#if 1

int __REPLACE__AddWork( void *arg )
{
	int iCount = 0;
	int i = 0;

	for( i = 0; i < 20; i++ )
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

		Into_Queue( pPoint_Task_Addr );
	}
}




/*
��ȡ������ĵ�ַ��ִ�о����ҵ�����
ֻ��Ҫ�ڴ˺����У����ж�����ص�ҵ��������ɣ����ļ��е������ط�����Ҫ�Ķ�
*/
int __REPLACE__DoWork( void * const pPoint_Task_Addr )
{
/*
	char * p2;
	p2 = (char* )pPoint_Task_Addr; 
	printf( "%s\n", p2 );
	free( pPoint_Task_Addr );
*/
	int fd;
	struct sockaddr_in addr;
	int r;
	
	/*1.����socket*/
	fd=socket(AF_INET,SOCK_STREAM,6);
	/*2.��������:write/send/sendto*/
	addr.sin_family=AF_INET;
	addr.sin_port=htons(6888);
	inet_aton("10.242.134.75",&addr.sin_addr);
	
	r = connect(fd,(struct sockaddr*)&addr,sizeof(addr));
	char buf[256];
	r = read(fd,buf,sizeof(buf)-1);
	if( r > 0 ){
		buf[r]=0;
		printf("���Է���������Ϣ:%s\n",buf);
	}
	if(r==0) printf("�����Ѿ��ر�!\n");
	
	if(r==-1) printf("�������!\n");
	
	/*3.�ر�socket*/
	close(fd);
	
}

#endif
/******************************end Ӧ�ñ���******************************/





int AddWork( void *arg )
{
	return __REPLACE__AddWork( arg );
}


int DoWork( void * const pPoint_Task_Addr )
{
	return __REPLACE__DoWork( pPoint_Task_Addr );
}

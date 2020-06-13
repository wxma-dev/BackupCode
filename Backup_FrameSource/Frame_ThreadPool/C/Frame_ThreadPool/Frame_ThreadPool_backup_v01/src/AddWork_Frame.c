
#include "Struct_Frame.h"

#include "AddWork_Frame.h"

#include "Common_Frame.h"

extern CThread_pool *pool;

/*

*/
void Into_Queue( void * pPoint )
{
	/* 分配一个链表节点的内存 */
	CList_Task *pNewWorker = ( CList_Task *) malloc( sizeof(CList_Task) );
	memset( pNewWorker, 0x00, sizeof( CList_Task ) );

	pNewWorker->pList_Task = pPoint;

	/* 加锁 */
	pthread_mutex_lock( &(pool->queue_lock_F) );

	/* 插入链表头部 */
	CList_Task *pMember = pool->queue_head_F;
	if( NULL != pMember )
	{
		while( NULL != pMember->next )
		{
			pMember = pMember->next;
		}
		pMember->next = pNewWorker;
	}
	else
	{
		pool->queue_head_F = pNewWorker;
	}
	++(pool->cur_queue_size_F);

	/* 解锁 */
	pthread_mutex_unlock( &(pool->queue_lock_F) );

	/* 通知一个等待的线程 */
	pthread_cond_signal( &(pool->queue_ready_F) );
}



/*********************************************************************
* Function：                                                         *
*    int Call_Addwork_Thread( void *arg)                             *
* Description：                                                      *
*    往CList_Task链表中添加任务（函数，参数）                        *
*    自旋锁、互斥锁成为可选择的方式                                  *
*    添加任务的部分，可以作为一个公共的部分，具体的发现任务的再做一个子接口来表现*
* In Params:                                                         *
*                                                                    *
* Out Params:                                                        *
*                                                                    *
* Return:                                                            *
*                                                                    *
*********************************************************************/
#if 0
void *Call_Addwork_Thread( void *arg )
{
	char     sRead_Fifo_Name[256 + 1];
	int      iRead_Fd;
	void     *pPoint_ReadMem;
	void     *pPoint_ReadMem_Tmp;
	int      iLength_Read;
	int      iSize_Mem;
	int      iSize_Mem_Pj;                            /* 是否拼接标志 */
	void     *pPoint_Void;
	int      iSize_ReadMem;                           /* read的buf大小 */
	int      iCount_FailOpenFifo;                     /* 失败打开FIFO的次数 */
	char     *pPoint_Start;                           /* 任务有效的开始地址 */

	/* 变量初始化 */
	memset( sRead_Fifo_Name, 0x00, sizeof( sRead_Fifo_Name ) );
	iRead_Fd = 0;
	pPoint_ReadMem = NULL;
	pPoint_ReadMem_Tmp = NULL;
	iLength_Read = 0;
	iSize_Mem = 0;
	iSize_Mem_Pj = 0;
	pPoint_Void = NULL;
	iSize_ReadMem = 0;
	iCount_FailOpenFifo = 0;
	pPoint_Start = NULL;

	/* 从配置文件中获取fifo的文件名 */
	memset( sRead_Fifo_Name, 0x00, sizeof( sRead_Fifo_Name ) );
	if ( 0 != Get_ValuseString_ByFieldKey_InConfFile( "../conf/frame_threadpool.conf", "FIFO_FRAME", "FIFONAME_READ_FOR_ADD", sRead_Fifo_Name ) )
	{
		ERROR_FRAME( "Get_ValuseString_ByFieldKey_InConfFile error" );
		return NULL;
	}
	DEBUG_FRAME( "从配置文件中获取fifo的文件名sRead_Fifo_Name[%s].", sRead_Fifo_Name );

	/* 分配内存 */
	iSize_ReadMem = 4096;
	pPoint_ReadMem = malloc( iSize_ReadMem );
	pPoint_ReadMem_Tmp = malloc( iSize_ReadMem );
	DEBUG_FRAME( "iSize_ReadMem=[%s].", iSize_ReadMem );

	/* 内存初始化 */
	memset( pPoint_ReadMem, 0x00, iSize_ReadMem );
	memset( pPoint_ReadMem_Tmp, 0x00, iSize_ReadMem );

	iCount_FailOpenFifo = 0;
	while( ( iRead_Fd = open( sRead_Fifo_Name, O_RDONLY ) ) == -1 ) 
	{
		iCount_FailOpenFifo++;
		DEBUG_FRAME( "打开FIFO失败第[%d]次.", iCount_FailOpenFifo );
		sleep(1);
	}
	DEBUG_FRAME( "打开FIFO成功." );

	while ( 1 )
	{
		DEBUG_FRAME( "开始循环从fifo中读取数据." );
		memset( pPoint_ReadMem, 0x00, iSize_ReadMem );
		iLength_Read = read( iRead_Fd, pPoint_ReadMem, iSize_ReadMem );
		if ( iLength_Read < 0 )
		{
			/* 报错 */
			ERROR_FRAME( "read buf of fifo error" );
			return NULL;
		}
		else
		{
			/*
			比如获取的内存区域：
				"\n0xxxxxxxxxx",\n作为开始的标志，后一位则是void *大小的指针内容，
				将其拷贝至其他区域解析即可。
			*/

			/* '\n'开始地址 */
			pPoint_Start = strchr( pPoint_ReadMem, '\n' );
			if ( NULL == pPoint_Start )
			{
				DEBUG_FRAME( "没有找到任务开始符号'\n'，continue" );
				continue;
			}

			/* 任务开始的地址 */
			pPoint_Start++;

			/* 任务开始地址后 复制有个void *大小区域即可 */
			memcpy( &pPoint_Void, pPoint_ReadMem, sizeof( void * ) );
			Into_Queue( pPoint_Void );
		}
		iLength_Read = 0;
	}
}

#endif



void *Call_Addwork_Thread( void *arg )
{
	int iCount = 0;
	
	while ( 1 )
	{
		iCount++;
		void *pPoint_Tmp;
		void *pPoint_Buf;

		pPoint_Tmp = NULL;
		pPoint_Buf = NULL;

		pPoint_Tmp = malloc( sizeof( void * ) + 1 );
		pPoint_Buf = (char *)malloc( 1024 );

		memset( pPoint_Tmp, 0x00, sizeof( void * ) + 1 );
		memset( pPoint_Buf, 0x00, 1024 );

		strcat( pPoint_Buf, "1234567890" );

		sleep( 2 );

		Into_Queue( pPoint_Buf );
		DEBUG_FRAME( "iCount=[%d]\n", iCount );
	}
}



#if 0

Realloc_Task_Mem( void * pPoint_Task_Mem )
{
	realloc( pPoint_Task_Mem
}

Into_Task( void * pPoint_Task_Mem )
{
	void    *pPoint_Tmp;
	int     iSize_Point_Tmp;

	pPoint_Tmp = NULL;
	iSize_Point_Tmp = 0;

	iSize_Point_Tmp = sizeof( void * ) + 1;
	pPoint_Tmp = malloc( iSize_Point_Tmp );
	memset( pPoint_Tmp, 0x00, iSize_Point_Tmp );

	
}

#endif





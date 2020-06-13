#include "Common_Frame.h"



/*
检查是否符合标准
*/
int Check_Task_Mem( void * const pPoint )
{
	if ( NULL ==  Get_Start_Addr( pPoint ) )
	{
		return -1;
	}

	return 0;
}



/*
获取到标志位的指针
*/
void * Get_Mark_Addr( void * const pPoint_Addr )
{
	void * pPoint_Mark_Addr;

	pPoint_Mark_Addr = NULL;

	/* '\n'开始地址 */
	pPoint_Mark_Addr = strchr( (char *)pPoint_Addr, '\n' );
	if ( NULL == pPoint_Mark_Addr )
	{
		return NULL;
	}

	return pPoint_Mark_Addr;
}

/*
计算”存放地址值的内存块“的首地址
*/
void * Get_Start_Addr( void * const pPoint_Addr )
{
	void * pPoint_Start_Addr;

	pPoint_Start_Addr = NULL;

	pPoint_Start_Addr = Get_Mark_Addr( pPoint_Addr );
	if ( NULL == pPoint_Start_Addr )
	{
		return NULL;
	}
	pPoint_Start_Addr++;

	return pPoint_Start_Addr;
}


/*
获取”存放地址值的内存块“中的值
入参：pPoint_Start_Addr   开始的地址
出参：pPoint_Task_Addr    ”存放地址值的内存块“中的值二级指针
*/
void Get_Task_Addr( void * const pPoint_Start_Addr, void ** pPoint_Task_Addr )
{
	memcpy( pPoint_Task_Addr, pPoint_Start_Addr, sizeof( void * ) );
}

/*
释放”存放地址值的内存块“指向的内存区域
*/
void Free_Task_Addr( void * pPoint_Task_Addr )
{
	free( pPoint_Task_Addr );
	pPoint_Task_Addr = NULL;
}






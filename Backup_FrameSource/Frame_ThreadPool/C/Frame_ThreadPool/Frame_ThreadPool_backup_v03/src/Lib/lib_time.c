/*************************************************************
*    FileName : Time.c                                       *
*    FileFunc : 时间、日期处理的定义实现的源文件             *
*    Version: V0.1                                           *
*    Author :                                                *
*    Date : 2016-12-25                                       *
*    Descp :                                                 *
*************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "lib_time.h"

/*************************************************************
*    Function:    getstrdate                                 *
*    Description: 获取字符串个数的日期(格式 %d%d%d )         *
*    Calls:                                                  *
*    Called By:                                              *
*    Table Accessed:                                         *
*    Table Updated:                                          *
*    Input:                                                  *
*    Output:                                                 *
*    Return:                                                 *
*    Others:                                                 *
*************************************************************/
int getstrdate( char *sOutStrTime )
{
	time_t timep; 
	struct tm *p; 
	
	memset( &timep, 0x00, sizeof( timep) );
	p = NULL;
	
	if( NULL == sOutStrTime )
	{
		return -1;
	}

	time( &timep );
	p = localtime( &timep );
	sprintf( sOutStrTime, "%d%d%d", (1900 + p->tm_year),(1 + p->tm_mon), p->tm_mday );
	
	return 0;
}


/*************************************************************
*    Function:    getstrtime                                 *
*    Description: 获取字符串个数的时间(格式：%02d%02d%02d )  *
*    Calls:                                                  *
*    Called By:                                              *
*    Table Accessed:                                         *
*    Table Updated:                                          *
*    Input:                                                  *
*    Output:                                                 *
*    Return:                                                 *
*    Others:                                                 *
*************************************************************/
int getstrtime( char *sOutStrTime )
{
	time_t timep; 
	struct tm *p; 
	
	memset( &timep, 0x00, sizeof( timep) );
	p = NULL;
	
	if( NULL == sOutStrTime )
	{
		return -1;
	}

	time( &timep );
	p = localtime( &timep );
	sprintf( sOutStrTime, "%02d%02d%02d", p->tm_hour, p->tm_min, p->tm_sec );
	
	return 0;
}




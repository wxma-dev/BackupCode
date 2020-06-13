#include "lib_file.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <sys/types.h>
#include <sys/stat.h>

/************************************************************
* Copyright (c) 2015 北京联银通科技有限公司                 *
* Source File:    Get_FileSize                              *
* Description:    获取文件大小(字节)                        *
* Author:         mawx                                      *
* Create Date:    2015/07/09                                *
* In:             filename 文件名(绝对路径)                 *
*                 valuename_str 配置字段名称                *
                  value_str 配置字段内容                    *
* Out:            0 非数字                                  *
*                 1 数字                                    *
*-----------------------------------------------------------*
* Modify Date:    YYYY-MM-DD                                *
* Modifier:       XXX                                       *
* Modify Note:    XXXXXXXXXXXXXX                            *
************************************************************/
off_t Get_FileSize( char * filename )
{
	struct stat file_stat;
	off_t file_size;
	
	memset( &file_stat, 0x00, sizeof( file_stat ) );
	file_size = 0;
	
	stat( filename, &file_stat );
	
	return file_stat.st_size;
}


/************************************************************
* Copyright (c) 2015 xxxxxxxxxxxxxxxxxx公司                 *
* Source File:    GetFileRowCount                           *
* Description:    获取文件行数                              *
* Author:         mawx                                      *
* Create Date:    2015/07/09                                *
* In:             sFilename 文件绝对路径                    *
*                 pNum 文件行数变量指针                     *
* Out:            -1 失败                                   *
*                 其他 文件的行数                           *  
*-----------------------------------------------------------*
* Modify Date:    YYYY-MM-DD                                *
* Modifier:       XXX                                       *
* Modify Note:    XXXXXXXXXXXXXX                            *
* **********************************************************/
int GetFileRowCount( char *sFilename, int * pNum )
{
	char sString[1024];    /* buf */
	int  iNum;
	char *pRet;
	int  iLeng_Str;
	
	memset( sString, 0x00, sizeof( sString ) );
	iNum = 0;
	pRet = NULL;
	iLeng_Str = 0;
	
	/* 打开文件 */
	FILE * fp = fopen( sFilename, "r" );
	
	/* 如果打开文件为NULL，则return -1 */
	if ( NULL == fp )
	{
		return -1;
	}
	
	/* 循环读取文件，统计行数 */
	while( 1 ) 
	{
		/* 读取 */
		pRet = fgets( sString, sizeof( sString ) , fp );
		
		/* 为NULL说明已经到达文件尾部，则跳出循环 */
		if ( NULL == pRet )  
		{
			break;
		}
		
		/* 获取读取到的字符串的长度 */
		iLeng_Str = strlen( sString );
		
		/* 若为换行符，则认为是一行；否则continue */
		if ( '\n' == sString[ iLeng_Str ] )
		{
			iNum++;
		}
		else
		{
			continue;
		}
	}
	(*pNum) = iNum;

	return *pNum;
}


/************************************************************
* Copyright (c) 2015 xxxxxxxxxxxxxxxxxx公司                 *
* Source File:    While_ReadLine_FromFile                   *
* Description:    循环读取文件的每一行                      *
* Author:         mawx                                      *
* Create Date:    2015/07/09                                *
* In:             pPoint_StReadLine ST_ReadLine结构体的二级指针*
* Out:            pPoint_StReadLine->iFlagFirst             *
*                 -2-异常结束，-1-文件读取完毕              *
*                 0-第一次使用未打开文件，1-第一次读取文完成*
*                 2-第二次打开文件完成，以此类推            *
*                 NULL 完毕或者异常结束                     *
*-----------------------------------------------------------*
* Modify Date:    YYYY-MM-DD                                *
* Modifier:       XXX                                       *
* Modify Note:    XXXXXXXXXXXXXX                            *
* **********************************************************/
ST_ReadLine * While_ReadLine_FromFile( ST_ReadLine ** pPoint_StReadLine )
{
	char  * pPoint_Tmp;

	/* 0-第一次使用未打开文件 */
	if ( 0 == (*pPoint_StReadLine)->iFlagFirst )
	{
		(*pPoint_StReadLine)->pPoint_fp = fopen( (*pPoint_StReadLine)->sStr_FilePathName, "r" );
		if ( NULL == (*pPoint_StReadLine)->pPoint_fp )
		{
			(*pPoint_StReadLine)->iFlagFirst = -2;
			return NULL;
		}
	}

	/* 接下来读取文件 */
	if ( -1 != (*pPoint_StReadLine)->iFlagFirst && -2 != (*pPoint_StReadLine)->iFlagFirst )
	{
		memset( (*pPoint_StReadLine)->sStr_Line, 0x00, sizeof( (*pPoint_StReadLine)->sStr_Line ) );
		pPoint_Tmp = fgets( (*pPoint_StReadLine)->sStr_Line, sizeof( (*pPoint_StReadLine)->sStr_Line ), (*pPoint_StReadLine)->pPoint_fp );
		if ( NULL == pPoint_Tmp )
		{
			if ( 0 != errno )
			{
				(*pPoint_StReadLine)->iFlagFirst = -1;
				return NULL;
			}
			else
			{
				(*pPoint_StReadLine)->iFlagFirst = -2;
				return NULL;
			}
		}
		else
		{
			((*pPoint_StReadLine)->iFlagFirst)++;
			return *pPoint_StReadLine;
		}
	}
}



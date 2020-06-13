


#include "lib_file.h"


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







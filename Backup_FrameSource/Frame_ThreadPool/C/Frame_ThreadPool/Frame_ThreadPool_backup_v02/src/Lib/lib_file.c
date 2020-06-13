


#include "lib_file.h"


/************************************************************
* Copyright (c) 2015 ��������ͨ�Ƽ����޹�˾                 *
* Source File:    Get_FileSize                              *
* Description:    ��ȡ�ļ���С(�ֽ�)                        *
* Author:         mawx                                      *
* Create Date:    2015/07/09                                *
* In:             filename �ļ���(����·��)                 *
*                 valuename_str �����ֶ�����                *
                  value_str �����ֶ�����                    *
* Out:            0 ������                                  *
*                 1 ����                                    *
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
* Copyright (c) 2015 xxxxxxxxxxxxxxxxxx��˾                 *
* Source File:    GetFileRowCount                           *
* Description:    ��ȡ�ļ�����                              *
* Author:         mawx                                      *
* Create Date:    2015/07/09                                *
* In:             sFilename �ļ�����·��                    *
*                 pNum �ļ���������ָ��                     *
* Out:            -1 ʧ��                                   *
*                 ���� �ļ�������                           *  
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
	
	/* ���ļ� */
	FILE * fp = fopen( sFilename, "r" );
	
	/* ������ļ�ΪNULL����return -1 */
	if ( NULL == fp )
	{
		return -1;
	}
	
	/* ѭ����ȡ�ļ���ͳ������ */
	while( 1 ) 
	{
		/* ��ȡ */
		pRet = fgets( sString, sizeof( sString ) , fp );
		
		/* ΪNULL˵���Ѿ������ļ�β����������ѭ�� */
		if ( NULL == pRet )  
		{
			break;
		}
		
		/* ��ȡ��ȡ�����ַ����ĳ��� */
		iLeng_Str = strlen( sString );
		
		/* ��Ϊ���з�������Ϊ��һ�У�����continue */
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







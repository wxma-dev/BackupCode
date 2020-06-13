#include "../include/lib_file.h"

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


/************************************************************
* Copyright (c) 2015 xxxxxxxxxxxxxxxxxx��˾                 *
* Source File:    While_ReadLine_FromFile                   *
* Description:    ѭ����ȡ�ļ���ÿһ��                      *
* Author:         mawx                                      *
* Create Date:    2015/07/09                                *
* In:             pPoint_StReadLine ST_ReadLine�ṹ��Ķ���ָ��*
* Out:            pPoint_StReadLine->iFlagFirst             *
*                 -2-�쳣������-1-�ļ���ȡ���              *
*                 0-��һ��ʹ��δ���ļ���1-��һ�ζ�ȡ�����*
*                 2-�ڶ��δ��ļ���ɣ��Դ�����            *
*                 NULL ��ϻ����쳣����                     *
*-----------------------------------------------------------*
* Modify Date:    YYYY-MM-DD                                *
* Modifier:       XXX                                       *
* Modify Note:    XXXXXXXXXXXXXX                            *
* **********************************************************/
ST_ReadLine * While_ReadLine_FromFile( ST_ReadLine ** pPoint_StReadLine )
{
	char  * pPoint_Tmp;

	/* 0-��һ��ʹ��δ���ļ� */
	if ( 0 == (*pPoint_StReadLine)->iFlagFirst )
	{
		(*pPoint_StReadLine)->pPoint_fp = fopen( (*pPoint_StReadLine)->sStr_FilePathName, "r" );
		if ( NULL == (*pPoint_StReadLine)->pPoint_fp )
		{
			(*pPoint_StReadLine)->iFlagFirst = -2;
			return NULL;
		}
	}

	/* ��������ȡ�ļ� */
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


/*
	���������Ҫ�ƶ�����Ӧ���ļ��Ĳ���������ȥ
	���ܣ���ȡ�ļ���һ�У����������ļ�һ�� �� ��̬�ڴ��ָ�� ���أ�ע������ڴ�ʹ�ú�ǵ��ͷ�
	���Σ�   pOut  malloc�ĵ�ַ�������ļ�һ�е�����
	return  �Ǹ��������еĳ���
			0 ����
			-1 �Ѿ�˳�������ļ�ĩβ  ��aEOF", ��ȡa ��return -1
			-2 �����ļ�ĩβ      "a\nEOF" ���������2�ζ�����һ�ζ�a���ڶ��ζ�ȡEOF return -2
			-3 ����

*/
int GetFileLine_Malloc( FILE * fp , char ** pOut )
{
    char * pTmp = NULL;
    char * pRet = NULL;
    int    iCount_Xh = 0;
    int    iLength = 0;
    int    iChar = 0;
    int    iCount_Line = 0;
    
    if ( EOF == fgetc( fp ) )
    {
        return -2;
    }
    fseek( fp, -1, SEEK_CUR );
    
    while( 1 )
    {
        iChar = fgetc( fp );
        
        if ( '\n' == iChar )
        {
            iCount_Line++;
            break;
        }
        else if ( EOF == iChar )
        {
            iCount_Line++;
            break;
        }
        else
        {
            iCount_Line++;
        }
    }
    
    if ( '\n' == iChar )
    {
    	fseek( fp, -iCount_Line, SEEK_CUR );
    }
    else if ( EOF == iChar )
    {
    	fseek( fp, -( iCount_Line -1 ), SEEK_CUR );
    }

    pTmp = (char *) malloc( iCount_Line );
    memset( pTmp, 0x00, iCount_Line );

    fgets( pTmp, iCount_Line , fp );
    *pOut = pTmp;

	if ( iChar == EOF )
	{
		return -1;
	}
	else if ( iChar == '\n' )
	{
    		fseek( fp, 1, SEEK_CUR );
    		return ( iCount_Line - 1 );
	}

	return -3;
}


/*
�ͷ� GetFileLine_Malloc �õ��ĵ�ַ
*/
void GetFileLine_Free( char * pIn )
{
    free( pIn );
}




#define _TEST_LIE_FILE_ 0
#if _TEST_LIE_FILE_
int main()
{
	char * sFileName = "1.txt";
	char  * pTmp;


	FILE * fp = fopen( sFileName, "r" );
	int i = 0;
	for( i = 0 ; i < 20 ; i++ )
	{
		int iRet = GetFileLine_Malloc( fp, &pTmp );
		if ( -2 == iRet ) break;
	
		printf( "[iRet=%d],%s\n", iRet, pTmp );
		GetFileLine_Free( pTmp );
		pTmp = NULL;

		if ( -1 == iRet )
		{
			break;
		}
	}

}
#endif






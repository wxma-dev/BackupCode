#ifndef __LIB_FILE_H__
#define __LIB_FILE_H__

#include <stdio.h>

typedef struct st_ReadLine{
	FILE  *pPoint_fp;                       /* �ļ���ָ�� */
	char  sStr_Line[40960 + 1];             /* ��ȡ��ĳһ�е��ڴ棬�޶��ļ���ĳһ�д�С������40960 */
	int   iFlagFirst;                       /*  -2 �쳣������-1 �ļ���ȡ��ϣ�0-��һ��ʹ��δ���ļ���1-��һ�ζ�ȡ�����, 2-�ڶ��δ��ļ���ɣ��Դ����� */
	char  sStr_FilePathName[256 + 1];       /* �ļ���·���� */
} ST_ReadLine;

/* ��ȡ�ļ���С(�ֽ�) */
off_t Get_FileSize( char * filename );

/* ��ȡ�ļ����� */
int GetFileRowCount( char *sFilename, int * pNum );

/* ѭ����ȡ�ļ���ÿһ�� */
ST_ReadLine * While_ReadLine_FromFile( ST_ReadLine ** pPoint_StReadLine );


#endif




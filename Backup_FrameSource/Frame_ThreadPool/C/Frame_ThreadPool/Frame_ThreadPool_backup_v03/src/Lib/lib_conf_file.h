#ifndef __LIB_CONF_FILE_H__
#define __LIB_CONF_FILE_H__

#include "lib_file.h"

/* ��ȡ�����ļ�ĳһ�У�����ڴ棬�洢�ַ���  
	����ǵ�һ�ζ�ȡĳһ����malloc�����һ��  
	���϶�ȡĳһ����realloc�������µ�ַ��� */
char * AddMem_For_AddString( const int iCount_ReadLine, const char * sSrc_String, char ** pPoint_AddMem );

/* �ͷ�AddMem_For_AddString��ӵ��ڴ� */
void FreeMem_For_AddString( char ** pPoint_NeedFree );

/* �������ļ��л�ȡĿ��Key������ */
int Get_ValuseString_ByKey_InConfFile( const char * sFile_Name, const char * sKey, char * sDst_String );


/* ѭ����ȡ�����ļ�����Ч�� */
ST_ReadLine * Wile_ReadLine_FromConfFile( ST_ReadLine ** pPoint_StReadLine );


/* �޸������ļ���ĳField/Key��ֵ */
/* �޸������ļ���ĳKey��ֵ(���ļ��е�һ�γ��ֵ�KeyΪ׼)*/




#endif












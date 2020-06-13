#ifndef __LIB_CONF_FILE_H__
#define __LIB_CONF_FILE_H__

#include "lib_file.h"

/* 读取配置文件某一行，添加内存，存储字符串  
	如果是第一次读取某一行则malloc，如果一次  
	以上读取某一行则realloc，并将新地址输出 */
char * AddMem_For_AddString( const int iCount_ReadLine, const char * sSrc_String, char ** pPoint_AddMem );

/* 释放AddMem_For_AddString添加的内存 */
void FreeMem_For_AddString( char ** pPoint_NeedFree );

/* 从配置文件中获取目标Key的内容 */
int Get_ValuseString_ByKey_InConfFile( const char * sFile_Name, const char * sKey, char * sDst_String );


/* 循环读取配置文件的有效行 */
ST_ReadLine * Wile_ReadLine_FromConfFile( ST_ReadLine ** pPoint_StReadLine );


/* 修改配置文件中某Field/Key的值 */
/* 修改配置文件中某Key的值(以文件中第一次出现的Key为准)*/




#endif












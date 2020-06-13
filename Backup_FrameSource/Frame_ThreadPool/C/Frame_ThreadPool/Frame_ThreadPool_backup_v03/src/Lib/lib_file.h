#ifndef __LIB_FILE_H__
#define __LIB_FILE_H__

#include <stdio.h>

typedef struct st_ReadLine{
	FILE  *pPoint_fp;                       /* 文件的指针 */
	char  sStr_Line[40960 + 1];             /* 读取的某一行的内存，限定文件的某一行大小不超过40960 */
	int   iFlagFirst;                       /*  -2 异常结束，-1 文件读取完毕，0-第一次使用未打开文件，1-第一次读取文完成, 2-第二次打开文件完成，以此类推 */
	char  sStr_FilePathName[256 + 1];       /* 文件名路径名 */
} ST_ReadLine;

/* 获取文件大小(字节) */
off_t Get_FileSize( char * filename );

/* 获取文件行数 */
int GetFileRowCount( char *sFilename, int * pNum );

/* 循环读取文件的每一行 */
ST_ReadLine * While_ReadLine_FromFile( ST_ReadLine ** pPoint_StReadLine );


#endif




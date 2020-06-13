#ifndef __LIB_STRING_H__
#define __LIB_STRING_H__
/************************************************************
* Copyright (c) 2015 xxxxxxxxxxxxxxxxxx��˾                 *
* Source File:    lib_mem_str.c                             *
* Description:    �����ڴ桢�ַ�����lib                     *
* Author:         mawx                                      *
* Create Date:    2015/05/14                                *
*-----------------------------------------------------------*
* Modify Date:    YYYY-MM-DD                                *
* Modifier:       XXX                                       *
* Modify Note:    XXXXXXXXXXXXXX                            *
************************************************************/



/************************************************************
* Copyright (c) 2015 xxxxxxxxxxxxxxxxxx��˾                 *
* Source File:    AddStr_Malloc                             *
* Description:    ����һ���µ��ڴ棬���ַ�����������        *
* Author:         mawx                                      *
* Create Date:    2015/07/09                                *
* In:             sAdd_String ��Ҫ��ӵ��ַ���              *
*                 pDst_Mem ����Ķ�̬�ڴ�ĵ�ַ             *
* Out:            char * NULLʧ��                           *
*                 ��NULL���·�����ڴ��ַ                  *
*-----------------------------------------------------------*
* Modify Date:    YYYY-MM-DD                                *
* Modifier:       XXX                                       *
* Modify Note:    XXXXXXXXXXXXXX                            *
************************************************************/
char * AddStr_Malloc( const char * sAdd_String, char ** pDst_Mem );


/************************************************************
* Copyright (c) 2015 xxxxxxxxxxxxxxxxxx��˾                 *
* Source File:    AddStr_Realloc                            *
* Description:    ���·�����ڴ��У���β������ַ���        *
*                 ԭ�ڴ�Ҳ������malloc���ͺ�������Ķ�̬�ڴ�*
*                 �·�����ڴ泤�� ԭ�ڴ��ַ�������+����ַ����ĳ���+1 *
* Author:         mawx                                      *
* Create Date:    2015/07/09                                *
* In:             pSrc_Mem    ԭ��̬�ڴ��ַ                *
*                 sAdd_String ��Ҫ��ӵ��ַ���              *
*                 pDst_Mem �µĶ�̬�ڴ�ĵ�ַ               *
* Out:            char * NULLʧ��                           *
*                 ��NULL���·�����ڴ��ַ                  *
*-----------------------------------------------------------*
* Modify Date:    YYYY-MM-DD                                *
* Modifier:       XXX                                       *
* Modify Note:    XXXXXXXXXXXXXX                            *
************************************************************/
char * AddStr_Realloc( char * pSrc_Mem, const char * sAdd_String, char ** pDst_Mem );

/************************************************************
* Copyright (c) 2015 xxxxxxxxxxxxxxxxxx��˾                 *
* Source File:    AddStr_Free                               *
* Description:    �ͷ�AddStr_Realloc��AddStr_Malloc����ڴ� *
* Author:         mawx                                      *
* Create Date:    2015/07/09                                *
* In:             pPoint_Mem    ԭ��̬�ڴ��ַ              *
* Out:            void                                      *
*                                                           *
*-----------------------------------------------------------*
* Modify Date:    YYYY-MM-DD                                *
* Modifier:       XXX                                       *
* Modify Note:    XXXXXXXXXXXXXX                            *
************************************************************/
void AddStr_Free( char ** pPoint_Mem );

/************************************************************
* Copyright (c) 2015 xxxxxxxxxxxxxxxxxx��˾                 *
* Source File:    Count_Char_Num                            *
* Description:    �ж�Դ�ַ����е��Ӵ��ĸ���                *
* Author:         mawx                                      *
* Create Date:    2015/07/09                                *
* In:             sSrc_String    Դ�ַ���                   *
*                 sChild_String ���ַ���                    *
* Out:            int ����                                  *
*-----------------------------------------------------------*
* Modify Date:    YYYY-MM-DD                                *
* Modifier:       XXX                                       *
* Modify Note:    XXXXXXXXXXXXXX                            *
************************************************************/
int Count_Char_Num( char * sSrc_String, char * sChild_String );

/************************************************************
* Copyright (c) 2015 xxxxxxxxxxxxxxxxxx��˾                 *
* Source File:    Char_To_Str                               *
* Description:    �ַ�ת�����ַ���                          *
* Author:         mawx                                      *
* Create Date:    2015/07/09                                *
* In:             cSrc_Char    Դ�ַ�                       *
*                 sDst_String  Ŀ���ַ��������Ŀ���ַ����Ŀռ�����2��������δ��֪*
* Out:            char * NULLʧ�ܣ���NULL Ŀ���ַ����ĵ�ַ  *
*-----------------------------------------------------------*
* Modify Date:    YYYY-MM-DD                                *
* Modifier:       XXX                                       *
* Modify Note:    XXXXXXXXXXXXXX                            *
************************************************************/
char * Char_To_Str( const char cSrc_Char, char * sDst_String );

/************************************************************
* Copyright (c) 2015 xxxxxxxxxxxxxxxxxx��˾                 *
* Source File:    Str_To_Char                               *
* Description:    �ַ�ת�����ַ������ַ�����һλΪ׼��      *
* Author:         mawx                                      *
* Create Date:    2015/07/09                                *
* In:             sSrc_String Դ�ַ����������ȴ���1�����Ե�һλ���ַ�Ϊ׼*
*                 sDst_Char   Ŀ���ַ�                      *                      
* Out:            char * NULLʧ�ܣ�Դ�ַ�����ֵ             *
*-----------------------------------------------------------*
* Modify Date:    YYYY-MM-DD                                *
* Modifier:       XXX                                       *
* Modify Note:    XXXXXXXXXXXXXX                            *
************************************************************/
char * Str_To_Char( const char * sSrc_String, char sDst_Char );



/************************************************************
* Copyright (c) 2015 xxxxxxxxxxxxxxxxxx��˾                 *
* Source File:    GetString_YYYYMMDD                        *
* Description:    ��ȡ��ǰʱ���YYYYMMDD                    *
* Author:         mawx                                      *
* Create Date:    2015/07/09                                *
* In:             pPoint_TimeMem  ��ȡ��YYYYMMDD���ڸ��ַ�����*
*                 pPoint_TimeMem �����ڴ治�������δ��֪   *
* Out:            void                                      *
*-----------------------------------------------------------*
* Modify Date:    YYYY-MM-DD                                *
* Modifier:       XXX                                       *
* Modify Note:    XXXXXXXXXXXXXX                            *
************************************************************/
void GetString_YYYYMMDD( char * pPoint_TimeMem );

/************************************************************
* Copyright (c) 2015 xxxxxxxxxxxxxxxxxx��˾                 *
* Source File:    GetString_HHMMSS                          *
* Description:    ��ȡ��ǰʱ���HHMMSS                      *
* Author:         mawx                                      *
* Create Date:    2015/07/09                                *
* In:             pPoint_TimeMem  ��ȡ��HHMMSS���ڸ��ַ�����*
*                 pPoint_TimeMem �����ڴ治�������δ��֪   *
* Out:            void                                      *
*-----------------------------------------------------------*
* Modify Date:    YYYY-MM-DD                                *
* Modifier:       XXX                                       *
* Modify Note:    XXXXXXXXXXXXXX                            *
************************************************************/
void GetString_HHMMSS( char * pPoint_TimeMem );

/************************************************************
* Copyright (c) 2015 xxxxxxxxxxxxxxxxxx��˾                 *
* Source File:    GetString_HHMMSS                          *
* Description:    ��ȡ��ǰʱ��ļ������ʱ�䣨������        *
* Author:         mawx                                      *
* Create Date:    2015/07/09                                *
* In:             pPoint_TimeMem  ��ȡ��HHMMSS���ڸ��ַ�����*
*                 pPoint_TimeMem �����ڴ治�������δ��֪   *
* Out:            void                                      *
*-----------------------------------------------------------*
* Modify Date:    YYYY-MM-DD                                *
* Modifier:       XXX                                       *
* Modify Note:    XXXXXXXXXXXXXX                            *
************************************************************/
void GetString_ComputerSec( char * pPoint_TimeMem );
#if 0

typedef struct str_strtok{
	char st_A1[35+1];	
	......
	char st_A13[200+1];	
} STR_STRTOK;


/********************************************************************
* Function��														*
*	struct str_strtok * Get_Strtok_String( char * string, struct str_strtok * st_p , char * split )*
* Description��														*
* 	���ݷָ��ַ�������ȡ�ָ����ݣ�����ṹ��						*
*	�ַ�����ʽ "a1|a2|a3|...|an"									*
* In Params:														*
*	string: Դ�ַ���												*
*	st_p: ��ŵĽṹ��ָ��											*
*	split: �����ָ����ַ���											*
* Out Params:														*
*																	*
* Return:															*
* ��NULL: ʧ��														*
* ��st_p: �ɹ�����ŵĽṹ��ָ��									*
********************************************************************/
struct str_strtok * Get_Strtok_String( char * string, struct str_strtok * st_p , char * split );
#endif


/************************************************************
* Copyright (c) 2015 xxxxxxxxxxxxxxxxxx��˾                 *
* Source File:    Dx_String                                 *
* Description:    �ַ�������                                *
*                 ���Ŀ���ַ�������С��Դ�ַ����ĳ��ȣ����δ��֪*
* Author:         mawx                                      *
* Create Date:    2015/07/09                                *
* In:             sSrc_string ԭ�ַ���                      *
*                 sDst_string Ŀ���ַ���                    *
* Out:            NULL ʧ��                                 *
*                 ��NULL Ŀ���ַ�����ַ                     *
*-----------------------------------------------------------*
* Modify Date:    YYYY-MM-DD                                *
* Modifier:       XXX                                       *
* Modify Note:    XXXXXXXXXXXXXX                            *
* **********************************************************/
char *Dx_String( char * sSrc_string, char * sDst_string );

/************************************************************
* Copyright (c) 2015 xxxxxxxxxxxxxxxxxx��˾                 *
* Source File:    Dx_String_Yzfc                            *
* Description:    �ַ�������(ֱ����Դ�ַ����Ŀռ��ϵ���)    *
* Author:         mawx                                      *
* Create Date:    2015/07/09                                *
* In:             sSrc_string ԭ�ַ���,�ĳɵ�������ַ���   *
* Out:            NULL ʧ��                                 *
*                 ��NULL  �ɹ���Դ�ַ����ĵ�ַ              *
*-----------------------------------------------------------*
* Modify Date:    YYYY-MM-DD                                *
* Modifier:       XXX                                       *
* Modify Note:    XXXXXXXXXXXXXX                            *
* **********************************************************/
char *Dx_String_Yzfc( char * sSrc_string );

/************************************************************
* Copyright (c) 2015 xxxxxxxxxxxxxxxxxx��˾                 *
* Source File:    Del_Char                                  *
* Description:    ȥ���ַ����е�ĳһ�ַ�(ȥ��ĳ�ַ���Դ�ַ����ϲ�)*
*                 �������ַ����ַ����в����ڣ�����Ϊɾ���ɹ� *
* Author:         mawx                                      *
* Create Date:    2015/07/09                                *
* In:             sSrc_String ԭ�ַ���                      *
*                 cChar ȥ���ַ�                            *
* Out:            NULL ʧ��                                 *
*                 ��NULL  �ɹ���Դ�ַ����ĵ�ַ              *
*-----------------------------------------------------------*
* Modify Date:    YYYY-MM-DD                                *
* Modifier:       XXX                                       *
* Modify Note:    XXXXXXXXXXXXXX                            *
* **********************************************************/
char * Del_Char( char * sSrc_String, char cChar );


/************************************************************
* Copyright (c) 2015 xxxxxxxxxxxxxxxxxx��˾                 *
* Source File:    Del_Char_CopyToDst                        *
* Description:    ȥ���ַ����е�ĳһ�ַ�(ȥ��ĳ�ַ���Ŀ���ַ����ϲ�)*
*                 �������ַ����ַ����в����ڣ�����Ϊɾ���ɹ�*
* Author:         mawx                                      *
* Create Date:    2015/07/09                                *
* In:             sSrc_string ԭ�ַ���                      *
*                 sDst_string Ŀ���ַ����������Ȳ��������δ��֪*
*                 sCh ȥ���ַ�                              *
* Out:            NULL ʧ��                                 *
*                 ��NULL �ɹ���Ŀ��ռ��ַ                 *
*-----------------------------------------------------------*
* Modify Date:    YYYY-MM-DD                                *
* Modifier:       XXX                                       *
* Modify Note:    XXXXXXXXXXXXXX                            *
* **********************************************************/
char * Del_Char_CopyToDst( char * sSrc_string, char * sDst_string, char sCh );

/************************************************************
* Copyright (c) 2015 xxxxxxxxxxxxxxxxxx��˾                 *
* Source File:    Del_Char_Hh                               *
* Description:    ȥ���ַ����еĻ��з�                      *
* Author:         mawx                                      *
* Create Date:    2015/07/09                                *
* In:             sSrc_string ԭ�ַ���                       *
*                                                           *
* Out:            NULL ʧ��                                 *
*                 ��NULL  Դ�ַ�����ַ                      *
*-----------------------------------------------------------*
* Modify Date:    YYYY-MM-DD                                *
* Modifier:       XXX                                       *
* Modify Note:    XXXXXXXXXXXXXX                            *
* **********************************************************/
char * Del_Char_Hh( char * sSrc_string);

/************************************************************
* Copyright (c) 2015 xxxxxxxxxxxxxxxxxx��˾                 *
* Source File:    Th_Str_To_Str                             *
* Description:    ��Դ�ַ������滻����Ӧ���ַ���            *
*                 ���û���ҵ���Ҫ�滻���ַ������򷵻�NULL  *
*                 sDst_string Ŀ���ַ������Ȳ����Ļ������δ��֪*
* Author:         mawx                                      *
* Create Date:    2015/07/09                                *
* In:             sSrc_string Դ�ַ���                      *
*                 sDst_string Ŀ���ַ���                    *
*                 sTh_Src_String �滻Դ�ַ���               *
*                 sTh_Dst_String �滻Ŀ���ַ���             *
* Out:            NULL ʧ��                                 *
*                 ��NULL  Ŀ���ַ���                        *
*-----------------------------------------------------------*
* Modify Date:    YYYY-MM-DD                                *
* Modifier:       XXX                                       *
* Modify Note:    XXXXXXXXXXXXXX                            *
* **********************************************************/
char * Th_Str_To_Str( char * sSrc_string, char * sDst_string, char * sTh_Src_String, char * sTh_Dst_String );

/************************************************************
* Copyright (c) 2015 xxxxxxxxxxxxxxxxxx��˾                 *
* Source File:    Del_Char_File                             *
* Description:    ����ɾ��ĳ�ļ��е�ĳһ�ַ�                *
* Author:         mawx                                      *
* Create Date:    2015/07/09                                *
* In:             sFilename �ļ���(����·�����������·��)   *
*                 cCh ��Ҫɾ�������ַ�                      *
* Out:            -1 ʧ��                                   *
*                 0  �ɹ�                                   *
*-----------------------------------------------------------*
* Modify Date:    YYYY-MM-DD                                *
* Modifier:       XXX                                       *
* Modify Note:    XXXXXXXXXXXXXX                            *
* **********************************************************/
int Del_Char_File( char * sFilename, char cCh );

/************************************************************
* Copyright (c) 2015 xxxxxxxxxxxxxxxxxx��˾                 *
* Source File:    Trim_Before                               *
* Description:    ȥ���ַ���ǰ��Ŀո�                      *
* Author:         mawx                                      *
* Create Date:    2015/07/09                                *
* In:             sString Դ�ַ���                          *
* Out:                                                      *
*-----------------------------------------------------------*
* Modify Date:    YYYY-MM-DD                                *
* Modifier:       XXX                                       *
* Modify Note:    XXXXXXXXXXXXXX                            *
* **********************************************************/
void Trim_Before( char * sString );


/************************************************************
* Copyright (c) 2015 xxxxxxxxxxxxxxxxxx��˾                 *
* Source File:    Trim_Behind                               *
* Description:    ȥ���ַ�������Ŀո�                      *
* Author:         mawx                                      *
* Create Date:    2015/07/09                                *
* In:             sString Դ�ַ���                          *
* Out:            NULL ʧ��                                 *
*                 ��NULL �ɹ���Դ�ַ�����ַ                 *
*-----------------------------------------------------------*
* Modify Date:    YYYY-MM-DD                                *
* Modifier:       XXX                                       *
* Modify Note:    XXXXXXXXXXXXXX                            *
* **********************************************************/
char *Trim_Behind( char * sString );
 
/************************************************************
* Copyright (c) 2015 xxxxxxxxxxxxxxxxxx��˾                 *
* Source File:    Trim                                      *
* Description:    ɾ���ַ���ǰ��Ŀո�                      *
* Author:         mawx                                      *
* Create Date:    2015/07/09                                *
* In:             sString Դ�ַ���                          *
* Out:            void                                      *
*-----------------------------------------------------------*
* Modify Date:    YYYY-MM-DD                                *
* Modifier:       XXX                                       *
* Modify Note:    XXXXXXXXXXXXXX                            *
* **********************************************************/
void Trim( char * sString );


/************************************************************
* Copyright (c) 2015 xxxxxxxxxxxxxxxxxx��˾                 *
* Source File:    Trim_And_Del_Hh                           *
* Description:    ȥ���ַ����еĻ��з����ո�                *
* Author:         mawx                                      *
* Create Date:    2015/07/09                                *
* In:             sString Դ�ַ���                          *
* Out:            char * NULL ʧ�ܣ�������                  *
*-----------------------------------------------------------*
* Modify Date:    YYYY-MM-DD                                *
* Modifier:       XXX                                       *
* Modify Note:    XXXXXXXXXXXXXX                            *
* **********************************************************/
char * Trim_Kg_Hh( char * sString );


/************************************************************
* Copyright (c) 2015 xxxxxxxxxxxxxxxxxx��˾                 *
* Source File:    Get_String_Behind_Char                    *
* Description:    ȡ���ַ�cChar����ַ���(����Դ�ַ�����û�ж�Ӧ�ַ�������Ϊʧ��)*
*                 Ŀ���ַ����ռ䲻�������δ��֪            *
* Author:         mawx                                      *
* Create Date:    2015/07/09                                *
* In:             sSrc_string Դ�ַ���                      *
*                 cChar �ַ�                                *
*                 sDst_string Ŀ���ַ���                    *
* Out:            NULL ʧ��                                 *
*                 sDst_string �ɹ�,ȡ�õ��ַ��������dst_string*
*-----------------------------------------------------------*
* Modify Date:    YYYY-MM-DD                                *
* Modifier:       XXX                                       *
* Modify Note:    XXXXXXXXXXXXXX                            *
************************************************************/
char * Get_String_Behind_Char( const char * sSrc_string , char cChar, char * sDst_string );

/************************************************************
* Copyright (c) 2015 xxxxxxxxxxxxxxxxxx��˾                 *
* Source File:    Get_String_Before_Char                    *
* Description:    ȡ���ַ�cCharǰ���ַ���(����Դ�ַ�����û�ж�Ӧ�ַ�������Ϊʧ��)*
*                 Ŀ���ַ����ռ䲻�������δ��֪            *
* Author:         mawx                                      *
* Create Date:    2015/07/09                                *
* In:             sSrc_string Դ�ַ���                      *
*                 cChar �ַ�                                *
*                 sDst_string Ŀ���ַ���                    *
* Out:            NULL ʧ��                                 *
*                 sDst_string �ɹ�,ȡ�õ��ַ��������dst_string*
*-----------------------------------------------------------*
* Modify Date:    YYYY-MM-DD                                *
* Modifier:       XXX                                       *
* Modify Note:    XXXXXXXXXXXXXX                            *
************************************************************/
char * Get_String_Before_Char( const char * sSrc_string , char cChar, char * sDst_string );

/************************************************************
* Copyright (c) 2015 xxxxxxxxxxxxxxxxxx��˾                 *
* Source File:    Get_String_Behind_Dh                      *
* Description:    ȡ���ַ�'='����ַ���(ԭ���ģ�û��ȥ���ո񡢻��з�)*
*                 (����Դ�ַ�����û�ж�Ӧ�ַ�������Ϊʧ��)  *
* Author:         mawx                                      *
* Create Date:    2015/07/09                                *
* In:             src_string Դ�ַ���                       *
*                 ch �ַ�                                   *
* Out:            NULL ʧ��                                 *
*                 dst_string �ɹ�,ȡ�õ��ַ��������dst_string*
*-----------------------------------------------------------*
* Modify Date:    YYYY-MM-DD                                *
* Modifier:       XXX                                       *
* Modify Note:    XXXXXXXXXXXXXX                            *
************************************************************/
char * Get_String_Behind_Dh( char * src_string , char * dst_string );

/************************************************************
* Copyright (c) 2015 xxxxxxxxxxxxxxxxxx��˾                 *
* Source File:    Get_String_Before_Dh                      *
* Description:    ȡ���ַ�'='ǰ���ַ���(ԭ���ģ�û��ȥ���ո񡢻��з�)*
*                 (����Դ�ַ�����û�ж�Ӧ�ַ�������Ϊʧ��)  *
* Author:         mawx                                      *
* Create Date:    2015/07/09                                *
* In:             src_string Դ�ַ���                       *
*                 ch �ַ�                                   *
* Out:            NULL ʧ��                                 *
*                 dst_string �ɹ�,ȡ�õ��ַ��������dst_string*
*-----------------------------------------------------------*
* Modify Date:    YYYY-MM-DD                                *
* Modifier:       XXX                                       *
* Modify Note:    XXXXXXXXXXXXXX                            *
************************************************************/
char * Get_String_Before_Dh( char * src_string , char * dst_string );

/************************************************************
* Copyright (c) 2015 xxxxxxxxxxxxxxxxxx��˾                 *
* Source File:    Get_String_Behind_Dh_QdKgHh               *
* Description:    ȡ���ַ�'='����ַ���(ȥ���ո񡢻��з�)   *
*                 (����Դ�ַ�����û�ж�Ӧ�ַ�������Ϊʧ��)  *
* Author:         mawx                                      *
* Create Date:    2015/07/09                                *
* In:             sSrc_String Դ�ַ���                      *
*                 ch �ַ�                                   *
* Out:            char *                                    *
*                 NULL ʧ��                                 *
*                 sDst_String �ɹ�,ȡ�õ��ַ��������dst_string*
*-----------------------------------------------------------*
* Modify Date:    YYYY-MM-DD                                *
* Modifier:       XXX                                       *
* Modify Note:    XXXXXXXXXXXXXX                            *
************************************************************/
char * Get_String_Behind_Dh_QdKgHh( char * sSrc_String , char * sDst_String );

/************************************************************
* Copyright (c) 2015 xxxxxxxxxxxxxxxxxx��˾                 *
* Source File:    Get_String_Before_Dh_QdKgHh               *
* Description:    ȡ���ַ�'='ǰ���ַ���(ȥ���ո񡢻��з�)   *
*                 (����Դ�ַ�����û�ж�Ӧ�ַ�������Ϊʧ��)  *
* Author:         mawx                                      *
* Create Date:    2015/07/09                                *
* In:             sSrc_String Դ�ַ���                      *
*                 ch �ַ�                                   *
* Out:            char *                                    *
*                 NULL ʧ��                                 *
*                 sDst_String �ɹ�,ȡ�õ��ַ��������dst_string*
*-----------------------------------------------------------*
* Modify Date:    YYYY-MM-DD                                *
* Modifier:       XXX                                       *
* Modify Note:    XXXXXXXXXXXXXX                            *
************************************************************/
char * Get_String_Before_Dh_QdKgHh( char * sSrc_String , char * sDst_String );

/************************************************************
* Copyright (c) 2015 xxxxxxxxxxxxxxxxxx��˾                 *
* Source File:    Get_String_Behind_Dh_QdKg                 *
* Description:    ȡ���ַ�'='����ַ���(ȥ���ո�)           *
*                 (����Դ�ַ�����û�ж�Ӧ�ַ�������Ϊʧ��)  *
* Author:         mawx                                      *
* Create Date:    2015/07/09                                *
* In:             sSrc_String Դ�ַ���                      *
* Out:            NULL ʧ��                                 *
*                 sDst_String �ɹ�,ȡ�õ��ַ��������dst_string*
*-----------------------------------------------------------*
* Modify Date:    YYYY-MM-DD                                *
* Modifier:       XXX                                       *
* Modify Note:    XXXXXXXXXXXXXX                            *
************************************************************/
char * Get_String_Behind_Dh_QdKg( char * sSrc_String , char * sDst_String );

/************************************************************
* Copyright (c) 2015 xxxxxxxxxxxxxxxxxx��˾                 *
* Source File:    Get_String_Before_Dh_QdKg                 *
* Description:    ȡ���ַ�'='ǰ���ַ���(ȥ���ո�)           *
*                 (����Դ�ַ�����û�ж�Ӧ�ַ�������Ϊʧ��)  *
* Author:         mawx                                      *
* Create Date:    2015/07/09                                *
* In:             sSrc_String Դ�ַ���                      *
* Out:            NULL ʧ��                                 *
*                 sDst_String �ɹ�,ȡ�õ��ַ��������dst_string*
*-----------------------------------------------------------*
* Modify Date:    YYYY-MM-DD                                *
* Modifier:       XXX                                       *
* Modify Note:    XXXXXXXXXXXXXX                            *
************************************************************/
char * Get_String_Before_Dh_QdKg( char * sSrc_String , char * sDst_String );

/************************************************************
* Copyright (c) 2015 xxxxxxxxxxxxxxxxxx��˾                 *
* Source File:    Get_String_Between_Zkh                    *
* Description:    ȡ���������ڵĵ��ַ���                    *
*                 (����Դ�ַ�����û�ж�Ӧ�ַ�������Ϊʧ��)  *
* Author:         mawx                                      *
* Create Date:    2015/07/09                                *
* In:             sSrc_String Դ�ַ���                      *
* Out:            NULL ʧ��                                 *
*                 sDst_String �ɹ�,ȡ�õ��ַ��������dst_string*
*-----------------------------------------------------------*
* Modify Date:    YYYY-MM-DD                                *
* Modifier:       XXX                                       *
* Modify Note:    XXXXXXXXXXXXXX                            *
************************************************************/
char * Get_String_Between_Zkh( const char * sSrc_String , char * sDst_String );

/************************************************************
* Copyright (c) 2015 xxxxxxxxxxxxxxxxxx��˾                 *
* Source File:    Is_Digit_ByString                         *
* Description:    �ַ��������Ƿ��Ƿ������ֹ���(�ɴ�С����)*
* Author:         mawx                                      *
* Create Date:    2015/07/09                                *
* In:             sDigit_Str ��Ҫ�жϵ��ַ���               *
* Out:            0 ������                                  *
*                 1 ����                                    *
*-----------------------------------------------------------*
* Modify Date:    YYYY-MM-DD                                *
* Modifier:       XXX                                       *
* Modify Note:    XXXXXXXXXXXXXX                            *
************************************************************/
int Is_Digit_ByString( const char * sDigit_Str );

/************************************************************
* Copyright (c) 2015 xxxxxxxxxxxxxxxxxx��˾                 *
* Source File:    Is_Digit_ByChar                           *
* Description:    �ַ������Ƿ��Ƿ������ֹ���(�ɴ�С����)  *
* Author:         mawx                                      *
* Create Date:    2015/07/09                                *
* In:             sDigit_Str ��Ҫ�жϵ��ַ���               *
* Out:            0 ������                                  *
*                 1 ����                                    *
*-----------------------------------------------------------*
* Modify Date:    YYYY-MM-DD                                *
* Modifier:       XXX                                       *
* Modify Note:    XXXXXXXXXXXXXX                            *
************************************************************/
int Is_Digit_ByChar( const char sDigit_Str );

/************************************************************
* Copyright (c) 2015 xxxxxxxxxxxxxxxxxx��˾                 *
* Source File:    Is_EnglishChar_ByString                   *
* Description:    �ַ��������Ƿ���Ӣ����ĸ�Ĺ���          *
* Author:         mawx                                      *
* Create Date:    2015/07/09                                *
* In:             sEnglishChar_Str  ��Ҫ�жϵ��ַ���        *
* Out:            0 �з���ĸ                                *
*                 1 ֻ��Сд��ĸ                            *
*                 2 ֻ�д�д��ĸ                            *
*                 3 ��д��ĸ��Сд��ĸ����                  *
*-----------------------------------------------------------*
* Modify Date:    YYYY-MM-DD                                *
* Modifier:       XXX                                       *
* Modify Note:    XXXXXXXXXXXXXX                            *
************************************************************/
int Is_EnglishChar_ByString( const char * sEnglishChar_Str );


/************************************************************
* Copyright (c) 2015 xxxxxxxxxxxxxxxxxx��˾                 *
* Source File:    Is_EnglishChar_ByChar                     *
* Description:    �ַ������Ƿ���Ӣ����ĸ�Ĺ���            *
* Author:         mawx                                      *
* Create Date:    2015/07/09                                *
* In:             sEnglishChar_Str  ��Ҫ�жϵ��ַ���        *
* Out:            0 �з���ĸ                                *
*                 1 ֻ��Сд��ĸ                            *
*                 2 ֻ�д�д��ĸ                            *
*                 3 ��д��ĸ��Сд��ĸ����                  *
*-----------------------------------------------------------*
* Modify Date:    YYYY-MM-DD                                *
* Modifier:       XXX                                       *
* Modify Note:    XXXXXXXXXXXXXX                            *
************************************************************/
int Is_EnglishChar_ByChar( const char sEnglishChar_Str );

/************************************************************
* Copyright (c) 2015 xxxxxxxxxxxxxxxxxx��˾                 *
* Source File:    Is_EnglishChar_Digit_ByString             *
* Description:    �ַ��������Ƿ���Ӣ����ĸ�����֣���С���㣩�Ĺ��� *
* Author:         mawx                                      *
* Create Date:    2015/07/09                                *
* In:             sEnglishChar_Str  ��Ҫ�жϵ��ַ���        *
* Out:            0 ����ĸ��Ҳ�����ֻ�С����                *
*                 1 �� ֻ��Сд��ĸ                         *
*                 2 �� ֻ�д�д��ĸ                         *
*                 3 �� ��д��ĸ��Сд��ĸ����               *
*                 4 �� ����(����С����)                     *
*                 5 ����(����С����)��Ӣ����ĸ���          *
*-----------------------------------------------------------*
* Modify Date:    YYYY-MM-DD                                *
* Modifier:       XXX                                       *
* Modify Note:    XXXXXXXXXXXXXX                            *
************************************************************/
int Is_EnglishChar_Digit_ByString( const char * sSrc_Str );

#endif


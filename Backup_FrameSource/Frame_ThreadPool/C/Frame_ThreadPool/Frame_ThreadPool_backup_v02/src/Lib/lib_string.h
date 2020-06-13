#ifndef __LIB_STRING_H__
#define __LIB_STRING_H__
/************************************************************
* Copyright (c) 2015 xxxxxxxxxxxxxxxxxx公司                 *
* Source File:    lib_mem_str.c                             *
* Description:    关于内存、字符串的lib                     *
* Author:         mawx                                      *
* Create Date:    2015/05/14                                *
*-----------------------------------------------------------*
* Modify Date:    YYYY-MM-DD                                *
* Modifier:       XXX                                       *
* Modify Note:    XXXXXXXXXXXXXX                            *
************************************************************/



/************************************************************
* Copyright (c) 2015 xxxxxxxxxxxxxxxxxx公司                 *
* Source File:    AddStr_Malloc                             *
* Description:    分配一块新的内存，将字符串拷贝至此        *
* Author:         mawx                                      *
* Create Date:    2015/07/09                                *
* In:             sAdd_String 需要添加的字符串              *
*                 pDst_Mem 分配的动态内存的地址             *
* Out:            char * NULL失败                           *
*                 非NULL重新分配的内存地址                  *
*-----------------------------------------------------------*
* Modify Date:    YYYY-MM-DD                                *
* Modifier:       XXX                                       *
* Modify Note:    XXXXXXXXXXXXXX                            *
************************************************************/
char * AddStr_Malloc( const char * sAdd_String, char ** pDst_Mem );


/************************************************************
* Copyright (c) 2015 xxxxxxxxxxxxxxxxxx公司                 *
* Source File:    AddStr_Realloc                            *
* Description:    在新分配的内存中，在尾部添加字符串        *
*                 原内存也必须是malloc类型函数分配的动态内存*
*                 新分配的内存长度 原内存字符串长度+添加字符串的长度+1 *
* Author:         mawx                                      *
* Create Date:    2015/07/09                                *
* In:             pSrc_Mem    原动态内存地址                *
*                 sAdd_String 需要添加的字符串              *
*                 pDst_Mem 新的动态内存的地址               *
* Out:            char * NULL失败                           *
*                 非NULL重新分配的内存地址                  *
*-----------------------------------------------------------*
* Modify Date:    YYYY-MM-DD                                *
* Modifier:       XXX                                       *
* Modify Note:    XXXXXXXXXXXXXX                            *
************************************************************/
char * AddStr_Realloc( char * pSrc_Mem, const char * sAdd_String, char ** pDst_Mem );

/************************************************************
* Copyright (c) 2015 xxxxxxxxxxxxxxxxxx公司                 *
* Source File:    AddStr_Free                               *
* Description:    释放AddStr_Realloc、AddStr_Malloc添加内存 *
* Author:         mawx                                      *
* Create Date:    2015/07/09                                *
* In:             pPoint_Mem    原动态内存地址              *
* Out:            void                                      *
*                                                           *
*-----------------------------------------------------------*
* Modify Date:    YYYY-MM-DD                                *
* Modifier:       XXX                                       *
* Modify Note:    XXXXXXXXXXXXXX                            *
************************************************************/
void AddStr_Free( char ** pPoint_Mem );

/************************************************************
* Copyright (c) 2015 xxxxxxxxxxxxxxxxxx公司                 *
* Source File:    Count_Char_Num                            *
* Description:    判断源字符串中的子串的个数                *
* Author:         mawx                                      *
* Create Date:    2015/07/09                                *
* In:             sSrc_String    源字符串                   *
*                 sChild_String 子字符串                    *
* Out:            int 个数                                  *
*-----------------------------------------------------------*
* Modify Date:    YYYY-MM-DD                                *
* Modifier:       XXX                                       *
* Modify Note:    XXXXXXXXXXXXXX                            *
************************************************************/
int Count_Char_Num( char * sSrc_String, char * sChild_String );

/************************************************************
* Copyright (c) 2015 xxxxxxxxxxxxxxxxxx公司                 *
* Source File:    Char_To_Str                               *
* Description:    字符转换成字符串                          *
* Author:         mawx                                      *
* Create Date:    2015/07/09                                *
* In:             cSrc_Char    源字符                       *
*                 sDst_String  目标字符串，如果目标字符串的空间少于2个，则结果未可知*
* Out:            char * NULL失败，非NULL 目标字符串的地址  *
*-----------------------------------------------------------*
* Modify Date:    YYYY-MM-DD                                *
* Modifier:       XXX                                       *
* Modify Note:    XXXXXXXXXXXXXX                            *
************************************************************/
char * Char_To_Str( const char cSrc_Char, char * sDst_String );

/************************************************************
* Copyright (c) 2015 xxxxxxxxxxxxxxxxxx公司                 *
* Source File:    Str_To_Char                               *
* Description:    字符转换成字符串（字符串第一位为准）      *
* Author:         mawx                                      *
* Create Date:    2015/07/09                                *
* In:             sSrc_String 源字符串，若长度大于1，则以第一位的字符为准*
*                 sDst_Char   目标字符                      *                      
* Out:            char * NULL失败，源字符串的值             *
*-----------------------------------------------------------*
* Modify Date:    YYYY-MM-DD                                *
* Modifier:       XXX                                       *
* Modify Note:    XXXXXXXXXXXXXX                            *
************************************************************/
char * Str_To_Char( const char * sSrc_String, char sDst_Char );



/************************************************************
* Copyright (c) 2015 xxxxxxxxxxxxxxxxxx公司                 *
* Source File:    GetString_YYYYMMDD                        *
* Description:    获取当前时间的YYYYMMDD                    *
* Author:         mawx                                      *
* Create Date:    2015/07/09                                *
* In:             pPoint_TimeMem  获取的YYYYMMDD放在该字符串中*
*                 pPoint_TimeMem 若是内存不够，结果未可知   *
* Out:            void                                      *
*-----------------------------------------------------------*
* Modify Date:    YYYY-MM-DD                                *
* Modifier:       XXX                                       *
* Modify Note:    XXXXXXXXXXXXXX                            *
************************************************************/
void GetString_YYYYMMDD( char * pPoint_TimeMem );

/************************************************************
* Copyright (c) 2015 xxxxxxxxxxxxxxxxxx公司                 *
* Source File:    GetString_HHMMSS                          *
* Description:    获取当前时间的HHMMSS                      *
* Author:         mawx                                      *
* Create Date:    2015/07/09                                *
* In:             pPoint_TimeMem  获取的HHMMSS放在该字符串中*
*                 pPoint_TimeMem 若是内存不够，结果未可知   *
* Out:            void                                      *
*-----------------------------------------------------------*
* Modify Date:    YYYY-MM-DD                                *
* Modifier:       XXX                                       *
* Modify Note:    XXXXXXXXXXXXXX                            *
************************************************************/
void GetString_HHMMSS( char * pPoint_TimeMem );

/************************************************************
* Copyright (c) 2015 xxxxxxxxxxxxxxxxxx公司                 *
* Source File:    GetString_HHMMSS                          *
* Description:    获取当前时间的计算机的时间（秒数）        *
* Author:         mawx                                      *
* Create Date:    2015/07/09                                *
* In:             pPoint_TimeMem  获取的HHMMSS放在该字符串中*
*                 pPoint_TimeMem 若是内存不够，结果未可知   *
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
* Function：														*
*	struct str_strtok * Get_Strtok_String( char * string, struct str_strtok * st_p , char * split )*
* Description：														*
* 	根据分隔字符串，获取分隔内容，放入结构体						*
*	字符串格式 "a1|a2|a3|...|an"									*
* In Params:														*
*	string: 源字符串												*
*	st_p: 存放的结构体指针											*
*	split: 用来分隔的字符串											*
* Out Params:														*
*																	*
* Return:															*
* 　NULL: 失败														*
* 　st_p: 成功，存放的结构体指针									*
********************************************************************/
struct str_strtok * Get_Strtok_String( char * string, struct str_strtok * st_p , char * split );
#endif


/************************************************************
* Copyright (c) 2015 xxxxxxxxxxxxxxxxxx公司                 *
* Source File:    Dx_String                                 *
* Description:    字符串倒序                                *
*                 如果目的字符串长度小于源字符串的长度，结果未可知*
* Author:         mawx                                      *
* Create Date:    2015/07/09                                *
* In:             sSrc_string 原字符串                      *
*                 sDst_string 目的字符串                    *
* Out:            NULL 失败                                 *
*                 非NULL 目的字符串地址                     *
*-----------------------------------------------------------*
* Modify Date:    YYYY-MM-DD                                *
* Modifier:       XXX                                       *
* Modify Note:    XXXXXXXXXXXXXX                            *
* **********************************************************/
char *Dx_String( char * sSrc_string, char * sDst_string );

/************************************************************
* Copyright (c) 2015 xxxxxxxxxxxxxxxxxx公司                 *
* Source File:    Dx_String_Yzfc                            *
* Description:    字符串倒序(直接在源字符串的空间上倒叙)    *
* Author:         mawx                                      *
* Create Date:    2015/07/09                                *
* In:             sSrc_string 原字符串,改成到倒序的字符串   *
* Out:            NULL 失败                                 *
*                 非NULL  成功，源字符串的地址              *
*-----------------------------------------------------------*
* Modify Date:    YYYY-MM-DD                                *
* Modifier:       XXX                                       *
* Modify Note:    XXXXXXXXXXXXXX                            *
* **********************************************************/
char *Dx_String_Yzfc( char * sSrc_string );

/************************************************************
* Copyright (c) 2015 xxxxxxxxxxxxxxxxxx公司                 *
* Source File:    Del_Char                                  *
* Description:    去掉字符串中的某一字符(去掉某字符后，源字符串合并)*
*                 如果这个字符在字符串中不存在，则认为删除成功 *
* Author:         mawx                                      *
* Create Date:    2015/07/09                                *
* In:             sSrc_String 原字符串                      *
*                 cChar 去掉字符                            *
* Out:            NULL 失败                                 *
*                 非NULL  成功，源字符串的地址              *
*-----------------------------------------------------------*
* Modify Date:    YYYY-MM-DD                                *
* Modifier:       XXX                                       *
* Modify Note:    XXXXXXXXXXXXXX                            *
* **********************************************************/
char * Del_Char( char * sSrc_String, char cChar );


/************************************************************
* Copyright (c) 2015 xxxxxxxxxxxxxxxxxx公司                 *
* Source File:    Del_Char_CopyToDst                        *
* Description:    去掉字符串中的某一字符(去掉某字符后，目标字符串合并)*
*                 如果这个字符在字符串中不存在，则认为删除成功*
* Author:         mawx                                      *
* Create Date:    2015/07/09                                *
* In:             sSrc_string 原字符串                      *
*                 sDst_string 目的字符串，若长度不够，结果未可知*
*                 sCh 去掉字符                              *
* Out:            NULL 失败                                 *
*                 非NULL 成功，目标空间地址                 *
*-----------------------------------------------------------*
* Modify Date:    YYYY-MM-DD                                *
* Modifier:       XXX                                       *
* Modify Note:    XXXXXXXXXXXXXX                            *
* **********************************************************/
char * Del_Char_CopyToDst( char * sSrc_string, char * sDst_string, char sCh );

/************************************************************
* Copyright (c) 2015 xxxxxxxxxxxxxxxxxx公司                 *
* Source File:    Del_Char_Hh                               *
* Description:    去掉字符串中的换行符                      *
* Author:         mawx                                      *
* Create Date:    2015/07/09                                *
* In:             sSrc_string 原字符串                       *
*                                                           *
* Out:            NULL 失败                                 *
*                 非NULL  源字符串地址                      *
*-----------------------------------------------------------*
* Modify Date:    YYYY-MM-DD                                *
* Modifier:       XXX                                       *
* Modify Note:    XXXXXXXXXXXXXX                            *
* **********************************************************/
char * Del_Char_Hh( char * sSrc_string);

/************************************************************
* Copyright (c) 2015 xxxxxxxxxxxxxxxxxx公司                 *
* Source File:    Th_Str_To_Str                             *
* Description:    在源字符串中替换掉对应的字符串            *
*                 如果没有找到需要替换的字符串，则返回NULL  *
*                 sDst_string 目标字符串长度不够的话，结果未可知*
* Author:         mawx                                      *
* Create Date:    2015/07/09                                *
* In:             sSrc_string 源字符串                      *
*                 sDst_string 目标字符串                    *
*                 sTh_Src_String 替换源字符串               *
*                 sTh_Dst_String 替换目标字符串             *
* Out:            NULL 失败                                 *
*                 非NULL  目标字符串                        *
*-----------------------------------------------------------*
* Modify Date:    YYYY-MM-DD                                *
* Modifier:       XXX                                       *
* Modify Note:    XXXXXXXXXXXXXX                            *
* **********************************************************/
char * Th_Str_To_Str( char * sSrc_string, char * sDst_string, char * sTh_Src_String, char * sTh_Dst_String );

/************************************************************
* Copyright (c) 2015 xxxxxxxxxxxxxxxxxx公司                 *
* Source File:    Del_Char_File                             *
* Description:    批量删除某文件中的某一字符                *
* Author:         mawx                                      *
* Create Date:    2015/07/09                                *
* In:             sFilename 文件名(绝对路径，或者相对路径)   *
*                 cCh 需要删除掉的字符                      *
* Out:            -1 失败                                   *
*                 0  成功                                   *
*-----------------------------------------------------------*
* Modify Date:    YYYY-MM-DD                                *
* Modifier:       XXX                                       *
* Modify Note:    XXXXXXXXXXXXXX                            *
* **********************************************************/
int Del_Char_File( char * sFilename, char cCh );

/************************************************************
* Copyright (c) 2015 xxxxxxxxxxxxxxxxxx公司                 *
* Source File:    Trim_Before                               *
* Description:    去掉字符串前面的空格                      *
* Author:         mawx                                      *
* Create Date:    2015/07/09                                *
* In:             sString 源字符串                          *
* Out:                                                      *
*-----------------------------------------------------------*
* Modify Date:    YYYY-MM-DD                                *
* Modifier:       XXX                                       *
* Modify Note:    XXXXXXXXXXXXXX                            *
* **********************************************************/
void Trim_Before( char * sString );


/************************************************************
* Copyright (c) 2015 xxxxxxxxxxxxxxxxxx公司                 *
* Source File:    Trim_Behind                               *
* Description:    去掉字符串后面的空格                      *
* Author:         mawx                                      *
* Create Date:    2015/07/09                                *
* In:             sString 源字符串                          *
* Out:            NULL 失败                                 *
*                 非NULL 成功，源字符串地址                 *
*-----------------------------------------------------------*
* Modify Date:    YYYY-MM-DD                                *
* Modifier:       XXX                                       *
* Modify Note:    XXXXXXXXXXXXXX                            *
* **********************************************************/
char *Trim_Behind( char * sString );
 
/************************************************************
* Copyright (c) 2015 xxxxxxxxxxxxxxxxxx公司                 *
* Source File:    Trim                                      *
* Description:    删除字符串前后的空格                      *
* Author:         mawx                                      *
* Create Date:    2015/07/09                                *
* In:             sString 源字符串                          *
* Out:            void                                      *
*-----------------------------------------------------------*
* Modify Date:    YYYY-MM-DD                                *
* Modifier:       XXX                                       *
* Modify Note:    XXXXXXXXXXXXXX                            *
* **********************************************************/
void Trim( char * sString );


/************************************************************
* Copyright (c) 2015 xxxxxxxxxxxxxxxxxx公司                 *
* Source File:    Trim_And_Del_Hh                           *
* Description:    去掉字符串中的换行符、空格                *
* Author:         mawx                                      *
* Create Date:    2015/07/09                                *
* In:             sString 源字符串                          *
* Out:            char * NULL 失败，其他城                  *
*-----------------------------------------------------------*
* Modify Date:    YYYY-MM-DD                                *
* Modifier:       XXX                                       *
* Modify Note:    XXXXXXXXXXXXXX                            *
* **********************************************************/
char * Trim_Kg_Hh( char * sString );


/************************************************************
* Copyright (c) 2015 xxxxxxxxxxxxxxxxxx公司                 *
* Source File:    Get_String_Behind_Char                    *
* Description:    取得字符cChar后的字符串(若在源字符串中没有对应字符，则认为失败)*
*                 目标字符串空间不够，结果未可知            *
* Author:         mawx                                      *
* Create Date:    2015/07/09                                *
* In:             sSrc_string 源字符串                      *
*                 cChar 字符                                *
*                 sDst_string 目标字符串                    *
* Out:            NULL 失败                                 *
*                 sDst_string 成功,取得的字符串存放在dst_string*
*-----------------------------------------------------------*
* Modify Date:    YYYY-MM-DD                                *
* Modifier:       XXX                                       *
* Modify Note:    XXXXXXXXXXXXXX                            *
************************************************************/
char * Get_String_Behind_Char( const char * sSrc_string , char cChar, char * sDst_string );

/************************************************************
* Copyright (c) 2015 xxxxxxxxxxxxxxxxxx公司                 *
* Source File:    Get_String_Before_Char                    *
* Description:    取得字符cChar前的字符串(若在源字符串中没有对应字符，则认为失败)*
*                 目标字符串空间不够，结果未可知            *
* Author:         mawx                                      *
* Create Date:    2015/07/09                                *
* In:             sSrc_string 源字符串                      *
*                 cChar 字符                                *
*                 sDst_string 目标字符串                    *
* Out:            NULL 失败                                 *
*                 sDst_string 成功,取得的字符串存放在dst_string*
*-----------------------------------------------------------*
* Modify Date:    YYYY-MM-DD                                *
* Modifier:       XXX                                       *
* Modify Note:    XXXXXXXXXXXXXX                            *
************************************************************/
char * Get_String_Before_Char( const char * sSrc_string , char cChar, char * sDst_string );

/************************************************************
* Copyright (c) 2015 xxxxxxxxxxxxxxxxxx公司                 *
* Source File:    Get_String_Behind_Dh                      *
* Description:    取得字符'='后的字符串(原生的，没有去掉空格、换行符)*
*                 (若在源字符串中没有对应字符，则认为失败)  *
* Author:         mawx                                      *
* Create Date:    2015/07/09                                *
* In:             src_string 源字符串                       *
*                 ch 字符                                   *
* Out:            NULL 失败                                 *
*                 dst_string 成功,取得的字符串存放在dst_string*
*-----------------------------------------------------------*
* Modify Date:    YYYY-MM-DD                                *
* Modifier:       XXX                                       *
* Modify Note:    XXXXXXXXXXXXXX                            *
************************************************************/
char * Get_String_Behind_Dh( char * src_string , char * dst_string );

/************************************************************
* Copyright (c) 2015 xxxxxxxxxxxxxxxxxx公司                 *
* Source File:    Get_String_Before_Dh                      *
* Description:    取得字符'='前的字符串(原生的，没有去掉空格、换行符)*
*                 (若在源字符串中没有对应字符，则认为失败)  *
* Author:         mawx                                      *
* Create Date:    2015/07/09                                *
* In:             src_string 源字符串                       *
*                 ch 字符                                   *
* Out:            NULL 失败                                 *
*                 dst_string 成功,取得的字符串存放在dst_string*
*-----------------------------------------------------------*
* Modify Date:    YYYY-MM-DD                                *
* Modifier:       XXX                                       *
* Modify Note:    XXXXXXXXXXXXXX                            *
************************************************************/
char * Get_String_Before_Dh( char * src_string , char * dst_string );

/************************************************************
* Copyright (c) 2015 xxxxxxxxxxxxxxxxxx公司                 *
* Source File:    Get_String_Behind_Dh_QdKgHh               *
* Description:    取得字符'='后的字符串(去掉空格、换行符)   *
*                 (若在源字符串中没有对应字符，则认为失败)  *
* Author:         mawx                                      *
* Create Date:    2015/07/09                                *
* In:             sSrc_String 源字符串                      *
*                 ch 字符                                   *
* Out:            char *                                    *
*                 NULL 失败                                 *
*                 sDst_String 成功,取得的字符串存放在dst_string*
*-----------------------------------------------------------*
* Modify Date:    YYYY-MM-DD                                *
* Modifier:       XXX                                       *
* Modify Note:    XXXXXXXXXXXXXX                            *
************************************************************/
char * Get_String_Behind_Dh_QdKgHh( char * sSrc_String , char * sDst_String );

/************************************************************
* Copyright (c) 2015 xxxxxxxxxxxxxxxxxx公司                 *
* Source File:    Get_String_Before_Dh_QdKgHh               *
* Description:    取得字符'='前的字符串(去掉空格、换行符)   *
*                 (若在源字符串中没有对应字符，则认为失败)  *
* Author:         mawx                                      *
* Create Date:    2015/07/09                                *
* In:             sSrc_String 源字符串                      *
*                 ch 字符                                   *
* Out:            char *                                    *
*                 NULL 失败                                 *
*                 sDst_String 成功,取得的字符串存放在dst_string*
*-----------------------------------------------------------*
* Modify Date:    YYYY-MM-DD                                *
* Modifier:       XXX                                       *
* Modify Note:    XXXXXXXXXXXXXX                            *
************************************************************/
char * Get_String_Before_Dh_QdKgHh( char * sSrc_String , char * sDst_String );

/************************************************************
* Copyright (c) 2015 xxxxxxxxxxxxxxxxxx公司                 *
* Source File:    Get_String_Behind_Dh_QdKg                 *
* Description:    取得字符'='后的字符串(去掉空格)           *
*                 (若在源字符串中没有对应字符，则认为失败)  *
* Author:         mawx                                      *
* Create Date:    2015/07/09                                *
* In:             sSrc_String 源字符串                      *
* Out:            NULL 失败                                 *
*                 sDst_String 成功,取得的字符串存放在dst_string*
*-----------------------------------------------------------*
* Modify Date:    YYYY-MM-DD                                *
* Modifier:       XXX                                       *
* Modify Note:    XXXXXXXXXXXXXX                            *
************************************************************/
char * Get_String_Behind_Dh_QdKg( char * sSrc_String , char * sDst_String );

/************************************************************
* Copyright (c) 2015 xxxxxxxxxxxxxxxxxx公司                 *
* Source File:    Get_String_Before_Dh_QdKg                 *
* Description:    取得字符'='前的字符串(去掉空格)           *
*                 (若在源字符串中没有对应字符，则认为失败)  *
* Author:         mawx                                      *
* Create Date:    2015/07/09                                *
* In:             sSrc_String 源字符串                      *
* Out:            NULL 失败                                 *
*                 sDst_String 成功,取得的字符串存放在dst_string*
*-----------------------------------------------------------*
* Modify Date:    YYYY-MM-DD                                *
* Modifier:       XXX                                       *
* Modify Note:    XXXXXXXXXXXXXX                            *
************************************************************/
char * Get_String_Before_Dh_QdKg( char * sSrc_String , char * sDst_String );

/************************************************************
* Copyright (c) 2015 xxxxxxxxxxxxxxxxxx公司                 *
* Source File:    Get_String_Between_Zkh                    *
* Description:    取得中括号内的的字符串                    *
*                 (若在源字符串中没有对应字符，则认为失败)  *
* Author:         mawx                                      *
* Create Date:    2015/07/09                                *
* In:             sSrc_String 源字符串                      *
* Out:            NULL 失败                                 *
*                 sDst_String 成功,取得的字符串存放在dst_string*
*-----------------------------------------------------------*
* Modify Date:    YYYY-MM-DD                                *
* Modifier:       XXX                                       *
* Modify Note:    XXXXXXXXXXXXXX                            *
************************************************************/
char * Get_String_Between_Zkh( const char * sSrc_String , char * sDst_String );

/************************************************************
* Copyright (c) 2015 xxxxxxxxxxxxxxxxxx公司                 *
* Source File:    Is_Digit_ByString                         *
* Description:    字符串内容是否都是符合数字规则(可带小数点)*
* Author:         mawx                                      *
* Create Date:    2015/07/09                                *
* In:             sDigit_Str 需要判断的字符串               *
* Out:            0 非数字                                  *
*                 1 数字                                    *
*-----------------------------------------------------------*
* Modify Date:    YYYY-MM-DD                                *
* Modifier:       XXX                                       *
* Modify Note:    XXXXXXXXXXXXXX                            *
************************************************************/
int Is_Digit_ByString( const char * sDigit_Str );

/************************************************************
* Copyright (c) 2015 xxxxxxxxxxxxxxxxxx公司                 *
* Source File:    Is_Digit_ByChar                           *
* Description:    字符内容是否都是符合数字规则(可带小数点)  *
* Author:         mawx                                      *
* Create Date:    2015/07/09                                *
* In:             sDigit_Str 需要判断的字符串               *
* Out:            0 非数字                                  *
*                 1 数字                                    *
*-----------------------------------------------------------*
* Modify Date:    YYYY-MM-DD                                *
* Modifier:       XXX                                       *
* Modify Note:    XXXXXXXXXXXXXX                            *
************************************************************/
int Is_Digit_ByChar( const char sDigit_Str );

/************************************************************
* Copyright (c) 2015 xxxxxxxxxxxxxxxxxx公司                 *
* Source File:    Is_EnglishChar_ByString                   *
* Description:    字符串内容是否都是英文字母的规则          *
* Author:         mawx                                      *
* Create Date:    2015/07/09                                *
* In:             sEnglishChar_Str  需要判断的字符串        *
* Out:            0 有非字母                                *
*                 1 只有小写字母                            *
*                 2 只有大写字母                            *
*                 3 大写字母、小写字母都有                  *
*-----------------------------------------------------------*
* Modify Date:    YYYY-MM-DD                                *
* Modifier:       XXX                                       *
* Modify Note:    XXXXXXXXXXXXXX                            *
************************************************************/
int Is_EnglishChar_ByString( const char * sEnglishChar_Str );


/************************************************************
* Copyright (c) 2015 xxxxxxxxxxxxxxxxxx公司                 *
* Source File:    Is_EnglishChar_ByChar                     *
* Description:    字符内容是否都是英文字母的规则            *
* Author:         mawx                                      *
* Create Date:    2015/07/09                                *
* In:             sEnglishChar_Str  需要判断的字符串        *
* Out:            0 有非字母                                *
*                 1 只有小写字母                            *
*                 2 只有大写字母                            *
*                 3 大写字母、小写字母都有                  *
*-----------------------------------------------------------*
* Modify Date:    YYYY-MM-DD                                *
* Modifier:       XXX                                       *
* Modify Note:    XXXXXXXXXXXXXX                            *
************************************************************/
int Is_EnglishChar_ByChar( const char sEnglishChar_Str );

/************************************************************
* Copyright (c) 2015 xxxxxxxxxxxxxxxxxx公司                 *
* Source File:    Is_EnglishChar_Digit_ByString             *
* Description:    字符串内容是否都是英文字母、数字（带小数点）的规则 *
* Author:         mawx                                      *
* Create Date:    2015/07/09                                *
* In:             sEnglishChar_Str  需要判断的字符串        *
* Out:            0 非字母，也非数字或小数点                *
*                 1 纯 只有小写字母                         *
*                 2 纯 只有大写字母                         *
*                 3 纯 大写字母、小写字母都有               *
*                 4 纯 数字(包括小数点)                     *
*                 5 数字(包括小数点)、英文字母混合          *
*-----------------------------------------------------------*
* Modify Date:    YYYY-MM-DD                                *
* Modifier:       XXX                                       *
* Modify Note:    XXXXXXXXXXXXXX                            *
************************************************************/
int Is_EnglishChar_Digit_ByString( const char * sSrc_Str );

#endif


#ifndef __LIB_CONF_FILE_H__
#define __LIB_CONF_FILE_H__


/************************************************************
* Copyright (c) 2015 xxxxxxxxxxxxxxxxxx公司                 *
* Source File:    AddMem_For_AddString                      *
* Description:    读取配置文件某一行，添加内存，存储字符串  *
*                 如果是第一次读取某一行则malloc，如果一次  *
*                 以上读取某一行则realloc，并将新地址输出   *
* Author:         mawx                                      *
* Create Date:    2015/07/09                                *
* In:             iCount_ReadLine 读取某一行的次数          *
*                 pPoint_AddMem  新内存的地址               *
* Out:            NULL 失败                                 *
*                 非NULL 成功,新地址                        *
*-----------------------------------------------------------*
* Modify Date:    YYYY-MM-DD                                *
* Modifier:       XXX                                       *
* Modify Note:    XXXXXXXXXXXXXX                            *
************************************************************/
char * AddMem_For_AddString( const int iCount_ReadLine, const char * sSrc_String, char ** pPoint_AddMem );

/************************************************************
* Copyright (c) 2015 xxxxxxxxxxxxxxxxxx公司                 *
* Source File:    FreeMem_For_AddString                     *
* Description:    释放AddMem_For_AddString添加的内存        *
* Author:         mawx                                      *
* Create Date:    2015/07/09                                *
* In:             pPoint_NeedFree 需要释放的内存            *
* Out:            void                                      *
*                                                           *
*-----------------------------------------------------------*
* Modify Date:    YYYY-MM-DD                                *
* Modifier:       XXX                                       *
* Modify Note:    XXXXXXXXXXXXXX                            *
************************************************************/
void FreeMem_For_AddString( char ** pPoint_NeedFree );

/************************************************************
* Copyright (c) 2015 xxxxxxxxxxxxxxxxxx公司                 *
* Source File:    Get_ValuseString_ByKey_InConfFile         *
* Description:    从配置文件中获取目标Key的内容             *
* Author:         mawx                                      *
* Create Date:    2015/07/09                                *
* In:             sFile_Name 文件名                         *
*                 sKey 目标Key的名字                        *
*                 sDst_String Key对应的value的内容          *  
* Out:            -1 失败                                   *
*                 -2 因为内存的问题失败                     *
*                 -3 没有匹配到目标域                       *
*                 0 成功                                    *
*-----------------------------------------------------------*
* Modify Date:    YYYY-MM-DD                                *
* Modifier:       XXX                                       *
* Modify Note:    XXXXXXXXXXXXXX                            *
************************************************************/
int Get_ValuseString_ByKey_InConfFile( const char * sFile_Name, const char * sKey, char * sDst_String );

/************************************************************
* Copyright (c) 2015 xxxxxxxxxxxxxxxxxx公司                 *
* Source File:    Get_ValuseString_ByFieldKey_InConfFil     *
* Description:    根据Field、Key的在配置文件中获取对应的值  *
* Author:         mawx                                      *
* Create Date:    2015/07/09                                *
* In:             sFile_Name 文件名                         *
*                 sField  目标域的名字
*                 sKey 目标Key的名字                        *
*                 sDst_String Key对应的value的内容          *  
* Out:            -1 失败                                   *
*                 -2 因为内存的问题失败                     *
*                 -3 没有匹配到目标域或Key                  *
*                 0 成功                                    *
*-----------------------------------------------------------*
* Modify Date:    YYYY-MM-DD                                *
* Modifier:       XXX                                       *
* Modify Note:    XXXXXXXXXXXXXX                            *
************************************************************/
int Get_ValuseString_ByFieldKey_InConfFile( const char *  sFile_Name, const char * sField, const char * sKey, char * sDst_String );


/* 修改配置文件中某Field/Key的值 */
/* 修改配置文件中某Key的值(以文件中第一次出现的Key为准)*/




#endif












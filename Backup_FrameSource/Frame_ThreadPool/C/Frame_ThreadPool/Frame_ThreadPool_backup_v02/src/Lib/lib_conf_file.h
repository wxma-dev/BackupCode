#ifndef __LIB_CONF_FILE_H__
#define __LIB_CONF_FILE_H__


/************************************************************
* Copyright (c) 2015 xxxxxxxxxxxxxxxxxx��˾                 *
* Source File:    AddMem_For_AddString                      *
* Description:    ��ȡ�����ļ�ĳһ�У�����ڴ棬�洢�ַ���  *
*                 ����ǵ�һ�ζ�ȡĳһ����malloc�����һ��  *
*                 ���϶�ȡĳһ����realloc�������µ�ַ���   *
* Author:         mawx                                      *
* Create Date:    2015/07/09                                *
* In:             iCount_ReadLine ��ȡĳһ�еĴ���          *
*                 pPoint_AddMem  ���ڴ�ĵ�ַ               *
* Out:            NULL ʧ��                                 *
*                 ��NULL �ɹ�,�µ�ַ                        *
*-----------------------------------------------------------*
* Modify Date:    YYYY-MM-DD                                *
* Modifier:       XXX                                       *
* Modify Note:    XXXXXXXXXXXXXX                            *
************************************************************/
char * AddMem_For_AddString( const int iCount_ReadLine, const char * sSrc_String, char ** pPoint_AddMem );

/************************************************************
* Copyright (c) 2015 xxxxxxxxxxxxxxxxxx��˾                 *
* Source File:    FreeMem_For_AddString                     *
* Description:    �ͷ�AddMem_For_AddString��ӵ��ڴ�        *
* Author:         mawx                                      *
* Create Date:    2015/07/09                                *
* In:             pPoint_NeedFree ��Ҫ�ͷŵ��ڴ�            *
* Out:            void                                      *
*                                                           *
*-----------------------------------------------------------*
* Modify Date:    YYYY-MM-DD                                *
* Modifier:       XXX                                       *
* Modify Note:    XXXXXXXXXXXXXX                            *
************************************************************/
void FreeMem_For_AddString( char ** pPoint_NeedFree );

/************************************************************
* Copyright (c) 2015 xxxxxxxxxxxxxxxxxx��˾                 *
* Source File:    Get_ValuseString_ByKey_InConfFile         *
* Description:    �������ļ��л�ȡĿ��Key������             *
* Author:         mawx                                      *
* Create Date:    2015/07/09                                *
* In:             sFile_Name �ļ���                         *
*                 sKey Ŀ��Key������                        *
*                 sDst_String Key��Ӧ��value������          *  
* Out:            -1 ʧ��                                   *
*                 -2 ��Ϊ�ڴ������ʧ��                     *
*                 -3 û��ƥ�䵽Ŀ����                       *
*                 0 �ɹ�                                    *
*-----------------------------------------------------------*
* Modify Date:    YYYY-MM-DD                                *
* Modifier:       XXX                                       *
* Modify Note:    XXXXXXXXXXXXXX                            *
************************************************************/
int Get_ValuseString_ByKey_InConfFile( const char * sFile_Name, const char * sKey, char * sDst_String );

/************************************************************
* Copyright (c) 2015 xxxxxxxxxxxxxxxxxx��˾                 *
* Source File:    Get_ValuseString_ByFieldKey_InConfFil     *
* Description:    ����Field��Key���������ļ��л�ȡ��Ӧ��ֵ  *
* Author:         mawx                                      *
* Create Date:    2015/07/09                                *
* In:             sFile_Name �ļ���                         *
*                 sField  Ŀ���������
*                 sKey Ŀ��Key������                        *
*                 sDst_String Key��Ӧ��value������          *  
* Out:            -1 ʧ��                                   *
*                 -2 ��Ϊ�ڴ������ʧ��                     *
*                 -3 û��ƥ�䵽Ŀ�����Key                  *
*                 0 �ɹ�                                    *
*-----------------------------------------------------------*
* Modify Date:    YYYY-MM-DD                                *
* Modifier:       XXX                                       *
* Modify Note:    XXXXXXXXXXXXXX                            *
************************************************************/
int Get_ValuseString_ByFieldKey_InConfFile( const char *  sFile_Name, const char * sField, const char * sKey, char * sDst_String );


/* �޸������ļ���ĳField/Key��ֵ */
/* �޸������ļ���ĳKey��ֵ(���ļ��е�һ�γ��ֵ�KeyΪ׼)*/




#endif












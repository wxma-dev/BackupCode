

#include "lib_conf_file.h"

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <fcntl.h>

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <pthread.h>

#include <sys/types.h>
#include <sys/stat.h>


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
char * AddMem_For_AddString( const int iCount_ReadLine, const char * sSrc_String, char ** pPoint_AddMem )
{
	char   * pPoint_Tmp;             /* 临时指针 */
	
	/* 变量初始化 */
	pPoint_Tmp = NULL;

	/* 第一次读取 */
	if ( 1 == iCount_ReadLine )
	{
		if ( NULL == AddStr_Malloc( sSrc_String, pPoint_AddMem ) )
		{
			return NULL;
		}
	}
	else
	{
		/* 第一次以上读取，需要在原动态内存的尾部添加字符串 */
		if ( NULL == AddStr_Realloc( *pPoint_AddMem , sSrc_String, &pPoint_Tmp ) )
		{
			return NULL;
		}
		/* 新地址 */
		*pPoint_AddMem = pPoint_Tmp;
	}
	
	return *pPoint_AddMem;
}


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
void FreeMem_For_AddString( char ** pPoint_NeedFree )
{
	AddStr_Free( pPoint_NeedFree );
}


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
int Get_ValuseString_ByKey_InConfFile( const char * sFile_Name, const char * sKey, char * sDst_String )
{
	FILE * fp;                        /* 文件指针 */
	char   sString_ReadLine[4096];    /* 读取文件的buf */
	char   *pPoint_AddMem;            /* 添加内存的指针 */
	int    iCount_ReadLine;           /* 循环读某一行的次数 */
	char   *pRet;                     /* 函数的返回指针内容 */
	char   sSting_Key[4096];          /* 临时存放Key */
	char   sSting_Value[4096 * 10];   /* Value值 */
	
	/* 变量初始化 */
	fp = NULL;
	memset( sString_ReadLine, 0x00, sizeof( sString_ReadLine ) );
	pPoint_AddMem = NULL;
	iCount_ReadLine = 0;
	pRet = NULL;
	memset( sSting_Key, 0x00, sizeof( sSting_Key ) );
	memset( sSting_Value, 0x00, sizeof( sSting_Value ) );
	
	/* 打开文件 */
	fp = fopen( sFile_Name, "r" );
	if ( NULL == fp )
	{
		return -1;
	}
	
	while ( 1 )
	{
		/* 释放内存 */
		FreeMem_For_AddString( &pPoint_AddMem );
		
		/* 读某一行次数自增 */
		iCount_ReadLine++;
		
		/* 读取 */
		memset( sString_ReadLine, 0x00, sizeof( sString_ReadLine ) );
		pRet = fgets( sString_ReadLine, sizeof( sString_ReadLine ) , fp );

		/* 将字符串移动到pPoint_AddMem这个指针指向的地址空间 */
		if ( NULL == AddMem_For_AddString( iCount_ReadLine, sString_ReadLine, &pPoint_AddMem ) )
		{
			/* 释放内存 */
			FreeMem_For_AddString( &pPoint_AddMem );
			
			return -2;
		}
		
		memset( sSting_Key, 0x00, sizeof( sSting_Key ) );
		
		/* 
			若这行没有等号，文件末尾退出 或者 跳出本次循环;
			若这行有等号，则匹配=号前面的是否等于Key,等于则取等号后面的值再成功跳出；否则报错退出 
		*/
		if ( NULL == Get_String_Before_Dh_QdKg( pPoint_AddMem, sSting_Key ) )
		{
			/* 这一行没有等号，或者获取失败，则进入该分支 */
			
			if ( NULL == pRet )
				{
				/* 释放内存 */
				FreeMem_For_AddString( &pPoint_AddMem );

				/* 文件末尾，还没有找到对应的Key，则报错失败 */
				return -1;
			}
			else if ( '\n' == sString_ReadLine[ strlen(sString_ReadLine) - 1 ] )
			{
				/* 到某一行结尾，读取次数初始化 */
				iCount_ReadLine = 0;

				continue;  /* continue继续读取下一行 */
			}
		}
		else
		{
			/* 这一行有等号，则进入该分支 */
			
			/* 一行都得到了，则进去判断获取的Key 是否与 目标Key 相同 */
			if ( '\n' == sString_ReadLine[ strlen(sString_ReadLine) - 1 ] )
			{
				/* 匹配是否等于Key */
				if ( 0 == strcmp( sSting_Key, sKey ) )
				{
					memset( sSting_Value, 0x00, sizeof( sSting_Value ) );
					if ( NULL == Get_String_Behind_Dh_QdKg( pPoint_AddMem, sSting_Value ) )
					{
						/* 释放内存 */
						FreeMem_For_AddString( &pPoint_AddMem );
						
						/* 取不到值报错 */
						return -1;
					}
					else
					{
						/* 释放内存 */
						FreeMem_For_AddString( &pPoint_AddMem );
						
						strcpy( sDst_String, sSting_Value );
						return 0;
					}
				}
				else
				{
					/* 到某一行结尾，读取次数初始化 */
					iCount_ReadLine = 0;
					
					continue; /* continue继续读取下一行 */
				}
			}
			/* 一行都没有得到则，继续读取该行 */
			{
				continue;  /* continue继续读取该行 */
			}
		}
	}
}


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
int Get_ValuseString_ByFieldKey_InConfFile( const char *  sFile_Name, const char * sField, const char * sKey, char * sDst_String )
{
	FILE * fp;                        /* 文件指针 */
	char   sString_ReadLine[4096];    /* 读取文件的buf */
	char   *pPoint_AddMem;            /* 添加内存的指针 */
	int    iCount_ReadLine;           /* 循环读某一行的次数 */
	char   *pRet;                     /* 函数的返回指针内容 */
	char   sSting_Field[4096];        /* 临时存放Key*/
	char   sSting_Key[4096];          /* 临时存放Field */
	char   sSting_Value[4096 * 10];   /* Value值 */
	
	/* 变量初始化 */
	fp = NULL;
	memset( sString_ReadLine, 0x00, sizeof( sString_ReadLine ) );
	pPoint_AddMem = NULL;
	iCount_ReadLine = 0;
	pRet = NULL;
	memset( sSting_Field, 0x00, sizeof( sSting_Field ) );
	memset( sSting_Value, 0x00, sizeof( sSting_Value ) );
	
	/* 打开文件 */
	fp = fopen( sFile_Name, "r" );
	if ( NULL == fp )
	{
		return -1;
	}
	
	while ( 1 )
	{
		/* 释放内存 */
		FreeMem_For_AddString( &pPoint_AddMem );
		
		/* 读某一行次数自增 */
		iCount_ReadLine++;
		
		/* 读取 */
		memset( sString_ReadLine, 0x00, sizeof( sString_ReadLine ) );
		pRet = fgets( sString_ReadLine, sizeof( sString_ReadLine ) , fp );

		/* 将字符串移动到pPoint_AddMem这个指针指向的地址空间 */
		if ( NULL == AddMem_For_AddString( iCount_ReadLine, sString_ReadLine, &pPoint_AddMem ) )
		{
			/* 释放内存 */
			FreeMem_For_AddString( &pPoint_AddMem );

			return -2;
		}
		
		memset( sSting_Field, 0x00, sizeof( sSting_Field ) );

		/* 
			若这行没有中扩号，文件末尾退出 或者 跳出本次循环;
			若这行有中扩号，则匹配中扩号前面的是否等于Field,等于则取中扩号后面的值再成功跳出；否则报错退出 
		*/
		if ( NULL == Get_String_Between_Zkh( pPoint_AddMem, sSting_Field ) )
		{
			/* 这一行没有等号，或者获取失败，则进入该分支 */

			if ( NULL == pRet )
			{
				/* 释放内存 */
				FreeMem_For_AddString( &pPoint_AddMem );

				/* 文件末尾，还没有找到对应的Field，则报错失败 */
				return -1;
			}
			else if ( '\n' == sString_ReadLine[ strlen(sString_ReadLine) - 1 ] )
			{
				/* 到某一行结尾，读取次数初始化 */
				iCount_ReadLine = 0;

				continue;  /* continue继续读取下一行 */
			}
		}
		else
		{
			/* 这一行有中扩号，则进入该分支 */
			
			/* 一行都得到了，则进去判断获取的Field 是否与 目标Field 相同 */
			if ( '\n' == sString_ReadLine[ strlen(sString_ReadLine) - 1 ] )
			{
				/* 匹配是否等于Filed */
				if ( 0 == strcmp( sSting_Field, sField ) )
				{
					iCount_ReadLine = 0;

					/* 进入找到Key的阶段 */
					while( 1 )
					{
						/* 释放内存 */
						FreeMem_For_AddString( &pPoint_AddMem );
						
						/* 读某一行次数自增 */
						iCount_ReadLine++;
						
						/* 读取 */
						memset( sString_ReadLine, 0x00, sizeof( sString_ReadLine ) );
						pRet = fgets( sString_ReadLine, sizeof( sString_ReadLine ) , fp );

						/* 获取中中括号，则认为到了下一个域了，依然没有找到对应Key */
						memset( sSting_Field, 0x00, sizeof( sSting_Field ) );
						if ( NULL != Get_String_Between_Zkh( sString_ReadLine, sSting_Field ) )
						{
							return -3;
						}

						/* 将字符串移动到pPoint_AddMem这个指针指向的地址空间 */
						if ( NULL == AddMem_For_AddString( iCount_ReadLine, sString_ReadLine, &pPoint_AddMem ) )
						{
							/* 释放内存 */
							FreeMem_For_AddString( &pPoint_AddMem );
							
							return -2;
						}
						
						memset( sSting_Key, 0x00, sizeof( sSting_Key ) );
						
						/* 
							若这行没有等号，文件末尾退出 或者 跳出本次循环;
							若这行有等号，则匹配=号前面的是否等于Key,等于则取等号后面的值再成功跳出；否则报错退出 
						*/
						if ( NULL == Get_String_Before_Dh_QdKg( pPoint_AddMem, sSting_Key ) )
						{
							/* 这一行没有等号，或者获取失败，则进入该分支 */
							
							if ( NULL == pRet )
							{
								/* 释放内存 */
								FreeMem_For_AddString( &pPoint_AddMem );
								
								/* 文件末尾，还没有找到对应的Key，则报错失败 */
								return -1;
							}
							else if ( '\n' == sString_ReadLine[ strlen(sString_ReadLine) - 1 ] )
							{
								/* 到某一行结尾，读取次数初始化 */
								iCount_ReadLine = 0;

								continue;  /* continue继续读取下一行 */
							}
						}
						else
						{
							/* 这一行有等号，则进入该分支 */
							
							/* 一行都得到了，则进去判断获取的Key 是否与 目标Key 相同 */
							if ( '\n' == sString_ReadLine[ strlen(sString_ReadLine) - 1 ] )
							{
								/* 匹配是否等于Key */
								if ( 0 == strcmp( sSting_Key, sKey ) )
								{
									memset( sSting_Value, 0x00, sizeof( sSting_Value ) );
									if ( NULL == Get_String_Behind_Dh_QdKgHh( pPoint_AddMem, sSting_Value ) )
									{
										/* 释放内存 */
										FreeMem_For_AddString( &pPoint_AddMem );

										/* 取不到值报错 */
										return -1;
									}
									else
									{
										/* 释放内存 */
										FreeMem_For_AddString( &pPoint_AddMem );
										
										strcpy( sDst_String, sSting_Value );
										return 0;
									}
								}
								else
								{
									/* 到某一行结尾，读取次数初始化 */
									iCount_ReadLine = 0;
									
									continue; /* continue继续读取下一行 */
								}
							}
							/* 一行都没有得到则，继续读取该行 */
							{
								continue;  /* continue继续读取该行 */
							}
						}
						
					}
				}
				else
				{
					/* 到某一行结尾，读取次数初始化 */
					iCount_ReadLine = 0;
					
					continue; /* continue继续读取下一行 */
				}
			}
			/* 一行都没有得到则，继续读取该行 */
			{
				continue;  /* continue继续读取该行 */
			}
		}
	}
}



/* 修改配置文件中某Field/Key的值 */
/* 修改配置文件中某Key的值(以文件中第一次出现的Key为准)*/

















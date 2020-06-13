

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
char * AddMem_For_AddString( const int iCount_ReadLine, const char * sSrc_String, char ** pPoint_AddMem )
{
	char   * pPoint_Tmp;             /* ��ʱָ�� */
	
	/* ������ʼ�� */
	pPoint_Tmp = NULL;

	/* ��һ�ζ�ȡ */
	if ( 1 == iCount_ReadLine )
	{
		if ( NULL == AddStr_Malloc( sSrc_String, pPoint_AddMem ) )
		{
			return NULL;
		}
	}
	else
	{
		/* ��һ�����϶�ȡ����Ҫ��ԭ��̬�ڴ��β������ַ��� */
		if ( NULL == AddStr_Realloc( *pPoint_AddMem , sSrc_String, &pPoint_Tmp ) )
		{
			return NULL;
		}
		/* �µ�ַ */
		*pPoint_AddMem = pPoint_Tmp;
	}
	
	return *pPoint_AddMem;
}


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
void FreeMem_For_AddString( char ** pPoint_NeedFree )
{
	AddStr_Free( pPoint_NeedFree );
}


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
int Get_ValuseString_ByKey_InConfFile( const char * sFile_Name, const char * sKey, char * sDst_String )
{
	FILE * fp;                        /* �ļ�ָ�� */
	char   sString_ReadLine[4096];    /* ��ȡ�ļ���buf */
	char   *pPoint_AddMem;            /* ����ڴ��ָ�� */
	int    iCount_ReadLine;           /* ѭ����ĳһ�еĴ��� */
	char   *pRet;                     /* �����ķ���ָ������ */
	char   sSting_Key[4096];          /* ��ʱ���Key */
	char   sSting_Value[4096 * 10];   /* Valueֵ */
	
	/* ������ʼ�� */
	fp = NULL;
	memset( sString_ReadLine, 0x00, sizeof( sString_ReadLine ) );
	pPoint_AddMem = NULL;
	iCount_ReadLine = 0;
	pRet = NULL;
	memset( sSting_Key, 0x00, sizeof( sSting_Key ) );
	memset( sSting_Value, 0x00, sizeof( sSting_Value ) );
	
	/* ���ļ� */
	fp = fopen( sFile_Name, "r" );
	if ( NULL == fp )
	{
		return -1;
	}
	
	while ( 1 )
	{
		/* �ͷ��ڴ� */
		FreeMem_For_AddString( &pPoint_AddMem );
		
		/* ��ĳһ�д������� */
		iCount_ReadLine++;
		
		/* ��ȡ */
		memset( sString_ReadLine, 0x00, sizeof( sString_ReadLine ) );
		pRet = fgets( sString_ReadLine, sizeof( sString_ReadLine ) , fp );

		/* ���ַ����ƶ���pPoint_AddMem���ָ��ָ��ĵ�ַ�ռ� */
		if ( NULL == AddMem_For_AddString( iCount_ReadLine, sString_ReadLine, &pPoint_AddMem ) )
		{
			/* �ͷ��ڴ� */
			FreeMem_For_AddString( &pPoint_AddMem );
			
			return -2;
		}
		
		memset( sSting_Key, 0x00, sizeof( sSting_Key ) );
		
		/* 
			������û�еȺţ��ļ�ĩβ�˳� ���� ��������ѭ��;
			�������еȺţ���ƥ��=��ǰ����Ƿ����Key,������ȡ�Ⱥź����ֵ�ٳɹ����������򱨴��˳� 
		*/
		if ( NULL == Get_String_Before_Dh_QdKg( pPoint_AddMem, sSting_Key ) )
		{
			/* ��һ��û�еȺţ����߻�ȡʧ�ܣ������÷�֧ */
			
			if ( NULL == pRet )
				{
				/* �ͷ��ڴ� */
				FreeMem_For_AddString( &pPoint_AddMem );

				/* �ļ�ĩβ����û���ҵ���Ӧ��Key���򱨴�ʧ�� */
				return -1;
			}
			else if ( '\n' == sString_ReadLine[ strlen(sString_ReadLine) - 1 ] )
			{
				/* ��ĳһ�н�β����ȡ������ʼ�� */
				iCount_ReadLine = 0;

				continue;  /* continue������ȡ��һ�� */
			}
		}
		else
		{
			/* ��һ���еȺţ������÷�֧ */
			
			/* һ�ж��õ��ˣ����ȥ�жϻ�ȡ��Key �Ƿ��� Ŀ��Key ��ͬ */
			if ( '\n' == sString_ReadLine[ strlen(sString_ReadLine) - 1 ] )
			{
				/* ƥ���Ƿ����Key */
				if ( 0 == strcmp( sSting_Key, sKey ) )
				{
					memset( sSting_Value, 0x00, sizeof( sSting_Value ) );
					if ( NULL == Get_String_Behind_Dh_QdKg( pPoint_AddMem, sSting_Value ) )
					{
						/* �ͷ��ڴ� */
						FreeMem_For_AddString( &pPoint_AddMem );
						
						/* ȡ����ֵ���� */
						return -1;
					}
					else
					{
						/* �ͷ��ڴ� */
						FreeMem_For_AddString( &pPoint_AddMem );
						
						strcpy( sDst_String, sSting_Value );
						return 0;
					}
				}
				else
				{
					/* ��ĳһ�н�β����ȡ������ʼ�� */
					iCount_ReadLine = 0;
					
					continue; /* continue������ȡ��һ�� */
				}
			}
			/* һ�ж�û�еõ��򣬼�����ȡ���� */
			{
				continue;  /* continue������ȡ���� */
			}
		}
	}
}


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
int Get_ValuseString_ByFieldKey_InConfFile( const char *  sFile_Name, const char * sField, const char * sKey, char * sDst_String )
{
	FILE * fp;                        /* �ļ�ָ�� */
	char   sString_ReadLine[4096];    /* ��ȡ�ļ���buf */
	char   *pPoint_AddMem;            /* ����ڴ��ָ�� */
	int    iCount_ReadLine;           /* ѭ����ĳһ�еĴ��� */
	char   *pRet;                     /* �����ķ���ָ������ */
	char   sSting_Field[4096];        /* ��ʱ���Key*/
	char   sSting_Key[4096];          /* ��ʱ���Field */
	char   sSting_Value[4096 * 10];   /* Valueֵ */
	
	/* ������ʼ�� */
	fp = NULL;
	memset( sString_ReadLine, 0x00, sizeof( sString_ReadLine ) );
	pPoint_AddMem = NULL;
	iCount_ReadLine = 0;
	pRet = NULL;
	memset( sSting_Field, 0x00, sizeof( sSting_Field ) );
	memset( sSting_Value, 0x00, sizeof( sSting_Value ) );
	
	/* ���ļ� */
	fp = fopen( sFile_Name, "r" );
	if ( NULL == fp )
	{
		return -1;
	}
	
	while ( 1 )
	{
		/* �ͷ��ڴ� */
		FreeMem_For_AddString( &pPoint_AddMem );
		
		/* ��ĳһ�д������� */
		iCount_ReadLine++;
		
		/* ��ȡ */
		memset( sString_ReadLine, 0x00, sizeof( sString_ReadLine ) );
		pRet = fgets( sString_ReadLine, sizeof( sString_ReadLine ) , fp );

		/* ���ַ����ƶ���pPoint_AddMem���ָ��ָ��ĵ�ַ�ռ� */
		if ( NULL == AddMem_For_AddString( iCount_ReadLine, sString_ReadLine, &pPoint_AddMem ) )
		{
			/* �ͷ��ڴ� */
			FreeMem_For_AddString( &pPoint_AddMem );

			return -2;
		}
		
		memset( sSting_Field, 0x00, sizeof( sSting_Field ) );

		/* 
			������û�������ţ��ļ�ĩβ�˳� ���� ��������ѭ��;
			�������������ţ���ƥ��������ǰ����Ƿ����Field,������ȡ�����ź����ֵ�ٳɹ����������򱨴��˳� 
		*/
		if ( NULL == Get_String_Between_Zkh( pPoint_AddMem, sSting_Field ) )
		{
			/* ��һ��û�еȺţ����߻�ȡʧ�ܣ������÷�֧ */

			if ( NULL == pRet )
			{
				/* �ͷ��ڴ� */
				FreeMem_For_AddString( &pPoint_AddMem );

				/* �ļ�ĩβ����û���ҵ���Ӧ��Field���򱨴�ʧ�� */
				return -1;
			}
			else if ( '\n' == sString_ReadLine[ strlen(sString_ReadLine) - 1 ] )
			{
				/* ��ĳһ�н�β����ȡ������ʼ�� */
				iCount_ReadLine = 0;

				continue;  /* continue������ȡ��һ�� */
			}
		}
		else
		{
			/* ��һ���������ţ������÷�֧ */
			
			/* һ�ж��õ��ˣ����ȥ�жϻ�ȡ��Field �Ƿ��� Ŀ��Field ��ͬ */
			if ( '\n' == sString_ReadLine[ strlen(sString_ReadLine) - 1 ] )
			{
				/* ƥ���Ƿ����Filed */
				if ( 0 == strcmp( sSting_Field, sField ) )
				{
					iCount_ReadLine = 0;

					/* �����ҵ�Key�Ľ׶� */
					while( 1 )
					{
						/* �ͷ��ڴ� */
						FreeMem_For_AddString( &pPoint_AddMem );
						
						/* ��ĳһ�д������� */
						iCount_ReadLine++;
						
						/* ��ȡ */
						memset( sString_ReadLine, 0x00, sizeof( sString_ReadLine ) );
						pRet = fgets( sString_ReadLine, sizeof( sString_ReadLine ) , fp );

						/* ��ȡ�������ţ�����Ϊ������һ�����ˣ���Ȼû���ҵ���ӦKey */
						memset( sSting_Field, 0x00, sizeof( sSting_Field ) );
						if ( NULL != Get_String_Between_Zkh( sString_ReadLine, sSting_Field ) )
						{
							return -3;
						}

						/* ���ַ����ƶ���pPoint_AddMem���ָ��ָ��ĵ�ַ�ռ� */
						if ( NULL == AddMem_For_AddString( iCount_ReadLine, sString_ReadLine, &pPoint_AddMem ) )
						{
							/* �ͷ��ڴ� */
							FreeMem_For_AddString( &pPoint_AddMem );
							
							return -2;
						}
						
						memset( sSting_Key, 0x00, sizeof( sSting_Key ) );
						
						/* 
							������û�еȺţ��ļ�ĩβ�˳� ���� ��������ѭ��;
							�������еȺţ���ƥ��=��ǰ����Ƿ����Key,������ȡ�Ⱥź����ֵ�ٳɹ����������򱨴��˳� 
						*/
						if ( NULL == Get_String_Before_Dh_QdKg( pPoint_AddMem, sSting_Key ) )
						{
							/* ��һ��û�еȺţ����߻�ȡʧ�ܣ������÷�֧ */
							
							if ( NULL == pRet )
							{
								/* �ͷ��ڴ� */
								FreeMem_For_AddString( &pPoint_AddMem );
								
								/* �ļ�ĩβ����û���ҵ���Ӧ��Key���򱨴�ʧ�� */
								return -1;
							}
							else if ( '\n' == sString_ReadLine[ strlen(sString_ReadLine) - 1 ] )
							{
								/* ��ĳһ�н�β����ȡ������ʼ�� */
								iCount_ReadLine = 0;

								continue;  /* continue������ȡ��һ�� */
							}
						}
						else
						{
							/* ��һ���еȺţ������÷�֧ */
							
							/* һ�ж��õ��ˣ����ȥ�жϻ�ȡ��Key �Ƿ��� Ŀ��Key ��ͬ */
							if ( '\n' == sString_ReadLine[ strlen(sString_ReadLine) - 1 ] )
							{
								/* ƥ���Ƿ����Key */
								if ( 0 == strcmp( sSting_Key, sKey ) )
								{
									memset( sSting_Value, 0x00, sizeof( sSting_Value ) );
									if ( NULL == Get_String_Behind_Dh_QdKgHh( pPoint_AddMem, sSting_Value ) )
									{
										/* �ͷ��ڴ� */
										FreeMem_For_AddString( &pPoint_AddMem );

										/* ȡ����ֵ���� */
										return -1;
									}
									else
									{
										/* �ͷ��ڴ� */
										FreeMem_For_AddString( &pPoint_AddMem );
										
										strcpy( sDst_String, sSting_Value );
										return 0;
									}
								}
								else
								{
									/* ��ĳһ�н�β����ȡ������ʼ�� */
									iCount_ReadLine = 0;
									
									continue; /* continue������ȡ��һ�� */
								}
							}
							/* һ�ж�û�еõ��򣬼�����ȡ���� */
							{
								continue;  /* continue������ȡ���� */
							}
						}
						
					}
				}
				else
				{
					/* ��ĳһ�н�β����ȡ������ʼ�� */
					iCount_ReadLine = 0;
					
					continue; /* continue������ȡ��һ�� */
				}
			}
			/* һ�ж�û�еõ��򣬼�����ȡ���� */
			{
				continue;  /* continue������ȡ���� */
			}
		}
	}
}



/* �޸������ļ���ĳField/Key��ֵ */
/* �޸������ļ���ĳKey��ֵ(���ļ��е�һ�γ��ֵ�KeyΪ׼)*/

















#ifndef __LIB_FILE_H__
#define __LIB_FILE_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
* Copyright (c) 2015 ��������ͨ�Ƽ����޹�˾                 *
* Source File:    Get_FileSize                              *
* Description:    ��ȡ�ļ���С(�ֽ�)                        *
* Author:         mawx                                      *
* Create Date:    2015/07/09                                *
* In:             filename �ļ���(����·��)                 *
*                 valuename_str �����ֶ�����                *
                  value_str �����ֶ�����                    *
* Out:            0 ������                                  *
*                 1 ����                                    *
*-----------------------------------------------------------*
* Modify Date:    YYYY-MM-DD                                *
* Modifier:       XXX                                       *
* Modify Note:    XXXXXXXXXXXXXX                            *
************************************************************/
off_t Get_FileSize( char * filename );

/************************************************************
* Copyright (c) 2015 xxxxxxxxxxxxxxxxxx��˾                 *
* Source File:    GetFileRowCount                           *
* Description:    ��ȡ�ļ�����                              *
* Author:         mawx                                      *
* Create Date:    2015/07/09                                *
* In:             sFilename �ļ�����·��                    *
*                 pNum �ļ���������ָ��                     *
* Out:            -1 ʧ��                                   *
*                 ���� �ļ�������                           *  
*-----------------------------------------------------------*
* Modify Date:    YYYY-MM-DD                                *
* Modifier:       XXX                                       *
* Modify Note:    XXXXXXXXXXXXXX                            *
* **********************************************************/
int GetFileRowCount( char *sFilename, int * pNum );


#endif




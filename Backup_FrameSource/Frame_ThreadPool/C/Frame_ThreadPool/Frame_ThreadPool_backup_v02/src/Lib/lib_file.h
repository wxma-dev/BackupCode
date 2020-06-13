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
* Copyright (c) 2015 北京联银通科技有限公司                 *
* Source File:    Get_FileSize                              *
* Description:    获取文件大小(字节)                        *
* Author:         mawx                                      *
* Create Date:    2015/07/09                                *
* In:             filename 文件名(绝对路径)                 *
*                 valuename_str 配置字段名称                *
                  value_str 配置字段内容                    *
* Out:            0 非数字                                  *
*                 1 数字                                    *
*-----------------------------------------------------------*
* Modify Date:    YYYY-MM-DD                                *
* Modifier:       XXX                                       *
* Modify Note:    XXXXXXXXXXXXXX                            *
************************************************************/
off_t Get_FileSize( char * filename );

/************************************************************
* Copyright (c) 2015 xxxxxxxxxxxxxxxxxx公司                 *
* Source File:    GetFileRowCount                           *
* Description:    获取文件行数                              *
* Author:         mawx                                      *
* Create Date:    2015/07/09                                *
* In:             sFilename 文件绝对路径                    *
*                 pNum 文件行数变量指针                     *
* Out:            -1 失败                                   *
*                 其他 文件的行数                           *  
*-----------------------------------------------------------*
* Modify Date:    YYYY-MM-DD                                *
* Modifier:       XXX                                       *
* Modify Note:    XXXXXXXXXXXXXX                            *
* **********************************************************/
int GetFileRowCount( char *sFilename, int * pNum );


#endif




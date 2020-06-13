/*
应用层，框架层，都使用文件
*/
#ifndef __COMMON_FRAME_H__
#define __COMMON_FRAME_H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/*
检查是否符合标准
*/
int Check_Task_Mem( void * const pPoint );

/*
获取到标志位的指针
*/
void * Get_Mark_Addr( void * const pPoint_Addr );


/*
计算”存放地址值的内存块“的首地址
*/
void * Get_Start_Addr( void * const pPoint_Addr );


/*
获取”存放地址值的内存块“中的值
入参：pPoint_Start_Addr   开始的地址
出参：pPoint_Task_Addr    ”存放地址值的内存块“中的值二级指针
*/
void Get_Task_Addr( void * const pPoint_Start_Addr, void ** pPoint_Task_Addr );


/*
释放”存放地址值的内存块“指向的内存区域
*/
void Free_Task_Addr( void * pPoint_Task_Addr );



#endif


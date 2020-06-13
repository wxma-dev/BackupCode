/*************************************************************
*    FileName : config.h                                     *
*    FileFunc : ����ͷ�ļ�                                   *
*    Version  : V0.1                                         *
*    Author   : Sunrier                                      *
*    Date     : 2012-05-09                                   *
*    Descp    : Linux�»�ȡ�����ļ���Ϣ                      *
*************************************************************/  
#ifndef   _CONFIG_H  
#define   _CONFIG_H  
  
#ifdef __cplusplus  
extern "C" {  
#endif  
  
#define  SUCCESS           0x00 /*�ɹ�*/  
#define  FAILURE           0x01 /*ʧ��*/  
  
#define  FILENAME_NOTEXIST      0x02 /*�����ļ���������*/  
#define  SECTIONNAME_NOTEXIST    0x03 /*����������*/  
#define  KEYNAME_NOTEXIST      0x04 /*����������*/  
#define  STRING_LENNOTEQUAL     0x05 /*�����ַ������Ȳ�ͬ*/  
#define  STRING_NOTEQUAL       0x06 /*�����ַ������ݲ���ͬ*/  
#define  STRING_EQUAL        0x00 /*�����ַ���������ͬ*/  
  
  
int CompareString(char *pInStr1,char *pInStr2);  
int GetKeyValue(FILE *fpConfig,char *pInKeyName,char *pOutKeyValue);  
int GetConfigIntValue(char *pInFileName,char *pInSectionName,char *pInKeyName,int *pOutKeyValue);  
int GetConfigStringValue(char *pInFileName,char *pInSectionName,char *pInKeyName,char *pOutKeyValue);  
  
#ifdef __cplusplus  
}  
#endif  
  
#endif  
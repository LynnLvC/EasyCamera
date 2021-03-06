/*
	Copyright (c) 2013-2015 EasyDarwin.ORG.  All rights reserved.
	Github: https://github.com/EasyDarwin
	WEChat: EasyDarwin
	Website: http://www.easydarwin.org
*/
#ifndef _Easy_CMS_API_H
#define _Easy_CMS_API_H

#include "EasyTypes.h"

#ifdef _WIN32
#define EasyCMS_API  __declspec(dllexport)
#define Easy_APICALL  __stdcall
#else
#define EasyCMS_API
#define Easy_APICALL 
#endif

#define Easy_CMS_Handle void*

/* CMS事件类型定义 */
typedef enum __EASY_CMS_EVENT_T
{
    Easy_CMS_Event_Login   =   1,		/* 连接成功 */
    Easy_CMS_Event_Offline,             /* 下线 */

}EASY_CMS_EVENT_T;

/* 推送回调函数定义 _userptr表示用户自定义数据 */
typedef int (*EasyCMS_Callback)(EASY_CMS_EVENT_T _event, const char* _pEventData, void* _pUserData);

#ifdef __cplusplus
extern "C"
{
#endif

	/* 创建CMS Session  返回为句柄值 */
	EasyCMS_API Easy_CMS_Handle Easy_APICALL EasyCMS_Session_Create();
	
	/* 释放CMS Session句柄 */
	EasyCMS_API Easy_U32 Easy_APICALL EasyCMS_Session_Release(Easy_CMS_Handle handle);

    /* 设置流传输事件回调 userptr传输自定义对象指针*/
    EasyCMS_API Easy_U32 Easy_APICALL EasyCMS_SetEventCallback(Easy_CMS_Handle handle,  EasyCMS_Callback callback, void *userData);

	/* 登录到CMS，携带具体的用户名密码 */
	EasyCMS_API Easy_U32 Easy_APICALL EasyCMS_Login(Easy_CMS_Handle handle, char* serverAddr, Easy_U16 port, char *username, char *password);

	/* 上传快照 */
	EasyCMS_API Easy_U32 Easy_APICALL EasyCMS_UpdateSnap(Easy_CMS_Handle handle, const char* snapData, unsigned int snapLen);

#ifdef __cplusplus
}
#endif


#endif
// ================================================================
// Copyright (c) 2019-2023 by VX-Lab. All rights reserved.
// 
// This file is property of VX-Lab. Any unauthorized copy,
// use or distribution is an offensive act against international
// law and may be prosecuted under federal law. Its content is
// company confidential asset.
// ================================================================
#ifndef _IVIDEOCAP_H_ //auto generated by vim script
#define _IVIDEOCAP_H_

#include "vxlMacros.h"
#include "vxlComTypes.h"
#include "vxlErrorCode.h"
#include "vxlSysInc.h"
#include "IVideoCapAux.h"

class IVideoCap
{
public:
    //! register the RuntimeExceptionCallback
    /*!
        \func    : function pointer to the runtime exception callback of the caller of this module
        \usrData : pointer to caller of this module
    */
    //virtual void RegisterRuntimeExceptionCallback(IN RuntimeStatusFunc func, IN void *usrData) = 0;

    //! launch log operation
    /*!
        after it called,program will output log information, such as,error information,etc.
    */
    //virtual void EnableLog(IN VXL_LOG_LEVEL logLevel = VXL_LOG_LEVEL_DEFAULT, IN const char* const logDir = NULL) = 0;

    //! cancel log operation
    /*!
        after it called,program will not output log information, such as,error information,etc.
    */
    virtual void DisableLog() = 0;

    //! init data, get rotated angle based on different coordinate system transform mode : world->camera; camera->world
    /*!
    */
    virtual VXL_EXECUTION_STATUS Init(
        IN const VideoCapCfg  &cfg,
        IN const VideoCapPara &para) = 0;

    //! release resources
    virtual VXL_EXECUTION_STATUS Release() = 0;


    virtual VXL_EXECUTION_STATUS Process(IN OUT char *imgBuff, IN const VxlSize &vxlSize) = 0;

    virtual VXL_EXECUTION_STATUS SetPara(
        IN const VideoCapPara &para) = 0;
};

#ifdef _WIN32
#ifdef VIDEOCAP_EXPORTS
#define INTERFACE_CLASS extern "C" __declspec(dllexport)
#else
#define INTERFACE_CLASS extern "C" __declspec(dllimport)
#endif
#elif defined __linux__
#define INTERFACE_CLASS __attribute__ ((visibility("default")))
#endif

//! creat a object
INTERFACE_CLASS IVideoCap* CreateVideoCap();

//!destroy a object, free the memory
INTERFACE_CLASS void DeleteVideoCap(IN OUT IVideoCap** const pIVideoCap);

#endif //_IVIDEOCAP_H_

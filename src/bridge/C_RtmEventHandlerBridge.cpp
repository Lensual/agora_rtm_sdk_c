// Agora C封装
#include "bridge/C_RtmEventHandlerBridge.h"

// IRtmEventHandler CPP实现
#include "bridge/RtmEventHandlerBridge.hh"

C_RtmEventHandlerBridge *C_RtmEventHandlerBridge_New(C_RtmEventHandlerBridge_Callbacks cbs, void *userData)
{
    auto this_ = new RtmEventHandlerBridge(cbs, userData);
    return (C_RtmEventHandlerBridge *)this_;
}

void C_RtmEventHandlerBridge_Delete(C_RtmEventHandlerBridge *this_)
{
    delete (RtmEventHandlerBridge *)this_;
    this_ = nullptr;
}
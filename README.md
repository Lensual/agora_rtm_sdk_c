# agora_rtm_sdk_c

Agora RTM SDK for C

base on `Agora_RTM_C++_SDK_for_Linux_v2.1.11`

该项目通过重写头文件中的定义和代理调用的方式提供了C调用声网SDK的可能性。

`C_xxxx.h`用于被C项目引入，`C_xxxx.cpp`是对应头文件的实现。

`bridge`目录中的非`C_`开头的`.hh`和`.cpp`文件是一些使用SDK所需的对象包装实现，例如`RtmEventHandle`。bridge 提供了C++类的实现，并向C开放了接口。

## build

```sh
cmake .
make
```

链接`libagora_rtm_sdk_c.a`、`libc++` 以及声网SDK至你的项目

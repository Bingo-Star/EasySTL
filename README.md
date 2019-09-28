# EasyDSL 简介

EasyDSL 即轻量级数据结构库，基于 C++ 实现。在本库中将实现顺序表、数组、链表等数据结构，并提供自定义的异常类型与智能指针，可在实际工程项目中直接使用。

EasyDSL 源于网课 [狄泰唐佐林老师C++数据结构项目实战视频教程（手撕数据结构）](https://item.taobao.com/item.htm?spm=a1z10.5-c-s.w4002-16326486341.33.20ff72dcNZdedb&id=559287639478)，为课程的示例程序，本人在其基础上进行了一定的优化，是非常好的学习 C++ 与数据结构的实战项目。

# 工程介绍

EasyDSL 的目录结构如下：

```shell
.
├── src
    └── main.cpp
├── include
├── library
├── output
├── object
├── Makefile
└── README.md
```

* src：源文件目录，.c 文件放在该目录中
* include：头文件目录，.h 文件放在该目录中
* library：库文件目录，所使用的库文件放在该目录中
* object：目标文件目录，生成的 .o 在该目录中
* output：可执行文件目录，最终生成的 app 在该目录中
* Makefile：工程编译管理

# 编译方法

在 EasyDSL/ 下执行 make 进行编译，可生成可执行文件 EasyDSL/output/app，默认编译工具为 g++，相关配置可在 Makefile 中修改。

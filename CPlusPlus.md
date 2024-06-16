# 如何编译C++程序

### CMake编译流程

1. 编写CMakeLists.txt
2. 执行cmake PATH生成的Makefile
3. 执行make编译



**编写CMakeLists.txt**

```C++
add_executable(main main.cpp) # add_executable: 使用指定的源文件来生成目标可执行文件
```

**生成Makefile文件**

```C++
cmake .
cmake -G "MinGW Makefiles" .. // 指定使用MinGW
```

**编译项目**

```C++
make
mingw32-make // z指定使用MinGW
```



**修复警告：**在MakeLists.txt重添加

```cmake
cmake_minimum_required(VERSION 3.14) # 指定最低的版本
project(hello) # 工程的名称
```



**语言版本：**在MakeLists.txt中添加

```cmake
set(CMAKE_CXX_STANDARD 11) # 指定C++11标准
```



**编译选项：**

```cmake
add_compile_options(-g -Wunused) # -g 表示可调试， -Wunused告警没有使用的变量
target_compile_options(main PUBLIC-WALL-Werror) # 给指定文件增加编译选项
```



**多文件编译**

在`add_excuatable`中将多个cpp文件添加进去



**自动添加cpp文件：**自动把src目录下的cpp文件添加到项目里

```cma
file(GLOB_RECURSE SOURCES "scr/*.cpp")
add_executable(main ${SOURCES} main.cpp)
```



**设置根路径**

```cmake
include_directories(./ ./include)
```



**多目标编译：** 如果项目会生成多个可执行函数（main 函数）,写多个`add_executable`

```
add_executable(main ${SOURCES} main.cpp)
add_executable(test ${SOURCES} test.cpp)
```



#### 静态库的编译和链接

例如编译mul.cpp

```
set(MUL_SOURCES ./mul/mul.cpp)
add_library(mul STATIC ${MUL_SOURCES})
```



**链接库文件:** 方法1，写在add_executable前面，会将目标链接到后面的可执行程序里

```cmake
link_directories(./)
link_libraries(mul)
```

**链接库文件:** 方法2，写在add_executable后面，指定链接到某一个目标里

```cmake
target_link_directories(main PUBLIC ./)
target_link_libraries(main mul)
```



### 动态库编译&链接

**编译：**产生一个so文件

```cmake
set(MUL_SOURCES ./mul/mul.cpp)
add_library(mul SHARED ${MUL_SOURCES})
```

链接方式与静态库链接相同



### 动态库与静态库的区别

**静态链接：**将自己的代码和标准库代码通过链接打包到可执行程序的方式。当运行程序时会将可执行文件的代码放到内存的代码区中。但是如果多个程序都采用了标准库，采用静态链接就会导致内存、磁盘空间占用。

**动态链接：**可执行程序中不再包含标准库的代码，而是一份参考目录（依赖哪个库，这个库保存在哪里）。动态链接把链接这个过程推迟到了运行过程。标准库的运行存放在一片共享内存中。

静态链接在大规模部署的服务器上非常方便，因为它不依赖其他库。但是修复bug不方便，需要重新编译再部署；

动态链接的bug修复方便，只需要重新编译动态库，不需要重新发布程序版本，但是需要有依赖的库。







# 数据结构与算法

### 实现双向链表



### 哈希表



**查找的复杂度：**

**插入的复杂度：**



### 快速排序

**善于处理怎么样的数据：**

**不善于处理怎么样的数据：**





# C++知识

### c++的内存管理



### 如何排查内存泄漏



### 构造函数传递指针会怎么样



### 析构函数定义为非虚函数会怎么样





# Linux

### window和linux开发的区别

**处理平台差异：**


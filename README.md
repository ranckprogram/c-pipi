# c 语言学习笔记

### 流程步骤

- [x] 环境安装
- [x] 常用指令
- [ ] 包管理器
- [x] 自己定义头文件
- [ ] 指针，函数，结构体
  - 一级指针
  - 二级指针
  - N级指针
- [ ] 内存管理
- [ ] 可变参数函数
- [ ] 命令行参数
- [x] 自定义可移植的函数库
- [ ] 使用一下标准库
- [ ] 动态库的封装和设计
- [ ] 实现一个数据结构
- [ ] 写个应用

### 环境安装

1. 下载 [MinGW](https://sourceforge.net/projects/mingw/files/)
2. 安装到 **C:\MinGW**
3. 配置环境变量

- 计算机”--->“属性”--->“高级系统设置”--->“环境变量”--->“系统变量(S)”

| 属性名  | 值               |     |
| ------- | ---------------- | --- |
| INCLUDE | C:\MinGW\include |     |
| LIB     | C:\MinGW\lib     |     |
| Path    | C:\MinGW\bin     |     |



### c 包管理器

https://conan.io/

### C 可以做什么

- 嵌入式
- 硬件编程
-

### 多文件编程

多文件的时候除了将所有代码写在 h 文件里面有没有办法将函数实现写在 c 文件里面

```
gcc -o tool.o tool.c
```

makefile
编译成目标文件，在转换成二进制

[跟我一起写makefile](https://blog.csdn.net/haoel/article/details/2886)

### 指针

- 指针定义
- 指针释放

```

```

### 结构体

定义

```c
struct Person {
  name char[30];
  age int;
}


int getPersonAge(struct People *p)
{
  return p->age;
}

char * getPersonName(struct People *p)
{
  return p->name;
}



void main() {
  struct Person p;

}




```

### 内存管理

- 固定分配
- 动态分配
- 重新分配
- 内存释放

```c

char name[100];
char *description;

strcpy(name, "Zara Ali");

description = (char *)malloc( 200 * sizeof(char) );

free(description);

```

- 栈区(stack) 2M

|        | 大小 | 释放     |     |
| ------ | ---- | -------- | --- |
| 栈内存 | 2M   | 自动释放 |
| 堆内存 | 80%  | 手动释放 |

```c
//40M内存
//字节
//void *任意类型的指针
int* p = malloc(1024 * 1024 * 10 * sizeof(int));

//释放
free(p);
```

1. 不能多次释放；
2. 释放完之后（指针仍然有值），给指针置 NULL，标志释放完成；
3. 内存泄露（p 重新赋值之后，再 free，并没有真正释放内存）；

### 练习任务列表

- [ ] 打印 hello world
- [ ] 输出整数，字符串，浮点数，双精度
- [ ] 判断三个数中最大的数字
- [ ] 输出 10 以内的偶数
- [ ] 20000 转换成时分秒
- [ ] 计算 10 的阶乘
- [ ] 输出 A-Z
- [ ] 输入一句话存到文件里面
- [ ] 统计一个字符串中每个字符出过的次数
- [ ] 数组排序




### 再次确认

- 指针的深刻理解和使用 / 对指针本质的认识，指针的各种使用场合
- 位运算 / 各种位运算符号应用（注意很对妙用），进制转换
- 存储管理 / 作用域和存储类型等
- 预处理 / 主要是#define和#include
- 字符串的处理 / 各种字符串处理函数
- 文件的读写操作 / 各种文件处理函数的使用，大量I/O函数使用
- 函数熟练使用 / 模块化编程思想和能力
- 常用数据结构 / 现阶段主要是表、栈和队列
- 图形图像的简单处理 / 能够利用C处理简单图像



### 真实场景

[郭天祥的51教程](https://www.bilibili.com/video/av68969715/)
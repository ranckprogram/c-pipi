# c语言学习笔记

### 流程步骤
- [x] 环境安装
- [x] 常用指令
- [ ] 包管理器
- [x] 自己定义头文件
- [ ] 指针，函数，结构体
- [ ] 内存管理
- [ ] 可变参数函数
- [ ] 命令行参数
- [x] 自定义可移植的函数库
- [ ] 使用一下标准库
- [ ] 实现一个数据结构
- [ ] 写个应用

### 环境安装


### c包管理器

https://conan.io/



### C可以做什么

- 嵌入式
- 硬件编程
- 


### 多文件编程

多文件的时候除了将所有代码写在 h 文件里面有没有办法将函数实现写在c文件里面
```
gcc -o tool.o tool.c 
```
makefile 
编译成目标文件，在转换成二进制


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

||大小|释放||
|-|-|-|-|
|栈内存|2M|自动释放|
|堆内存|80%|手动释放|


```c
//40M内存
//字节
//void *任意类型的指针
int* p = malloc(1024 * 1024 * 10 * sizeof(int));

//释放
free(p);
```


1. 不能多次释放；
2. 释放完之后（指针仍然有值），给指针置NULL，标志释放完成；
3. 内存泄露（p重新赋值之后，再free，并没有真正释放内存）；
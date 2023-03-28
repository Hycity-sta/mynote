// 这里是一些大话数据结构的基础知识
#include <stdio.h>
#include <stdlib.h> //malloc函数在这个头文件里面有

#define MAXSIZE 30 //预定义一个30常量

typedef int ElemType; //定义一个新的类型来当int方便修改
typedef int Status;

struct Node {
    int num; //这是一个结构体
};
typedef struct Node * PtoNode; //定义一个指针类型到结构体
typedef PtoNode list; //将指针变量定义一个list出来
//这样子,写list的时候就变成了PtoNode,进而变成struct Node *
//例如 list a变成了struct Node * a, a其实是一个指针变量.
int main() {
    list a = (list)malloc(sizeof(struct Node)); //因为a是一个指针变量,所以要分配内存给他
    int *b; //创建一个指针变量的时候,没有赋值给他地址,所以他是没有内存空间的. 但是指针变量本身是有一个地址的
    return 0;
}

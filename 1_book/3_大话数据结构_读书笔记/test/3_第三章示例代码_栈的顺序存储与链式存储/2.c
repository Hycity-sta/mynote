/**
 * 这里是栈的链式存储
 * 搞清楚一下概念
 * 链式栈内部是由链结点构成的,与链表一个样,数据都存放在结点上
 * 链式栈本身的操作只有计数,还有操作栈顶的结点
 * 结点本身存在于内存的各个角落,
 * 不过操作的时候是将通过一个指向栈顶的指针来进行操作
 * 可以没有头结点,下面都是没有头结点的
 **/
#include <stdio.h>
#include <stdlib.h>

#define ERROR 0
#define OK 1

typedef int ElemType;
typedef int Status;

typedef struct StackNode * PtoStackNode;
typedef PtoStackNode LinkStackNode;
struct StackNode {
    ElemType data;
    LinkStackNode next;
};//这个玩意跟链表的结点一样

//下面这个结构才是链式栈的本体
//本体代表栈顶的结点,还有一个计数器
typedef struct LinkStack{
    LinkStackNode top;
    int count;
}* PtoLinkStack;
typedef PtoLinkStack LinkStack;

//初始化链式栈的结点 --空结点 
//貌似这一步初始化没必要了,如果你想要集成度高一点的话,可
//以将这个函数实现初始化操作
LinkStackNode EmptyLinkStackNode(LinkStackNode n) {
    n = (LinkStackNode)malloc(sizeof(struct StackNode));
    return n;
}

//初始化一个链式栈出来
//这是一个空栈,栈顶是空的
//如果追求安全才做这一步,将栈的计数器归零并把指针指向null
LinkStack EmptyLinkStack(LinkStack s) {
    s = (LinkStack)malloc(sizeof(struct LinkStack));
    s->top = NULL;
    s->count = 0;
    return s;
}


/**
 * 输入元素e为新的栈顶元素
 * e为用户输入的元素
 * 需要传入一个链式栈
 **/
Status Push(LinkStack s, ElemType e) {
    //先新建一个链式栈的结点
    LinkStackNode my = (LinkStackNode)malloc(sizeof(struct StackNode));
    my->data = e; //将数据赋值给准备成栈顶的结点
    my->next = s->top; //将栈顶结点下一个指向原来的栈顶结点
    s->top = my; //将现在的栈顶结点的地址赋值,更新现在的栈顶
    s->count++;//计数器加一
    return OK;
}
//图示如下
//[a1(top)]
//[my]  [a1(top)]
//[my]->[a1(top)]
//[my(top)]->[a1]
//栈底是链表的尾部


//链式栈的出栈操作
Status Pop(LinkStack s, ElemType *e) {
    LinkStackNode p;
    if (s->count == 0) {
        return ERROR;//栈是空的,错误
    }

    *e = s->top->data;//将栈顶数据存到e

    p = s->top; //通过中间节点来操控栈顶节点
    s->top = s->top->next;

    free(p);//释放掉栈顶结点的内存
    s->count--;//将计数器减一
    return OK;
}

int main() {
    LinkStack s = EmptyLinkStack(s);
    Push(s,5);
    Push(s,4);
    int d;
    Pop(s,&d);
    printf("%d",s->top->data);
    printf("%d",d);
}

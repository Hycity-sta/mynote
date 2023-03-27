/**
 * 这里是栈的顺序存储
 * 还有共享栈
 **/

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 30
#define OK 1
#define ERROR 0

typedef int Status;
typedef int ElemType;

typedef struct SqStack * PtoStack;
typedef PtoStack Stack;

/**
 * 先说好
 * 这里的栈是顺序存储的,所以用数组来存储data
 * 这里top是指栈顶
 * 如果是空栈,那么top为-1
 * 栈的倒数第一个元素对应的top为0
 * 在这里,可以将top当做是data的下标
 */
struct SqStack {
    ElemType data[MAXSIZE];
    int top;
};

//初始化一个栈
Stack EmptyStack(Stack s) {
    s = (Stack)malloc(sizeof(struct SqStack));
    s->top = -1;
    return s;
}

//插入元素e为新的栈顶元素 --进栈
Status Push(Stack s, ElemType e){
    if (s->top == MAXSIZE-1) {
        //栈满了
        return ERROR;
    }
    s->top++; //栈顶加一
    s->data[s->top]=e; //赋值给栈
    return OK;
}

//删除栈顶元素,用e返回其值 --出栈
Status Pop(Stack s, ElemType *e){
    if (s->top == -1) {
        return ERROR; //空栈不合法
    }
    *e = s->data[s->top]; //将栈顶的元素存到e那里
    s->top--;
    return OK;
}


/**
 * 两栈共享空间结构
 * 这种是进化版的栈,用一个数组来存放两个栈
 *
 **/
typedef struct SqDoubleStack {
    ElemType data[MAXSIZE];
    int top1;
    int top2;
}* PtoDoubleStack;
typedef PtoDoubleStack DoubleStack;

/**
 * 初始化共享栈
 * 两个栈共享一个数组
 * 当栈1为空时,top为-1
 * 当栈2为空时,top为maxsize
 **/
DoubleStack EmptyDoubleStack(DoubleStack s) {
    s = (DoubleStack)malloc(sizeof(struct SqDoubleStack));
    s->top1=-1;
    s->top2=MAXSIZE;
    return s;
}

/**
 * 共享栈的插入
 * e是要插入的元素
 * stackNumber是指定要插入哪一个栈
 * top1是向+移动,top2是向-移动,两者相差为1的时候为栈满
 **/
Status Push_double(DoubleStack s, ElemType e, int stackNumber) {
    if (s->top1+1 == s->top2) {
        return ERROR; //栈满
    }
    if (stackNumber == 1) {
        s->data[++s->top1] = e; //先让top移动,然后赋值
    }
    else if (stackNumber == 2) {
        s->data[--s->top2] = e; //先让top移动,然后赋值
    }
    return OK;
}

/**
 * 共享栈的弹出
 * 用e返回值
 * 用stackNumber来判断是哪个栈
 **/
Status Pop_double(DoubleStack s, ElemType * e, int stackNumber) {
    if (stackNumber == 1) {
        if (s->top1==-1) {
            return ERROR; //栈1是空栈
        }
        *e = s->data[s->top1--]; //先赋值再top--
    }
    else if (stackNumber == 2) {
        if (s->top2 == MAXSIZE) {
            return ERROR; //栈二是空的
        }
        *e = s->data[s->top2++]; //先赋值再运算
    }
    return OK;
}


int main() {
    Stack my = EmptyStack(my);
    Push(my,3);
    Push(my,2);
    int a = 0;
    int b = 0;
    printf("%d\n%d",a,b);
    return 0;
}


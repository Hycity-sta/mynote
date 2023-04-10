// 这儿是队列的顺序存储
// 需要注意的是,这里队列的满队条件是留下一个数组空间,而不是全部占满.
// 如果是全部占满的话,处理起来会与下面的代码不一样,而且会很麻烦
// 以下代码都是是循环队列,属于一种特殊情况.
// 对于一般的队列,实现方法与顺序表差不多,只需要满足队列的操作要求即可所以这里不写示例了
// 因为循环队列是为了处理顺序表中需要移动元素还有假上溢的缺陷

/**
 * 这里涉及到了数学方面的知识,不过对于我而言当做工具使用即可.
 * 这里的取余%运算是很有用的,因为rear和front永远不会超过MAXSIZE,所以取余之后都会得到他自己
 * 如果rear+1之后取余得到与front一样的值,说明这两个是相邻的,也说明队列是满的
 * 这里rear和front都是指数组的下标而不是位序
 * 这里计算队列长度的公式是通用的,也不用问为什么成立,记住就好了.因为这是数学的东西,现在还没有实力接触
 * 因为避免front和rear相等的判断问题,所以这里循环队列的对尾是指向最后一个空的位置, 也就是说, 数组并没有完全塞满, 这样子就可以保证在front等于rear时队列是空的了.
 **/

#include <stdlib.h>
#include <stdio.h>

#define OK 1
#define ERROR 0
#define MAXSIZE 30

typedef int ElemType;
typedef int Status;

struct SqQueue {
    ElemType data[MAXSIZE];
    int front; //队头 都是下标
    int rear; //队尾
};
typedef struct SqQueue * Ptosq;
typedef Ptosq queue;

// 初始化一个队列
queue InitQueue(queue q) {
    q = (queue)malloc(sizeof(struct SqQueue));
    q->front = 0;
    q->rear = 0;
    return q;
}

// 返回队列的长度
int QueueLength(queue q) {
    //这个是一个数学公式来的
    return (q->rear - q->front + MAXSIZE) % MAXSIZE; //看来这个公式涉及到数学了,所以先记着吧,毕竟网络上也没有相关的说明
}

// 在队列的队尾插入元素e
Status EnQueue(queue q, ElemType e) {
    if ((q->rear+1) % MAXSIZE == q->front) {
        return ERROR;//这是队列满的情况,加1之后取余等于队头
    }
    q->data[q->rear]=e;
    q->rear = (q->rear+1) %MAXSIZE; //取余可以保证rear可以在新的循环中从0开始
    return OK;
}

// 将队头元素出队,用指针e返回
Status DeQueue(queue q, ElemType *e) {
    if (q->front == q->rear) {
        return ERROR; //这两个相等,所以队列是空的
    }
    *e = q->data[q->front];
    q->front = (q->front+1)%MAXSIZE;
    return OK;
}

// 下面是具体实现
int main(int argc, char *argv[])
{
    queue a = InitQueue(a);
    int b = 8;
    EnQueue(a,b);
    EnQueue(a,5);
    DeQueue(a,&b);
    DeQueue(a,&b);
    printf("%d",b);
    return 0;
}

//最重要的运算公式
//(q->rear+1) % MAXSIZE == q->front 判断队列是满的
//q->rear = (q->rear+1)  %MAXSIZE 在入队之后对rear的操作
//q->front = q->front+1 %MAXSIZE 在出队之后对front的操作
//q->front = q->rear 判断队列是空的
//(q->rear - q->front + MAXSIZE) % MAXSIZE 获取队列的长度

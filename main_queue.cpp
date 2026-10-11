// main_queue.cpp - 队列测试
#include "SqQueue.h"
#include <cstdio>

int main()
{
    SqQueue sq;
    ElemType e;

    printf("初始化队列\n");
    InitQueue(sq);
    printf("队%s\n", (QueueEmpty(sq) == 1 ? "空" : "不空"));

    printf("a进队\n"); EnQueue(sq, 'a');
    printf("b进队\n"); EnQueue(sq, 'b');
    printf("c进队\n"); EnQueue(sq, 'c');
    printf("d进队\n"); EnQueue(sq, 'd');
    printf("队%s\n", (QueueEmpty(sq) == 1 ? "空" : "不空"));

    GetHead(sq, e);
    printf("队头元素：%c\n", e);

    printf("出队次序：");
    while (!QueueEmpty(sq))
    {
        DeQueue(sq, e);
        printf("%c ", e);
    }
    printf("\n");

    DestroyQueue(sq);
    return 0;
}

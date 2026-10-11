// SqQueue.h - 顺序队（循环队列）类型声明
#ifndef SQQUEUE_H
#define SQQUEUE_H

#define MaxSize 20         // 指定队列的容量

typedef char ElemType;     // 保存队列元素

typedef struct
{
    ElemType data[MaxSize];
    int front, rear;         // 队头和队尾指针
} SqQueue;

void InitQueue(SqQueue& sq);
void DestroyQueue(SqQueue sq);
int EnQueue(SqQueue& sq, ElemType x);
int DeQueue(SqQueue& sq, ElemType& x);
int GetHead(SqQueue sq, ElemType& x);
int QueueEmpty(SqQueue sq);

#endif

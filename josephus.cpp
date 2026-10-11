// josephus.cpp - 用循环队列求解约瑟夫问题
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

#define MaxSize 100

// 整数循环队列（算法与课本SqQueue完全一致）
typedef struct
{
    int data[MaxSize];
    int front, rear;   // 队头和队尾指针
} IntQueue;

void InitQueue(IntQueue &sq)
{
    sq.rear = sq.front = 0;
}

int QueueEmpty(IntQueue sq)
{
    if (sq.rear == sq.front) return 1;
    else return 0;
}

int EnQueue(IntQueue &sq, int x)
{
    if ((sq.rear + 1) % MaxSize == sq.front)  // 队满上溢出
        return 0;
    sq.rear = (sq.rear + 1) % MaxSize;        // 队尾循环进1
    sq.data[sq.rear] = x;
    return 1;
}

int DeQueue(IntQueue &sq, int &x)
{
    if (sq.rear == sq.front)                   // 队空下溢出
        return 0;
    sq.front = (sq.front + 1) % MaxSize;       // 队头循环进1
    x = sq.data[sq.front];
    return 1;
}

int main()
{
    int n, m, p, i = 0;
    IntQueue sq;      // 定义一个整数队列sq

    printf("=== 用循环队列求解约瑟夫问题 ===\n");
    printf("请输入总人数n：");
    scanf("%d", &n);
    printf("请输入报数m（数到m的人出列）：");
    scanf("%d", &m);

    if (n <= 0 || m <= 0 || n > MaxSize - 1)
    {
        printf("输入不合法！请确保 0 < n <= %d 且 m > 0\n", MaxSize - 1);
        return 1;
    }

    InitQueue(sq);

    // 将1~n（对应n个人的编号）依次进队
    for (int k = 1; k <= n; k++)
        EnQueue(sq, k);

    printf("出列顺序：");
    while (!QueueEmpty(sq))   // 队不空循环
    {
        i++;                  // 报数次数加1
        DeQueue(sq, p);       // 连续出队元素p

        if (i % m != 0)
            EnQueue(sq, p);   // 还没数到m，将p重新进队
        else
            printf("%d ", p); // 恰好数到m，p出列
    }
    printf("\n");
    return 0;
}

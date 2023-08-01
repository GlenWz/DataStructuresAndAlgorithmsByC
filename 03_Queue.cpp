#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 5 // 设置队列的最大容量为5

typedef struct
{
    int data[MAX_SIZE];
    int front; // 队头指针
    int rear;  // 队尾指针
} CircularQueue;

// 初始化队列
void initQueue(CircularQueue *queue)
{
    queue->front = queue->rear = 0;
}

// 判断队列是否为空
bool isEmpty(CircularQueue *queue)
{
    return queue->front == queue->rear;
}

// 判断队列是否满
bool isFull(CircularQueue *queue)
{
    return (queue->rear + 1) % MAX_SIZE == queue->front;
}

// 入队
bool enqueue(CircularQueue *queue, int value)
{
    if (isFull(queue))
    {
        printf("the queue is full\n");
        return false; // 队列满，入队失败
    }
    queue->data[queue->rear] = value;
    queue->rear = (queue->rear + 1) % MAX_SIZE;
    return true;
}

// 出队
bool dequeue(CircularQueue *queue, int *value)
{
    if (isEmpty(queue))
    {
        return false; // 队列空，出队失败
    }
    *value = queue->data[queue->front];
    queue->front = (queue->front + 1) % MAX_SIZE;
    return true;
}

// 打印循环队列
void print(CircularQueue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty.\n");
        return;
    }

    int i = queue->front;
    printf("Queue elements: ");
    do
    {
        printf("%d-> ", queue->data[i]);
        i = (i+1) % MAX_SIZE;
    }
    while (i != (queue->rear) % MAX_SIZE);

    printf("\n");
}

int main()
{
    CircularQueue queue;
    initQueue(&queue);

    // 入队操作
    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);
    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);
    print(&queue);
    // 出队操作
    int value;
    dequeue(&queue, &value);
    printf("Dequeued element: %d\n", value);
    print(&queue);
    enqueue(&queue, 888);
    dequeue(&queue, &value);
    enqueue(&queue, 999);
    print(&queue);
    return 0;
}

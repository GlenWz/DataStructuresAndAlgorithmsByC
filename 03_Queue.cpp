#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 5 // ���ö��е��������Ϊ5

typedef struct
{
    int data[MAX_SIZE];
    int front; // ��ͷָ��
    int rear;  // ��βָ��
} CircularQueue;

// ��ʼ������
void initQueue(CircularQueue *queue)
{
    queue->front = queue->rear = 0;
}

// �ж϶����Ƿ�Ϊ��
bool isEmpty(CircularQueue *queue)
{
    return queue->front == queue->rear;
}

// �ж϶����Ƿ���
bool isFull(CircularQueue *queue)
{
    return (queue->rear + 1) % MAX_SIZE == queue->front;
}

// ���
bool enqueue(CircularQueue *queue, int value)
{
    if (isFull(queue))
    {
        printf("the queue is full\n");
        return false; // �����������ʧ��
    }
    queue->data[queue->rear] = value;
    queue->rear = (queue->rear + 1) % MAX_SIZE;
    return true;
}

// ����
bool dequeue(CircularQueue *queue, int *value)
{
    if (isEmpty(queue))
    {
        return false; // ���пգ�����ʧ��
    }
    *value = queue->data[queue->front];
    queue->front = (queue->front + 1) % MAX_SIZE;
    return true;
}

// ��ӡѭ������
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

    // ��Ӳ���
    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);
    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);
    print(&queue);
    // ���Ӳ���
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

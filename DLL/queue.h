#ifndef QUEUE_H
#define QUEUE_H

typedef struct QueueNode {
    void* data;
    int priority;
    struct QueueNode* next;
} QueueNode;

typedef struct {
    QueueNode* front;
    QueueNode* rear;
    int size;
} PriorityQueue;

// Fungsi dasar
void initQueue(PriorityQueue* q);
void enqueue(PriorityQueue* q, void* data, int priority);
void* dequeue(PriorityQueue* q);
int isQueueEmpty(PriorityQueue q);
int queueSize(PriorityQueue q);
void printQueue(PriorityQueue q, void (*printData)(void*));

#endif

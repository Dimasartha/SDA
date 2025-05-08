#include "queue.h"
#include <stdlib.h>

void initQueue(PriorityQueue* q) {
    q->front = q->rear = NULL;
    q->size = 0;
}

void enqueue(PriorityQueue* q, void* data, int priority) {
    QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
    newNode->data = data;
    newNode->priority = priority;
    newNode->next = NULL;

    if (isQueueEmpty(*q)) {
        q->front = q->rear = newNode;
    } else if (priority < q->front->priority) {
        newNode->next = q->front;
        q->front = newNode;
    } else {
        QueueNode* current = q->front;
        while (current->next && current->next->priority <= priority) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
        if (!newNode->next) q->rear = newNode;
    }
    q->size++;
}

void* dequeue(PriorityQueue* q) {
    if (isQueueEmpty(*q)) return NULL;
    
    QueueNode* temp = q->front;
    void* data = temp->data;
    
    q->front = q->front->next;
    if (!q->front) q->rear = NULL;
    
    free(temp);
    q->size--;
    return data;
}

int isQueueEmpty(PriorityQueue q) {
    return q.front == NULL;
}

int queueSize(PriorityQueue q) {
    return q.size;
}

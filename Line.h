#ifndef __LINKEDQUEUE_H__
#define __LINKEDQUEUE_H__
#include "patient.h"
#include <cstddef>


typedef struct Node
{
    Patient patient;
    struct Node* next;
}QueueNode;

typedef struct
{
    QueueNode* front, * rear;
}LinkedQueue;


//���
void push(LinkedQueue& s, Patient x);

//����
void pop(LinkedQueue& s, Patient* e);

//��ȡ��ͷ
Patient* getHead(LinkedQueue& s);

//�ж��Ƿ�ն�
int emptyQueue(LinkedQueue& s);

//�������������Ϣ
void printQueue(LinkedQueue& s);


//��ȡ���г���
int lengthQueue(LinkedQueue& s);

void InitQueue(LinkedQueue& s);

#endif


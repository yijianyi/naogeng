#include "Line.h"
#include <iostream>

/*
@brief
*/

void push(LinkedQueue& s, Patient x) {
    QueueNode* p = new QueueNode;
    p->patient = x;
    p->next = NULL;
    s.rear->next = p;
    s.rear = p;

}

//����
void pop(LinkedQueue& s, Patient* e) {
    if (emptyQueue(s))
    {
        std::cout << "����Ϊ��" << std::endl;
        return;
    }

    QueueNode* p;
    p = s.front->next;
    if (p == s.rear)
    {
        s.front = s.rear;
    }
    *e = p->patient;
    if (p->next == NULL)
    {
        std::cout << "test" << std::endl;
    }
    else
    {
        std::cout << "sssss" << std::endl;
    }
    s.front->next = p->next;
 
}

//��ȡ��ͷ
Patient* getHead(LinkedQueue& s) {
    if (emptyQueue(s))
    {
        std::cout << "����Ϊ��" << std::endl;
        return NULL;
    }
    return &(s.front->next->patient);
}

//�ж��Ƿ�ն�
int emptyQueue(LinkedQueue& s) {
    if (s.front == s.rear)
    {
        return 1;
    }
    return 0;
}

//�������������Ϣ
void printQueue(LinkedQueue& scanf_s) {
    QueueNode* iter = scanf_s.front->next;
    if (iter == NULL)
    {
        std::cout << "���Ŷӻ���" << std::endl;
    }
    while (iter != NULL)
    {
        std::cout << "������" << iter->patient.name << std::endl;
        std::cout << "ID: " << iter->patient.ID << std::endl;
        std::cout << "���ң�" << iter->patient.roomNumber << std::endl;
        std::cout << "ҽ����" << iter->patient.doctor << std::endl;
        std::cout << std::endl;
        iter = iter->next;
    }
}


//��ȡ���г���
int lengthQueue(LinkedQueue& s) {
    QueueNode* p;
    p = s.front;

    int length = 0;
    while (p->next)
    {
        length++;
        p = p->next;
    }
    return length;
}

void InitQueue(LinkedQueue& s)
{
    QueueNode* p;
    p = new QueueNode;
    if (!p)
    {
        std::cout << "�����ڴ�ʧ��" << std::endl;
        return;
    }
    p->next = NULL;
    s.front = s.rear = p;
}
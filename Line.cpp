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

//出队
void pop(LinkedQueue& s, Patient* e) {
    if (emptyQueue(s))
    {
        std::cout << "队列为空" << std::endl;
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

//获取队头
Patient* getHead(LinkedQueue& s) {
    if (emptyQueue(s))
    {
        std::cout << "队列为空" << std::endl;
        return NULL;
    }
    return &(s.front->next->patient);
}

//判断是否空队
int emptyQueue(LinkedQueue& s) {
    if (s.front == s.rear)
    {
        return 1;
    }
    return 0;
}

//遍历输出病人信息
void printQueue(LinkedQueue& scanf_s) {
    QueueNode* iter = scanf_s.front->next;
    if (iter == NULL)
    {
        std::cout << "无排队患者" << std::endl;
    }
    while (iter != NULL)
    {
        std::cout << "姓名：" << iter->patient.name << std::endl;
        std::cout << "ID: " << iter->patient.ID << std::endl;
        std::cout << "科室：" << iter->patient.roomNumber << std::endl;
        std::cout << "医生：" << iter->patient.doctor << std::endl;
        std::cout << std::endl;
        iter = iter->next;
    }
}


//获取队列长度
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
        std::cout << "分配内存失败" << std::endl;
        return;
    }
    p->next = NULL;
    s.front = s.rear = p;
}
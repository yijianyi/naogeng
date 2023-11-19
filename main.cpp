#include <iostream>
#include <string>
#include "Line.h"
//#include "Patient.h"


int main() {
    LinkedQueue patients;  // ��������
    InitQueue(patients);   // ��ʼ������

    int choice;
    do {
        // ��ʾ�˵�
        std::cout << "====== ���в����˵� ======" << std::endl;
        std::cout << "1. ���" << std::endl;
        std::cout << "2. ����" << std::endl;
        std::cout << "3. �鿴��ͷ������Ϣ" << std::endl;
        std::cout << "4. �鿴���г���" << std::endl;
        std::cout << "5. ��ӡ������ʣ�໼����Ϣ" << std::endl;
        std::cout << "0. �˳�" << std::endl;
        std::cout << "���������ѡ��: ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            // ��Ӳ���
            std::string name, ID, doctor;
            int roomNumber;
            int priority;

            std::cout << "�����뻼������: ";
            std::cin >> name;
            std::cout << "�����뻼��ID: ";
            std::cin >> ID;
            std::cout << "��������Һ�: ";
            std::cin >> roomNumber;
            std::cout << "������ҽ������: ";
            std::cin >> doctor;
            std::cout << "�����뻼�����ȼ�: ";
            std::cin >> priority;

            Patient newPatient(name, ID, roomNumber, doctor);
            push(patients, newPatient);
            break;
        }
        case 2: {
            // ���Ӳ���
            if (emptyQueue(patients)) {
                Patient poppedPatient;
                pop(patients, &poppedPatient);
                std::cout << "���ӻ�����Ϣ��" << std::endl;
                std::cout << "������" << poppedPatient.name << std::endl;
                std::cout << "ID��" << poppedPatient.ID << std::endl;
                std::cout << "���ң�" << poppedPatient.roomNumber << std::endl;
                std::cout << "ҽ����" << poppedPatient.doctor << std::endl;
            }
            else {
                std::cout << "�����ѿգ��޷����ӣ�" << std::endl;
            }
            break;
        }
        case 3: {
            // �鿴��ͷ������Ϣ
            if (emptyQueue(patients)) {
                Patient headPatient = getHead(patients);
                std::cout << "��ͷ������Ϣ��" << std::endl;
                std::cout << "������" << headPatient.name << std::endl;
                std::cout << "ID��" << headPatient.ID << std::endl;
                std::cout << "���ң�" << headPatient.roomNumber << std::endl;
                std::cout << "ҽ����" << headPatient.doctor << std::endl;
            }
            else {
                std::cout << "����Ϊ�գ�" << std::endl;
            }
            break;
        }
        case 4:
            // �鿴���г���
            std::cout << "���г���: " << lengthQueue(patients) << std::endl;
            break;
        case 5:
            // ��ӡ������ʣ�໼����Ϣ
            std::cout << "ʣ�໼����Ϣ��" << std::endl;
            printQueue(patients);
            break;
        case 0:
            // �˳�����
            std::cout << "�˳������ټ���" << std::endl;
            break;
        default:
            std::cout << "��Ч��ѡ�����������룡" << std::endl;
        }
    } while (choice != 0);

    return 0;
}

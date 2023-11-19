#include <iostream>
#include <string>
#include "Line.h"
//#include "Patient.h"


int main() {
    LinkedQueue patients;  // 创建队列
    InitQueue(patients);   // 初始化队列

    int choice;
    do {
        // 显示菜单
        std::cout << "====== 队列操作菜单 ======" << std::endl;
        std::cout << "1. 入队" << std::endl;
        std::cout << "2. 出队" << std::endl;
        std::cout << "3. 查看队头患者信息" << std::endl;
        std::cout << "4. 查看队列长度" << std::endl;
        std::cout << "5. 打印队列中剩余患者信息" << std::endl;
        std::cout << "0. 退出" << std::endl;
        std::cout << "请输入你的选择: ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            // 入队操作
            std::string name, ID, doctor;
            int roomNumber;
            int priority;

            std::cout << "请输入患者姓名: ";
            std::cin >> name;
            std::cout << "请输入患者ID: ";
            std::cin >> ID;
            std::cout << "请输入科室号: ";
            std::cin >> roomNumber;
            std::cout << "请输入医生姓名: ";
            std::cin >> doctor;
            std::cout << "请输入患者优先级: ";
            std::cin >> priority;

            Patient newPatient(name, ID, roomNumber, doctor);
            push(patients, newPatient);
            break;
        }
        case 2: {
            // 出队操作
            if (emptyQueue(patients)) {
                Patient poppedPatient;
                pop(patients, &poppedPatient);
                std::cout << "出队患者信息：" << std::endl;
                std::cout << "姓名：" << poppedPatient.name << std::endl;
                std::cout << "ID：" << poppedPatient.ID << std::endl;
                std::cout << "科室：" << poppedPatient.roomNumber << std::endl;
                std::cout << "医生：" << poppedPatient.doctor << std::endl;
            }
            else {
                std::cout << "队列已空，无法出队！" << std::endl;
            }
            break;
        }
        case 3: {
            // 查看队头患者信息
            if (emptyQueue(patients)) {
                Patient headPatient = getHead(patients);
                std::cout << "队头患者信息：" << std::endl;
                std::cout << "姓名：" << headPatient.name << std::endl;
                std::cout << "ID：" << headPatient.ID << std::endl;
                std::cout << "科室：" << headPatient.roomNumber << std::endl;
                std::cout << "医生：" << headPatient.doctor << std::endl;
            }
            else {
                std::cout << "队列为空！" << std::endl;
            }
            break;
        }
        case 4:
            // 查看队列长度
            std::cout << "队列长度: " << lengthQueue(patients) << std::endl;
            break;
        case 5:
            // 打印队列中剩余患者信息
            std::cout << "剩余患者信息：" << std::endl;
            printQueue(patients);
            break;
        case 0:
            // 退出程序
            std::cout << "退出程序，再见！" << std::endl;
            break;
        default:
            std::cout << "无效的选择，请重新输入！" << std::endl;
        }
    } while (choice != 0);

    return 0;
}

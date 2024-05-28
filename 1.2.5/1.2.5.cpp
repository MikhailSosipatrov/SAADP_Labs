#include <iostream>
using namespace std;
const int SIZE = 4;

//Структура очереди
int First, Last;
int RING_QUEUE[SIZE];
int countt = 0;

//Input check 
int failure() {
    int a;
    while (!(cin >> a) || (cin.peek() != '\n'))
    {
        cin.clear();
        while (cin.get() != '\n');
        cout << "\nОшибка. Повторите ввод \n" << endl;
    }
    return a;
}

//Empty queue
void create_queue() {
    First = Last = 0;
}

//Empty check 
int queue_is_empty() {
    if (countt == 0) {
        return 1;
    }
    else {
        return 0;
    }
}

//Full check 
int queue_is_full() {
    if (countt >= SIZE) {
        return 1;
    }
    else {
        return 0;
    }
}

//Add to the end
void add(int value) {

    if (!queue_is_full()) {
        RING_QUEUE[Last] = value;
        Last++;
        if (Last == SIZE) Last = 0;
        countt++;
    }
    else {
        std::cout << "\nОчередь переполнена.\n";
    }

}

//Delete from head
int del() {
    if (!queue_is_empty()) {
        RING_QUEUE[First] = NULL;
        First++;
        if (First == SIZE) First = 0;
        countt--;
    }
    else {
        std::cout << "\nОчередь пуста.\n";
        return -1;
    }
}

//Show queue
void show_queue() {
    if (!queue_is_empty()) {
        std::cout << "\n";
        int current = First;
        int  i = 1;
        do {
            std::cout << i << ") " << RING_QUEUE[current] << "\n";
            current++;
            if (current == SIZE) current = 0;
            i++;
        } while (current != Last);
    }
    else {
        std::cout << "Очередь пустая\n";
    }
}





void menu() {
    int number, value;
    while (true) {
        cout << "\n";
        std::cout << "1. Проверка пустоты очереди\n";
        std::cout << "2. Проверка заполненности очереди\n";
        std::cout << "3. Добавить элемент в конец очереди\n";
        std::cout << "4. Удалить элемент из начала очереди\n";
        std::cout << "5. Вывод текущего состояния очереди на экран\n";
        std::cout << "0. Завершить работу программы\n";
        std::cout << "Введите номер команды: ";
        number = failure();

        switch (number)
        {
        case 0:
            exit(0);
            break;

        case 1:
            if (queue_is_empty() == 1) {
                std::cout << "\nОчередь пустая\n";
            }
            else {
                std::cout << "\nОчередь не пустая\n";
            }
            break;
        case 2:
            if (queue_is_full() == 1) {
                std::cout << "\nОчередь полная\n";
            }
            else {
                std::cout << "\nОчередь не полная\n";
            }
            break;
        case 3:
            if (queue_is_full() == 0) {
                std::cout << "\nВведите число: ";
                value = failure();
                add(value);
            }
            else {
                std::cout << "\nОчередь переполнена.\n";
            }
            break;
        case 4:
            del();
            break;
        case 5:
            show_queue();
            break;
        default:
            cout << "Ошибка. Повторите ввод\n";
            break;

        }




    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    create_queue();
    menu();
    return 0;
}


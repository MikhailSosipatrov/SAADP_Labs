#include <iostream>
#include <ctime>

using namespace std;



//Правильность ввода
int input_check() {
    int a;
    while (!(cin >> a) || (cin.peek() != '\n'))
    {
        cin.clear();
        while (cin.get() != '\n');
        cout << "\nОшибка. Повторите ввод.\n" << endl;
    }
    return a;
}

//Структура стека
struct Stack {
    int value;
    Stack* next;
}*main_stack, *reserve_stack; 

//Создание пустого стека
void createStack() {
    main_stack = NULL;
    reserve_stack = NULL; 
}

//Проверка пустоты стека
bool isEmpty() {
    if (main_stack == NULL) return 1;
    else return 0;
}

//Проверка пустоты вспомогательного стека
bool isrReserveEmpty() {
    if (reserve_stack == NULL) {
        return 1;
    }
    else {
        return 0;
    }
}

//Функция вывода состояния стека
void stackCondition(Stack* stack) {
    if (stack != NULL) {
        cout << "\n";
        Stack* current = stack;
        int i = 1;
        do {
             cout << i << ") " << current->value << "\n";
            current = current->next;
            i++;
        } while (current != NULL);
        delete current;
    }
    else {
         cout << "Стек пуст.\n";
    }
    
}

//Функция добавления в стек
Stack* add(Stack* stack, int val) {
    Stack* new_element = new Stack;
    new_element->value = val;
    new_element->next = stack;
    stack = new_element;
    return stack;
}

//Функция добавления случайного числа элементов в стек
void addRandom() {
    int count;
    cout << "Сколько чисел добавить? ";
    count = input_check();
    for (int i = 0; i < count; i++)
        main_stack = add(main_stack, rand());
}

//Функция удаления из стека
void del() {
    if (!isEmpty()) {
        Stack* current; 
        current = main_stack;
        main_stack = main_stack->next;
        delete current;
    }
}

//Вместо удаления - перемещение во вспомогательный стек
void moveToReserveStack() {
    Stack* current = main_stack;
    main_stack = main_stack->next;
    current->next = reserve_stack;
    reserve_stack = current;
}

//Добавление с вершины вспомогательного стека
void addFromSecond() {
    Stack* current = reserve_stack;
    reserve_stack = reserve_stack->next;
    current->next = main_stack;
    main_stack = current;
}

void menu() {
    int number, value, choice;
    while (true) {
        cout << "\n";
        cout << "\nВведите номер команды:\n";
        cout << "1. Вывести состояние главного стека\n";
        cout << "2. Добавить элемент в главный стек\n";
        cout << "3. Удалить элемент из главного стека\n";
        cout << "4. Добавить несколько случайных чисел в главный стек\n";
        cout << "5. Вывести состояние вспомогательного стека\n";
        cout << "0. Завершить работу программы\n";
        cout << "Ваш выбор: ";
        number = input_check(); 
        switch (number)
        {
            case 0:
                exit(0);
                break;

            case 1:
                cout << "Состояние стека: ";
                stackCondition(main_stack);
                break; 


            case 2: 
                cout << "\n 1. Создать новый элемент \n 2. Взять элемент с вершины вспомогательного стека\nВведите: ";
                choice = input_check();
                if (choice == 1) {
                    cout << "Введите целое число: "; 
                    value = input_check();
                    main_stack = add(main_stack, value);
                }
                else if (choice == 2) {
                    if (!isrReserveEmpty())
                    {
                        addFromSecond();
                    }
                    else  cout << "Вспомогательный стек пуст.\n";
                }
                else
                    cout << "Ошибка ввода. Повторите ввод команды\n";
                break; 





            case 3:
                if (!isEmpty()) {
                    cout << "\n 1. Удалить элемент \n 2. Включить его в вершину вспомогательного стека удаленных элементов\nВведите: ";
                    choice = input_check();
                    if (choice == 1) {
                        del();
                    }
                    else if (choice == 2) {
                        moveToReserveStack();
                    }
                    else {
                        cout << "Ошибка. Повторите ввод\n";
                    }
                }
                else {
                    cout << "Стек пуст\n";
                }
                break;






            case 4: 
                addRandom();
                break;



            case 5: 
                cout << "Состояние вспомогательного стека удаленных элементов: ";
                stackCondition(reserve_stack);
                break; 



            default: 
                cout << "Ошибка. Повторите ввод\n";


        }
       
             
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    createStack(); 
    srand(time(0)); 
    menu();
    ::main_stack = NULL; 
    ::reserve_stack = NULL; 
    return 0;
}

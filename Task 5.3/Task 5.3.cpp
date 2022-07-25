#include <iostream>
#include <time.h>
#include <Windows.h>
using namespace std;

void task_1();
void task_2();
void task_3();
void fill_array(int* array, int length);
void show_array(int* array, int length);
void menu();

int main()
{
    setlocale(LC_ALL, "Russian");

    menu();

    return 0;
}

void fill_array(int* array, int length)
{
    Sleep(1000);
    srand(time(NULL));
    for (int i = 0; i < length; i++)
    {
        array[i] = rand() % 101;
    }
}

void show_array(int* array, int length)
{
    for (int i = 0; i < length; i++)
    {
        cout << array[i] << "\t";
    }
    cout << "\n\n";
}

void task_1()
{
    int length = 10;
    int* array = new int[length];
    fill_array(array, length);
    cout << "Массив: ";
    show_array(array, length);
    int* first_half_array = new int[length / 2];
    int* second_half_array = new int[length / 2];
    for (int i = 0; i < length; i++)
    {
        if (i < length / 2) first_half_array[i] = array[i];
        else second_half_array[i - length / 2] = array[i];
    }
    cout << "Первая половина массива: ";
    show_array(first_half_array, length / 2);
    cout << "Вторая половина массива: ";
    show_array(second_half_array, length / 2);
    delete[]array;
    delete[]first_half_array;
    delete[]second_half_array;
}

void task_2()
{
    int length = 10;
    int* array_1 = new int[length];
    fill_array(array_1, length);
    cout << "Массив 1:\t";
    show_array(array_1, length);
    int* array_2 = new int[length];
    fill_array(array_2, length);
    cout << "Массив 2:\t";
    show_array(array_2, length);
    int* array = new int[length * 2];
    for (int i = 0; i < length * 2; i++)
    {
        if (i < length) array[i] = array_1[i];
        else array[i] = array_2[i - length];
    }
    cout << "Объединенный массив:\t";
    show_array(array, length * 2);
    delete[]array_1;
    delete[]array_2;
    delete[]array;
}

void task_3()
{
    struct week
    {
        string day;
        int expenses;
    };
    string days_in_week[7] = { "Понедельник", "Вторник", "Среда", "Четверг", "Пятница", "Суббота", "Воскресенье" };
    week expenses_per_week[7];
    double average = 0;
    int sum = 0, number_of_overdraft = 0;
    for (int i = 0; i < 7; i++)
    {
        expenses_per_week[i].day = days_in_week[i];
    }
    cout << "Введите расходы по дням:\n\n";
    for (int i = 0; i < 7; i++)
    {
        cout << expenses_per_week[i].day << ": ";
        cin >> expenses_per_week[i].expenses;
        cout << "\n";
        sum += expenses_per_week[i].expenses;
        (expenses_per_week[i].expenses > 100) ? number_of_overdraft++ : number_of_overdraft;
    }
    average = sum / 7;
    cout << "\nСредний расход за неделю: " << average << endl;
    cout << "Общая потраченная сумма: " << sum << endl;
    cout << "Количество дней, когда расход превысил 100: " << number_of_overdraft << endl;
    if (number_of_overdraft)
    {
        for (int i = 0; i < 7; i++)
        {
            if (expenses_per_week[i].expenses > 100) cout << expenses_per_week[i].day << "\t" << expenses_per_week[i].expenses << endl;
        }
    }
}

void menu()
{
    int task = 0;
    void(*list_of_menu[3])() = { task_1, task_2, task_3 };
    cout << "ЗАДАЧА № 4 НЕ РЕАЛИЗОВАНА ПО ПРИЧИНЕ НЕПОНЯТНО ЧЕГО ОТ МЕНЯ ХОТЯТ\n\n";
    do
    {
        do
        {
            cout << "Введите номер задачи, 0 - выход: ";
            cin >> task;
        } while (task < 0 or task > 3);
        if (task) list_of_menu[task - 1]();
    } while (task);
}
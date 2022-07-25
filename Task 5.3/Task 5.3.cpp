#include <iostream>
#include <time.h>
#include <Windows.h>
using namespace std;

void task_1();
void task_2();
void task_3();
void fill_array(int* array, int length);
void show_array(int* array, int length);

int main()
{
    setlocale(LC_ALL, "Russian");

    task_1();

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
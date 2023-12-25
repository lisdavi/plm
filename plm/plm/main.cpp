#include <iostream>
#include <fstream>
#include <cstring>
#include "file_reader.h"
#include "tele_cons.h"
#include "const.h"
#include <string>
using namespace std;

void print_stuff(phone_call* call[], int id)
{
    cout << call[id]->phone_number << ' ';
    cout << call[id]->call_date.day << '.';
    cout << call[id]->call_date.month << '.';
    cout << call[id]->call_date.year << ' ';
    cout << call[id]->call_time.hours << ':';
    cout << call[id]->call_time.minutes << ':';
    cout << call[id]->call_time.seconds << ' ';
    cout << call[id]->duration.hours << ':';
    cout << call[id]->duration.minutes << ':';
    cout << call[id]->duration.seconds << ' ';
    cout << call[id]->tariff << ' ';
    cout << call[id]->cost << '\n';
}

void only_mobile(phone_call* subscriptions[], int size)
{


    for (int i = 0; i < size; i++)
    {
        if (strstr(subscriptions[i]->tariff, "mobile") != NULL)
        {
            print_stuff(subscriptions, i);
        }
    }
}
void only_november21(phone_call* subscriptions[], int size)
{


    for (int i = 0; i < size; i++)
    {
        if (subscriptions[i]->call_date.month == 11 && subscriptions[i]->call_date.year == 2021)
        {
            print_stuff(subscriptions, i);
        }
    }
}

bool SortCase(int sort_id, phone_call* subscriptions[], int size, int id, int id2)
{
    switch (sort_id)
    {
    case 1:
    {
        if ((subscriptions[id]->duration.hours) * 3600 + (subscriptions[id]->duration.minutes) * 60 + (subscriptions[id]->duration.seconds) < (subscriptions[id2]->duration.hours) * 3600 + (subscriptions[id2]->duration.minutes) * 60 + (subscriptions[id2]->duration.seconds))
        {
            return true;
        }
        else
        {
            return false;
        }
        break;
    }
    case 2:
    {
        if (subscriptions[id]->phone_number < subscriptions[id2]->phone_number)
        {
            return false;
        }
        if (subscriptions[id]->phone_number > subscriptions[id2]->phone_number)
        {
            return true;
        }
        if (subscriptions[id]->phone_number == subscriptions[id2]->phone_number)
        {
            if (subscriptions[id]->cost < subscriptions[id2]->cost)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        break;
    }
    }
}

void heapify(phone_call* subscriptions[], int size, int i, int sort_id)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (sort_id == 1) {
        if (l < size && SortCase(sort_id, subscriptions, size, l, largest)) {
            largest = l;
        }
        if (r < size && SortCase(sort_id, subscriptions, size, r, largest)) {
            largest = r;
        }
    }
    else if (sort_id == 2) {
        if (l < size && SortCase(sort_id, subscriptions, size, l, largest)) {
            largest = l;
        }
        if (r < size&& SortCase(sort_id, subscriptions, size, r, largest)) {
            largest = r;
        }
    }

    if (largest != i) {
        phone_call* temp = subscriptions[i];
        subscriptions[i] = subscriptions[largest];
        subscriptions[largest] = temp;
        heapify(subscriptions, size, largest, sort_id);
    }
}

void heapSort(phone_call* subscriptions[], int size, int sort_id)
{
    for (int i = size / 2 - 1; i >= 0; i--) {
        heapify(subscriptions, size, i, sort_id);
    }
    for (int i = size - 1; i > 0; i--) {
        phone_call* temp = subscriptions[0];
        subscriptions[0] = subscriptions[i];
        subscriptions[i] = temp;
        heapify(subscriptions, i, 0, sort_id);
    }
}

int partition(phone_call* arr[], int low, int high, int sort_id, int size) {
    phone_call* pivot = arr[high];
    int i = low;
    for (int j = low; j < high; j++) {
        if (!SortCase(sort_id, arr, size, j, high)) {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[high]);
    return i;
}

void quickSort(phone_call* arr[], int low, int high, int sort_id, int permament_size) {
    if (low < high) {
        int p = partition(arr, low, high, sort_id, permament_size);
        quickSort(arr, low, p - 1, sort_id, permament_size);
        quickSort(arr, p + 1, high, sort_id, permament_size);
    }

}
int main() {
    int sort_id;
    setlocale(LC_ALL, "Russian");
    cout << "Laboratory work #8. GIT\n";
    cout << "Variant #9.telephone conversations\n";
    cout << "Author: Anastasia Nabieva\n";

    phone_call* call[MAX_FILE_ROWS_COUNT];

    int size;
    try { //чтение файла 
        read("data.txt", call, size);
        for (int i = 0; i < size; i++) {
            print_stuff(call, i);
        }
    }
    catch (const char* error) {
        cout << error << '\n';
    }
    string filename = "data.txt";

    bool rpts = true;
    int rpts_value = 0;
    while (rpts == true) {
        cout << "What do you want to do next? " << endl
            << "1. Вывод всех разговоров на мобильных телефонах " << endl
            << "2. Разговоры за Ноябрь 21 " << endl
            << "3. Пирамидой" << endl
            << "4. Быстрая сортировка" << endl
            << "5. Exit " << endl;

        cin >> rpts_value;
        switch (rpts_value)
        {
        case 1:
        {
            only_mobile(call, size);

            break;
        }
        case 2:
        {
            only_november21(call, size);

            break;
        }
        case 3:
        {

            cout << "Критерии сортировки" << endl
                << "1.По убыванию продолжительности разговора" << endl
                << "2. По возрастанию номера телефона, а в рамках одного номера по убыванию стоимости разговора" << endl;
            cin >> sort_id;
            heapSort(call, size, sort_id);
            for (int i = 0; i < size; i++)
            {
                print_stuff(call, i);
            }
            break;
        }
        case 4:
        {

            cout << "Критерии сортировки" << endl
                << "1.По убыванию продолжительности разговора" << endl
                << "2. По возрастанию номера телефона, а в рамках одного номера по убыванию стоимости разговора" << endl;
            cin >> sort_id;
            quickSort(call, 0, size - 1, sort_id, size);
            for (int i = 0; i < size; i++)
            {
                print_stuff(call, i);
            }
            break;
        }
        case 5:
        {
            rpts = false;
            break;
        }

        }
        for (int i = 0; i < size; i++) {
            delete call[i];
        }
        return 0;
    }

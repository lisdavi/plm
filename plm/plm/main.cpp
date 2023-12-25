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
<<<<<<< HEAD
    try { //÷òåíèå ôàéëà 
=======
    try { //Ñ‡Ñ‚ÐµÐ½Ð¸Ðµ Ñ„Ð°Ð¹Ð»Ð° 
>>>>>>> bccea089d03b28eecf52fff9588c51f4a4580466
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
<<<<<<< HEAD
            << "1. Âûâîä âñåõ ðàçãîâîðîâ íà ìîáèëüíûõ òåëåôîíàõ " << endl
            << "2. Ðàçãîâîðû çà Íîÿáðü 21 " << endl
            << "3. Ïèðàìèäîé" << endl
            << "4. Áûñòðàÿ ñîðòèðîâêà" << endl
=======
            << "1. Ð’Ñ‹Ð²Ð¾Ð´ Ð²ÑÐµÑ… Ñ€Ð°Ð·Ð³Ð¾Ð²Ð¾Ñ€Ð¾Ð² Ð½Ð° Ð¼Ð¾Ð±Ð¸Ð»ÑŒÐ½Ñ‹Ñ… Ñ‚ÐµÐ»ÐµÑ„Ð¾Ð½Ð°Ñ… " << endl
            << "2. Ð Ð°Ð·Ð³Ð¾Ð²Ð¾Ñ€Ñ‹ Ð·Ð° ÐÐ¾ÑÐ±Ñ€ÑŒ 21 " << endl
            << "3. ÐŸÐ¸Ñ€Ð°Ð¼Ð¸Ð´Ð¾Ð¹" << endl
            << "4. Ð‘Ñ‹ÑÑ‚Ñ€Ð°Ñ ÑÐ¾Ñ€Ñ‚Ð¸Ñ€Ð¾Ð²ÐºÐ°" << endl
>>>>>>> bccea089d03b28eecf52fff9588c51f4a4580466
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

<<<<<<< HEAD
            cout << "Êðèòåðèè ñîðòèðîâêè" << endl
                << "1.Ïî óáûâàíèþ ïðîäîëæèòåëüíîñòè ðàçãîâîðà" << endl
                << "2. Ïî âîçðàñòàíèþ íîìåðà òåëåôîíà, à â ðàìêàõ îäíîãî íîìåðà ïî óáûâàíèþ ñòîèìîñòè ðàçãîâîðà" << endl;
=======
            cout << "ÐšÑ€Ð¸Ñ‚ÐµÑ€Ð¸Ð¸ ÑÐ¾Ñ€Ñ‚Ð¸Ñ€Ð¾Ð²ÐºÐ¸" << endl
                << "1.ÐŸÐ¾ ÑƒÐ±Ñ‹Ð²Ð°Ð½Ð¸ÑŽ Ð¿Ñ€Ð¾Ð´Ð¾Ð»Ð¶Ð¸Ñ‚ÐµÐ»ÑŒÐ½Ð¾ÑÑ‚Ð¸ Ñ€Ð°Ð·Ð³Ð¾Ð²Ð¾Ñ€Ð°" << endl
                << "2. ÐŸÐ¾ Ð²Ð¾Ð·Ñ€Ð°ÑÑ‚Ð°Ð½Ð¸ÑŽ Ð½Ð¾Ð¼ÐµÑ€Ð° Ñ‚ÐµÐ»ÐµÑ„Ð¾Ð½Ð°, Ð° Ð² Ñ€Ð°Ð¼ÐºÐ°Ñ… Ð¾Ð´Ð½Ð¾Ð³Ð¾ Ð½Ð¾Ð¼ÐµÑ€Ð° Ð¿Ð¾ ÑƒÐ±Ñ‹Ð²Ð°Ð½Ð¸ÑŽ ÑÑ‚Ð¾Ð¸Ð¼Ð¾ÑÑ‚Ð¸ Ñ€Ð°Ð·Ð³Ð¾Ð²Ð¾Ñ€Ð°" << endl;
>>>>>>> bccea089d03b28eecf52fff9588c51f4a4580466
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

<<<<<<< HEAD
            cout << "Êðèòåðèè ñîðòèðîâêè" << endl
                << "1.Ïî óáûâàíèþ ïðîäîëæèòåëüíîñòè ðàçãîâîðà" << endl
                << "2. Ïî âîçðàñòàíèþ íîìåðà òåëåôîíà, à â ðàìêàõ îäíîãî íîìåðà ïî óáûâàíèþ ñòîèìîñòè ðàçãîâîðà" << endl;
=======
            cout << "ÐšÑ€Ð¸Ñ‚ÐµÑ€Ð¸Ð¸ ÑÐ¾Ñ€Ñ‚Ð¸Ñ€Ð¾Ð²ÐºÐ¸" << endl
                << "1.ÐŸÐ¾ ÑƒÐ±Ñ‹Ð²Ð°Ð½Ð¸ÑŽ Ð¿Ñ€Ð¾Ð´Ð¾Ð»Ð¶Ð¸Ñ‚ÐµÐ»ÑŒÐ½Ð¾ÑÑ‚Ð¸ Ñ€Ð°Ð·Ð³Ð¾Ð²Ð¾Ñ€Ð°" << endl
                << "2. ÐŸÐ¾ Ð²Ð¾Ð·Ñ€Ð°ÑÑ‚Ð°Ð½Ð¸ÑŽ Ð½Ð¾Ð¼ÐµÑ€Ð° Ñ‚ÐµÐ»ÐµÑ„Ð¾Ð½Ð°, Ð° Ð² Ñ€Ð°Ð¼ÐºÐ°Ñ… Ð¾Ð´Ð½Ð¾Ð³Ð¾ Ð½Ð¾Ð¼ÐµÑ€Ð° Ð¿Ð¾ ÑƒÐ±Ñ‹Ð²Ð°Ð½Ð¸ÑŽ ÑÑ‚Ð¾Ð¸Ð¼Ð¾ÑÑ‚Ð¸ Ñ€Ð°Ð·Ð³Ð¾Ð²Ð¾Ñ€Ð°" << endl;
>>>>>>> bccea089d03b28eecf52fff9588c51f4a4580466
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
<<<<<<< HEAD
    }
=======
    }
>>>>>>> bccea089d03b28eecf52fff9588c51f4a4580466

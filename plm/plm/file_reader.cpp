#include "file_reader.h"
#include "tele_cons.h"
#include "const.h"
#include <fstream>
#include <cstring>



date convert_date(char* str)
{
    date result;
    char* context = NULL;
    char* str_number = strtok_s(str, ".", &context);
    result.day = atoi(str_number);
    str_number = strtok_s(NULL, ".", &context);
    result.month = atoi(str_number);
    str_number = strtok_s(NULL, " ", &context);
    result.year = atoi(str_number);
    return result;
}

times convert_time(char* str)
{
    times result;
    char* context = NULL;
    char* str_number = strtok_s(str, ":", &context);
    result.hours = atoi(str_number);
    str_number = strtok_s(NULL, ":", &context);
    result.minutes = atoi(str_number);
    str_number = strtok_s(NULL, " ", &context);
    result.seconds = atoi(str_number);
    return result;
}
//принимает аргумент,просматривает его и переводит в целочисленный тип 

void read(const char* file_name, phone_call* array[], int& size)
{

    std::ifstream file(file_name);
    if (file.is_open())
    {
        size = 0;
        char tmp_buffer[MAX_STRING_SIZE];
        while (!file.eof())  //считывает содержимое файла до тех пор, пока не будет достигнут конец 
        {
            phone_call* item = new phone_call;  //динамически выделяем память
            file >> item->phone_number;
            file >> tmp_buffer;
            item->call_date = convert_date(tmp_buffer);
            file >> tmp_buffer;
            item->call_time = convert_time(tmp_buffer);
            file >> tmp_buffer;
            item->duration = convert_time(tmp_buffer);
            file >> item->tariff;
            file >> item->cost;
            array[size++] = item;
        }
        file.close();
    } //считываем данные из файла ,присваем результат  convert_date и добавляем указатель на объект в массив

    else
    {
        throw "Ошибка открытия файла";
    }
}




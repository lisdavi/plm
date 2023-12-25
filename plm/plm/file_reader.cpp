<<<<<<< HEAD
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



=======
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
//РїСЂРёРЅРёРјР°РµС‚ Р°СЂРіСѓРјРµРЅС‚,РїСЂРѕСЃРјР°С‚СЂРёРІР°РµС‚ РµРіРѕ Рё РїРµСЂРµРІРѕРґРёС‚ РІ С†РµР»РѕС‡РёСЃР»РµРЅРЅС‹Р№ С‚РёРї 

void read(const char* file_name, phone_call* array[], int& size)
{

    std::ifstream file(file_name);
    if (file.is_open())
    {
        size = 0;
        char tmp_buffer[MAX_STRING_SIZE];
        while (!file.eof())  //СЃС‡РёС‚С‹РІР°РµС‚ СЃРѕРґРµСЂР¶РёРјРѕРµ С„Р°Р№Р»Р° РґРѕ С‚РµС… РїРѕСЂ, РїРѕРєР° РЅРµ Р±СѓРґРµС‚ РґРѕСЃС‚РёРіРЅСѓС‚ РєРѕРЅРµС† 
        {
            phone_call* item = new phone_call;  //РґРёРЅР°РјРёС‡РµСЃРєРё РІС‹РґРµР»СЏРµРј РїР°РјСЏС‚СЊ
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
    } //СЃС‡РёС‚С‹РІР°РµРј РґР°РЅРЅС‹Рµ РёР· С„Р°Р№Р»Р° ,РїСЂРёСЃРІР°РµРј СЂРµР·СѓР»СЊС‚Р°С‚  convert_date Рё РґРѕР±Р°РІР»СЏРµРј СѓРєР°Р·Р°С‚РµР»СЊ РЅР° РѕР±СЉРµРєС‚ РІ РјР°СЃСЃРёРІ

    else
    {
        throw "РћС€РёР±РєР° РѕС‚РєСЂС‹С‚РёСЏ С„Р°Р№Р»Р°";
    }
}



>>>>>>> bccea089d03b28eecf52fff9588c51f4a4580466

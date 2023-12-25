#pragma once
#pragma once
#include "const.h"
#ifndef PHONE_CALL_H
#define PHONE_CALL_H



struct date 
{
    int day;
    int month;
    int year;
};

struct times
{
    int hours;
    int minutes;
    int seconds;
};
struct phone_call
{
    int phone_number;
    times call_time;
    date call_date;
    times duration;
    char tariff[TARIFF_SIZE];
    float cost;
};

#endif

#include "tele_cons.h"
#include "processing.h"
#include <iostream>
using namespace std;
float Cost(phone_call* subscriptions[], int size)
{
    float Costs = 0;
    float Costssum = 0;


    for (int i = 0;i < size;i++)
    {
        float temp1 = subscriptions[i]->cost;
        float temp2 = subscriptions[i]->duration.seconds + (subscriptions[i]->duration.minutes) * 60 + (subscriptions[i]->duration.hours) * 3600;


        Costssum += temp1 / temp2;
    }
    Costs = Costssum / size;

    cout << "—редн€€ стоимость одной секунды разговора: " << Costs << endl;

    return Costs;
}
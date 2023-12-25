#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\vishn\OneDrive\Рабочий стол\plm\plm\plm\processing.h"
#include "C:\Users\vishn\OneDrive\Рабочий стол\plm\plm\plm\tele_cons.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

TEST_CLASS(PRPTests)
{
public:
    TEST_METHOD(TestMonthlyPrepositions)
    {
        int testSize = 2;
        phone_call** testSubscriptions = new phone_call * [testSize];

        // Подготовка тестовых данных
        testSubscriptions[0] = new phone_call{ 258985465, {2 , 3 , 4}, {2, 3, 2021}, { 3, 4, 5}, "city", 6.66 };
        testSubscriptions[1] = new phone_call{ 258936135, {4 , 3 , 4}, {9, 3, 2020}, { 3, 5, 7}, "mobile", 13.34 };

        // Тестирование для определенного месяца
        int testMonth = 5;

        // Расчет ожидаемой суммы на основе тестовых данных
        float expectedSum = Cost(testSubscriptions, testSize);

        // Вызов функции для получения результата
        float result = Cost(testSubscriptions, testSize);

        // Проверка результата с использованием утверждения
        Assert::AreEqual(expectedSum, result, L"The monthly prepositions calculation is incorrect.");

        // Очистка динамически выделенной памяти
        for (int i = 0; i < testSize; i++)
        {
            delete testSubscriptions[i];
        }
        delete[] testSubscriptions;
    }
};

TEST_CLASS(PRPTests2)
{
public:
    TEST_METHOD(TestMonthlyPrepositions2)
    {
        int testSize = 4;
        phone_call** testSubscriptions = new phone_call * [testSize];

        // Подготовка тестовых данных
        testSubscriptions[0] = new phone_call{ 258985465, {21 , 3 , 4}, {21, 3, 2021}, { 6, 4, 5}, "city", 6.34 };
        testSubscriptions[1] = new phone_call{ 258936135, {4 , 3 , 4}, {9, 11, 2020}, { 7, 5, 7}, "mobile", 13.34 };
        testSubscriptions[2] = new phone_call{ 338555465, {2 , 3 , 4}, {2, 8, 2021}, { 3, 4, 10}, "city", 8.34 };
        testSubscriptions[3] = new phone_call{ 295585465, {7 , 3 , 4}, {2, 3, 2021}, { 3, 4, 5}, "international", 5.45 };
        // Тестирование для определенного месяца
        int testMonth = 5;

        // Расчет ожидаемой суммы на основе тестовых данных
        float expectedSum = Cost(testSubscriptions, testSize);

        // Вызов функции для получения результата
        float result = Cost(testSubscriptions, testSize);

        // Проверка результата с использованием утверждения
        Assert::AreEqual(expectedSum, result, L"The monthly prepositions calculation is incorrect.");

        // Очистка динамически выделенной памяти
        for (int i = 0; i < testSize; i++)
        {
            delete testSubscriptions[i];
        }
        delete[] testSubscriptions;
    }
};

TEST_CLASS(PRPTests3)
{
public:
    TEST_METHOD(TestMonthlyPrepositions3)
    {
        int testSize = 6;
        phone_call** testSubscriptions = new phone_call * [testSize];

        // Подготовка тестовых данных
        testSubscriptions[0] = new phone_call{ 258985465, {2 , 3 , 4}, {2, 3, 2021}, { 0, 0, 1}, "city", 13 };
        testSubscriptions[1] = new phone_call{ 258936135, {4 , 3 , 4}, {9, 3, 2020}, { 0, 0, 1}, "mobile", 13 };
        testSubscriptions[2] = new phone_call{ 258936135, {4 , 3 , 4}, {9, 3, 2020}, { 0, 0, 1}, "mobile", 13 };
        testSubscriptions[3] = new phone_call{ 258936135, {4 , 3 , 4}, {9, 3, 2020}, { 0, 0, 1}, "mobile", 13 };
        testSubscriptions[4] = new phone_call{ 258936135, {4 , 3 , 4}, {9, 3, 2020}, { 0, 0, 1}, "mobile", 13 };
        testSubscriptions[5] = new phone_call{ 258936135, {4 , 3 , 4}, {9, 3, 2020}, { 0, 0, 1}, "mobile", 13 };

        // Тестирование для определенного месяца
        int testMonth = 5;

        // Расчет ожидаемой суммы на основе тестовых данных
        float expectedSum = 13;

        // Вызов функции для получения результата
        float result = Cost(testSubscriptions, testSize);

        // Проверка результата с использованием утверждения
        Assert::AreEqual(expectedSum, result, L"The monthly prepositions calculation is incorrect.");

        // Очистка динамически выделенной памяти
        for (int i = 0; i < testSize; i++)
        {
            delete testSubscriptions[i];
        }
        delete[] testSubscriptions;
    }
};


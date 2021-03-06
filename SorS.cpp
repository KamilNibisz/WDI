// SorS.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include "pch.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    int price;
    int choice;
    bool change;
    int z;
    double winR;
    double l = 1;
    double win = 0;

    while (true)
    {
        int doors[3] = {0,0,0};
        int t[2] = {0,0};
        price = rand() % 3;
        doors[price] = 2;
        std::cout << "1   " << "2   " << "3" << std::endl;

        while(true)
        {
            std::cout << "Wybierz drzwi: ";
            std::cin >> choice;
            if (choice > 3 || choice < 1)
                std::cout << "Nie ma takich drzwi" << std::endl;
            else break;
        }

        --choice;

        if (choice == price)
        {
            int j = 0;
            for (int i = 0; i < 3; ++i)
            {
                if (doors[i] == 0)
                {
                    t[j] = i;
                    ++j;
                }
            }
            z = rand() % 2;
            int tmp = t[z];
            doors[tmp] = -1;
        }
        else
        {
            for (int i = 0; i < 3; ++i)
            {
                if (i != choice && doors[i] == 0)
                    doors[i] = -1;
            }
        }

        for (int i = 0; i < 3; ++i)
        {
            if (doors[i] == -1)
            {
                std::cout << "Goat!   ";
            }
            else
            {
                std::cout << i + 1 << "   ";
            }
        }

        std::cout << std::endl;

        std::cout << "Czy chcesz zmienic drzwi(Tak - 1, Nie - 0): ";
        std::cin >> change;
        std::cout << std::endl;
        for (int i = 0; i < 3; ++i)
        {
            if (doors[i] == 2)
                std::cout << "Car!   ";
            else
                std::cout << "Goat!   ";
        }
        std::cout << std::endl;
        bool fwin = (!change && choice == price) || (change && choice != price);
        if (fwin)
        {
            std::cout << "Wygrales!!!       win rate: ";
            win += 1;
            std::cout << win / l * 100 << "%" << std::endl;
        }
        else
        {
            std::cout << "Przegrales!!!     win rate: ";
            std::cout << win / l * 100 << "%" << std::endl;
        }

        l += 1;
        std::cout << std::endl;
    }

    return 0;
}


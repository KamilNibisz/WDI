// MaszynaT.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//
// ConsoleApplication6.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include "pch.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include<string>

using namespace std;

int main()
{
    vector<string> commands;
    string command;
    cout << "Enter commands (example A0B1L):" << endl;
    do {
        getline(cin, command);
        commands.push_back(command);

    } while (!command.empty());

    string data;
    cout << "Enter data from the tape:" << endl;
    cin >> data;

    int position;
    cout << "Enter head position:" << endl;
    cin >> position;

    char state;
    cout << "Enter initial state:" << endl;
    cin >> state;

    vector<string>::const_iterator iterator;
    while (true)
    {
        cout << data << endl;
        for (int i = 0; i < position; ++i)
            cout << ' ';
        cout << '^' << endl;

        iterator = find_if(commands.begin(), commands.end(), [&](const string& c) {
            return c[0] == data[position] && c[1] == state;
        });

        if (iterator != commands.end()) {
            data[position] = (*iterator)[2];
            state = (*iterator)[3];
            position += ((*iterator)[4] == 'l' || (*iterator)[4] == 'L') ? -1 : 1;
        }
        else break;
    }

    return 0;
}
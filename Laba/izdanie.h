#pragma once
#pragma once
#include <iostream>
#include <string>
#include <string.h>
using namespace std;
#define N 5

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

class Izdanie {
public:
    string FIO;
    virtual void set() {}
    virtual void show() = 0;
};

class Poet : public Izdanie {
public:
    int year_of_birth;
    int year_of_death;
    int n;
    string* mas = new string[N];
    Poet() {}
    Poet(const Poet& p)
    {
        FIO = p.FIO;
        year_of_birth = p.year_of_birth;
        year_of_death = p.year_of_death;
        n = p.n;
        for (int i = 0; i < n; i++) {
            mas[i] = p.mas[i];
        }
    }

    void choose_FIO() {
        string new_FIO;
        cout << "Enter new FIO in format Ivanov_I_I: ";
        cin >> new_FIO;
        FIO = new_FIO;
    }

    void choose_years_of_life() {
        int new_y_o_b, new_y_o_d;
        cout << "Enter new year of birth: ";
        cin >> new_y_o_b;
        cout << "Enter new year of death: ";
        cin >> new_y_o_d;
        year_of_birth = new_y_o_b;
        year_of_death = new_y_o_d;
    }

    void set_poet(int a1, int a2, string* a3, int a4, string a5) {
        FIO = a5;
        year_of_birth = a1;
        year_of_death = a2;
        n = a4;
        for (int i = 0; i < a4; i++) {
            mas[i] = a3[i];
        }
    }

    void show_FIO() {
        cout << FIO;
    }

    void show() override {
        SetConsoleTextAttribute(hConsole, 1);
        cout << "Poet" << endl;
        cout << "FIO: " << FIO << endl;
        cout << "Years of life: " << year_of_birth << " - " << year_of_death << endl;
        cout << "Poems: ";
        for (int i = 0; i < n; i++) {
            cout << mas[i] << endl;
        }
        SetConsoleTextAttribute(hConsole, 15);
    }

    int operator + (int numb) const {
        return year_of_birth + numb;
    }
};

class Roman : public Izdanie {
public:
    int year_of_birth;
    int year_of_death;
    string* mas = new string[N];
    int n;
    string inf;
    Roman() {}

    void choose_FIO() {
        string new_FIO;
        "Enter new FIO in format Ivanov_I_I: ";
        cin >> new_FIO;
        FIO = new_FIO;
    }

    void choose_years_of_life() {
        int new_y_o_b, new_y_o_d;
        cout << "Enter new year of birth: ";
        cin >> new_y_o_b;
        cout << "Enter new year of death: ";
        cin >> new_y_o_d;
        year_of_birth = new_y_o_b;
        year_of_death = new_y_o_d;
    }

    Roman(const Roman& p)
    {
        FIO = p.FIO;
        year_of_birth = p.year_of_birth;
        year_of_death = p.year_of_death;
        n = p.n;
        for (int i = 0; i < n; i++) {
            mas[i] = p.mas[i];
        }
        inf = p.inf;
    }
    void set_roman(int a1, int a2, string* a3, int a4, string a5, string a6) {
        FIO = a6;
        year_of_birth = a1;
        year_of_death = a2;
        n = a4;
        for (int i = 0; i < a4; i++) {
            mas[i] = a3[i];
        }
        inf = a5;
    }

    void show_FIO() {
        cout << FIO;
    }

    void show() override {
        SetConsoleTextAttribute(hConsole, 5);
        cout << "Roman" << endl;
        cout << "FIO: " << FIO << endl;
        cout << "Years of life: " << year_of_birth << " - " << year_of_death << endl;
        cout << "Poems: ";
        for (int i = 0; i < n; i++) {
            cout << mas[i] << endl;
        }
        cout << "Information: " << inf << endl;
        SetConsoleTextAttribute(hConsole, 15);
    }

    int operator + (int numb) const {
        return year_of_birth + numb;
    }
};

class Fantast : public Izdanie {
public:
    string* mas = new string[N];
    int* mmas = new int[N];
    int n;
    Fantast() {}
    Fantast(const Fantast& p)
    {
        FIO = p.FIO;
        n = p.n;
        for (int i = 0; i < n; i++) {
            mas[i] = p.mas[i];
            mmas[i] = p.mmas[i];
        }
    }

    void choose_FIO() {
        string new_FIO;
        "Enter new FIO in format Ivanov_I_I: ";
        cin >> new_FIO;
        FIO = new_FIO;
    }

    void set_fantast(int a1, int* a2, string* a3, string a4) {
        FIO = a4;
        n = a1;
        for (int i = 0; i < a1; i++) {
            mas[i] = a3[i];
        }
        for (int i = 0; i < a1; i++) {
            mmas[i] = a2[i];
        }
    }

    void show_FIO() {
        cout << FIO;
    }

    void show() override {
        SetConsoleTextAttribute(hConsole, 3);
        cout << "Fantast" << endl;
        cout << "FIO: " << FIO << endl;
        cout << "Poems: " << endl;
        for (int i = 0; i < n; i++) {
            cout << mas[i];
            if (mmas[i] == 0) {
                cout << " hasn't got a film" << endl;
            }
            else {
                cout << " has got a film" << endl;
            }
        }
        SetConsoleTextAttribute(hConsole, 15);
    }
};

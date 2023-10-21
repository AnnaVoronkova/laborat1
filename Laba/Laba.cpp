#include <iostream>
#include <Windows.h>
#include "izdanie.h"
#include "Keeper.h"
#include <fstream>
#define N 10



int main()
{
    int kodif;
    string fio, inff;
    int y_o_b, y_o_d, nn;
    string* maas = new string[N];
    int* maas1 = new int[N];
    Keeper array1;
    int l = 0;
    ifstream file1("1.txt");

    int k = 1;
    while (k != 0) {
        cout << "Enter '1' if you want to add an author" << endl;
        cout << "Enter '2' if you want to delete an author" << endl;
        cout << "Enter '3' if you want to add authors from file" << endl;
        cout << "Enter '4' if you want to show authors" << endl;
        cout << "Enter '5' if you want to put authors into the file" << endl;
        cout << "Enter '6' if you want to max the year of death" << endl;
        cout << "Enter '7' if you want to add new data" << endl;
        cout << "Enter '0' if you end working" << endl;
        cin >> k;
        if (k == 1) {
            int k1;
            cout << "Enter '1' if you want to add Poet" << endl;
            cout << "Enter '2' if you want to add Roman" << endl;
            cout << "Enter '3' if you want to add Fantast" << endl;
            cin >> k1;
            if (k1 == 1) {
                cout << "Enter FIO in format Ivanov_I_I: ";
                cin >> fio;
                cout << "Enter the year of birth: ";
                cin >> y_o_b;
                cout << "Enter the year of death: ";
                cin >> y_o_d;
                cout << "Enter number of proezvedeniy: ";
                cin >> nn;
                for (int i = 0; i < nn; i++) {
                    cout << "Enter the name of the proizvedeniye: ";
                    cin >> maas[i];
                }
                Poet poet1;
                poet1.set_poet(y_o_b, y_o_d, maas, nn, fio);
                array1.add_Poet(poet1);
            }
            if (k1 == 2) {
                cout << "Enter FIO in format Ivanov_I_I: ";
                cin >> fio;
                cout << "Enter the year of birth: ";
                cin >> y_o_b;
                cout << "Enter the year of death: ";
                cin >> y_o_d;
                cout << "Enter number of proezvedeniy: ";
                cin >> nn;
                for (int i = 0; i < nn; i++) {
                    cout << "Enter the name of the proizvedeniye: ";
                    cin >> maas[i];
                }
                cout << "Enter some information: ";
                cin >> inff;
                Roman roman;
                roman.set_roman(y_o_b, y_o_d, maas, nn, inff, fio);
                array1.add_Roman(roman);
            }
            if (k1 == 3) {
                cout << "Enter FIO in format Ivanov_I_I: ";
                cin >> fio;
                cout << "Enter number of proezvedeniy: ";
                cin >> nn;
                for (int i = 0; i < nn; i++) {
                    cout << "Enter the name of the proizvedeniye: ";
                    cin >> maas[i];
                    cout << "Enter '1' if this poem has a film" << endl;
                    cout << "Enter '2' if this poem hasn't a film" << endl;
                    int t;
                    cin >> t;
                    if (t == 1) {
                        maas1[i] = 1;
                    }
                    else {
                        maas1[i] = 0;
                    }
                }
                cout << "Enter some information: ";
                cin >> inff;
                Fantast fantast;
                fantast.set_fantast(nn, maas1, maas, fio);
                array1.add_Fantast(fantast);
            }

        }
        if (k == 7) {
            cout << "Enter '1' if you want to change a poet" << endl;
            cout << "Enter '2' if you want to change a roman" << endl;
            cout << "Enter '3' if you want to change a fantast" << endl;
            int q1 = 0;
            cin >> q1;
            if (q1 == 0) {
                // ghklojfg
            }
        }
        if (k == 2) {
            cout << "Enter '1' if you want to delete poet" << endl;
            cout << "Enter '2' if you want to delete roman" << endl;
            cout << "Enter '3' if you want to delete fantast" << endl;
            int q;
            cin >> q;
            if (q == 1) {
                array1.delete_Poet();
            }
            if (q == 2) {
                array1.delete_Roman();
            }
            if (q == 2) {
                array1.delete_Fantast();
            }
        }
        if (k == 3) {
            file1 >> l;
            if (l != 0) {
                for (int i = 0; i < l; i++) {
                    file1 >> kodif;
                    if (kodif == 1) {
                        file1 >> fio >> y_o_b >> y_o_d >> nn;
                        for (int j = 0; j < nn; j++) {
                            file1 >> maas[j];
                        }
                        Poet poet1;
                        poet1.set_poet(y_o_b, y_o_d, maas, nn, fio);
                        array1.add_Poet(poet1);
                    }
                    if (kodif == 2) {
                        file1 >> fio >> y_o_b >> y_o_d >> nn;
                        for (int j = 0; j < nn; j++) {
                            file1 >> maas[j];
                        }
                        file1 >> inff;
                        Roman roman1;
                        roman1.set_roman(y_o_b, y_o_d, maas, nn, inff, fio);
                        array1.add_Roman(roman1);
                    }
                    if (kodif == 3) {
                        file1 >> fio >> nn;
                        for (int j = 0; j < nn; j++) {
                            file1 >> maas[i];
                        }
                        Fantast fantast1;
                        fantast1.set_fantast(nn, maas1, maas, fio);
                        array1.add_Fantast(fantast1);
                    }
                }
            }
        }
        if (k == 6) {
            for (int i = 0; i < array1.n; i++) {
                cout << "Enter " << i << " if you want to use " << array1.mas[i].FIO << endl;
            }
            for (int i = 0; i < array1.n1; i++) {
                cout << "Enter " << i + array1.n << " if you want to use " << array1.mas1[i].FIO << endl;
            }
            int count, years;
            cin >> count;
            cout << "Enter years you want to add: ";
            cin >> years;
            if (count > array1.n) {
                cout << array1.mas1[count - array1.n] + years;
            }
            else {
                cout << array1.mas[count] + years;
            }
        }
        if (k == 4) {
            int Sum = array1.n + array1.n1 + array1.n2;
            for (int i = 0; i < array1.n; i++) {
                array1.mas[i].show();
            }
            for (int i = 0; i < array1.n1; i++) {
                array1.mas1[i].show();
            }
            for (int i = 0; i < array1.n2; i++) {
                array1.mas2[i].show();
            }
        }
        if (k == 5) {
            file1.close();
            ofstream file2;
            file2.open("1.txt");
            int Sum = array1.n + array1.n1 + array1.n2;
            file2 << Sum << endl;
            for (int i = 0; i < array1.n; i++) {
                file2 << 1 << endl;
                file2 << array1.mas[i].FIO << endl;
                file2 << array1.mas[i].year_of_birth << endl;
                file2 << array1.mas[i].year_of_death << endl;
                file2 << array1.mas[i].n << endl;
                for (int j = 0; j < array1.mas[i].n; j++) {
                    file2 << array1.mas[i].mas[j] << endl;
                }
            }
            for (int i = 0; i < array1.n1; i++) {
                file2 << 2 << endl;
                file2 << array1.mas1[i].FIO << endl;
                file2 << array1.mas1[i].year_of_birth << endl;
                file2 << array1.mas1[i].year_of_death << endl;
                file2 << array1.mas1[i].n << endl;
                for (int j = 0; j < array1.mas1[i].n; j++) {
                    file2 << array1.mas1[i].mas[j] << endl;
                }
                file2 << array1.mas1[i].inf << endl;
            }
            for (int i = 0; i < array1.n2; i++) {
                file2 << 3 << endl;
                file2 << array1.mas2[i].FIO << endl;
                file2 << array1.mas2[i].n << endl;
                for (int j = 0; j < array1.mas2[i].n; j++) {
                    file2 << array1.mas2[i].mas[j] << endl;
                }
                for (int j = 0; j < array1.mas2[i].n; j++) {
                    file2 << array1.mas2[i].mmas[j] << endl;
                }
            }
        }
    }
}

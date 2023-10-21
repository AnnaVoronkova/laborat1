#pragma once
#pragma once
#include "izdanie.h"

class Keeper {
public:
	int n = 0;
	int n1 = 0;
	int n2 = 0;
	Poet mas[N];
	Roman mas1[N];
	Fantast mas2[N];
	Keeper() {}
	void add_Poet(Poet k1) {
		mas[n] = k1;
		n++;
	}

	void add_Roman(Roman k2) {
		mas1[n1] = k2;
		n1++;
	}

	void add_Fantast(Fantast k3) {
		mas2[n2] = k3;
		n2++;
	}
	void delete_Poet() {
		for (int i = 0; i < n; i++) {
			cout << "Enter " << i << " if you want to delete ";
			mas[i].show_FIO();
			cout << endl;
		}
		int t;
		cin >> t;
		for (int i = t; i < n - 1; i++) {
			mas[i] = mas[i + 1];
		}
		n--;
	}
	void delete_Roman() {
		for (int i = 0; i < n1; i++) {
			cout << "Enter " << i << " if you want to delete ";
			mas1[i].show_FIO();
			cout << endl;
		}
		int t;
		cin >> t;
		for (int i = t; i < n1 - 1; i++) {
			mas1[i] = mas1[i + 1];
		}
		n1--;
	} //
	void delete_Fantast() {
		for (int i = 0; i < n2; i++) {
			cout << "Enter " << i << " if you want to delete ";
			mas2[i].show_FIO();
			cout << endl;
		}
		int t;
		cin >> t;
		for (int i = t - 1; i < n2 - 1; i++) {
			mas2[i] = mas2[i + 1];
		}
		n2--;
	}
};
#include <iostream>
#include <string>
#include <Windows.h>
#include <vector>
#include <algorithm>
using namespace std;

int Max(string a, string b, string c, string d) { //поиск максимального количества символов в строке, для того чтобы построить
	vector <int> SIze;							//верх и низ рамки
	SIze.push_back(a.size());
	SIze.push_back(b.size());
	SIze.push_back(c.size());
	SIze.push_back(d.size());
	SIze.push_back(size("Лабораторная работа № 1"));
	SIze.push_back(size("Выполнил(а): "));
	SIze.push_back(size("Номер группы: "));
	auto Max = max_element(SIze.begin(), SIze.end());
	int result = a.size() + b.size() + c.size() + d.size() + *Max;
	return result;
}
void horizon(int a) {  //построение горизонтальной части рамки
	for (int i = 0; i < a; i++) {
		cout << "*";
	}
	cout << endl;
}


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string Name, Familia, Middle, Number;
	cout << "Введите имя студента:";
	cin >> Name;
	cout << "Введите фамилию студента:";
	cin >> Familia;
	cout << "Введите отчество студента:";
	cin >> Middle;
	cout << "Введите номер группы:";
	cin >> Number;
	int t = Max(Name, Familia, Middle, Number);
	horizon(t);
	cout << "*   " << "Лабораторная работа № 1";
	for (int i = 0; i < t - size("Лабораторная работа № 1") - 4; i++) { //построение правого конца рамки 1 - ой строки
		cout << " ";
	}
	cout << "*" << endl << "*   " << "Выполнил(а): " << Familia << " " << Name << " " << Middle;
	for (int i = 0; i < t - size("Выполнил(а): ") - size(Name) - size(Familia) - size(Middle) - 6; i++) {  //построение правого конца рамки 2 - ой строки
		cout << " ";
	}
	cout << "*" << endl << "*   " << "Номер группы: " << Number;
	for (int i = 0; i < t - size("Номер группы: ") - size(Number) - 4; i++) {  //построение правого конца рамки 3 - ей строки
		cout << " ";
	}
	cout << "*" << endl;
	horizon(t);
	return 0;
}


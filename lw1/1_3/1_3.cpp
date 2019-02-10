#include "pch.h"
#include <iostream>
#include <vector>
#include <random>
#include <iterator>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	random_device rd;
	mt19937 g(rd());
	vector<size_t> v = { 7, 1, 9, 4, 5, 0, 2, 3, 8, 6 };
	char again;

	cout << "До перемешивания:    ";
	copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
	do
	{
		cout << endl << "После перемешивания: ";
		shuffle(v.begin(), v.end(), g);
		copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
		do
		{
			cout << endl << "Ещё раз?(y/n): ";
			cin >> again;
		} while (again != 'y' && again != 'n');
	} while (again == 'y');

	return 0;
}

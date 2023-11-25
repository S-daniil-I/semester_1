//Вводится последовательность из n вещественных чисел.Найти порядковый
//номер того из них, которое наиболее близко к какому - либо целому.
#include <iostream>
#include <math.h>

using namespace std;
int main()
{
	setlocale(LC_ALL, "RU");
	int n,index=0;
	double comparison_number=1;
	double number;
	int integer_part = 0;
	cout << "Введите количество элементов:";
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cout << "Введите " << i << "-e число: ";
			cin >> number;
			integer_part = round(number);
			if (abs(number - integer_part) < comparison_number) {
				index = i;
				comparison_number = abs(number - integer_part);
			}
	}
	cout <<"Номер элемента: " << index;
	return 0;
	
}
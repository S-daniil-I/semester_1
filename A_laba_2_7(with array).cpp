/*Вводится последовательность из n вещественных чисел.Найти порядковый
номер того из них, которое наиболее близко к какому - либо целому.*/
#include <iostream>
#include <math.h>

using namespace std;

int main() {
	setlocale(LC_ALL, "RU");
	double  intpart, n, fractional,min=1;
	int i,  k = 0;
	cout << "Введите количество чисел:";
	cin >> n;
	double* array = new double[n];
	for (i = 0; i < n; i++) {
		cout << "Element " << i+1 << ": ";
		cin >> array[i]; cout << endl;
		fractional = modf(array[i], &intpart);
		array[i] = fractional;
	}
	min = array[0];
	for (i = 0; i < n; i++) {
		
		if (abs(0.5 - min) < abs(0.5 - array[i])) {
			min = array[i];
			k = i;
		}
	}
	cout << "Номер элемента: " << k+1 << endl;
 	return 0;
}
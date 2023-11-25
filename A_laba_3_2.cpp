//Найти все такие числа k, что k - я строка совпадает с k - м столбцом.Найти
//наибольший элемент главной диагонали матрицы и вывести на печать строку, в
//которой он находится.

#include <iostream>
#include <iomanip>
#include <math.h>
#include <time.h>

using namespace std;
int main()
{
    setlocale(LC_ALL, "Ru");
    int a, max, count = 0, n = 0;
    const int N = 4;
    int arr[N][N]{ {10,2,3,5},
                   {3,9,5,4},
                   {5,5,5,7},
                   {5,4,7,5}};;

    enum ch { const_numb, user_numb, rand_numb };

    cout << "Виды инициализации\n\n";
    cout << const_numb << " - Постоянные значения\n";
    cout << user_numb << " - Ввод своих значений\n";
    cout << rand_numb << " - Случайные значения\n\n";

    ch choice = const_numb;
    cout << "Ваш выбор: ";
    {
        int temp = 0;
        cin >> temp;
        choice = ch(temp);
    }

    switch (choice)
    {
    case const_numb: { 
       
        break; }
    case user_numb: {
        cout << "Введите " << N * N << " элементов матрицы! \n";
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout << "Введите элементы матрицы: ";
                cin >> arr[i][j];
            }
        }
        break; }
    case rand_numb: {
        srand(time(nullptr));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                arr[i][j] = rand() % 10;
            }
        }
        break; }
    default:
        cout << "Что-то пошло не так\n";
        break;
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << setw(3) << arr[i][j];
        cout << endl;
    }
    max = arr[0][0];
    int k = 0;
    for (int i = 0; i < N; i++) {
        if (arr[i][i] > max) {
            max = arr[i][i];
            k = i;
        }
    }
    cout << "Максимальный элемент равен:" << max << " " << ", находится на " << k + 1 << "-ой строке \n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (arr[i][j] == arr[j][i])
                count++;
            if (count == N) {
                cout << i + 1 << " " << "строка совпдает с " << j + 1 << " cтолбцом";
                n++;
            }
        }
        count = 0;
    }
    if (n == 0)
        cout << "Совпадений не найдено";
    return 0;
}

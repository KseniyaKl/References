//Обращение к указателю и ссылки
#include <iostream>
using namespace std;

int mx[10][2];

template <typename T>
void show_arr(T arr[], const int length) {
	cout << '[';
	for (int i = 0; i < length; i++)
		cout << arr[i] << ", ";
	cout << "\b\b]\n";
}

void my_swap(int num1, int num2) {
	int tmp = num1;
	num1 = num2;
	num2 = tmp;
}
void pswap(int* pnum1, int* pnum2) {
	int tmp = *pnum1;
	*pnum1 = *pnum2;
	*pnum2 = tmp;
}
template <typename T>
void refswap(T &refnum1, T &refnum2) {
	T tmp = refnum1;
	refnum1 = refnum2;
	refnum2 = tmp;
}

int& func(int index) {
	return mx[index][1];
}
template <typename T>
T &ref_max(T arr[], const int length) {
	T tmp = 0;
	for (int i = 1; i < length; i++)
		if (arr[i] > arr[tmp])
			tmp = i;
	return arr[tmp];
}
template <typename T>
void two_var(T &num1, T &num2);
template <typename T1, typename T2>
void copy_arr(T1 arr1[], const int length1, T2 arr2[], const int length2);
int main() {
	setlocale(LC_ALL, "Russian");
	int n = 10, m = 15;

	//int* pn;
	//Ошибка при обращении к неинициализированному указателю
	//cout << pn << endl;


	//Нейтральные указатели
	
	//Первый способ

	/*pn = 0;

	pn = &n;

	if (pn)
		cout << *pn << endl;// нейтральный указатель
	else cout << "Указатель не инициализирован\n";*/

	//Второй способ
	
	//pn = NULL; // абсолютно то же самое
	// отдельный потому что понятнее что обращение к указателю

	//Третий способ

	/*pn = nullptr; // отдельный вид данных, не является числом, указывает на нейтральную территорию оперативной памяти
	if (pn == nullptr)
		cout << "Указатель не инициализирован\n";
	else 
		cout << pn << endl;*/

	//Указатель на константу. Нельзя менять значение объекта, используя разыменование указателя
	/*int const* pn;
	pn = &n;
	//*pn = 5; //ошибка// через указатель нельзя поменять значение переменной
	*/
	
	//Константный указатель. Нельзя перенаправить на другую область памяти, но можно менять переменную
	/*const int* pn = &n;
	//pn = &m; //ошибка, но не точно
	//указывает только на один объект
	*/

	//Константный указатель на константу. Нельзя менять значение объекта через разыменование и нельзя перенаправлять на другую область памяти
	/*const int const* pn = &n;
	//*pn = 5; // ошибка
	//pn = &m; //ошибка
	*/

	//Массив как константный указатель
	/*int mass[5]{};
	//mass = &n; //ошибка, так как название массива является константным указателем
	*/

	//ССЫЛКИ
	//Указатель
	/*int* pn = &n;
	cout << *pn << endl; //для обращения к переменной требуется разыменование
	*/

	//Ссылка
	/*int &refm = m;
	refm = 20; //не хранят адрес, являются альтернативным именем переменной, обладающее доступ к ней из любого блока кода.
	cout << "Новая m = " << m << endl;*/

	//SWAP функции
	/*my_swap(n, m); //не работает
	cout << n << " " << m << endl;

	n = 10; m = 15;
	pswap(&n, &m); //работает, но неудобно
	cout << n << " " << m << endl;

	n = 10; m = 15;
	refswap(n, m);
	cout << n << " " << m << endl;*/


	/*for (int i = 0; i < 10; i++) {
		cout << "Введите число: ";
		cin >> mx[i][0];
		func(i) = mx[i][0];
	}
	cout << "Итоговый массив: \n";
	for (int i = 0; i < 10; i++)
		cout << mx[i][0] << "\t" << func(i) << '\n';
	*/
	int arr_max[5]{4, 7, 2, -9, 6};
	cout << "Изначальный массив: \n";
	show_arr(arr_max, 5);
	cout << "Максимум = " << ref_max(arr_max, 5) << endl;

	ref_max(arr_max, 5) = 0;
	cout << "Итоговый массив: \n";
	show_arr(arr_max, 5);
	cout << endl;

	//Задача 1. Две переменные
	cout << "Задача №1.\nВведите два числа: ";
	cin >> n >> m;
	two_var(n,m);
	cout << "n = " << n << endl;
	cout << "m = " << m << endl;

	//Задача 2. Копирование массива
	const int size1 = 5;
	const int size2 = 7;
	int arr1[size1]{ 4, 2, 1, 6, 7 };
	int arr2[size2]{};
	cout << "Задача №2.\nПервый массив: \n";
	show_arr(arr1, size1);
	copy_arr(arr1, size1, arr2, size2);
	cout << "Второй массив: \n";
	show_arr(arr2, size2);

	return 0;
}

//Задача 1
template <typename T>
void two_var(T &num1, T &num2) {
	if (num1 > num2) {
		num1 *= num1; // num1 = pow (num1, 2) - cmath библиотека
		num2 *= num2;
	}
	else {
		num1 = 0;
		num2 = 0; // num1{0}
	}
}
template <typename T1, typename T2>
void copy_arr(
	T1 arr1[], const int length1, 
	T2 arr2[], const int length2
) {
	int min_len = length1 < length2 ? length1 : length2;
	for (int i = 0; i < min_len; i++) {
		//arr2[i] = arr1[i];
		*(arr2 + i) = *(arr1 + i);
	}
}
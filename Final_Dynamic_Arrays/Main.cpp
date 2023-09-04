#include <iostream>
#include <cstdlib>
#include <ctime>

//Заполнение массива случайными числами
template <typename T>
void fill_arr(T arr, const int length, int left, int right) {
	srand(time(NULL));
	for (int i = 0; i < length; i++)
		arr[i] = rand() % (right - left) + left;
}

//Вывод массива в консоль
template <typename T>
void print_arr(T arr[], const int length) {
	if (length <= 0) {
		std::cout << "{}" << std::endl;
		return;
	}
	std::cout << "{ ";
	for (int i = 0; i < length; i++)
		std::cout << arr[i] << ", ";
	std::cout << "\b\b }" << std::endl;
}

template<typename T>
void arr_app(T*& arr, int& length, int num);

template <typename T>
void arr_push(T*& arr, int& length, int num);

template <typename T>
void arr_delete_back(T*& arr, int& length, int num);



int main() {
	system("chcp 1251>nul");
	int n, m;

	//Задача 1. Добавить элементы в конец массива.
	std::cout << "Задача 1.\nВведите размер массива -> ";
	int size1;
	std::cin >> size1;
	int* arr1 = new int[size1];
	fill_arr(arr1, size1, 10, 21);
	std::cout << "Изначальный массив:\n";
	print_arr(arr1, size1);

	std::cout << "Введите кол-во новых элементов -> ";
	std::cin >> n;
	arr_app(arr1, size1, n);

	std::cout << "Итоговвый массив:\n";
	print_arr(arr1, size1);
	std::cout << std::endl;


	//Задача 2. Добавить элементы в начало массива.
	std::cout << "Задача 2.\nВведите размер массива -> ";
	int size2;
	std::cin >> size2;
	int* arr2 = new int[size2];
	fill_arr(arr2, size2, 10, 21);
	std::cout << "Изначальный массив:\n";
	print_arr(arr2, size2);

	std::cout << "Введите кол-во новых элементов -> ";
	std::cin >> n;
	arr_push(arr2, size2, n);
	

	std::cout << "Итоговвый массив:\n";
	print_arr(arr2, size2);
	std::cout << std::endl;


	//Задача 3. Удалить элементы из конца массива.
	std::cout << "Задача 3.\nВведите размер массива -> ";
	int size3;
	std::cin >> size3;
	int* arr3 = new int[size3];
	fill_arr(arr3, size3, 10, 21);
	std::cout << "Изначальный массив:\n";
	print_arr(arr3, size3);

	std::cout << "Введите кол-во элементов для удаления -> ";
	std::cin >> n;
	arr_delete_back(arr3, size3, n);


	std::cout << "Итоговвый массив:\n";
	print_arr(arr3, size3);
	std::cout << std::endl;


	//Двумерный динамический массив.
	std::cout << "Введите кол-во рядов -> ";
	std::cin >> n;
	std::cout << "Введите кол-во колонок -> ";
	std::cin >> m;

	//int* dynamic_mx = new int[n][m]; ОШИБКА неправильный синтаксис

	//Выделение памяти под двумерный динамический массив
	int** dynamic_mx = new int*[n];
	for (int i = 0; i < n; i++)
		dynamic_mx[i] = new int[m];



	//Освобождение памяти выделенной под двумерный динамический массив
	for (int i = 0; i < n; i++)
		delete[] dynamic_mx[i];
	delete[] dynamic_mx;




	return 0;
}


template <typename T>
void arr_delete_back(T*& arr, int& length, int num) {
	if (num <= 0)
		return;

	if (num >= length) {
		arr = nullptr;
		length = 0;
		return;
	}
	length -= num;
	T* tmp = new T[length];
	for (int i = 0; i < length; i++)
		tmp[i] = arr[i];

	delete[] arr;
	arr = tmp;
}


template <typename T>
void arr_push(T*& arr, int& length, int num) {
	if (num <= 0)
		return;

	T* tmp = new T[length + num]{};
	for (int i = 0; i < length; i++)
		tmp[i + num] = arr[i];

	delete[] arr;
	arr = tmp;
	length += num;
}



template<typename T>
void arr_app(T*& arr, int& length, int num) {
	//Отмена функции, если кол-во новых элементов не положительное
	if (num <= 0)
		return;

	T* tmp = new T[length + num]{};//Шаг 1. Создание нового временного массива необходимого размера
	for (int i = 0; i < length; i++)//Шаг 2. Копирование элементов старого массива в новый
		tmp[i] = arr[i];

	delete[] arr;//Шаг 3. Освобождение памяти, выделенное под старый массив
	arr = tmp;//Шаг 4. Перенаправление главного указателя на новый массив
	length += num;//Шаг 5. Увеличение переменной, хранящей размер массива.
}


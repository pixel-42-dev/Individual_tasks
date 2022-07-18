#include <iostream>
using namespace std;

int Binary_Search(int arr[], int left, int right, int key) {
	int middle = 0;
	while (true) {
		middle = (left + right) / 2;	// Находим середину массива

		if (key < arr[middle]) {		// Если искомое число меньше чем среднее...
			right = middle - 1;			// Сдвигаем правую границу поиска на место среднего числа
		} else if (key > arr[middle]) {	// Если число меньше чем среднее...
			left = middle + 1;			// Сдвигаем левую границу поиска на место среднего числа
		} else							// Иначе...
			return middle;				// Искомое число находится в середине, число найдено

		if (left > right)				// Если границы сомкнулись...
			return -1;					// Значит, искомого числа нет в массиве
	}
}

int main() {
	setlocale(LC_ALL, "rus");

	int x;
	int array[10] = { 2, 4, 6, 8, 10, 12, 14, 16, 18, 20 };

	cout << "Массив:" << endl;
	for (int i = 0; i < 10; i++) {
		cout << array[i] << " ";
	}
	cout << "\n\nВведите число: ";
	cin >> x;


	int index = Binary_Search(array, 0, 10, x);

	if (index >= 0)
		cout << "\nЧисло находится в ячейке с индексом: " << index << "\n";
	else
		cout << "\nИскомого числа нет в массиве";

	return 0;
}
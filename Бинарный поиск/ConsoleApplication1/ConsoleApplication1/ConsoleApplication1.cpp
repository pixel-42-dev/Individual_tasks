#include <iostream>
using namespace std;

int Binary_Search(int arr[], int left, int right, int key) {
	int middle = 0;
	while (true) {
		middle = (left + right) / 2;

		if (key < arr[middle]) {
			right = middle - 1;
		} else if (key > arr[middle]) {
			left = middle + 1;
		} else
			return middle;

		if (left > right)
			return -1;
	}
}

int main() {
	setlocale(LC_ALL, "rus");

	int array[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	int index = Binary_Search(array, 0, 10, 2);

	if (index >= 0)
		cout << "Число находится в ячейке с индексом: " << index << "\n\n";
	else
		cout << "Искомого числа нет в массиве";

	return 0;
}
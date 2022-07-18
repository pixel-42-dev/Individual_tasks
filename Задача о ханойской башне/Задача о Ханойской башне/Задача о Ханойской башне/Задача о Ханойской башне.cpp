#include <iostream>
using namespace std;

void hanoi_towers(int quantity, int from, int to, int buf_peg) {	// Количество дисков, номер начального, конечного, среднего колышков
	if (quantity != 0) {
		hanoi_towers(quantity - 1, from, buf_peg, to);	// Передвигаем все диски кроме нижнего на буфферный диск
		cout << from << " -> " << to << endl;			// Перемещаем последний диск
		hanoi_towers(quantity - 1, buf_peg, to, from);	// Передвигаем все оставшиеся диски на финальный колышек
	}
}

int main() {
	setlocale(LC_ALL, "rus");

	int plate_quantity;
	cout << "Количество дисков: ";
	cin >> plate_quantity;

	hanoi_towers(plate_quantity, 1, 3, 2);
	return 0;
}
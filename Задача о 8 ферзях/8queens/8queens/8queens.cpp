#include <iostream>
using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");

	int q[8][8] = {};	// Создаем доску 8x8
	int r = 0, c = 0;	// Начало с 1-ой строки, 1-ой колонки
	q[r][c] = 1;		// Помещаем первую королеву в перхний левый угол

nextCol:
	c++;					// Движение к следующей колонке
	if (c == 8) goto print;	// Если достигли последней колонки - переходим к выводу
	r = -1;					// В противном случае начало с ВЕРХА столбца ВЕРХ равно -1.

nextRow:
	r++;	// Двигаемся к следующей строке
	if (r == 8) goto backtrack;
	// Тест по строке
	for (int i = 0; i < c; i++) {
		if (q[r][i] == 1) goto nextRow;
	}
	// Тест по одной диагонали
	for (int i = 1; ((r - i) >= 0 && (c - i) >= 0); i++) {
		if (q[r - i][c - i] == 1) goto nextRow;
	}
	// Тест по другой диагонали
	for (int i = 1; ((r + i) <= 7 && (c - i) >= 0); i++) {
		if (q[r + i][c - i] == 1) goto nextRow;
	}
	q[r][c] = 1;
	goto nextCol;

backtrack:
	c--;	// Двигаемся к предыдущей колонке
	// Если вышли влево за шахматную доску - выходим из программы
	if (c == -1) {
		return 0;
	}
	// Находим квадрат с королевой в столбце и устанавливаем r равным номеру строки этого квадрата.
	r = 0;
	while (q[r][c] != 1) {
		r++;
	}
	q[r][c] = 0;	// Удаляем королеву с этого квадрата
	goto nextRow;	

print:
	static int numSolutions = 0;
	cout << "Решение " << ++numSolutions << ":\n";
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			cout << q[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	goto backtrack;
}
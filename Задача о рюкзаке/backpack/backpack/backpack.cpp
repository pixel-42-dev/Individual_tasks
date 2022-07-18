#include <iostream>
using namespace std;

int max(int a, int b) { return (a > b) ? a : b; }

// Возвращает максимальную ценность
int knapSack(int W, int wt[], int val[], int n) {

	if (n == 0 || W == 0)
		return 0;

	
	if (wt[n - 1] > W)		// Если вес n-го предмета больше вместимости ранца, предмет не может быть включен в оптимальное решение
		return knapSack(W, wt, val, n - 1);
	else					// Возвращаем большее из двух: данный элемент входит в подбор, или не входит
		return max( val[n - 1] + knapSack(W - wt[n - 1], wt, val, n - 1), knapSack(W, wt, val, n - 1));
}

int main()
{
	int val[] = { 60, 100, 120 };
	int wt[] = { 10, 20, 30 };
	int W = 50;
	int n = 3;
	cout << knapSack(W, wt, val, n);		// Вместительность, массив веса, массив стоимости, количество предметов
	return 0;
}
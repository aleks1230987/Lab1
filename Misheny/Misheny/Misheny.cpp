// Misheny.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>, <stdlib.h>, <math.h>
using namespace std;

int main()
{

	

	setlocale(LC_ALL, "Russian");
	int i, score;
	signed int randx, randy, x, y, shotx, shoty;
	score = 0;
	for (i = 0; i < 5; i = -(~i))
	{
		randx = 0;
		randy = 0;
		cout << "Введите Х-координату выстрела" << endl;
		cout << "x = ";
		cin >> shotx;
		cout << "Введите Y-координату выстрела" << endl;
		cout << "y = ";
		cin >> shoty;

		srand((unsigned)time(NULL));

		randx = rand() % 10 - 5;
		randy = rand() % 10 - 5;

		x = shotx + randx;
		y = shoty + randy;

		cout << "Попадание по X: " << x << endl;
		cout << "Попадание по Y: " << y << endl;
		double z = sqrt(x * x + y * y);
		

		((z >= 0 && z < 1) ? score += 5 : score = score);
		((z >= 1 && z < 2) ? score += 4 : score = score);
		((z >= 2 && z < 3) ? score += 3 : score = score);
		((z >= 3 && z < 4) ? score += 2 : score = score);
		((z >= 4 && z < 5) ? score += 1 : score = score);
		((z >= 5) ? score = score : score = score);

		cout << "Очки: " << score << endl;
		cout << endl;
		cout << endl;

		
	}
	if (score < 10)
	{
		cout << "ЛУЗЕР" << endl;
	}
	return 0;
}



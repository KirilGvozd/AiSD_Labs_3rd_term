#include <iostream>
using namespace std;

void hanoi(int startPin, int finishPin, int numberOfDisks)
{
    if (numberOfDisks == 1) {
        cout << "ѕерекладываем диск 1 со стержн€ " << startPin << " на стержень " << finishPin << ".\n";
    }
    else {
        int tmp = 6 - startPin - finishPin;
        hanoi(startPin, tmp, numberOfDisks - 1);
        cout << "ѕерекладываем диск " << numberOfDisks << " со стержн€ " << startPin << " на стержень " << finishPin << ".\n";
        hanoi(tmp, finishPin, numberOfDisks - 1);
    }
}

int main()
{
    setlocale(LC_ALL, "Rus");
    int number1, number2, number3;
	while (true)
	{
		cout << "¬ведите (через пробел или через Enter) с какого стержн€ вз€ть диски, на какой стержень переложить диск и количество дисков: ";
		try
		{
			cin >> number1 >> number2 >> number3;
			if (number1 <= 0 || !cin || number2 <= 0 || number3 <= 0 || number1 > 3 || number2 > 3 || number1 == number2)
			{
			throw exception("Incorrect input!");
			}
			else break;

		}
		catch (const exception e)
		{
			cin.clear();
			cin.ignore(3, '\n');
			cout << "Ќеверный ввод!" << endl;
		}
	}
	hanoi(number1, number2, number3);
    return 0;
}
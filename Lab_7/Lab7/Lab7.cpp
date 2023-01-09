#include <iostream>
#include <vector>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	int n;

	while (true)
	{
		cout << "Введите длину последовательности:" << endl;
		cin >> n;

		if (cin.get() != (int)'\n')
		{
			cout << "\nДанные введены неверно, попробуйте ещё раз!" << endl;
			cin.clear();
			cin.ignore(32767, '\n');
			continue;
		}
		else 
		{
			break;
		}
	}
	vector <int> sequence(n);
	vector<int> maxLen(n);
	vector<int> next(n);

	cout << "Вводите массив:" << endl;
	while (true)
	{
		int i = 0;
		for (; i < n; i++)
		{
			cout << i + 1 << "-й элемент: ";
			cin >> sequence[i];
			if (cin.get() != (int)'\n')
			{
				cout << "\nНеверный ввод, введите сначала!" << endl;
				cin.clear();
				cin.ignore(32767, '\n');
				break;
			}
			else 
			{
				continue;
			}
		}
		if (i == n) 
		{
			break;
		}
	}

	for (int i = n - 1; i >= 0; i--)
	{
		int maxNextLen = 0;
		int bestNext = -1;
		for (int j = i + 1; j < n; j++)
		{
			if (sequence[j] > sequence[i])
			{
				if (maxLen[j] > maxNextLen)
				{
					maxNextLen = maxLen[j];
					bestNext = j;
				}
			}
		}
		next[i] = bestNext;
		maxLen[i] = maxNextLen + 1;
	}
	int max = 0;
	int bestStart = -1;

	for (int i = 0; i < n; i++)
	{
		if (maxLen[i] > max)
		{
			max = maxLen[i];
			bestStart = i;
		}
	}

	cout << "Максимальная длина подпоследовательности: " << max << endl;

	for (int i = bestStart; i != -1; i = next[i])
		cout << sequence[i] << " ";

	return 0;
}
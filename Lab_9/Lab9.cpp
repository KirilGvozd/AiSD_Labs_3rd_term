#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;


#define V 5

#define CHILD 3
#define GENES ABCDE

#define START 0

#define POP_SIZE 5


int map[V][V] = { { INT_MAX, 25, 40, 31, 27},
				{ 5, INT_MAX, 17, 30, 25},
				{ 19, 15, INT_MAX, 6, 1},
				{ 9, 50, 24, INT_MAX, 6 },
				{ 22, 8, 7, 10, INT_MAX } };
struct individual 
{
	string genome;
	int way;
};


int rand_num(int start, int end)
{
	int r = end - start;

	int rnum = start + rand() % r;
	return rnum;
}


bool repeat(string s, char ch)
{
	for (int i = 0; i < s.size(); i++) 
	{
		if (s[i] == ch)
			return true;
	}
	return false;
}


string mutatedGene(string genome)
{
	while (true) {
		int r = rand_num(1, V);
		int r1 = rand_num(1, V);
		if (r1 != r) 
		{
			char temp = genome[r];
			genome[r] = genome[r1];
			genome[r1] = temp;
			break;
		}
	}
	return genome;
}

string create_genome()
{
	string genome = "0";
	while (true) {
		if (genome.size() == V) 
		{
			genome += genome[0];
			break;
		}
		int temp = rand_num(1, V);
		if (!repeat(genome, (char)(temp + 48))) 
		{
			genome += (char)(temp + 48);
		}
	}
	return genome;
}

int cal_way(string genome)
{

	int f = 0;
	for (int i = 0; i < genome.size() - 1; i++) {
		if (map[genome[i] - 48][genome[i + 1] - 48] == INT_MAX) 
		{
			return INT_MAX;
		}
		f += map[genome[i] - 48][genome[i + 1] - 48];
	}
	return f;
}

int cooldown(int temp)
{
	return (90 * temp) / 100;
}

bool lessthan(struct individual t1, struct individual t2)
{
	return t1.way < t2.way;
}

void TSPUtil(int map[V][V])
{
	int gen = 1;
	int gen_thres = 30;

	vector<struct individual> population;
	struct individual temp;

	for (int i = 0; i < POP_SIZE; i++) 
	{
		temp.genome = create_genome();
		temp.way = cal_way(temp.genome);
		population.push_back(temp);
	}

	cout << "\nРазмер популяции: " << endl << "Длина пути генома:\n";
	for (int i = 0; i < POP_SIZE; i++)
	{
		cout << population[i].genome << " " << population[i].way << endl;
	}
	cout << "\n";

	int temperature = 1000;

	sort(population.begin(), population.end(), lessthan);

	while (temperature > 100 && gen <= gen_thres) 
	{
		cout << endl << "Самый лучший геном: " << population[0].genome << endl;
		cout << endl << "Самый лучший путь: " << population[0].way << endl;

		cout << "\nТекущая температура: " << temperature << "\n";
		vector<struct individual> new_population;

		for (int i = 0; i < CHILD; i++) {
			
			struct individual p1 = population[i];
			
			while (true)
			{	
				string new_g = mutatedGene(p1.genome);
				struct individual new_gnome;
				new_gnome.genome = new_g;
				new_gnome.way = cal_way(new_gnome.genome);

				if (new_gnome.way <= population[i].way) {
					new_population.push_back(new_gnome);
					break;
				}
				else {
					new_gnome.way = INT_MAX;
					new_population.push_back(new_gnome);
					break;
				}
			}
		}

		temperature = cooldown(temperature);
		for (int i = 0; i < CHILD; i++)
		{
			population.push_back(new_population[i]);
		}
		sort(population.begin(), population.end(), lessthan);

		for (int i = 0; i < CHILD; i++)
		{
			population.pop_back();
		}
	
		cout << "Популяция: " << gen << " \n";
		cout << "Длина пути генома: \n";

		for (int i = 0; i < POP_SIZE; i++)
			cout << population[i].genome << " " << population[i].way << endl;
		gen++;
	}
}

int main()
{
	setlocale(LC_ALL, "Rus");
	TSPUtil(map);
}
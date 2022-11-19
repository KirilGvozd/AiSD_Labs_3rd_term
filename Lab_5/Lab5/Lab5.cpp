#include "stdafx.h"
#include "Graph.h"


int main()
{
    setlocale(LC_ALL, "Rus");
    Graph graph;
    cout << "Список ребер остовного дерева и их вес (через алгоритм Прима)" << endl;
    graph.PrimsAlgorithm();
    cout << "\nСписок ребер остовного дерева и их вес (через алгоритм Краскала)" << endl;
    graph.KruskalsAlgoritm();
}
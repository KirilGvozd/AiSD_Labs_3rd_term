#include <iostream>
#include "Graph.h"

int main()
{
    setlocale(LC_ALL, "Rus");

    Graph graph;

    graph.dejkstra('G');

    system("pause");

    return 0;
}
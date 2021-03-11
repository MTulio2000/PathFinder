#include "Dijkstra/dijkstra.h"

void addNodes(PathFinder *pathFinder)
{
    pathFinder->addNode(1);
    pathFinder->addNode(2);
    pathFinder->addNode(3);
    pathFinder->addNode(4);
    pathFinder->addNode(5);
    pathFinder->addNode(6);
}
void makeConnections(PathFinder *pathFinder)
{
    pathFinder->makeConnect(1,2,4);
    pathFinder->makeConnect(1,4,3);
    pathFinder->makeConnect(4,1,3);
    pathFinder->makeConnect(4,3,2);
    pathFinder->makeConnect(2,6,2);
    pathFinder->makeConnect(6,3,3);
    pathFinder->makeConnect(6,2,2);
    pathFinder->makeConnect(3,5,3);
    pathFinder->makeConnect(5,2,5);
    pathFinder->makeConnect(3,4,2);
}

void print(PathFinder *pathFinder,int start,int end)
{
    vector<int> path = pathFinder->findPath(start,end);
    for(int i:path)
        printf("%i\n",i);
}

int main()
{
    Dijkstra *pathFinder = new Dijkstra;
    addNodes(pathFinder);
    makeConnections(pathFinder);
    print(pathFinder,5,1);
    return 0;
}
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
typedef vector<pair<int,int>> Neighbor;

typedef struct Node
{
    struct Node *father;
    int distance,id;
    Neighbor neighbor;
}Node;

typedef map<int,Node*>NodeMap;

class Dijkstra
{
protected:
    void initDistances();
    static bool existIn(vector<int>,int);
    NodeMap nodes;
public:
    ~Dijkstra();
    void addNode(int id);
    void removeNode(int id);
    void makeConnect(int first,int second,int distance);
    vector<int> findPath(int init,int end);
}; 
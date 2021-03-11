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

class PathFinder
{
protected:
    void initDistances();
    static bool existIn(vector<int>,int);
    NodeMap nodes;
public:
    ~PathFinder();
    void addNode(int id);
    void removeNode(int id);
    void makeConnect(int first,int second,int distance);
    virtual vector<int> findPath(int init,int end) = 0;
};
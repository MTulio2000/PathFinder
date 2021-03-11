#include "pathfinder.h"

class Dijkstra: public PathFinder
{
public:
    vector<int> findPath(int init,int end) override;
};
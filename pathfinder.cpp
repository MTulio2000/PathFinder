#include "pathfinder.h"

bool PathFinder::existIn(vector<int> l,int id)
{
    return find(l.begin(),l.end(),id)!=l.end();
}

void PathFinder::addNode(int id)
{
    Node *n = new Node;
    n->id = id;
    n->father = nullptr;
    nodes.emplace(id,n);
}

void PathFinder::removeNode(int id)
{
    NodeMap::iterator it = nodes.find(id);
    if(it!=nodes.end())
        nodes.erase(it),delete it->second;
}

void PathFinder::makeConnect(int first,int second,int distance)
{
    NodeMap::iterator ob1,ob2;
    ob1 = nodes.find(first);
    ob2 = nodes.find(second);
    if(ob1!=nodes.end()&&ob2!=nodes.end())
        ob1->second->neighbor.push_back(make_pair(second,distance));
}

void PathFinder::initDistances()
{
    NodeMap::iterator it;
    for(it = nodes.begin();it!=nodes.end();it++)
        it->second->distance = 2^31-1;
}


PathFinder::~PathFinder()
{
    NodeMap::iterator it;
    for(it = nodes.begin();it!=nodes.end();it++)
        removeNode(it->first);
}
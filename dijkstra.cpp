#include "dijkstra.h"

bool Dijkstra::existIn(vector<int> l,int id)
{
    return find(l.begin(),l.end(),id)!=l.end();
}

void Dijkstra::addNode(int id)
{
    Node *n = new Node;
    n->id = id;
    n->father = nullptr;
    nodes.emplace(id,n);
}

void Dijkstra::removeNode(int id)
{
    NodeMap::iterator it = nodes.find(id);
    if(it!=nodes.end())
        nodes.erase(it),delete it->second;
}

void Dijkstra::makeConnect(int first,int second,int distance)
{
    NodeMap::iterator ob1,ob2;
    ob1 = nodes.find(first);
    ob2 = nodes.find(second);
    if(ob1!=nodes.end()&&ob2!=nodes.end())
        ob1->second->neighbor.push_back(make_pair(second,distance));
}

void Dijkstra::initDistances()
{
    NodeMap::iterator it;
    for(it = nodes.begin();it!=nodes.end();it++)
        it->second->distance = 2^31-1;
}

vector<int> Dijkstra::findPath(int init,int end)
{
    NodeMap::iterator it = nodes.find(init);
    vector<int> path = {};
    if(it!= nodes.end() && nodes.find(end)!=nodes.end())
    {
        vector<int> opened;
        initDistances();
        vector<Node*> n;
        Node *node,*act;
        n.push_back(it->second);
        it->second->distance = 0;
        it->second->father = nullptr;

        //dijkstra algorithm loop
        while(!n.empty())
        {
            node = n[0];
            opened.push_back(node->id);
            n.erase(n.begin());
            for(pair<int,int> neighbor:node->neighbor)
            {
                act = nodes.find(neighbor.first)->second;
                if(!existIn(opened,neighbor.first))
                    n.push_back(act);
                if(node->distance+neighbor.second<act->distance)
                {
                    act->father = node;
                    act->distance = node->distance+neighbor.second;
                }
            }
        }

        //making the path
        node = nodes.find(end)->second;
        while(node)
        {
            path.push_back(node->id);
            node = node->father;
        }

        //reverse the path
        reverse(path.begin(),path.end());
    }
    return path;
}

Dijkstra::~Dijkstra()
{
    NodeMap::iterator it;
    for(it = nodes.begin();it!=nodes.end();it++)
        removeNode(it->first);
}
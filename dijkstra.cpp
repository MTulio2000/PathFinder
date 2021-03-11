#include "dijkstra.h"

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
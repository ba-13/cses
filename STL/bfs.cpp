#include "macro.hpp"
#include <queue>
using namespace std;

int num_nodes;
vvi graph;

/**
 * queue supports:
 * front, back, push(~push_back), pop(~pop_front)
 */

bool check_graph_connected_bfs()
{
    int start_vertex = 0;
    vi visited(num_nodes, false);
    queue<int> Q;
    Q.push(start_vertex);
    visited[start_vertex] = true;
    while (!Q.empty())
    {
        int i = Q.front();
        Q.pop();
        tr(graph[i], it)
        {
            if (!visited[*it])
            {
                visited[*it] = true;
                Q.push(*it);
            }
        }
    }
    return (find(all(visited), false) == visited.end());
}
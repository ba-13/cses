#include "macro.hpp"
using namespace std;

// adjacency list approach
int num_nodes;
vvi graph;
vi visited;

void dfs(int i)
{
    if (!visited[i])
    {
        visited[i] = true;
        for_each(graph.begin(), graph.end(), dfs);
        // for_each calls the specified function for each element in range
    }
}

bool check_graph_connected_dfs()
{
    int start_vertex = 0;
    visited = vi(num_nodes, false); // a constructor!
    dfs(start_vertex);
    return (find(all(visited), false) == visited.end());
}
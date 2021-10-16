/**
 * Priority queue is a binary heap
 * it can: push, view top, and pop top element
 */
#include "macro.hpp"
#include <queue>
using namespace std;
const bool debugging = true;

#define INF 987654321

class Graph
{
    int N;
    std::vector<std::vector<std::pair<int, int>>> adj;

public:
    Graph(int N);
    void addEdge(int u, int v, int w);
    vi shortestPath(int s);
    vi shortestPathSet(int src);
};

Graph::Graph(int N)
{
    this->N = N;
    this->adj = std::vector<std::vector<std::pair<int, int>>>(N);
}

void Graph::addEdge(int u, int v, int w)
{
    adj[u].push_back(ii(v, w));
    adj[v].push_back(ii(u, w));
}

vi Graph::shortestPath(int src)
{
    // priority_queue with reverse comparision, so top() returns least distance
    std::priority_queue<ii, vector<ii>, greater<ii>> pq;
    // distance from start to each vertex, infty initially
    vi dist(N, INF);
    // making self, 0 distance
    pq.push(ii(0, src));
    dist[src] = 0;

    while (!pq.empty())
    {
        int u = pq.top().second; // fetch the nearest element
        pq.pop();
        tr(adj[u], it)
        {
            int v = it->first;
            int weight = it->second;
            if (dist[v] > dist[u] + weight)
            {
                dist[v] = dist[u] + weight;
                pq.push(ii(dist[v], v));
            }
        }
    }
    return dist;
}

vi Graph::shortestPathSet(int src)
{
    vi dist(N, INF);
    std::set<ii> Q;
    dist[src] = 0;
    Q.insert(ii(0, src));

    while (!Q.empty())
    {
        int u = Q.begin()->second;
        Q.erase(Q.begin());

        tr(adj[u], it)
        {
            int v = it->first;
            int weight = it->second;
            if (dist[v] > dist[u] + weight)
            {
                dist[v] = dist[u] + weight;
                Q.insert(ii(dist[v], v));
            }
        }
    }
    return dist;
}

int main()
{
    // create the graph
    int V = 9;
    Graph g(V);

    //  making above shown graph
    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);

    // shows all nodes' shortest distances from provided node
    vi dist = g.shortestPathSet(0);
    vi dist2 = g.shortestPath(0);
    show(dist);
    show(dist2);
    return 0;
}
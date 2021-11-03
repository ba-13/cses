#include <iostream>
#include <random>
#include <vector>
#include <set>
const int debugging = true;
#define deb(x)     \
    if (debugging) \
        std::cout << #x << " : " << x << "\n";
#define fr(i, n) for (int i = 0; i < n; i++)
#define vi std::vector<int>

std::vector<int> solveMaze(std::vector<std::vector<int>> maze, int start, int finish);
std::vector<int> solveMazeRecursiveInitiator(std::vector<std::vector<int>> maze, int start, int finish);

int main()
{
    std::mt19937 mt(69);
    std::uniform_int_distribution<int> dist(10, 1000);
    if (debugging)
        std::cout << ">>>\n";

    /**
     * Represent a grid as:
     * 1   2   3  4
     *      _______
     * 5 |  6  7  8
     *   |        __
     * 9 | 10 | 11 12
     * 
     * Ok that's a bad representation, but you get the point. We will define an adjacency list, and then try to go from start to end.
     */
    int n = 0;
    std::cin >> n;
    std::vector<std::vector<int>> graph(n);
    fr(i, n)
    {
        int tmp = 0;
        while (std::cin >> tmp && tmp != -1)
            graph[i].push_back(tmp);
    }
    int start, finish;
    std::cin >> start >> finish;
    std::vector<int> slowSol = solveMaze(graph, start, finish);
    std::vector<int> sol = solveMazeRecursiveInitiator(graph, start, finish);
    fr(i, sol.size())
            std::cout
        << sol[i] << "->";
    return 0;
}

// explicitly backtracking
std::vector<int> solveMaze(std::vector<std::vector<int>> maze, int start, int finish)
{
    std::set<int> visited;
    std::vector<int> path;

    path.push_back(start);
    int curr = start;
    visited.insert(start);

    while (path.back() != finish && path.empty() == false)
    {
        std::vector<int>::iterator it = maze[curr].begin();
        bool foundOutlet = false;

        while ((it != maze[curr].end()) && (!foundOutlet))
        {
            if (visited.count(*it) == 0)
            {
                foundOutlet = true;
            }
            else
                it++;
        }

        if (foundOutlet)
        {
            path.push_back(*it);
            visited.insert(*it);
        }
        else
        {
            path.pop_back();
        }
        curr = path.back();
    }
    return path;
}

// implicit backtracking
bool solveMazeRecursive(std::vector<std::vector<int>> &maze, int start, int finish, std::set<int> &visited, std::vector<int> &path)
{
    if (start == finish)
    {
        path.push_back(start);
        return true;
    }

    visited.insert(start);
    std::vector<int>::iterator it = maze[start].begin();
    while (it != maze[start].end())
    {
        if (visited.count(*it) == 0)
        {
            // when this returns true, the path should already contain that *it (i.e. all nodes from finish to *it, we have a backtrack, pun intended)
            if (solveMazeRecursive(maze, *it, finish, visited, path))
            {
                // if such a neighbour corresponding to start is found that allows to move on, add start to path
                path.push_back(start);
                return true;
            }
        }
        it++;
    }
    return false; // stuck at start
}

std::vector<int> solveMazeRecursiveInitiator(std::vector<std::vector<int>> maze, int start, int finish)
{
    std::set<int> visited;
    std::vector<int> solution_path;
    solveMazeRecursive(maze, start, finish, visited, solution_path);
    fr(i, solution_path.size() / 2)
    {
        int tmp = solution_path[i];
        solution_path[i] = solution_path[solution_path.size() - i - 1];
        solution_path[solution_path.size() - i - 1] = tmp;
    }
    return solution_path; // either will contain the solution_path, or will contain any partial path
}
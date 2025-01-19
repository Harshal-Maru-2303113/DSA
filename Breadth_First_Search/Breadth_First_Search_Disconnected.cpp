#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void Breadth_First_Search(vector<vector<int>> &adj_list, int starting_node, vector<bool> &visited, int n)
{
    queue<int> nodes_queue;
    visited[starting_node] = true;
    nodes_queue.push(starting_node);

    while (!nodes_queue.empty())
    {
        int current_node = nodes_queue.front();
        nodes_queue.pop();
        cout << current_node << " ";

        for (int node : adj_list[current_node])
        {
            if (!visited[node])
            {
                visited[node] = true;
                nodes_queue.push(node);
            }
        }
    }
}

void Breadth_First_Search_Disconnected(vector<vector<int>> &adj_list)
{
    int n = adj_list.size();
    vector<bool> visited(n, false);
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            Breadth_First_Search(adj_list, i, visited, n);
        }
    }
}

int main()
{
    vector<vector<int>> adjList = {
        {1, 3},
        {0, 2},
        {1, 4},
        {0},
        {2},
        {},
        {7},
        {6, 8},
        {7, 9},
        {8}};

    Breadth_First_Search_Disconnected(adjList);
    return 0;
}
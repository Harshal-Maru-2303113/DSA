#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void Breadth_First_Search(vector<vector<int>> &adj_list, int starting_node)
{
    int n = adj_list.size();
    vector<bool> visited(n, false);
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

int main()
{
    vector<vector<int>> adjList = {
        {1, 3},
        {0, 2, 4},
        {1},
        {0},
        {1, 5},
        {4}};

    Breadth_First_Search(adjList, 0);
    return 0;
}
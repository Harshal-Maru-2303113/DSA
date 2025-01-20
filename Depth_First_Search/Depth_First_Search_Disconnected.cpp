#include <iostream>
#include <vector>
using namespace std;

void Depth_First_Search_Recursive(vector<vector<int>> &adj_list, int starting_node, vector<bool> &visited)
{
    if (visited[starting_node])
    {
        return;
    }
    visited[starting_node] = true;
    cout << starting_node << " ";
    for (auto node : adj_list[starting_node])
    {
        if (!visited[node])
        {
            Depth_First_Search_Recursive(adj_list, node, visited);
        }
    }
}

void Depth_First_Search_Disconnected(vector<vector<int>> &adj_list)
{
    vector<bool> visited(adj_list.size(), false);
    for (int i = 0; i < adj_list.size(); i++)
    {
        Depth_First_Search_Recursive(adj_list, i, visited);
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

    Depth_First_Search_Disconnected(adjList);
    return 0;
}
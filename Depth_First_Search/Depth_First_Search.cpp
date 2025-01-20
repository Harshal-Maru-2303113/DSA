#include <iostream>
#include <vector>
using namespace std;

void Depth_First_Search_Recursive(vector<vector<int>> & adj_list, int starting_node,vector<bool> &visited){
    visited[starting_node] =true;
    cout << starting_node << " ";
    for(auto node: adj_list[starting_node]){
        if(!visited[node]){
            Depth_First_Search_Recursive(adj_list,node,visited);
        }
    }
}


void Depth_First_Search(vector<vector<int>> & adj_list, int starting_node)
{
    vector<bool> visited(adj_list.size(),false);
    Depth_First_Search_Recursive(adj_list,starting_node,visited);
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

    Depth_First_Search(adjList, 0);
    return 0;
}
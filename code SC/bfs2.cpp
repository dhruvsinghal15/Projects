#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<bool> visited;
vector<vector<int>> g;

void bfs(int b)
{
    //Declare a queue to store all the nodes connected to b
    queue<int> q;

    //Insert b to queue by using push command
    q.push(b);

    //to ensure b as visited
    visited[b] = true;

    cout << "\n\nThe traversal bfs will be :  ";


    while (!q.empty())
    {
        int a = q.front();
        q.pop(); //delete the first element form queue

        for (auto j = g[a].begin(); j != g[a].end(); j++)
        {
            if (!visited[*j])
            {
                visited[*j] = true;
                q.push(*j);
            }
        }
        cout << a << "  ";
    }
}

// class use to making egdes
void makeEdge(int a, int b)
{
    g[a].push_back(b); //an edge from a to b 
}

// main class
int main()
{
    //The vertices are numbered from 0 to n-1
    int vertex, edge;

    cout << "Enter the number of vertices: ";

    cin >> vertex;

    cout << "\nEnter the number of edges: ";

    cin >> edge;

    visited.assign(vertex, false);
    g.assign(vertex, vector<int>());

    int a, b, i;

    cout << "\nEnter the edges with source and target vetex:\n ";

    //using for loop to take inputes an making egdes
    for (i = 0; i < edge; i++)
    {
        cin >> a >> b;
        makeEdge(a, b);
    }

    for (i = 0; i < vertex; i++)
    {
        //if the node i is unvisited
        if (!visited[i])
        {
            bfs(i);
        }
    }

    cout << "\n\n\n";

    return 0;
}
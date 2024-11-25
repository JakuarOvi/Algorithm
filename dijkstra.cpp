#include <bits/stdc++.h>
using namespace std;
#define INF 99999

int V, src, cost[100][100];
int dist[100];
bool visited[100];
int parent[100];

int getNear()
{
    int minvalue = INF;
    int minnode = -1;
    for(int i = 0; i < V; i++)
    {
        if(!visited[i] && dist[i] < minvalue)
        {
            minvalue = dist[i];
            minnode = i;
        }
    }
    return minnode;
}

void init()
{
    for(int i = 0; i < V; i++)
    {
        parent[i] = -1;
        dist[i] = INF;
        visited[i] = false;
    }
    dist[src] = 0;
}

void dijkstra()
{
    for(int i = 0; i < V-1; i++)
    {
        int near = getNear();
        visited[near] = true;

        for(int adj = 0; adj < V; adj++)
        {
            if(cost[near][adj] != INF && dist[adj] > dist[near] + cost[near][adj])
            {
                dist[adj] = dist[near] + cost[near][adj];
                parent[adj] = near;
            }
        }
    }
}

void display()
{
    cout << "Node\t\tCost\t\tPath\n";
    for(int i = 0; i < V; i++)
    {
        cout << i << "\t\t" << dist[i] << "\t\t";
        if (dist[i] == INF) {
            cout << "No Path\n";
        } else {
            stack<int> path;
            int parnode = i;
            while(parnode != -1)
            {
                path.push(parnode);
                parnode = parent[parnode];
            }
            while(!path.empty())
            {
                cout << path.top() << " ";
                path.pop();
            }
            cout << endl;
        }
    }
}

int main()
{
    cin >> V;

    for(int i = 0; i < V; i++)
    {
        for(int j = 0; j < V; j++)
        {
            cin >> cost[i][j];
            if(cost[i][j] == 999)
                cost[i][j] = INF;
        }
    }

    cin >> src;
    src--;
    init();
    dijkstra();
    display();

    return 0;
}

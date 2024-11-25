#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    int V, E;
    cin >> V >> E;

    vector<vector<int>> adj(V);
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int start;
    cin >> start;

    vector<bool> visited(V, false);
    stack<int> s;

    s.push(start);

    while (!s.empty()) {
        int node = s.top();
        s.pop();

        if (!visited[node]) {
            visited[node] = true;
            cout << node << " ";
        }

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                s.push(neighbor);
            }
        }
    }

    return 0;
}

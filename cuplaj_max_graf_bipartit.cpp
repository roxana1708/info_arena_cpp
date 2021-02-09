#include <iostream>
#include <vector>
#include <fstream>
#include <queue>

using namespace std;



ifstream f("cuplaj.in");

struct node {
    int x;
    int cap;
    int flux;
};

vector <vector<node>> adj(1000);
int n, s, t, m, e;
int max_flow_aux;
int rez_graph[100][100];
int parent[100];
bool visited[100];
queue <int> q;

int bfs() {
    memset(visited, 0, sizeof(visited));

    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    while (!q.empty()) {
        cout << "bbb";
        int u = q.front();
        //cout << u << " ";
        q.pop();

        for (int v = 0; v <= n+m+1; v++) {
            if (!visited[v] && rez_graph[u][v] == 1) {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }

    //cout << endl;
    return visited[t];
}


void dfs(int st) {
    visited[st] = true;
    for (auto i : adj[s]) {
        if (rez_graph[st][i.x] && !visited[i.x])
            dfs(i.x);
    }
}

void maxFlow_minCut() {
    int u, v;

    int max_flow = max_flow_aux;

    while (bfs()) {
        cout << "aaa";
        int flow_current = 2;// = INT_MAX;
        for (v=t; v!=s; v=parent[v]) {
            //u = parent[v];
            flow_current = min(flow_current, rez_graph[u][v]);
        }


        for (v=t; v != s; v=parent[v]) {
            u = parent[v];
            rez_graph[u][v] -= flow_current;
            rez_graph[v][u] += flow_current;
        }

        max_flow += flow_current;
    }

    cout << max_flow << endl;

    for (int i = 1; i <= n; i++)
        for(auto j : adj[i])
            cout << i << " " << j.x << " " << j.cap - rez_graph[i][j.x] << endl;


    memset(visited, false, sizeof(visited));
    dfs(s);

    cout << max_flow << endl;

    for (int i = 1; i <= n; i++) {
        for (auto j : adj[i]) {
            if (visited[i] && !visited[j.x])
                cout << i << " " << j.x << endl;
        }
    }

}

int main()
{
    //int rez_graph[n][n];
    for (int u = 1; u <= n; u++)
        for (int v = 1; v <= n; v++)
            rez_graph[u][v] = 0;

    int a, b;
    f >> n >> m >> e;
    //cout << n;
    node nod;
    for(int i = 0; i < e; i++) {
        f >> a >> b;
        nod.x = b+n;
        nod.cap = 1;
        nod.flux = 0;
        adj[a].push_back(nod);
        rez_graph[a][b] = 1;
    }


    s = 0, t = m+n+1;

    for(int i = 1; i <= n; i++) {
        nod.x = i;
        nod.cap = 1;
        nod.flux = 0;
        adj[s].push_back(nod);
        rez_graph[s][i] = 1;
    }

    for(int i = 1; i <= m; i++) {
        nod.x = t;
        nod.cap = 1;
        nod.flux = 0;
        adj[i+n].push_back(nod);
        rez_graph[i+n][t] = 1;
    }

    maxFlow_minCut();

    return 0;
}



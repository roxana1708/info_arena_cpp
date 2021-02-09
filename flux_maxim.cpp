#include <iostream>
#include <queue>
#include <fstream>
#include <vector>
using namespace std;

ifstream f("retea.in");

struct node {
    int x;
    int cap;
    int flux;
};

int n, s, t, m;
int max_flow_aux;
vector<vector<node>> adj(100);
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
        int u = q.front();
        //cout << u << " ";
        q.pop();

        for (int v = 1; v <= n; v++) {
            if (!visited[v] && rez_graph[u][v] > 0) {
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
        //cout << "aaa";
        int flow_current = INT_MAX;
        for (v=t; v!=s; v=parent[v]) {
            u = parent[v];
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

bool check_constraints(int s, int t) {
    int sum_in[n], sum_out[n];
    memset(sum_in, 0, sizeof(sum_in));
    memset(sum_out, 0, sizeof(sum_out));

    for(int i = 1; i <= n; i++) {
        for (auto j : adj[i]) {
                if (j.cap < j.flux)
                    return false;
                sum_out[i] += j.flux;
                sum_in[j.x] += j.flux;


        }
    }

    for(int i = 1; i <= n; i++) {
        if(i != s && i!= t && sum_in[i] != sum_out[i])
            return false;
    }

    return true;
}

int main() {

    f >> n >> s >> t >> m;
    node nod;

    for (int u = 1; u <= n; u++) {
        for (int v = 1; v <= n; v++)
            rez_graph[u][v] = 0;
    }

    int a, b, c, d;
    for (int i = 0; i < m; i++) {
        f >> a >> b >> c >> d;
        nod.x = b;
        nod.cap = c;
        nod.flux = d;
        adj[a].push_back(nod);
        rez_graph[a][b] = nod.cap - nod.flux;
        rez_graph[b][a] = nod.flux;
    }

    for(auto i : adj[s]) {
        max_flow_aux += i.flux;
    }

    if(check_constraints(s, t))
        cout << "DA";
    else
        cout << "NU";

    maxFlow_minCut();

    return 0;
}
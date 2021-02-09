#include <fstream>

using namespace std;

int main() {
    ifstream f("deque.in");
    ofstream g("deque.out");

    int n, k;
    long long sol = 0;


    f >> n >> k;

    int d[n];

    int  v[n+1];

    for(int i = 1; i <= n; i++)
        f >> v[i];


    int front = 1, back = 0;

    for(int i = 1; i <= n; i++) {

        while(front <= back && v[i] <= v[d[back]])
            back--;

        d[++back] = i;

        if(d[front] == i-k)
            front++;

        if(i >= k)
            sol += v[d[front]];
    }

    g << sol;
    return 0;
}
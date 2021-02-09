#include <fstream>
#include <queue>
#include <algorithm>

int main() {
    //auto t7 = std::chrono::high_resolution_clock::now();
    std::ifstream f("proc2.in");
    std::ofstream g("proc2.out");

    int n, m;

    std::ios::sync_with_stdio(false);

    f >> n >> m;

    std::priority_queue <int, std::vector <int>, std::greater <>> procesoare;
    std::priority_queue <std::pair<int, int>, std::vector <std::pair<int, int>>, std::greater <>> taskuri;

    for(int i = 0; i < n; i++)
        procesoare.push(i);

    int timp, durata;
    for(int i = 0; i < m; i++) {
        f >> timp >> durata;

        while(!taskuri.empty() && taskuri.top().first <= timp) {
            procesoare.push(taskuri.top().second);
            taskuri.pop();
        }

        g << procesoare.top() + 1 << "\n";
        taskuri.emplace(timp + durata, procesoare.top());
        procesoare.pop();
    }
    //auto t8 = std::chrono::high_resolution_clock::now();
    //auto duration_quick = std::chrono::duration_cast<std::chrono::microseconds>(t8 - t7).count();
    //g << duration_quick;
    return 0;
}
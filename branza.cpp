#include <fstream>
#include <deque>

using namespace std;

long long deque1[100001];

long long nrZile, pretDep, timpDep, sol;

struct br{
    long long pret;
    long long cantNec;
}branza[100005];

ifstream f("branza.in");

void rezolvare()
{
    int front = 1, back = 0;
    for (int i = 1; i <= nrZile; i++)
    {
        f >> branza[i].pret >> branza[i].cantNec;

        while (front <= back && branza[deque1[back]].pret + pretDep * (i - deque1[back]) >= branza[i].pret)
            back--;
        if (front <= back && i - deque1[front] == timpDep + 1)
            front++;
        deque1[++back] = i;
        sol += branza[deque1[front]].pret * branza[i].cantNec + (i - deque1[front]) * pretDep * branza[i].cantNec;
    }
}

int main() {

    ofstream g("branza.out");

    f >> nrZile >> pretDep>> timpDep;

    rezolvare();

    g << sol;
    return 0;
}
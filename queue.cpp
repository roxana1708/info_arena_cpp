#include <fstream>

using namespace std;

ifstream f("queue.in");
ofstream g("queue.out");

char operatie[50];
int st1[30003], st2[30003], k1, k2;

int obtNr () {
    int n = 0;

    for(int i = 10; operatie[i] >= '0' && operatie[i] <= '9'; ++i)
        n = n * 10 + (operatie[i] - '0');
    return n;
}

int main() {
    ios_base::sync_with_stdio(false);

    int n,i;

    f >> n;

    for(i = 1; i <= n; i++) {
        f >> operatie;

        int nr = obtNr();

        if(operatie[1]=='u') {
            k1++;
            st1[k1] = nr;
            g << i << ": read(" << nr << ") push(1," << nr << ")\n";
        }
        else {
            g << i <<":";

            if(!k2)
                while(k1)
                {
                    g << " pop(1) push(2," << st1[k1] <<")";
                    k2++;
                    st2[k2] = st1[k1];
                    k1--;
                }

            g << " pop(2) write(" << st2[k2] << ")\n";
            k2--;
        }
    }
    return 0;
}
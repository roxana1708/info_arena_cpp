#include <fstream>
#include <stack>
#include <algorithm>

using namespace std;

ifstream f("paranteze.in");
ofstream g("paranteze.out");

struct val_stiva{
    int val;
    char chr;
};

stack <val_stiva> st;

bool pereche(char x, char y) {
    if((x == '(' && y == ')') || (x == '[' && y == ']') || (x == '{' && y == '}'))
        return true;

    return false;
}

int main() {
    int n, k = 0, maxim = 0;
    char p;
    f >> n;

    for(int i = 0; i < n; i++) {
        f >> p;

        if(p == '{' || p == '[' || p == '(') {
            st.push({k, p});
            k = 0;
        }
        else {
            if(st.empty() || !pereche(st.top().chr, p)) {
                while(st.size())
                    st.pop();
                k = 0;
            }
            else{
                k = k + 2 + st.top().val;
                st.pop();
            }
        }
        maxim = max(maxim, k);
    }

    g << maxim;
    return 0;
}
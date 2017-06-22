#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <set>
#include <vector>
using namespace std;
#define LL long long
const int N = 1001;
struct node {
    string name;
    int score;
}r[N];
map<string, int> fir, sec;
int main() {
    ios_base::sync_with_stdio(false);
    int n, max_num = -1, i;
    cin >> n;
    for (i=0; i < n; i++) {
        cin >> r[i].name >> r[i].score;
        fir[r[i].name] += r[i].score;
    }
    for (i=0; i < n; i++)
        max_num = max(max_num, fir[r[i].name]);
    for (i=0; i < n; i++) {
        string name = r[i].name;
        if (fir[name] < max_num)
            continue;
        sec[name] += r[i].score;
        if (sec[name] >= max_num) {
            cout << name << '\n';
            return 0;
        }
    }
}

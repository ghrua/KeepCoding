#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <set>
#include <vector>
#include <queue>
using namespace std;
#define LL long long
map<string, int> reg;
int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i=0; i < n; i++) {
        string str;
        cin >> str;
        if (reg.count(str)) {
            cout << str << reg[str] << '\n';
            reg[str]++;
        }
        else {
            cout << "OK\n";
            reg[str] = 1;
        }
    }
    return 0;
}

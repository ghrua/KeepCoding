#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <set>
#include <vector>
using namespace std;
#define LL long long
char s[3]={0}, t[3]={0}, dir[3]={0};
int main() {
    ios_base::sync_with_stdio(false);
    cin >> s[0] >> s[1];
    cin >> t[0] >> t[1];
    int h, v, a, b, tag=0;
    h = t[0]-s[0]; v = t[1]-s[1];
    dir[0]=(h > 0 ? 'R' : 'L');
    dir[1]=(v > 0 ? 'U' : 'D');
    a = min(abs(h), abs(v));
    if (a == abs(h)) {
        b = abs(abs(v)-a);
        tag=1;
    }
    else {
        b = abs(abs(h)-a);
    }
    cout << a+b << '\n';
    for (int i=0; i < a; i++)
        cout << dir[0] << dir[1] << '\n';
    for (int i=0; i < b; i++)
        cout << dir[tag] << '\n';
}

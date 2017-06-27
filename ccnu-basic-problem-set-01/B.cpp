#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <string>
using namespace std;
#define LL long long
bool is2 (string & str) {
    if (str[0] != 'R')
        return false;
    if (str[1] > '9' )
        return false;
    for (int i=0; i < str.size(); i++)
        if (str[i] == 'C')
            return true;
    return false;
}
void c1 (string& str) {
    int p=2, ans=0;
    while (str[p] != 'C')
        p++;
    for (int i=p+1; i < str.size(); i++) {
        ans *= 10;
        ans += str[i]-'0';
    }
    string tmp="", tmp2(str.begin()+1, str.begin()+p);
    while (ans) {
        ans -= 1;
        tmp.push_back(ans%26+'A');
        ans /= 26;
    }
    reverse(tmp.begin(), tmp.end());
    cout << tmp << tmp2 << '\n';
}
void c2 (string& str) {
    int p=0;
    while (str[p] > '9')
        p++;
    int base=1, ans=0;
    for (int i=p-1; i>=0; i--) {
        ans += (str[i]-'A'+1)*base;
        base *= 26;
    }
    string tmp(str.begin()+p, str.end());
    cout << 'R' << tmp << 'C' << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    string str;
    int n;
    cin >> n;
    while(n--) {
        cin >> str;
        if (is2(str))
            c1(str);
        else
            c2(str);
    }
}

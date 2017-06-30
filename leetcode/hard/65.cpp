#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <set>
#include <vector>
#include <queue>
using namespace std;
#define LL long long
string strip(string& str) {
    int b=0, e=str.size()-1;
    for (; b < str.size(); b++) {
        if (str[b] != ' ')
            break;
    }
    for (; e >= 0; e--)
        if (str[e] != ' ')
            break;
    if (b > str.size() || e < 0)
        return "a";
    return string(str.begin()+b, str.begin()+e+1);
}
bool check_num (char ch) {
    return ch <= '9' && ch >= '0';
}
bool is_float (string str) {
    int n = -1, it=0, d=0;
    if (str[0] == '+' || str[0] == '-')
        it = 1;
    for (int i=it; i < str.size(); i++) {
        if (str[i] == '.')
            n = i;
        else if (check_num(str[i]))
            d++;
    }
    if (d == 0)
        return false;
    for (int i=it; i < str.size(); i++) {
        if (i == n)
            continue;
        if (!check_num(str[i]))
            return false;
    }
    return true;
}
bool is_int (string str) {
    int it=0, d=0;
    if (str[0] == '+' || str[0] == '-')
        it = 1;
    for (int i=it; i < str.size(); i++) {
        if (!check_num(str[i]))
            return false;
        else
            d++;
    }
    if (d == 0)
        return false;
    return true;
}
bool isNumber(string s) {
    string str = strip(s);
    int n=-1;
    for (int i=0; i < str.size(); i++)
        if (str[i] == 'e')
            n = i;
    if (n == -1)
        return is_float(str);
    else if (n == 0 || n == str.size()-1)
        return false;
    else {
        string s1(str.begin(), str.begin()+n);
        string s2(str.begin()+n+1, str.end());
        bool a = is_float(s1);
        bool b = is_int(s2);
        return a && b;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    string s;
    getline(cin, s);
    cout << isNumber(s) << '\n';
}

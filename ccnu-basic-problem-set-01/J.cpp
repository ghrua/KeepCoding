#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <set>
#include <vector>
#include <queue>
using namespace std;
#define LL long long

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    if (n != 2 && n % 2 == 0)
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}

#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
using namespace std;
#define LL long long

int main() {
    ios_base::sync_with_stdio(false);
    LL hi=0, wi=0;
    int n, a, m;
    cin >> n >> m >> a;
    hi = m/a;
    wi = n/a;
    if (n % a != 0)
        wi++;
    if (m % a != 0)
        hi++;
    cout << hi*wi << '\n';
}

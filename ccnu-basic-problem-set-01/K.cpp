#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <set>
#include <vector>
#include <queue>
using namespace std;
#define LL long long
int sche[35]={0}, min_time[35]={0}, max_time[35]={0};
int main() {
    ios_base::sync_with_stdio(false);
    int d, sum_time, min_sum=0;
    cin >> d >> sum_time;
    for (int i=0; i < d; i++) {
        cin >> min_time[i] >> max_time[i];
        sche[i] = min_time[i];
        min_sum += min_time[i];
    }
    if (min_sum > sum_time) {
        cout << "NO\n";
        return 0;
    }
    int rem = sum_time-min_sum;
    for (int i=0; i < d && rem > 0; i++) {
        int diff = max_time[i]-min_time[i];
        sche[i] += min(rem, diff);
        rem -= min(rem, diff);
    }
    if (rem != 0) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    for (int i=0; i < d; i++) {
        cout << sche[i];
        if (i == d-1)
            cout << '\n';
        else
            cout << ' ';
    }
    return 0;
}

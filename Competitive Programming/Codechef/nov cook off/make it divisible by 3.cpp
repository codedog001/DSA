#include <iostream>
#include<vector>
#define ll long long
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--){
    int n;
    cin >> n;

    vector<ll> a(n);
    int count1 = 0, count2 = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        if (a[i] % 3 == 1) count1++;
        else if (a[i] % 3 == 2) count2++;
    }

    int ans = min(count1, count2);
    int rem = max(count1, count2) - ans;
    if (rem % 3 == 0) {
        ans += 2 * (rem / 3);
    } else ans = -1;

    cout << ans << endl;
    }
    return 0;
}

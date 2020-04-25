/**
 * author : Wang Shaotong
 * email  : wangshaotongsydemon@gmail.com
 * date   : 2020-04-25
 * 
 * id     : D
 * name   : Constant Palindrome Sum
 * url    : https://codeforces.com/contest/1343/problem/D
 * level  : 2
 * tag    : 差分, 前缀和
 */

#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 200100;

int a[MAXN], cnt[MAXN * 2];

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i <= k * 2; i++) {
            cnt[i] = 0;
        }

        for (int i = 0; i < n / 2; i++) {
            cnt[1] += 2;
            cnt[min(a[i], a[n - i - 1]) + 1]--;
            cnt[a[i] + a[n - i - 1]]--;
            cnt[a[i] + a[n - i - 1] + 1]++;
            cnt[max(a[i], a[n - i - 1]) + k + 1]++;
        }

        int ans = n;
        for (int i = 2; i <= k * 2; i++) {
            cnt[i] += cnt[i - 1];
            ans = min(ans, cnt[i]);            
        }
        cout << ans << endl;
    }    
    return 0;
}
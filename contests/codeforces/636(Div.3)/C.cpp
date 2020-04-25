/**
 * author : Wang Shaotong
 * email  : wangshaotongsydemon@gmail.com
 * date   : 2020-04-21
 * 
 * id     : C
 * name   : Alternating Subsequence
 * url    : https://codeforces.com/contest/1343/problem/C
 * level  : 1
 * tag    : 模拟
 */

#include <iostream>
#define ll long long
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        ll flag = -1, sum = 0, temp = 0;
        for (int i = 0; i < n; i++) {
            ll a;
            cin >> a;
            if (flag == (a > 0)) {
                temp = a > temp ? a : temp;
            } else {
                sum += temp;
                temp = a;
                flag = a > 0;
            }
        }
        cout << sum + temp << endl;
    }
    return 0;
}
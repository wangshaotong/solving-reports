/**
 * author : Wang Shaotong
 * email  : wangshaotongsydemon@gmail.com
 * date   : 2020-04-21
 * 
 * id     : B
 * name   : Balanced Array
 * url    : https://codeforces.com/contest/1343/problem/B
 * level  : 1
 * tag    : 模拟, 数学
 */

#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        if (n / 2 % 2) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
            for (int i = 1; i <= n / 2; i++) {
                cout << i * 2 << " ";
            }
            for (int i = 1; i < n / 2; i++) {
                cout << i * 2 - 1 << " ";
            }
            cout << n * 3 / 2 - 1 << endl;
        }
    }
    return 0;
}
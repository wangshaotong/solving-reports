/**
 * author : Wang Shaotong
 * email  : wangshaotongsydemon@gmail.com
 * date   : 2020-04-21
 * 
 * id     : A
 * name   : Candies
 * url    : https://codeforces.com/contest/1343/problem/A
 * level  : 1
 * tag    : 枚举, 数学
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
        for (int i = 4; i <= n + 1; i *= 2) {
            if (n % (i - 1) == 0) {
                cout << n / (i - 1) << endl;
                break;
            }
        }
    }
    return 0;
}
/**
 * author : Wang Shaotong
 * email  : wangshaotongsydemon@gmail.com
 * date   : 2020-04-05
 * 
 * id     : poj 1003
 * name   : Hangover
 * url    : http://poj.org/problem?id=1003
 * level  : 1
 * tag    : 枚举
 */

#include <iostream>
using namespace std;

const int MAXN = 600;

int main()
{
    double sum = 0, a[MAXN];
    for (int i = 0; i < MAXN; i++) {
        sum += 1.0 / (i + 2);
        a[i] = sum;
    }

    double n;
    while (cin >> n && n != 0.00) {
        for (int i = 0; i < MAXN; i++) {
            if (a[i] >= n) {
                cout << i + 1 << " card(s)" << endl;
                break;
            }
        }
    }
    return 0;
}
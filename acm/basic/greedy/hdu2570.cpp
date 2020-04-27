/**
 * author : Wang Shaotong
 * email  : wangshaotongsydemon@gmail.com
 * date   : 2020-04-27
 * 
 * id     : hdu 2570
 * name   : 迷瘴
 * url    : http://acm.hdu.edu.cn/showproblem.php?pid=2570
 * level  : 1
 * tag    : 贪心
 */

#include <iomanip>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 120;

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n, v, w, p[MAXN];
        cin >> n >> v >> w;
        for (int i = 0; i < n; i++) {
            cin >> p[i];
        }
        sort(p, p + n);

        int vol = 0;
        double ans = 0;
        for (int i = 0; i < n; i++) {
            if (ans * vol+ p[i] * v <= w * (vol + v)) {
                ans = (ans * vol + p[i] * v) / (vol + v);
                vol += v;
            } else {
                break;
            }
        }
        cout << vol << " " << fixed << setprecision(2) << 1.0 * ans / 100 << endl;
    }
    return 0;
}
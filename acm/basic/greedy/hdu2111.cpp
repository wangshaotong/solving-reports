/**
 * author : Wang Shaotong
 * email  : wangshaotongsydemon@gmail.com
 * date   : 2020-04-27
 * 
 * id     : hdu 2111
 * name   : Saving HDU
 * url    : http://acm.hdu.edu.cn/showproblem.php?pid=2111
 * level  : 1
 * tag    : 贪心
 */

#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 120;

class Obj {
public:
    int p, m;
};

bool cmp(Obj o1, Obj o2) {
    return o1.p > o2.p;
}

int main()
{
    int v, n;
    while (cin >> v >> n && v != 0) {
        Obj obj[MAXN];
        for (int i = 0; i < n; i++) {
            cin >> obj[i].p >> obj[i].m;
        }

        sort(obj, obj + n, cmp);

        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (v >= obj[i].m) {
                v -= obj[i].m;
                ans += obj[i].p * obj[i].m;
            } else {
                ans += obj[i].p * v;
                break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
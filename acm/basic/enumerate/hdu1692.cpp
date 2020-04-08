/**
 * author : Wang Shaotong
 * email  : wangshaotongsydemon@gmail.com
 * date   : 2020-04-08
 * 
 * id     : hdu 1692
 * name   : Destroy the Well of Life
 * url    : http://acm.hdu.edu.cn/showproblem.php?pid=1692
 * level  : 1
 * tag    : 枚举
 */

#include <iostream>
using namespace std;

const int MAXN = 100100;
const int INF = 0x3f3f3f;

int w[MAXN], l[MAXN], p[MAXN];

int main()
{
    int t;
    cin >> t;
    int tmp = t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> w[i] >> l[i] >> p[i];
        }

        int minPoint = INF;
        for (int i = 0; i < n; i++) {
            int weight = 0, point = 0;
            for (int j = i; j < n; j++) {
                if (j >= n) {
                    j -= n;
                }
                if (w[j] + weight <= l[j]) {
                    point += p[j];
                    weight += w[j];
                } else {
                    weight += w[j];
                }
                if (point > minPoint) {     // 终止不符和条件的循环以减少时间
                    break;
                }
            }
            minPoint = point < minPoint ? point : minPoint;
        }
        cout << "Case " << tmp - t << ": Need to use " << minPoint << " mana points." << endl;
    }
    return 0;
}
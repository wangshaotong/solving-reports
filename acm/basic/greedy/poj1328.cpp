/**
 * author : Wang Shaotong
 * email  : wangshaotongsydemon@gmail.com
 * date   : 2020-04-26
 * 
 * id     : poj 1328
 * name   : Radar Installation
 * url    : http://poj.org/problem?id=1328
 * level  : 1
 * tag    : 贪心
 */

#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<pair<double, double> > v;

bool cmp(pair<double, double> p1, pair<double, double> p2) {
    return p1.first < p2.first;
}

int main()
{
    int n, d, t = 0;
    while (cin >> n >> d && (n != 0 || d != 0)) {
        t++;
        v.clear();

        for (int i = 0; i < n; i++) {
            int a, b;
            double len;
            pair<double, double> temp;
            cin >> a >> b;
            if (b <= d) {
                len = sqrt(1.0 * d * d - b * b);
                temp.first = a - len;
                temp.second = a + len;
                v.push_back(temp);
            }
        }
        
        cout << "Case " << t << ": ";
        if (v.size() != n) {
            cout << "-1" << endl;
        } else {
            sort(v.begin(), v.end(), cmp);

            int ans = 1;
            double cur = v.begin()->second;
            for (vector<pair<double, double> >::iterator it = v.begin(); it != v.end(); it++) {
                if (cur < it->first) {
                    ans++;
                    cur = it->second;
                } else {
                    cur = min(cur, it->second);
                }
            }
            cout << ans << endl;
        }
    }
    return 0;
}
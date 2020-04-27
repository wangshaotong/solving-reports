/**
 * author : Wang Shaotong
 * email  : wangshaotongsydemon@gmail.com
 * date   : 2020-04-27
 * 
 * id     : poj 2586
 * name   : Y2K Accounting Bug
 * url    : http://poj.org/problem?id=2586
 * level  : 1
 * tag    : 贪心
 */

#include <iostream>
using namespace std;

int main()
{
    int s, d;
    while (cin >> s >> d) {
        int cnt = 0, sum = -5 * d;
        while (sum < 0) {
            sum += d + s;
            cnt++;
        }
        cnt--;
        switch (cnt) {
            case 0:
                sum = -12 * d;
                break;
            case 1:
                sum = 3 * s - 9 * d;
                break;
            case 2:
                sum = 6 * s - 6 * d;
                break;
            case 3:
                sum = 8 * s - 4 * d;
                break;
            case 4:
                sum = 10 * s - 2 * d;
                break;
        }
        sum > 0 ? cout << sum << endl : cout << "Deficit" << endl;
    }
    return 0;
}
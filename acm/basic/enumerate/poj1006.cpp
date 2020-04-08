/**
 * author : Wang Shaotong
 * email  : wangshaotongsydemon@gmail.com
 * date   : 2020-04-08
 * 
 * id     : poj 1006
 * name   : Biorhythms
 * url    : http://poj.org/problem?id=1006
 * level  : 1
 * tag    : 枚举, 数学, 数论, 中国剩余定理
 */

#include <iostream>
using namespace std;

const int P = 23;
const int E = 28;
const int I = 33;
const int MAXDAY = 30000;

int main()
{
    int p, e, i, d, t = 1;
    while (cin >> p >> e >> i >> d && (p != -1 || e != -1 || i != -1 || d != -1)) {
        for (int days = d + 1; days < MAXDAY; days++) {
            if ((days - p) % P == 0 && (days - e) % E == 0 && (days - i) % I == 0) {
                cout << "Case " << t << ": the next triple peak occurs in " << days - d << " days." << endl;
                break;
            }
        }
        t++;
    }
    return 0;
}
/**
 * author : Wang Shaotong
 * email  : wangshaotongsydemon@gmail.com
 * date   : 2020-04-18
 * 
 * id     : poj 1835
 * name   : 宇航员
 * url    : http://poj.org/problem?id=1835
 * level  : 1
 * tag    : 模拟, 几何, 三维向量
 */

#include <iostream>
using namespace std;

class Position {
public:
    int x, y, z;
    int f, r, u;
};

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Position pos;
        pos.x = pos.y = pos.z = 0;
        pos.f = 0, pos.r = 1, pos.u = 2;
        for (int i = 0; i < n; i++) {
            char str[10];
            int num, temp;
            cin >> str >> num;
            switch (str[0]) {
                case 'b':
                    pos.f = (pos.f + 3) % 6;
                    pos.r = (pos.r + 3) % 6;
                    break;
                case 'l':
                    temp = pos.r;
                    pos.r = pos.f;
                    pos.f = (temp + 3) % 6;
                    break;
                case 'r':
                    temp = pos.f;
                    pos.f = pos.r;
                    pos.r = (temp + 3) % 6;
                    break;
                case 'u':
                    temp = pos.f;
                    pos.f = pos.u;
                    pos.u = (temp + 3) % 6;
                    break;
                case 'd':
                    temp = pos.u;
                    pos.u = pos.f;
                    pos.f = (temp + 3) % 6;
                    break;
                default:
                    break;
            }
            switch (pos.f) {
                case 0:
                    pos.x += num;    
                    break;
                case 1:
                    pos.y += num;
                    break;
                case 2:
                    pos.z += num;
                    break;
                case 3:
                    pos.x -= num;
                    break;
                case 4:
                    pos.y -= num;
                    break;
                case 5:
                    pos.z -= num;
                    break;
            }
        }
        cout << pos.x << " " << pos.y << " " << pos.z << " " << pos.f <<endl; 
    }
    return 0;
}
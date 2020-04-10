/**
 * author : Wang Shaotong
 * email  : wangshaotongsydemon@gmail.com
 * date   : 2020-04-10
 * 
 * id     : poj 3174
 * name   : Alignment of the Planets
 * url    : http://poj.org/problem?id=3174
 * level  : 1
 * tag    : 枚举
 */

#include <vector>
#include <iostream>
using namespace std;

const int MAXN = 800;

class Node {
public:
    int a, b, c;
};
vector<Node> v;
int point[2][MAXN];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> point[0][i] >> point[1][i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                int x1 = point[0][i] - point[0][j];
                int x2 = point[0][j] - point[0][k];
                int y1 = point[1][i] - point[1][j];
                int y2 = point[1][j] - point[1][k];
                if (x1 * y2 == x2 * y1) {
                    Node n;
                    n.a = i + 1;
                    n.b = j + 1;
                    n.c = k + 1;
                    v.push_back(n);
                } 
            }
        }
    }
    cout << v.size() << endl;
    for (vector<Node>::iterator it = v.begin(); it != v.end(); it++) {
        cout << it->a << " " << it->b << " " << it->c << endl;
    }
    return 0;
}
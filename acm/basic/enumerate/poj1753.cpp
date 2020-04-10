/**
 * author : Wang Shaotong
 * email  : wangshaotongsydemon@gmail.com
 * date   : 2020-04-09
 * 
 * id     : poj 1753
 * name   : Flip Game
 * url    : http://poj.org/problem?id=1753
 * level  : 2
 * tag    : 枚举, 搜索
 */

#include <iostream>
using namespace std;

const int SIDE = 4;
const int INF = 0x3f3f3f;

int chess[4][4];
int cnt = 0, minCnt = INF;

void flipIt(int x, int y) {
    if (x >= 0 && x < 4 && y >= 0 && y < 4) {
        chess[x][y] = !chess[x][y];
    }
}

void flipThem(int x, int y) {
    flipIt(x, y);
    flipIt(x + 1, y);
    flipIt(x - 1, y);
    flipIt(x, y + 1);
    flipIt(x, y - 1);
}

bool isSame() {
    for (int i = 0; i < SIDE; i++) {
        for (int j = 0; j < SIDE; j++) {
            if (chess[i][j] != chess[0][0]) {
                return false;
            }
        }
    }
    return true;
}

void dfs(int n) {
    if (n == 16) {
        if (isSame()) {
            minCnt = cnt < minCnt ? cnt : minCnt;
        } 
        return;
    }

    for (int i = 0; i < 2; i++) {
        if (i == 0) {
            dfs(n + 1);
        } else {
            flipThem(n / SIDE, n % SIDE);
            cnt++;
            dfs(n + 1);
            cnt--;
            flipThem(n / SIDE, n % SIDE);
        }
    }
}

int main()
{
    for (int i = 0; i < SIDE; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < SIDE; j++) {
            chess[i][j] = str[j] == 'b' ? 1 : 0;
        }
    }
    dfs(0);
    minCnt == INF ? cout << "Impossible" << endl : cout << minCnt << endl;
    return 0;
}
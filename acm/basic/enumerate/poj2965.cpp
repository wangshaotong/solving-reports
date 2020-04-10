/**
 * author : Wang Shaotong
 * email  : wangshaotongsydemon@gmail.com
 * date   : 2020-04-10
 * 
 * id     : poj 2965
 * name   : The Pilots Brothers' refrigerator
 * url    : http://poj.org/problem?id=2965
 * level  : 2
 * tag    : 枚举, 搜索
 */

#include <vector>
#include <string>
#include <iostream>
using namespace std;

const int SIDE = 4;
const int INF = 0x3f3f3f;

vector <pair<int, int> > v, ans;
int cnt = 0, minCnt = INF;
int matrix[4][4] = {
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0}
};

bool isOpen() {
    for (int i = 0; i < SIDE; i++) {
        for (int j = 0; j < SIDE; j++) {
            if (matrix[i][j] == 1) {
                return false;
            }
        }
    }
    return true;
}

void open(int x, int y) {
    matrix[x][y] = !matrix[x][y];
    for (int i = 0; i < 4; i++) {
        matrix[x][i] = !matrix[x][i];
        matrix[i][y] = !matrix[i][y];
    }
}

void dfs(int n) {
    if (n == 16) {
        if (isOpen() && cnt < minCnt) {
            minCnt = cnt;
            ans = v;
        }
        return;
    }

    for (int i = 0; i < 2; i++) {
        if (i == 0) {
            dfs(n + 1);
        } else {
            cnt++;
            open(n / SIDE, n % SIDE);
            v.push_back(pair<int, int>(n / SIDE, n % SIDE));
            dfs(n + 1);
            v.pop_back();
            open(n / SIDE, n % SIDE);
            cnt--;
        }
    }
}

int main()
{
    for (int i = 0; i < SIDE; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < SIDE; j++) {
            matrix[i][j] = str[j] == '-' ? 0 : 1;
        }
    }
    dfs(0);
    cout << minCnt << endl;
    for (vector<pair<int, int> >::iterator it = ans.begin(); it != ans.end(); it++) {
        cout << it->first + 1 << " " << it->second + 1 << endl;
    }
    return 0;
}
/**
 * author : Wang Shaotong
 * email  : wangshaotongsydemon@gmail.com
 * date   : 2020-04-15
 * 
 * id     : poj 1068
 * name   : Parencodings
 * url    : http://poj.org/problem?id=1068
 * level  : 1
 * tag    : 模拟
 */

#include <vector>
#include <iostream>
using namespace std;

const int MAXN = 50;

int f[MAXN];
vector<int> p, w;
vector<char> bracket;

void pToBracket() {
    int pre = p[0];
    for (int i = 0; i < p[0]; i++) {
        bracket.push_back('(');
    }
    bracket.push_back(')');
    for (int i = 1; i < p.size(); i++) {
        for (int j = 0; j < p[i] - pre; j++) {
            bracket.push_back('(');
        }
        bracket.push_back(')');
        pre = p[i];
    }
}

void bracketToW() {
    for (int i = 0; i < bracket.size(); i++) {
        if (bracket[i] == ')') {
            int cnt = 0;
            for (int j = i; j >= 0; j--) {
                if (bracket[j] == '(') {
                    cnt++;
                }
                if (bracket[j] == '(' && f[j] == 0) {
                    f[j] = 1;
                    w.push_back(cnt);
                    break;
                }
            }
        }
    }    
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        p.clear();
        w.clear();
        bracket.clear();
        for (int i = 0; i < MAXN; i++) {
            f[i] = 0;
        }

        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            p.push_back(a);
        }
        pToBracket();
        bracketToW();
        for (int i = 0; i < w.size(); i++) {
            cout << w[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
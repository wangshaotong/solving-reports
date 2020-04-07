/**
 * author : Wang Shaotong
 * email  : wangshaotongsydemon@gmail.com
 * date   : 2020-04-07
 * 
 * id     : hdu 1015
 * name   : Safecracker
 * url    : http://acm.hdu.edu.cn/showproblem.php?pid=1015
 * level  : 1
 * tag    : 枚举
 */

#include <set>
#include <string> 
#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;

bool cmp(char a, char b) {
    return a > b;
}

inline ll toLong(char ch) {
    return ch - 'A' + 1;
}

bool isEqual(char v, char w, char x, char y, char z, ll n) {
    ll a = toLong(v),
        b = toLong(w),
        c = toLong(x),
        d = toLong(y),
        e = toLong(z);
    set<ll> st;
    st.insert(a);
    st.insert(b);
    st.insert(c);
    st.insert(d);
    st.insert(e);
    if (n == a - b * b + c * c * c - d * d * d * d + e * e * e * e * e && st.size() == 5) {
        return true;
    } else {
        return false;
    }
}

int main()
{
    ll n;
    string s;
    while (cin >> n >> s && (n != 0 || s != "END")) {
        string ans;
        int flag = 0, length = s.length();
        sort(s.begin(), s.end(), cmp);
        for (int v = 0; v < length; v++) {
            for (int w = 0; w < length; w++) {
                for (int x = 0; x < length; x++) {
                    for (int y = 0; y < length; y++) {
                        for (int z = 0; z < length; z++) {
                            if (isEqual(s[v], s[w], s[x], s[y], s[z], n)) {
                                flag = 1;
                                ans += s[v];
                                ans += s[w];
                                ans += s[x];
                                ans += s[y];
                                ans += s[z];
                                goto label;
                            }
                        }
                    }
                }
            }
        }
        label:
        if (flag == 0) {
            cout << "no solution" << endl;
        } else {
            cout << ans << endl;
        }
    }
    return 0;
}
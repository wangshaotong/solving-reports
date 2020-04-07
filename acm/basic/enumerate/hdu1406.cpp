/**
 * author : Wang Shaotong
 * email  : wangshaotongsydemon@gmail.com
 * date   : 2020-04-07
 * 
 * id     : hdu 1406
 * name   : 完数
 * url    : http://acm.hdu.edu.cn/showproblem.php?pid=1406
 * level  : 1
 * tag    : 枚举
 */

#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n--) {
        int a, b, cnt = 0;
        cin >> a >> b;        
        for (int i = min(a, b); i <= max(a, b); i++) {
            int sum = 0;
            for (int j = 1; j < i; j++) {
                if (i % j == 0) {
                    sum += j;
                }
            }
            if (sum == i) {
                cnt++;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}
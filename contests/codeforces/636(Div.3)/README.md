# Codeforces Round #636 (Div. 3) 解题报告 *(1343A - 1343F)*

- [Codeforces Round #636 (Div. 3) 解题报告 *(1343A - 1343F)*](#codeforces-round-636-div-3-%e8%a7%a3%e9%a2%98%e6%8a%a5%e5%91%8a-1343a---1343f)
  - [A. Candies](#a-candies)
    - [题意](#%e9%a2%98%e6%84%8f)
    - [思路](#%e6%80%9d%e8%b7%af)
    - [代码](#%e4%bb%a3%e7%a0%81)
  - [B. Balanced Array](#b-balanced-array)
    - [题意](#%e9%a2%98%e6%84%8f-1)
    - [思路](#%e6%80%9d%e8%b7%af-1)
    - [代码](#%e4%bb%a3%e7%a0%81-1)
  - [C. Alternating Subsequence](#c-alternating-subsequence)
    - [题意](#%e9%a2%98%e6%84%8f-2)
    - [思路](#%e6%80%9d%e8%b7%af-2)
    - [代码](#%e4%bb%a3%e7%a0%81-2)
  - [D. Constant Palindrome Sum](#d-constant-palindrome-sum)
    - [题意](#%e9%a2%98%e6%84%8f-3)
    - [思路](#%e6%80%9d%e8%b7%af-3)
    - [代码](#%e4%bb%a3%e7%a0%81-3)

## A. Candies

[题目](https://codeforces.com/problemset/problem/1343/A) | [代码](./A.cpp)

### 题意

输入$n$，求任意正整数$x$，使得$x + 2x + 4x + ... + 2 ^ {k - 1} x = n$ $(k > 1)$成立。

### 思路

由公式可以看出

当$k = 2$时，则$x + 2x = 3x = (2 ^ 2 - 1) x$;

当$k = 3$时，则$x + 2x + 4x = 7x = (2 ^ 3 - 1) x$;

当$k = n$时，则$x + 2x + ... 2 ^ {k - 1} x = (2 ^ k - 1) x$.

所以当$n \div (2 ^ k - 1)$的余数为0时，该式的结果即为答案。

### 代码

```cpp
#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 4; i <= n + 1; i *= 2) {
            if (n % (i - 1) == 0) {
                cout << n / (i - 1) << endl;
                break;
            }
        }
    }
    return 0;
}
```

## B. Balanced Array

[题目](https://codeforces.com/problemset/problem/1343/B) | [代码](./B.cpp)

### 题意

输入偶数$n$，要求构建一个数组并满足以下条件：

1. 前一半的元素均为偶数
2. 后一半的元素均为奇数
3. 所有元素均为正数且各不相同
4. 前半部分元素和等于后半部分元素和

如果该数组不存在，则输出`NO`；如果存在，则输出`YES`及任一符合条件的数组。

### 思路

当$\frac{n}{2}$为奇数时，奇数个偶数相加，和为偶数，奇数个奇数相加，和为奇数，不符合条件4。

当$\frac{n}{2}$为偶数时，给前一半元素赋值为$2i$，后一半元素赋值为$2i - 1$，满足前三个条件；因为前一半每一个元素均比后一半每一个元素大1，所以给最后一个元素加上$\frac{n}{2}$即可满足条件4。

### 代码

```cpp
#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        if (n / 2 % 2) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
            for (int i = 1; i <= n / 2; i++) {
                cout << i * 2 << " ";
            }
            for (int i = 1; i < n / 2; i++) {
                cout << i * 2 - 1 << " ";
            }
            cout << n * 3 / 2 - 1 << endl;
        }
    }
    return 0;
}
```

## C. Alternating Subsequence

[题目](https://codeforces.com/problemset/problem/1343/C) | [代码](./C.cpp)

### 题意

交错：正数与负数交错，即当前数为正数，下一个数为负数；当前数为负数，下一个数为正数。

子序列：不改变顺序，去除某些元素所形成的序列。

使一个序列的交错子序列长度最长，且元素和最大。

输出交错子序列的元素和。

### 思路

选取符号一致的连续子序列的最大值相加。

### 代码

```cpp
#include <iostream>
#define ll long long
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        ll flag = -1, sum = 0, temp = 0;
        for (int i = 0; i < n; i++) {
            ll a;
            cin >> a;
            if (flag == (a > 0)) {
                temp = a > temp ? a : temp;
            } else {
                sum += temp;
                temp = a;
                flag = a > 0;
            }
        }
        cout << sum + temp << endl;
    }
    return 0;
}
```

## D. Constant Palindrome Sum

[题目](https://codeforces.com/problemset/problem/1343/D) | [代码](./D.cpp)

### 题意

给出一个数组，要求经过替换后，所有元素不大于$k$且$a_i + a_{n - i - 1} = a_{i + 1} + a_{n - (i + 1) - 1} = ... = a_{i + \frac{n}{2} - 1} + a_{n - (i + \frac{n}{2} - 1) - 1} = x$。求最小替换次数。

### 思路

先分情况讨论：

1. $x \in [2, min(a_i, a_{n - i - 1})]$ 替换2次
2. $x \in (min(a_i, a_{n - i + 1}), a_i + a_{n - i - 1}]$ 替换1次
3. $x = a_i + a_{n - i - 1}$ 替换0次
4. $x \in (a_i + a_{n - i - 1}, max(a_i, a_{n - i - 1}) + k]$ 替换1次
5. $x \in (max(a_i, a_{n - i - 1}) + k, 2k]$ 替换2次

然后维护一个差分数组。

### 代码

```cpp
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 200100;

int a[MAXN], cnt[MAXN * 2];

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i <= k * 2; i++) {
            cnt[i] = 0;
        }

        for (int i = 0; i < n / 2; i++) {
            cnt[1] += 2;
            cnt[min(a[i], a[n - i - 1]) + 1]--;
            cnt[a[i] + a[n - i - 1]]--;
            cnt[a[i] + a[n - i - 1] + 1]++;
            cnt[max(a[i], a[n - i - 1]) + k + 1]++;
        }

        int ans = n;
        for (int i = 2; i <= k * 2; i++) {
            cnt[i] += cnt[i - 1];
            ans = min(ans, cnt[i]);            
        }
        cout << ans << endl;
    }    
    return 0;
}
```
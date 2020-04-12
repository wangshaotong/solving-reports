/**
 * author : Wang Shaotong
 * email  : wangshaotongsydemon@gmail.com
 * date   : 2020-04-12
 * 
 * id     : poj 1008
 * name   : Maya Calendar
 * url    : http://poj.org/problem?id=1008
 * level  : 1
 * tag    : 模拟
 */

#include <string>
#include <iostream>
using namespace std;

int getMonth(string str) {
    if ("pop" == str) {
        return 0;
    }
    if ("no" == str) {
        return 1 * 20;
    }
    if ("zip" == str) {
        return 2 * 20;
    }
    if ("zotz" == str) {
        return 3 * 20;
    }
    if ("tzec" == str) {
        return 4 * 20;
    }
    if ("xul" == str) {
        return 5 * 20;
    }
    if ("yoxkin" == str) {
        return 6 * 20;
    }
    if ("mol" == str) {
        return 7 * 20;
    }
    if ("chen" == str) {
        return 8 * 20;
    }
    if ("yax" == str) {
        return 9 * 20;
    }
    if ("zac" == str) {
        return 10 * 20;
    }
    if ("ceh" == str) {
        return 11 * 20;
    }
    if ("mac" == str) {
        return 12 * 20;
    }
    if ("kankin" == str) {
        return 13 * 20;
    }
    if ("muan" == str) {
        return 14 * 20;
    }
    if ("pax" == str) {
        return 15 * 20;
    }
    if ("koyab" == str) {
        return 16 * 20;
    }
    if ("cumhu" == str) {
        return 17 * 20;
    }
    if ("uayet" == str) {
        return 18 * 20;
    }
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int days;

        string dot, haabMonth;
        int haabDay, haabYear;
        cin >> haabDay >> dot >> haabMonth >> haabYear;
        days = haabDay + (getMonth(haabMonth)-1)*20 + haabYear * 365;

        string tzolkinDay;
        string tzolkinDayNames[] = {
            "imix", "ik", "akbal", "kan", "chicchan", 
            "cimi", "manik", "lamat", "muluk", "ok", 
            "chuen", "eb", "ben", "ix", "mem", "cib", 
            "caban", "eznab", "canac", "ahau" 
        };
        int tzolkinYear = days / 260;
        int tzolkinNumber = days % 13 + 1;
        tzolkinDay =  tzolkinDayNames[days % 20];
        cout << tzolkinNumber << " " << tzolkinDay << " " << tzolkinYear << endl;
    }
    return 0;
}
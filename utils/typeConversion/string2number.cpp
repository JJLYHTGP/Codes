#include <iostream>
#include <string> 
#include <set>
#include <sstream>
using namespace std;

// 字符串转数字的方法
long long s2ll(string str) {
    long long res;
    istringstream is(str);
    is >> res;
    return res;
}

int main() {
    string str;
    while(cin >> str) {
        cout<<s2ll(str)<<endl;
    }
}

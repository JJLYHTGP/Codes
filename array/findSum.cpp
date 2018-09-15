#include <iostream>
#include <string> 
#include <map>
#include <sstream>
using namespace std;

// 字符串转化为long long 
long long stols(string str) {
	long long res;
	istringstream is(str);
	is >> res;
	return res;
}

int main() {
    string str;
    cin >> str;
    // 获取n 
    int nIndex = str.find('|');
    long long n = stols(str.substr(nIndex+1));
	str = str.substr(0, nIndex);
	long long sum = 0;
	map <long long, bool> mySet;
	long long mIndex = -1;
	while(str.length()) {
		mIndex = str.find(',');
		long long m = 0;
		// 获取m并截断字符串 
		if (mIndex != string::npos)  {
			m = stols(str.substr(0, mIndex));
			str = str.substr(mIndex+1);
		} else {
			m = stols(str);
			str = "";
		}
		// map[m] = true; 寻找map[n-m]比较并将其弹出集合 
		mySet.insert(pair<long long, bool>(m, true));

		if (m < n && mySet[n-m] == true) {
			sum++;
			mySet.erase(m);
			mySet.erase(n-m);
		}
	}
    cout<<sum<<endl;
}

/* 
### 1,2,3,5|10寻找相加=10的对数(5+5=10也算)
``` 
输入：1,2,3,4,5|10
输出：1
```

还是新浪笔试，数组的输入仍然是字符串形式，
就不能转换成数组了会越界。本想使用桶排序也不行了，
数值范围可能是64位整数绝对越界。
代替桶排序使用map，舒心不担心越界

*/

#include <iostream>
#include <string> 
#include <map>
#include <sstream>
using namespace std;

// �ַ���ת��Ϊlong long 
long long stols(string str) {
	long long res;
	istringstream is(str);
	is >> res;
	return res;
}

int main() {
    string str;
    cin >> str;
    // ��ȡn 
    int nIndex = str.find('|');
    long long n = stols(str.substr(nIndex+1));
	str = str.substr(0, nIndex);
	long long sum = 0;
	map <long long, bool> mySet;
	long long mIndex = -1;
	while(str.length()) {
		mIndex = str.find(',');
		long long m = 0;
		// ��ȡm���ض��ַ��� 
		if (mIndex != string::npos)  {
			m = stols(str.substr(0, mIndex));
			str = str.substr(mIndex+1);
		} else {
			m = stols(str);
			str = "";
		}
		// map[m] = true; Ѱ��map[n-m]�Ƚϲ����䵯������ 
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
### 1,2,3,5|10Ѱ�����=10�Ķ���(5+5=10Ҳ��)
``` 
���룺1,2,3,4,5|10
�����1
```

�������˱��ԣ������������Ȼ���ַ�����ʽ��
�Ͳ���ת���������˻�Խ�硣����ʹ��Ͱ����Ҳ�����ˣ�
��ֵ��Χ������64λ��������Խ�硣
����Ͱ����ʹ��map�����Ĳ�����Խ��

*/

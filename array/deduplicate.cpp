#include <iostream>
#include <string> 
#include <set>
#include <sstream>
using namespace std;

// �ַ���ת���ֵķ���
long long s2ll(string str) {
	long long res;
	istringstream is(str);
	is >> res;
	return res;
}

void printSet(set<long long> mySet) {
	set <long long>::iterator it = mySet.begin();
    for (;it!=mySet.end();) {
    	cout<<*it;
    	it++;
		if (it!=mySet.end()) {
			cout<<","; 
		} else {
			cout<<endl;
		}
    }
}

int main() {
    string str;
    cin >> str;

	set <long long> mySet;
	long long mIndex = -1;
	while(str.length()) {
		mIndex = str.find(',');
		long long m = 0;
		// ��ȡ����Ԫ�ز���������ȥ����Ԫ�� 
		if (mIndex != string::npos)  {
			m = s2ll(str.substr(0, mIndex));
			str = str.substr(mIndex+1);
		} else {
			m = s2ll(str);
			str = "";
		}
		mySet.insert(m);
	}
	// ���������Ԫ�� 
    printSet(mySet);
}

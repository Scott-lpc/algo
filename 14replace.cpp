#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

//repalce(begin,end,oldvalue,newvalue)
class print10
{
public:
	void operator()(int val)
	{
		cout << val << endl;
	}
};

void test19()
{
	vector<int>v;
	v.push_back(20);
	v.push_back(30);
	v.push_back(20);
	v.push_back(20);
	v.push_back(40);
	v.push_back(20);
	v.push_back(70);
	replace(v.begin(), v.end(), 20, 100);
	for_each(v.begin(), v.end(), print10());
}

int main14()
{
	test19();
	system("pause");
	return 0;
}
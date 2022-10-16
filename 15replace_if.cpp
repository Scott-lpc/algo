#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
//repalce_if(beg,end,pred,newvalue)
class Greater10
{
public:
	bool operator()(int val)
	{
		return val > 10;
	}
};
void print15(int val)
{
	cout << val << " ";
}
void test20()
{
	vector<int>v;
	v.push_back(20);
	v.push_back(30);
	v.push_back(20);
	v.push_back(20);
	v.push_back(40);
	v.push_back(20);
	v.push_back(70);
	replace_if(v.begin(), v.end(), Greater10(), 50);
	for_each(v.begin(), v.end(), print15);
}

int main15()
{
	test20();
	system("pause");
	return 0;
}
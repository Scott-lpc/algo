#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;

//sort(begin,end,pred)
void print(int val)
{
	cout << val << " ";
}

void test14()
{
	vector<int>v;
	v.push_back(10);
	v.push_back(2);
	v.push_back(23);
	v.push_back(45);
	sort(v.begin(), v.end());
	for_each(v.begin(), v.end(), print);
	cout << endl;
	//½µÐò
	sort(v.begin(), v.end(), greater<int>());
	for_each(v.begin(), v.end(), print);
}

int main9()
{
	test14();
	system("pause");
	return 0;
}
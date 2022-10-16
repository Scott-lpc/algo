#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
void print2(int val)
{
	cout << val << " ";
}
void test15()
{
	vector<int>v;
	v.push_back(10);
	v.push_back(2);
	v.push_back(23);
	v.push_back(45);
	random_shuffle(v.begin(), v.end());
	for_each(v.begin(), v.end(), print2);
}
int main10()
{
	srand((unsigned)time(NULL));
	test15();
	system("pause");
	return 0;
}
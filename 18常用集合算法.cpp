#include<iostream>
#include<numeric>
#include<vector>
#include<algorithm>
using namespace std;
void print18(int val)
{
	cout << val << " ";
}
void test24()
{
	vector<int>v1;
	vector<int>v2;
	vector<int>v3;
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	v1.push_back(50);
	v1.push_back(60);
	v1.push_back(70);
	v1.push_back(80);
	v2.push_back(30);
	v2.push_back(40);
	v2.push_back(50);
	v2.push_back(60);
	v2.push_back(70);
	v2.push_back(80);
	v3.resize(min(v1.size(),v2.size()));
	//交集
	auto it=set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(),v3.begin()); //原集合必须有序！！！！！！！！
	for_each(v3.begin(), v3.end(), print18);
}

void test25()
{
	vector<int>v1;
	vector<int>v2;
	vector<int>v3;
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	v1.push_back(50);
	v1.push_back(60);
	v1.push_back(70);
	v1.push_back(80);
	v2.push_back(30);
	v2.push_back(40);
	v2.push_back(50);
	v2.push_back(60);
	v2.push_back(70);
	v2.push_back(80);
	v3.resize(v1.size()+v2.size());
	//并集
	auto it = set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin()); //原集合必须有序！！！！！！！！
	for_each(v3.begin(), it, print18);
}


void test26()
{
	vector<int>v1;
	vector<int>v2;
	vector<int>v3;
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	v1.push_back(50);
	v1.push_back(60);
	v1.push_back(70);
	v1.push_back(80);
	v2.push_back(30);
	v2.push_back(40);
	v2.push_back(50);
	v2.push_back(60);
	v2.push_back(70);
	v2.push_back(80);
	v2.push_back(90);
	v3.resize(v1.size() + v2.size());
	//差集
	auto it = set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin()); 
	for_each(v3.begin(), it, print18);
	v3.clear();  //清空函数把位置大小也清空
	v3.resize(v1.size() + v2.size());
	cout << endl;
	auto it2= set_difference(v2.begin(), v2.end(), v1.begin(), v1.end(), v3.begin());
	for_each(v3.begin(), it2, print18);
}


int main()
{
	test24();
	cout << endl;
	test25();
	cout << endl;
	test26();
	system("pause");
	return 0;
}
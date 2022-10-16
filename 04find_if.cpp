#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//find if
//查找 内置
class Greater
{
public:
	bool operator()(int val)
	{
		return val > 5;

	}
};

void test05()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	auto it=find_if(v.begin(), v.end(), Greater());
	if (it == v.end())
	{
		cout << "未找到" << endl;
	}
	else
	{
		cout << "找到" << *it << endl;
	}
}
class Person1
{
public:
	Person1(const string& name, const int& age)
	{
		Name = name;
		Age = age;
	}
	string Name;
	int Age;
};
class Greater20
{
public:
	bool operator()(Person1 p)
	{
		return p.Age > 20;
	}
};
void test06()
{
	Person1 p1("aa", 11);
	Person1 p2("aa", 11);
	Person1 p3("aa", 22);
	Person1 p4("aa", 45);
	vector<Person1>v;
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	auto it=find_if(v.begin(), v.end(), Greater20());
	if (it == v.end())
	{
		cout << "未找到" << endl;
	}
	else
	{
		cout << "找到" << it->Age <<it->Name<< endl;
	}

}
int main4()
{
	test05();
	test06();
	system("pause");
	return 0;
}


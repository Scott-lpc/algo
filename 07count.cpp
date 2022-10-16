#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

//统计内置类型
void test09()
{
	vector<int>v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(10);
	v.push_back(30);
	int num = count(v.begin(), v.end(), 10);
	cout << num << endl;
}

//统计自定义类型
class Person2
{
public:
	Person2(string name, int age)
	{
		Name = name;
		Age = age;
	}
	bool operator==(const Person2& p)
	{
		if (p.Age == Age)
		{
			return true;
		}
		else
			return false;
	}
	string Name;
	int Age;
};
void test10()
{
	vector<Person2>v;
	Person2 p1("aa", 1);
	Person2 p2("g", 2);
	Person2 p3("d", 3);
	Person2 p4("s", 4);
	Person2 p5("as", 1);
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);
	Person2 p6("s", 1);
	int num=count(v.begin(), v.end(), p6);
	cout << num << endl;
}

int main7()
{
	test09();
	test10();
	system("pause");
	return 0;
}
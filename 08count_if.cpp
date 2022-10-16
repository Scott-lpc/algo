#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

//常用查找算法 count_if(begin,end,pred) pred.谓词
//统计内置类型
class Greater10
{
public:
	bool operator()(int val)
	{
		return val > 10;
	}
};
void test11()
{
	vector<int>v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(10);
	v.push_back(30);
	int num = count_if(v.begin(), v.end(), Greater10());
	cout << num << endl;
}

//统计自定义类型
class Person3
{
public:
	Person3(string name, int age)
	{
		Name = name;
		Age = age;
	}
	string Name;
	int Age;
};
class Greater1
{
public:
	bool operator()(Person3& p)
	{
		return p.Age > 1;
	}
};
void test12()
{
	vector<Person3>v;
	Person3 p1("aa", 1);
	Person3 p2("g", 2);
	Person3 p3("d", 3);
	Person3 p4("s", 4);
	Person3 p5("as", 1);
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);
	int num = count_if(v.begin(), v.end(), Greater1());
	cout << num << endl;
}

int main8()
{
	test11();
	test12();
	system("pause");
	return 0;
}
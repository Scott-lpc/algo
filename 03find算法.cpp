#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//find
//���� ����
void test03()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	auto it=find(v.begin(), v.end(), 5);
	if (it == v.end())
	{
		cout << "wei" << endl;
	}
	else
	{
		cout << "�ҵ�" << *it << endl;
	}
}
class Person
{
public:
	Person(string name, int age)
	{
		Name = name;
		Age = age;
	}
	//����==�� �õײ�֪����ζԱ�Person !!!!!!
	bool operator==(const Person& p)
	{
		if (Name == p.Name && Age == p.Age)
		{
			return true;
		}
		return false;
	}
	string Name;
	int Age;
};

void test04()
{
	vector<Person>v;
	Person p1("1", 12);
	Person p2("ss", 12);
	Person p3("2", 12);
	Person p4("s5", 12);
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);

	auto it = find(v.begin(), v.end(), p2);		//find����ֵ�ǵ�����������
	if (it == v.end())
	{
		cout << "û���ҵ�" << endl;
	}
	else
	{
		cout << "�ҵ���" << endl;
	}
}

int main3()
{
	test03();
	test04();
	system("pause");
	return 0;
}
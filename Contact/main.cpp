#include<iostream>
using namespace std;
#include<string>

#define MAX  1000	//通讯录允许保存的最大联系人个数

struct Person
{
	string name;
	int age;
	int sex;
};

struct AddressBooks
{
	struct Person personArray[MAX];	//通讯录中保存的联系人数组
	int m_size;	//通讯录中联系人个数
};




void addPerson(AddressBooks * abs)		//添加联系人
{
	if (abs->m_size >= MAX)
	{
		cout << "通讯录已满" << endl;
		return;
	}
	string name;
	int sex,age;
	cout << "请输入姓名：";
	cin >> name;
	cout << "请输入年龄：";
	cin >> age;
	while (1)
	{
		cout << "请输入性别：" << endl;
		cout << "1-----男" << endl;
		cout << "2-----女" << endl;
		cin >> sex;
		if (sex != 1 && sex != 2)
		{
			cout << "请重新输入" << endl;
		}
		else {
			break;
		}
	}
	abs->personArray[abs->m_size].name = name;
	abs->personArray[abs->m_size].age = age;
	abs->personArray[abs->m_size].sex = sex;
	abs->m_size++;
	cout << "添加成功" << endl;
	system("pause");
}

void dispaly(AddressBooks *abs)		//展示联系人
{
	if (abs->m_size == 0) {
		cout << "通讯录为空" << endl;
		system("pause");
	}
	else
	{
		int ret;

		for (ret = 0; ret < abs->m_size; ret++)
		{
			cout << "姓名：" << abs->personArray[ret].name<<"\t";
			cout << "年龄：" << abs->personArray[ret].age << "\t";
			cout << "性别：" << (abs->personArray[ret].sex == 1 ? "男":"女") << endl;
		}
		system("pause");
	}
	
}

int isExist(AddressBooks* abs, string name)
{
	for (int i = 0; i < abs->m_size; i++)
	{
		if (abs->personArray[i].name == name) 
		{
			return i;
		}
	}
	return -1;
}

void deletPerson(AddressBooks * abs)		//删除联系人
{
	cout << "请输入要删除的联系人名称" << endl;
	string name;
	cin >> name;

	int ret = isExist(abs, name);
	if (ret != -1) {
		for (; ret < abs->m_size - 1; ret++) {	//用后面的覆盖前面的以达到删除的效果
			abs->personArray[ret] = abs->personArray[ret + 1];
		}
		abs->m_size--;
		cout << "删除成功" << endl;
	}
	else {
		cout << "联系人不存在" << endl;
	}
	system("pause");
}

void findPerson(AddressBooks * abs)
{
	string name;
	cout << "请输入要查找的联系人名称：";
	cin >> name;
	int ret = isExist(abs, name);
	if (ret == -1) {
		cout << "联系人不存在" << endl;
	}
	else {
		cout << "找到此人，信息如下" << endl;
		cout << "姓名：" << abs->personArray[ret].name << "\t";
		cout << "年龄：" << abs->personArray[ret].age << "\t";
		cout << "性别：" << (abs->personArray[ret].sex == 1 ? "男" : "女") << endl;
	}
	system("pause");
}

void modifyPerson(AddressBooks* abs) 
{
	cout << "请输入要修改的联系人名称:";
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1) 
	{
		cout << "已找到该联系人,请重新输入联系人信息:" << endl;
		cout << "请输入姓名：" ;
		string nName;
		cin >> nName;
		abs->personArray[ret].name = nName;
		cout << "请输入年龄：" ;
		int nAge;
		cin >> nAge;
		abs->personArray[ret].age = nAge;
		while (1)
		{
			cout << "请输入性别：" << endl;
			cout << "1-----男" << endl;
			cout << "2-----女" << endl;
			int nSex;
			cin >> nSex;
			if (nSex != 1 && nSex != 2)
			{
				cout << "请重新输入" << endl;
			}
			else {
				abs->personArray[ret].sex = nSex;
				break;
			}
		}
		cout << "修改成功" << endl;
	}
	else {
		cout << "联系人不存在" << endl;
	}
	system("pause");
}

void cleanPerson(AddressBooks* abs) 
{
	abs->m_size = 0;
	cout << "通讯录已清空！" << endl;
	system("pause");
}

void showMenu()			//菜单
{
	cout << "***************************" << endl;
	cout << "****	1、添加联系人	***" << endl;
	cout << "****	2、显示联系人	***" << endl;
	cout << "****	3、删除联系人	***" << endl;
	cout << "****	4、查找联系人	***" << endl;
	cout << "****	5、修改联系人	***" << endl;
	cout << "****	6、清空联系人	***" << endl;
	cout << "****	0、退出通讯录	***" << endl;
	cout << "***************************" << endl;
}  


int main()
{
	AddressBooks abs;
	abs.m_size = 0;

	int select = 0;

	while (1)
	{
		system("cls");
		showMenu();
		cin >> select;
		switch (select)
		{
		case 1:	//添加
			addPerson(&abs);
			break;
		case 2:	//展示
			dispaly(&abs);
			break;
		case 3:	//删除
		{
			deletPerson(&abs);
		}
		break;
		case 4:	//查找
		{
			findPerson(&abs);
		}
		break; 
		case 5:	//修改
			modifyPerson(&abs);
			break;
		case 6:	//清空
			cleanPerson(&abs);
			break;
		case 0:	//退出
		{
			cout << "欢迎下次使用！！！" << endl;
			system("pause");
			return 0;
		}
			break;
		default:
			break;
		}
	}
	
	
	return 0;
}
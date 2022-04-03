#include<iostream>
using namespace std;
#include<string>

#define MAX  1000	//ͨѶ¼������������ϵ�˸���

struct Person
{
	string name;
	int age;
	int sex;
};

struct AddressBooks
{
	struct Person personArray[MAX];	//ͨѶ¼�б������ϵ������
	int m_size;	//ͨѶ¼����ϵ�˸���
};




void addPerson(AddressBooks * abs)		//�����ϵ��
{
	if (abs->m_size >= MAX)
	{
		cout << "ͨѶ¼����" << endl;
		return;
	}
	string name;
	int sex,age;
	cout << "������������";
	cin >> name;
	cout << "���������䣺";
	cin >> age;
	while (1)
	{
		cout << "�������Ա�" << endl;
		cout << "1-----��" << endl;
		cout << "2-----Ů" << endl;
		cin >> sex;
		if (sex != 1 && sex != 2)
		{
			cout << "����������" << endl;
		}
		else {
			break;
		}
	}
	abs->personArray[abs->m_size].name = name;
	abs->personArray[abs->m_size].age = age;
	abs->personArray[abs->m_size].sex = sex;
	abs->m_size++;
	cout << "��ӳɹ�" << endl;
	system("pause");
}

void dispaly(AddressBooks *abs)		//չʾ��ϵ��
{
	if (abs->m_size == 0) {
		cout << "ͨѶ¼Ϊ��" << endl;
		system("pause");
	}
	else
	{
		int ret;

		for (ret = 0; ret < abs->m_size; ret++)
		{
			cout << "������" << abs->personArray[ret].name<<"\t";
			cout << "���䣺" << abs->personArray[ret].age << "\t";
			cout << "�Ա�" << (abs->personArray[ret].sex == 1 ? "��":"Ů") << endl;
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

void deletPerson(AddressBooks * abs)		//ɾ����ϵ��
{
	cout << "������Ҫɾ������ϵ������" << endl;
	string name;
	cin >> name;

	int ret = isExist(abs, name);
	if (ret != -1) {
		for (; ret < abs->m_size - 1; ret++) {	//�ú���ĸ���ǰ����Դﵽɾ����Ч��
			abs->personArray[ret] = abs->personArray[ret + 1];
		}
		abs->m_size--;
		cout << "ɾ���ɹ�" << endl;
	}
	else {
		cout << "��ϵ�˲�����" << endl;
	}
	system("pause");
}

void findPerson(AddressBooks * abs)
{
	string name;
	cout << "������Ҫ���ҵ���ϵ�����ƣ�";
	cin >> name;
	int ret = isExist(abs, name);
	if (ret == -1) {
		cout << "��ϵ�˲�����" << endl;
	}
	else {
		cout << "�ҵ����ˣ���Ϣ����" << endl;
		cout << "������" << abs->personArray[ret].name << "\t";
		cout << "���䣺" << abs->personArray[ret].age << "\t";
		cout << "�Ա�" << (abs->personArray[ret].sex == 1 ? "��" : "Ů") << endl;
	}
	system("pause");
}

void modifyPerson(AddressBooks* abs) 
{
	cout << "������Ҫ�޸ĵ���ϵ������:";
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1) 
	{
		cout << "���ҵ�����ϵ��,������������ϵ����Ϣ:" << endl;
		cout << "������������" ;
		string nName;
		cin >> nName;
		abs->personArray[ret].name = nName;
		cout << "���������䣺" ;
		int nAge;
		cin >> nAge;
		abs->personArray[ret].age = nAge;
		while (1)
		{
			cout << "�������Ա�" << endl;
			cout << "1-----��" << endl;
			cout << "2-----Ů" << endl;
			int nSex;
			cin >> nSex;
			if (nSex != 1 && nSex != 2)
			{
				cout << "����������" << endl;
			}
			else {
				abs->personArray[ret].sex = nSex;
				break;
			}
		}
		cout << "�޸ĳɹ�" << endl;
	}
	else {
		cout << "��ϵ�˲�����" << endl;
	}
	system("pause");
}

void cleanPerson(AddressBooks* abs) 
{
	abs->m_size = 0;
	cout << "ͨѶ¼����գ�" << endl;
	system("pause");
}

void showMenu()			//�˵�
{
	cout << "***************************" << endl;
	cout << "****	1�������ϵ��	***" << endl;
	cout << "****	2����ʾ��ϵ��	***" << endl;
	cout << "****	3��ɾ����ϵ��	***" << endl;
	cout << "****	4��������ϵ��	***" << endl;
	cout << "****	5���޸���ϵ��	***" << endl;
	cout << "****	6�������ϵ��	***" << endl;
	cout << "****	0���˳�ͨѶ¼	***" << endl;
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
		case 1:	//���
			addPerson(&abs);
			break;
		case 2:	//չʾ
			dispaly(&abs);
			break;
		case 3:	//ɾ��
		{
			deletPerson(&abs);
		}
		break;
		case 4:	//����
		{
			findPerson(&abs);
		}
		break; 
		case 5:	//�޸�
			modifyPerson(&abs);
			break;
		case 6:	//���
			cleanPerson(&abs);
			break;
		case 0:	//�˳�
		{
			cout << "��ӭ�´�ʹ�ã�����" << endl;
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
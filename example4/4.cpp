#include<iostream>
using namespace std;

float checkAgeScore(int age, float score)
{
	if (age < 19 || age>25)
		throw age;
	if (score < 0 || score>5)
		throw score;
	return score * 20;
}

int main()
{
	char name[20];
	int age;
	float score;
	cout << "������һ��ѧ�������������䡢�ٷ��Ƴɼ���" << endl;
	cin >> name >> age >> score;
	
	try
	{
		score = checkAgeScore(age, score);
		cout << "������" << name << " ���䣺" << age << " �ٷ��Ƴɼ���" << score << endl;
	}
	catch (int)
	{
		cout << "��������" << endl;
	}
	catch (float)
	{
		cout << "��������" << endl;
	}
	system("pause");
	return 0;
}
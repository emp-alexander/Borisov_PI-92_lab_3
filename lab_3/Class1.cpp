#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <malloc.h>
#include <iostream>
#include <string>
#pragma warning (disable:4996)
#define SIZE 25
using namespace std;


class Engine {
public:
	Engine()
	{

	}
	Engine(int cylinders, int capacity, int power)
	{
		this->cylinders = cylinders;
		this->capacity = capacity;
		this->power = power;
	}
	string GetInfo()
	{
		return "���������: ���-�� ��������� = " + to_string(cylinders) + " ����� = " + to_string(capacity) + " �������� = " + to_string(power);
	}
	void Read()
	{
		puts("������� ���-�� ��������� � ���������:");
		scanf("%d", &this->cylinders);
		fflush(stdin);

		puts("������� ����� ���������:");
		scanf("%d", &this->capacity);
		fflush(stdin);

		puts("������� �������� ���������:");
		scanf("%d", &this->power);
		fflush(stdin);
	}
	
	private:
	int cylinders;
	int capacity;
	int power;
};

class Auto_show
{
public:

	Auto_show()
	{

	}
	~Auto_show()
	{

	}

	void init(const char* brend, const char* name, int cost, int max_speed, int year, Engine eng1)
	{
		strcpy(this->autoBrend, brend);
		strcpy(this->autoName, name);
		this->autoCost = cost;
		this->autoMax_speed = max_speed;
		this->autoYear = year;
		this->autoeng1 = eng1;

	}

	void Display()
	{

		printf("\n�����: %s\n", this->autoBrend);
		printf("��������: %s\n", this->autoName);
		printf("���������: %d\n", this->autoCost);
		printf("������������ ��������: %d\n", this->autoMax_speed);
		printf("��� �������: %d\n", this->autoYear);
		cout << autoeng1.GetInfo() << endl << endl;
		//printf("\n");

	}

	void Read()
	{

		puts("������� ����� ����������:");
		scanf("%s", this->autoBrend);
		fflush(stdin);

		puts("������� �������� ����������:");
		scanf("%s", this->autoName);
		fflush(stdin);


		puts("������� ��������� ����������:");
		scanf("%d", &this->autoCost);
		fflush(stdin);

		puts("������� ������������ �������� ����������:");
		scanf("%d", &this->autoMax_speed);
		fflush(stdin);

		puts("������� ��� ������� ����������:");
		scanf("%d", &this->autoYear);
		fflush(stdin);

		autoeng1.Read();

	}

	int Add(Auto_show second)
	{
		return this->autoCost + second.autoCost;
	}
	


private:
	char autoBrend[SIZE];
	char autoName[SIZE];
	int autoCost;
	int autoMax_speed;
	int autoYear;
	Engine autoeng1;
	//Engine eng2;
};





int main()
{
	setlocale(LC_ALL, "ru");


	puts("������ ����������");

	Auto_show first_auto;
	Engine autoeng(4, 2, 100);
	first_auto.init("lada", "granta", 300, 150, 2017, autoeng);
	first_auto.Display();


	
	puts("������ ����������");
	Auto_show second_auto;
	second_auto.Read();

	second_auto.Display();

	printf("��������� ���� �����������: %d\n", second_auto.Add(first_auto));

	//�������.

	puts("������ ����������");
	Auto_show* auto_1 = (Auto_show*)malloc(sizeof(Auto_show));
	Engine autoeng_1(4, 2, 100);
	(*auto_1).init("lada", "granta", 300, 150, 2017, autoeng_1);
	(*auto_1).Display();

	puts("������ ����������");
	Auto_show* auto_2 = (Auto_show*)calloc(1, sizeof(Auto_show));
	(*auto_2).Read();
	(*auto_2).Display();

	free(auto_1);
	free(auto_2);



	return 0;

}

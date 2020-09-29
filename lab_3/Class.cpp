#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <malloc.h>
#pragma warning (disable:4996)
#define SIZE 25
//using namespace std;


class Auto_show
{
public:

	Auto_show()
	{

	}
	~Auto_show()
	{

	}

	void init(const char* brend, const char* name, int cost, int max_speed, int year)
	{
		strcpy(this->autoBrend, brend);
		strcpy(this->autoName, name);
		this->autoCost = cost;
		this->autoMax_speed = max_speed;
		this->autoYear = year;
	}

	void Display()
	{

		printf("\n�����: %s\n", this->autoBrend);
		printf("��������: %s\n", this->autoName);
		printf("���������: %d\n", this->autoCost);
		printf("������������ ��������: %d\n", this->autoMax_speed);
		printf("��� �������: %d\n", this->autoYear);
		printf("\n");

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


};





int main()
{
	setlocale(LC_ALL, "ru");


	puts("������ ����������");

	Auto_show first_auto;
	first_auto.init("lada", "granta", 300, 150, 2017);
	first_auto.Display();

	puts("������ ����������");
	Auto_show second_auto;
	second_auto.Read();
	second_auto.Display();

	printf("��������� ���� �����������: %d\n", second_auto.Add(first_auto));

	//�������.

	puts("������ ����������");
	Auto_show* auto_1 = (Auto_show*)malloc(sizeof(Auto_show));
	
	(*auto_1).init("lada", "granta", 300, 150, 2017);
	(*auto_1).Display();

	puts("������ ����������");
	Auto_show* auto_2 = (Auto_show*)calloc(1, sizeof(Auto_show));
	(*auto_2).Read();
	(*auto_2).Display();

	free(auto_1);
	free(auto_2);


	return 0;

}
#include <stdio.h>
#include <string.h>
#include <locale.h>
#pragma warning (disable:4996)
#define SIZE 25
using namespace std;


class Auto_show
{
public:

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



	//�������.



	return 0;
}
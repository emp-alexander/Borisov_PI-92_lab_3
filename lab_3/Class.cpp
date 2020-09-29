#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <malloc.h>
#include <iostream>
#pragma warning (disable:4996)
#define SIZE 25



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

		printf("\nМарка: %s\n", this->autoBrend);
		printf("Название: %s\n", this->autoName);
		printf("Стоимость: %d\n", this->autoCost);
		printf("Максимальная скорость: %d\n", this->autoMax_speed);
		printf("Год выпуска: %d\n", this->autoYear);
		printf("\n");

	}

	void Read()
	{

		puts("Введите марку автомобиля:");
		scanf("%s", this->autoBrend);
		fflush(stdin);
		
		puts("Введите название автомобиля:");
		scanf("%s", this->autoName);
		fflush(stdin);
		

		puts("Введите стоимость автомобиля:");
		scanf("%d", &this->autoCost);
		fflush(stdin);

		puts("Введите максимальную скорость автомобиля:");
		scanf("%d", &this->autoMax_speed);
		fflush(stdin);
		
		puts("Введите год выпуска автомобиля:");
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


	puts("Первый автомобиль");

	Auto_show first_auto;
	first_auto.init("lada", "granta", 300, 150, 2017);
	first_auto.Display();

	puts("Второй автомобиль");
	Auto_show second_auto;
	second_auto.Read();
	second_auto.Display();

	printf("Стоимость двух автомобилей: %d\n", second_auto.Add(first_auto));

	//Динамич.

	puts("Первый автомобиль");
	Auto_show* auto_1 = (Auto_show*)malloc(sizeof(Auto_show));
	
	(*auto_1).init("lada", "granta", 300, 150, 2017);
	(*auto_1).Display();

	puts("Второй автомобиль");
	Auto_show* auto_2 = (Auto_show*)calloc(1, sizeof(Auto_show));
	(*auto_2).Read();
	(*auto_2).Display();

	free(auto_1);
	free(auto_2);


	//динамич. массив объектов

	puts("Динамич. массив");

	puts("Первый автомобиль");
	Auto_show* car1 = new Auto_show[3];

	car1[0].init("lada", "granta", 300, 150, 2017);
	car1[1].init("lada", "vesta", 900, 180, 2020);
	car1[2].init("nissan", "gt-r", 3500, 300, 2014);
	for (int i = 0; i < 3; i++)
	{
		car1[i].Display();
	}



	puts("Второй автомобиль");
	Auto_show** car2 = new Auto_show * [3];
	for (int i = 0; i < 3; i++)
	{
		car2[i] = new Auto_show();
		car2[i]->init("lada", "granta", 300, 150, 2017);
		std::cout << "Стоимость: " << i << car2[i]->Add(car1[i]) << std::endl;
	}
	for (int i = 0; i < 3; i++)
		delete car2[i];
	delete[] car2;
	delete[] car1;



	return 0;

}
#include "Sundae.h"
#include<string.h>
#include<iostream>

using namespace std;

Sundae::Sundae()
{
	pr_cost_of_toping = 0;
	pr_toping = nullptr;
}

Sundae::Sundae(int toping_cost, const char* toping_name, int cost, const char* flavour, const char* Name) :IceCream(cost, flavour, Name)
{
	pr_cost_of_toping = toping_cost;

	int length = 0;
	length = strlen(toping_name);

	pr_toping = new char[length + 1];
	for (int i = 0; i < length; i++)
	{
		pr_toping[i] = toping_name[i];
	}

	pr_toping[length] = '\0';
}

void Sundae::set_price(int price)
{
	pr_cost_of_toping = price;
}

int Sundae::get_cost()
{
	int i_cost=IceCream::get_cost();
	int cost = i_cost + pr_cost_of_toping;

	return cost;
}

int Sundae::get_tax()
{
	float price = this->get_cost();
	float tax = price * 0.02;
	int rounded_tax = round(tax);
	return tax;
}

void Sundae::print()
{
	DesertItem::print();
	cout << "	Flavour of Sundae : " << IceCream::get_flavour() << endl;
	cout << "	Price of Sundae : " << IceCream::get_cost() << endl;
	cout << "	Toping of Sundae :  "<<pr_toping << endl;
	cout << "	Cost of Toping : "<<pr_cost_of_toping << endl;

	cout << "	Cost Without Tax :  "<<this->get_cost() << endl;
	cout << "	Tax : "<<this->get_tax() << endl;
	cout << "	Total Cost : "<<this->get_cost()+this->get_tax() << endl;
	
}

Sundae::~Sundae()
{
	delete[]pr_toping;
}

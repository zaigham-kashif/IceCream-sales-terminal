#include "IceCream.h"
#include<string.h>
#include<iostream>

using namespace std;

IceCream::IceCream()
{
	pr_cost = 0;
	pr_flavour = nullptr;
}

IceCream::IceCream(int price, const char* flavour, const char* name) :DesertItem(name)
{
	pr_cost = price;

	int lenght = 0;
	lenght = strlen(flavour);

	pr_flavour = new char[lenght + 1];

	for (int i = 0; i < lenght; i++)
	{
		pr_flavour[i] = flavour[i];
	}

	pr_flavour[lenght] = '\0';

}

void IceCream::set_price(int price)
{
	pr_cost = price;
}


int IceCream::get_cost()
{
	return pr_cost;
}

int IceCream::get_tax()
{
	float price = this->get_cost();
	float tax = price * 0.02;
	int rounded_tax = round(tax);
	return tax;
}

const char* IceCream::get_flavour()
{
	return pr_flavour;
}

void IceCream::print()
{
	DesertItem::print();
	cout << "	Flavour of icecream : " << pr_flavour << endl;
	cout << "	Price of IceCream : " << pr_cost << endl;
	cout << "	Price Without Tax" << this->get_cost() << endl;
	cout << "	Tax : " << this->get_tax() << endl;
	cout << "	Net Price : " << this->get_cost() + this->get_tax() << endl;
}

IceCream::~IceCream()
{
	delete[]pr_flavour;
}

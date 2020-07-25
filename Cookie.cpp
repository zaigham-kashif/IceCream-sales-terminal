#include "Cookie.h"
#include<iostream>

using namespace std;

Cookie::Cookie()
{
	pr_no_of_cookies = 0;
	pr_PPD = 0;
}

Cookie::Cookie(int no, int price, const char* Name) :DesertItem(Name)
{
	pr_no_of_cookies = no;
	pr_PPD = price;
}

void Cookie::set_NoOfCookies(int no)
{
	pr_no_of_cookies = no;
}

void Cookie::set_PPD(int price)
{
	pr_PPD = price;
}

int Cookie::get_NoOfCookies()
{
	return pr_no_of_cookies;
}

int Cookie::get_PPD()
{
	return pr_PPD;
}

int Cookie::get_cost()
{
	int cost_per_cookie;
	cost_per_cookie = pr_PPD / pr_no_of_cookies;

	int cost = 0;
	cost = pr_no_of_cookies * cost_per_cookie;

	int x = cost % 10;

	if (x < 5)
	{
		cost = cost - x;
	}
	else
	{
		cost = cost - x;
		cost = cost + 10;
	}

	return cost;
}

int Cookie::get_tax()
{
	float price = this->get_cost();
	float tax = price * 0.02;
	int rounded_tax = round(tax);
	return tax;
}

void Cookie::print()
{
	DesertItem::print();
	cout << "	Price per doze of cookies : "<<pr_PPD << endl;
	cout << "	Number of Cookies : "<<pr_no_of_cookies << endl;
	cout << "	Price Without Tax"<<this->get_cost() << endl;
	cout << "	Tax : "<<this->get_tax() << endl;
	cout << "	Net Price : " << this->get_cost() + this->get_tax() << endl;
}



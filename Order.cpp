#include<iostream>
#include "Order.h"
#include"Cookie.h"
#include"IceCream.h"
#include"Sundae.h"

using namespace std;

Order::Order()
{
	pr_no_of_items = 0;
	pr_items_list = nullptr;
}

Order::Order(int no)
{
	pr_no_of_items = no;
	pr_items_list = new DesertItem*[pr_no_of_items];
}

void Order::place_order()
{
	int option = 1;

	for (int i = 0; i < pr_no_of_items; i++)
	{
		do
		{
			if (option <= 0 || option > 3)
			{
				cout << "	Invalid option selected" << endl;
			}
			cout << "	Select an option from menu below : " << endl;
			cout << "	1-> Cookie" << endl;
			cout << "	2-> IceCream" << endl;
			cout << "	3-> Sundae" << endl;
			cout << "	";
			cin >> option;
		}
		while (option <= 0 || option > 3);

		if (option == 1)
		{
			int no = 0, price = 0;
			cout << "	Enter price per dozen : ";
			cin >> price;

			cout << "	Enter No of cookies : ";
			cin >> no;

			pr_items_list[i] = new Cookie(no, price, "Cookie");
		}
		else if (option == 2)
		{
			int price = 0;
			char flavour[30];

			cin.ignore();
			cout << "	Enter Flavour of ice cream : ";
			cin.getline(flavour, 30);

			cout << "	Enter price of ice cream : ";
			cin >> price;

			pr_items_list[i] = new IceCream(price, flavour, "IceCream");
		}
		else if (option == 3)
		{
			int price_1 = 0, price_2 = 0;
			char flavour[30], toping[30];

			cin.ignore();
			cout << "	Enter Flavour of ice cream : ";
			cin.getline(flavour, 30);

			cout << "	Enter price of ice cream : ";
			cin >> price_1;

			cin.ignore();
			cout << "	Enter Toping of Sundae : ";
			cin.getline(toping, 30);

			cout << "	Enter price of toping : ";
			cin >> price_2;

			pr_items_list[i] = new Sundae(price_2, toping, price_1, flavour, "Sundae");
		}
	}
	
}

void Order::print_order()
{
	int total_cost = 0;
	int total_tax = 0;

	for (int i = 0; i < pr_no_of_items; i++)
	{
		cout << endl;
		cout << "	Item No " << i + 1 << endl;
		pr_items_list[i][0].print();
		cout << endl;

		total_cost = pr_items_list[i][0].get_cost() + total_cost;
		total_tax = total_tax + pr_items_list[i][0].get_tax();
	}

	cout << endl;
	cout << "	Total Cost of order is"<<total_cost << endl;
	cout << "	Total Tax of order is" << total_tax << endl;

	cout << "	Net Total : " << total_cost + total_tax << endl;
}

Order::~Order()
{
	for (int i = 0; i < pr_no_of_items; i++)
	{
		delete pr_items_list[i];
	}

	delete[]pr_items_list;
	pr_items_list = nullptr;
}

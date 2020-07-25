#include<iostream>
#include"Order.h"

using namespace std;

void main() {
	int totalOrders;
	cout << "How many orders you want to place: ?";
	cin >> totalOrders;
	Order** ordersList = new Order*[totalOrders];
	for (int i = 0; i < totalOrders; i++)
	{
		int itemsCount;
		cout << "How many items you want: ?";
		cin >> itemsCount;
		ordersList[i] = new Order(itemsCount);
		ordersList[i]->place_order();
	}

	for (int i = 0; i < totalOrders; i++)
	{
		cout << "	Order Number : " << i + 1 << endl;
		ordersList[i]->print_order();
	}

	for (int i = 0; i < totalOrders; i++)
	{
		delete ordersList[i];
	}
	delete[]ordersList;
	ordersList = nullptr;

}

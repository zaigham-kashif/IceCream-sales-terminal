#pragma once
#include"DesertItem.h"


class Order
{
	private:
		int pr_no_of_items;
		DesertItem** pr_items_list;
	public:
		Order();
		Order(int);

		void place_order();
		void print_order();

		~Order();
};


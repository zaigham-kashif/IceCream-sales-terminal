#pragma once
#include"DesertItem.h"

class IceCream : public DesertItem
{
	private:
		int pr_cost;
		char* pr_flavour;

	public:
		IceCream();
		IceCream(int,const char*,const char*);

		void set_price(int);

		int get_cost() override;
		int get_tax() override;

		const char* get_flavour();

		void print() override;

		~IceCream();

};


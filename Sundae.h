#pragma once
#include"IceCream.h"

class Sundae:public IceCream
{
	private:
		int pr_cost_of_toping;
		char* pr_toping;

	public:

		Sundae();
		Sundae(int, const char*, int, const char*,const char*);

		void set_price(int);

		int get_cost() override;
		int get_tax() override;

		void print() override;

		~Sundae();
};


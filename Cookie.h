#pragma once

#include"DesertItem.h"

class Cookie:public DesertItem
{
	private:
		int pr_no_of_cookies;
		int pr_PPD;
	public:

		Cookie();
		Cookie(int, int, const char*);

		void set_NoOfCookies(int);
		void set_PPD(int);

		int get_NoOfCookies();
		int get_PPD();

		int get_cost() override;
		int get_tax() override;

		void print() override;

};


#pragma once
class DesertItem
{
	private:
		char* pr_name;
	public:
		DesertItem();
		DesertItem(const char*);

		void set_name(const char*);

		virtual int get_cost();
		virtual int get_tax();

		virtual void print();

		~DesertItem();

};

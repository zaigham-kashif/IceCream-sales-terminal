#include "DesertItem.h"
#include<string.h>
#include<iostream>

DesertItem::DesertItem()
{
	pr_name = nullptr;
}

DesertItem::DesertItem(const char* Name)
{
	int length = strlen(Name);

	pr_name = new char[length + 1];

	for (int i = 0; i < length; i++)
	{
		pr_name[i] = Name[i];
	}

	pr_name[length] = '\0';
}

void DesertItem::set_name(const char* Name)
{
	int length = strlen(Name);

	pr_name = new char[length + 1];
	strcpy_s(pr_name, length, Name);
}

int DesertItem::get_cost()
{
	return 0;
}

int DesertItem::get_tax()
{
	return 0;
}

void DesertItem::print()
{
	std::cout <<"	"<< pr_name << std::endl;
}

DesertItem::~DesertItem()
{
	delete[]pr_name;
	pr_name = nullptr;
}

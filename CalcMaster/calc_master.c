//
// CalcMaster - A Multi-Functional Calculator Written In Modern C.
// Copyright (c) 2023 Lokesh Wankhede.
//

#include <stdio.h>

#include "calc_master.h"
#include "menu.h"

int main(void)
{
	// Display a main menu and performs actions based on the user's choice.
	while (1)
	{
		show_categories_menu();
		const char category_menu_choice = get_valid_categories_menu_choice();

		if (category_menu_choice == 'G')
			break;

		if (category_menu_choice >= 'A' && category_menu_choice <= 'G')
			show_sub_categories_menu(category_menu_choice);
	}

	printf(" Goodbye!\n");

	return 0;
}

//
// CalcMaster - A Multi-Functional Calculator Written In Modern C.
// Copyright (c) 2023 Lokesh Wankhede.
//

#include <stdio.h>

#include "calc_master.h"

#include <stdlib.h>
#include <time.h>

#include "menu.h"

int main(void)
{
	// wait for 1s to make sure the console is visible.
	// temporary fix for windows.
	const clock_t start_time = clock();
	const clock_t end_time = start_time + (1000 * CLOCKS_PER_SEC / 1000);
	while (clock() < end_time) {}

	// Display a main menu and performs actions based on the user's choice.
	while (1)
	{
		show_categories_menu();
		const char category_menu_choice = get_valid_categories_menu_choice();

		if (category_menu_choice == 'H')
			break;

		if (category_menu_choice >= 'A' && category_menu_choice <= 'H')
			show_sub_categories_menu(category_menu_choice);
	}

	printf(" Goodbye!\n");

	return 0;
}

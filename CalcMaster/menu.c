//
// CalcMaster - A Multi-Functional Calculator Written In Modern C.
// Copyright (c) 2023 Lokesh Wankhede.
//

// ReSharper disable CppDeprecatedEntity
#include <ctype.h>
#include <stdio.h>

#include "menu.h"
#include "calc_master.h"

#include <stdlib.h>
#include <string.h>

#include "operations.h"

/**
 * Clears the input buffer by reading and discarding any remaining
 * characters until a newline or end-of-file character is encountered.
 */
void clear_input_buffer(void)
{
	int c;
	while ((c = getchar()) != '\n' && c != EOF);
}

/**
 * Displays information about the CalcMaster and its version.
 */
void show_app_info(void)
{
	CLEAR_SCREEN;
	printf(COLOR_BLUE "\n -----------------------------------------------------------------------\n" COLOR_RESET);
	printf(COLOR_GREEN TEXT_BOLD " *  CalcMaster - A Multi-Functional Calculator Written In Modern C \n" COLOR_RESET);
	printf(COLOR_CYAN " *  Copyright (c) 2023 Lokesh Wankhede\n" COLOR_RESET);
	printf(COLOR_CYAN " *  Website: logicallokesh.net\n" COLOR_RESET);
	printf(COLOR_CYAN " *  Version %s\n" COLOR_RESET, CALC_VERSION);
	printf(COLOR_BLUE " -----------------------------------------------------------------------\n" COLOR_RESET);
}

/**
 * Reads and validates a user's choice from the category main menu.
 *
 * @note We are using some typecasting to avoid warnings of ReSharper and Visual Studio.
 * @return a character, which represents the valid choice selected from the menu.
 */
char get_valid_categories_menu_choice(void)
{
	printf("\n Enter your choice: ");
	int input = getchar();

	if (input == '\n' || input == EOF)
	{
		// Handle empty input
		return '0';
	}

	clear_input_buffer(); // Discard any additional characters

	while (input < 'A' || input > 'K')
	{
		printf("\n Invalid choice. Please enter a valid option: ");
		input = getchar();

		if (input == '\n' || input == EOF)
		{
			// Handle empty input
			return '0';
		}

		clear_input_buffer(); // Discard any additional characters
	}

	// ReSharper disable once CppRedundantCastExpression
	return (char)input;
}

/**
 * Reads and validates a user's choice for a sub operations menu option,
 * returning the choice as a int.
 *
 * @return a int, which represents the valid choice entered by the user.
 */
int get_valid_operations_menu_choice(const int max_operations_available)
{
	int choice;
	char input[2]; // Assuming the input won't exceed 2 characters

	while (1)
	{
		printf(" Enter your choice: ");
		if (fgets(input, sizeof(input), stdin) == NULL)
		{
			printf(" Error reading input.\n");
			return -1;
		}

		// cleanup
		clear_input_buffer();

		// Remove the newline character from input
		input[strcspn(input, "\n")] = '\0';

		// Check if input consists only of digits
		int is_digit = 1;
		for (size_t i = 0; i < strlen(input); i++)
		{
			if (!isdigit(input[i]))
			{
				is_digit = 0;
				break;
			}
		}

		if (!is_digit)
		{
			printf(" Invalid input. Please enter a number.\n");
			continue;
		}

		choice = atoi(input);

		// Check if the choice is within the valid range
		if (choice < 1 || choice > max_operations_available)
		{
			printf(" Invalid choice. Please enter a number between 1 and %d.\n", max_operations_available);
			continue;
		}

		break; // Valid input, exit the loop
	}

	return choice;
}


/**
 * Displays a main category menu with various options for different types of sub-categories.
 */
void show_categories_menu(void)
{
	const char* categories[] = {
		"Arithmetic Operations",
		"Comparison Operations",
		"Logical Operations",
		"Bitwise Operations",
		"Modulus Operation",
		"Matrix Operations",
		"Number Properties",
		"Exit"
	};

	PRINT_MAIN_MENU("Main Menu", categories);
}


/**
 * Displays a category menu based on the user's choice and performs an action
 * based on the category menu option selected.
 *
 * @param sub_category_choice A character that represents the choice of the sub category menu.
 * It is used in the switch statement to determine which category menu to show.
 */
void show_sub_categories_menu(const char sub_category_choice)
{
	switch (sub_category_choice)
	{
	case 'A':
		perform_arithmetic_operations();
		clear_input_buffer();
		// wait for user to press enter
		printf(" Press enter to continue...");
		PAUSE
			break;

	case 'B':
		perform_comparison_operations();
		clear_input_buffer();
		// wait for user to press enter
		printf(" Press enter to continue...");
		PAUSE
			break;

	case 'C':
		perform_logical_operations();
		clear_input_buffer();
		// wait for user to press enter
		printf(" Press enter to continue...");
		PAUSE
			break;

	case 'D':
		perform_bitwise_operations();
		clear_input_buffer();
		// wait for user to press enter
		printf(" Press enter to continue...");
		PAUSE
			break;

	case 'E':
		perform_modulo_operation();
		clear_input_buffer();
		// wait for user to press enter
		printf(" Press enter to continue...");
		PAUSE
			break;

	case 'F':
		perform_matrix_operations();
		// wait for user to press enter
		printf(" Press enter to continue...");
		PAUSE
			break;
	case 'G':
		find_number_properties();
		// wait for user to press enter
		printf(" Press enter to continue...");
		PAUSE
			break;

	default:
		break;
	}
}

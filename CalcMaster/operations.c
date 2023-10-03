//
// CalcMaster - A Multi-Functional Calculator Written In Modern C.
// Copyright (c) 2023 Lokesh Wankhede.
//

// Disable the _CRT_SECURE_NO_WARNINGS for Visual Studio & ReSharper
// ReSharper disable once CppInconsistentNaming
// ReSharper disable CppDeprecatedEntity
#define _CRT_SECURE_NO_WARNINGS  // NOLINT(bugprone-reserved-identifier)

#include <stdio.h>
#include <stdlib.h>

#include "operations.h"

#include "calc_master.h"
#include "menu.h"
#include "number_properties.h"


/**
 * Prompts the user for an integer input, validates it, and
 * returns the valid input.
 *
 * @param prompt The prompt is a string that will be displayed to the user to ask for input.
 * It provides clear instructions on what kind of input is expected.
 *
 * @return an integer value.
 */
int get_valid_integer_input(const char* prompt)
{
	int value;

	while (1)
	{
		char input_buffer[256];
		printf("%s ", prompt);
		fgets(input_buffer, sizeof(input_buffer), stdin); // NOLINT(cert-err33-c)

		// Convert the input to an integer
		char* endptr;
		value = strtol(input_buffer, &endptr, 10);

		// Check for conversion errors and valid input
		if (endptr == input_buffer || *endptr != '\n' || value < 0)
			printf(" Invalid input. Please enter a valid positive integer.\n");
		else
			break;
	}

	return value;
}


/**
 * Performs arithmetic operations (addition, subtraction, multiplication, and division) on
 * a given set of numbers and displays the result with two decimal places.
 *
 * @return operation_return_reason
 */
enum operation_return_reason perform_arithmetic_operations(void)
{
	// Build the operations menu and show to the user
	const char* operations[] = {
		"Addition",
		"Subtraction",
		"Multiplication",
		"Division"
	};

	PRINT_SUB_MENU("Arithmetic Operations", operations);

	const int operations_choice = get_valid_operations_menu_choice(sizeof(operations) / sizeof(operations[0]));

	if (operations_choice == 0)
	{
		printf(" Press enter to go back...");
		return return_reason_user_exit;
	}

	int num_count;
	printf(" Enter the number of values: ");
	if (scanf("%d", &num_count) != 1 || num_count <= 0)
	{
		printf(" Invalid input for the number of values.\n");
		return return_reason_error;
	}

	double result, num;

	printf(" Enter value 1: ");
	if (scanf("%lf", &result) != 1)
	{
		printf(" Invalid input for value 1.\n");
		return return_reason_error;
	}

	for (int i = 1; i < num_count; ++i)
	{
		printf(" Enter value %d: ", i + 1);
		if (scanf("%lf", &num) != 1)
		{
			printf(" Invalid input for value %d.\n", i + 1);
			return return_reason_error;
		}

		switch (operations_choice)
		{
		case 1: // Addition
			result += num;
			break;
		case 2: // Subtraction
			result -= num;
			break;
		case 3: // Multiplication
			result *= num;
			break;
		case 4: // Division
			if ((int)num == 0)
			{
				printf(COLOR_RED " You can't handle the truth!\n" COLOR_RESET);
				return return_reason_error;
			}
			result /= num;
			break;
		default:
			printf(" Invalid operation choice.\n");
			return return_reason_error;
		}
	}

	// Accuracy = last two digits after decimal.
	printf(COLOR_GREEN"\n Result: %.2lf\n" COLOR_RESET, result);

	return return_reason_success;
}

/**
 * Performs various comparison operations on two input values and prints the result.
 *
 * @return operation_return_reason
 */
enum operation_return_reason perform_comparison_operations(void)
{
	// Build the operations menu and show
	const char* operations[] = {
		"Less than or equal to",
		"Greater than or equal to",
		"Equal to",
		"Not equal to",
		"Greater than",
		"Less than"
	};

	PRINT_SUB_MENU("Comparison Operations", operations);

	const int operations_choice = get_valid_operations_menu_choice(sizeof(operations) / sizeof(operations[0]));

	// check if user want to go back
	if (operations_choice == 0)
	{
		printf(" Press enter to go back...");
		return return_reason_user_exit;
	}

	double num1, num2;
	printf(" Enter value 1: ");
	if (scanf("%lf", &num1) != 1)
	{
		printf(" Invalid input for value 1.\n");
		return return_reason_error;
	}

	printf(" Enter value 2: ");
	if (scanf("%lf", &num2) != 1)
	{
		printf(" Invalid input for value 2.\n");
		return return_reason_error;
	}

	int result;

	switch (operations_choice)
	{
	case 1: // Less than or equal to
		result = num1 <= num2;
		break;
	case 2: // Greater than or equal to
		result = num1 >= num2;
		break;
	case 3: // Equal to
		result = (int)num1 == (int)num2;
		break;
	case 4: // Not equal to
		result = (int)num1 != (int)num2;
		break;
	case 5: // Greater than
		result = num1 > num2;
		break;
	case 6: // Less than
		result = num1 < num2;
		break;
	default:
		printf(" Invalid operation choice.\n");
		return return_reason_error;
	}

	printf(COLOR_GREEN "\n Result: %d\n" COLOR_RESET, result);

	return return_reason_success;
}

/**
 * Performs logical operations (AND, OR, NOT, XOR) on two input values and prints the
 * result.
 *
 * @return operation_return_reason
 */
enum operation_return_reason perform_logical_operations(void)
{
	const char* operations[] = {
		"AND",
		"OR",
		"NOT",
		"XOR"
	};

	PRINT_SUB_MENU("Logical Operations", operations);

	const int operations_choice = get_valid_operations_menu_choice(sizeof(operations) / sizeof(operations[0]));

	// check if user want to go back
	if (operations_choice == 0)
	{
		printf(" Press enter to go back...");
		return return_reason_user_exit;
	}


	int input1, input2, result;

	switch (operations_choice)
	{
	case 1: // AND  // NOLINT(bugprone-branch-clone)
		printf(" Enter value 1 (0 or 1): ");
		if (scanf("%d", &input1) == EOF) { PRINT_ERROR("Failed to read input."); }
		printf("  Enter value 2 (0 or 1): ");
		if (scanf("%d", &input2) == EOF) { PRINT_ERROR("Failed to read input."); }
		break;
	case 2: // OR
		printf(" Enter value 1 (0 or 1): ");
		if (scanf("%d", &input1) == EOF) { PRINT_ERROR("Failed to read input."); }
		printf(" Enter value 2 (0 or 1): ");
		if (scanf("%d", &input2) == EOF) { PRINT_ERROR("Failed to read input."); }
		break;
	case 3: // NOT
		printf(" Enter value (0 or 1): ");
		printf(" Enter value 1 (0 or 1): ");
		if (scanf("%d", &input1) == EOF) { PRINT_ERROR("Failed to read input."); }
		input2 = 0;
		break;
	case 4: // XOR
		printf(" Enter value 1 (0 or 1): ");
		if (scanf("%d", &input1) == EOF) { PRINT_ERROR(" Failed to read input."); }
		printf(" Enter value 2 (0 or 1): ");
		if (scanf("%d", &input2) == EOF) { PRINT_ERROR(" Failed to read input."); }
		break;
	default:
		printf(" Invalid operation choice.\n");
		return return_reason_error;
	}

	// Sanitize inputs
	input1 = (input1 != 0) ? 1 : 0;
	input2 = (input2 != 0) ? 1 : 0;

	switch (operations_choice)
	{
	case 1: // AND
		result = input1 && input2;
		break;
	case 2: // OR
		result = input1 || input2;
		break;
	case 3: // NOT
		result = !input1;
		break;
	case 4: // XOR
		result = (input1 || input2) && !(input1 && input2);
		break;
	default:
		return return_reason_error;
	}

	printf(COLOR_GREEN"\n Result: %d\n", result);

	return return_reason_success;
}

/**
 * Performs bitwise operations (left shift and right shift) on two input values and prints
 * the result.
 *
 * @return operation_return_reason
 */
enum operation_return_reason perform_bitwise_operations(void)
{
	const char* operations[] = {
		"Left Shift",
		"Right Shift"
	};

	PRINT_SUB_MENU("Bitwise Operations", operations);

	const int operations_choice = get_valid_operations_menu_choice(sizeof(operations) / sizeof(operations[0]));

	// check if user want to go back
	if (operations_choice == 0)
	{
		printf(" Press enter to go back...");
		return return_reason_user_exit;
	}

	int input1, input2, result;

	printf(" Enter value 1 (0 or 1): ");
	if (scanf("%d", &input1) == EOF) { PRINT_ERROR("Failed to read input."); }
	printf(" Enter value 2 (0 or 1): ");
	if (scanf("%d", &input2) == EOF) { PRINT_ERROR("Failed to read input."); }

	// Sanitize inputs
	input1 = (input1 != 0) ? 1 : 0;
	input2 = (input2 != 0) ? 1 : 0;

	switch (operations_choice)
	{
	case 1: // Left Shift
		result = input1 << input2;
		break;
	case 2: // Right Shift
		result = input1 >> input2;
		break;
	default:
		return return_reason_error;
	}
	printf(COLOR_RED"\n Result: %d\n", result);
	return return_reason_success;
}

/**
 * Performs a modulo operation on two user-inputted integers.
 *
 * @return operation_return_reason
 */
enum operation_return_reason perform_modulo_operation(void)
{
	const char* operations[] = {
		"Modulo"
	};

	PRINT_SUB_MENU("Modulo Operations", operations);

	const int operations_choice = get_valid_operations_menu_choice(sizeof(operations) / sizeof(operations[0]));

	// check if user want to go back
	if (operations_choice == 0)
	{
		printf(" Press enter to go back...");
		return return_reason_user_exit;
	}

	if (operations_choice == 1)
	{
		int divisor;
		int dividend;
		printf(" Enter dividend: ");

		if (scanf("%d", &dividend) == EOF) { PRINT_ERROR("Failed to read input."); }

		printf(" Enter divisor: ");
		if (scanf("%d", &divisor) == EOF) { PRINT_ERROR("Failed to read input."); }

		if (divisor == 0)
		{
			printf(" Error: You need glasses!\n");
			return return_reason_error;
		}

		printf(COLOR_GREEN "\n Result: %d\n", dividend % divisor);
		return return_reason_success;
	}

	printf(" Invalid operation choice.\n");
	return return_reason_error;
}

/**
 * Allows the user to input a number and choose from a menu of
 * operations to determine various properties of the number.
 *
 * @return operation_return_reason
 */
enum operation_return_reason find_number_properties(void)
{
	// Build the operations menu and show to the user
	const char* operations[] = {
		"Is Even",
		"Is Odd",
		"Is Prime",
		"Is Perfect Number",
		"Is Armstrong Number",
		"Is Palindrome"
	};

	PRINT_SUB_MENU("Number Properties", operations);

	const int operations_choice = get_valid_operations_menu_choice(sizeof(operations) / sizeof(operations[0]));

	// check if user want to go back
	if (operations_choice == 0)
	{
		printf(" Press enter to go back...");
		return return_reason_user_exit;
	}

	const int number = get_valid_integer_input(" Enter a number: ");

	switch (operations_choice)
	{
	case 1: // Is Even
		printf(COLOR_GREEN "\n %d %s an even number.\n" COLOR_RESET, number,
		       is_even(number) ? "is" : "not");
		break;

	case 2: // Is Odd
		printf(COLOR_GREEN "\n %d %s an odd number.\n" COLOR_RESET, number,
		       is_odd(number) ? "is" : "not");
		break;

	case 3: // Is Prime
		printf(COLOR_GREEN "\n %d %s a prime number.\n" COLOR_RESET, number,
		       is_prime(number) ? "is" : "not");
		break;

	case 4: // Is Perfect Number
		printf(COLOR_GREEN "\n %d %s a perfect number.\n" COLOR_RESET, number,
		       is_perfect_number(number) ? "is" : "not");
		break;

	case 5: // Is Armstrong Number
		printf(COLOR_GREEN "\n %d %s an Armstrong number.\n" COLOR_RESET, number,
		       is_armstrong_number(number) ? "is" : "not");
		break;

	case 6: // Is Palindrome
		printf(COLOR_GREEN "\n %d %s a Palindrome number.\n" COLOR_RESET, number,
		       is_palindrome(number) ? "is" : "not");
		break;

	default:
		printf(" Invalid operation choice.\n");
		return return_reason_error;
	}
	return return_reason_success;
}

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

#include <string.h>

#include "menu.h"

/**
 * Performs arithmetic operations (addition, subtraction, multiplication, and division) on
 * a given set of numbers and displays the result with two decimal places.
 *
 * @return The function does not have a return type specified, so it is returning nothing (void).
 */
void perform_arithmetic_operations(void)
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

	int num_count;
	printf(" Enter the number of values: ");
	if (scanf("%d", &num_count) != 1 || num_count <= 0)
	{
		printf(" Invalid input for the number of values.\n");
		return;
	}

	double result, num;

	printf(" Enter value 1: ");
	if (scanf("%lf", &result) != 1)
	{
		printf(" Invalid input for value 1.\n");
		return;
	}

	for (int i = 1; i < num_count; ++i)
	{
		printf(" Enter value %d: ", i + 1);
		if (scanf("%lf", &num) != 1)
		{
			printf(" Invalid input for value %d.\n", i + 1);
			return;
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
				return;
			}
			result /= num;
			break;
		default:
			printf(" Invalid operation choice.\n");
			return;
		}
	}

	// Accuracy = last two digits after decimal.
	printf(COLOR_GREEN" Result: %.2lf\n" COLOR_RESET, result);
}

/**
 * Performs various comparison operations on two input values and prints the result.
 *
 * @return The function does not have a return type specified, so it is returning void.
 */
void perform_comparison_operations(void)
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

	double num1, num2;
	printf(" Enter value 1: ");
	if (scanf("%lf", &num1) != 1)
	{
		printf(" Invalid input for value 1.\n");
		return;
	}

	printf(" Enter value 2: ");
	if (scanf("%lf", &num2) != 1)
	{
		printf(" Invalid input for value 2.\n");
		return;
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
		return;
	}

	printf(COLOR_GREEN " Result: %d\n" COLOR_RESET, result);
}

/**
 * Performs logical operations (AND, OR, NOT, XOR) on two input values and prints the
 * result.
 *
 * @return The function does not have a return type specified, so it does not explicitly return a
 * value.
 */
void perform_logical_operations(void)
{
	const char* operations[] = {
		"AND",
		"OR",
		"NOT",
		"XOR"
	};

	PRINT_SUB_MENU("Logical Operations", operations);

	const int operations_choice = get_valid_operations_menu_choice(sizeof(operations) / sizeof(operations[0]));

	int input1, input2, result;

	switch (operations_choice)
	{
	case 1: // AND  // NOLINT(bugprone-branch-clone)
		printf(" Enter value 1 (0 or 1): ");
		if (scanf("%d", &input1) == EOF)
		{
			PRINT_ERROR("Failed to read input.");
		}
		printf("  Enter value 2 (0 or 1): ");
		if (scanf("%d", &input2) == EOF)
		{
			PRINT_ERROR("Failed to read input.");
		}
		break;
	case 2: // OR
		printf(" Enter value 1 (0 or 1): ");
		if (scanf("%d", &input1) == EOF)
		{
			PRINT_ERROR("Failed to read input.");
		}
		printf(" Enter value 2 (0 or 1): ");
		if (scanf("%d", &input2) == EOF)
		{
			PRINT_ERROR("Failed to read input.");
		}
		break;
	case 3: // NOT
		printf(" Enter value (0 or 1): ");
		printf(" Enter value 1 (0 or 1): ");
		if (scanf("%d", &input1) == EOF)
		{
			PRINT_ERROR("Failed to read input.");
		}
		input2 = 0;
		break;
	case 4: // XOR
		printf(" Enter value 1 (0 or 1): ");
		if (scanf("%d", &input1) == EOF)
		{
			PRINT_ERROR(" Failed to read input.");
		}
		printf(" Enter value 2 (0 or 1): ");
		if (scanf("%d", &input2) == EOF)
		{
			PRINT_ERROR(" Failed to read input.");
		}
		break;
	default:
		printf(" Invalid operation choice.\n");
		return;
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
		return;
	}

	printf(COLOR_GREEN" Result: %d\n", result);
}

/**
 * Performs bitwise operations (left shift and right shift) on two input values and prints
 * the result.
 *
 * @return The function does not explicitly return a value. It has a default case in the switch
 * statement that returns, but there is no return statement for the other cases. Therefore, the
 * function will implicitly return without a value.
 */
void perform_bitwise_operations(void)
{
	const char* operations[] = {
		"Left Shift",
		"Right Shift"
	};

	PRINT_SUB_MENU("Bitwise Operations", operations);

	const int operations_choice = get_valid_operations_menu_choice(sizeof(operations) / sizeof(operations[0]));

	int input1, input2, result;


	printf(" Enter value 1 (0 or 1): ");
	if (scanf("%d", &input1) == EOF)
	{
		PRINT_ERROR("Failed to read input.");
	}
	printf(" Enter value 2 (0 or 1): ");
	if (scanf("%d", &input2) == EOF)
	{
		PRINT_ERROR("Failed to read input.");
	}

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
		return;
	}
	printf(COLOR_RED" Result: %d\n", result);
}

/**
 * Performs a modulo operation on two user-inputted integers.
 *
 * @return void, which means it is not returning any value.
 */
void perform_modulo_operation(void)
{
	const char* operations[] = {
		"Modulo"
	};

	PRINT_SUB_MENU("Modulo Operations", operations);

	const int operations_choice = get_valid_operations_menu_choice(sizeof(operations) / sizeof(operations[0]));

	if (operations_choice == 1)
	{
		int divisor;
		int dividend;
		printf(" Enter dividend: ");

		if (scanf("%d", &dividend) == EOF)
		{
			PRINT_ERROR("Failed to read input.");
		}

		printf(" Enter divisor: ");
		if (scanf("%d", &divisor) == EOF)
		{
			PRINT_ERROR("Failed to read input.");
		}

		if (divisor == 0)
		{
			printf(" Error: You need glasses!\n");
			return;
		}

		printf(COLOR_GREEN " Result: %d\n", dividend % divisor);
		return;
	}

	printf(" Invalid operation choice.\n");
}


/**
 * Prompts the user for an integer input, validates it, and
 * returns the valid input.
 *
 * @param prompt The prompt is a string that will be displayed to the user to ask for input.
 * It provides clear instructions on what kind of input is expected.
 *
 * @return an integer value.
 */
int get_valid_integer_input(const char* prompt) {
	int value;

	while (1) {
		char input_buffer[256];
		printf("%s", prompt);
		fgets(input_buffer, sizeof(input_buffer), stdin);   // NOLINT(cert-err33-c)

		// Convert the input to an integer
		char* endptr;
		value = strtol(input_buffer, &endptr, 10);

		// Check for conversion errors and valid input
		if (endptr == input_buffer || *endptr != '\n' || value < 0) {
			printf(" Invalid input. Please enter a valid positive integer.\n");
		}
		else {
			break;
		}
	}

	return value;
}

/**
 * Initializes a matrix by allocating memory for each row and setting all elements to
 * zero.
 *
 * @param matrix The parameter "matrix" is a pointer to a pointer to an integer. It represents a 2D
 * matrix or array.
 * @param rows The number of rows in the matrix.
 * @param columns The "columns" parameter represents the number of columns in the matrix.
 */
void initialize_matrix(int** matrix, const int rows, const int columns) {
	for (int i = 0; i < rows; ++i) {
		matrix[i] = (int*)malloc(columns * sizeof(int));
		memset(matrix[i], 0, columns * sizeof(int));
	}
}

/**
 * Frees the memory allocated for a 2D matrix.
 *
 * @param matrix A pointer to a pointer to an integer. It represents a 2D matrix.
 * @param rows The number of rows in the matrix.
 */
void free_matrix(int** matrix, const int rows) {
	for (int i = 0; i < rows; ++i) {
		free(matrix[i]);
	}
	free(matrix);
}

/**
 * Performs matrix addition, subtraction, or multiplication based on user input.
 */
void perform_matrix_operations(void)
{
	// Build the operations menu and show to the user
	const char* operations[] = {
		"Addition",
		"Subtraction",
		"Multiplication"
	};

	PRINT_SUB_MENU("Matrix Operations", operations);

	const int operations_choice = get_valid_operations_menu_choice(sizeof(operations) / sizeof(operations[0]));

	if (operations_choice >= 1 && operations_choice <= 3) {
		const int rows = get_valid_integer_input(" Enter the number of rows: ");
		const int columns = get_valid_integer_input(" Enter the number of columns: ");

		int** matrix1 = malloc(rows * sizeof(int*));
		int** matrix2 = malloc(rows * sizeof(int*));
		int** result = malloc(rows * sizeof(int*));

		initialize_matrix(matrix1, rows, columns);
		initialize_matrix(matrix2, rows, columns);
		initialize_matrix(result, rows, columns);

		// Input for matrix1
		printf(" Enter elements of matrix 1:\n");
		for (int i = 0; i < rows; ++i) {
			for (int j = 0; j < columns; ++j) {
				matrix1[i][j] = get_valid_integer_input("");
			}
		}

		// Input for matrix2
		printf(" Enter elements of matrix 2:\n");
		for (int i = 0; i < rows; ++i) {
			for (int j = 0; j < columns; ++j) {
				matrix2[i][j] = get_valid_integer_input("");
			}
		}

		// Perform matrix addition, subtraction, or multiplication operation
		if (operations_choice == 1) {  // Addition
			for (int i = 0; i < rows; ++i) {
				for (int j = 0; j < columns; ++j) {
					result[i][j] = matrix1[i][j] + matrix2[i][j];
				}
			}
		}
		else if (operations_choice == 2) {  // Subtraction
			for (int i = 0; i < rows; ++i) {
				for (int j = 0; j < columns; ++j) {
					result[i][j] = matrix1[i][j] - matrix2[i][j];
				}
			}
		}
		else if (operations_choice == 3) {  // Multiplication
			for (int i = 0; i < rows; ++i) {
				for (int j = 0; j < columns; ++j) {
					result[i][j] = 0;
					for (int k = 0; k < columns; ++k) {
						result[i][j] += matrix1[i][k] * matrix2[k][j];
					}
				}
			}
		}

		// Display the matrices
		printf(COLOR_BLUE " Matrix 1:\n");
		for (int i = 0; i < rows; ++i) {
			for (int j = 0; j < columns; ++j) {
				printf(" %d\t", matrix1[i][j]);
			}
			printf("\n");
		}
		printf(COLOR_BLUE " Matrix 2:\n");
		for (int i = 0; i < rows; ++i) {
			for (int j = 0; j < columns; ++j) {
				printf(" %d\t", matrix2[i][j]);
			}
			printf("\n");
		}

		// Display the result
		printf(COLOR_GREEN " Result:\n");
		for (int i = 0; i < rows; ++i) {
			for (int j = 0; j < columns; ++j) {
				printf(" %d\t", result[i][j]);
			}
			printf("\n");
		}

		// Free allocated memory
		for (int i = 0; i < rows; ++i) {
			free(matrix1[i]);
			free(matrix2[i]);
			free(result[i]);
		}
		free(matrix1);
		free(matrix2);
		free(result);
	}
	else {
		printf(" Invalid operation choice.\n");
	}

}

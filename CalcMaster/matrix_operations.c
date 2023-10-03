//
// CalcMaster - A Multi-Functional Calculator Written In Modern C.
// Copyright (c) 2023 Lokesh Wankhede.
//

#include "matrix_operations.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "menu.h"
#include "operations.h"


/**
 * Initializes a matrix by allocating memory for each row and setting all elements to
 * zero.
 *
 * @param matrix The parameter "matrix" is a pointer to a pointer to an integer. It represents a 2D
 * matrix or array.
 * @param rows The number of rows in the matrix.
 * @param columns The "columns" parameter represents the number of columns in the matrix.
 */
void initialize_matrix(int** matrix, const int rows, const int columns)
{
	for (int i = 0; i < rows; ++i)
	{
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
void free_matrix(int** matrix, const int rows)
{
	for (int i = 0; i < rows; ++i)
		free(matrix[i]);
	free(matrix);
}

/**
 * Performs matrix addition, subtraction, or multiplication based on user input.
 *
 * @result operation_return_reason
 */
enum operation_return_reason perform_matrix_operations(void)
{
	// Build the operations menu and show to the user
	const char* operations[] = {
		"Addition",
		"Subtraction",
		"Multiplication"
	};

	PRINT_SUB_MENU("Matrix Operations", operations);

	const int operations_choice = get_valid_operations_menu_choice(sizeof(operations) / sizeof(operations[0]));

	// check if user want to go back
	if (operations_choice == 0)
	{
		printf(" Press enter to go back...");
		return return_reason_user_exit;
	}

	if (operations_choice < 0 || operations_choice >= 4)
		return return_reason_error;

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
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < columns; ++j)
			matrix1[i][j] = get_valid_integer_input("");
	}

	// Input for matrix2
	printf(" Enter elements of matrix 2:\n");
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < columns; ++j)
			matrix2[i][j] = get_valid_integer_input("");
	}

	// Perform matrix addition, subtraction, or multiplication operation
	if (operations_choice == 1)
	{
		// Addition
		for (int i = 0; i < rows; ++i)
		{
			for (int j = 0; j < columns; ++j)
				result[i][j] = matrix1[i][j] + matrix2[i][j];
		}
	}
	if (operations_choice == 2)
	{
		// Subtraction
		for (int i = 0; i < rows; ++i)
		{
			for (int j = 0; j < columns; ++j)
				result[i][j] = matrix1[i][j] - matrix2[i][j];
		}
	}
	if (operations_choice == 3)
	{
		// Multiplication
		for (int i = 0; i < rows; ++i)
		{
			for (int j = 0; j < columns; ++j)
			{
				result[i][j] = 0;
				for (int k = 0; k < columns; ++k)
					result[i][j] += matrix1[i][k] * matrix2[k][j];
			}
		}
	}

	// Display the matrices
	printf(COLOR_BLUE "\n Matrix 1:\n");
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < columns; ++j)
			printf(" %d\t", matrix1[i][j]);
		printf("\n");
	}
	printf(COLOR_BLUE "\n Matrix 2:\n");
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < columns; ++j)
			printf(" %d\t", matrix2[i][j]);
		printf("\n");
	}

	// Display the result
	printf(COLOR_GREEN "\n Result:\n");
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < columns; ++j)
			printf(" %d\t", result[i][j]);
		printf("\n");
	}

	// Free allocated memory
	for (int i = 0; i < rows; ++i)
	{
		free(matrix1[i]);
		free(matrix2[i]);
		free(result[i]);
	}
	free(matrix1);
	free(matrix2);
	free(result);

	return return_reason_success;
}

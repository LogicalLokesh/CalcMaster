//
// CalcMaster - A Multi-Functional Calculator Written In Modern C.
// Copyright (c) 2023 Lokesh Wankhede.
//

#pragma once

void perform_arithmetic_operations(void);
void perform_comparison_operations(void);
void perform_logical_operations(void);
void perform_bitwise_operations(void);
void perform_modulo_operation(void);

// matrix related
int get_valid_integer_input(const char* prompt);
void initialize_matrix(int** matrix, int rows, int columns);
void free_matrix(int** matrix, int rows);
void perform_matrix_operations(void);

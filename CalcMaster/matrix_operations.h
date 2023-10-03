//
// CalcMaster - A Multi-Functional Calculator Written In Modern C.
// Copyright (c) 2023 Lokesh Wankhede.
//

#pragma once

#include "calc_master.h"

void initialize_matrix(int** matrix, int rows, int columns);
void free_matrix(int** matrix, int rows);
enum operation_return_reason perform_matrix_operations(void);

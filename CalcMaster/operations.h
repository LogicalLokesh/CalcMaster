//
// CalcMaster - A Multi-Functional Calculator Written In Modern C.
// Copyright (c) 2023 Lokesh Wankhede.
//

#pragma once

#include "calc_master.h"

int get_valid_integer_input(const char* prompt);

enum operation_return_reason perform_arithmetic_operations(void);
enum operation_return_reason perform_comparison_operations(void);
enum operation_return_reason perform_logical_operations(void);
enum operation_return_reason perform_bitwise_operations(void);
enum operation_return_reason perform_modulo_operation(void);

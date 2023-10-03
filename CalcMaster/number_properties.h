//
// CalcMaster - A Multi-Functional Calculator Written In Modern C.
// Copyright (c) 2023 Lokesh Wankhede.
//

#pragma once

#include <stdbool.h>

#include "calc_master.h"

enum operation_return_reason find_number_properties(void);

bool is_even(int number);
bool is_odd(int number);
bool is_prime(int number);
bool is_perfect_number(int number);
bool is_armstrong_number(int number);
bool is_palindrome(int number);

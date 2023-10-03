//
// CalcMaster - A Multi-Functional Calculator Written In Modern C.
// Copyright (c) 2023 Lokesh Wankhede.
//

#include "number_properties.h"

#include <stdbool.h>


bool is_even(const int number) { return number % 2 == 0; }

bool is_odd(const int number) { return number % 2 != 0; }

bool is_prime(const int number)
{
	if (number <= 1)
		return false;
	if (number <= 3)
		return true;
	if (number % 2 == 0 || number % 3 == 0)
		return false;
	for (int i = 5; i * i <= number; i += 6)
	{
		if (number % i == 0 || number % (i + 2) == 0)
			return false;
	}
	return true;
}

bool is_perfect_number(const int number)
{
	int sum = 1;
	for (int i = 2; i * i <= number; i++)
	{
		if (number % i == 0)
		{
			if (i * i != number)
				sum = sum + i + number / i;
			else
				sum = sum + i;
		}
	}
	return sum == number && number != 1;
}

bool is_armstrong_number(const int number)
{
	int result = 0;
	int original_number = number;
	int num_digits = 0;

	// Count the number of digits in the number
	while (original_number != 0)
	{
		original_number /= 10;
		num_digits++;
	}

	original_number = number;

	while (original_number != 0)
	{
		const int remainder = original_number % 10;

		// Calculate remainder raised to the power of num_digits
		int temp = 1;
		for (int i = 0; i < num_digits; ++i)
			temp *= remainder;

		result += temp;
		original_number /= 10;
	}

	return result == number;
}


bool is_palindrome(int number)
{
	int reversed_number = 0;
	const int original_number = number;

	while (number != 0)
	{
		const int remainder = number % 10;
		reversed_number = reversed_number * 10 + remainder;
		number /= 10;
	}

	return original_number == reversed_number;
}

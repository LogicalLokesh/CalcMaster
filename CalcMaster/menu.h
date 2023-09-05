//
// CalcMaster - A Multi-Functional Calculator Written In Modern C.
// Copyright (c) 2023 Lokesh Wankhede.
//

#pragma once

// ANSI color escape codes
#define COLOR_RESET "\x1b[0m"
#define COLOR_BLACK "\x1b[30m"
#define COLOR_RED "\x1b[31m"
#define COLOR_GREEN "\x1b[32m"
#define COLOR_YELLOW "\x1b[33m"
#define COLOR_BLUE "\x1b[34m"
#define COLOR_MAGENTA "\x1b[35m"
#define COLOR_CYAN "\x1b[36m"
#define COLOR_WHITE "\x1b[37m"

// Text styles
#define TEXT_BOLD "\x1b[1m"
#define TEXT_UNDERLINE "\x1b[4m"

#define CLEAR_SCREEN printf("\x1B[1;1H\x1B[2J") // Escape codes to clear the screen

#define PAUSE {char _trash = getchar();}

// Menu builder
#define PRINT_SUB_MENU(title, arr)\
	CLEAR_SCREEN;\
	show_app_info();\
	printf(COLOR_BLUE "\n ------<" " "title" " ">------\n\n" COLOR_RESET);\
	do { \
	size_t arr_size = sizeof(arr) / sizeof((arr)[0]); \
	for (size_t i = 0; i < arr_size; ++i) { \
		if (i == 0) printf(COLOR_GREEN); \
		printf(" %zu. %s", i + 1, (arr)[i]); \
		if (i == arr_size - 1) printf(COLOR_RESET); \
		printf("\n"); \
	} \
} while (0)

// Main Menu builder
#define PRINT_MAIN_MENU(title, arr)\
	CLEAR_SCREEN;\
	show_app_info();\
	printf(COLOR_GREEN "\n ------<" " "title" " ">------\n\n");\
	do { \
	size_t arr_size = sizeof(arr) / sizeof((arr)[0]); \
	char letter = 'A'; \
	for (size_t i = 0; i < arr_size; ++i) { \
		if (i == 0) printf(COLOR_WHITE); \
		if (i == arr_size - 1) printf(COLOR_RED);\
		printf(" %c. %s", letter, (arr)[i]); \
		if (i == arr_size - 1) printf(COLOR_RESET); \
		printf("\n"); \
		++letter; \
	} \
} while (0)


// Error screen builder
#define PRINT_ERROR(reason)\
	CLEAR_SCREEN;\
	show_app_info();\
	printf(TEXT_BOLD COLOR_RED "\n ------< ! ERROR ! >------\n\n");\
	printf(COLOR_MAGENTA " Something went wrong :(\n\n");\
	printf(COLOR_RED " Reason: " reason "\n\n");\
	printf(COLOR_WHITE " Press enter to exit.");\
	char trash_ = getchar();\
	exit(-1)


void clear_input_buffer(void);
void show_app_info(void);

char get_valid_categories_menu_choice(void);
int get_valid_operations_menu_choice(int max_operations_available);

void show_categories_menu(void);
void show_sub_categories_menu(char sub_category_choice);

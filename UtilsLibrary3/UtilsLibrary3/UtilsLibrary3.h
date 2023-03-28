#pragma once

using namespace System;

namespace UtilsLibrary3 {

	public ref class Utils
	{
	public:
		static void fill_array_randomly(int* array, size_t length, int min, int max);
		static size_t solve(int* array, size_t length);
		static void solve2(int* array, int* new_array, size_t length, size_t& new_length, int number);
		
		static void fill_with_array(System::Windows::Forms::DataGridView^ grid, int* array, size_t length);
		
		static size_t find_max(int* array, size_t length);
		static void remove_from_array(int* array, size_t& length, size_t index);
		static void add_to_array(int* array, size_t& length, size_t index, int value);
		static bool is_monotone(int* array, size_t length);
		static int find_first_prime(int* array, size_t length);

		static double log_custom(double x, double accuracy, System::Windows::Forms::ListView^ list);

		static int* create_array_form_dgv(System::Windows::Forms::DataGridView^ grid, size_t& size);
		static void insertation_sort(int* array, size_t length);
		static void binary_sort(int* array, size_t length);
		static void selection_sort(int* array, size_t length);
		static void bubble_sort(int* array, size_t length);
		static void bubble_sort_ext(int* array, size_t length);
		static void shaker_sort(int* array, size_t length);

		static void save_array(System::Windows::Forms::DataGridView^ grid);
		static void load_array(System::Windows::Forms::DataGridView^ grid);
	};
}

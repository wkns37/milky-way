#pragma once

using namespace System;
using namespace System::Windows::Forms;

namespace UtilsLibrary4 {
	public ref class Utils
	{
	public:
		static void generate_matrix(int** array, size_t rows, size_t columns);
		static void fill_with_array(DataGridView^ grid, int* array, size_t length);
		static void fill_with_matrix(DataGridView ^ grid, int** array, size_t rows, size_t columns);
		static size_t solve(int** array, size_t rows, size_t columns);
		static void solve2(int** array, size_t rows, size_t columns, int* array_result);
		static double solve3(double x, double accuracy, size_t& last_summand, ListView^ list);
		
		static void find_min_matrix(int** array, size_t rows, size_t columns, size_t& min_row, size_t& min_column);
		static void find_max_matrix(int** array, size_t rows, size_t columns, size_t& max_row, size_t& max_column);
		static void swap_matrix_rows(int** array, size_t rows, size_t columns, size_t first_row, size_t second_row);
		static void swap_matrix_columns(int** array, size_t rows, size_t columns, size_t first_column, size_t second_column);
	};
}

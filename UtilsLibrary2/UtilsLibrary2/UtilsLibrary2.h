#pragma once

using namespace System;

using System::Windows::Forms::MessageBox;
using System::Windows::Forms::MessageBoxButtons;
using System::Windows::Forms::MessageBoxIcon;

using System::Data::OleDb::OleDbConnection;
using System::Data::OleDb::OleDbCommand;
using System::Data::OleDb::OleDbException;

namespace UtilsLibrary2 {
	public ref class Utils
	{
	public:
		static void fillArrayRandomly(int* array, size_t length, int min, int max);
		static void fillWithArray(System::Windows::Forms::DataGridView^ grid, int* array, size_t length);
		static size_t solve(int* array, size_t length);
		static void solve2(int* array, int* new_array, int length, int& new_length, int number);
		static void create_db();
		static void configure_db();
		static void write_to_db(int* array, int* new_array, int length, int new_length);
		static void write_to_word(String^ title, int* array, int length);
		static void write_to_notepad(System::Windows::Forms::DataGridView^ view1, System::Windows::Forms::DataGridView^ view2);
	};
}

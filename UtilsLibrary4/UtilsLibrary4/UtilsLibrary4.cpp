#include <cstdlib>
#include <ctime>
#include <cassert>
#include "UtilsLibrary4.h"

// Генерация матрицы
void UtilsLibrary4::Utils::generate_matrix(int** array, size_t rows, size_t columns)
{
	srand((unsigned)time(NULL));
	for (size_t i = 0; i < rows; i++)
	{
		array[i] = new int[columns];
		for (size_t j = 0; j < columns; j++)
		{
			array[i][j] = (int)(rand() % 1001);
		}
	}
}

// Заполнение графического элемента DataGridView элементами массива
void UtilsLibrary4::Utils::fill_with_array(DataGridView^ grid, int* array, size_t length)
{
	grid->ColumnCount = length;
	grid->RowCount = 2;

	for (size_t i = 0; i < length; i++)
	{
		grid->Rows[0]->Cells[i]->Value = "[" + i + "]";
		grid->Rows[1]->Cells[i]->Value = array[i];
	}

	size_t width = 0, heigth = 3;
	for (size_t i = 0; i < grid->ColumnCount; i++)
		width += grid->Columns[i]->Width;

	for (size_t j = 0; j < grid->RowCount; j++)
		heigth += grid->Rows[j]->Height;

	if (width > 410)
		grid->Width = 410;
	else
		grid->Width = width;

	grid->Height = heigth;
}

// Вывод матрицы в графический элемент DataGridView
void UtilsLibrary4::Utils::fill_with_matrix(DataGridView^ grid, int** array, size_t rows, size_t columns)
{
	grid->ColumnCount = columns + 1;
	grid->RowCount = rows + 1;
	grid->Rows[0]->Cells[0]->Value = "[" + rows + "][" + columns + "]";

	for (size_t i = 0; i < rows; i++)
	{
		grid->Rows[i + 1]->Cells[0]->Value = "[" + i + "]";
		grid->Rows[0]->Cells[i + 1]->Value = "[" + i + "]";

		for (size_t j = 0; j < columns; j++)
		{
			grid->Rows[i + 1]->Cells[j + 1]->Value = array[i][j];
		}
	}

	// Add pre-calculated padding
	size_t width = 3, height = 3;
	for (size_t i = 0; i < grid->ColumnCount; i++)
		width += grid->Columns[i]->Width;

	for (size_t i = 0; i < grid->RowCount; i++)
		height += grid->Rows[i]->Height;

	grid->Width = width;
	grid->Height = height;
}

// Поиск кол-ва элементов главной диагонали кратных 7
size_t UtilsLibrary4::Utils::solve(int** array, size_t rows, size_t columns)
{
	size_t count = 0;
	for (size_t i = 0; i < rows; i++)
	{
		if (array[i][i] % 7 == 0)
		{
			count++;
		}
	}

	return count;
}

// Создание массива из элементов главной диагонали кратных 7
void UtilsLibrary4::Utils::solve2(int** array, size_t rows, size_t columns, int* array_result)
{
	size_t count = 0;
	for (size_t i = 0; i < rows; i++)
	{
		int value = array[i][i];
		if (value % 7 == 0)
		{
			array_result[count] = value;
			count++;
		}
	}
}

// Сумма ряда с заданой точностью, выводящая номер последнего слагаемого в последний параметр
double UtilsLibrary4::Utils::solve3(double x, double accuracy, size_t& last_summand, ListView^ list)
{
	list->Items->Clear();
	// Значение первого элемента формулы
	double first_value = pow(x, 4) / 162.0;
	double result = first_value;
	double prev_value;

	// Номер предыдущего вычисленного элемента
	size_t k = 1;
	do
	{
		array<String^>^ entry = { k.ToString(), result.ToString() };
		list->Items->Add(gcnew ListViewItem(entry));

		prev_value = result;
		result *= (-pow(x, 4) / (double)(162 * (k + 1) * (2 * k + 1)));
		k++;
	} while (fabs(result - prev_value) >= accuracy);

	last_summand = k - 1;

	return result;
}

// Нахождение минимального элемента матрицы
void UtilsLibrary4::Utils::find_min_matrix(int** array, size_t rows, size_t columns, size_t& min_row, size_t& min_column)
{
	min_row = 0;
	min_column = 0;
	for (size_t i = 0; i < rows; ++i)
	{
		for (size_t j = 0; j < columns; ++j)
		{
			if (array[i][j] < array[min_row][min_column])
			{
				min_row = i;
				min_column = j;
			}
		}
	}
}

// Нахождение максимального элемента матрицы
void UtilsLibrary4::Utils::find_max_matrix(int** array, size_t rows, size_t columns, size_t& max_row, size_t& max_column)
{
	max_row = 0;
	max_column = 0;
	for (size_t i = 0; i < rows; ++i)
	{
		for (size_t j = 0; j < columns; ++j)
		{
			if (array[i][j] > array[max_row][max_column])
			{
				max_row = i;
				max_column = j;
			}
		}
	}
}

// Функция, меняющая указанные строки местами
void UtilsLibrary4::Utils::swap_matrix_rows(int** array, size_t rows, size_t columns, size_t first_row, size_t second_row)
{
	if ((first_row >= rows) || (second_row >= rows))
	{
		return;
	}

	for (size_t j = 0; j < columns; ++j)
	{
		int value = array[first_row][j];
		array[first_row][j] = array[second_row][j];
		array[second_row][j] = value;
	}
}

// Функция, меняющая указанные столбцы местами
void UtilsLibrary4::Utils::swap_matrix_columns(int** array, size_t rows, size_t columns, size_t first_column, size_t second_column)
{
	if ((first_column >= columns) || (second_column >= columns))
	{
		return;
	}

	for (size_t i = 0; i < rows; ++i)
	{
		int value = array[i][first_column];
		array[i][first_column] = array[i][second_column];
		array[i][second_column] = value;
	}
}

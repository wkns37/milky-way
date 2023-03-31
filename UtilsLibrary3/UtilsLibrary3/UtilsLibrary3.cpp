#include "UtilsLibrary3.h"
#include <algorithm>
#include <cstdlib>

// ���������� ������� ���������� �������
void UtilsLibrary3::Utils::fill_array_randomly(int* array, size_t length, int min, int max)
{
	// ������� �� ���� �������, ��������� �� 7 ��� �������
	bool found = false;
	for (size_t i = 0; i < length; i++)
	{
		// ��������� ����� � ���������� [min;max]
		int value = rand() % (max - min + 1) + min;
		array[i] = value;
		if (value % 7 == 0) found = true;
	}

	if (!found)
	{
		// ������������� ������������� ��������
		array[length / 2] = 7;
	}
}

// ������� ������������ ������
size_t UtilsLibrary3::Utils::solve(int* array, size_t length)
{
	size_t count = 0;
	for (size_t i = 0; i < length - 1; i++)
	{
		int delta = array[i] - array[i + 1];
		// ��������� ��������� % ����� ��������, ���� delta < 0;
		// ������� �� ������� ������ ����������� � �������������� ����� ������
		// � ������������ � ���� (a % b + b) % b
		if ((delta % 7 + 7) % 7 != 0) count++;
	}

	return count;
}

// ������� ������������ ������
void UtilsLibrary3::Utils::solve2(int* array, int* new_array, size_t length, size_t& new_length, int number)
{
	int index = 0;
	for (size_t i = 0; i < length; i++)
	{
		if (array[i] % number == 0)
		{
			new_array[index] = array[i];
			index++;
		}
	}
	new_length = index;
}

// ���������� ������������ �������� DataGridView ���������� �������
void UtilsLibrary3::Utils::fill_with_array(System::Windows::Forms::DataGridView^ grid, int* array, size_t length)
{
	grid->ColumnCount = length;
	grid->RowCount = 2;

	for (size_t i = 0; i < length; i++)
	{
		grid->Rows[0]->Cells[i]->Value = "[" + i + "]";
		grid->Rows[1]->Cells[i]->Value = array[i];
	}

	int sum = 0;
	for (int i = 0; i < grid->ColumnCount; i++)
		sum += grid->Columns[i]->Width;

	if (sum > 410)
		grid->Width = 410;
	else
		grid->Width = sum;
}

// ����� ������� ������������� �������� � �������
size_t UtilsLibrary3::Utils::find_max(int* array, size_t length)
{
	int index = 0;

	for (size_t i = 1; i < length; i++)
	{
		if (array[i] > array[index])
		{
			index = i;
		}
	}

	return index;
}

// �������� �������� �� �������
void UtilsLibrary3::Utils::remove_from_array(int* array, size_t& length, size_t index)
{
	for (size_t i = index; i < length - 1; i++)
	{
		array[i] = array[i + 1];
	}

	length--;
}

// ������� �������� � ������
void UtilsLibrary3::Utils::add_to_array(int* array, size_t& length, size_t index, int value)
{
	for (size_t i = length; i > index; i--)
	{
		array[i] = array[i - 1];
	}

	array[index] = value;
	length++;
}

// �������� ������������������ ������� �� ������������
bool UtilsLibrary3::Utils::is_monotone(int* array, size_t length)
{
	for (size_t i = 1; i < length; i++)
	{
		if (array[i] > array[i - 1])
		{
			return false;
		}
	}

	return true;
}

// �������� ����� �� ��������
static bool is_prime(int number)
{
	for (long long i = 2; i <= sqrt(number); i++)
	{
		if (number % i == 0)
		{
			return false;
		}
	}

	return true;
}

// ���������� ������� ������� �������� �������� � �������
int UtilsLibrary3::Utils::find_first_prime(int* array, size_t length)
{
	bool found = false;
	size_t index = 0;
	while (index < length && !found)
	{
		if (is_prime(array[index]))
		{
			found = true;
		}
		else
		{
			index++;
		}
	}

	return found ? index : -1;
}

// ��������������� ���������� �������������� ������� ���������
double UtilsLibrary3::Utils::log_custom(double x, double accuracy, System::Windows::Forms::ListView^ list)
{
	list->Items->Clear();
	double result = 0.0, prev_value = 0.0;
	size_t n = 1;

	do
	{
		prev_value = result;
		result += pow(-1, n + 1) * pow(x, n) / (double)n;

		array<String^>^ entry = { n.ToString(), result.ToString() };
		list->Items->Add(gcnew System::Windows::Forms::ListViewItem(entry));

		n++;
	} while (fabs(result - prev_value) >= accuracy);

	return result;
}

// ������������ ������� �� ������ ������������ �������� DataGridView
int* UtilsLibrary3::Utils::create_array_form_dgv(System::Windows::Forms::DataGridView^ grid, size_t& size)
{
	size = grid->ColumnCount;
	int* array = new int[size];

	for (size_t i = 0; i < size; i++)
	{
		array[i] = Convert::ToInt32(grid->Rows[1]->Cells[i]->Value);
	}

	return array;
}

// ���������� ������� ������� ������� �������
void UtilsLibrary3::Utils::insertation_sort(int* array, size_t length)
{
	for (size_t i = 1; i < length; i++)
	{
		for (size_t j = i; j > 0; j--)
		{
			if (array[j - 1] > array[j])
			{
				std::swap(array[j - 1], array[j]);
			}
			else break;
		}
	}
}

// ���������� ������� ������� �������� �������
void UtilsLibrary3::Utils::binary_sort(int* array, size_t length)
{
	for (size_t i = 0; i < length; i++)
	{
		int x = array[i];
		int low = 0, high = i;

		while (low < high)
		{
			int middle = (low + high) / 2;

			if (array[middle] > x)
				high = middle;
			else
				low = middle + 1;
		}

		for (size_t j = i; j > low; j--)
		{
			array[j] = array[j - 1];
		}

		array[low] = x;
	}
}

// ���������� ������� ������� ������
void UtilsLibrary3::Utils::selection_sort(int* array, size_t length)
{
	for (size_t i = 0; i < length - 1; i++)
	{
		size_t min = i;
		for (size_t j = i + 1; j < length; j++)
		{
			if (array[j] < array[min])
			{
				min = j;
			}
		}

		std::swap(array[i], array[min]);
	}
}

// ���������� ������� ������� (���������)
void UtilsLibrary3::Utils::bubble_sort(int* array, size_t length)
{
	for (size_t i = 0; i < length; i++)
	{
		for (size_t j = length - 1; j > i; j--)
		{
			if (array[j - 1] > array[j])
			{
				std::swap(array[j - 1], array[j]);
			}
		}
	}
}

// ���������� ������� ������� (���������), ����������
void UtilsLibrary3::Utils::bubble_sort_ext(int* array, size_t length)
{
	bool flag = true;
	for (size_t i = length - 1; i > 0 && flag; i--)
	{
		flag = false;
		for (size_t j = 0; j < i; j++)
		{
			if (array[j] > array[j + 1])
			{
				std::swap(array[j], array[j + 1]);
				flag = true;
			}
		}
	}
}

// ������-����������
void UtilsLibrary3::Utils::shaker_sort(int* array, size_t length)
{
	size_t left = 0, right = length - 1, k = right;
	while (left < right)
	{
		for (size_t i = right; i > left; i--)
		{
			if (array[i - 1] > array[i])
			{
				std::swap(array[i - 1], array[i]);
				k = i;
			}
		}
		left = k;
		for (size_t i = left; i < right; i++)
		{
			if (array[i] > array[i + 1])
			{
				std::swap(array[i], array[i + 1]);
				k = i;
			}
		}
		right = k;
	}
}

// ���������� ������ ������������ �������� DataGridView � ����
void UtilsLibrary3::Utils::save_array(System::Windows::Forms::DataGridView^ grid)
{
	String^ filename = Microsoft::VisualBasic::Interaction::InputBox(
		"������� ���� � �����, � ������� ����� �������� ��������� ������", "����", "", -1, -1);

	try
	{
		IO::StreamWriter^ writer = gcnew IO::StreamWriter(filename, false, System::Text::Encoding::ASCII);
		size_t size = grid->ColumnCount;
		writer->WriteLine(size);

		for (size_t i = 0; i < size; i++)
		{
			writer->WriteLine(grid->Rows[1]->Cells[i]->Value->ToString());
		}

		writer->Close();
		System::Windows::Forms::MessageBox::Show("������ ��������� �������", "����������",
			System::Windows::Forms::MessageBoxButtons::OK,
			System::Windows::Forms::MessageBoxIcon::Information);
	}
	catch (System::Exception^ e)
	{
		System::Windows::Forms::MessageBox::Show(e->Message, "������",
			System::Windows::Forms::MessageBoxButtons::OK,
			System::Windows::Forms::MessageBoxIcon::Error);
	}
}

// �������� ������ � ����������� ������� DataGridView �� �����
void UtilsLibrary3::Utils::load_array(System::Windows::Forms::DataGridView^ grid)
{
	String^ filename = Microsoft::VisualBasic::Interaction::InputBox(
		"������� ���� � �����, � ������� �������� ����������� ������", "����", "", -1, -1);

	try
	{
		IO::StreamReader^ reader = gcnew IO::StreamReader(filename);
		size_t size = Convert::ToInt32(reader->ReadLine()->ToString());

		int* array = new int[size];

		for (size_t i = 0; i < size; i++)
		{
			array[i] = Convert::ToInt32(reader->ReadLine());
		}

		reader->Close();

		fill_with_array(grid, array, size);
	}
	catch (System::Exception^ e)
	{
		System::Windows::Forms::MessageBox::Show(e->Message, "������",
			System::Windows::Forms::MessageBoxButtons::OK,
			System::Windows::Forms::MessageBoxIcon::Error);
	}
}

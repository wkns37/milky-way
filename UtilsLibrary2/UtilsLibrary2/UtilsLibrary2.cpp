#include "UtilsLibrary2.h"
#include <cstdlib>

void UtilsLibrary2::Utils::fillArrayRandomly(int* array, size_t length, int min, int max)
{
	// Найдено ли один элемент, делящийся на 7 без остатка
	bool found = false;
	for (size_t i = 0; i < length; i++)
	{
		// Случайное число в промежутке [min;max]
		int value = rand() % (max - min + 1) + min;
		array[i] = value;
		if (value % 7 == 0) found = true;
	}

	if (!found)
	{
		// Принудительно устанавливаем значение
		array[length / 2] = 7;
	}
}

void UtilsLibrary2::Utils::fillWithArray(System::Windows::Forms::DataGridView^ grid, int* array, size_t length)
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

size_t UtilsLibrary2::Utils::solve(int* array, size_t length)
{
	size_t count = 0;
	for (size_t i = 0; i < length - 1; i++)
	{
		int delta = array[i] - array[i + 1];
		// результат оператора % будет неверным, если delta < 0;
		// остаток от деления всегда положителен с математической точки зрения
		// и записывается в виде (a % b + b) % b
		if ((delta % 7 + 7) % 7 != 0) count++;
	}

	return count;
}

void UtilsLibrary2::Utils::solve2(int* array, int* new_array, int length, int& new_length, int number)
{
	int index = 0;
	for (size_t i = 0; i < length; i++)
	{
		if (array[i] % number == 0)
		{
			new_array[index] = i;
			index++;
		}
	}
	new_length = index;
}

void UtilsLibrary2::Utils::create_db()
{
	ADOX::Catalog^ catalog = gcnew ADOX::CatalogClass();
	try
	{
		catalog->Create("Provider = Microsoft.Jet.OLEDB.4.0; Data Source = solution.mdb");
		MessageBox::Show("Файл базы данных успешно создан", "Инфо", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
	catch (System::Runtime::InteropServices::COMException^ exception)
	{
		MessageBox::Show(exception->Message, "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
	finally
	{
		catalog = nullptr;
	}
}

void UtilsLibrary2::Utils::configure_db()
{
	auto p = gcnew OleDbConnection("Provider=Microsoft.Jet.OLEDB.4.0; Data Source = solution.mdb");
	p->Open();
	auto c = gcnew OleDbCommand("CREATE TABLE [Результат]([Индекс] counter, [Исходный массив] char(200)," +
		"[Результирующий массив] char(200))", p);
	try
	{
		c->ExecuteNonQuery();
		MessageBox::Show("Структура базы данных успешно сформирована", "Инфо", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
	catch (OleDbException^ exception)
	{
		MessageBox::Show(exception->Message, "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
	p->Close();
}

void UtilsLibrary2::Utils::write_to_db(int* array, int* new_array, int length, int new_length)
{
	for (size_t i = 0; i < length; i++)
	{
		auto p = gcnew OleDbConnection("Provider=Microsoft.Jet.OLEDB.4.0; Data Source = solution.mdb");
		p->Open();

		if (i < new_length)
		{
			auto c = gcnew OleDbCommand("INSERT INTO[Результат](" +
				"[Исходный массив], [Результирующий массив]) VALUES('" + array[i] + "','" + new_array[i] + " ')");
			c->Connection = p;
			c->ExecuteNonQuery();
		}
		else
		{
			auto c = gcnew OleDbCommand("INSERT INTO[Результат](" +
				"[Исходный массив], [Результирующий массив]) VALUES('" + array[i] + "','')");
			c->Connection = p;
			c->ExecuteNonQuery();
		}
	}
}

void UtilsLibrary2::Utils::write_to_word(String^ title, int* array, int length)
{
	auto word = gcnew Microsoft::Office::Interop::Word::ApplicationClass();
	word->Visible = true;
	auto missing = Type::Missing;
	auto document = word->Documents->Add(missing, missing, missing, missing);
	Object^ behavior1 = Microsoft::Office::Interop::Word::WdDefaultTableBehavior::wdWord9TableBehavior;
	Object^ behavior2 = Microsoft::Office::Interop::Word::WdAutoFitBehavior::wdAutoFitContent;

	word->Selection->TypeText(title);
	Microsoft::Office::Interop::Word::Table^ table = word->ActiveDocument->Tables->Add(word->Selection->Range,
		2, length, behavior1, behavior2);

	for (size_t i = 0; i < length; i++)
	{
		table->Cell(1, i + 1)->Range->InsertAfter("[" + Convert::ToString(i) + "]");
		String^ str = String::Format("{0:f0}", array[i]);
		table->Cell(2, i + 1)->Range->InsertAfter(str);
	}
}

void UtilsLibrary2::Utils::write_to_notepad(System::Windows::Forms::DataGridView^ view1,
	System::Windows::Forms::DataGridView^ view2)
{
	String^ f = Microsoft::VisualBasic::Interaction::InputBox("Введите путь по которому будет сохранен файл и его имя. " +
		"Расширение добавляется автоматически\nНапример:C:\\Users\\name\\repos\'имя файла'", "Ввод", "Ввод", -1, -1);
	String^ filename = f + ".txt";
	try {
		auto encoding = System::Text::Encoding::GetEncoding(1251);
		auto stream = gcnew IO::StreamWriter(filename, false, encoding);
		stream->WriteLine("Исходный массив | Результирующий массив");
		const char* tst = "Исходный массив |";
		for (int i = 0; i < view1->ColumnCount; i++)
		{
			if (i < view2->ColumnCount)
				stream->WriteLine(String::Format("{0, 18}",
					Convert::ToString(view1->Rows[1]->Cells[i]->Value) + " | ") +
					Convert::ToString(view2->Rows[1]->Cells[i]->Value));
			else
				stream->WriteLine(String::Format("{0, 17}",
					Convert::ToString(view1->Rows[1]->Cells[i]->Value) + " |"));
		}

		stream->Close();
		MessageBox::Show("Запись произведена успешна");
	}
	catch (System::Exception^ exception) {
		MessageBox::Show(exception->Message, "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
}

// CourseworkLibrary.cpp
#include "CourseworkLibrary.h"

void CourseworkLibrary::Tools::showInfoBox(String^ message)
{
	// Вывод информационного сообщения
	MessageBox::Show(message, "Информация", MessageBoxButtons::OK, MessageBoxIcon::Information);
}

void CourseworkLibrary::Tools::showErrorBox(String^ message)
{
	// Вывод информационного сообщения
	MessageBox::Show(message, "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
}

static void showRightAnswer(String^ message = "Вы ответили правильно!")
{
	// Вывод информационного сообщения
	MessageBox::Show(message, "Верно", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
}

static void showWrongAnswer(String^ message)
{
	// Вывод информационного сообщения
	MessageBox::Show(message, "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
}

static String^ buildFolders(String^ timestamp)
{
	// Содание структуры папок
	if (!IO::Directory::Exists("results"))
		IO::Directory::CreateDirectory("results");

	if (!IO::Directory::Exists("results\\" + timestamp))
		IO::Directory::CreateDirectory("results\\" + timestamp);

	return "results\\" + timestamp;
}

void CourseworkLibrary::Tools::setHighlighted(Label^ label, bool bold)
{
	// Выделение полужирным шрифтом
	if (bold) label->Font = gcnew Font(label->Font, FontStyle::Bold);
	else label->Font = gcnew Font(label->Font, FontStyle::Regular);
}

void CourseworkLibrary::Tools::setBackgroundColor(Form^ form, double percentage)
{
	// Цвет итоговой формы зависит от процента выполнения
	if (percentage >= 0 && percentage < 33)
	{
		// RED
		form->BackColor = System::Drawing::Color::FromArgb(
			static_cast<System::Int32>(static_cast<System::Byte>(0xff)),
			static_cast<System::Int32>(static_cast<System::Byte>(0xe5)),
			static_cast<System::Int32>(static_cast<System::Byte>(0xe5)));
	}
	else if (percentage >= 33 && percentage < 66)
	{
		// YELLOW
		form->BackColor = System::Drawing::Color::FromArgb(
			static_cast<System::Int32>(static_cast<System::Byte>(0xff)),
			static_cast<System::Int32>(static_cast<System::Byte>(0xff)),
			static_cast<System::Int32>(static_cast<System::Byte>(0xe5)));
	}
	else if (percentage >= 66 && percentage <= 100)
	{
		// GREEN
		form->BackColor = System::Drawing::Color::FromArgb(
			static_cast<System::Int32>(static_cast<System::Byte>(0xe5)),
			static_cast<System::Int32>(static_cast<System::Byte>(0xff)),
			static_cast<System::Int32>(static_cast<System::Byte>(0xe5)));
	}
}


bool CourseworkLibrary::Tools::isCredentialsValid(TextBox^ field_username, TextBox^ field_password)
{
	// Проверка валидности имени и пароля
	String^ username = field_username->Text->Trim();
	String^ password = field_password->Text->Trim();

	if (username->Equals(""))
	{
		showErrorBox("Поле имени пользователя не может быть пустым");
		return false;
	}

	if (!password->Equals("password1324"))
	{
		showErrorBox("Неверный пароль");
		return false;
	}

	return true;
}

bool CourseworkLibrary::Tools::loadMaterial(WebBrowser^ view, String^ file)
{
	// Загрузка материала
	String^ documentPath = Environment::CurrentDirectory + "\\" + file;
	if (!File::Exists(documentPath))
	{
		showErrorBox("Не найден файл с теоретическим материалом! (" + file + ")\nПереустановите программный продукт");
		return false;
	}
	view->Navigate(documentPath);
	return true;
}

void CourseworkLibrary::Tools::handleExitButton(FormClosingEventArgs^ e, String^ message)
{
	// Подтверждение выхода из приложения
	if (e->CloseReason != CloseReason::UserClosing)
	{
		Application::Exit();
		return;
	}

	if (MessageBox::Show(message, "Подтверждение", MessageBoxButtons::YesNo,
		MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes)
	{
		Application::Exit();
	}
	else
	{
		e->Cancel = true;
	}
}

bool CourseworkLibrary::Tools::handleAnswerOne(RadioButton^ answer)
{
	bool right = answer->Checked;
	if (right) showRightAnswer();
	else showErrorBox("Операционная система является узлом основных аппаратных компонентов. " + 
		"В виду этого, работа ЭВМ без ОС невозможна.");

	return right;
}

bool CourseworkLibrary::Tools::handleAnswerTwo(CheckedListBox^ answer)
{
	bool right =
		answer->GetItemChecked(2) &&
		answer->GetItemChecked(3) &&
		answer->GetItemChecked(6) &&
		answer->CheckedIndices->Count == 3;

	if (right) showRightAnswer();
	else showErrorBox("Запуск ЭВМ невозможен без ЦПУ, ОЗУ и BIOS");

	return right;
}

bool CourseworkLibrary::Tools::handleAnswerThree(TextBox^ answer)
{
	bool right = answer->Text->Trim()->ToLower()->Equals("post");
	if (right) showRightAnswer();
	else showErrorBox("При нажатии кнопки питания на устройстве происходит начальная инициализация устройства. " +
		"Эта инициализация представляет собой серию диагностик, называемых POST — Power-On Self-Test.");

	return right;
}

bool CourseworkLibrary::Tools::handleAnswerFour(ListBox^ answer)
{
	bool right = answer->SelectedIndex == 2;
	if (right) showRightAnswer();
	else showErrorBox("Чтобы диск считался загрузочным, он должен иметь " +
		"специальную сигнатуру под названием ГЛАВНАЯ ЗАГРУЗОЧНАЯ ЗАПИСЬ");

	return right;
}

bool CourseworkLibrary::Tools::handleAnswerFive(int answer)
{
	bool right = answer == 4;
	if (right) showRightAnswer();
	else showErrorBox("Гибридное ядро представляет собой модифицированную версию микроядра, " +
		"объединяющую достоинства и недостатки монолитного и микроядра.");

	return right;
}

bool CourseworkLibrary::Tools::handleAnswerSix(CheckBox^ answer_1, CheckBox^ answer_2, CheckBox^ answer_3)
{
	bool right = !answer_1->Checked && answer_2->Checked && answer_3->Checked;
	if (right) showRightAnswer();
	else showErrorBox("Верными утверждениями являются пункты 2 и 3.");

	return right;
}

bool CourseworkLibrary::Tools::handleAnswerSeven(int answer)
{
	bool right = answer == 3;
	if (right) showRightAnswer();
	else showErrorBox("Максимально доступный объём оперативной памяти, с которым может работать " +
		"32-х разрядная операционная система, ограничен 4-мя гигабайтами.");

	return right;
}

bool CourseworkLibrary::Tools::handleAnswerEight(CheckBox^ answer_1, CheckBox^ answer_2, CheckBox^ answer_3)
{
	bool right = answer_1->Checked && !answer_2->Checked && answer_3->Checked;
	if (right) showRightAnswer();
	else showErrorBox("Верными утверждениями являются пункты 1 и 3.");

	return right;
}

bool CourseworkLibrary::Tools::handleAnswerNine(RadioButton^ answer)
{
	bool right = answer->Checked;
	if (right) showRightAnswer();
	else showErrorBox("Процессы порождают потоки.");

	return right;
}

bool CourseworkLibrary::Tools::handleAnswerTen(TextBox^ answer)
{
	bool right = answer->Text->Trim()->ToLower()->Equals("пулом");
	if (right) showRightAnswer();
	else showErrorBox("Контейнером для процессов называется пул потоков.");

	return right;
}

bool CourseworkLibrary::Tools::handleAnswerEleven(TextBox^ answer)
{
	String^ str = answer->Text->Trim()->ToLower();
	bool right = str->Equals("семафор") || str->Equals("семафоры");
	if (right) showRightAnswer();
	else showErrorBox("Синхронизация потоков в Windows обеспечивается семафорами.");

	return right;
}

bool CourseworkLibrary::Tools::handleAnswerTwelve(NumericUpDown^ counter_1, NumericUpDown^ counter_2, NumericUpDown^ counter_3)
{
	bool right = counter_1->Value == 2 && counter_2->Value == 3 && counter_3->Value == 1;
	if (right) showRightAnswer();
	else showErrorBox("Задание — коллекция процессов.\nПроцесс — контейнер для ресурсов.\n" +
		"Пул потоков — контейнер, занимающийся поочерёдным выполнением заданий.");

	return right;
}

bool CourseworkLibrary::Tools::handleAnswerThirteen(RadioButton^ answer)
{
	bool right = answer->Checked;
	if (right) showRightAnswer();
	else showErrorBox("Данная концепция называется виртуальной памятью.");

	return right;
}

bool CourseworkLibrary::Tools::handleAnswerFourteen(RadioButton^ answer)
{
	bool right = answer->Checked;
	if (right) showRightAnswer();
	else showErrorBox("В ОС Windows реализована страничная организация памяти.");

	return right;
}

bool CourseworkLibrary::Tools::handleAnswerFifteen(
	CheckBox^ answer_1, CheckBox^ answer_2,
	CheckBox^ answer_3, CheckBox^ answer_4)
{
	bool right = answer_1->Checked && !answer_2->Checked && answer_3->Checked && answer_4->Checked;
	if (right) showRightAnswer();
	else showErrorBox("Верными утверждениями являются пункты 1, 3 и 4.");

	return right;
}

bool CourseworkLibrary::Tools::handleAnswerSixteen(RadioButton^ answer)
{
	bool right = answer->Checked;
	if (right) showRightAnswer();
	else showErrorBox("В настоящее время в персональных и других компьютерах используется третий способ ввода - вывода.");

	return right;
}

void CourseworkLibrary::Tools::showResults(DataGridView^ view, array<bool>^ results)
{
	// Вывод в DGV
	view->ColumnCount = 2;
	view->RowCount = 16;

	for (size_t i = 0; i < 16; i++)
	{
		view->Rows[i]->Cells[0]->Value = "Вопрос №" + (i + 1);
		view->Rows[i]->Cells[1]->Value = results[i] ? "ВЕРНО" : "НЕВЕРНО";
	}

	int sum = 0;
	for (int i = 0; i < view->RowCount; i++)
		sum += view->Rows[i]->Height;
	
	view->Height = sum;

	view->Columns[0]->AutoSizeMode = DataGridViewAutoSizeColumnMode::AllCells;
	view->Columns[1]->AutoSizeMode = DataGridViewAutoSizeColumnMode::AllCells;
}

void CourseworkLibrary::Tools::showResults(Chart^ view, double percentage)
{
	// Вывод в диаграмму
	view->Titles->Add("РЕЗУЛЬТАТЫ (В ПРОЦЕНТАХ)");
	view->Series["Series"]->IsValueShownAsLabel = true;
	view->Series["Series"]->Points->AddXY("ВЕРНО", percentage);
	view->Series["Series"]->Points->AddXY("НЕВЕРНО", (double)(100 - percentage));
}

static void create_db(String^ path)
{
	// Создание файла БД
	ADOX::Catalog^ catalog = gcnew ADOX::CatalogClass();
	try
	{
		catalog->Create("Provider = Microsoft.Jet.OLEDB.4.0; Data Source = " + path);
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

static void configure_db(String^ path)
{
	// Создание структуры БД
	auto p = gcnew OleDbConnection("Provider = Microsoft.Jet.OLEDB.4.0; Data Source = " + path);
	p->Open();
	auto c = gcnew OleDbCommand("CREATE TABLE [Результат]([Номер вопроса] counter, [Результат] char(200))", p);
	try
	{
		c->ExecuteNonQuery();
	}
	catch (OleDbException^ exception)
	{
		MessageBox::Show(exception->Message, "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
	p->Close();
}

void CourseworkLibrary::Tools::write_to_db(array<bool>^ array, String^ timestamp)
{
	// Запись в БД
	String^ path = buildFolders(timestamp) + "\\РЕЗУЛЬТАТ.mdb";
	
	create_db(path);
	configure_db(path);

	for (size_t i = 0; i < 16; i++)
	{
		auto p = gcnew OleDbConnection("Provider=Microsoft.Jet.OLEDB.4.0; Data Source = " + path);
		p->Open();

		auto c = gcnew OleDbCommand("INSERT INTO[Результат](" +
			"[Номер вопроса], [Результат]) VALUES('" + (i + 1) + "','" + (array[i] ? "ВЕРНО" : "НЕВЕРНО") + " ')");
		c->Connection = p;
		c->ExecuteNonQuery();
	}

	showInfoBox("Ваши результаты были успешно записаны в таблицу Microsoft Access. Файл отчета может быть найден" +
		"в директории results рядом с запускаемым файлом программы.");
}

void CourseworkLibrary::Tools::write_to_notepad(array<bool>^ array, String^ timestamp)
{
	// Запись в текстовый файл
	String^ path = buildFolders(timestamp) + "\\РЕЗУЛЬТАТ.txt";

	try {
		auto encoding = System::Text::Encoding::GetEncoding(1251);
		auto stream = gcnew StreamWriter(path, false, encoding);
		stream->WriteLine("Номер вопроса | Результат");
		for (int i = 0; i < 16; i++)
		{
			stream->WriteLine(String::Format("{0, 16}", (i + 1) + " | ") + (array[i] ? "ВЕРНО" : "НЕВЕРНО"));
		}

		stream->Close();
		showInfoBox("Ваши результаты были успешно записаны в тестовый файл. Файл отчета может быть найден " +
			"в директории results рядом с запускаемым файлом программы.");
	}
	catch (System::Exception^ exception) {
		MessageBox::Show(exception->Message, "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
}

void CourseworkLibrary::Tools::write_to_word(array<bool>^ array)
{
	// Запись в документ Word
	auto word = gcnew WordApplicationClass();
	word->Visible = true;
	auto missing = Type::Missing;
	auto document = word->Documents->Add(missing, missing, missing, missing);
	Object^ behavior1 = WdDefaultTableBehavior::wdWord9TableBehavior;
	Object^ behavior2 = WdAutoFitBehavior::wdAutoFitContent;

	word->Selection->TypeText("Результат тестирования");
	Table^ table = word->ActiveDocument->Tables->Add(word->Selection->Range,
		16, 2, behavior1, behavior2);

	for (size_t i = 0; i < 16; i++)
	{
		table->Cell(i + 1, 1)->Range->InsertAfter("Вопрос №" + (i + 1));
		String^ str = String::Format("{0:f0}", (array[i] ? "ВЕРНО" : "НЕВЕРНО"));
		table->Cell(i + 1, 2)->Range->InsertAfter(str);
	}
}

void CourseworkLibrary::Tools::write_to_excel(array<bool>^ array)
{
	// Запись в лист Excel
	auto excel = gcnew ExcelApplication();
	excel->Visible = true;
	auto missing = Type::Missing;
	auto workbook = excel->Workbooks->Add(missing);
	auto sheet = workbook->Worksheets;

	for (size_t i = 0; i < 16; i++)
	{
		excel->Cells[2, i + 1] = "№" + (i + 1);
	}
	
	for (size_t i = 0; i < 16; i++)
	{
		excel->Cells[3, i + 1] = array[i] ? "ВЕРНО" : "НЕВЕРНО";
	}
}

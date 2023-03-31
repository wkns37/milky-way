// CourseworkLibrary.cpp
#include "CourseworkLibrary.h"

void CourseworkLibrary::Tools::showInfoBox(String^ message)
{
	// ����� ��������������� ���������
	MessageBox::Show(message, "����������", MessageBoxButtons::OK, MessageBoxIcon::Information);
}

void CourseworkLibrary::Tools::showErrorBox(String^ message)
{
	// ����� ��������������� ���������
	MessageBox::Show(message, "������", MessageBoxButtons::OK, MessageBoxIcon::Error);
}

static void showRightAnswer(String^ message = "�� �������� ���������!")
{
	// ����� ��������������� ���������
	MessageBox::Show(message, "�����", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
}

static void showWrongAnswer(String^ message)
{
	// ����� ��������������� ���������
	MessageBox::Show(message, "������", MessageBoxButtons::OK, MessageBoxIcon::Error);
}

static String^ buildFolders(String^ timestamp)
{
	// ������� ��������� �����
	if (!IO::Directory::Exists("results"))
		IO::Directory::CreateDirectory("results");

	if (!IO::Directory::Exists("results\\" + timestamp))
		IO::Directory::CreateDirectory("results\\" + timestamp);

	return "results\\" + timestamp;
}

void CourseworkLibrary::Tools::setHighlighted(Label^ label, bool bold)
{
	// ��������� ���������� �������
	if (bold) label->Font = gcnew Font(label->Font, FontStyle::Bold);
	else label->Font = gcnew Font(label->Font, FontStyle::Regular);
}

void CourseworkLibrary::Tools::setBackgroundColor(Form^ form, double percentage)
{
	// ���� �������� ����� ������� �� �������� ����������
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
	// �������� ���������� ����� � ������
	String^ username = field_username->Text->Trim();
	String^ password = field_password->Text->Trim();

	if (username->Equals(""))
	{
		showErrorBox("���� ����� ������������ �� ����� ���� ������");
		return false;
	}

	if (!password->Equals("password1324"))
	{
		showErrorBox("�������� ������");
		return false;
	}

	return true;
}

bool CourseworkLibrary::Tools::loadMaterial(WebBrowser^ view, String^ file)
{
	// �������� ���������
	String^ documentPath = Environment::CurrentDirectory + "\\" + file;
	if (!File::Exists(documentPath))
	{
		showErrorBox("�� ������ ���� � ������������� ����������! (" + file + ")\n�������������� ����������� �������");
		return false;
	}
	view->Navigate(documentPath);
	return true;
}

void CourseworkLibrary::Tools::handleExitButton(FormClosingEventArgs^ e, String^ message)
{
	// ������������� ������ �� ����������
	if (e->CloseReason != CloseReason::UserClosing)
	{
		Application::Exit();
		return;
	}

	if (MessageBox::Show(message, "�������������", MessageBoxButtons::YesNo,
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
	else showErrorBox("������������ ������� �������� ����� �������� ���������� �����������. " + 
		"� ���� �����, ������ ��� ��� �� ����������.");

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
	else showErrorBox("������ ��� ���������� ��� ���, ��� � BIOS");

	return right;
}

bool CourseworkLibrary::Tools::handleAnswerThree(TextBox^ answer)
{
	bool right = answer->Text->Trim()->ToLower()->Equals("post");
	if (right) showRightAnswer();
	else showErrorBox("��� ������� ������ ������� �� ���������� ���������� ��������� ������������� ����������. " +
		"��� ������������� ������������ ����� ����� ����������, ���������� POST � Power-On Self-Test.");

	return right;
}

bool CourseworkLibrary::Tools::handleAnswerFour(ListBox^ answer)
{
	bool right = answer->SelectedIndex == 2;
	if (right) showRightAnswer();
	else showErrorBox("����� ���� �������� �����������, �� ������ ����� " +
		"����������� ��������� ��� ��������� ������� ����������� ������");

	return right;
}

bool CourseworkLibrary::Tools::handleAnswerFive(int answer)
{
	bool right = answer == 4;
	if (right) showRightAnswer();
	else showErrorBox("��������� ���� ������������ ����� ���������������� ������ ���������, " +
		"������������ ����������� � ���������� ����������� � ���������.");

	return right;
}

bool CourseworkLibrary::Tools::handleAnswerSix(CheckBox^ answer_1, CheckBox^ answer_2, CheckBox^ answer_3)
{
	bool right = !answer_1->Checked && answer_2->Checked && answer_3->Checked;
	if (right) showRightAnswer();
	else showErrorBox("������� ������������� �������� ������ 2 � 3.");

	return right;
}

bool CourseworkLibrary::Tools::handleAnswerSeven(int answer)
{
	bool right = answer == 3;
	if (right) showRightAnswer();
	else showErrorBox("����������� ��������� ����� ����������� ������, � ������� ����� �������� " +
		"32-� ��������� ������������ �������, ��������� 4-�� �����������.");

	return right;
}

bool CourseworkLibrary::Tools::handleAnswerEight(CheckBox^ answer_1, CheckBox^ answer_2, CheckBox^ answer_3)
{
	bool right = answer_1->Checked && !answer_2->Checked && answer_3->Checked;
	if (right) showRightAnswer();
	else showErrorBox("������� ������������� �������� ������ 1 � 3.");

	return right;
}

bool CourseworkLibrary::Tools::handleAnswerNine(RadioButton^ answer)
{
	bool right = answer->Checked;
	if (right) showRightAnswer();
	else showErrorBox("�������� ��������� ������.");

	return right;
}

bool CourseworkLibrary::Tools::handleAnswerTen(TextBox^ answer)
{
	bool right = answer->Text->Trim()->ToLower()->Equals("�����");
	if (right) showRightAnswer();
	else showErrorBox("����������� ��� ��������� ���������� ��� �������.");

	return right;
}

bool CourseworkLibrary::Tools::handleAnswerEleven(TextBox^ answer)
{
	String^ str = answer->Text->Trim()->ToLower();
	bool right = str->Equals("�������") || str->Equals("��������");
	if (right) showRightAnswer();
	else showErrorBox("������������� ������� � Windows �������������� ����������.");

	return right;
}

bool CourseworkLibrary::Tools::handleAnswerTwelve(NumericUpDown^ counter_1, NumericUpDown^ counter_2, NumericUpDown^ counter_3)
{
	bool right = counter_1->Value == 2 && counter_2->Value == 3 && counter_3->Value == 1;
	if (right) showRightAnswer();
	else showErrorBox("������� � ��������� ���������.\n������� � ��������� ��� ��������.\n" +
		"��� ������� � ���������, ������������ ���������� ����������� �������.");

	return right;
}

bool CourseworkLibrary::Tools::handleAnswerThirteen(RadioButton^ answer)
{
	bool right = answer->Checked;
	if (right) showRightAnswer();
	else showErrorBox("������ ��������� ���������� ����������� �������.");

	return right;
}

bool CourseworkLibrary::Tools::handleAnswerFourteen(RadioButton^ answer)
{
	bool right = answer->Checked;
	if (right) showRightAnswer();
	else showErrorBox("� �� Windows ����������� ���������� ����������� ������.");

	return right;
}

bool CourseworkLibrary::Tools::handleAnswerFifteen(
	CheckBox^ answer_1, CheckBox^ answer_2,
	CheckBox^ answer_3, CheckBox^ answer_4)
{
	bool right = answer_1->Checked && !answer_2->Checked && answer_3->Checked && answer_4->Checked;
	if (right) showRightAnswer();
	else showErrorBox("������� ������������� �������� ������ 1, 3 � 4.");

	return right;
}

bool CourseworkLibrary::Tools::handleAnswerSixteen(RadioButton^ answer)
{
	bool right = answer->Checked;
	if (right) showRightAnswer();
	else showErrorBox("� ��������� ����� � ������������ � ������ ����������� ������������ ������ ������ ����� - ������.");

	return right;
}

void CourseworkLibrary::Tools::showResults(DataGridView^ view, array<bool>^ results)
{
	// ����� � DGV
	view->ColumnCount = 2;
	view->RowCount = 16;

	for (size_t i = 0; i < 16; i++)
	{
		view->Rows[i]->Cells[0]->Value = "������ �" + (i + 1);
		view->Rows[i]->Cells[1]->Value = results[i] ? "�����" : "�������";
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
	// ����� � ���������
	view->Titles->Add("���������� (� ���������)");
	view->Series["Series"]->IsValueShownAsLabel = true;
	view->Series["Series"]->Points->AddXY("�����", percentage);
	view->Series["Series"]->Points->AddXY("�������", (double)(100 - percentage));
}

static void create_db(String^ path)
{
	// �������� ����� ��
	ADOX::Catalog^ catalog = gcnew ADOX::CatalogClass();
	try
	{
		catalog->Create("Provider = Microsoft.Jet.OLEDB.4.0; Data Source = " + path);
	}
	catch (System::Runtime::InteropServices::COMException^ exception)
	{
		MessageBox::Show(exception->Message, "������", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
	finally
	{
		catalog = nullptr;
	}
}

static void configure_db(String^ path)
{
	// �������� ��������� ��
	auto p = gcnew OleDbConnection("Provider = Microsoft.Jet.OLEDB.4.0; Data Source = " + path);
	p->Open();
	auto c = gcnew OleDbCommand("CREATE TABLE [���������]([����� �������] counter, [���������] char(200))", p);
	try
	{
		c->ExecuteNonQuery();
	}
	catch (OleDbException^ exception)
	{
		MessageBox::Show(exception->Message, "������", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
	p->Close();
}

void CourseworkLibrary::Tools::write_to_db(array<bool>^ array, String^ timestamp)
{
	// ������ � ��
	String^ path = buildFolders(timestamp) + "\\���������.mdb";
	
	create_db(path);
	configure_db(path);

	for (size_t i = 0; i < 16; i++)
	{
		auto p = gcnew OleDbConnection("Provider=Microsoft.Jet.OLEDB.4.0; Data Source = " + path);
		p->Open();

		auto c = gcnew OleDbCommand("INSERT INTO[���������](" +
			"[����� �������], [���������]) VALUES('" + (i + 1) + "','" + (array[i] ? "�����" : "�������") + " ')");
		c->Connection = p;
		c->ExecuteNonQuery();
	}

	showInfoBox("���� ���������� ���� ������� �������� � ������� Microsoft Access. ���� ������ ����� ���� ������" +
		"� ���������� results ����� � ����������� ������ ���������.");
}

void CourseworkLibrary::Tools::write_to_notepad(array<bool>^ array, String^ timestamp)
{
	// ������ � ��������� ����
	String^ path = buildFolders(timestamp) + "\\���������.txt";

	try {
		auto encoding = System::Text::Encoding::GetEncoding(1251);
		auto stream = gcnew StreamWriter(path, false, encoding);
		stream->WriteLine("����� ������� | ���������");
		for (int i = 0; i < 16; i++)
		{
			stream->WriteLine(String::Format("{0, 16}", (i + 1) + " | ") + (array[i] ? "�����" : "�������"));
		}

		stream->Close();
		showInfoBox("���� ���������� ���� ������� �������� � �������� ����. ���� ������ ����� ���� ������ " +
			"� ���������� results ����� � ����������� ������ ���������.");
	}
	catch (System::Exception^ exception) {
		MessageBox::Show(exception->Message, "������", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
}

void CourseworkLibrary::Tools::write_to_word(array<bool>^ array)
{
	// ������ � �������� Word
	auto word = gcnew WordApplicationClass();
	word->Visible = true;
	auto missing = Type::Missing;
	auto document = word->Documents->Add(missing, missing, missing, missing);
	Object^ behavior1 = WdDefaultTableBehavior::wdWord9TableBehavior;
	Object^ behavior2 = WdAutoFitBehavior::wdAutoFitContent;

	word->Selection->TypeText("��������� ������������");
	Table^ table = word->ActiveDocument->Tables->Add(word->Selection->Range,
		16, 2, behavior1, behavior2);

	for (size_t i = 0; i < 16; i++)
	{
		table->Cell(i + 1, 1)->Range->InsertAfter("������ �" + (i + 1));
		String^ str = String::Format("{0:f0}", (array[i] ? "�����" : "�������"));
		table->Cell(i + 1, 2)->Range->InsertAfter(str);
	}
}

void CourseworkLibrary::Tools::write_to_excel(array<bool>^ array)
{
	// ������ � ���� Excel
	auto excel = gcnew ExcelApplication();
	excel->Visible = true;
	auto missing = Type::Missing;
	auto workbook = excel->Workbooks->Add(missing);
	auto sheet = workbook->Worksheets;

	for (size_t i = 0; i < 16; i++)
	{
		excel->Cells[2, i + 1] = "�" + (i + 1);
	}
	
	for (size_t i = 0; i < 16; i++)
	{
		excel->Cells[3, i + 1] = array[i] ? "�����" : "�������";
	}
}

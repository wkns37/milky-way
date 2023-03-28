#pragma once

using namespace System;
using namespace System::IO;
using namespace System::Windows::Forms;
using namespace System::Drawing;

using System::Windows::Forms::DataVisualization::Charting::Chart;
using Microsoft::VisualBasic::Interaction;

using System::Data::OleDb::OleDbConnection;
using System::Data::OleDb::OleDbCommand;
using System::Data::OleDb::OleDbException;

using WordApplicationClass = Microsoft::Office::Interop::Word::ApplicationClass;
using Microsoft::Office::Interop::Word::Table;
using Microsoft::Office::Interop::Word::WdDefaultTableBehavior;
using Microsoft::Office::Interop::Word::WdAutoFitBehavior;

using ExcelApplication = Microsoft::Office::Interop::Excel::Application;

namespace CourseworkLibrary {

	public ref class Tools
	{
	public:
		static void showInfoBox(String^ message);
		static void showErrorBox(String^ message);
		static bool isCredentialsValid(TextBox^ field_username, TextBox^ field_password);
		static bool loadMaterial(WebBrowser^ view, String^ file);
		static void handleExitButton(FormClosingEventArgs^ e, String^ message);

		static void setHighlighted(Label^ label, bool bold);
		static void setBackgroundColor(Form^ form, double percentage);

		static bool handleAnswerOne(RadioButton^ answer);
		static bool handleAnswerTwo(CheckedListBox^ answer);
		static bool handleAnswerThree(TextBox^ answer);
		static bool handleAnswerFour(ListBox^ answer);
		static bool handleAnswerFive(int answer);
		static bool handleAnswerSix(CheckBox^ answer_1, CheckBox^ answer_2, CheckBox^ answer_3);
		static bool handleAnswerSeven(int answer);
		static bool handleAnswerEight(CheckBox^ answer_1, CheckBox^ answer_2, CheckBox^ answer_3);
		static bool handleAnswerNine(RadioButton^ answer);
		static bool handleAnswerTen(TextBox^ answer);
		static bool handleAnswerEleven(TextBox^ answer);
		static bool handleAnswerTwelve(NumericUpDown^ counter_1, NumericUpDown^ counter_2, NumericUpDown^ counter_3);
		static bool handleAnswerThirteen(RadioButton^ answer);
		static bool handleAnswerFourteen(RadioButton^ answer);
		static bool handleAnswerFifteen(CheckBox^ answer_1, CheckBox^ answer_2, CheckBox^ answer_3, CheckBox^ answer_4);
		static bool handleAnswerSixteen(RadioButton^ answer);

		static void showResults(DataGridView^ view, array<bool>^ results);
		static void showResults(Chart^ view, double percentage);
		
		static void write_to_db(array<bool>^ array, String^ timestamp);
		static void write_to_notepad(array<bool>^ array, String^ timestamp);
		static void write_to_word(array<bool>^ array);
		static void write_to_excel(array<bool>^ array);
	};
}

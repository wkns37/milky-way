#pragma once
#include <math.h>
#include <algorithm>
#include <assert.h>

namespace Labs {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace Microsoft::VisualBasic;

	/// <summary>
	/// Summary for Lab1
	/// </summary>
	public ref class Lab7 : public System::Windows::Forms::Form
	{
	private:
		Form^ parent = nullptr;
	public:
		Lab7(Form^ parent)
		{
			InitializeComponent();
			this->parent = parent;
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Lab7()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		System::Windows::Forms::Label^ header_title;
		System::Windows::Forms::Label^ label_copyright;
		System::Windows::Forms::Button^ button_home;
		System::Windows::Forms::Button^ button_fill;
		System::Windows::Forms::Label^ label8;
		System::Windows::Forms::DataGridView^ grid;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->header_title = (gcnew System::Windows::Forms::Label());
			this->label_copyright = (gcnew System::Windows::Forms::Label());
			this->button_home = (gcnew System::Windows::Forms::Button());
			this->button_fill = (gcnew System::Windows::Forms::Button());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->grid = (gcnew System::Windows::Forms::DataGridView());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->grid))->BeginInit();
			this->SuspendLayout();
			// 
			// header_title
			// 
			this->header_title->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->header_title->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->header_title->Location = System::Drawing::Point(12, 11);
			this->header_title->Name = L"header_title";
			this->header_title->Size = System::Drawing::Size(1317, 98);
			this->header_title->TabIndex = 1;
			this->header_title->Text = L"Лабораторная работа №7\r\n«Работа с одномерными массивами»";
			this->header_title->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// label_copyright
			// 
			this->label_copyright->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->label_copyright->AutoSize = true;
			this->label_copyright->Enabled = false;
			this->label_copyright->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_copyright->Location = System::Drawing::Point(12, 745);
			this->label_copyright->Name = L"label_copyright";
			this->label_copyright->Size = System::Drawing::Size(605, 132);
			this->label_copyright->TabIndex = 5;
			this->label_copyright->Text = L"Выполнил: студент группы БСТ2001 Савкин Д.И.\r\nВариант № 26\r\nПроверил: доцент кафе"
				L"дры «Информатика»\r\nГуриков С.Р.\r\n";
			// 
			// button_home
			// 
			this->button_home->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->button_home->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_home->Location = System::Drawing::Point(1162, 833);
			this->button_home->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->button_home->Name = L"button_home";
			this->button_home->Size = System::Drawing::Size(167, 44);
			this->button_home->TabIndex = 6;
			this->button_home->Text = L"На главную";
			this->button_home->UseVisualStyleBackColor = true;
			this->button_home->Click += gcnew System::EventHandler(this, &Lab7::button_home_click);
			// 
			// button_fill
			// 
			this->button_fill->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_fill->Location = System::Drawing::Point(12, 180);
			this->button_fill->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->button_fill->Name = L"button_fill";
			this->button_fill->Size = System::Drawing::Size(202, 44);
			this->button_fill->TabIndex = 3;
			this->button_fill->Text = L"ЗАПОЛНИТЬ";
			this->button_fill->UseVisualStyleBackColor = true;
			this->button_fill->Click += gcnew System::EventHandler(this, &Lab7::button_solve_click);
			// 
			// label8
			// 
			this->label8->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label8->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label8->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label8->Location = System::Drawing::Point(12, 109);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(1317, 67);
			this->label8->TabIndex = 2;
			this->label8->Text = L"При нажатии на кнопку будет сформирован массив, а в блоке вывода\r\nданных будет ук"
				L"азано количество пар значений массива, разность которых кратна 7";
			this->label8->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// grid
			// 
			this->grid->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::AllCells;
			this->grid->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::AllCells;
			this->grid->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->grid->ColumnHeadersVisible = false;
			this->grid->Location = System::Drawing::Point(12, 231);
			this->grid->Name = L"grid";
			this->grid->ReadOnly = true;
			this->grid->RowHeadersVisible = false;
			this->grid->RowHeadersWidth = 62;
			this->grid->RowTemplate->Height = 28;
			this->grid->ScrollBars = System::Windows::Forms::ScrollBars::Horizontal;
			this->grid->Size = System::Drawing::Size(627, 104);
			this->grid->TabIndex = 4;
			// 
			// Lab7
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(10, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1341, 886);
			this->Controls->Add(this->grid);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->button_home);
			this->Controls->Add(this->label_copyright);
			this->Controls->Add(this->header_title);
			this->Controls->Add(this->button_fill);
			this->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->Name = L"Lab7";
			this->ShowIcon = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Лабораторная №7";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &Lab7::button_exit_click);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->grid))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion

	private:
		System::Void button_exit_click(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e)
		{
			Application::Exit();
		}

		System::Void button_home_click(System::Object^ sender, System::EventArgs^ e)
		{
			parent->Show();
			this->Hide();
		}

		System::Void button_solve_click(System::Object^ sender, System::EventArgs^ e)
		{
			String^ input = Interaction::InputBox("Введите количество элементов массива", "Ввод", "10", -1, -1);
			int number = Convert::ToInt16(input);
			int* arr = new int[number];

			UtilsLibrary2::Utils::fillArrayRandomly(arr, number, 0, 1000);
			UtilsLibrary2::Utils::fillWithArray(grid, arr, number);
			size_t count = UtilsLibrary2::Utils::solve(arr, number);
			MessageBox::Show("Количество пар соседних элементов, разница\nмежду которыми НЕ кратна 7: " +
				Convert::ToString(count), "Вывод", MessageBoxButtons::OK, MessageBoxIcon::Information);
			delete[] arr;
		}
	};
}

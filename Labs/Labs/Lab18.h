#pragma once

namespace Labs {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Lab18
	/// </summary>
	public ref class Lab18 : public System::Windows::Forms::Form
	{
	private:
		Form^ parent = nullptr;
	public:
		Lab18(Form^ parent)
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
		~Lab18()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ header_title;
	private: System::Windows::Forms::Button^ button_home;
	private: System::Windows::Forms::Label^ label_copyright;

	private: System::Windows::Forms::DataGridView^ grid_first;
	private: System::Windows::Forms::Button^ button_run;




	private: System::Windows::Forms::DataGridView^ grid_second;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::GroupBox^ groupBox2;






























	protected:

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
			this->button_home = (gcnew System::Windows::Forms::Button());
			this->label_copyright = (gcnew System::Windows::Forms::Label());
			this->grid_first = (gcnew System::Windows::Forms::DataGridView());
			this->button_run = (gcnew System::Windows::Forms::Button());
			this->grid_second = (gcnew System::Windows::Forms::DataGridView());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->grid_first))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->grid_second))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->SuspendLayout();
			// 
			// header_title
			// 
			this->header_title->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->header_title->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->header_title->Location = System::Drawing::Point(12, 9);
			this->header_title->Name = L"header_title";
			this->header_title->Size = System::Drawing::Size(1357, 133);
			this->header_title->TabIndex = 1;
			this->header_title->Text = L"Лабораторная работа №9\r\n«Двумерные массивы»";
			this->header_title->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// button_home
			// 
			this->button_home->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->button_home->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_home->Location = System::Drawing::Point(1202, 1004);
			this->button_home->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->button_home->Name = L"button_home";
			this->button_home->Size = System::Drawing::Size(167, 44);
			this->button_home->TabIndex = 8;
			this->button_home->Text = L"На главную";
			this->button_home->UseVisualStyleBackColor = true;
			this->button_home->Click += gcnew System::EventHandler(this, &Lab18::button_home_click);
			// 
			// label_copyright
			// 
			this->label_copyright->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->label_copyright->AutoSize = true;
			this->label_copyright->Enabled = false;
			this->label_copyright->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_copyright->Location = System::Drawing::Point(12, 920);
			this->label_copyright->Name = L"label_copyright";
			this->label_copyright->Size = System::Drawing::Size(605, 132);
			this->label_copyright->TabIndex = 7;
			this->label_copyright->Text = L"Выполнил: студент группы БСТ2001 Савкин Д.И.\r\nВариант № 24\r\nПроверил: доцент кафе"
				L"дры «Информатика»\r\nГуриков С.Р.\r\n";
			// 
			// grid_first
			// 
			this->grid_first->AllowUserToAddRows = false;
			this->grid_first->AllowUserToDeleteRows = false;
			this->grid_first->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::AllCells;
			this->grid_first->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::AllCells;
			this->grid_first->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->grid_first->ColumnHeadersVisible = false;
			this->grid_first->Location = System::Drawing::Point(6, 30);
			this->grid_first->Name = L"grid_first";
			this->grid_first->ReadOnly = true;
			this->grid_first->RowHeadersVisible = false;
			this->grid_first->RowHeadersWidth = 62;
			this->grid_first->RowTemplate->Height = 28;
			this->grid_first->ScrollBars = System::Windows::Forms::ScrollBars::None;
			this->grid_first->Size = System::Drawing::Size(319, 252);
			this->grid_first->TabIndex = 4;
			// 
			// button_run
			// 
			this->button_run->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_run->Location = System::Drawing::Point(12, 146);
			this->button_run->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->button_run->Name = L"button_run";
			this->button_run->Size = System::Drawing::Size(375, 44);
			this->button_run->TabIndex = 2;
			this->button_run->Text = L"ЗАПОЛНИТЬ И ПРИМЕНИТЬ АЛГОРИТМЫ";
			this->button_run->UseVisualStyleBackColor = true;
			this->button_run->Click += gcnew System::EventHandler(this, &Lab18::button_run_click);
			// 
			// grid_second
			// 
			this->grid_second->AllowUserToAddRows = false;
			this->grid_second->AllowUserToDeleteRows = false;
			this->grid_second->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::AllCells;
			this->grid_second->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::AllCells;
			this->grid_second->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->grid_second->ColumnHeadersVisible = false;
			this->grid_second->Location = System::Drawing::Point(6, 30);
			this->grid_second->Name = L"grid_second";
			this->grid_second->ReadOnly = true;
			this->grid_second->RowHeadersVisible = false;
			this->grid_second->RowHeadersWidth = 62;
			this->grid_second->RowTemplate->Height = 28;
			this->grid_second->ScrollBars = System::Windows::Forms::ScrollBars::None;
			this->grid_second->Size = System::Drawing::Size(627, 104);
			this->grid_second->TabIndex = 6;
			// 
			// groupBox1
			// 
			this->groupBox1->AutoSize = true;
			this->groupBox1->Controls->Add(this->grid_first);
			this->groupBox1->Location = System::Drawing::Point(12, 197);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(331, 312);
			this->groupBox1->TabIndex = 3;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Изначальная матрица";
			// 
			// groupBox2
			// 
			this->groupBox2->AutoSize = true;
			this->groupBox2->Controls->Add(this->grid_second);
			this->groupBox2->Location = System::Drawing::Point(12, 507);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(639, 164);
			this->groupBox2->TabIndex = 5;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Результирующий массив";
			// 
			// Lab18
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(10, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1381, 1061);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->button_run);
			this->Controls->Add(this->button_home);
			this->Controls->Add(this->label_copyright);
			this->Controls->Add(this->header_title);
			this->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->Name = L"Lab18";
			this->ShowIcon = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Лабораторная №9";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &Lab18::button_exit_click);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->grid_first))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->grid_second))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox2->ResumeLayout(false);
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

		System::Void button_run_click(System::Object^ sender, System::EventArgs^ e)
		{
			button_run->Enabled = false;

			String^ input = Interaction::InputBox("Введите количество строк матрицы", "Ввод", "5", -1, -1);
			size_t rows = Convert::ToInt16(input);
			input = Interaction::InputBox("Введите количество столбцов матрицы", "Ввод", "5", -1, -1);
			size_t columns = Convert::ToInt16(input);

			int** array = new int* [rows];

			UtilsLibrary4::Utils::generate_matrix(array, rows, columns);
			UtilsLibrary4::Utils::fill_with_matrix(grid_first, array, rows, columns);

			size_t size = UtilsLibrary4::Utils::solve(array, rows, columns);
			int* array2 = new int[size];
			UtilsLibrary4::Utils::solve2(array, rows, columns, array2);
			UtilsLibrary4::Utils::fill_with_array(grid_second, array2, size);

			MessageBox::Show(
				"Количество элементов на главной диагонали кратные 7: " + size, "Вывод",
				MessageBoxButtons::OK, MessageBoxIcon::Information
			);

			for (size_t i = 0; i < rows; i++)
				delete[] array[i];
			delete[] array;

			button_run->Enabled = true;
		}
	};
}

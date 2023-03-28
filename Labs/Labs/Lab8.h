#pragma once

namespace Labs {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Lab8
	/// </summary>
	public ref class Lab8 : public System::Windows::Forms::Form
	{
	private:
		Form^ parent = nullptr;
	public:
		Lab8(Form^ parent)
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
		~Lab8()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ header_title;
	private: System::Windows::Forms::Button^ button_home;
	private: System::Windows::Forms::Label^ label_copyright;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::DataGridView^ grid_first;
	private: System::Windows::Forms::Button^ button_fill;
	private: System::Windows::Forms::Button^ button_create;


	private: System::Windows::Forms::DataGridView^ grid_second;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Lab8::typeid));
			this->header_title = (gcnew System::Windows::Forms::Label());
			this->button_home = (gcnew System::Windows::Forms::Button());
			this->label_copyright = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->grid_first = (gcnew System::Windows::Forms::DataGridView());
			this->button_fill = (gcnew System::Windows::Forms::Button());
			this->button_create = (gcnew System::Windows::Forms::Button());
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
			this->header_title->Size = System::Drawing::Size(1317, 98);
			this->header_title->TabIndex = 1;
			this->header_title->Text = L"Лабораторная работа №8\r\n«Запись одномерных массивов в БД Microsoft Access»";
			this->header_title->TextAlign = System::Drawing::ContentAlignment::TopCenter;
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
			this->button_home->TabIndex = 10;
			this->button_home->Text = L"На главную";
			this->button_home->UseVisualStyleBackColor = true;
			this->button_home->Click += gcnew System::EventHandler(this, &Lab8::button_home_click);
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
			this->label_copyright->TabIndex = 9;
			this->label_copyright->Text = L"Выполнил: студент группы БСТ2001 Савкин Д.И.\r\nВариант № 26\r\nПроверил: доцент кафе"
				L"дры «Информатика»\r\nГуриков С.Р.\r\n";
			// 
			// label8
			// 
			this->label8->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label8->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label8->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label8->Location = System::Drawing::Point(12, 107);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(1317, 104);
			this->label8->TabIndex = 2;
			this->label8->Text = resources->GetString(L"label8.Text");
			this->label8->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// grid_first
			// 
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
			this->grid_first->ScrollBars = System::Windows::Forms::ScrollBars::Horizontal;
			this->grid_first->Size = System::Drawing::Size(627, 104);
			this->grid_first->TabIndex = 6;
			// 
			// button_fill
			// 
			this->button_fill->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_fill->Location = System::Drawing::Point(220, 215);
			this->button_fill->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->button_fill->Name = L"button_fill";
			this->button_fill->Size = System::Drawing::Size(202, 44);
			this->button_fill->TabIndex = 4;
			this->button_fill->Text = L"ЗАПОЛНИТЬ";
			this->button_fill->UseVisualStyleBackColor = true;
			this->button_fill->Click += gcnew System::EventHandler(this, &Lab8::button_fill_click);
			// 
			// button_create
			// 
			this->button_create->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_create->Location = System::Drawing::Point(12, 215);
			this->button_create->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->button_create->Name = L"button_create";
			this->button_create->Size = System::Drawing::Size(202, 44);
			this->button_create->TabIndex = 3;
			this->button_create->Text = L"СОЗДАТЬ ТАБЛИЦУ";
			this->button_create->UseVisualStyleBackColor = true;
			this->button_create->Click += gcnew System::EventHandler(this, &Lab8::button_create_click);
			// 
			// grid_second
			// 
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
			this->grid_second->ScrollBars = System::Windows::Forms::ScrollBars::Horizontal;
			this->grid_second->Size = System::Drawing::Size(627, 104);
			this->grid_second->TabIndex = 8;
			// 
			// groupBox1
			// 
			this->groupBox1->AutoSize = true;
			this->groupBox1->Controls->Add(this->grid_first);
			this->groupBox1->Location = System::Drawing::Point(12, 266);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(639, 164);
			this->groupBox1->TabIndex = 5;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Изначальный массив";
			// 
			// groupBox2
			// 
			this->groupBox2->AutoSize = true;
			this->groupBox2->Controls->Add(this->grid_second);
			this->groupBox2->Location = System::Drawing::Point(12, 436);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(639, 164);
			this->groupBox2->TabIndex = 7;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Конечный массив";
			// 
			// Lab8
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(10, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1341, 886);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->button_create);
			this->Controls->Add(this->button_fill);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->button_home);
			this->Controls->Add(this->label_copyright);
			this->Controls->Add(this->header_title);
			this->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->Name = L"Lab8";
			this->ShowIcon = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Лабораторная №8";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &Lab8::button_exit_click);
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

		System::Void button_create_click(System::Object^ sender, System::EventArgs^ e)
		{
			if (System::IO::File::Exists("solution.mdb"))
			{
				// Следует создать новый файл базы данных,
				// чтобы не мешать результаты с прошлыми
				System::IO::File::Delete("solution.mdb");
			}
			UtilsLibrary2::Utils::create_db();
			UtilsLibrary2::Utils::configure_db();
		}

		System::Void button_fill_click(System::Object^ sender, System::EventArgs^ e)
		{
			button_fill->Enabled = false;
			String^ input = Interaction::InputBox("Введите количество элементов массива", "Ввод", "10", -1, -1);
			int number = Convert::ToInt16(input);
			int* arr1 = new int[number];
			int* arr2 = new int[number];

			UtilsLibrary2::Utils::fillArrayRandomly(arr1, number, 0, 1000);
			UtilsLibrary2::Utils::fillWithArray(grid_first, arr1, number);
			size_t count = UtilsLibrary2::Utils::solve(arr1, number);
			MessageBox::Show("Количество пар соседних элементов, разница\nмежду которыми НЕ кратна 7: " +
				Convert::ToString(count), "Вывод", MessageBoxButtons::OK, MessageBoxIcon::Information);

			int new_length = 0;
			UtilsLibrary2::Utils::solve2(arr1, arr2, number, new_length, count);
			UtilsLibrary2::Utils::fillWithArray(grid_second, arr2, new_length);
			UtilsLibrary2::Utils::write_to_db(arr1, arr2, number, new_length);

			delete[] arr1;
			delete[] arr2;
			button_fill->Enabled = true;
		}
	};
}

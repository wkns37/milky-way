#pragma once

namespace Labs {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Lab9
	/// </summary>
	public ref class Lab16 : public System::Windows::Forms::Form
	{
	private:
		Form^ parent = nullptr;
	public:
		Lab16(Form^ parent)
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
		~Lab16()
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
	private: System::Windows::Forms::DataGridView^ grid_third;
	private: System::Windows::Forms::DataGridView^ grid_fourth;
	private: System::Windows::Forms::GroupBox^ groupBox3;
	private: System::Windows::Forms::GroupBox^ groupBox4;
	private: System::Windows::Forms::RadioButton^ radio_1;
	private: System::Windows::Forms::RadioButton^ radio_2;
	private: System::Windows::Forms::RadioButton^ radio_3;
	private: System::Windows::Forms::RadioButton^ radio_4;




	private: System::Windows::Forms::GroupBox^ groupBox5;
	private: System::Windows::Forms::Button^ button_do_insertation_sort;

	private: System::Windows::Forms::GroupBox^ groupBox6;
	private: System::Windows::Forms::Button^ button_do_binary_sort;
	private: System::Windows::Forms::Button^ button_do_selection_sort;
	private: System::Windows::Forms::Button^ button_save_array;
	private: System::Windows::Forms::Button^ button_load_array;



	private: System::Windows::Forms::Label^ label1;






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
			this->grid_third = (gcnew System::Windows::Forms::DataGridView());
			this->grid_fourth = (gcnew System::Windows::Forms::DataGridView());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->radio_1 = (gcnew System::Windows::Forms::RadioButton());
			this->radio_2 = (gcnew System::Windows::Forms::RadioButton());
			this->radio_3 = (gcnew System::Windows::Forms::RadioButton());
			this->radio_4 = (gcnew System::Windows::Forms::RadioButton());
			this->groupBox5 = (gcnew System::Windows::Forms::GroupBox());
			this->button_do_insertation_sort = (gcnew System::Windows::Forms::Button());
			this->groupBox6 = (gcnew System::Windows::Forms::GroupBox());
			this->button_load_array = (gcnew System::Windows::Forms::Button());
			this->button_save_array = (gcnew System::Windows::Forms::Button());
			this->button_do_selection_sort = (gcnew System::Windows::Forms::Button());
			this->button_do_binary_sort = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->grid_first))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->grid_second))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->grid_third))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->grid_fourth))->BeginInit();
			this->groupBox3->SuspendLayout();
			this->groupBox4->SuspendLayout();
			this->groupBox5->SuspendLayout();
			this->groupBox6->SuspendLayout();
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
			this->header_title->Text = L"Лабораторная работа №7\r\n«Алгоритмы сортировки одномерных массивов.\r\nЗапись и чтен"
				L"ие одномерных массивов в/из файла»";
			this->header_title->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// button_home
			// 
			this->button_home->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->button_home->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_home->Location = System::Drawing::Point(1202, 1156);
			this->button_home->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->button_home->Name = L"button_home";
			this->button_home->Size = System::Drawing::Size(167, 44);
			this->button_home->TabIndex = 8;
			this->button_home->Text = L"На главную";
			this->button_home->UseVisualStyleBackColor = true;
			this->button_home->Click += gcnew System::EventHandler(this, &Lab16::button_home_click);
			// 
			// label_copyright
			// 
			this->label_copyright->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->label_copyright->AutoSize = true;
			this->label_copyright->Enabled = false;
			this->label_copyright->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_copyright->Location = System::Drawing::Point(12, 1072);
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
			this->grid_first->ScrollBars = System::Windows::Forms::ScrollBars::Horizontal;
			this->grid_first->Size = System::Drawing::Size(627, 104);
			this->grid_first->TabIndex = 4;
			// 
			// button_run
			// 
			this->button_run->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_run->Location = System::Drawing::Point(12, 223);
			this->button_run->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->button_run->Name = L"button_run";
			this->button_run->Size = System::Drawing::Size(375, 44);
			this->button_run->TabIndex = 2;
			this->button_run->Text = L"ЗАПОЛНИТЬ И ПРИМЕНИТЬ АЛГОРИТМЫ";
			this->button_run->UseVisualStyleBackColor = true;
			this->button_run->Click += gcnew System::EventHandler(this, &Lab16::button_run_click);
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
			this->grid_second->ScrollBars = System::Windows::Forms::ScrollBars::Horizontal;
			this->grid_second->Size = System::Drawing::Size(627, 104);
			this->grid_second->TabIndex = 6;
			// 
			// groupBox1
			// 
			this->groupBox1->AutoSize = true;
			this->groupBox1->Controls->Add(this->grid_first);
			this->groupBox1->Location = System::Drawing::Point(12, 274);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(639, 164);
			this->groupBox1->TabIndex = 3;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Изначальный массив";
			// 
			// groupBox2
			// 
			this->groupBox2->AutoSize = true;
			this->groupBox2->Controls->Add(this->grid_second);
			this->groupBox2->Location = System::Drawing::Point(12, 444);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(639, 164);
			this->groupBox2->TabIndex = 5;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Результирующий массив";
			// 
			// grid_third
			// 
			this->grid_third->AllowUserToAddRows = false;
			this->grid_third->AllowUserToDeleteRows = false;
			this->grid_third->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::AllCells;
			this->grid_third->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::AllCells;
			this->grid_third->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->grid_third->ColumnHeadersVisible = false;
			this->grid_third->Location = System::Drawing::Point(6, 30);
			this->grid_third->Name = L"grid_third";
			this->grid_third->ReadOnly = true;
			this->grid_third->RowHeadersVisible = false;
			this->grid_third->RowHeadersWidth = 62;
			this->grid_third->RowTemplate->Height = 28;
			this->grid_third->ScrollBars = System::Windows::Forms::ScrollBars::Horizontal;
			this->grid_third->Size = System::Drawing::Size(627, 104);
			this->grid_third->TabIndex = 7;
			// 
			// grid_fourth
			// 
			this->grid_fourth->AllowUserToAddRows = false;
			this->grid_fourth->AllowUserToDeleteRows = false;
			this->grid_fourth->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::AllCells;
			this->grid_fourth->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::AllCells;
			this->grid_fourth->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->grid_fourth->ColumnHeadersVisible = false;
			this->grid_fourth->Location = System::Drawing::Point(6, 30);
			this->grid_fourth->Name = L"grid_fourth";
			this->grid_fourth->ReadOnly = true;
			this->grid_fourth->RowHeadersVisible = false;
			this->grid_fourth->RowHeadersWidth = 62;
			this->grid_fourth->RowTemplate->Height = 28;
			this->grid_fourth->ScrollBars = System::Windows::Forms::ScrollBars::Horizontal;
			this->grid_fourth->Size = System::Drawing::Size(627, 104);
			this->grid_fourth->TabIndex = 9;
			// 
			// groupBox3
			// 
			this->groupBox3->AutoSize = true;
			this->groupBox3->Controls->Add(this->grid_third);
			this->groupBox3->Location = System::Drawing::Point(12, 606);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(639, 164);
			this->groupBox3->TabIndex = 7;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Массив после удаления элемента";
			// 
			// groupBox4
			// 
			this->groupBox4->AutoSize = true;
			this->groupBox4->Controls->Add(this->grid_fourth);
			this->groupBox4->Location = System::Drawing::Point(12, 760);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(639, 164);
			this->groupBox4->TabIndex = 8;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"Массив после вставки элемента";
			// 
			// radio_1
			// 
			this->radio_1->AutoSize = true;
			this->radio_1->Checked = true;
			this->radio_1->Location = System::Drawing::Point(6, 75);
			this->radio_1->Name = L"radio_1";
			this->radio_1->Size = System::Drawing::Size(21, 20);
			this->radio_1->TabIndex = 9;
			this->radio_1->TabStop = true;
			this->radio_1->UseVisualStyleBackColor = true;
			// 
			// radio_2
			// 
			this->radio_2->AutoSize = true;
			this->radio_2->Location = System::Drawing::Point(6, 245);
			this->radio_2->Name = L"radio_2";
			this->radio_2->Size = System::Drawing::Size(21, 20);
			this->radio_2->TabIndex = 10;
			this->radio_2->UseVisualStyleBackColor = true;
			// 
			// radio_3
			// 
			this->radio_3->AutoSize = true;
			this->radio_3->Location = System::Drawing::Point(6, 399);
			this->radio_3->Name = L"radio_3";
			this->radio_3->Size = System::Drawing::Size(21, 20);
			this->radio_3->TabIndex = 11;
			this->radio_3->UseVisualStyleBackColor = true;
			// 
			// radio_4
			// 
			this->radio_4->AutoSize = true;
			this->radio_4->Location = System::Drawing::Point(6, 553);
			this->radio_4->Name = L"radio_4";
			this->radio_4->Size = System::Drawing::Size(21, 20);
			this->radio_4->TabIndex = 12;
			this->radio_4->UseVisualStyleBackColor = true;
			// 
			// groupBox5
			// 
			this->groupBox5->Controls->Add(this->radio_1);
			this->groupBox5->Controls->Add(this->radio_4);
			this->groupBox5->Controls->Add(this->radio_2);
			this->groupBox5->Controls->Add(this->radio_3);
			this->groupBox5->Location = System::Drawing::Point(657, 274);
			this->groupBox5->Name = L"groupBox5";
			this->groupBox5->Size = System::Drawing::Size(26, 650);
			this->groupBox5->TabIndex = 13;
			this->groupBox5->TabStop = false;
			// 
			// button_do_insertation_sort
			// 
			this->button_do_insertation_sort->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_do_insertation_sort->Location = System::Drawing::Point(6, 23);
			this->button_do_insertation_sort->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->button_do_insertation_sort->Name = L"button_do_insertation_sort";
			this->button_do_insertation_sort->Size = System::Drawing::Size(375, 44);
			this->button_do_insertation_sort->TabIndex = 14;
			this->button_do_insertation_sort->Text = L"СОРТИРОВКА ПРОСТЫМИ ВСТАВКАМИ";
			this->button_do_insertation_sort->UseVisualStyleBackColor = true;
			this->button_do_insertation_sort->Click += gcnew System::EventHandler(this, &Lab16::button_do_insertation_sort_click);
			// 
			// groupBox6
			// 
			this->groupBox6->AutoSize = true;
			this->groupBox6->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->groupBox6->Controls->Add(this->button_load_array);
			this->groupBox6->Controls->Add(this->button_save_array);
			this->groupBox6->Controls->Add(this->button_do_selection_sort);
			this->groupBox6->Controls->Add(this->button_do_binary_sort);
			this->groupBox6->Controls->Add(this->button_do_insertation_sort);
			this->groupBox6->Location = System::Drawing::Point(689, 274);
			this->groupBox6->Name = L"groupBox6";
			this->groupBox6->Size = System::Drawing::Size(387, 306);
			this->groupBox6->TabIndex = 15;
			this->groupBox6->TabStop = false;
			this->groupBox6->Text = L"Управление";
			// 
			// button_load_array
			// 
			this->button_load_array->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_load_array->Location = System::Drawing::Point(6, 231);
			this->button_load_array->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->button_load_array->Name = L"button_load_array";
			this->button_load_array->Size = System::Drawing::Size(375, 44);
			this->button_load_array->TabIndex = 18;
			this->button_load_array->Text = L"ЗАГРУЗИТЬ МАССИВ ИЗ ФАЙЛА";
			this->button_load_array->UseVisualStyleBackColor = true;
			this->button_load_array->Click += gcnew System::EventHandler(this, &Lab16::button_load_array_click);
			// 
			// button_save_array
			// 
			this->button_save_array->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_save_array->Location = System::Drawing::Point(6, 179);
			this->button_save_array->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->button_save_array->Name = L"button_save_array";
			this->button_save_array->Size = System::Drawing::Size(375, 44);
			this->button_save_array->TabIndex = 17;
			this->button_save_array->Text = L"СОХРАНИТЬ МАССИВ В ФАЙЛ";
			this->button_save_array->UseVisualStyleBackColor = true;
			this->button_save_array->Click += gcnew System::EventHandler(this, &Lab16::button_save_array_click);
			// 
			// button_do_selection_sort
			// 
			this->button_do_selection_sort->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_do_selection_sort->Location = System::Drawing::Point(6, 127);
			this->button_do_selection_sort->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->button_do_selection_sort->Name = L"button_do_selection_sort";
			this->button_do_selection_sort->Size = System::Drawing::Size(375, 44);
			this->button_do_selection_sort->TabIndex = 16;
			this->button_do_selection_sort->Text = L"СОРТИРОВКА ПРОСТЫМ ВЫБОРОМ";
			this->button_do_selection_sort->UseVisualStyleBackColor = true;
			this->button_do_selection_sort->Click += gcnew System::EventHandler(this, &Lab16::button_do_selection_sort_click);
			// 
			// button_do_binary_sort
			// 
			this->button_do_binary_sort->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_do_binary_sort->Location = System::Drawing::Point(6, 75);
			this->button_do_binary_sort->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->button_do_binary_sort->Name = L"button_do_binary_sort";
			this->button_do_binary_sort->Size = System::Drawing::Size(375, 44);
			this->button_do_binary_sort->TabIndex = 15;
			this->button_do_binary_sort->Text = L"СОРТИРОВКА БИНАРНЫМИ ВСТАВКАМИ";
			this->button_do_binary_sort->UseVisualStyleBackColor = true;
			this->button_do_binary_sort->Click += gcnew System::EventHandler(this, &Lab16::button_do_binary_sort_click);
			// 
			// label1
			// 
			this->label1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label1->Location = System::Drawing::Point(12, 142);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(1357, 77);
			this->label1->TabIndex = 22;
			this->label1->Text = L"Выберите нужный массив, установив рядом с ним\r\nсоответствующий флажок, а затем пр"
				L"имените\r\nнеобходимые действия";
			this->label1->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// Lab16
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(10, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1381, 1213);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->groupBox6);
			this->Controls->Add(this->groupBox5);
			this->Controls->Add(this->groupBox4);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->button_run);
			this->Controls->Add(this->button_home);
			this->Controls->Add(this->label_copyright);
			this->Controls->Add(this->header_title);
			this->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->Name = L"Lab16";
			this->ShowIcon = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Лабораторная №7";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &Lab16::button_exit_click);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->grid_first))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->grid_second))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->grid_third))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->grid_fourth))->EndInit();
			this->groupBox3->ResumeLayout(false);
			this->groupBox4->ResumeLayout(false);
			this->groupBox5->ResumeLayout(false);
			this->groupBox5->PerformLayout();
			this->groupBox6->ResumeLayout(false);
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

			String^ input = Interaction::InputBox("Введите количество элементов массива", "Ввод", "100", -1, -1);
			size_t number = Convert::ToInt16(input);
			int* arr1 = new int[number];
			int* arr2 = new int[number];

			UtilsLibrary3::Utils::fill_array_randomly(arr1, number, 0, 1000);
			UtilsLibrary3::Utils::fill_with_array(grid_first, arr1, number);
			size_t count = UtilsLibrary3::Utils::solve(arr1, number);
			MessageBox::Show("Количество пар соседних элементов, разница\nмежду которыми НЕ кратна 7: " +
				Convert::ToString(count), "Вывод", MessageBoxButtons::OK, MessageBoxIcon::Information);

			size_t new_length = 0;
			UtilsLibrary3::Utils::solve2(arr1, arr2, number, new_length, count);
			UtilsLibrary3::Utils::fill_with_array(grid_second, arr2, new_length);

			MessageBox::Show("Удаляем максимальный элемень в массиве", "Вывод", MessageBoxButtons::OK, MessageBoxIcon::Information);
			size_t max = UtilsLibrary3::Utils::find_max(arr2, new_length);
			UtilsLibrary3::Utils::remove_from_array(arr2, new_length, max);
			UtilsLibrary3::Utils::fill_with_array(grid_third, arr2, new_length);

			input = Interaction::InputBox(
				"Введите индекс элемента, в который хотите вставить значение", "Ввод", "0", -1, -1);
			int index = Convert::ToInt16(input);

			input = Interaction::InputBox(
				"Введите значение этого элемента", "Ввод", "10", -1, -1);
			int value = Convert::ToInt16(input);
			UtilsLibrary3::Utils::add_to_array(arr2, new_length, index, value);
			UtilsLibrary3::Utils::fill_with_array(grid_fourth, arr2, new_length);

			MessageBox::Show(
				UtilsLibrary3::Utils::is_monotone(arr2, new_length) ? "Функция монотонна" : "Функция не монотонна",
				"Вывод", MessageBoxButtons::OK, MessageBoxIcon::Information
			);

			int first_prime = UtilsLibrary3::Utils::find_first_prime(arr2, new_length);
			MessageBox::Show(
				first_prime > -1 ? "Первое простое число " + arr2[first_prime] : "Простых чисел нет",
				"Вывод", MessageBoxButtons::OK, MessageBoxIcon::Information
			);

			delete[] arr1;
			delete[] arr2;
			button_run->Enabled = true;
		}

		DataGridView^ get_selected_grid()
		{
			if (radio_1->Checked)
				return grid_first;

			if (radio_2->Checked)
				return grid_second;

			if (radio_3->Checked)
				return grid_third;

			if (radio_4->Checked)
				return grid_fourth;
		}

		System::Void button_do_insertation_sort_click(System::Object^ sender, System::EventArgs^ e)
		{
			DataGridView^ view = get_selected_grid();
			size_t size = 0;
			int* array = UtilsLibrary3::Utils::create_array_form_dgv(view, size);
			UtilsLibrary3::Utils::insertation_sort(array, size);
			UtilsLibrary3::Utils::fill_with_array(view, array, size);
			delete[] array;
		}
		
		System::Void button_do_binary_sort_click(System::Object^ sender, System::EventArgs^ e)
		{
			DataGridView^ view = get_selected_grid();
			size_t size = 0;
			int* array = UtilsLibrary3::Utils::create_array_form_dgv(get_selected_grid(), size);
			UtilsLibrary3::Utils::binary_sort(array, size);
			UtilsLibrary3::Utils::fill_with_array(view, array, size);
			delete[] array;
		}
		
		System::Void button_do_selection_sort_click(System::Object^ sender, System::EventArgs^ e)
		{
			DataGridView^ view = get_selected_grid();
			size_t size = 0;
			int* array = UtilsLibrary3::Utils::create_array_form_dgv(get_selected_grid(), size);
			UtilsLibrary3::Utils::selection_sort(array, size);
			UtilsLibrary3::Utils::fill_with_array(view, array, size);
			delete[] array;
		}

		System::Void button_save_array_click(System::Object^ sender, System::EventArgs^ e)
		{
			UtilsLibrary3::Utils::save_array(get_selected_grid());
		}
		
		System::Void button_load_array_click(System::Object^ sender, System::EventArgs^ e)
		{
			UtilsLibrary3::Utils::load_array(get_selected_grid());
		}
	};
}

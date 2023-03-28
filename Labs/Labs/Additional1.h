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
	public ref class Additional1 : public System::Windows::Forms::Form
	{
	private:
		Form^ parent = nullptr;
	public:
		Additional1(Form^ parent)
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
		~Additional1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ header_title;
	private: System::Windows::Forms::Button^ button_home;
	private: System::Windows::Forms::Label^ label_copyright;


	private: System::Windows::Forms::Button^ button_run;
	private: System::Windows::Forms::ListView^ list;
	private: System::Windows::Forms::ColumnHeader^ columnIterationNumber;
	private: System::Windows::Forms::ColumnHeader^ columnValue;

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
			this->button_run = (gcnew System::Windows::Forms::Button());
			this->list = (gcnew System::Windows::Forms::ListView());
			this->columnIterationNumber = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnValue = (gcnew System::Windows::Forms::ColumnHeader());
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
			this->header_title->Text = L"Контрольное задание на тему\r\n«Программирование алгоритмов итеративных циклических"
				L" структур»\r\n";
			this->header_title->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// button_home
			// 
			this->button_home->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->button_home->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_home->Location = System::Drawing::Point(1202, 926);
			this->button_home->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->button_home->Name = L"button_home";
			this->button_home->Size = System::Drawing::Size(167, 44);
			this->button_home->TabIndex = 8;
			this->button_home->Text = L"На главную";
			this->button_home->UseVisualStyleBackColor = true;
			this->button_home->Click += gcnew System::EventHandler(this, &Additional1::button_home_click);
			// 
			// label_copyright
			// 
			this->label_copyright->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->label_copyright->AutoSize = true;
			this->label_copyright->Enabled = false;
			this->label_copyright->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_copyright->Location = System::Drawing::Point(12, 838);
			this->label_copyright->Name = L"label_copyright";
			this->label_copyright->Size = System::Drawing::Size(605, 132);
			this->label_copyright->TabIndex = 7;
			this->label_copyright->Text = L"Выполнил: студент группы БСТ2001 Савкин Д.И.\r\nВариант № 24\r\nПроверил: доцент кафе"
				L"дры «Информатика»\r\nГуриков С.Р.\r\n";
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
			this->button_run->Click += gcnew System::EventHandler(this, &Additional1::button_run_click);
			// 
			// list
			// 
			this->list->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(2) {
				this->columnIterationNumber,
					this->columnValue
			});
			this->list->HideSelection = false;
			this->list->Location = System::Drawing::Point(16, 197);
			this->list->Name = L"list";
			this->list->Size = System::Drawing::Size(307, 360);
			this->list->TabIndex = 16;
			this->list->UseCompatibleStateImageBehavior = false;
			this->list->View = System::Windows::Forms::View::Details;
			// 
			// columnIterationNumber
			// 
			this->columnIterationNumber->Text = L"Номер итерации";
			this->columnIterationNumber->Width = 159;
			// 
			// columnValue
			// 
			this->columnValue->Text = L"Значение функции";
			this->columnValue->Width = 124;
			// 
			// Additional1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(10, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1381, 983);
			this->Controls->Add(this->list);
			this->Controls->Add(this->button_run);
			this->Controls->Add(this->button_home);
			this->Controls->Add(this->label_copyright);
			this->Controls->Add(this->header_title);
			this->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->Name = L"Additional1";
			this->ShowIcon = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Лабораторная №9";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &Additional1::button_exit_click);
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
			double x = Convert::ToDouble(
				Interaction::InputBox("Введите значие X", "Ввод", "5", -1, -1)
			);
			double accuracy = Convert::ToDouble(
				Interaction::InputBox("Введите точность вычислений", "Ввод", "5", -1, -1)
			);
			size_t last_summad;
			UtilsLibrary4::Utils::solve3(x, accuracy, last_summad, list);
			MessageBox::Show("Номер последнего слагаемого: " +
				Convert::ToString(last_summad), "Вывод", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
	};
}

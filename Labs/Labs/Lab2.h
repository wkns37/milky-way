#pragma once
#include <math.h>
#include <assert.h>

namespace Labs {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace UtilsLibrary;

	/// <summary>
	/// Summary for Lab2
	/// </summary>
	public ref class Lab2 : public System::Windows::Forms::Form
	{
	private:
		Form^ parent = nullptr;
	public:
		Lab2(Form^ parent)
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
		~Lab2()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ header_title;
	private: System::Windows::Forms::Label^ label_copyright;
	private: System::Windows::Forms::Button^ button_home;
	private: System::Windows::Forms::TextBox^ field_y;

	private: System::Windows::Forms::TextBox^ field_result;
	private: System::Windows::Forms::Button^ button_calc;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ field_x;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Lab2::typeid));
			this->header_title = (gcnew System::Windows::Forms::Label());
			this->label_copyright = (gcnew System::Windows::Forms::Label());
			this->button_home = (gcnew System::Windows::Forms::Button());
			this->field_y = (gcnew System::Windows::Forms::TextBox());
			this->field_result = (gcnew System::Windows::Forms::TextBox());
			this->button_calc = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->field_x = (gcnew System::Windows::Forms::TextBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
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
			this->header_title->Size = System::Drawing::Size(1154, 179);
			this->header_title->TabIndex = 1;
			this->header_title->Text = L"Лабораторная работа №2\r\n«Запись арифметических выражений\r\nна языке программирован"
				L"ия\r\nVisual C++ на основе\r\nпользовательских функций и создании DLL библиотеки»";
			this->header_title->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// label_copyright
			// 
			this->label_copyright->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->label_copyright->AutoSize = true;
			this->label_copyright->Enabled = false;
			this->label_copyright->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_copyright->Location = System::Drawing::Point(12, 653);
			this->label_copyright->Name = L"label_copyright";
			this->label_copyright->Size = System::Drawing::Size(605, 132);
			this->label_copyright->TabIndex = 10;
			this->label_copyright->Text = L"Выполнил: студент группы БСТ2001 Савкин Д.И.\r\nВариант № 26\r\nПроверил: доцент кафе"
				L"дры «Информатика»\r\nГуриков С.Р.\r\n";
			// 
			// button_home
			// 
			this->button_home->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->button_home->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_home->Location = System::Drawing::Point(1016, 747);
			this->button_home->Name = L"button_home";
			this->button_home->Size = System::Drawing::Size(150, 35);
			this->button_home->TabIndex = 11;
			this->button_home->Text = L"На главную";
			this->button_home->UseVisualStyleBackColor = true;
			this->button_home->Click += gcnew System::EventHandler(this, &Lab2::button_home_click);
			// 
			// field_y
			// 
			this->field_y->Location = System::Drawing::Point(36, 57);
			this->field_y->Name = L"field_y";
			this->field_y->Size = System::Drawing::Size(100, 26);
			this->field_y->TabIndex = 6;
			// 
			// field_result
			// 
			this->field_result->Location = System::Drawing::Point(6, 25);
			this->field_result->Name = L"field_result";
			this->field_result->Size = System::Drawing::Size(200, 26);
			this->field_result->TabIndex = 8;
			// 
			// button_calc
			// 
			this->button_calc->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_calc->Location = System::Drawing::Point(6, 57);
			this->button_calc->Name = L"button_calc";
			this->button_calc->Size = System::Drawing::Size(200, 35);
			this->button_calc->TabIndex = 9;
			this->button_calc->Text = L"РАСЧЕТ";
			this->button_calc->UseVisualStyleBackColor = true;
			this->button_calc->Click += gcnew System::EventHandler(this, &Lab2::button_calc_click);
			// 
			// groupBox1
			// 
			this->groupBox1->AutoSize = true;
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->field_y);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->field_x);
			this->groupBox1->Location = System::Drawing::Point(12, 191);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(142, 108);
			this->groupBox1->TabIndex = 2;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Ввод данных";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(6, 56);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(25, 25);
			this->label2->TabIndex = 5;
			this->label2->Text = L"y:";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(6, 24);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(24, 25);
			this->label1->TabIndex = 3;
			this->label1->Text = L"x:";
			// 
			// field_x
			// 
			this->field_x->Location = System::Drawing::Point(36, 25);
			this->field_x->Name = L"field_x";
			this->field_x->Size = System::Drawing::Size(100, 26);
			this->field_x->TabIndex = 4;
			// 
			// groupBox2
			// 
			this->groupBox2->AutoSize = true;
			this->groupBox2->Controls->Add(this->field_result);
			this->groupBox2->Controls->Add(this->button_calc);
			this->groupBox2->Location = System::Drawing::Point(12, 305);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(212, 117);
			this->groupBox2->TabIndex = 7;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Вывод данных";
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(12, 428);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(425, 115);
			this->pictureBox1->TabIndex = 12;
			this->pictureBox1->TabStop = false;
			// 
			// Lab2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1178, 794);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->button_home);
			this->Controls->Add(this->label_copyright);
			this->Controls->Add(this->header_title);
			this->Name = L"Lab2";
			this->ShowIcon = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Лабораторная №2";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &Lab2::button_exit_click);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion

	private:

		double func1(double x, double y)
		{
			return (1 - tan(x * pow(y, 2))) / (cbrt(x)) + 4 * sqrt(pow(x, 2) - 0.1);
		}

		void func2(double x, double y, double& result)
		{
			result = (1 - tan(x * pow(y, 2))) / (cbrt(x)) + 4 * sqrt(pow(x, 2) - 0.1);
		}

		System::Void button_exit_click(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e)
		{
			Application::Exit();
		}

		System::Void button_home_click(System::Object^ sender, System::EventArgs^ e)
		{
			parent->Show();
			this->Hide();
		}

		System::Void button_calc_click(System::Object^ sender, System::EventArgs^ e)
		{
			double result1 = 0, result2 = 0;
			double x = Utils::getDoubleFromTextBox(field_x);
			double y = Utils::getDoubleFromTextBox(field_y);

			result1 = func1(x, y);		// Получение результата первым способом
			func2(x, y, result2);		// Получение результата вторым способом
			assert(result1 == result2);	// Проверяем эквивалентность

			Utils::setDataToTextBox(field_result, result1);
		}
	};
}

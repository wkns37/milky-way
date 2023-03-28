#pragma once
#include "Lab1.h"
#include "Lab2.h"
#include "Lab3.h"
#include "Lab4.h"
#include "Lab5.h"
#include "Lab6.h"
#include "Lab7.h"
#include "Lab8.h"
#include "Lab9.h"
#include "Lab10.h"
#include "Lab15.h"
#include "Lab16.h"
#include "Lab17.h"
#include "Lab18.h"
#include "Lab21.h"
#include "Additional1.h"

namespace Labs {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class App : public System::Windows::Forms::Form
	{
	private: System::Windows::Forms::Label^ header_title;
	private: System::Windows::Forms::Button^ button_lab2;
	private: System::Windows::Forms::Button^ button_lab1;
	private: System::Windows::Forms::Label^ label_copyright;
	private: System::Windows::Forms::Button^ button_lab3;
	private: System::Windows::Forms::Button^ button_lab4;
	private: System::Windows::Forms::Button^ button_lab5;
	private: System::Windows::Forms::Button^ button_lab6;
	private: System::Windows::Forms::Button^ button_lab7;
	private: System::Windows::Forms::Button^ button_lab8;
	private: System::Windows::Forms::Button^ button_lab9;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::Button^ button_lab10;
	private: System::Windows::Forms::Button^ button_lab15;
	private: System::Windows::Forms::Button^ button_lab16;
	private: System::Windows::Forms::Button^ button_lab17;
	private: System::Windows::Forms::Button^ button_lab18;
	private: System::Windows::Forms::Button^ button_additional1;
	private: System::Windows::Forms::Button^ button_lab21;







	private:
		System::ComponentModel::Container^ components;

	public:
		App(void)
		{
			InitializeComponent();
		}

	protected:
		~App()
		{
			if (components)
			{
				delete components;
			}
		}

#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(App::typeid));
			this->header_title = (gcnew System::Windows::Forms::Label());
			this->button_lab2 = (gcnew System::Windows::Forms::Button());
			this->button_lab1 = (gcnew System::Windows::Forms::Button());
			this->label_copyright = (gcnew System::Windows::Forms::Label());
			this->button_lab3 = (gcnew System::Windows::Forms::Button());
			this->button_lab4 = (gcnew System::Windows::Forms::Button());
			this->button_lab5 = (gcnew System::Windows::Forms::Button());
			this->button_lab6 = (gcnew System::Windows::Forms::Button());
			this->button_lab7 = (gcnew System::Windows::Forms::Button());
			this->button_lab8 = (gcnew System::Windows::Forms::Button());
			this->button_lab9 = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->button_additional1 = (gcnew System::Windows::Forms::Button());
			this->button_lab18 = (gcnew System::Windows::Forms::Button());
			this->button_lab17 = (gcnew System::Windows::Forms::Button());
			this->button_lab16 = (gcnew System::Windows::Forms::Button());
			this->button_lab15 = (gcnew System::Windows::Forms::Button());
			this->button_lab10 = (gcnew System::Windows::Forms::Button());
			this->button_lab21 = (gcnew System::Windows::Forms::Button());
			this->button_additional1 = (gcnew System::Windows::Forms::Button());
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
			this->header_title->Location = System::Drawing::Point(8, 6);
			this->header_title->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->header_title->Name = L"header_title";
			this->header_title->Size = System::Drawing::Size(836, 239);
			this->header_title->TabIndex = 0;
			this->header_title->Text = resources->GetString(L"header_title.Text");
			this->header_title->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// button_lab2
			// 
			this->button_lab2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_lab2->Location = System::Drawing::Point(4, 43);
			this->button_lab2->Margin = System::Windows::Forms::Padding(2);
			this->button_lab2->Name = L"button_lab2";
			this->button_lab2->Size = System::Drawing::Size(267, 23);
			this->button_lab2->TabIndex = 2;
			this->button_lab2->Text = L"Лабораторная №2";
			this->button_lab2->UseVisualStyleBackColor = true;
			this->button_lab2->Click += gcnew System::EventHandler(this, &App::button_lab2_click);
			// 
			// button_lab1
			// 
			this->button_lab1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_lab1->Location = System::Drawing::Point(4, 16);
			this->button_lab1->Margin = System::Windows::Forms::Padding(2);
			this->button_lab1->Name = L"button_lab1";
			this->button_lab1->Size = System::Drawing::Size(267, 23);
			this->button_lab1->TabIndex = 1;
			this->button_lab1->Text = L"Лабораторная №1";
			this->button_lab1->UseVisualStyleBackColor = true;
			this->button_lab1->Click += gcnew System::EventHandler(this, &App::button_lab1_click);
			// 
			// label_copyright
			// 
			this->label_copyright->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->label_copyright->AutoSize = true;
			this->label_copyright->Enabled = false;
			this->label_copyright->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_copyright->Location = System::Drawing::Point(8, 585);
			this->label_copyright->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label_copyright->Name = L"label_copyright";
			this->label_copyright->Size = System::Drawing::Size(410, 63);
			this->label_copyright->TabIndex = 13;
			this->label_copyright->Text = L"Выполнил: студент группы БСТ2001 Савкин Д.И.\r\nПроверил: доцент кафедры «Информати"
				L"ка»\r\nГуриков С.Р.";
			// 
			// button_lab3
			// 
			this->button_lab3->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_lab3->Location = System::Drawing::Point(4, 70);
			this->button_lab3->Margin = System::Windows::Forms::Padding(2);
			this->button_lab3->Name = L"button_lab3";
			this->button_lab3->Size = System::Drawing::Size(267, 23);
			this->button_lab3->TabIndex = 3;
			this->button_lab3->Text = L"Лабораторная №3";
			this->button_lab3->UseVisualStyleBackColor = true;
			this->button_lab3->Click += gcnew System::EventHandler(this, &App::button_lab3_click);
			// 
			// button_lab4
			// 
			this->button_lab4->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_lab4->Location = System::Drawing::Point(4, 96);
			this->button_lab4->Margin = System::Windows::Forms::Padding(2);
			this->button_lab4->Name = L"button_lab4";
			this->button_lab4->Size = System::Drawing::Size(267, 23);
			this->button_lab4->TabIndex = 4;
			this->button_lab4->Text = L"Лабораторная №4";
			this->button_lab4->UseVisualStyleBackColor = true;
			this->button_lab4->Click += gcnew System::EventHandler(this, &App::button_lab4_click);
			// 
			// button_lab5
			// 
			this->button_lab5->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_lab5->Location = System::Drawing::Point(275, 16);
			this->button_lab5->Margin = System::Windows::Forms::Padding(2);
			this->button_lab5->Name = L"button_lab5";
			this->button_lab5->Size = System::Drawing::Size(267, 23);
			this->button_lab5->TabIndex = 5;
			this->button_lab5->Text = L"Лабораторная №5";
			this->button_lab5->UseVisualStyleBackColor = true;
			this->button_lab5->Click += gcnew System::EventHandler(this, &App::button_lab5_click);
			// 
			// button_lab6
			// 
			this->button_lab6->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_lab6->Location = System::Drawing::Point(275, 43);
			this->button_lab6->Margin = System::Windows::Forms::Padding(2);
			this->button_lab6->Name = L"button_lab6";
			this->button_lab6->Size = System::Drawing::Size(267, 23);
			this->button_lab6->TabIndex = 6;
			this->button_lab6->Text = L"Лабораторная №6";
			this->button_lab6->UseVisualStyleBackColor = true;
			this->button_lab6->Click += gcnew System::EventHandler(this, &App::button_lab6_click);
			// 
			// button_lab7
			// 
			this->button_lab7->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_lab7->Location = System::Drawing::Point(275, 70);
			this->button_lab7->Margin = System::Windows::Forms::Padding(2);
			this->button_lab7->Name = L"button_lab7";
			this->button_lab7->Size = System::Drawing::Size(267, 23);
			this->button_lab7->TabIndex = 7;
			this->button_lab7->Text = L"Лабораторная №7";
			this->button_lab7->UseVisualStyleBackColor = true;
			this->button_lab7->Click += gcnew System::EventHandler(this, &App::button_lab7_click);
			// 
			// button_lab8
			// 
			this->button_lab8->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_lab8->Location = System::Drawing::Point(275, 96);
			this->button_lab8->Margin = System::Windows::Forms::Padding(2);
			this->button_lab8->Name = L"button_lab8";
			this->button_lab8->Size = System::Drawing::Size(267, 23);
			this->button_lab8->TabIndex = 8;
			this->button_lab8->Text = L"Лабораторная №8";
			this->button_lab8->UseVisualStyleBackColor = true;
			this->button_lab8->Click += gcnew System::EventHandler(this, &App::button_lab8_click);
			// 
			// button_lab9
			// 
			this->button_lab9->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_lab9->Location = System::Drawing::Point(545, 16);
			this->button_lab9->Margin = System::Windows::Forms::Padding(2);
			this->button_lab9->Name = L"button_lab9";
			this->button_lab9->Size = System::Drawing::Size(267, 23);
			this->button_lab9->TabIndex = 9;
			this->button_lab9->Text = L"Лабораторная №9";
			this->button_lab9->UseVisualStyleBackColor = true;
			this->button_lab9->Click += gcnew System::EventHandler(this, &App::button_lab9_click);
			// 
			// groupBox1
			// 
			this->groupBox1->AutoSize = true;
			this->groupBox1->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->groupBox1->Controls->Add(this->button_lab1);
			this->groupBox1->Controls->Add(this->button_lab9);
			this->groupBox1->Controls->Add(this->button_lab2);
			this->groupBox1->Controls->Add(this->button_lab8);
			this->groupBox1->Controls->Add(this->button_lab3);
			this->groupBox1->Controls->Add(this->button_lab7);
			this->groupBox1->Controls->Add(this->button_lab4);
			this->groupBox1->Controls->Add(this->button_lab6);
			this->groupBox1->Controls->Add(this->button_lab5);
			this->groupBox1->Location = System::Drawing::Point(8, 247);
			this->groupBox1->Margin = System::Windows::Forms::Padding(2);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Padding = System::Windows::Forms::Padding(2);
			this->groupBox1->Size = System::Drawing::Size(816, 136);
			this->groupBox1->TabIndex = 10;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Основы программирования";
			// 
			// groupBox2
			// 
			this->groupBox2->AutoSize = true;
			this->groupBox2->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->groupBox2->Controls->Add(this->button_lab21);
			this->groupBox2->Controls->Add(this->button_additional1);
			this->groupBox2->Controls->Add(this->button_lab18);
			this->groupBox2->Controls->Add(this->button_lab17);
			this->groupBox2->Controls->Add(this->button_lab16);
			this->groupBox2->Controls->Add(this->button_lab15);
			this->groupBox2->Controls->Add(this->button_lab10);
			this->groupBox2->Location = System::Drawing::Point(8, 386);
			this->groupBox2->Margin = System::Windows::Forms::Padding(2);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Padding = System::Windows::Forms::Padding(2);
			this->groupBox2->Size = System::Drawing::Size(546, 137);
			this->groupBox2->TabIndex = 12;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Информатика";
			// 
			// button_lab18
			// 
			this->button_lab18->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			// button_additional1
			// 
			this->button_additional1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_additional1->Location = System::Drawing::Point(275, 70);
			this->button_additional1->Margin = System::Windows::Forms::Padding(2);
			this->button_additional1->Name = L"button_additional1";
			this->button_additional1->Size = System::Drawing::Size(267, 23);
			this->button_additional1->TabIndex = 16;
			this->button_additional1->Text = L"Дополнительное задание №1";
			this->button_additional1->UseVisualStyleBackColor = true;
			this->button_additional1->Click += gcnew System::EventHandler(this, &App::button_additional1_click);
			// 
			// button_lab18
			// 
			this->button_lab18->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_lab18->Location = System::Drawing::Point(275, 17);
			this->button_lab18->Margin = System::Windows::Forms::Padding(2);
			this->button_lab18->Name = L"button_lab18";
			this->button_lab18->Size = System::Drawing::Size(267, 23);
			this->button_lab18->TabIndex = 15;
			this->button_lab18->Text = L"Лабораторная №9";
			this->button_lab18->UseVisualStyleBackColor = true;
			this->button_lab18->Click += gcnew System::EventHandler(this, &App::button_lab18_click);
			// 
			// button_lab17
			// 
			this->button_lab17->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_lab17->Location = System::Drawing::Point(4, 97);
			this->button_lab17->Margin = System::Windows::Forms::Padding(2);
			this->button_lab17->Name = L"button_lab17";
			this->button_lab17->Size = System::Drawing::Size(267, 23);
			this->button_lab17->TabIndex = 14;
			this->button_lab17->Text = L"Лабораторная №8";
			this->button_lab17->UseVisualStyleBackColor = true;
			this->button_lab17->Click += gcnew System::EventHandler(this, &App::button_lab17_click);
			// 
			// button_lab16
			// 
			this->button_lab16->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_lab16->Location = System::Drawing::Point(4, 70);
			this->button_lab16->Margin = System::Windows::Forms::Padding(2);
			this->button_lab16->Name = L"button_lab16";
			this->button_lab16->Size = System::Drawing::Size(267, 23);
			this->button_lab16->TabIndex = 13;
			this->button_lab16->Text = L"Лабораторная №7";
			this->button_lab16->UseVisualStyleBackColor = true;
			this->button_lab16->Click += gcnew System::EventHandler(this, &App::button_lab16_click);
			// 
			// button_lab15
			// 
			this->button_lab15->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_lab15->Location = System::Drawing::Point(4, 43);
			this->button_lab15->Margin = System::Windows::Forms::Padding(2);
			this->button_lab15->Name = L"button_lab15";
			this->button_lab15->Size = System::Drawing::Size(267, 23);
			this->button_lab15->TabIndex = 12;
			this->button_lab15->Text = L"Лабораторная №6";
			this->button_lab15->UseVisualStyleBackColor = true;
			this->button_lab15->Click += gcnew System::EventHandler(this, &App::button_lab15_click);
			// 
			// button_lab10
			// 
			this->button_lab10->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_lab10->Location = System::Drawing::Point(4, 16);
			this->button_lab10->Margin = System::Windows::Forms::Padding(2);
			this->button_lab10->Name = L"button_lab10";
			this->button_lab10->Size = System::Drawing::Size(267, 23);
			this->button_lab10->TabIndex = 11;
			this->button_lab10->Text = L"Лабораторная №1";
			this->button_lab10->UseVisualStyleBackColor = true;
			this->button_lab10->Click += gcnew System::EventHandler(this, &App::button_lab10_click);
			// 
			// button_additional1
			// 
			this->button_additional1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_additional1->Location = System::Drawing::Point(275, 43);
			this->button_additional1->Margin = System::Windows::Forms::Padding(2);
			this->button_additional1->Name = L"button_additional1";
			this->button_additional1->Size = System::Drawing::Size(267, 23);
			this->button_additional1->TabIndex = 16;
			this->button_additional1->Text = L"Дополнительное задание №1";
			this->button_additional1->UseVisualStyleBackColor = true;
			this->button_additional1->Click += gcnew System::EventHandler(this, &App::button_additional1_click);
			// button_lab21
			// 
			this->button_lab21->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_lab21->Location = System::Drawing::Point(275, 43);
			this->button_lab21->Margin = System::Windows::Forms::Padding(2);
			this->button_lab21->Name = L"button_lab21";
			this->button_lab21->Size = System::Drawing::Size(267, 23);
			this->button_lab21->TabIndex = 17;
			this->button_lab21->Text = L"Лабораторная №12";
			this->button_lab21->UseVisualStyleBackColor = true;
			this->button_lab21->Click += gcnew System::EventHandler(this, &App::button_lab21_click);
			// 
			// App
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(852, 655);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->label_copyright);
			this->Controls->Add(this->header_title);
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"App";
			this->ShowIcon = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Главное меню";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->groupBox1->ResumeLayout(false);
			this->groupBox2->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion

	private:
		System::Void button_lab1_click(System::Object^ sender, System::EventArgs^ e)
		{
			Lab1^ window = gcnew Lab1(this);
			this->Hide();
			window->Show();
		}

		System::Void button_lab2_click(System::Object^ sender, System::EventArgs^ e)
		{
			Lab2^ window = gcnew Lab2(this);
			this->Hide();
			window->Show();
		}

		System::Void button_lab3_click(System::Object^ sender, System::EventArgs^ e)
		{
			Lab3^ window = gcnew Lab3(this);
			this->Hide();
			window->Show();
		}

		System::Void button_lab4_click(System::Object^ sender, System::EventArgs^ e)
		{
			Lab4^ window = gcnew Lab4(this);
			this->Hide();
			window->Show();
		}

		System::Void button_lab5_click(System::Object^ sender, System::EventArgs^ e)
		{
			Lab5^ window = gcnew Lab5(this);
			this->Hide();
			window->Show();
		}

		System::Void button_lab6_click(System::Object^ sender, System::EventArgs^ e)
		{
			Lab6^ window = gcnew Lab6(this);
			this->Hide();
			window->Show();
		}

		System::Void button_lab7_click(System::Object^ sender, System::EventArgs^ e)
		{
			Lab7^ window = gcnew Lab7(this);
			this->Hide();
			window->Show();
		}

		System::Void button_lab8_click(System::Object^ sender, System::EventArgs^ e)
		{
			Lab8^ window = gcnew Lab8(this);
			this->Hide();
			window->Show();
		}

		System::Void button_lab9_click(System::Object^ sender, System::EventArgs^ e)
		{
			Lab9^ window = gcnew Lab9(this);
			this->Hide();
			window->Show();
		}

		System::Void button_lab10_click(System::Object^ sender, System::EventArgs^ e)
		{
			Lab10^ window = gcnew Lab10(this);
			this->Hide();
			window->Show();
		}

		System::Void button_lab15_click(System::Object^ sender, System::EventArgs^ e)
		{
			Lab15^ window = gcnew Lab15(this);
			this->Hide();
			window->Show();
		}

		System::Void button_lab16_click(System::Object^ sender, System::EventArgs^ e)
		{
			Lab16^ window = gcnew Lab16(this);
			this->Hide();
			window->Show();
		}

		System::Void button_lab17_click(System::Object^ sender, System::EventArgs^ e)
		{
			Lab17^ window = gcnew Lab17(this);
			this->Hide();
			window->Show();
		}

		System::Void button_lab18_click(System::Object^ sender, System::EventArgs^ e)
		{
			Lab18^ window = gcnew Lab18(this);
			this->Hide();
			window->Show();
		}

		System::Void button_lab21_click(System::Object^ sender, System::EventArgs^ e)
		{
			Lab21^ window = gcnew Lab21(this);
			this->Hide();
			window->Show();
		}

		System::Void button_additional1_click(System::Object^ sender, System::EventArgs^ e)
		{
			Additional1^ window = gcnew Additional1(this);
			this->Hide();
			window->Show();
		}
	};
}

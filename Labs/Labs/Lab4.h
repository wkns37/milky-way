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
	using namespace UtilsLibrary;

	/// <summary>
	/// Summary for Lab1
	/// </summary>
	public ref class Lab4 : public System::Windows::Forms::Form
	{
	private:
		Form^ parent = nullptr;
	public:
		Lab4(Form^ parent)
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
		~Lab4()
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


	private: System::Windows::Forms::Button^ button_calc;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ field_x;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ field_a;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ field_branch;

	private: System::Windows::Forms::TextBox^ field_z;

	private: System::Windows::Forms::Label^ label5;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Lab4::typeid));
			this->header_title = (gcnew System::Windows::Forms::Label());
			this->label_copyright = (gcnew System::Windows::Forms::Label());
			this->button_home = (gcnew System::Windows::Forms::Button());
			this->field_y = (gcnew System::Windows::Forms::TextBox());
			this->button_calc = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->field_a = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->field_x = (gcnew System::Windows::Forms::TextBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->field_branch = (gcnew System::Windows::Forms::TextBox());
			this->field_z = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
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
			this->header_title->Size = System::Drawing::Size(1412, 112);
			this->header_title->TabIndex = 1;
			this->header_title->Text = L"Лабораторная работа №4\r\n«Программирование алгоритмов разветвляющих структур.\r\nНах"
				L"ождение максимального и минимального значений»";
			this->header_title->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// label_copyright
			// 
			this->label_copyright->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->label_copyright->AutoSize = true;
			this->label_copyright->Enabled = false;
			this->label_copyright->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_copyright->Location = System::Drawing::Point(12, 809);
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
			this->button_home->Location = System::Drawing::Point(1274, 905);
			this->button_home->Name = L"button_home";
			this->button_home->Size = System::Drawing::Size(150, 35);
			this->button_home->TabIndex = 11;
			this->button_home->Text = L"На главную";
			this->button_home->UseVisualStyleBackColor = true;
			this->button_home->Click += gcnew System::EventHandler(this, &Lab4::button_home_click);
			// 
			// field_y
			// 
			this->field_y->Location = System::Drawing::Point(36, 58);
			this->field_y->Name = L"field_y";
			this->field_y->Size = System::Drawing::Size(100, 26);
			this->field_y->TabIndex = 6;
			// 
			// button_calc
			// 
			this->button_calc->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_calc->Location = System::Drawing::Point(6, 95);
			this->button_calc->Name = L"button_calc";
			this->button_calc->Size = System::Drawing::Size(182, 35);
			this->button_calc->TabIndex = 9;
			this->button_calc->Text = L"РАСЧЕТ";
			this->button_calc->UseVisualStyleBackColor = true;
			this->button_calc->Click += gcnew System::EventHandler(this, &Lab4::button_calc_click);
			// 
			// groupBox1
			// 
			this->groupBox1->AutoSize = true;
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->field_a);
			this->groupBox1->Controls->Add(this->field_y);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->field_x);
			this->groupBox1->Location = System::Drawing::Point(12, 191);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(144, 148);
			this->groupBox1->TabIndex = 2;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Ввод данных";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(8, 94);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(25, 25);
			this->label3->TabIndex = 12;
			this->label3->Text = L"а:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(8, 62);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(25, 25);
			this->label2->TabIndex = 5;
			this->label2->Text = L"y:";
			// 
			// field_a
			// 
			this->field_a->Location = System::Drawing::Point(36, 91);
			this->field_a->Name = L"field_a";
			this->field_a->Size = System::Drawing::Size(100, 26);
			this->field_a->TabIndex = 13;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(8, 29);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(24, 25);
			this->label1->TabIndex = 3;
			this->label1->Text = L"x:";
			// 
			// field_x
			// 
			this->field_x->Location = System::Drawing::Point(36, 26);
			this->field_x->Name = L"field_x";
			this->field_x->Size = System::Drawing::Size(100, 26);
			this->field_x->TabIndex = 4;
			// 
			// groupBox2
			// 
			this->groupBox2->AutoSize = true;
			this->groupBox2->Controls->Add(this->label4);
			this->groupBox2->Controls->Add(this->button_calc);
			this->groupBox2->Controls->Add(this->field_branch);
			this->groupBox2->Controls->Add(this->field_z);
			this->groupBox2->Controls->Add(this->label5);
			this->groupBox2->Location = System::Drawing::Point(12, 337);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(194, 157);
			this->groupBox2->TabIndex = 7;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Вывод данных";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(9, 62);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(70, 25);
			this->label4->TabIndex = 15;
			this->label4->Text = L"branch:";
			// 
			// field_branch
			// 
			this->field_branch->Location = System::Drawing::Point(86, 58);
			this->field_branch->Name = L"field_branch";
			this->field_branch->ReadOnly = true;
			this->field_branch->Size = System::Drawing::Size(100, 26);
			this->field_branch->TabIndex = 16;
			// 
			// field_z
			// 
			this->field_z->Location = System::Drawing::Point(86, 26);
			this->field_z->Name = L"field_z";
			this->field_z->ReadOnly = true;
			this->field_z->Size = System::Drawing::Size(100, 26);
			this->field_z->TabIndex = 14;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(9, 29);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(24, 25);
			this->label5->TabIndex = 13;
			this->label5->Text = L"z:";
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(12, 500);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(453, 122);
			this->pictureBox1->TabIndex = 12;
			this->pictureBox1->TabStop = false;
			// 
			// Lab4
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1436, 951);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->button_home);
			this->Controls->Add(this->label_copyright);
			this->Controls->Add(this->header_title);
			this->Name = L"Lab4";
			this->ShowIcon = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Лабораторная №4";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &Lab4::button_exit_click);
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
			double x = Utils::getDoubleFromTextBox(field_x);
			double y = Utils::getDoubleFromTextBox(field_y);
			double a = Utils::getDoubleFromTextBox(field_a);
			double z = 0;		// result
			double branch = 0;	// branch

			Utils::solve1(x, y, a, z, branch);

			Utils::setDataToTextBox(field_z, z);
			Utils::setDataToTextBox(field_branch, branch);
		}
	};
}

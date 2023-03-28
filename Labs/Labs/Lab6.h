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
	using namespace UtilsLibrary;

	/// <summary>
	/// Summary for Lab1
	/// </summary>
	public ref class Lab6 : public System::Windows::Forms::Form
	{
	private:
		Form^ parent = nullptr;
	public:
		Lab6(Form^ parent)
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
		~Lab6()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ header_title;
	private: System::Windows::Forms::Label^ label_copyright;
	private: System::Windows::Forms::Button^ button_home;
	private: System::Windows::Forms::TextBox^ field_xk;




	private: System::Windows::Forms::Button^ button_calc;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::Label^ textBox2;


	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ field_a;

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ field_xn;





	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ field_sum;

	private: System::Windows::Forms::ListBox^ result_container;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ field_dx;

	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ field_cnt;

	private: System::Windows::Forms::TextBox^ field_mlt;
	private: System::Windows::Forms::Label^ label7;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Lab6::typeid));
			this->header_title = (gcnew System::Windows::Forms::Label());
			this->label_copyright = (gcnew System::Windows::Forms::Label());
			this->button_home = (gcnew System::Windows::Forms::Button());
			this->field_xk = (gcnew System::Windows::Forms::TextBox());
			this->button_calc = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->field_dx = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::Label());
			this->field_xn = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->field_a = (gcnew System::Windows::Forms::TextBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->result_container = (gcnew System::Windows::Forms::ListBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->field_cnt = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->field_mlt = (gcnew System::Windows::Forms::TextBox());
			this->field_sum = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
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
			this->header_title->Text = L"Лабораторная работа №6\r\n«Программирование алгоритмов регулярных\r\nциклических стру"
				L"ктур»";
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
			this->button_home->Click += gcnew System::EventHandler(this, &Lab6::button_home_click);
			// 
			// field_xk
			// 
			this->field_xk->Location = System::Drawing::Point(47, 91);
			this->field_xk->Name = L"field_xk";
			this->field_xk->Size = System::Drawing::Size(100, 31);
			this->field_xk->TabIndex = 8;
			// 
			// button_calc
			// 
			this->button_calc->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_calc->Location = System::Drawing::Point(6, 131);
			this->button_calc->Name = L"button_calc";
			this->button_calc->Size = System::Drawing::Size(182, 35);
			this->button_calc->TabIndex = 18;
			this->button_calc->Text = L"РАСЧЕТ";
			this->button_calc->UseVisualStyleBackColor = true;
			this->button_calc->Click += gcnew System::EventHandler(this, &Lab6::button_calc_click);
			// 
			// groupBox1
			// 
			this->groupBox1->AutoSize = true;
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->field_dx);
			this->groupBox1->Controls->Add(this->textBox2);
			this->groupBox1->Controls->Add(this->field_xn);
			this->groupBox1->Controls->Add(this->field_xk);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->field_a);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->groupBox1->Location = System::Drawing::Point(12, 191);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(153, 184);
			this->groupBox1->TabIndex = 2;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Ввод данных";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(6, 122);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(35, 25);
			this->label2->TabIndex = 9;
			this->label2->Text = L"dx:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(8, 90);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(33, 25);
			this->label3->TabIndex = 5;
			this->label3->Text = L"xk:";
			// 
			// field_dx
			// 
			this->field_dx->Location = System::Drawing::Point(47, 123);
			this->field_dx->Name = L"field_dx";
			this->field_dx->Size = System::Drawing::Size(100, 31);
			this->field_dx->TabIndex = 10;
			// 
			// textBox2
			// 
			this->textBox2->AutoSize = true;
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox2->Location = System::Drawing::Point(7, 58);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(34, 25);
			this->textBox2->TabIndex = 7;
			this->textBox2->Text = L"xn:";
			// 
			// field_xn
			// 
			this->field_xn->Location = System::Drawing::Point(47, 59);
			this->field_xn->Name = L"field_xn";
			this->field_xn->Size = System::Drawing::Size(100, 31);
			this->field_xn->TabIndex = 6;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(16, 26);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(25, 25);
			this->label1->TabIndex = 3;
			this->label1->Text = L"a:";
			// 
			// field_a
			// 
			this->field_a->Location = System::Drawing::Point(47, 27);
			this->field_a->Name = L"field_a";
			this->field_a->Size = System::Drawing::Size(100, 31);
			this->field_a->TabIndex = 4;
			// 
			// groupBox2
			// 
			this->groupBox2->AutoSize = true;
			this->groupBox2->Controls->Add(this->result_container);
			this->groupBox2->Controls->Add(this->label6);
			this->groupBox2->Controls->Add(this->label5);
			this->groupBox2->Controls->Add(this->field_cnt);
			this->groupBox2->Controls->Add(this->label4);
			this->groupBox2->Controls->Add(this->field_mlt);
			this->groupBox2->Controls->Add(this->field_sum);
			this->groupBox2->Controls->Add(this->button_calc);
			this->groupBox2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox2->Location = System::Drawing::Point(12, 381);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(611, 295);
			this->groupBox2->TabIndex = 11;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Вывод данных";
			// 
			// result_container
			// 
			this->result_container->FormattingEnabled = true;
			this->result_container->ItemHeight = 25;
			this->result_container->Location = System::Drawing::Point(194, 22);
			this->result_container->Name = L"result_container";
			this->result_container->Size = System::Drawing::Size(411, 229);
			this->result_container->TabIndex = 19;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label6->Location = System::Drawing::Point(16, 93);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(40, 25);
			this->label6->TabIndex = 16;
			this->label6->Text = L"cnt:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(14, 61);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(42, 25);
			this->label5->TabIndex = 14;
			this->label5->Text = L"mlt:";
			// 
			// field_cnt
			// 
			this->field_cnt->Location = System::Drawing::Point(62, 94);
			this->field_cnt->Name = L"field_cnt";
			this->field_cnt->ReadOnly = true;
			this->field_cnt->Size = System::Drawing::Size(126, 31);
			this->field_cnt->TabIndex = 17;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(6, 29);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(50, 25);
			this->label4->TabIndex = 12;
			this->label4->Text = L"sum:";
			// 
			// field_mlt
			// 
			this->field_mlt->Location = System::Drawing::Point(62, 62);
			this->field_mlt->Name = L"field_mlt";
			this->field_mlt->ReadOnly = true;
			this->field_mlt->Size = System::Drawing::Size(126, 31);
			this->field_mlt->TabIndex = 15;
			// 
			// field_sum
			// 
			this->field_sum->Location = System::Drawing::Point(62, 30);
			this->field_sum->Name = L"field_sum";
			this->field_sum->ReadOnly = true;
			this->field_sum->Size = System::Drawing::Size(126, 31);
			this->field_sum->TabIndex = 13;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label7->Location = System::Drawing::Point(12, 679);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(340, 75);
			this->label7->TabIndex = 13;
			this->label7->Text = L"sum — сумма значений функции\r\nmlt — произведение значений функции\r\ncnt — количест"
				L"во значений функции";
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(206, 217);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(414, 118);
			this->pictureBox1->TabIndex = 14;
			this->pictureBox1->TabStop = false;
			// 
			// Lab6
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1436, 951);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->button_home);
			this->Controls->Add(this->label_copyright);
			this->Controls->Add(this->header_title);
			this->Name = L"Lab6";
			this->ShowIcon = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Лабораторная №6";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &Lab6::button_exit_click);
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
			double a = Utils::getDoubleFromTextBox(field_a);
			double xn = Utils::getDoubleFromTextBox(field_xn);
			double xk = Utils::getDoubleFromTextBox(field_xk);
			double dx = Utils::getDoubleFromTextBox(field_dx);
			double sum = 0, mlt = 1, cnt = 0;
			Utils::solve3(result_container, a, xn, xk, dx, sum, mlt, cnt);
			if (cnt == 0) return; // there is nothing to show
			Utils::setDataToTextBox(field_sum, sum);
			Utils::setDataToTextBox(field_mlt, mlt);
			Utils::setDataToTextBox(field_cnt, cnt);
		}
	};
}

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
	public ref class Lab15 : public System::Windows::Forms::Form
	{
	private:
		Form^ parent = nullptr;
	public:
		Lab15(Form^ parent)
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
		~Lab15()
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
	private: System::Windows::Forms::TextBox^ input_x;
	private: System::Windows::Forms::TextBox^ output1;
	private: System::Windows::Forms::TextBox^ output2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::ListView^ list;

	private: System::Windows::Forms::ColumnHeader^ columnIterationNumber;
	private: System::Windows::Forms::ColumnHeader^ columnValue;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::GroupBox^ groupBox3;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Lab15::typeid));
			this->header_title = (gcnew System::Windows::Forms::Label());
			this->button_home = (gcnew System::Windows::Forms::Button());
			this->label_copyright = (gcnew System::Windows::Forms::Label());
			this->button_run = (gcnew System::Windows::Forms::Button());
			this->input_x = (gcnew System::Windows::Forms::TextBox());
			this->output1 = (gcnew System::Windows::Forms::TextBox());
			this->output2 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->list = (gcnew System::Windows::Forms::ListView());
			this->columnIterationNumber = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnValue = (gcnew System::Windows::Forms::ColumnHeader());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->groupBox3->SuspendLayout();
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
			this->header_title->Size = System::Drawing::Size(1317, 98);
			this->header_title->TabIndex = 1;
			this->header_title->Text = L"Лабораторная работа №6\r\n«Программирование алгоритмов итеративных циклических стру"
				L"ктур»";
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
			this->button_home->TabIndex = 8;
			this->button_home->Text = L"На главную";
			this->button_home->UseVisualStyleBackColor = true;
			this->button_home->Click += gcnew System::EventHandler(this, &Lab15::button_home_click);
			// 
			// label_copyright
			// 
			this->label_copyright->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->label_copyright->AutoSize = true;
			this->label_copyright->Enabled = false;
			this->label_copyright->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_copyright->Location = System::Drawing::Point(8, 793);
			this->label_copyright->Name = L"label_copyright";
			this->label_copyright->Size = System::Drawing::Size(410, 84);
			this->label_copyright->TabIndex = 7;
			this->label_copyright->Text = L"Выполнил: студент группы БСТ2001 Савкин Д.И.\r\nВариант № 24\r\nПроверил: доцент кафе"
				L"дры «Информатика»\r\nГуриков С.Р.\r\n";
			// 
			// button_run
			// 
			this->button_run->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_run->Location = System::Drawing::Point(6, 171);
			this->button_run->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->button_run->Name = L"button_run";
			this->button_run->Size = System::Drawing::Size(375, 44);
			this->button_run->TabIndex = 2;
			this->button_run->Text = L"РАССЧИТАТЬ";
			this->button_run->UseVisualStyleBackColor = true;
			this->button_run->Click += gcnew System::EventHandler(this, &Lab15::button_calc_click);
			// 
			// input_x
			// 
			this->input_x->Location = System::Drawing::Point(6, 38);
			this->input_x->Name = L"input_x";
			this->input_x->Size = System::Drawing::Size(300, 23);
			this->input_x->TabIndex = 9;
			// 
			// output1
			// 
			this->output1->Location = System::Drawing::Point(6, 82);
			this->output1->Name = L"output1";
			this->output1->ReadOnly = true;
			this->output1->Size = System::Drawing::Size(300, 23);
			this->output1->TabIndex = 10;
			// 
			// output2
			// 
			this->output2->Location = System::Drawing::Point(6, 141);
			this->output2->Name = L"output2";
			this->output2->ReadOnly = true;
			this->output2->Size = System::Drawing::Size(300, 23);
			this->output2->TabIndex = 11;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(6, 19);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(78, 15);
			this->label1->TabIndex = 12;
			this->label1->Text = L"Значение \"x\"";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(6, 64);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(207, 15);
			this->label2->TabIndex = 13;
			this->label2->Text = L"Значение \"ln(x+1)\" | Точность 0,0001";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(6, 108);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(263, 30);
			this->label3->TabIndex = 14;
			this->label3->Text = L"Значение \"ln(x+1)\" | Точность 0,0001\r\n(результат вычисления стандартной фкнкции)";
			// 
			// list
			// 
			this->list->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(2) {
				this->columnIterationNumber,
					this->columnValue
			});
			this->list->Location = System::Drawing::Point(6, 17);
			this->list->Name = L"list";
			this->list->Size = System::Drawing::Size(307, 360);
			this->list->TabIndex = 15;
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
			// groupBox1
			// 
			this->groupBox1->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->groupBox1->Controls->Add(this->input_x);
			this->groupBox1->Controls->Add(this->button_run);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->output1);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->output2);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Location = System::Drawing::Point(12, 272);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(625, 238);
			this->groupBox1->TabIndex = 16;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Ввод";
			// 
			// groupBox2
			// 
			this->groupBox2->AutoSize = true;
			this->groupBox2->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->groupBox2->Controls->Add(this->list);
			this->groupBox2->Location = System::Drawing::Point(643, 110);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(319, 399);
			this->groupBox2->TabIndex = 17;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Вывод";
			// 
			// groupBox3
			// 
			this->groupBox3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->groupBox3->AutoSize = true;
			this->groupBox3->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->groupBox3->Controls->Add(this->pictureBox1);
			this->groupBox3->Location = System::Drawing::Point(12, 110);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(625, 156);
			this->groupBox3->TabIndex = 18;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Задание";
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(20, 22);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(599, 112);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// Lab15
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1341, 886);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->button_home);
			this->Controls->Add(this->label_copyright);
			this->Controls->Add(this->header_title);
			this->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->Name = L"Lab15";
			this->ShowIcon = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Лабораторная №6";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &Lab15::button_exit_click);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
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
			// Get 'x' value
			double x = Convert::ToDouble(input_x->Text);
			
			// Calculate results
			double result1 = UtilsLibrary3::Utils::log_custom(x, 0.0001, list);
			double result2 = log(x + 1);
			
			// Show them
			output1->Text = result1.ToString();
			output2->Text = result2.ToString();
		}
	};
}

#pragma once
#include "QuestionThirteen.h"

namespace Coursework {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace CourseworkLibrary;
	/// <summary>
	/// Summary for QuestionTwelve1
	/// </summary>
	public ref class QuestionTwelve : public System::Windows::Forms::Form
	{
	public:
		QuestionTwelve(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~QuestionTwelve()
		{
			if (components)
			{
				delete components;
			}
		}


	private: System::Windows::Forms::Button^ button_next;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::NumericUpDown^ counter_1;
	private: System::Windows::Forms::NumericUpDown^ counter_2;
	private: System::Windows::Forms::NumericUpDown^ counter_3;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::GroupBox^ groupBox1;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(QuestionTwelve::typeid));
			this->button_next = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->counter_1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->counter_2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->counter_3 = (gcnew System::Windows::Forms::NumericUpDown());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->counter_1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->counter_2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->counter_3))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// button_next
			// 
			this->button_next->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->button_next->AutoSize = true;
			this->button_next->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->button_next->Location = System::Drawing::Point(842, 502);
			this->button_next->Name = L"button_next";
			this->button_next->Size = System::Drawing::Size(34, 35);
			this->button_next->TabIndex = 2;
			this->button_next->Text = L">";
			this->button_next->UseVisualStyleBackColor = true;
			this->button_next->Click += gcnew System::EventHandler(this, &QuestionTwelve::button_next_click);
			// 
			// label1
			// 
			this->label1->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(238, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(412, 25);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Соотнесите название концепции с её описанием";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(57, 33);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(83, 25);
			this->label2->TabIndex = 0;
			this->label2->Text = L"Процесс";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(57, 71);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(117, 25);
			this->label3->TabIndex = 0;
			this->label3->Text = L"Пул потоков";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(57, 109);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(79, 25);
			this->label4->TabIndex = 0;
			this->label4->Text = L"Задание";
			// 
			// counter_1
			// 
			this->counter_1->Location = System::Drawing::Point(7, 31);
			this->counter_1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 3, 0, 0, 0 });
			this->counter_1->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->counter_1->Name = L"counter_1";
			this->counter_1->Size = System::Drawing::Size(44, 31);
			this->counter_1->TabIndex = 1;
			this->counter_1->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// counter_2
			// 
			this->counter_2->Location = System::Drawing::Point(7, 69);
			this->counter_2->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 3, 0, 0, 0 });
			this->counter_2->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->counter_2->Name = L"counter_2";
			this->counter_2->Size = System::Drawing::Size(44, 31);
			this->counter_2->TabIndex = 2;
			this->counter_2->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// counter_3
			// 
			this->counter_3->Location = System::Drawing::Point(7, 107);
			this->counter_3->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 3, 0, 0, 0 });
			this->counter_3->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->counter_3->Name = L"counter_3";
			this->counter_3->Size = System::Drawing::Size(44, 31);
			this->counter_3->TabIndex = 3;
			this->counter_3->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(201, 33);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(212, 25);
			this->label5->TabIndex = 1;
			this->label5->Text = L"1. Коллекция процессов";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(201, 71);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(233, 25);
			this->label6->TabIndex = 0;
			this->label6->Text = L"2. Контейнер для ресурсов";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(201, 109);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(319, 50);
			this->label7->TabIndex = 0;
			this->label7->Text = L"3. Контейнер, занимающийся\r\nпоочерёдным выполнением заданий";
			// 
			// groupBox1
			// 
			this->groupBox1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->groupBox1->AutoSize = true;
			this->groupBox1->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->groupBox1->Controls->Add(this->label7);
			this->groupBox1->Controls->Add(this->label6);
			this->groupBox1->Controls->Add(this->label5);
			this->groupBox1->Controls->Add(this->counter_3);
			this->groupBox1->Controls->Add(this->counter_2);
			this->groupBox1->Controls->Add(this->counter_1);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Location = System::Drawing::Point(181, 194);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(526, 186);
			this->groupBox1->TabIndex = 1;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Варианты ответов";
			// 
			// QuestionTwelve
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(10, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(888, 549);
			this->Controls->Add(this->button_next);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->label1);
			this->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->MaximizeBox = false;
			this->Name = L"QuestionTwelve";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Вопрос 12";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &QuestionTwelve::button_exit_click);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->counter_1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->counter_2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->counter_3))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private:

		System::Void button_exit_click(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e)
		{
			Tools::handleExitButton(e, "Выход из программы понесет за собой потерю " +
				"прогресса тестирования.\nВы действительно хотите выйти?");
		}

		System::Void button_next_click(System::Object^ sender, System::EventArgs^ e)
		{
			UserAnswers::Instance->setAnswerResult(12, Tools::handleAnswerTwelve(counter_1, counter_2, counter_3));

			Form^ next = gcnew QuestionThirteen();
			this->Hide();
			next->Show();
		}
	};
}

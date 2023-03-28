#pragma once
#include "Results.h"

namespace Coursework {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace CourseworkLibrary;
	/// <summary>
	/// Summary for QuestionSixteen1
	/// </summary>
	public ref class QuestionSixteen : public System::Windows::Forms::Form
	{
	public:
		QuestionSixteen(void)
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
		~QuestionSixteen()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^ groupBox1;
	protected:

	protected:
	private: System::Windows::Forms::RadioButton^ radio_two;
	private: System::Windows::Forms::RadioButton^ radio_one;
	private: System::Windows::Forms::Button^ button_next;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::RadioButton^ radio_three;

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
			   System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(QuestionSixteen::typeid));
			   this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			   this->radio_three = (gcnew System::Windows::Forms::RadioButton());
			   this->radio_two = (gcnew System::Windows::Forms::RadioButton());
			   this->radio_one = (gcnew System::Windows::Forms::RadioButton());
			   this->button_next = (gcnew System::Windows::Forms::Button());
			   this->label1 = (gcnew System::Windows::Forms::Label());
			   this->groupBox1->SuspendLayout();
			   this->SuspendLayout();
			   // 
			   // groupBox1
			   // 
			   this->groupBox1->Anchor = System::Windows::Forms::AnchorStyles::None;
			   this->groupBox1->AutoSize = true;
			   this->groupBox1->Controls->Add(this->radio_three);
			   this->groupBox1->Controls->Add(this->radio_two);
			   this->groupBox1->Controls->Add(this->radio_one);
			   this->groupBox1->Location = System::Drawing::Point(179, 232);
			   this->groupBox1->Name = L"groupBox1";
			   this->groupBox1->Size = System::Drawing::Size(531, 160);
			   this->groupBox1->TabIndex = 0;
			   this->groupBox1->TabStop = false;
			   this->groupBox1->Text = L"Варианты ответов";
			   // 
			   // radio_three
			   // 
			   this->radio_three->AutoSize = true;
			   this->radio_three->Location = System::Drawing::Point(6, 101);
			   this->radio_three->Name = L"radio_three";
			   this->radio_three->Size = System::Drawing::Size(360, 29);
			   this->radio_three->TabIndex = 3;
			   this->radio_three->TabStop = true;
			   this->radio_three->Text = L"С помощью прямого доступа к памяти";
			   this->radio_three->UseVisualStyleBackColor = true;
			   // 
			   // radio_two
			   // 
			   this->radio_two->AutoSize = true;
			   this->radio_two->Location = System::Drawing::Point(6, 66);
			   this->radio_two->Name = L"radio_two";
			   this->radio_two->Size = System::Drawing::Size(519, 29);
			   this->radio_two->TabIndex = 2;
			   this->radio_two->TabStop = true;
			   this->radio_two->Text = L"С помощью ввода-вывода, управляемого прерываниями";
			   this->radio_two->UseVisualStyleBackColor = true;
			   // 
			   // radio_one
			   // 
			   this->radio_one->AutoSize = true;
			   this->radio_one->Location = System::Drawing::Point(6, 30);
			   this->radio_one->Name = L"radio_one";
			   this->radio_one->Size = System::Drawing::Size(433, 29);
			   this->radio_one->TabIndex = 1;
			   this->radio_one->TabStop = true;
			   this->radio_one->Text = L"С помощью программируемого ввода-вывода";
			   this->radio_one->UseVisualStyleBackColor = true;
			   // 
			   // button_next
			   // 
			   this->button_next->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			   this->button_next->AutoSize = true;
			   this->button_next->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			   this->button_next->Location = System::Drawing::Point(617, 502);
			   this->button_next->Name = L"button_next";
			   this->button_next->Size = System::Drawing::Size(259, 35);
			   this->button_next->TabIndex = 4;
			   this->button_next->Text = L"ЗАВЕРШИТЬ ТЕСТИРОВАНИЕ";
			   this->button_next->UseVisualStyleBackColor = true;
			   this->button_next->Click += gcnew System::EventHandler(this, &QuestionSixteen::button_next_click);
			   // 
			   // label1
			   // 
			   this->label1->Anchor = System::Windows::Forms::AnchorStyles::Top;
			   this->label1->AutoSize = true;
			   this->label1->Location = System::Drawing::Point(171, 9);
			   this->label1->Name = L"label1";
			   this->label1->Size = System::Drawing::Size(547, 75);
			   this->label1->TabIndex = 0;
			   this->label1->Text = L"Для персональных компьютеров операции ввода-вывода могут\r\nвыполняться тремя спосо"
				   L"бами. Укажите, какой способ наиболее\r\nоптимальный на текущий момент развития арх"
				   L"итектуры ЭВМ";
			   this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			   // 
			   // QuestionSixteen
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(10, 25);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->ClientSize = System::Drawing::Size(888, 549);
			   this->Controls->Add(this->groupBox1);
			   this->Controls->Add(this->button_next);
			   this->Controls->Add(this->label1);
			   this->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			   this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			   this->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			   this->MaximizeBox = false;
			   this->Name = L"QuestionSixteen";
			   this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			   this->Text = L"Вопрос 16";
			   this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &QuestionSixteen::button_exit_click);
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
			UserAnswers::Instance->setAnswerResult(16, Tools::handleAnswerSixteen(radio_three));

			Form^ next = gcnew Results();
			this->Hide();
			next->Show();
		}
	};
}

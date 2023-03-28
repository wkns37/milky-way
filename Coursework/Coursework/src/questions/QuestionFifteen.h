#pragma once
#include "QuestionSixteen.h"

namespace Coursework {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace CourseworkLibrary;
	/// <summary>
	/// Summary for QuestionFifteen1
	/// </summary>
	public ref class QuestionFifteen : public System::Windows::Forms::Form
	{
	public:
		QuestionFifteen(void)
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
		~QuestionFifteen()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:


	private: System::Windows::Forms::Button^ button_next;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::CheckBox^ answer_3;
	private: System::Windows::Forms::CheckBox^ answer_2;
	private: System::Windows::Forms::CheckBox^ answer_1;
	private: System::Windows::Forms::CheckBox^ answer_4;
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
			   System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(QuestionFifteen::typeid));
			   this->button_next = (gcnew System::Windows::Forms::Button());
			   this->label1 = (gcnew System::Windows::Forms::Label());
			   this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			   this->answer_4 = (gcnew System::Windows::Forms::CheckBox());
			   this->answer_3 = (gcnew System::Windows::Forms::CheckBox());
			   this->answer_2 = (gcnew System::Windows::Forms::CheckBox());
			   this->answer_1 = (gcnew System::Windows::Forms::CheckBox());
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
			   this->button_next->TabIndex = 5;
			   this->button_next->Text = L">";
			   this->button_next->UseVisualStyleBackColor = true;
			   this->button_next->Click += gcnew System::EventHandler(this, &QuestionFifteen::button_next_click);
			   // 
			   // label1
			   // 
			   this->label1->Anchor = System::Windows::Forms::AnchorStyles::Top;
			   this->label1->AutoSize = true;
			   this->label1->Location = System::Drawing::Point(159, 9);
			   this->label1->Name = L"label1";
			   this->label1->Size = System::Drawing::Size(571, 50);
			   this->label1->TabIndex = 0;
			   this->label1->Text = L"Исходя из полученных знаний о работе подсистемы ввода-вывода,\r\nвыберите верные ут"
				   L"верждения из списка предложенных";
			   this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			   // 
			   // groupBox1
			   // 
			   this->groupBox1->Anchor = System::Windows::Forms::AnchorStyles::None;
			   this->groupBox1->AutoSize = true;
			   this->groupBox1->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			   this->groupBox1->Controls->Add(this->answer_4);
			   this->groupBox1->Controls->Add(this->answer_3);
			   this->groupBox1->Controls->Add(this->answer_2);
			   this->groupBox1->Controls->Add(this->answer_1);
			   this->groupBox1->Location = System::Drawing::Point(122, 152);
			   this->groupBox1->Name = L"groupBox1";
			   this->groupBox1->Size = System::Drawing::Size(644, 294);
			   this->groupBox1->TabIndex = 0;
			   this->groupBox1->TabStop = false;
			   this->groupBox1->Text = L"Варианты ответов";
			   // 
			   // answer_4
			   // 
			   this->answer_4->AutoSize = true;
			   this->answer_4->Location = System::Drawing::Point(6, 210);
			   this->answer_4->Name = L"answer_4";
			   this->answer_4->Size = System::Drawing::Size(526, 54);
			   this->answer_4->TabIndex = 4;
			   this->answer_4->Text = L"Система ввода-вывода способна поддерживать несколько\r\nфайловых систем";
			   this->answer_4->UseVisualStyleBackColor = true;
			   // 
			   // answer_3
			   // 
			   this->answer_3->AutoSize = true;
			   this->answer_3->Location = System::Drawing::Point(6, 150);
			   this->answer_3->Name = L"answer_3";
			   this->answer_3->Size = System::Drawing::Size(474, 54);
			   this->answer_3->TabIndex = 3;
			   this->answer_3->Text = L"Разделением устройств и данных между процессами\r\nзанимается система ввода-вывода";
			   this->answer_3->UseVisualStyleBackColor = true;
			   // 
			   // answer_2
			   // 
			   this->answer_2->AutoSize = true;
			   this->answer_2->Location = System::Drawing::Point(6, 90);
			   this->answer_2->Name = L"answer_2";
			   this->answer_2->Size = System::Drawing::Size(504, 54);
			   this->answer_2->TabIndex = 2;
			   this->answer_2->Text = L"Согласование скоростей обмена и кэширования данных\r\nне предусмотрено системой вво"
				   L"да-вывода";
			   this->answer_2->UseVisualStyleBackColor = true;
			   // 
			   // answer_1
			   // 
			   this->answer_1->AutoSize = true;
			   this->answer_1->Location = System::Drawing::Point(6, 30);
			   this->answer_1->Name = L"answer_1";
			   this->answer_1->Size = System::Drawing::Size(632, 54);
			   this->answer_1->TabIndex = 1;
			   this->answer_1->Text = L"Грамотная организация параллельной работы устройств ввода-вывода\r\nи процессора ле"
				   L"жит в основе указанной подсистемы";
			   this->answer_1->UseVisualStyleBackColor = true;
			   // 
			   // QuestionFifteen
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
			   this->Name = L"QuestionFifteen";
			   this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			   this->Text = L"Вопрос 15";
			   this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &QuestionFifteen::button_exit_click);
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
			UserAnswers::Instance->setAnswerResult(15,
				Tools::handleAnswerFifteen(answer_1, answer_2, answer_3, answer_4));

			Form^ next = gcnew QuestionSixteen();
			this->Hide();
			next->Show();
		}
	};
}

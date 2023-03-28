#pragma once
#include "QuestionFour.h"

namespace Coursework {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace CourseworkLibrary;

	/// <summary>
	/// Summary for QuestionThree1
	/// </summary>
	public ref class QuestionThree : public System::Windows::Forms::Form
	{
	public:
		QuestionThree(void)
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
		~QuestionThree()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::GroupBox^ groupBox1;

	private: System::Windows::Forms::Button^ button_next;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ field_answer;
	private: System::Windows::Forms::Label^ label3;





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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(QuestionThree::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->field_answer = (gcnew System::Windows::Forms::TextBox());
			this->button_next = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(91, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(522, 75);
			this->label1->TabIndex = 0;
			this->label1->Text = L"В процессе запуска ЭВМ BIOS проверяет физическое наличие\r\nнеобходимых компонентов"
				L". Напишите аббревиатуру\r\nпроцесса, о котором идёт речь.";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// groupBox1
			// 
			this->groupBox1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->groupBox1->AutoSize = true;
			this->groupBox1->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->field_answer);
			this->groupBox1->Location = System::Drawing::Point(266, 242);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(172, 116);
			this->groupBox1->TabIndex = 1;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Поле ввода";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(6, 27);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(63, 25);
			this->label2->TabIndex = 0;
			this->label2->Text = L"Ответ:";
			// 
			// field_answer
			// 
			this->field_answer->Location = System::Drawing::Point(6, 55);
			this->field_answer->Name = L"field_answer";
			this->field_answer->Size = System::Drawing::Size(160, 31);
			this->field_answer->TabIndex = 1;
			// 
			// button_next
			// 
			this->button_next->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->button_next->AutoSize = true;
			this->button_next->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->button_next->Location = System::Drawing::Point(658, 479);
			this->button_next->Name = L"button_next";
			this->button_next->Size = System::Drawing::Size(34, 35);
			this->button_next->TabIndex = 2;
			this->button_next->Text = L">";
			this->button_next->UseVisualStyleBackColor = true;
			this->button_next->Click += gcnew System::EventHandler(this, &QuestionThree::button_next_click);
			// 
			// label3
			// 
			this->label3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->label3->AutoSize = true;
			this->label3->Enabled = false;
			this->label3->Location = System::Drawing::Point(12, 492);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(337, 25);
			this->label3->TabIndex = 0;
			this->label3->Text = L"Ответ должен быть введён на латинице";
			// 
			// QuestionThree
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(10, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(704, 526);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->button_next);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->label1);
			this->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->MaximizeBox = false;
			this->Name = L"QuestionThree";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Вопрос 3";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &QuestionThree::button_exit_click);
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
			UserAnswers::Instance->setAnswerResult(3, Tools::handleAnswerThree(field_answer));

			Form^ next = gcnew QuestionFour();
			this->Hide();
			next->Show();
		}
	};
}

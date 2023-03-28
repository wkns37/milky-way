#pragma once
#include "QuestionTwo.h"

namespace Coursework {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace CourseworkLibrary;

	/// <summary>
	/// Summary for QuestionOne
	/// </summary>
	public ref class QuestionOne : public System::Windows::Forms::Form
	{
	public:
		QuestionOne(void)
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
		~QuestionOne()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::RadioButton^ radio_no;
	private: System::Windows::Forms::RadioButton^ radio_yes;



	private: System::Windows::Forms::Button^ button_next;



	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(QuestionOne::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->radio_no = (gcnew System::Windows::Forms::RadioButton());
			this->radio_yes = (gcnew System::Windows::Forms::RadioButton());
			this->button_next = (gcnew System::Windows::Forms::Button());
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(68, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(568, 50);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Возможна ли работа с ЭВМ (работа с прикладными программами),\r\nна которой не устан"
				L"овлена операционная система\?";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// groupBox1
			// 
			this->groupBox1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->groupBox1->AutoSize = true;
			this->groupBox1->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->groupBox1->Controls->Add(this->radio_no);
			this->groupBox1->Controls->Add(this->radio_yes);
			this->groupBox1->Location = System::Drawing::Point(256, 225);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(192, 126);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Варианты ответов";
			// 
			// radio_no
			// 
			this->radio_no->AutoSize = true;
			this->radio_no->Location = System::Drawing::Point(7, 67);
			this->radio_no->Name = L"radio_no";
			this->radio_no->Size = System::Drawing::Size(179, 29);
			this->radio_no->TabIndex = 2;
			this->radio_no->TabStop = true;
			this->radio_no->Text = L"Нет, невозможна";
			this->radio_no->UseVisualStyleBackColor = true;
			// 
			// radio_yes
			// 
			this->radio_yes->AutoSize = true;
			this->radio_yes->Location = System::Drawing::Point(7, 31);
			this->radio_yes->Name = L"radio_yes";
			this->radio_yes->Size = System::Drawing::Size(152, 29);
			this->radio_yes->TabIndex = 1;
			this->radio_yes->TabStop = true;
			this->radio_yes->Text = L"Да, возможна";
			this->radio_yes->UseVisualStyleBackColor = true;
			// 
			// button_next
			// 
			this->button_next->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->button_next->AutoSize = true;
			this->button_next->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->button_next->Location = System::Drawing::Point(658, 479);
			this->button_next->Name = L"button_next";
			this->button_next->Size = System::Drawing::Size(34, 35);
			this->button_next->TabIndex = 3;
			this->button_next->Text = L">";
			this->button_next->UseVisualStyleBackColor = true;
			this->button_next->Click += gcnew System::EventHandler(this, &QuestionOne::button_next_click);
			// 
			// QuestionOne
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(10, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(704, 526);
			this->Controls->Add(this->button_next);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->label1);
			this->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->MaximizeBox = false;
			this->Name = L"QuestionOne";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Вопрос 1";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &QuestionOne::button_exit_click);
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
			UserAnswers::Instance->setAnswerResult(1, Tools::handleAnswerOne(radio_no));

			Form^ next = gcnew QuestionTwo();
			this->Hide();
			next->Show();
		}
	};
}

#pragma once
#include "Auth.h"
#include "Splash.h"

namespace Coursework {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace CourseworkLibrary;
	/// <summary>
	/// Summary for App
	/// </summary>
	public ref class App : public System::Windows::Forms::Form
	{
	public:

	public:
		App(void)
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
		~App()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;

	private: System::Windows::Forms::Button^ button_start;
	private: System::ComponentModel::IContainer^ components;
		
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(App::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button_start = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(12, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(1334, 376);
			this->label1->TabIndex = 0;
			this->label1->Text = resources->GetString(L"label1.Text");
			this->label1->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// label2
			// 
			this->label2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->label2->AutoSize = true;
			this->label2->Enabled = false;
			this->label2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(741, 703);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(605, 132);
			this->label2->TabIndex = 0;
			this->label2->Text = L"Выполнил: студент группы БСТ2001 Савкин Д.И.\r\nВариант № 26\r\nПроверил: доцент кафе"
				L"дры «Информатика»\r\nГуриков С.Р.";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// button_start
			// 
			this->button_start->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button_start->Location = System::Drawing::Point(567, 519);
			this->button_start->Name = L"button_start";
			this->button_start->Size = System::Drawing::Size(223, 50);
			this->button_start->TabIndex = 2;
			this->button_start->Text = L"НАЧАТЬ РАБОТУ";
			this->button_start->UseVisualStyleBackColor = true;
			this->button_start->Click += gcnew System::EventHandler(this, &App::button_start_click);
			// 
			// App
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(10, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1358, 844);
			this->Controls->Add(this->button_start);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->Name = L"App";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Курсовая работа | Операционные системы";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private:
		System::Void button_start_click(System::Object^ sender, System::EventArgs^ e)
		{
			UserAnswers::Instance->setAnswerResult(1, 1);
			UserAnswers::Instance->setAnswerResult(2, 1);
			UserAnswers::Instance->setAnswerResult(3, 0);
			UserAnswers::Instance->setAnswerResult(4, 1);
			UserAnswers::Instance->setAnswerResult(5, 1);
			UserAnswers::Instance->setAnswerResult(6, 0);
			UserAnswers::Instance->setAnswerResult(7, 1);
			UserAnswers::Instance->setAnswerResult(8, 0);
			UserAnswers::Instance->setAnswerResult(9, 1);
			UserAnswers::Instance->setAnswerResult(10, 0);
			UserAnswers::Instance->setAnswerResult(11, 0);
			UserAnswers::Instance->setAnswerResult(12, 0);
			UserAnswers::Instance->setAnswerResult(13, 1);
			UserAnswers::Instance->setAnswerResult(14, 1);
			UserAnswers::Instance->setAnswerResult(15, 0);
			UserAnswers::Instance->setAnswerResult(16, 1);

			Form^ splash = gcnew Splash();
			Auth^ auth = gcnew Auth(this, splash);
			this->Hide();
			auth->Show();
		}
	};
}

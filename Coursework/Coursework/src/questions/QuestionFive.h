#pragma once
#include "QuestionSix.h"

namespace Coursework {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace CourseworkLibrary;

	/// <summary>
	/// Summary for QuestionFive1
	/// </summary>
	public ref class QuestionFive : public System::Windows::Forms::Form
	{
	private:
		int selectedAnswer = 1;

	public:
		QuestionFive(void)
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
		~QuestionFive()
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
	private: System::Windows::Forms::HScrollBar^ bar;

	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label6;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(QuestionFive::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->bar = (gcnew System::Windows::Forms::HScrollBar());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button_next = (gcnew System::Windows::Forms::Button());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(77, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(734, 75);
			this->label1->TabIndex = 0;
			this->label1->Text = resources->GetString(L"label1.Text");
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// groupBox1
			// 
			this->groupBox1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->groupBox1->AutoSize = true;
			this->groupBox1->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->groupBox1->Controls->Add(this->bar);
			this->groupBox1->Controls->Add(this->label5);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Location = System::Drawing::Point(101, 257);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(687, 136);
			this->groupBox1->TabIndex = 1;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Варианты ответов";
			// 
			// bar
			// 
			this->bar->Location = System::Drawing::Point(3, 83);
			this->bar->Name = L"bar";
			this->bar->Size = System::Drawing::Size(681, 26);
			this->bar->SmallChange = 10;
			this->bar->TabIndex = 1;
			this->bar->Value = 7;
			this->bar->ValueChanged += gcnew System::EventHandler(this, &QuestionFive::onScroll);
			// 
			// label5
			// 
			this->label5->Location = System::Drawing::Point(503, 27);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(152, 50);
			this->label5->TabIndex = 0;
			this->label5->Text = L"Гибридное ядро";
			this->label5->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// label4
			// 
			this->label4->Location = System::Drawing::Point(345, 27);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(152, 50);
			this->label4->TabIndex = 0;
			this->label4->Text = L"Наноядро";
			this->label4->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// label3
			// 
			this->label3->Location = System::Drawing::Point(187, 27);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(152, 50);
			this->label3->TabIndex = 0;
			this->label3->Text = L"Экзоядро";
			this->label3->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// label2
			// 
			this->label2->Location = System::Drawing::Point(29, 27);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(152, 50);
			this->label2->TabIndex = 0;
			this->label2->Text = L"Модульное ядро";
			this->label2->TextAlign = System::Drawing::ContentAlignment::TopCenter;
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
			this->button_next->Click += gcnew System::EventHandler(this, &QuestionFive::button_next_click);
			// 
			// label6
			// 
			this->label6->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->label6->AutoSize = true;
			this->label6->Enabled = false;
			this->label6->Location = System::Drawing::Point(12, 515);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(509, 25);
			this->label6->TabIndex = 0;
			this->label6->Text = L"Передвиньте полосу прокрутки под нужный вариант ответа";
			// 
			// QuestionFive
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(10, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(888, 549);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->button_next);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->label1);
			this->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->MaximizeBox = false;
			this->Name = L"QuestionFive";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Вопрос 5";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &QuestionFive::button_exit_click);
			this->Shown += gcnew System::EventHandler(this, &QuestionFive::onShown);
			this->groupBox1->ResumeLayout(false);
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

		System::Void onScroll(System::Object^ sender, System::EventArgs^ e)
		{
			// Looks bad but works
			if (bar->Value >= 0 && bar->Value < 25)
			{
				Tools::setHighlighted(label2, true);
				Tools::setHighlighted(label3, false);
				Tools::setHighlighted(label4, false);
				Tools::setHighlighted(label5, false);
				selectedAnswer = 1;
			}
			else if (bar->Value >= 25 && bar->Value < 50)
			{
				Tools::setHighlighted(label2, false);
				Tools::setHighlighted(label3, true);
				Tools::setHighlighted(label4, false);
				Tools::setHighlighted(label5, false);
				selectedAnswer = 2;
			}
			else if (bar->Value >= 50 && bar->Value < 75)
			{
				Tools::setHighlighted(label2, false);
				Tools::setHighlighted(label3, false);
				Tools::setHighlighted(label4, true);
				Tools::setHighlighted(label5, false);
				selectedAnswer = 3;
			}
			else
			{
				Tools::setHighlighted(label2, false);
				Tools::setHighlighted(label3, false);
				Tools::setHighlighted(label4, false);
				Tools::setHighlighted(label5, true);
				selectedAnswer = 4;
			}
		}

		System::Void onShown(System::Object^ sender, System::EventArgs^ e)
		{
			// Choose default value
			Tools::setHighlighted(label2, true);
		}

		System::Void button_next_click(System::Object^ sender, System::EventArgs^ e)
		{
			UserAnswers::Instance->setAnswerResult(5, Tools::handleAnswerFive(selectedAnswer));

			Form^ next = gcnew QuestionSix();
			this->Hide();
			next->Show();
		}
	};
}




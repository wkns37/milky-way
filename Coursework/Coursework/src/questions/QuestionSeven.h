#pragma once
#include "QuestionEight.h"

namespace Coursework {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace CourseworkLibrary;

	/// <summary>
	/// Summary for QuestionSeven1
	/// </summary>
	public ref class QuestionSeven : public System::Windows::Forms::Form
	{
	private:
		int selectedAnswer = 1;

	public:
		QuestionSeven(void)
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
		~QuestionSeven()
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
	private: System::Windows::Forms::TrackBar^ bar;

	private: System::Windows::Forms::Label^ label_8gb;

	private: System::Windows::Forms::Label^ label_4gb;

	private: System::Windows::Forms::Label^ label_1gb;
	private: System::Windows::Forms::Label^ label_2gb;
	private: System::Windows::Forms::Label^ label2;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(QuestionSeven::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->label_8gb = (gcnew System::Windows::Forms::Label());
			this->bar = (gcnew System::Windows::Forms::TrackBar());
			this->label_4gb = (gcnew System::Windows::Forms::Label());
			this->label_1gb = (gcnew System::Windows::Forms::Label());
			this->label_2gb = (gcnew System::Windows::Forms::Label());
			this->button_next = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bar))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(160, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(568, 150);
			this->label1->TabIndex = 0;
			this->label1->Text = resources->GetString(L"label1.Text");
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// groupBox1
			// 
			this->groupBox1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->groupBox1->AutoSize = true;
			this->groupBox1->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->groupBox1->Controls->Add(this->label_8gb);
			this->groupBox1->Controls->Add(this->bar);
			this->groupBox1->Controls->Add(this->label_4gb);
			this->groupBox1->Controls->Add(this->label_1gb);
			this->groupBox1->Controls->Add(this->label_2gb);
			this->groupBox1->Location = System::Drawing::Point(279, 260);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(330, 179);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Варианты ответов";
			// 
			// label_8gb
			// 
			this->label_8gb->Location = System::Drawing::Point(249, 27);
			this->label_8gb->Name = L"label_8gb";
			this->label_8gb->Size = System::Drawing::Size(75, 50);
			this->label_8gb->TabIndex = 0;
			this->label_8gb->Text = L"8 Гб";
			this->label_8gb->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// bar
			// 
			this->bar->LargeChange = 1;
			this->bar->Location = System::Drawing::Point(27, 80);
			this->bar->Maximum = 4;
			this->bar->Minimum = 1;
			this->bar->Name = L"bar";
			this->bar->Size = System::Drawing::Size(280, 69);
			this->bar->TabIndex = 1;
			this->bar->TickStyle = System::Windows::Forms::TickStyle::TopLeft;
			this->bar->Value = 1;
			this->bar->ValueChanged += gcnew System::EventHandler(this, &QuestionSeven::onScroll);
			// 
			// label_4gb
			// 
			this->label_4gb->Location = System::Drawing::Point(168, 27);
			this->label_4gb->Name = L"label_4gb";
			this->label_4gb->Size = System::Drawing::Size(75, 50);
			this->label_4gb->TabIndex = 0;
			this->label_4gb->Text = L"4 Гб";
			this->label_4gb->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// label_1gb
			// 
			this->label_1gb->Location = System::Drawing::Point(6, 27);
			this->label_1gb->Name = L"label_1gb";
			this->label_1gb->Size = System::Drawing::Size(75, 50);
			this->label_1gb->TabIndex = 0;
			this->label_1gb->Text = L"1 Гб";
			this->label_1gb->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// label_2gb
			// 
			this->label_2gb->Location = System::Drawing::Point(87, 27);
			this->label_2gb->Name = L"label_2gb";
			this->label_2gb->Size = System::Drawing::Size(75, 50);
			this->label_2gb->TabIndex = 0;
			this->label_2gb->Text = L"2 Гб";
			this->label_2gb->TextAlign = System::Drawing::ContentAlignment::TopCenter;
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
			this->button_next->Click += gcnew System::EventHandler(this, &QuestionSeven::button_next_click);
			// 
			// label2
			// 
			this->label2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->label2->AutoSize = true;
			this->label2->Enabled = false;
			this->label2->Location = System::Drawing::Point(12, 515);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(437, 25);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Передвиньте указатель под нужный вариант ответа";
			// 
			// QuestionSeven
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(10, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(888, 549);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->button_next);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->label1);
			this->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->Name = L"QuestionSeven";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Вопрос 7";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &QuestionSeven::button_exit_click);
			this->Shown += gcnew System::EventHandler(this, &QuestionSeven::onShown);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bar))->EndInit();
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
			if (bar->Value == 1)
			{
				Tools::setHighlighted(label_1gb, true);
				Tools::setHighlighted(label_2gb, false);
				Tools::setHighlighted(label_4gb, false);
				Tools::setHighlighted(label_8gb, false);
				selectedAnswer = 1;
			}
			else if (bar->Value == 2)
			{
				Tools::setHighlighted(label_1gb, false);
				Tools::setHighlighted(label_2gb, true);
				Tools::setHighlighted(label_4gb, false);
				Tools::setHighlighted(label_8gb, false);
				selectedAnswer = 2;
			}
			else if (bar->Value == 3)
			{
				Tools::setHighlighted(label_1gb, false);
				Tools::setHighlighted(label_2gb, false);
				Tools::setHighlighted(label_4gb, true);
				Tools::setHighlighted(label_8gb, false);
				selectedAnswer = 3;
			}
			else
			{
				Tools::setHighlighted(label_1gb, false);
				Tools::setHighlighted(label_2gb, false);
				Tools::setHighlighted(label_4gb, false);
				Tools::setHighlighted(label_8gb, true);
				selectedAnswer = 4;
			}
		}

		System::Void onShown(System::Object^ sender, System::EventArgs^ e)
		{
			// Choose default value
			Tools::setHighlighted(label_1gb, true);
		}

		System::Void button_next_click(System::Object^ sender, System::EventArgs^ e)
		{
			UserAnswers::Instance->setAnswerResult(7, Tools::handleAnswerSeven(selectedAnswer));

			Form^ next = gcnew QuestionEight();
			this->Hide();
			next->Show();
		}
	};
}

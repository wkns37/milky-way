#pragma once
#include "QuestionFifteen.h"

namespace Coursework {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace CourseworkLibrary;
	/// <summary>
	/// Summary for QuestionFourteen1
	/// </summary>
	public ref class QuestionFourteen : public System::Windows::Forms::Form
	{
	public:
		QuestionFourteen(void)
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
		~QuestionFourteen()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^ groupBox2;
	protected:
	private: System::Windows::Forms::RadioButton^ radio_two;
	private: System::Windows::Forms::RadioButton^ radio_one;
	private: System::Windows::Forms::Button^ button_next;
	private: System::Windows::Forms::Label^ label1;
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
			   System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(QuestionFourteen::typeid));
			   this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			   this->radio_two = (gcnew System::Windows::Forms::RadioButton());
			   this->radio_one = (gcnew System::Windows::Forms::RadioButton());
			   this->button_next = (gcnew System::Windows::Forms::Button());
			   this->label1 = (gcnew System::Windows::Forms::Label());
			   this->groupBox2->SuspendLayout();
			   this->SuspendLayout();
			   // 
			   // groupBox2
			   // 
			   this->groupBox2->Anchor = System::Windows::Forms::AnchorStyles::None;
			   this->groupBox2->AutoSize = true;
			   this->groupBox2->Controls->Add(this->radio_two);
			   this->groupBox2->Controls->Add(this->radio_one);
			   this->groupBox2->Location = System::Drawing::Point(357, 249);
			   this->groupBox2->Name = L"groupBox2";
			   this->groupBox2->Size = System::Drawing::Size(175, 125);
			   this->groupBox2->TabIndex = 0;
			   this->groupBox2->TabStop = false;
			   this->groupBox2->Text = L"�������� �������";
			   // 
			   // radio_two
			   // 
			   this->radio_two->AutoSize = true;
			   this->radio_two->Location = System::Drawing::Point(6, 66);
			   this->radio_two->Name = L"radio_two";
			   this->radio_two->Size = System::Drawing::Size(133, 29);
			   this->radio_two->TabIndex = 2;
			   this->radio_two->TabStop = true;
			   this->radio_two->Text = L"����������";
			   this->radio_two->UseVisualStyleBackColor = true;
			   // 
			   // radio_one
			   // 
			   this->radio_one->AutoSize = true;
			   this->radio_one->Location = System::Drawing::Point(6, 30);
			   this->radio_one->Name = L"radio_one";
			   this->radio_one->Size = System::Drawing::Size(131, 29);
			   this->radio_one->TabIndex = 1;
			   this->radio_one->TabStop = true;
			   this->radio_one->Text = L"����������";
			   this->radio_one->UseVisualStyleBackColor = true;
			   // 
			   // button_next
			   // 
			   this->button_next->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			   this->button_next->AutoSize = true;
			   this->button_next->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			   this->button_next->Location = System::Drawing::Point(842, 502);
			   this->button_next->Name = L"button_next";
			   this->button_next->Size = System::Drawing::Size(34, 35);
			   this->button_next->TabIndex = 3;
			   this->button_next->Text = L">";
			   this->button_next->UseVisualStyleBackColor = true;
			   this->button_next->Click += gcnew System::EventHandler(this, &QuestionFourteen::button_next_click);
			   // 
			   // label1
			   // 
			   this->label1->Anchor = System::Windows::Forms::AnchorStyles::Top;
			   this->label1->AutoSize = true;
			   this->label1->Location = System::Drawing::Point(127, 9);
			   this->label1->Name = L"label1";
			   this->label1->Size = System::Drawing::Size(634, 75);
			   this->label1->TabIndex = 0;
			   this->label1->Text = L"�� ����� �������� ������ ������������ ������ �������� �����������\r\n��������� ���"
				   L"������ ����������� ������ � ������� � �� Windows\r\n����������� _________ ��������"
				   L"��� ������";
			   this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			   // 
			   // QuestionFourteen
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(10, 25);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->ClientSize = System::Drawing::Size(888, 549);
			   this->Controls->Add(this->groupBox2);
			   this->Controls->Add(this->button_next);
			   this->Controls->Add(this->label1);
			   this->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			   this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			   this->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			   this->MaximizeBox = false;
			   this->Name = L"QuestionFourteen";
			   this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			   this->Text = L"������ 14";
			   this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &QuestionFourteen::button_exit_click);
			   this->groupBox2->ResumeLayout(false);
			   this->groupBox2->PerformLayout();
			   this->ResumeLayout(false);
			   this->PerformLayout();

		   }
#pragma endregion

	private:

		System::Void button_exit_click(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e)
		{
			Tools::handleExitButton(e, "����� �� ��������� ������� �� ����� ������ " +
				"��������� ������������.\n�� ������������� ������ �����?");
		}

		System::Void button_next_click(System::Object^ sender, System::EventArgs^ e)
		{
			UserAnswers::Instance->setAnswerResult(14, Tools::handleAnswerFourteen(radio_two));

			Form^ next = gcnew QuestionFifteen();
			this->Hide();
			next->Show();
		}
	};
}

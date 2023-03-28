#pragma once
#include "user/User.h"

namespace Coursework {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace CourseworkLibrary;
	/// <summary>
	/// Summary for Auth
	/// </summary>
	public ref class Auth : public System::Windows::Forms::Form
	{
	private:
		Form ^parent, ^next;
	private: System::Windows::Forms::Label^ label5;
	public:
		Auth(Form^ parent, Form^ next)
		{
			this->parent = parent;
			this->next = next;
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Auth()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^ groupBox1;
	protected:
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ field_password;
	private: System::Windows::Forms::Button^ button_start;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ field_username;
	private: System::Windows::Forms::ToolTip^ toolTip2;
	private: System::Windows::Forms::ToolTip^ toolTip1;
	private: System::ComponentModel::IContainer^ components;

	private:
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
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Auth::typeid));
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->field_password = (gcnew System::Windows::Forms::TextBox());
			this->button_start = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->field_username = (gcnew System::Windows::Forms::TextBox());
			this->toolTip1 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->toolTip2 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// groupBox1
			// 
			this->groupBox1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->groupBox1->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->field_password);
			this->groupBox1->Controls->Add(this->button_start);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->field_username);
			this->groupBox1->Location = System::Drawing::Point(142, 79);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(235, 226);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Авторизация";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(6, 85);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(63, 21);
			this->label4->TabIndex = 0;
			this->label4->Text = L"Пароль";
			this->toolTip2->SetToolTip(this->label4, L"password1324");
			// 
			// field_password
			// 
			this->field_password->Location = System::Drawing::Point(6, 109);
			this->field_password->Name = L"field_password";
			this->field_password->PasswordChar = '*';
			this->field_password->Size = System::Drawing::Size(223, 31);
			this->field_password->TabIndex = 2;
			// 
			// button_start
			// 
			this->button_start->Location = System::Drawing::Point(6, 146);
			this->button_start->Name = L"button_start";
			this->button_start->Size = System::Drawing::Size(223, 50);
			this->button_start->TabIndex = 3;
			this->button_start->Text = L"НАЧАТЬ РАБОТУ";
			this->button_start->UseVisualStyleBackColor = true;
			this->button_start->Click += gcnew System::EventHandler(this, &Auth::button_start_click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(6, 27);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(142, 21);
			this->label3->TabIndex = 0;
			this->label3->Text = L"Имя пользователя";
			this->toolTip1->SetToolTip(this->label3, L"Имя пользователя будет использовано для вывода результатов тестирования");
			// 
			// field_username
			// 
			this->field_username->Location = System::Drawing::Point(6, 51);
			this->field_username->Name = L"field_username";
			this->field_username->Size = System::Drawing::Size(223, 31);
			this->field_username->TabIndex = 1;
			// 
			// label5
			// 
			this->label5->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->label5->AutoSize = true;
			this->label5->Enabled = false;
			this->label5->Location = System::Drawing::Point(28, 325);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(462, 50);
			this->label5->TabIndex = 0;
			this->label5->Text = L"Наведите курсор на соответствующие названия полей\r\nдля получения дополнительной и"
				L"нформации";
			this->label5->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// Auth
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(10, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(518, 384);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->groupBox1);
			this->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->MaximizeBox = false;
			this->Name = L"Auth";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Авторизация";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &Auth::button_exit_click);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private:

		System::Void button_exit_click(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e)
		{
			this->Hide();
			parent->Show();
		}

		System::Void button_start_click(System::Object^ sender, System::EventArgs^ e)
		{
			String^ username = field_username->Text->Trim();

			if (Tools::isCredentialsValid(field_username, field_password))
			{
				User^ user = User::Instance;
				// Проверяем, правильно ли пользователь ввел свои данные второй раз
				if (!user->checkAuth(username))
				{
					Tools::showErrorBox("Введенное имя пользователя не совпадает с именем, зарегистрированным " +
						"ранее!\nПроверьте корректность ввода.");
					return;
				}
				
				User::Instance->logIn(username);
				Tools::showInfoBox("Аутентификация выполнена успешно!");
				
				parent->Hide();
				this->Hide();
				next->Show();
			}
		}
	};
}

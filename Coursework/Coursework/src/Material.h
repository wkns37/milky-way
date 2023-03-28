#pragma once
#include "Auth.h"
#include "questions/QuestionOne.h"

namespace Coursework {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace CourseworkLibrary;

	/// <summary>
	/// Summary for Material
	/// </summary>
	public ref class Material : public System::Windows::Forms::Form
	{
	private:
		
	public:
		Material(void)
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
		~Material()
		{
			if (components)
			{
				delete components;
			}
		}


	private: System::Windows::Forms::WebBrowser^ material_view;
	private: System::Windows::Forms::Button^ button_start;

	protected:

	protected:

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Material::typeid));
			this->material_view = (gcnew System::Windows::Forms::WebBrowser());
			this->button_start = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// material_view
			// 
			this->material_view->Dock = System::Windows::Forms::DockStyle::Fill;
			this->material_view->Location = System::Drawing::Point(0, 0);
			this->material_view->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->material_view->MinimumSize = System::Drawing::Size(22, 25);
			this->material_view->Name = L"material_view";
			this->material_view->Size = System::Drawing::Size(1231, 980);
			this->material_view->TabIndex = 0;
			// 
			// button_start
			// 
			this->button_start->AutoSize = true;
			this->button_start->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->button_start->Location = System::Drawing::Point(0, 980);
			this->button_start->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->button_start->Name = L"button_start";
			this->button_start->Size = System::Drawing::Size(1231, 35);
			this->button_start->TabIndex = 1;
			this->button_start->Text = L"НАЧАТЬ ТЕСТИРОВАНИЕ";
			this->button_start->UseVisualStyleBackColor = true;
			this->button_start->Click += gcnew System::EventHandler(this, &Material::startQuiz);
			// 
			// Material
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(10, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1231, 1015);
			this->Controls->Add(this->material_view);
			this->Controls->Add(this->button_start);
			this->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->Name = L"Material";
			this->Text = L"Теоретический материал";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &Material::button_exit_click);
			this->Shown += gcnew System::EventHandler(this, &Material::onShown);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private:

		System::Void button_exit_click(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e)
		{
			Application::Exit();
		}

		System::Void startQuiz(System::Object^ sender, System::EventArgs^ e)
		{
			Form^ question = gcnew QuestionOne();
			Auth^ auth = gcnew Auth(this, question);
			auth->Show();
		}
	
		void showInfo()
		{
			Tools::showInfoBox("На данной странице можно ознакомиться с теоретической частью материала. " +
				"Нажмите кнопку внизу окна, если хотите проверить свои знания по изученному материалу.");
		}

		System::Void onShown(System::Object^ sender, System::EventArgs^ e)
		{
			if (!Tools::loadMaterial(material_view, "data.mht"))
				Application::Exit();

			showInfo();
		}
	};
}

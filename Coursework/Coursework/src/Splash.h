#pragma once
#include "Material.h"

namespace Coursework {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Splash
	/// </summary>
	public ref class Splash : public System::Windows::Forms::Form
	{
	public:
		Splash(void)
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
		~Splash()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Timer^ timer;

	private: System::ComponentModel::IContainer^ components;
	protected:

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Splash::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->timer = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->ForeColor = System::Drawing::SystemColors::ActiveCaption;
			this->label1->Location = System::Drawing::Point(12, 646);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(697, 65);
			this->label1->TabIndex = 0;
			this->label1->Text = L"ÎÏÅÐÀÖÈÎÍÍÛÅ ÑÈÑÒÅÌÛ";
			// 
			// timer
			// 
			this->timer->Interval = 2000;
			this->timer->Tick += gcnew System::EventHandler(this, &Splash::timer_tick);
			// 
			// Splash
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->ClientSize = System::Drawing::Size(1280, 720);
			this->ControlBox = false;
			this->Controls->Add(this->label1);
			this->DoubleBuffered = true;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"Splash";
			this->ShowIcon = false;
			this->ShowInTaskbar = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Çàãðóçî÷íûé ýêðàí";
			this->Load += gcnew System::EventHandler(this, &Splash::onShown);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private:

		void step()
		{
			Application::Run(gcnew Material());
		}
		
		System::Void onShown(System::Object^ sender, System::EventArgs^ e)
		{
			timer->Start();
		}

		System::Void timer_tick(System::Object^ sender, System::EventArgs^ e)
		{
			timer->Stop();
			Form^ material = gcnew Material();
			this->Hide();
			material->Show();
		}
	};
}

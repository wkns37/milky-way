#pragma once
#include "../user/User.h"
#include "../database/UserAnswers.h"

namespace Coursework {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace CourseworkLibrary;

	/// <summary>
	/// Summary for Results
	/// </summary>
	public ref class Results : public System::Windows::Forms::Form
	{
	private:
		String^ timestamp = DateTime::Now.ToString("yyyyMMdd_HHmmssfff");
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Button^ button_save_as_xls;


		   array<bool>^ answers = UserAnswers::Instance->getAnswers();

	public:
		Results(void)
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
		~Results()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ result_dgv;
	private: System::Windows::Forms::Label^ label_title;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ result_chart;

	private: System::Windows::Forms::Button^ button_save_as_txt;
	private: System::Windows::Forms::Button^ button_save_as_db;
	private: System::Windows::Forms::Button^ button_save_as_doc;
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
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Results::typeid));
			this->result_dgv = (gcnew System::Windows::Forms::DataGridView());
			this->label_title = (gcnew System::Windows::Forms::Label());
			this->button_save_as_txt = (gcnew System::Windows::Forms::Button());
			this->button_save_as_db = (gcnew System::Windows::Forms::Button());
			this->button_save_as_doc = (gcnew System::Windows::Forms::Button());
			this->result_chart = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->button_save_as_xls = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->result_dgv))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->result_chart))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// result_dgv
			// 
			this->result_dgv->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::AllCells;
			this->result_dgv->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::AllCells;
			this->result_dgv->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->result_dgv->ColumnHeadersVisible = false;
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle1->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			dataGridViewCellStyle1->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->result_dgv->DefaultCellStyle = dataGridViewCellStyle1;
			this->result_dgv->Location = System::Drawing::Point(460, 32);
			this->result_dgv->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->result_dgv->Name = L"result_dgv";
			this->result_dgv->RowHeadersVisible = false;
			this->result_dgv->RowHeadersWidth = 62;
			this->result_dgv->ScrollBars = System::Windows::Forms::ScrollBars::None;
			this->result_dgv->Size = System::Drawing::Size(212, 448);
			this->result_dgv->TabIndex = 0;
			// 
			// label_title
			// 
			this->label_title->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label_title->BackColor = System::Drawing::Color::Transparent;
			this->label_title->Location = System::Drawing::Point(12, 9);
			this->label_title->Name = L"label_title";
			this->label_title->Size = System::Drawing::Size(1198, 36);
			this->label_title->TabIndex = 0;
			this->label_title->Text = L"PLACEHOLDER";
			this->label_title->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// button_save_as_txt
			// 
			this->button_save_as_txt->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->button_save_as_txt->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->button_save_as_txt->Location = System::Drawing::Point(12, 867);
			this->button_save_as_txt->Name = L"button_save_as_txt";
			this->button_save_as_txt->Size = System::Drawing::Size(430, 35);
			this->button_save_as_txt->TabIndex = 2;
			this->button_save_as_txt->Text = L"ÑÎÕÐÀÍÈÒÜ ÐÅÇÓËÜÒÀÒ Â ÒÅÑÒÎÂÛÉ ÄÎÊÓÌÅÍÒ";
			this->button_save_as_txt->UseVisualStyleBackColor = true;
			this->button_save_as_txt->Click += gcnew System::EventHandler(this, &Results::save_as_txt);
			// 
			// button_save_as_db
			// 
			this->button_save_as_db->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->button_save_as_db->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->button_save_as_db->Location = System::Drawing::Point(12, 826);
			this->button_save_as_db->Name = L"button_save_as_db";
			this->button_save_as_db->Size = System::Drawing::Size(430, 35);
			this->button_save_as_db->TabIndex = 1;
			this->button_save_as_db->Text = L"ÑÎÕÐÀÍÈÒÜ ÐÅÇÓËÜÒÀÒ Â ÁÀÇÓ ÄÀÍÍÛÕ";
			this->button_save_as_db->UseVisualStyleBackColor = true;
			this->button_save_as_db->Click += gcnew System::EventHandler(this, &Results::save_as_db);
			// 
			// button_save_as_doc
			// 
			this->button_save_as_doc->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->button_save_as_doc->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->button_save_as_doc->Location = System::Drawing::Point(448, 826);
			this->button_save_as_doc->Name = L"button_save_as_doc";
			this->button_save_as_doc->Size = System::Drawing::Size(511, 35);
			this->button_save_as_doc->TabIndex = 3;
			this->button_save_as_doc->Text = L"ÎÒÊÐÛÒÜ ÐÅÇÓËÜÒÀÒ Â ÄÎÊÓÌÅÍÒÅ MICROSOFT WORD";
			this->button_save_as_doc->UseVisualStyleBackColor = true;
			this->button_save_as_doc->Click += gcnew System::EventHandler(this, &Results::save_as_doc);
			// 
			// result_chart
			// 
			chartArea1->Name = L"ChartArea1";
			this->result_chart->ChartAreas->Add(chartArea1);
			legend1->Name = L"Legend1";
			this->result_chart->Legends->Add(legend1);
			this->result_chart->Location = System::Drawing::Point(6, 31);
			this->result_chart->Name = L"result_chart";
			series1->ChartArea = L"ChartArea1";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Pie;
			series1->Legend = L"Legend1";
			series1->Name = L"Series";
			this->result_chart->Series->Add(series1);
			this->result_chart->Size = System::Drawing::Size(448, 448);
			this->result_chart->TabIndex = 0;
			this->result_chart->Text = L"chart1";
			// 
			// groupBox1
			// 
			this->groupBox1->AutoSize = true;
			this->groupBox1->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->groupBox1->Controls->Add(this->result_chart);
			this->groupBox1->Controls->Add(this->result_dgv);
			this->groupBox1->Location = System::Drawing::Point(272, 202);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(678, 511);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Ðåçóëüòàòû";
			// 
			// button_save_as_xls
			// 
			this->button_save_as_xls->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->button_save_as_xls->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->button_save_as_xls->Location = System::Drawing::Point(448, 867);
			this->button_save_as_xls->Name = L"button_save_as_xls";
			this->button_save_as_xls->Size = System::Drawing::Size(511, 35);
			this->button_save_as_xls->TabIndex = 4;
			this->button_save_as_xls->Text = L"ÎÒÊÐÛÒÜ ÐÅÇÓËÜÒÀÒ Â ÄÎÊÓÌÅÍÒÅ MICROSOFT EXCEL";
			this->button_save_as_xls->UseVisualStyleBackColor = true;
			this->button_save_as_xls->Click += gcnew System::EventHandler(this, &Results::save_as_xls);
			// 
			// Results
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(10, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1222, 914);
			this->Controls->Add(this->button_save_as_xls);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->button_save_as_doc);
			this->Controls->Add(this->button_save_as_txt);
			this->Controls->Add(this->button_save_as_db);
			this->Controls->Add(this->label_title);
			this->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->Name = L"Results";
			this->Text = L"Ðåçóëüòàòû òåñòèðîâàíèÿ";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &Results::button_exit_click);
			this->Load += gcnew System::EventHandler(this, &Results::onLoad);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->result_dgv))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->result_chart))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private:

		System::Void button_exit_click(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e)
		{
			Application::Exit();
		}

		System::Void save_as_db(System::Object^ sender, System::EventArgs^ e)
		{
			String^ tmp = button_save_as_db->Text;
			button_save_as_db->Text = L"ÑÎÕÐÀÍÅÍÈÅ...";
			this->Enabled = false;
			
			Tools::write_to_db(answers, timestamp);
			
			this->Enabled = true;
			button_save_as_db->Text = tmp;
		}
		
		System::Void save_as_txt(System::Object^ sender, System::EventArgs^ e)
		{
			Tools::write_to_notepad(answers, timestamp);
		}
		
		System::Void save_as_doc(System::Object^ sender, System::EventArgs^ e)
		{
			Tools::write_to_word(answers);
		}
		
		System::Void save_as_xls(System::Object^ sender, System::EventArgs^ e)
		{
			Tools::write_to_excel(answers);
		}

		System::Void onLoad(System::Object^ sender, System::EventArgs^ e)
		{
			label_title->Text = "Íà äàííîé ñòðàíèöå Âû, " + User::Instance->getName() +
				", ìîæåòå îçíàêîìèòüñÿ ñ ðåçóëüòàòàìè òåñòèðîâàíèÿ";
			
			double percentage = UserAnswers::Instance->getPercentage();
			Tools::showResults(result_dgv, answers);
			Tools::showResults(result_chart, percentage);
			Tools::setBackgroundColor(this, percentage);
		}
	};
}

#pragma once
#include "UI_result.h"
#include "Dataset.h"
#define version "v1.3"

namespace SeriesHandler {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// //////////////////////////////////////////////////////////////////

	public ref class UI : public System::Windows::Forms::Form
	{
	/// //////////////////////////////////////////////////////////////////
#pragma region Form base

	private:
		Dataset^ dataset;
	public:
		UI(void)
		{
			InitializeComponent();
			dataset = gcnew Dataset();
		}
	protected:
		~UI()
		{
			if (components)
			{
				delete components;
			}
			delete dataset;
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::RichTextBox^ richTextBox1;
	private: System::Windows::Forms::RadioButton^ radioButton_extend;
	private: System::Windows::Forms::RadioButton^ radioButton_merge;
	private: System::Windows::Forms::RadioButton^ radioButton_delspc;
	private: System::Windows::Forms::CheckBox^ checkBox_cut;


	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::RadioButton^ radioButton_none;


	private:
		System::ComponentModel::Container^ components;


#pragma endregion
		/// //////////////////////////////////////////////////////////////////


		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(UI::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->radioButton_extend = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton_merge = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton_delspc = (gcnew System::Windows::Forms::RadioButton());
			this->checkBox_cut = (gcnew System::Windows::Forms::CheckBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->radioButton_none = (gcnew System::Windows::Forms::RadioButton());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(79, 9);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(171, 18);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Выберите операцию:";
			// 
			// richTextBox1
			// 
			this->richTextBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Right));
			this->richTextBox1->BackColor = System::Drawing::SystemColors::Window;
			this->richTextBox1->Location = System::Drawing::Point(366, 1);
			this->richTextBox1->Margin = System::Windows::Forms::Padding(4);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(413, 457);
			this->richTextBox1->TabIndex = 1;
			this->richTextBox1->Text = L"";
			// 
			// radioButton_extend
			// 
			this->radioButton_extend->AutoSize = true;
			this->radioButton_extend->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->radioButton_extend->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->radioButton_extend->Location = System::Drawing::Point(13, 79);
			this->radioButton_extend->Margin = System::Windows::Forms::Padding(4);
			this->radioButton_extend->Name = L"radioButton_extend";
			this->radioButton_extend->Size = System::Drawing::Size(191, 23);
			this->radioButton_extend->TabIndex = 2;
			this->radioButton_extend->Text = L"Протягивание серий";
			this->radioButton_extend->UseVisualStyleBackColor = true;
			// 
			// radioButton_merge
			// 
			this->radioButton_merge->AutoSize = true;
			this->radioButton_merge->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->radioButton_merge->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->radioButton_merge->Location = System::Drawing::Point(13, 132);
			this->radioButton_merge->Margin = System::Windows::Forms::Padding(4);
			this->radioButton_merge->Name = L"radioButton_merge";
			this->radioButton_merge->Size = System::Drawing::Size(267, 23);
			this->radioButton_merge->TabIndex = 3;
			this->radioButton_merge->Text = L"Попарное объединение серий";
			this->radioButton_merge->UseVisualStyleBackColor = true;
			// 
			// radioButton_delspc
			// 
			this->radioButton_delspc->AutoSize = true;
			this->radioButton_delspc->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->radioButton_delspc->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->radioButton_delspc->Location = System::Drawing::Point(13, 186);
			this->radioButton_delspc->Margin = System::Windows::Forms::Padding(4);
			this->radioButton_delspc->Name = L"radioButton_delspc";
			this->radioButton_delspc->Size = System::Drawing::Size(237, 23);
			this->radioButton_delspc->TabIndex = 4;
			this->radioButton_delspc->Text = L"Удаление спец. символов";
			this->radioButton_delspc->UseVisualStyleBackColor = true;
			// 
			// checkBox_cut
			// 
			this->checkBox_cut->AutoSize = true;
			this->checkBox_cut->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->checkBox_cut->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->checkBox_cut->Location = System::Drawing::Point(13, 303);
			this->checkBox_cut->Margin = System::Windows::Forms::Padding(4);
			this->checkBox_cut->Name = L"checkBox_cut";
			this->checkBox_cut->Size = System::Drawing::Size(272, 23);
			this->checkBox_cut->TabIndex = 5;
			this->checkBox_cut->Text = L"Очистка данных с Манхэттана";
			this->checkBox_cut->UseVisualStyleBackColor = true;
			this->checkBox_cut->CheckedChanged += gcnew System::EventHandler(this, &UI::checkBox_cut_CheckedChanged);
			// 
			// button1
			// 
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(82, 362);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(152, 66);
			this->button1->TabIndex = 6;
			this->button1->Text = L"Выполнить";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &UI::button1_Click);
			// 
			// radioButton_none
			// 
			this->radioButton_none->AutoSize = true;
			this->radioButton_none->Checked = true;
			this->radioButton_none->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->radioButton_none->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->radioButton_none->Location = System::Drawing::Point(13, 245);
			this->radioButton_none->Margin = System::Windows::Forms::Padding(4);
			this->radioButton_none->Name = L"radioButton_none";
			this->radioButton_none->Size = System::Drawing::Size(170, 23);
			this->radioButton_none->TabIndex = 7;
			this->radioButton_none->TabStop = true;
			this->radioButton_none->Text = L"Не обрабатывать";
			this->radioButton_none->UseVisualStyleBackColor = true;
			// 
			// UI
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->ClientSize = System::Drawing::Size(784, 461);
			this->Controls->Add(this->radioButton_none);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->checkBox_cut);
			this->Controls->Add(this->radioButton_delspc);
			this->Controls->Add(this->radioButton_merge);
			this->Controls->Add(this->radioButton_extend);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->label1);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(4);
			this->MaximizeBox = false;
			this->Name = L"UI";
			this->Text = L"Series Handler" + " " + version;
			this->ResumeLayout(false);
			this->PerformLayout();

		}


		/// //////////////////////////////////////////////////////////////////


	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

		dataset->Write(this->richTextBox1->Text);
		SeriesHandler::UI_result ui_result;

		/// //////////////////////////////////////////////////////////////////

		if (this->checkBox_cut->Checked)
			dataset->Cut();
		if (this->radioButton_extend->Checked)
			dataset->Extend();
		if (this->radioButton_merge->Checked)
			dataset->Merge();
		if (this->radioButton_delspc->Checked)
			dataset->Delsmb();

		/// //////////////////////////////////////////////////////////////////

		ui_result.write_result(dataset->Get());
		dataset->Clear();
		ui_result.ShowDialog();
	}
	private: System::Void checkBox_cut_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}

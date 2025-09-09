#pragma once

namespace SeriesHandler {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	/// //////////////////////////////////////////////////////////////////


	public ref class UI_result : public System::Windows::Forms::Form
	{
#pragma region Form base
	public:
		UI_result(void)
		{
			InitializeComponent();
		}

	protected:
		~UI_result()
		{
			if (components)
			{
				delete components;
			}
		}
#pragma endregion
	/// //////////////////////////////////////////////////////////////////

#pragma region Form Components
	private: System::Windows::Forms::RichTextBox^ richTextBox1;
	private:
		System::ComponentModel::Container ^components;

		void InitializeComponent(void)
		{
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->SuspendLayout();
			// 
			// richTextBox1
			// 
			this->richTextBox1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->richTextBox1->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->richTextBox1->Location = System::Drawing::Point(0, 0);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(484, 761);
			this->richTextBox1->TabIndex = 0;
			this->richTextBox1->Text = L"";
			this->richTextBox1->TextChanged += gcnew System::EventHandler(this, &UI_result::richTextBox1_TextChanged);
			// 
			// UI_result
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(484, 761);
			this->Controls->Add(this->richTextBox1);
			this->Name = L"UI_result";
			this->Text = L"UI_result";
			this->ResumeLayout(false);

		}
#pragma endregion

	/// //////////////////////////////////////////////////////////////////

	public: void write_result(String^ value) {
		this->richTextBox1->Clear();
		this->richTextBox1->Text = value;
		this->richTextBox1->Refresh();
		}
	private: System::Void richTextBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}

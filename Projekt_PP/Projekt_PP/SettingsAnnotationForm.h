#pragma once

namespace Projekt_PP {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for SettingsAnnotationForm
	/// </summary>
	public ref class SettingsAnnotationForm : public System::Windows::Forms::Form
	{
	public:
		SettingsAnnotationForm(void)
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
		~SettingsAnnotationForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Button^  OK_button;
	private: System::Windows::Forms::Button^  cancel_button;
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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->OK_button = (gcnew System::Windows::Forms::Button());
			this->cancel_button = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(35, 14);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(116, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Enter number of points:";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(38, 30);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(113, 20);
			this->textBox1->TabIndex = 1;
			// 
			// OK_button
			// 
			this->OK_button->Location = System::Drawing::Point(12, 56);
			this->OK_button->Name = L"OK_button";
			this->OK_button->Size = System::Drawing::Size(75, 23);
			this->OK_button->TabIndex = 2;
			this->OK_button->Text = L"Ok";
			this->OK_button->UseVisualStyleBackColor = true;
			// 
			// cancel_button
			// 
			this->cancel_button->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->cancel_button->Location = System::Drawing::Point(93, 56);
			this->cancel_button->Name = L"cancel_button";
			this->cancel_button->Size = System::Drawing::Size(75, 23);
			this->cancel_button->TabIndex = 3;
			this->cancel_button->Text = L"Cancel";
			this->cancel_button->UseVisualStyleBackColor = true;
			// 
			// SettingsAnnotationForm
			// 
			this->AcceptButton = this->OK_button;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->CancelButton = this->cancel_button;
			this->ClientSize = System::Drawing::Size(184, 85);
			this->Controls->Add(this->cancel_button);
			this->Controls->Add(this->OK_button);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"SettingsAnnotationForm";
			this->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->Text = L"SettingsAnnotationForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	};
}

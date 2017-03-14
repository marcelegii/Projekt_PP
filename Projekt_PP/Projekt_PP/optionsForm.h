#pragma once

namespace Projekt_PP {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for optionsForm
	/// </summary>
	public ref class optionsForm : public System::Windows::Forms::Form
	{
	public:
		optionsForm(void)
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
		~optionsForm()
		{
			if (components)
			{
				delete components;
			}
		}

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
			this->SuspendLayout();
			// 
			// optionsForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 262);
			this->Name = L"optionsForm";
			this->Text = L"optionsForm";
			this->Load += gcnew System::EventHandler(this, &optionsForm::optionsForm_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void optionsForm_Load(System::Object^  sender, System::EventArgs^  e) {
		MessageBox::Show("dupa");
	}
	};
}

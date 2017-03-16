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
	private: System::Windows::Forms::TextBox^  sliceNameTextBox;
	protected:
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  butApplySliceName;
	private: System::Windows::Forms::CheckBox^  chBoxNegative;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Button^  butApplyScale;
	private: System::Windows::Forms::Button^  butApplyThreshold;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::TextBox^  textBox5;
	private: System::Windows::Forms::TextBox^  textBox6;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::CheckBox^  chBoxMode;
	private: System::Windows::Forms::CheckBox^  chBoxFast_Slow;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::TextBox^  textBox7;
	private: System::Windows::Forms::Button^  butApplySDA;
	private: System::Windows::Forms::Button^  butApplySize;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::Panel^  panel6;
	private: System::Windows::Forms::Panel^  panel5;
	private: System::Windows::Forms::Panel^  panel3;
	private: System::Windows::Forms::Panel^  panel4;
	private: System::Windows::Forms::Panel^  panel7;
	private: System::Windows::Forms::Panel^  panel8;

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
			this->sliceNameTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->butApplySliceName = (gcnew System::Windows::Forms::Button());
			this->chBoxNegative = (gcnew System::Windows::Forms::CheckBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->butApplyScale = (gcnew System::Windows::Forms::Button());
			this->butApplyThreshold = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->chBoxMode = (gcnew System::Windows::Forms::CheckBox());
			this->chBoxFast_Slow = (gcnew System::Windows::Forms::CheckBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->butApplySDA = (gcnew System::Windows::Forms::Button());
			this->butApplySize = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->panel6 = (gcnew System::Windows::Forms::Panel());
			this->panel7 = (gcnew System::Windows::Forms::Panel());
			this->panel8 = (gcnew System::Windows::Forms::Panel());
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->panel4->SuspendLayout();
			this->panel7->SuspendLayout();
			this->panel8->SuspendLayout();
			this->SuspendLayout();
			// 
			// sliceNameTextBox
			// 
			this->sliceNameTextBox->Location = System::Drawing::Point(9, 17);
			this->sliceNameTextBox->Name = L"sliceNameTextBox";
			this->sliceNameTextBox->Size = System::Drawing::Size(77, 20);
			this->sliceNameTextBox->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->label1->Location = System::Drawing::Point(16, -1);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(63, 15);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Slice Name";
			// 
			// butApplySliceName
			// 
			this->butApplySliceName->Location = System::Drawing::Point(9, 43);
			this->butApplySliceName->Name = L"butApplySliceName";
			this->butApplySliceName->Size = System::Drawing::Size(75, 23);
			this->butApplySliceName->TabIndex = 2;
			this->butApplySliceName->Text = L"Apply";
			this->butApplySliceName->UseVisualStyleBackColor = true;
			// 
			// chBoxNegative
			// 
			this->chBoxNegative->AutoSize = true;
			this->chBoxNegative->Location = System::Drawing::Point(12, 15);
			this->chBoxNegative->Name = L"chBoxNegative";
			this->chBoxNegative->Size = System::Drawing::Size(69, 17);
			this->chBoxNegative->TabIndex = 3;
			this->chBoxNegative->Text = L"Negative";
			this->chBoxNegative->UseVisualStyleBackColor = true;
			this->chBoxNegative->CheckedChanged += gcnew System::EventHandler(this, &optionsForm::chBoxNegative_CheckedChanged);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(34, 17);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 20);
			this->textBox1->TabIndex = 4;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(69, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(34, 13);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Scale";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(68, 51);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(45, 20);
			this->textBox2->TabIndex = 6;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(6, 54);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(54, 13);
			this->label3->TabIndex = 7;
			this->label3->Text = L"Threshold";
			// 
			// butApplyScale
			// 
			this->butApplyScale->Location = System::Drawing::Point(48, 44);
			this->butApplyScale->Name = L"butApplyScale";
			this->butApplyScale->Size = System::Drawing::Size(75, 23);
			this->butApplyScale->TabIndex = 8;
			this->butApplyScale->Text = L"Apply";
			this->butApplyScale->UseVisualStyleBackColor = true;
			// 
			// butApplyThreshold
			// 
			this->butApplyThreshold->Location = System::Drawing::Point(155, 48);
			this->butApplyThreshold->Name = L"butApplyThreshold";
			this->butApplyThreshold->Size = System::Drawing::Size(75, 23);
			this->butApplyThreshold->TabIndex = 9;
			this->butApplyThreshold->Text = L"Apply";
			this->butApplyThreshold->UseVisualStyleBackColor = true;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(6, 6);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(73, 13);
			this->label4->TabIndex = 10;
			this->label4->Text = L"SDA_Settings";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(68, 37);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(45, 20);
			this->textBox3->TabIndex = 11;
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(68, 63);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(45, 20);
			this->textBox4->TabIndex = 12;
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(68, 89);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(45, 20);
			this->textBox5->TabIndex = 13;
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(68, 115);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(45, 20);
			this->textBox6->TabIndex = 14;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(6, 40);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(40, 13);
			this->label5->TabIndex = 15;
			this->label5->Text = L"Radius";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(6, 66);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(54, 13);
			this->label6->TabIndex = 16;
			this->label6->Text = L"Threshold";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(6, 92);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(61, 13);
			this->label7->TabIndex = 17;
			this->label7->Text = L"Binarisation";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(6, 118);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(29, 13);
			this->label8->TabIndex = 18;
			this->label8->Text = L"Area";
			// 
			// chBoxMode
			// 
			this->chBoxMode->AutoSize = true;
			this->chBoxMode->Location = System::Drawing::Point(155, 39);
			this->chBoxMode->Name = L"chBoxMode";
			this->chBoxMode->Size = System::Drawing::Size(53, 17);
			this->chBoxMode->TabIndex = 19;
			this->chBoxMode->Text = L"Mode";
			this->chBoxMode->UseVisualStyleBackColor = true;
			// 
			// chBoxFast_Slow
			// 
			this->chBoxFast_Slow->AutoSize = true;
			this->chBoxFast_Slow->Location = System::Drawing::Point(155, 66);
			this->chBoxFast_Slow->Name = L"chBoxFast_Slow";
			this->chBoxFast_Slow->Size = System::Drawing::Size(74, 17);
			this->chBoxFast_Slow->TabIndex = 20;
			this->chBoxFast_Slow->Text = L"Fast/Slow";
			this->chBoxFast_Slow->UseVisualStyleBackColor = true;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(4, 1);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(52, 13);
			this->label9->TabIndex = 21;
			this->label9->Text = L"Dendrites";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(19, 28);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(27, 13);
			this->label10->TabIndex = 22;
			this->label10->Text = L"Size";
			// 
			// textBox7
			// 
			this->textBox7->Location = System::Drawing::Point(66, 25);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(45, 20);
			this->textBox7->TabIndex = 23;
			// 
			// butApplySDA
			// 
			this->butApplySDA->Location = System::Drawing::Point(154, 112);
			this->butApplySDA->Name = L"butApplySDA";
			this->butApplySDA->Size = System::Drawing::Size(75, 23);
			this->butApplySDA->TabIndex = 24;
			this->butApplySDA->Text = L"Apply";
			this->butApplySDA->UseVisualStyleBackColor = true;
			// 
			// butApplySize
			// 
			this->butApplySize->Location = System::Drawing::Point(150, 24);
			this->butApplySize->Name = L"butApplySize";
			this->butApplySize->Size = System::Drawing::Size(75, 23);
			this->butApplySize->TabIndex = 25;
			this->butApplySize->Text = L"Apply";
			this->butApplySize->UseVisualStyleBackColor = true;
			// 
			// panel1
			// 
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel1->Controls->Add(this->butApplySDA);
			this->panel1->Controls->Add(this->chBoxFast_Slow);
			this->panel1->Controls->Add(this->chBoxMode);
			this->panel1->Controls->Add(this->label8);
			this->panel1->Controls->Add(this->label7);
			this->panel1->Controls->Add(this->label6);
			this->panel1->Controls->Add(this->label5);
			this->panel1->Controls->Add(this->textBox6);
			this->panel1->Controls->Add(this->textBox5);
			this->panel1->Controls->Add(this->textBox4);
			this->panel1->Controls->Add(this->textBox3);
			this->panel1->Controls->Add(this->label4);
			this->panel1->Location = System::Drawing::Point(1, 170);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(269, 154);
			this->panel1->TabIndex = 26;
			// 
			// panel2
			// 
			this->panel2->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel2->Controls->Add(this->panel6);
			this->panel2->Controls->Add(this->panel5);
			this->panel2->Controls->Add(this->panel3);
			this->panel2->Controls->Add(this->butApplySliceName);
			this->panel2->Controls->Add(this->label1);
			this->panel2->Controls->Add(this->sliceNameTextBox);
			this->panel2->Location = System::Drawing::Point(1, 0);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(113, 76);
			this->panel2->TabIndex = 27;
			// 
			// panel3
			// 
			this->panel3->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel3->Location = System::Drawing::Point(100, -2);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(165, 75);
			this->panel3->TabIndex = 3;
			// 
			// panel4
			// 
			this->panel4->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel4->Controls->Add(this->butApplyScale);
			this->panel4->Controls->Add(this->label2);
			this->panel4->Controls->Add(this->textBox1);
			this->panel4->Location = System::Drawing::Point(103, 0);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(166, 76);
			this->panel4->TabIndex = 28;
			// 
			// panel5
			// 
			this->panel5->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel5->Location = System::Drawing::Point(-4, 72);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(269, 96);
			this->panel5->TabIndex = 4;
			// 
			// panel6
			// 
			this->panel6->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel6->Location = System::Drawing::Point(-4, 73);
			this->panel6->Name = L"panel6";
			this->panel6->Size = System::Drawing::Size(268, 94);
			this->panel6->TabIndex = 5;
			// 
			// panel7
			// 
			this->panel7->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel7->Controls->Add(this->butApplyThreshold);
			this->panel7->Controls->Add(this->label3);
			this->panel7->Controls->Add(this->textBox2);
			this->panel7->Controls->Add(this->chBoxNegative);
			this->panel7->Location = System::Drawing::Point(1, 79);
			this->panel7->Name = L"panel7";
			this->panel7->Size = System::Drawing::Size(268, 89);
			this->panel7->TabIndex = 29;
			// 
			// panel8
			// 
			this->panel8->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel8->Controls->Add(this->butApplySize);
			this->panel8->Controls->Add(this->textBox7);
			this->panel8->Controls->Add(this->label10);
			this->panel8->Controls->Add(this->label9);
			this->panel8->Location = System::Drawing::Point(1, 324);
			this->panel8->Name = L"panel8";
			this->panel8->Size = System::Drawing::Size(268, 60);
			this->panel8->TabIndex = 30;
			// 
			// optionsForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(270, 385);
			this->Controls->Add(this->panel8);
			this->Controls->Add(this->panel4);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel7);
			this->Controls->Add(this->panel1);
			this->Name = L"optionsForm";
			this->Text = L"optionsForm";
			this->Load += gcnew System::EventHandler(this, &optionsForm::optionsForm_Load);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->panel4->ResumeLayout(false);
			this->panel4->PerformLayout();
			this->panel7->ResumeLayout(false);
			this->panel7->PerformLayout();
			this->panel8->ResumeLayout(false);
			this->panel8->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void optionsForm_Load(System::Object^  sender, System::EventArgs^  e) {
		
	}
	
	private: System::Void chBoxNegative_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	}
};
}

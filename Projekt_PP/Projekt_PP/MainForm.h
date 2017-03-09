#pragma once

namespace Projekt_PP {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
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
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^  MenuStrip;
	protected:
	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  openToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  saveAnnotaionToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  saveImageToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  saveDistributionToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  saveCellDestriToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  saveAllToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  saveStateToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  loadStateToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  cellParamsSettingToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  zoomToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  annotationToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  processToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  aboutToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  zoomInToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  zoomOutToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  overviewToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  polyToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  divideSectionToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  referenceToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  relativeX0ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  relativeX100ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  settingsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  exitHMinsFindCellToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  sDACellFinderToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  negativeToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  optionWindowsToolStripMenuItem;

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
			this->MenuStrip = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveAnnotaionToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveImageToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveDistributionToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveCellDestriToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveAllToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveStateToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->loadStateToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->cellParamsSettingToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->zoomToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->zoomInToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->zoomOutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->overviewToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->annotationToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->polyToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->divideSectionToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->referenceToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->relativeX0ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->relativeX100ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->settingsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->processToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitHMinsFindCellToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->sDACellFinderToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->negativeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->optionWindowsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->aboutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->MenuStrip->SuspendLayout();
			this->SuspendLayout();
			// 
			// MenuStrip
			// 
			this->MenuStrip->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				this->fileToolStripMenuItem,
					this->zoomToolStripMenuItem, this->annotationToolStripMenuItem, this->processToolStripMenuItem, this->aboutToolStripMenuItem
			});
			this->MenuStrip->Location = System::Drawing::Point(0, 0);
			this->MenuStrip->Name = L"MenuStrip";
			this->MenuStrip->Size = System::Drawing::Size(448, 24);
			this->MenuStrip->TabIndex = 0;
			this->MenuStrip->Text = L"MenuStrip";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(9) {
				this->openToolStripMenuItem,
					this->saveAnnotaionToolStripMenuItem, this->saveImageToolStripMenuItem, this->saveDistributionToolStripMenuItem, this->saveCellDestriToolStripMenuItem,
					this->saveAllToolStripMenuItem, this->saveStateToolStripMenuItem, this->loadStateToolStripMenuItem, this->cellParamsSettingToolStripMenuItem
			});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// openToolStripMenuItem
			// 
			this->openToolStripMenuItem->Name = L"openToolStripMenuItem";
			this->openToolStripMenuItem->Size = System::Drawing::Size(182, 22);
			this->openToolStripMenuItem->Text = L"Open";
			// 
			// saveAnnotaionToolStripMenuItem
			// 
			this->saveAnnotaionToolStripMenuItem->Name = L"saveAnnotaionToolStripMenuItem";
			this->saveAnnotaionToolStripMenuItem->Size = System::Drawing::Size(182, 22);
			this->saveAnnotaionToolStripMenuItem->Text = L"Save Annotaion";
			// 
			// saveImageToolStripMenuItem
			// 
			this->saveImageToolStripMenuItem->Name = L"saveImageToolStripMenuItem";
			this->saveImageToolStripMenuItem->Size = System::Drawing::Size(182, 22);
			this->saveImageToolStripMenuItem->Text = L"Save Image";
			// 
			// saveDistributionToolStripMenuItem
			// 
			this->saveDistributionToolStripMenuItem->Name = L"saveDistributionToolStripMenuItem";
			this->saveDistributionToolStripMenuItem->Size = System::Drawing::Size(182, 22);
			this->saveDistributionToolStripMenuItem->Text = L"Save Distribution";
			// 
			// saveCellDestriToolStripMenuItem
			// 
			this->saveCellDestriToolStripMenuItem->Name = L"saveCellDestriToolStripMenuItem";
			this->saveCellDestriToolStripMenuItem->Size = System::Drawing::Size(182, 22);
			this->saveCellDestriToolStripMenuItem->Text = L"Save Cell Destription";
			// 
			// saveAllToolStripMenuItem
			// 
			this->saveAllToolStripMenuItem->Name = L"saveAllToolStripMenuItem";
			this->saveAllToolStripMenuItem->Size = System::Drawing::Size(182, 22);
			this->saveAllToolStripMenuItem->Text = L"Save All";
			// 
			// saveStateToolStripMenuItem
			// 
			this->saveStateToolStripMenuItem->Name = L"saveStateToolStripMenuItem";
			this->saveStateToolStripMenuItem->Size = System::Drawing::Size(182, 22);
			this->saveStateToolStripMenuItem->Text = L"Save State";
			// 
			// loadStateToolStripMenuItem
			// 
			this->loadStateToolStripMenuItem->Name = L"loadStateToolStripMenuItem";
			this->loadStateToolStripMenuItem->Size = System::Drawing::Size(182, 22);
			this->loadStateToolStripMenuItem->Text = L"Load State";
			// 
			// cellParamsSettingToolStripMenuItem
			// 
			this->cellParamsSettingToolStripMenuItem->Name = L"cellParamsSettingToolStripMenuItem";
			this->cellParamsSettingToolStripMenuItem->Size = System::Drawing::Size(182, 22);
			this->cellParamsSettingToolStripMenuItem->Text = L"Cell Params Settings";
			// 
			// zoomToolStripMenuItem
			// 
			this->zoomToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->zoomInToolStripMenuItem,
					this->zoomOutToolStripMenuItem, this->overviewToolStripMenuItem
			});
			this->zoomToolStripMenuItem->Enabled = false;
			this->zoomToolStripMenuItem->Name = L"zoomToolStripMenuItem";
			this->zoomToolStripMenuItem->Size = System::Drawing::Size(51, 20);
			this->zoomToolStripMenuItem->Text = L"Zoom";
			// 
			// zoomInToolStripMenuItem
			// 
			this->zoomInToolStripMenuItem->Name = L"zoomInToolStripMenuItem";
			this->zoomInToolStripMenuItem->Size = System::Drawing::Size(127, 22);
			this->zoomInToolStripMenuItem->Text = L"Zoom in";
			// 
			// zoomOutToolStripMenuItem
			// 
			this->zoomOutToolStripMenuItem->Name = L"zoomOutToolStripMenuItem";
			this->zoomOutToolStripMenuItem->Size = System::Drawing::Size(127, 22);
			this->zoomOutToolStripMenuItem->Text = L"Zoom out";
			// 
			// overviewToolStripMenuItem
			// 
			this->overviewToolStripMenuItem->Name = L"overviewToolStripMenuItem";
			this->overviewToolStripMenuItem->Size = System::Drawing::Size(127, 22);
			this->overviewToolStripMenuItem->Text = L"Overview";
			// 
			// annotationToolStripMenuItem
			// 
			this->annotationToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(6) {
				this->polyToolStripMenuItem,
					this->divideSectionToolStripMenuItem, this->referenceToolStripMenuItem, this->relativeX0ToolStripMenuItem, this->relativeX100ToolStripMenuItem,
					this->settingsToolStripMenuItem
			});
			this->annotationToolStripMenuItem->Enabled = false;
			this->annotationToolStripMenuItem->Name = L"annotationToolStripMenuItem";
			this->annotationToolStripMenuItem->Size = System::Drawing::Size(79, 20);
			this->annotationToolStripMenuItem->Text = L"Annotation";
			// 
			// polyToolStripMenuItem
			// 
			this->polyToolStripMenuItem->Name = L"polyToolStripMenuItem";
			this->polyToolStripMenuItem->Size = System::Drawing::Size(187, 22);
			this->polyToolStripMenuItem->Text = L"Poly";
			// 
			// divideSectionToolStripMenuItem
			// 
			this->divideSectionToolStripMenuItem->Name = L"divideSectionToolStripMenuItem";
			this->divideSectionToolStripMenuItem->Size = System::Drawing::Size(187, 22);
			this->divideSectionToolStripMenuItem->Text = L"Divide Section";
			// 
			// referenceToolStripMenuItem
			// 
			this->referenceToolStripMenuItem->Name = L"referenceToolStripMenuItem";
			this->referenceToolStripMenuItem->Size = System::Drawing::Size(187, 22);
			this->referenceToolStripMenuItem->Text = L"Reference  Brightness";
			// 
			// relativeX0ToolStripMenuItem
			// 
			this->relativeX0ToolStripMenuItem->Name = L"relativeX0ToolStripMenuItem";
			this->relativeX0ToolStripMenuItem->Size = System::Drawing::Size(187, 22);
			this->relativeX0ToolStripMenuItem->Text = L"Relative X0";
			// 
			// relativeX100ToolStripMenuItem
			// 
			this->relativeX100ToolStripMenuItem->Name = L"relativeX100ToolStripMenuItem";
			this->relativeX100ToolStripMenuItem->Size = System::Drawing::Size(187, 22);
			this->relativeX100ToolStripMenuItem->Text = L"Relative X100";
			// 
			// settingsToolStripMenuItem
			// 
			this->settingsToolStripMenuItem->Name = L"settingsToolStripMenuItem";
			this->settingsToolStripMenuItem->Size = System::Drawing::Size(187, 22);
			this->settingsToolStripMenuItem->Text = L"Settings";
			// 
			// processToolStripMenuItem
			// 
			this->processToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->exitHMinsFindCellToolStripMenuItem,
					this->sDACellFinderToolStripMenuItem, this->negativeToolStripMenuItem, this->optionWindowsToolStripMenuItem
			});
			this->processToolStripMenuItem->Enabled = false;
			this->processToolStripMenuItem->Name = L"processToolStripMenuItem";
			this->processToolStripMenuItem->Size = System::Drawing::Size(59, 20);
			this->processToolStripMenuItem->Text = L"Process";
			// 
			// exitHMinsFindCellToolStripMenuItem
			// 
			this->exitHMinsFindCellToolStripMenuItem->Name = L"exitHMinsFindCellToolStripMenuItem";
			this->exitHMinsFindCellToolStripMenuItem->Size = System::Drawing::Size(184, 22);
			this->exitHMinsFindCellToolStripMenuItem->Text = L"Exit H-Mins Find Cell";
			// 
			// sDACellFinderToolStripMenuItem
			// 
			this->sDACellFinderToolStripMenuItem->Name = L"sDACellFinderToolStripMenuItem";
			this->sDACellFinderToolStripMenuItem->Size = System::Drawing::Size(184, 22);
			this->sDACellFinderToolStripMenuItem->Text = L"SDA Cell Finder";
			// 
			// negativeToolStripMenuItem
			// 
			this->negativeToolStripMenuItem->Name = L"negativeToolStripMenuItem";
			this->negativeToolStripMenuItem->Size = System::Drawing::Size(184, 22);
			this->negativeToolStripMenuItem->Text = L"Negative";
			// 
			// optionWindowsToolStripMenuItem
			// 
			this->optionWindowsToolStripMenuItem->Name = L"optionWindowsToolStripMenuItem";
			this->optionWindowsToolStripMenuItem->Size = System::Drawing::Size(184, 22);
			this->optionWindowsToolStripMenuItem->Text = L"Option Windows";
			// 
			// aboutToolStripMenuItem
			// 
			this->aboutToolStripMenuItem->Name = L"aboutToolStripMenuItem";
			this->aboutToolStripMenuItem->Size = System::Drawing::Size(52, 20);
			this->aboutToolStripMenuItem->Text = L"About";
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(448, 262);
			this->Controls->Add(this->MenuStrip);
			this->KeyPreview = true;
			this->MainMenuStrip = this->MenuStrip;
			this->Name = L"MainForm";
			this->Text = L"CAS-Cell Annotation Software";
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MainForm::MainForm_KeyDown);
			this->MenuStrip->ResumeLayout(false);
			this->MenuStrip->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MainForm_Load(System::Object^  sender, System::EventArgs^  e) {
	}
	
private: System::Void MainForm_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {

	if (e->Control)
	{
		if (e->KeyCode.ToString() == "O") MessageBox::Show("Open image test");

		else if (e->KeyCode.ToString() == "S") MessageBox::Show("Save Annotation test");
		else if (e->KeyCode.ToString() == "B") MessageBox::Show("Save State test");
		else if (e->KeyCode.ToString() == "N") MessageBox::Show("Load State test");
		else if (e->KeyCode.ToString() == "P") MessageBox::Show("Poly test");
		else if (e->KeyCode.ToString() == "M") MessageBox::Show("Option window test");
		
		
	
	}
}
};
}

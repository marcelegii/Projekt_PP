#include "MainForm.h"

using namespace std;
using namespace System;
using namespace System::Windows::Forms;

[STAThread]
void main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Projekt_PP::MainForm form;
	Application::Run(%form);
}


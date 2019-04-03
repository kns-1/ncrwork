#include "MyForm.h"
using namespace System;
//using namespace System::Windows::Forms;

[STAThread]
int main(array<String^>^ argv)
{
	System::Windows::Forms::Application::EnableVisualStyles();
	System::Windows::Forms::Application::SetCompatibleTextRenderingDefault(false);
	
	WebBrowser::MyForm form;
	System::Windows::Forms::Application::Run(%form);
	
	return 0;
}
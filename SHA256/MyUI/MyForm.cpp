#include "MyForm.h"

using namespace MyUI;
using namespace System;
using namespace System::Windows::Forms;


[STAThreadAttribute]
int main(array<System::String ^>^ args)
{
	// Enabling Windows XP visual effects before any controls are created
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	// Create the main window and run it
	Application::Run(gcnew MyForm());
	
	return 0;
}


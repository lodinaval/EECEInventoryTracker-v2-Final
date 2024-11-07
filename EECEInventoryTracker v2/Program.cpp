#include "LoginPage.h"
#include "MainPage.h"
using namespace System;
using namespace System::Windows::Forms;
using namespace EECEInventoryTrackerv2;

[STAThread]
void main(array<String^>^ args) { // Using System::Array for .NET compatibility
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew LoginPage());
}

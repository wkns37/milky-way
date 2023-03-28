#include "App.h"

namespace Labs
{
	using namespace System;
	using namespace System::Windows::Forms;

	[STAThreadAttribute]
	void main(array<String^>^ args)
	{
		Application::EnableVisualStyles();
		Application::SetCompatibleTextRenderingDefault(false);
		Application::Run(gcnew App());
	}
}
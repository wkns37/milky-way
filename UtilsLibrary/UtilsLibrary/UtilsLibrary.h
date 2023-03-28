#pragma once

using namespace System;

namespace UtilsLibrary {
	public ref class Utils
	{
	public:
		static double getDoubleFromTextBox(System::Windows::Forms::TextBox^ box);
		static void setDataToTextBox(System::Windows::Forms::TextBox^ box, double result);
		static double func1(double x, double y);
		static void func2(double x, double y, double& result);
		static void solve1(double x, double y, double a, double& z, double& branch);
		static double solve2(double x);
		static void solve3(System::Windows::Forms::ListBox^ container, double a, double xn, double xk, double dx, double& sum, double& mlt, double& cnt);
	};
}

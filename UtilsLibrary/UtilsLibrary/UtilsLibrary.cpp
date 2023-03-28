#include "UtilsLibrary.h"
#include <cmath>
#include <algorithm>

double UtilsLibrary::Utils::getDoubleFromTextBox(System::Windows::Forms::TextBox^ box)
{
	return (double)System::Convert::ToDouble(box->Text);
}

void UtilsLibrary::Utils::setDataToTextBox(System::Windows::Forms::TextBox^ box, double result)
{
	box->Text = result.ToString();
}

// Main application
double UtilsLibrary::Utils::func1(double x, double y)
{
	return (1 - tan(x * pow(y, 2))) / (cbrt(x)) + 4 * sqrt(pow(x, 2) - 0.1);
}

void UtilsLibrary::Utils::func2(double x, double y, double& result)
{
	result = (1 - tan(x * pow(y, 2))) / (cbrt(x)) + 4 * sqrt(pow(x, 2) - 0.1);
}

void UtilsLibrary::Utils::solve1(double x, double y, double a, double& z, double& branch)
{
	if (x > 0 && y > 2)
	{
		branch = 1;
		z = a > 0 ? x + sqrt(a) : 0;
		return;
	}

	if (x < 0 && y <= 2)
	{
		branch = 2;
		z = std::min({ a * x, y, sin(x * y) });
		return;
	}

	branch = 3;
	z = std::max({ exp(x), x + a * y });
	return;
}

double UtilsLibrary::Utils::solve2(double x)
{
	return cos(8 * x) / sqrt(1 + 10 * x);
}

double solve3_internal(double a, double x)
{
	return (sqrt(abs(a - x * x) * log(a + x))) / (pow(x * x + pow(a, 1 / 5), 1 / 3));
}

void UtilsLibrary::Utils::solve3(System::Windows::Forms::ListBox^ container, double a, double xn, double xk, double dx, double& sum, double& mlt, double& cnt)
{
	container->Items->Clear();

	double x = xn;
	while (x <= xk)
	{
		double y = solve3_internal(a, x);
		sum += y;
		mlt *= y;
		cnt++;
		String^ format = String::Format("{0,6:F2}{1,15:F7}", x, y);
		container->Items->Add(format);
		x += dx;
	}
}

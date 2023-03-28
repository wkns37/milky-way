#include "UserAnswers.h"

UserAnswers::UserAnswers(const UserAnswers%)
{
	// Объект пользователя в куче должен быть один
	throw gcnew System::InvalidOperationException("Cannot have more than one instances of class");
}

bool UserAnswers::isRight(size_t index)
{
	if (index >= 16) return false;
	return ans[index];
}

void UserAnswers::setAnswerResult(size_t index, bool result)
{
	if (index > 16) return;
	ans[index - 1] = result;
}

array<bool>^ UserAnswers::getAnswers()
{
	return ans;
}

double UserAnswers::getPercentage()
{
	double percentage = 0;

	for (size_t i = 0; i < 16; i++)
	{
		if (ans[i])
			percentage += (double)100 / 16;
	}

	return percentage;
}

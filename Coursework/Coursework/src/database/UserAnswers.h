#pragma once

public ref class UserAnswers
{
private:
	static UserAnswers instance;

	array<bool>^ ans = gcnew array<bool>(16);

private:
	UserAnswers() {}
	UserAnswers(const UserAnswers%);

public:
	static property UserAnswers^ Instance
	{
		UserAnswers^ get()
		{
			return %instance;
		}
	}

	bool isRight(size_t index);
	void setAnswerResult(size_t index, bool result);
	array<bool>^ getAnswers();
	double getPercentage();
};
#pragma once

public ref class User
{
private:
	static User instance;

	System::String^ username = "Пользователь";
	bool state = false;

private:
	User() {}
	User(const User%);

public:
	static property User^ Instance
	{
		User^ get()
		{
			return %instance;
		}
	}

	void logIn(System::String^ username);

	System::String^ getName();
	bool isLoggedIn();

	bool checkAuth(System::String^ username);
};
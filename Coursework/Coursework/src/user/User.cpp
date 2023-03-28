#include "User.h"

User::User(const User%)
{
	// Объект пользователя в куче должен быть один
	throw gcnew System::InvalidOperationException("Cannot have more than one instances of class");
}

void User::logIn(System::String^ username)
{
	this->username = username;
	this->state = true;
}

System::String^ User::getName()
{
	return username;
}

bool User::isLoggedIn()
{
	return state;
}

bool User::checkAuth(System::String^ username)
{
	return !this->state || this->username->Equals(username);
}
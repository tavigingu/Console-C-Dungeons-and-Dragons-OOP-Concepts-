#pragma once
#include <iostream>
using namespace std;

class MyException
{
private:
	string message;

public:
	MyException(const string& msg)
		:message(msg) { };

	friend ostream& operator<<(ostream& out, const MyException& obj);
};


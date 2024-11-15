#include "MyException.h"

ostream& operator<<(ostream& out, const MyException& obj)
{
	out << obj.message << endl;
	return out;
}
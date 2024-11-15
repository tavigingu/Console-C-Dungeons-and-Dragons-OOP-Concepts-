#include "Object.h"

void Object::show() const
{
	if (type == BOOK)
		cout << "Read -> Book " << name << "( Difficulty Class: " << diff_class.first << " " << diff_class.second <<" )" << endl;
	if (type == STATUE)
		cout << "Look -> Statue " << name << "( Difficulty Class: " << diff_class.first << " " << diff_class.second << " )" << endl;

}

void Object::setVisited()
{
	visited = true;
	name = name + "(~COMPLETED~)";
}

bool Object::getVisited() const
{
	return visited;
}

#pragma once
#include <iostream>
using namespace std;

typedef enum obj_type { BOOK, STATUE};

class Object
{
private:
	obj_type type;
	string name;
	pair<string, int> diff_class;
	pair<string, int> gains;
	bool visited;

public:
	Object(obj_type t, const string& name, pair<string, int> diffc, pair<string, int> gains)
		:type(t), name(name), diff_class(diffc), gains(gains) {
		visited = 0;
	};

	void show() const;
	inline pair<string, int> getGains() { return gains; }
	inline pair<string, int> getDiiffc() { return diff_class; }
	void setVisited();
	bool getVisited() const;
};


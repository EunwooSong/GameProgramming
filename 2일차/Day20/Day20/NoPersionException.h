#pragma once

class NoPersionException
{
private:
	int persons;
public:
	NoPersionException(int p) : persons(p) {}
	int getPerson() { return persons; }
};


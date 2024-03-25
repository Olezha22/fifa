#include "footballer.h"

Footballer::Footballer()
	: footballer_name(""), footballer_surname("") , footballer_goals(0), footballer_coefficient(1.0)
{
}
Footballer::Footballer(const std::string& name, const std::string& surname, int goals)
	: footballer_name(name), footballer_surname(surname), footballer_goals(goals), footballer_coefficient(1.0)
{
}
Footballer::Footballer(const Footballer& F)
	: footballer_name(F.footballer_name), footballer_surname(F.footballer_surname), footballer_goals(F.footballer_goals), footballer_coefficient(F.footballer_coefficient)
{
}
Footballer::~Footballer()
{
}



int Footballer::getGoals() const
{
	return footballer_goals;
}
void Footballer::setCoef(double coef)
{
	footballer_coefficient = coef;
}
double Footballer::getIncome() const
{
	return footballer_goals * footballer_coefficient;
}


void Footballer::printOn(std::ostream& os) const
{
	os << "\nName: " << footballer_name << "\nSurname: " << footballer_surname << "\nGoals: " << footballer_goals << "\nCoef: " << footballer_coefficient << "\nSalary: " << getIncome() << "\n";
}
void Footballer::readFrom(std::istream& is)
{
	is >> footballer_name >> footballer_surname >> footballer_goals;
}


std::ostream& operator << (std::ostream& os, const Footballer& F) 
{
	F.printOn(os);
	return os;
}
std::istream& operator >> (std::istream& is, Footballer& F)
{
	F.readFrom(is);
	return is;
}
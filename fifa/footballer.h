#pragma once
#include <iostream>
#include <string>

class Footballer
{
private: 
	std::string footballer_name;
	std::string footballer_surname;
	int footballer_goals;
	double footballer_coefficient;
public:
	Footballer();
	Footballer(const std::string& name, const std::string& surname, int goals);
	Footballer(const Footballer& F);
	~Footballer();

	int getGoals() const;
	void setCoef(double coef);
	double getIncome() const;

	void printOn(std::ostream& os) const;
	void readFrom(std::istream& is);
};

std::ostream& operator << (std::ostream& os, const Footballer& F) ;
std::istream& operator >> (std::istream& is, Footballer& F);
#pragma once
#include <iostream>
#include <string>
#include "footballer.h"

class Club
{
private: 
	std::string club_name;
	double club_coef;
	Footballer* club_players;
	int club_maxSize;
	int club_size;
public:
	Club();
	Club(const std::string& name, double coef);
	Club(const Club& C);
	~Club();

	void addPlayer(Footballer& player);
	void print();
	void sortByGoals();
	int getTotalGoals() const;
	std::string getName() const;
	double getTotalPayment() const;
};


void fetchData(Club** clubs, int clubsCount, const std::string& filename);
void printAndFindTopClubs(Club** clubs, int clubsCount);
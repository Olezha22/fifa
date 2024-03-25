#include "club.h"
#include <fstream>

Club::Club() 
    : club_name("Default Club"), club_coef(1.0), club_players(nullptr), club_maxSize(10), club_size(0) 
{
    club_players = new Footballer[club_maxSize];
}

Club::Club(const std::string& name, double coef) 
    : club_name(name), club_coef(coef), club_players(nullptr), club_maxSize(10), club_size(0) 
{
    club_players = new Footballer[club_maxSize];
}

Club::Club(const Club& C) 
    : club_name(C.club_name), club_coef(C.club_coef), club_players(C.club_players), club_maxSize(C.club_maxSize), club_size(C.club_size)
{
}

Club::~Club() 
{
    delete[] club_players;
}

void Club::addPlayer(Footballer& player) {
    if (club_size < club_maxSize) {
        player.setCoef(club_coef);
        club_players[club_size] = player;
        club_size++;
        
    }
    else {
        std::cout << "Can not add Club is full!" << std::endl;
    }
}

void Club::print() 
{
    std::cout << "\nClub Name: " << club_name << std::endl;
    std::cout << "Payment Coefficient: " << club_coef << std::endl;
    std::cout << "Players:" << std::endl;
    for (int i = 0; i < club_size; ++i) {
        std::cout << club_players[i];
    }
}

void Club::sortByGoals() {
    for (int i = 0; i < club_size - 1; ++i) {
        for (int j = 0; j < club_size - i - 1; ++j) {
            if (club_players[j].getGoals() < club_players[j + 1].getGoals()) {
                std::swap(club_players[j], club_players[j + 1]);
            }
        }
    }
}

int Club::getTotalGoals() const {
    int totalGoals = 0;
    for (int i = 0; i < club_size; ++i) {
        totalGoals += club_players[i].getGoals();
    }
    return totalGoals;
}

double Club::getTotalPayment() const {
    return getTotalGoals() * club_coef;
}

std::string Club::getName() const
{
    return club_name;
}


void fetchData(Club** clubs, int clubsCount, const std::string& filename) {
    std::ifstream fin(filename);

    int size;
    fin >> size;

    std::string clubName, playerName, playerSurname;
    int goals;

    for (int i = 0; i < size; ++i) {
        fin >> clubName >> playerName >> playerSurname >> goals;
        Footballer player(playerName, playerSurname, goals);
        for (int j = 0; j < clubsCount; ++j) {
            if (clubs[j]->getName() == clubName) {
                clubs[j]->addPlayer(player);
                break;
            }
        }
    }

    fin.close();
}


void printAndFindTopClubs(Club** clubs, int clubsCount) {
    Club* topGoalsClub = clubs[0], * topPaymentClub = clubs[0];
    for (int i = 0; i < clubsCount; ++i) {
        clubs[i]->print();
        if (!topGoalsClub || clubs[i]->getTotalGoals() > topGoalsClub->getTotalGoals()) {
            topGoalsClub = clubs[i];
        }
        if (!topPaymentClub || clubs[i]->getTotalPayment() > topPaymentClub->getTotalPayment()) {
            topPaymentClub = clubs[i];
        }
    }
    if (topGoalsClub != nullptr) {
        std::cout << "Club with the most goals: " << topGoalsClub->getName() << "\n";
    }
    else {
        std::cout << "No club with the most goals found.\n";
    }

    if (topPaymentClub != nullptr) {
        std::cout << "Club with the highest payment: " << topPaymentClub->getName() << "\n";
    }
    else {
        std::cout << "No club with the highest payment found.\n";
    }
}
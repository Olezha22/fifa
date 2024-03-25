#include <iostream>
#include <string>
#include "footballer.h"
#include "club.h"
#include <fstream>



int main() {
    size_t size = 3;
    Club** clubs = new Club * [size];
    clubs[0] = new Club("Barcelona", 3.7);
    clubs[1] = new Club("PSG", 8.2);
    clubs[2] = new Club("ManchesterCity", 5.0);

    fetchData(clubs, size, "players.txt");
    printAndFindTopClubs(clubs, size);

    for (int i = 0; i < 3; ++i) {
        delete clubs[i];
    }
    delete[] clubs;

    return 0;
}

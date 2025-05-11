#include "Defender.hpp"

Defender::Defender() : Footballer("noname", 2000, "defender", "Indonesia", 180, 70), tackleSuccess(0), interceptions(0){}

Defender::Defender(string name, int birthYear, int tackleSuccess, int interceptions) : Footballer(name, birthYear, "defender", "Indonesia", 180, 70), tackleSuccess(tackleSuccess), interceptions(interceptions){}

void Defender::setTackleSuccess(int succ) {tackleSuccess = succ;}

int Defender::getTackleSuccess() const {return tackleSuccess;}

void Defender::setInterceptions(int interc) {interceptions = interc;}

int Defender::getInterceptions() const{return interceptions;}

int Defender::defensiveRating() const{return ((tackleSuccess * 2) + interceptions);}

int Defender::transferRate() {return (600000 * tackleSuccess + 400000 * interceptions);}

void Defender::displayInfo(){
    Footballer::displayInfo();
    cout << "Tackle Success: " << getTackleSuccess() << endl;
    cout << "Interceptions: " << getInterceptions() << endl;
    cout << "Defensive Rating: " << defensiveRating() << endl;
}
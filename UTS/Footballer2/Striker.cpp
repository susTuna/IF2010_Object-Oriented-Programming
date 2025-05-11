#include "Striker.hpp"

Striker::Striker() : Footballer("noname", 2000, "striker", "Indonesia", 180, 70), goalScore(0), shotsOnTarget(0){}

Striker::Striker(string name, int birthYear, int goalScore, int shotsOnTarget) : Footballer(name, birthYear, "striker", "Indonesia", 180, 70), goalScore(goalScore), shotsOnTarget(shotsOnTarget){}

void Striker::setGoalScore(int cum) {goalScore = cum;}

int Striker::getGoalScore() const{return goalScore;}

void Striker::setShotsOnTarget(int cum) {shotsOnTarget = cum;}

int Striker::getShotsOnTarget() const{return shotsOnTarget;}

float Striker::conversionRate() const{return ((shotsOnTarget == 0) ? 0.0f :(static_cast<float>(goalScore) / static_cast<float>(shotsOnTarget)) * 100);}

int Striker::transferRate(){return (1000000 * goalScore + 10000 * conversionRate());}

void Striker::displayInfo(){
    Footballer::displayInfo();
    cout << "Goals: " << getGoalScore() << endl;
    cout << "Conversion Rate: " << fixed << setprecision(2) << conversionRate() << "%" << endl;
}
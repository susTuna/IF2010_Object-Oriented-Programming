#include "Goalkeeper.hpp"

Goalkeeper::Goalkeeper() : Footballer("noname", 2000, "goalkeeper", "Indonesia", 180, 70), cleanSheets(0), saves(0), totalShotsOnGoal(0){}

Goalkeeper::Goalkeeper(string name, int birthYear, int cleanSheets, int saves, int totalShotsOnGoal) : Footballer(name, birthYear, "goalkeeper", "Indonesia", 180, 70), cleanSheets(cleanSheets), saves(saves), totalShotsOnGoal(totalShotsOnGoal){}

void Goalkeeper::setCleanSheets(int shit) {cleanSheets = shit;}

int Goalkeeper::getCleanSheets() const{return cleanSheets;}

void Goalkeeper::setSaves(int save) {saves = save;}

int Goalkeeper::getSaves() const{return saves;}

void Goalkeeper::setTotalShotsOnGoal(int shit) {totalShotsOnGoal = shit;}

int Goalkeeper::getTotalShotsOnGoal() const{return totalShotsOnGoal;}

float Goalkeeper::savePercentage() const{return ((totalShotsOnGoal== 0) ? 0.0f : (static_cast<float>(saves) / static_cast<float>(totalShotsOnGoal)) * 100);}

int Goalkeeper::transferRate(){return (700000 * cleanSheets + 50000 * saves);}

void Goalkeeper::displayInfo(){
    Footballer::displayInfo();
    cout << "Clean Sheets: " << getCleanSheets() << endl;
    cout << "Saves: " << getSaves() << endl;
    cout << "Save Percentage: " << fixed << setprecision(2) << savePercentage() << "%" << endl;
}
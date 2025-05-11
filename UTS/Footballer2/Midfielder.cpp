#include "Midfielder.hpp"

Midfielder::Midfielder() : Footballer("noname", 2000, "midfielder", "Indonesia", 180, 70), assist(0), keyPasses(0){}

Midfielder::Midfielder(string name, int birthYear, int assist, int keyPasses) : Footballer(name, birthYear, "midfielder", "Indonesia", 180, 70), assist(assist), keyPasses(keyPasses){}

void Midfielder::setAssist(int sis) {assist = sis;}

int Midfielder::getAssist() const{return assist;}

void Midfielder::setKeyPasses(int ses) {keyPasses = ses;}

int Midfielder::getKeyPasses() const{return keyPasses;}

int Midfielder::playmakerRating() const{return (assist * 3 + keyPasses);}

int Midfielder::transferRate(){return ((800000 * assist) + (30000 * keyPasses));}

void Midfielder::displayInfo(){
    Footballer::displayInfo();
    cout << "Assists: " << getAssist() << endl;
    cout << "Key Passes: " << getKeyPasses() << endl;
    cout << "Playmaker Rating: " << playmakerRating() << endl;
}
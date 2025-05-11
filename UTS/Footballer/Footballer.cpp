#include "Footballer.hpp"

Footballer::Footballer() : name("noname"), birthYear(2000), playPosition("none"),
                           nationality("Indonesia"), height(180), weight(70) {}

Footballer::Footballer(string name, int birthYear, string playPosition, string nationality, int height, int weight)
                         : name(name), birthYear(birthYear), playPosition(playPosition),
                           nationality(nationality), height(height), weight(weight) {}

Footballer::Footballer(const Footballer& other) : name(other.name), birthYear(other.birthYear), playPosition(other.playPosition),
                           nationality(other.nationality), height(other.height), weight(other.weight) {}      

Footballer::~Footballer(){}

Footballer &Footballer::operator=(const Footballer& other){
    if(this != &other){
        this->name = other.name;
        this->birthYear = other.birthYear;
        this->playPosition = other.playPosition;
        this->nationality = other.nationality;
        this->height = other.height;
        this->weight = other.weight;
    }
    return *this;
}

string Footballer::getName() const{return name;}

void Footballer::setName(string name) {this->name = name;}

void Footballer::setPlayPosition(string playPosition) {this->playPosition = playPosition;}

string Footballer::getPlayPosition() const{return playPosition;}

void Footballer::setNationality(string nation) {nationality = nation;}

string Footballer::getNationality() const{return nationality;}

void Footballer::setHeight(int height) {this->height = height;}

int Footballer::getHeight() const{return height;}

void Footballer::setWeight(int weight) {this->weight = weight;}

int Footballer::getWeight() const{return weight;}

int Footballer::getAge() const{return CURRENT_YEAR - birthYear;}

double Footballer::getBMI() const{double h = static_cast<double>(height) / 100; return (static_cast<double>(weight) / (h * h));}

string Footballer::getCategory() const{
    double bmi = getBMI();
    if(bmi >= 30.0) return "Obese";
    if(bmi >= 25.0) return "Overweight";
    if(bmi >= 18.5) return "Normal";
    return "Underweight";
}

void Footballer::displayInfo(){
    cout << "Name: " << name << endl;
    cout << "Age: " << getAge() << endl;
    cout << "Position: " << playPosition << endl;
    cout << "Nationality: " << nationality << endl;
    cout << "BMI: " << fixed << setprecision(2) << getBMI() << " (" << getCategory() << ")" << endl;
    cout << "Transfer Rate: " << transferRate() << endl;
}
#include "PetShelter.hpp"

using namespace std;

template<typename T>
PetShelter<T>::PetShelter(string shelterName) : shelterName(shelterName), dogCapacity(8), catCapacity(12), petCount(0), currentDogs(0), currentCats(0) {for(int i = 0; i < MAX_SHELTER_CAPACITY; ++i) pets[i] = nullptr;}
template<typename T>
PetShelter<T>::PetShelter(string shelterName, int dogCapacity, int catCapacity) : shelterName(shelterName), dogCapacity(dogCapacity), catCapacity(catCapacity), petCount(0), currentDogs(0), currentCats(0) {
    int total = catCapacity + dogCapacity;
    for(int i = 0; i < MAX_SHELTER_CAPACITY; ++i) pets[i] = nullptr;
    if(total > MAX_SHELTER_CAPACITY) cout << "The total capacity you construct is " << total << ", meanwhile the shelter capacity is 20" << endl;
}
template<typename T>
PetShelter<T>::~PetShelter() {
    for(int i = 0; i < MAX_SHELTER_CAPACITY ; ++i){
        if(pets[i] == nullptr) continue;
        delete pets[i];
        pets[i] = nullptr;
    }
}
template<typename T>
string PetShelter<T>::getShelterName() const {return shelterName;}
template<typename T>
void PetShelter<T>::addPet(const string &petName, int age, bool isDog, const string &extraInfo) {
    int total = dogCapacity + catCapacity;
    total = (total > MAX_SHELTER_CAPACITY) ? MAX_SHELTER_CAPACITY : total;
    if(petCount >= total) {cout << "Error: Shelter is at full capacity!" << endl; return;}
    string id;
    Pet* newPet;
    if(isDog){
        if(currentDogs >= dogCapacity) {cout << "Error: No space for more dogs!" << endl; return;}
        newPet = new Dog(petName,age,extraInfo);
        id = "D" + to_string(++currentDogs);
        
    }else{
        if(currentCats >= catCapacity) {cout << "Error: No space for more cats!" << endl; return;}
        newPet = new Cat(petName,age,extraInfo);
        id = "C" + to_string(++currentCats);
    }
    newPet->setId(id);
    for(int i = 0; i < MAX_SHELTER_CAPACITY; ++i){
        if(pets[i] == nullptr) {pets[i] = newPet; break;}
    }
    petCount++;
    cout << "Success: " << petName << " has been added as a " << ((isDog) ? "Dog": "Cat") << "! Pet ID: " << id << endl;
}
template<typename T>
T* PetShelter<T>::findPet(const string &petID) const{
    for(int i = 0; i < MAX_SHELTER_CAPACITY; ++i){
        if(pets[i] == nullptr) continue;
        if(petID == pets[i]->getId()) {pets[i]->displayInfo(); return dynamic_cast<T*>(pets[i]);}
    }
    cout << "Pet ID is invalid!" << endl; return nullptr;
}
template<typename T>
void PetShelter<T>::listAllPets() const{
    if(petCount == 0) cout << "No pets in the shelter yet!" << endl;
    else {
        int j = 1; 
        for(int i = 0; i < MAX_SHELTER_CAPACITY; ++i) {
            if(pets[i] == nullptr) continue;
            cout << j++ << ". "; pets[i]->displayInfo();
        }
    }
}
template<typename T>
int PetShelter<T>::calculateCost() const{
    int cost = 0;
    for(int i = 0; i < MAX_SHELTER_CAPACITY; ++i){
        if(pets[i] == nullptr) continue;
        if(dynamic_cast<Dog*>(pets[i])) cost += 75;
        else if(dynamic_cast<Cat*>(pets[i])) cost += 60;
    }
    return cost;
}
template<typename T>
void PetShelter<T>::removePet(const string &petID){
    for (int i = 0; i < MAX_SHELTER_CAPACITY; i++) {
        if (pets[i] == nullptr) continue; 
        if (pets[i]->getId() == petID) {
            cout << pets[i]->getName() << " has been removed from the shelter." << endl;

            if (dynamic_cast<Dog*>(pets[i])) { currentDogs--; }
            else if (dynamic_cast<Cat*>(pets[i])) { currentCats--; }
            petCount--;

            pets[i] = nullptr;
            return;
        }
    }
    cout << "Pet ID is invalid!" << endl;
}

template class PetShelter<Pet>;
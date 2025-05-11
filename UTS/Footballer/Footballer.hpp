#ifndef FOOTBALLER_HPP
#define FOOTBALLER_HPP

#include <iostream>
#include <iomanip>

using namespace std;

#define CURRENT_YEAR 2025

class Footballer
{
protected:
  string name;
  string playPosition;
  int birthYear;

  string nationality;
  int height;
  int weight;

public:
  // Default cosntructor set nilai attribut sebagai berikut:
  Footballer();
  // name = "noname"; birthYear = 2000; playPosition = "none";
  // nationality = "Indonesia"; height = 180, weight = 70
  // ...

  // User-defined constructor:
  Footballer(string name, int birthYear, string playPosition, string nationality, int height, int weight);
  // set nilai atribut berdasarkan nilai parameter masukan
  // dengan urutan: name, birthYear, playPosition, nationality, height, weight
  // ...

  // Copy constructor
  Footballer(const Footballer& other);
  // ...

  // Destructor
  ~Footballer();
  // ...

  // Operator assignment
  Footballer& operator=(const Footballer& other);
  // ...

  // Getter dan setter name
  string getName() const;
  void setName(string name);
  // setName(...)
  // getName()

  // Getter dan setter playPosition
  void setPlayPosition(string playPosition);
  string getPlayPosition() const;
  // setPlayPosition(...)
  // getPlayPosition()

  // Getter dan setter nationality
  void setNationality(string nation);
  string getNationality() const;
  // setNationality(...)
  // getNationality()

  // Getter dan setter height and weight
  void setHeight(int height);
  int getHeight() const;
  void setWeight(int weight);
  int getWeight() const;
  // setHeight(...)
  // getHeight()
  // setWeight(...)
  // getWeight()

  // gunakan CURRENT_YEAR untuk menghitung umur
  int getAge() const;
  // getAge()

  // gunakan height and weight untuk menghitung BMI
  // BMI = weight(kg) / (height(m))²
  double getBMI() const;
  // getBMI()

  // gunakan BMI untuk mendapat category
  string getCategory() const;
  // BMI < 18.5         -> Underweight
  // 18.5 ≤ BMI < 25.0  -> Normal
  // 25.0 ≤ BMI < 30.0  -> Overweight
  // BMI ≥ 30.0         -> Obese
  // getCategory() -> string

  // Mencetak informasi footballer dengan format sebagai berikut:
  // Name: {name}
  // Age: {hasil pemanggilan getAge()}
  // Position: {playPosition}
  // Nationality: {nationality}
  // BMI: {<BMI> (<getCategory()>)}, BMI 2 angka di belakang koma, HINT: "cout << fixed << setprecision(2);"
  // Transfer Rate: {hasil pemanggilan transferRate()}
  virtual void displayInfo();

  // Melakukan kalkulasi nilai transfer sesuai umur, playPosition, dan getCategory()
  // transferRate() akan diimplementasikan oleh kelas anak Footballer
  // yang ada di soal berikutnya. Gunakan tipe data integer.
  virtual int transferRate() = 0;
};

#endif
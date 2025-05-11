// PetShelterTest.cpp
#include <cassert>
#include <iostream>
#include "PetShelter.hpp"

// NB: pastikan file‑file Pet, Dog, Cat, dan PetShelter template
//     ikut di‑compile & link.  Contoh baris kompilasi ada di bawah.

int main() {
    // -----  setup shelter dengan kapasitas kecil agar mudah dicek  -----
    PetShelter<Pet> shelter("UnitTestShelter", /*dogCap*/2, /*catCap*/2);

    // ---------- 1) uji tambah anjing ----------
    shelter.addPet("Buddy", 3, /*isDog*/true,  "Corgi");
    assert(shelter.findPet("D1") != nullptr);          // ID otomatis “D1”
    assert(shelter.calculateCost() == 75);             // 1 anjing -> 75

    // ---------- 2) uji tambah kucing ----------
    shelter.addPet("Misty", 1, /*isDog*/false, "Calico");
    assert(shelter.findPet("C1") != nullptr);          // ID otomatis “C1”
    assert(shelter.calculateCost() == 75 + 60);        // total 135

    // ---------- 3) uji hapus anjing ----------
    shelter.removePet("D1");
    assert(shelter.findPet("D1") == nullptr);          // harus hilang
    assert(shelter.calculateCost() == 60);             // hanya 1 kucing tersisa

    // ---------- 4) uji hapus ID tidak valid (harus tidak crash) ----------
    shelter.removePet("D99");                          // hanya men‑print warning

    std::cout << "\n✅  All add/remove tests passed!\n";
    return 0;
}

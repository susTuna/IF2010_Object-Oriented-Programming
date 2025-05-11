#include "Gudang.hpp"
#include "Barang.hpp"
#include "Exception.hpp"
#include "BarangMakanan.hpp"
#include "BarangElektronik.hpp"
#include <iostream>

Gudang::Gudang() : kapasitasTotal(DEFAULT_KAPASITAS), kapasitasTerpakai(0), tenagaKerja(DEFAULT_TENAGA_KERJA), uang(DEFAULT_UANG){}

Gudang::Gudang(int kapasitas, int uang, int tenagaKerja) : kapasitasTotal(kapasitas), kapasitasTerpakai(0), tenagaKerja(tenagaKerja), uang(uang){}

Gudang::~Gudang(){
    for (int i = 0; i < daftarBarang.size(); ++i){
        delete daftarBarang.at(i);
    }
}

void Gudang::simpanBarang(Barang *barang){
    try{
        int berat = barang->getBerat();
        int cap = kapasitasTotal - kapasitasTerpakai;

        if(barang->getJenis() == "Makanan"){
        BarangMakanan *makanan = dynamic_cast<BarangMakanan *>(barang);
        if(makanan->getHariKedaluwarsa() <= 0){
            throw BarangKedaluwarsaException();
            }
        }

        if(berat > cap) throw KapasitasPenuhException();
        if(uang < 100) throw UangTidakCukupException();
        if(tenagaKerja <= 0) throw TenagaKerjaTidakCukupException();

        daftarBarang.push_back(barang);
        pakaiKapasitas(berat);
        pakaiUang(100);
        pakaiTenagaKerja();
        cout << "Barang [" << daftarBarang.size()-1 << "] " << barang->getNama() << " berhasil disimpan\n";
    }
    catch(BarangKedaluwarsaException &e){
        cout << "Barang makanan sudah kedaluwarsa, buang dulu.\n";
    }
    catch(KapasitasPenuhException &e){
        cout << "Kapasitas gudang tidak mencukupi, perluas gudang dulu.\n";
    }
    catch(UangTidakCukupException &e){
        cout << "Uang tidak cukup, cari pemasukan dulu.\n";        
    }
    catch(TenagaKerjaTidakCukupException &e){
        cout <<  "Tenaga kerja tidak cukup, rekrut dulu.\n";
    } 
}

void Gudang::tambahKapasitas(int kg){
    kapasitasTotal += kg;
}

void Gudang::tambahTenagaKerja(int jumlah){
    tenagaKerja += jumlah;
}

void Gudang::tambahUang(int jumlah){
    uang += jumlah;
}

void Gudang::pakaiKapasitas(int kg){
    if(kapasitasTerpakai + kg > kapasitasTotal){
        throw KapasitasPenuhException();
    }
    kapasitasTerpakai += kg;
}

void Gudang::pakaiUang(int jumlah){
    if(uang - jumlah < 0){
        throw UangTidakCukupException();
    }
    uang -= jumlah;
}

void Gudang::pakaiTenagaKerja(){
    if(tenagaKerja == 0){
        throw TenagaKerjaTidakCukupException();
    }
    tenagaKerja--;
}

void Gudang::sebutBarang(int idx){
    Barang *b = daftarBarang.at(idx);
    string nama = b->getNama();
    string jenis = b->getJenis();
    int berat = b->getBerat();
    cout << nama << " - " << jenis << " - " << berat << "kg\n";  
}

void Gudang::statusGudang() const{
    cout << "Status gudang:\n";
    cout << "  Kapasitas total: " << kapasitasTotal << " kg\n";
    cout << "  Kapasitas terpakai: " << kapasitasTerpakai << " kg\n";
    cout << "  Uang: " << uang << "\n";
    cout << "  Tenaga kerja: " << tenagaKerja << "\n";
    cout << "  Barang:\n";
    for (int i = 0; i < daftarBarang.size(); ++i){
        Barang* cur = daftarBarang.at(i);
        cout << "    [" << i << "] " << cur->getNama() << " - " << cur->getJenis() << " - " << cur->getBerat() << "kg\n";
    }
}
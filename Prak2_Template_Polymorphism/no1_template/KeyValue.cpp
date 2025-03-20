#include <iostream>
#include <math.h>

using namespace std;


template<class T1, class T2>
class KeyValue{
    private:
        T1* keys;
        T2* values;
        int nEFF;
        const int MAX = 10;
    
    public:
        KeyValue(){
            this->keys = new T1[MAX];
            this->values = new T2[MAX];
            this->nEFF = 0;
        }

        KeyValue(const KeyValue& other){
            this->keys = new T1[MAX];
            this->values = new T2[MAX];
            this->nEFF = other.nEFF;

            for (int i = 0; i < nEFF ; i++){
                this->keys[i] = other.keys[i];
            }

            for (int j = 0; j < nEFF ; j++){
                this->values[j] = other.values[j];
            }
        }

        ~KeyValue(){
            delete[] this->keys;
            delete[] this->values;
        }

        void set(T1 key, T2 value){
            for (int i = 0 ; i < nEFF ; i++){
                if (key == this->keys[i]) {
                    this->values[i] = value;
                    return;
                }
            }

            if (nEFF == MAX) {
                cout << "KeyValue penuh! Tidak bisa menambahkan KeyValue lagi." << endl;
                return;
            }

            this->keys[nEFF] = key;
            this->values[nEFF] = value;
            nEFF++;
        }

        void display(T1 key){
            for (int i = 0; i < nEFF ; i++){
                if (key == this->keys[i]) {
                    cout << this->values[i] << endl;
                    return;
                }
            }

            cout << "Key tidak ditemukan!" << endl;
        }
};


template<class T2>
class KeyValue<double, T2>{
    private:
        double* keys;
        T2* values;
        int nEFF;
        const int MAX = 10;
    
    public:
        KeyValue(){
            this->keys = new double[MAX];
            this->values = new T2[MAX];
            this->nEFF = 0;
        }

        KeyValue(const KeyValue& other){
            this->keys = new double[MAX];
            this->values = new T2[MAX];
            this->nEFF = other.nEFF;

            for (int i = 0; i < nEFF ; i++){
                this->keys[i] = other.keys[i];
            }

            for (int j = 0; j < nEFF ; j++){
                this->values[j] = other.values[j];
            }
        }

        ~KeyValue(){
            delete[] this->keys;
            delete[] this->values;
        }

        void set(double key, T2 value){
            for (int i = 0 ; i < nEFF ; i++){
                if (key == this->keys[i] || abs(key - this->keys[i] < 0.01)) {
                    this->values[i] = value;
                    return;
                }
            }

            if (nEFF == MAX) {
                cout << "KeyValue penuh! Tidak bisa menambahkan KeyValue lagi." << endl;
                return;
            }

            this->keys[nEFF] = key;
            this->values[nEFF] = value;
            nEFF++;
        }

        void display(double key){
            for (int i = 0; i < nEFF ; i++){
                if (key == this->keys[i] || abs(key - this->keys[i] < 0.01)) {
                    cout << this->values[i] << endl;
                    return;
                }
            }

            cout << "Key tidak ditemukan!" << endl;
        }
};
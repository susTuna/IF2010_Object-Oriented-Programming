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

        void displayAll(){
            for (int i = 0; i < nEFF ; i++){
                cout << "Key: " << this->keys[i] << " Value: " << this->values[i] << endl;
            }
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

        void displayAll(){
            for (int i = 0; i < nEFF ; i++){
                cout << "Key: " << this->keys[i] << " Value: " << this->values[i] << endl;
            }
        }
};

// int main(){
//     KeyValue<int, string> kv;
//     kv.set(1, "Alice");
//     kv.set(2, "Bob");
//     kv.set(3, "Charlie");
//     kv.displayAll();
//     kv.display(1);
//     kv.display(2); // Output: "Bob"
//     kv.display(3); // Output: "Charlie"

//     KeyValue<double, int> k;
//     k.set(1.01, 1);
//     k.set(1.02, 2);
//     k.set(1.012, 2);
//     k.displayAll();
//     return 0;
// }
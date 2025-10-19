#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

class Buffer {
private:
    size_t size;
    unsigned char* data;

public:

    Buffer() : size(0), data(nullptr) {
        cout << "Constructeur par défaut : Buffer vide" << endl;
    }


    Buffer(size_t n) : size(n) {
        data = new unsigned char[size];
        memset(data, 0, size);
        cout << "Constructeur paramétré : Buffer de " << size << " octet(s)" << endl;
    }


    Buffer(const Buffer& autre) : size(autre.size) {
        if (size > 0) {
            data = new unsigned char[size];
            memcpy(data, autre.data, size);
        } else {
            data = nullptr;
        }
        cout << "Constructeur de copie : Buffer de " << size << " octet(s)" << endl;
    }


    Buffer& operator=(const Buffer& autre) {
        if (this != &autre) {
            delete[] data;
            size = autre.size;
            if (size > 0) {
                data = new unsigned char[size];
                memcpy(data, autre.data, size);
            } else {
                data = nullptr;
            }
        }
        cout << "Opérateur d’affectation appelé" << endl;
        return *this;
    }

    // ✅ Méthode pour remplir le buffer
    void fill(unsigned char value) {
        if (data) memset(data, value, size);
    }


    size_t getSize() const {
        return size;
    }


    void printHex() const {
        cout << "Buffer (" << size << " octet(s)) : ";
        for (size_t i = 0; i < size; ++i) {
            cout << uppercase << hex << setw(2) << setfill('0') << (int)data[i] << " ";
        }
        cout << dec << endl;
    }


    ~Buffer() {
        cout << "Destruction du buffer de " << size << " octet(s)" << endl;
        delete[] data;
    }
};




int main() {
    Buffer buf1;
    Buffer buf2(8);
    buf2.fill(0xAA);

    Buffer buf3 = buf2;

    cout << "\n=== Contenus ===" << endl;
    buf1.printHex();
    buf2.printHex();
    buf3.printHex();

    cout << "\n=== Fin du programme ===" << endl;
    return 0;
}

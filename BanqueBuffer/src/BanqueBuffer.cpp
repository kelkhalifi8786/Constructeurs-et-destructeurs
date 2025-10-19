#include <iostream>
#include <string>
using namespace std;

class CompteBancaire {
private:
    string titulaire;
    double solde;

public:

    CompteBancaire() : titulaire("Inconnu"), solde(0.0) {
        cout << "Constructeur par défaut appelé pour " << titulaire << endl;
    }


    CompteBancaire(const string& nom, double montant)
        : titulaire(nom), solde(montant) {
        cout << "Constructeur paramétré appelé pour " << titulaire << endl;
    }


    CompteBancaire(const CompteBancaire& autre)
        : titulaire(autre.titulaire), solde(autre.solde) {
        cout << "Constructeur de copie appelé pour " << titulaire << endl;
    }


    void afficher() const {
        cout << "Titulaire : " << titulaire << " | Solde : " << solde << " €" << endl;
    }


    ~CompteBancaire() {
        cout << "Destruction du compte de " << titulaire << endl;
    }
};


int main() {
    CompteBancaire compte1;
    CompteBancaire compte2("Alice", 1500.0);
    CompteBancaire compte3 = compte2;

    cout << "\n=== Informations des comptes ===" << endl;
    compte1.afficher();
    compte2.afficher();
    compte3.afficher();

    cout << "\n=== Fin du programme ===" << endl;
    return 0;
}

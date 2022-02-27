#include <iostream>
#include <string>

using namespace std;

class Forca {
    public: 
        string palavra; // A palavra que deverá ser descoberta;

        int inicia(string palavra) {
            this -> palavra = palavra;
            cout << "Iniciando o jogo com a palavra: " << this -> palavra << "!\n\n";
            return 0;
        }
};
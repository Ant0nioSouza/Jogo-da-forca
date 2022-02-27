#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Forca {
    public: 
        string palavra; // A palavra que deverá ser descoberta;

        int inicia(string palavra) {
            
            this -> palavra = palavra;
            cout << "Iniciando o jogo com a palavra: " << this -> palavra << "!\n\n";
            registraLetras();
            return 0;
        }
    private:
        int i, tamanho;
        vector<char> letras;
        void registraLetras() {
            tamanho = palavra.length();
            for (i = 0; i < tamanho; i++) {
                cout << "Tentando adicionar às letras: " << palavra[i] << "\n";
                letras.push_back(palavra[i]);
            }
        }
};
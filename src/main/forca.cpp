#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Forca {
    public: 
        string palavra; // A palavra que deverá ser descoberta;

        void resetaTela() {
            int i;
            cout << flush;
            for (i = 0; i < palavra.length(); i++) {
                cout << "*";
            }
        }

        void adivinhaLetra(char letraEscolhida) {
            int acertos = 0;
            int i;
            resetaTela();
            for (i = 0; i < palavra.length(); i++) {
                if (palavra[i] == letraEscolhida) {
                    acertos ++;
                    cout << letraEscolhida;
                } else {
                    cout << "*";
                }
            }
        }

        int inicia(string palavra) {
            this -> palavra = palavra;
            registraLetras();
            cout << "JOGO INICIADO!!";
            return 0;
        }
    private:
        vector<char> letras;
        void registraLetras() {
            int i, tamanho;
            tamanho = palavra.length();
            for (i = 0; i < tamanho; i++) {
                letras.push_back(palavra[i]);
            }
        }
};

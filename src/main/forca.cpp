#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Forca {
    public: 
        string palavra; // A palavra que deverá ser descoberta;
        bool finalizado;
        int tentativas;

        void resetaTela() {
            int i;
            cout << flush;
            for (i = 0; i < palavra.length(); i++) {
                cout << "*";
            }
        }

        void adivinhaLetra(char letraEscolhida) {
            int acertos = 0;
            int i, j;
            cout << "\033[2J\033[1;1H"; // limpa a tela;
            for (i = 0; i < palavra.length(); i++) {
                if (letrasDescobertas.size() > 0) {
                for (j = 0; j < letrasDescobertas.size(); j++) {
                    if (palavra[i] == letrasDescobertas[j]) {
                        cout << letrasDescobertas[j];
                    } else if (palavra[i] == letraEscolhida) {
                        acertos ++;
                        cout << letraEscolhida;
                    } else {
                        cout << "*";
                    }
                }
                } else {
                    if (palavra[i] == letraEscolhida) {
                        acertos ++;
                        cout << letraEscolhida;
                    } else {
                        cout << "*";
                    }
                }
            }


            if (acertos > 0) {
                letrasDescobertas.push_back(letraEscolhida);
            } else {
                letrasTentadas.push_back(letraEscolhida);
                tentativas --;
            }

            if (tentativas <= 0) {
                cout << "\033[2J\033[1;1H";
                cout << "JOGO FINALIZADO! SUA PONTUAÇÃO: " << letrasDescobertas.size() - letrasTentadas.size();
                finalizado = true;
            }
            if (letrasDescobertas == letras) {
                cout << "\033[2J\033[1;1H";
                cout << "JOGO FINALIZADO! SUA PONTUAÇÃO: " << letrasDescobertas.size() - letrasTentadas.size();
                finalizado = true;
            }

        }

        int inicia(string palavra, int tentativas) {
            this -> palavra = palavra;
            this -> tentativas = tentativas;

            registraLetras();
            finalizado = false;
            cout << "JOGO INICIADO!!";
            return 0;
        }
    private:
        vector<char> letras;
        vector<char> letrasDescobertas;
        vector<char> letrasTentadas;

        void registraLetras() {
            int i, tamanho;
            tamanho = palavra.length();
            for (i = 0; i < tamanho; i++) {
                letras.push_back(palavra[i]);
            }
        }
};

int main() {
    Forca forca;
    string palavra;
    cout << "Digite a palavra do jogo: ";
    cin >> palavra;
    forca.inicia(palavra, 3);

    while (!forca.finalizado) {
        cout << "Digite uma letra para adivinhar: ";
        char letra;
        cin >> letra;
        forca.adivinhaLetra(letra);
    }
    return 0;
}

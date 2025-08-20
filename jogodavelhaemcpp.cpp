#include <iostream>
#include <string>

using namespace std;

// Função para exibir o tabuleiro
void imprimir_tabuleiro(const string &s) {
    cout << " " << s[0] << " | " << s[1] << " | " << s[2] << endl;
    cout << "-----------" << endl;
    cout << " " << s[3] << " | " << s[4] << " | " << s[5] << endl;
    cout << "-----------" << endl;
    cout << " " << s[6] << " | " << s[7] << " | " << s[8] << endl;
    cout << endl;
}

// Função para verificar vitória de um jogador
bool verificar_vitoria(const string &s, char jogador) {
    return (s[0]==jogador && s[1]==jogador && s[2]==jogador) ||
           (s[3]==jogador && s[4]==jogador && s[5]==jogador) ||
           (s[6]==jogador && s[7]==jogador && s[8]==jogador) ||
           (s[0]==jogador && s[3]==jogador && s[6]==jogador) ||
           (s[1]==jogador && s[4]==jogador && s[7]==jogador) ||
           (s[2]==jogador && s[5]==jogador && s[8]==jogador) ||
           (s[0]==jogador && s[4]==jogador && s[8]==jogador) ||
           (s[2]==jogador && s[4]==jogador && s[6]==jogador);
}

// Função para checar empate
bool verificar_empate(const string &s) {
    for(char c : s) {
        if(c != 'X' && c != 'O') return false;
    }
    return true;
}

// Função para a jogada de um jogador
int jogador(string &tabuleiro, int n, char simbolo) {
    int pos;
    while(true) {
        cout << "Jogador " << n << " (" << simbolo << "), escolha uma posicao: ";
        cin >> pos;
        cout << endl;

        if(pos < 1 || pos > 9) {
            cout << "Posicao invalida! Escolha de 1 a 9.\n";
            continue;
        }

        if(tabuleiro[pos-1] == 'X' || tabuleiro[pos-1] == 'O') {
            cout << "Posicao ja ocupada! Escolha outra.\n";
            continue;
        }

        return pos;
    }
}

// Perguntar se deseja jogar novamente
bool jogar_novamente() {
    char r;
    while(true) {
        cout << "Deseja reiniciar o jogo? (S/N): ";
        cin >> r;
        if(r=='S' || r=='s') return true;
        if(r=='N' || r=='n') return false;
        cout << "Opcao invalida! Digite S para sim ou N para nao.\n";
    }
}

int main() {
    do {
        string tabuleiro = "123456789";
        int jogador_atual = 1;
        char simbolo;

        while(true) {
            imprimir_tabuleiro(tabuleiro);
            simbolo = (jogador_atual == 1) ? 'X' : 'O';
            int pos = jogador(tabuleiro, jogador_atual, simbolo);
            tabuleiro[pos-1] = simbolo;

            // Verifica vitória
            if(verificar_vitoria(tabuleiro, simbolo)) {
                imprimir_tabuleiro(tabuleiro);
                cout << "\nParabens! Jogador " << jogador_atual << " venceu!\n";
                break;
            }

            // Verifica empate
            if(verificar_empate(tabuleiro)) {
                imprimir_tabuleiro(tabuleiro);
                cout << "\nEmpate! Nenhum jogador venceu.\n";
                break;
            }

            // Alterna jogador
            jogador_atual = (jogador_atual == 1) ? 2 : 1;
        }
    } while(jogar_novamente());

    cout << "Obrigado por jogar!\n";
    return 0;
}

#include <iostream>

using namespace std;

void imprimir_tabuleiro(string s){
    cout << " " << s[0] << " | " << s[1] << " | " << s[2] << endl;
    cout << "-----------" << endl;
    cout << " " << s[3] << " | " << s[4] << " | " << s[5] << endl;
    cout << "-----------" << endl;
    cout << " " << s[6] << " | " << s[7] << " | " << s[8] << endl;
}

void vitoria1(){
    cout << "Parabens! Jogador 1 venceu!" << endl;
}

void verificacao_de_vitoria(string t){
    if(t[0]=='X' && t[1]=='X' && t[2]=='X'){
        vitoria1();
    }
}

int jogador1(string tabuleiro){
    verificacao_de_vitoria(tabuleiro);
    int x;
    for(int i=0; i==i; i++){
        cout << endl;
        cout << "Jogador 1 (X), escolha uma posicao: ";
        cin >> x;
        if(x<1 || x>9){
            cout << "Opcao invalida ou ja ocupada! Escolha outra posicao";
            continue;
        }
        if(tabuleiro[x-1]=='X' || tabuleiro[x-1]=='O'){
            cout << "Opcao invalida ou ja ocupada! Escolha outra posicao";
            continue;
        }
        cout << endl;
        return x;
        break;
    }
}

int jogador2(string tabuleiro){
    int x;
    for(int i=0; i==i; i++){
        cout << endl;
        cout << "Jogador 2 (O), escolha uma posicao: ";
        cin >> x;
        if(x<1 || x>9){
            cout << "Opcao invalida ou ja ocupada! Escolha outra posicao";
            continue;
        }
        if(tabuleiro[x-1]=='X' || tabuleiro[x-1]=='O'){
            cout << "Opcao invalida ou ja ocupada! Escolha outra posicao";
            continue;
        }
        cout << endl;
        return x;
        break;
    }
}


int main(){
    string s={'1','2','3','4','5','6','7','8','9'};
    imprimir_tabuleiro(s);
    int x=jogador1(s);
    s[x-1]='X';
    imprimir_tabuleiro(s);
    int y=jogador2(s);
    s[y-1]='O';
    imprimir_tabuleiro(s);
    x=jogador1(s);
    s[x-1]='X';
    imprimir_tabuleiro(s);
    y=jogador2(s);
    s[y-1]='O';

}
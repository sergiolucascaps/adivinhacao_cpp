#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

int main(){
    cout << "***********************************************" << endl;
    cout << "*********** JOGO DA ADIVINHAÇÃO C++ ***********" << endl;
    cout << "***********************************************" << endl;

    cout << "Escolha seu nível de dificuldade: " << endl;
    cout << "Fácil (F), Médio (M), Difícil (D)" << endl;

    char nivel;
    cin >> nivel;

    int numero_de_tentativas;

    switch (nivel)
    {
        case 'F':
            numero_de_tentativas = 15;
            break;
        case 'M':
            numero_de_tentativas = 10;
            break;
        case 'D':
            numero_de_tentativas = 5;
            break;
        default:
            cout << "Como você não sabe interpretar as opções corretamente, seu nível foi definido como fácil!" << endl;
            numero_de_tentativas = 15;
            break;
    }

    srand(time(NULL));
    const int NUMERO_SECRETO = rand() % 100;

    bool nao_acertou = true;
    short tentativas = 0;
    double pontos = 1000;

    for (tentativas = 1; tentativas <= numero_de_tentativas; tentativas++){
        cout << "Tentativa " << tentativas << endl;
        cout << "Qual seu chute? " << endl;
        int chute;
        cin >> chute;

        double pontos_perdidos = abs(chute - NUMERO_SECRETO) / 2.0;
        pontos = pontos - pontos_perdidos;
        
        bool acertou = chute == NUMERO_SECRETO;
        bool maior = chute > NUMERO_SECRETO;

        if(acertou) {
            nao_acertou = false;
            break;
        }
        else if(maior){
            cout << "Seu chute é maior que o número secreto" << endl;
        }
        else {
            cout << "Seu chute é menor que o número secreto" << endl;
        }
    };

    if(nao_acertou)
        cout << "Que pena... Você falhou em " << tentativas << " tentativas!" << endl;
    else {
        cout << "Legal, você venceu em " << tentativas << " tentativas!!!" << endl;

        cout.precision(2);
        cout << fixed;
        cout << "Sua pontuação foi de " << pontos << endl;
    }
}
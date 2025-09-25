#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
using namespace std;

void desenhoforca(int tentativas) {
    switch (tentativas) {
        case 0:
            cout << " _______\n";
            cout << " |     | \n";
            cout << " |\n";
            cout << " |\n";
            cout << " |\n";
            cout << " |\n";
            cout << "_|_\n";
            break;
        case 1:
            cout << " _______\n";
            cout << " |     | \n";
            cout << " |     O \n";
            cout << " |\n";
            cout << " |\n";
            cout << " |\n";
            cout << "_|_\n";
            break;
        case 2:
            cout << " _______\n";
            cout << " |     | \n";
            cout << " |     O \n";
            cout << " |     | \n";
            cout << " |\n";
            cout << " |\n";
            cout << "_|_\n";
            break;
        case 3:
            cout << " _______\n";
            cout << " |     | \n";
            cout << " |     O \n";
            cout << " |    /| \n";
            cout << " |\n";
            cout << " |\n";
            cout << "_|_\n";
            break;
        case 4:
            cout << " _______\n";
            cout << " |     | \n";
            cout << " |     O \n";
            cout << " |    /|\\ \n";
            cout << " |\n";
            cout << " |\n";
            cout << "_|_\n";
            break;
        case 5:
            cout << " _______\n";
            cout << " |     | \n";
            cout << " |     O \n";
            cout << " |    /|\\ \n";
            cout << " |    / \n";
            cout << " |\n";
            cout << "_|_\n";
            break;
        case 6:
            cout << " _______\n";
            cout << " |     | \n";
            cout << " |     O \n";
            cout << " |    /|\\ \n";
            cout << " |    / \\ \n";
            cout << " |\n";
            cout << "_|_\n";
            break;
    }
}

void palavraescondida(char palavra_s[], char palavra_oc[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        if (palavra_s[i] == ' ') {
            palavra_oc[i] = ' ';
        } else {
            palavra_oc[i] = 'X';
        }
    }
    palavra_oc[tamanho] = '\0';
}

int main() {
    char palavra[25][30] = {
        "nanatsu no taizai", "naruto", "demon slayer", "hunter x hunter",
        "sakamoto days", "dandadan", "dragon ball", "jujutsu kaisen", "pokemon",
        "death note", "jojo", "blue lock", "sailor moon", "chainsaw man",
        "black clover", "bleach", "fullmetal alchemist", "one piece", "dr stone", "one punch man"
    };

    char palavra_s[20], palavra_oc[20];
    char letra;
    int ns, tentativas;
    bool acertou;
    char resposta[10];

    srand(time(NULL));

    strcpy(resposta, "sim");

    while (strcmp(resposta, "sim") == 0) {
        ns = rand() % 25;
        strcpy(palavra_s, palavra[ns]);
        int tamanho = strlen(palavra_s);
        palavraescondida(palavra_s, palavra_oc, tamanho);
        tentativas = 0;

        system("cls");
        cout << "______________________________\n";
        cout << "Seja bem-vindo ao jogo da forca\n";
        desenhoforca(tentativas);

        while (true) {
            cout << "\nTema: Animes\n";
            cout << "Palavra: " << palavra_oc << "\n";
            cout << "Digite uma letra: ";
            cin >> letra;
            letra = tolower(letra);
            acertou = false;

            for (int i = 0; i < tamanho; i++) {
                if (tolower(palavra_s[i]) == letra && palavra_oc[i] == 'X') {
                    palavra_oc[i] = palavra_s[i];
                    acertou = true;
                }
            }

            system("cls");

            if (!acertou) {
                tentativas++;
                cout << "Letra errada! Tentativas restantes: " << (6 - tentativas) << "\n";
            } else {
                cout << "Voce acertou! Tentativas restantes: " << (6 - tentativas) << "\n";
            }

            desenhoforca(tentativas);

            if (tentativas == 6) {
                cout << "Voce perdeu! A palavra era: " << palavra_s << "\n";
                break;
            }

            if (strcmp(palavra_oc, palavra_s) == 0) {
                cout << "Parabens! Voce acertou a palavra: " << palavra_s << "\n";
                break;
            }
        }

        cout << "\nDeseja continuar? (sim/nao): ";
        cin >> resposta;
        for (int i = 0; resposta[i]; i++) resposta[i] = tolower(resposta[i]);
    }

    cout << "Obrigado por jogar!\n";
    return 0;
}

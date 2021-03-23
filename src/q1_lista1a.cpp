#include <string>
#include <algorithm>

// Bilbioteca onde tem as caracteríticas da Matriz de Automatos
#include "Automato.h"

using namespace std;

// Linguagens
vector<string> Ln;
vector<string> Lm;

void ShowLanguage(vector<string> L){
     cout << '{';
    for(vector<string>::const_iterator i = L.begin(); i != L.end(); i++){
        cout << *i << ' ';
    }
    cout << '}' << endl;
}

// Retorna se o estado é marcado
bool IsMarked(int state){
    if (((Xm >> state)&=0x01) == 0x01)
        return true;
    else return false;
}

// Essa função retornará a linguagem com palavras de N letras a partir de um estado dado
void GetLanguageFromState(int N, int state = 0, string word_above =""){
    for(int i = 0; i < N; i++){
        int changes = 0;
        for(int j = 0; j < automata_matrix[state].size(); j++){
            char c = automata_matrix[state][j];
            if(find(E.begin(), E.end(), c) != E.end()){
                string word;
                if(N == 1){
                    word = word_above + c;
                    if(find(Ln.begin(), Ln.end(), word) == Ln.end()){
                        Ln.push_back(word);
                        if(IsMarked(j))
                            Lm.push_back(word);
                    }
                }
                else
                    GetLanguageFromState(N-1, j, word_above + c);
            }
        }
    }
}

int main()
{
    bool ans = true;
    do{
        string input;
        int N;
        cout << "Entre com o tamanho N das palavras para para obter a linguagens Ln e Lm: ";
        cin >> N;

        GetLanguageFromState(N);

        cout << "Ln: ";
        ShowLanguage(Ln);
        cout << "Lm: ";
        ShowLanguage(Lm);

        cout<< "Deseja verificar com outro valor N? [y/n] ";
        cin >> input;
        if(input != "y" && input != "yes" && input != "s" && input != "sim")
            ans = !ans;
        else{
            Ln.clear();
            Lm.clear();
        }
    }while(ans);
    return 0;
}

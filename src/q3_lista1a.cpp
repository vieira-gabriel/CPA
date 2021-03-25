#include <string>
#include <algorithm>
#include <map>

// Bilbioteca onde tem as caracteríticas da Matriz de Automatos
#include "Automato.h"

using namespace std;

vector<map<char, int>> MEF;

// Linguagens
vector<string> Ln;
vector<string> Lm;

vector<map<char, int>> MEF_Matrix_Gen(vector<vector<char>> automata){
    vector<map<char, int>> MEF;
    for(int i = 0; i < automata.size(); i++){
        map<char, int> state;
        for(vector<char>::const_iterator k = E.begin(); k != E.end(); k++){
            int to_state = -1;
            vector<char>::const_iterator it = find(automata[i].begin(), automata[i].end(), *k);
            if(it != automata[i].end())
                to_state = it - automata[i].begin();
            state.emplace(*k, to_state);
        }
        MEF.push_back(state);
    }
    return MEF;
}

// Retorna se o estado é marcado
bool IsMarked(int state){
    if (((Xm >> state)&=0x01) == 0x01)
        return true;
    else return false;
}

// Essa função retornará a linguagem com palavras de N letras a partir de um estado dado
void GetLanguageFromState(vector<vector<char>> automata, int N, int state = 0, string word_above = ""){
    for(int i = 0; i < N; i++){
        int changes = 0;
        for(int j = 0; j < automata[state].size(); j++){
            char c = automata[state][j];
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
                    GetLanguageFromState(automata, N-1, j, word_above + c);
            }
        }
    }
}

bool IsDeadlockMEF(map<char, int> input){
    map<char, int> deadlock_map = {{'a', -1}, {'b', -1}, {'c', -1}};
    return (input == deadlock_map);
}

bool IsDeadlock(vector<char> input, int state){
    vector<char> deadlock_vector = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
    if (input == deadlock_vector){
        cout << "Estado " << state << " é deadlock" << endl;
        return true;
    }
    return false;
}

bool IsLivelock(vector<vector<char>> automata, int state){
    Ln.clear();
    Lm.clear();

    GetLanguageFromState(automata, 5, state,"");
    if (Lm.size() == 0){
        cout << "Estado " << state << " é livelock" << endl;
        return true;
    }
    return false;
}


void Show_MEF(vector<map<char, int>> MEF){
    cout << "___|_a_|_b_|_c_|" << endl;
    for(int i = 0; i < MEF.size(); i++){
        cout << ' ' << i << " |";
        for(auto& state: MEF[i]){
                if(state.second == -1)
                    cout << "   |";
                else
                    cout << " " << state.second << " |";
        }
        cout << endl;
    }
}

void Show_MEF_withou_deadlock_and_livelock(vector<map<char, int>> MEF){
    cout << endl << "MEF sem Deadlock e Livelock" << endl << endl;
    cout << "___|_a_|_b_|_c_|" << endl;
    for(int i = 0; i < MEF.size(); i++){
        if(!IsDeadlockMEF(MEF[i])){
            cout << ' ' << i << " |";
            for(auto& state: MEF[i]){
                    if(state.second == -1)
                        cout << "   |";
                    else
                        cout << " " << state.second << " |";
            }
            cout << endl;
        }
    }
}

vector<vector<char>> CoAc(vector<vector<char>> automata){
    for(int i = 0; i < automata.size(); i++){
        if (IsDeadlock(automata[i], i) || IsLivelock(automata, i)){
            for(int j = 0; j < automata.size(); j++){
                automata[j][i] = 0x00;
            }
        }
    }
    return automata;
}

int main(){
    cout << "MEF original:" << endl << endl;
    Show_MEF(MEF_Matrix_Gen(automata_matrix));
    cout << endl;
    vector<map<char, int>> MEF = MEF_Matrix_Gen(CoAc(automata_matrix));
    Show_MEF_withou_deadlock_and_livelock(MEF);
    return 0;
}

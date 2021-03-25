#include <string>
#include <algorithm>
#include <map>

// Bilbioteca onde tem as caracteríticas da Matriz de Automatos
#include "Automato.h"

using namespace std;

vector<map<char, int>> MEF;

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

int main(){
    vector<map<char, int>> MEF = MEF_Matrix_Gen(automata_matrix);
    Show_MEF(MEF);
    return 0;
}

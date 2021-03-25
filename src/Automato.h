#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

// Matriz que define o automato
vector<vector<char>> automata_matrix{{0x00, 'a', 'b', 0x00, 0x00, 0x00, 0x00}, 
                                     {0x00, 'a', 0x00, 'c', 0x00, 0x00, 0x00},
                                     {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
                                     {0x00, 0x00, 0x00, 'c', 'a', 'b', 0x00, 0x00},
                                     {'c', 'b', 'a', 0x00, 0x00, 0x00, 0x00},
                                     {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 'a'},
                                     {0x00, 0x00, 0x00, 0x00, 0x00, 'c', 0x00}};

// Vetor com as letras no automato
vector<char> E{'a', 'b', 'c'};

// Mascara de bits que mostra quais estados são marcados
bitset<5> Xm = 0x19;
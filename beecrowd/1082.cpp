#include<iostream>
#include <vector>
using namespace std;

int char_to_num(char x) {
    return x-'a';
}

char num_to_char(int x) {
    return x+'a';
}


// cada vertice eh uma posiçao do vector adj.
void dfs(vector<vector<char>> adj, char v, vector<bool> vis) {
    int vertix = char_to_num(v); // armazena valor numerico do caracter
    vis[vertix] = true; // marca como visitado...

    for (int i; i<adj[vertix].size(); i++) { // para i menor que o numero de adjacencias de v... (i se torna o indice de adjacencias de cada vertice)
        if (!vis[ char_to_num(adj[vertix][i]) ]) { // caso nao esteja visitado
            dfs(adj, adj[vertix][i], vis);
        }
    }
}

int main() {
    int tests; cin >> tests;

    for (int i=0; i<tests; i++) { // para cada caso de teste

        int v, e; cin >> v, e;
        vector<vector<char>> adj(v); // input (arestas)
        vector<bool> vis(v);

        for (int i=0; i<e; i++) { // monta a lista de adjacência
            char v1, v2; cin >> v1, v2;
            adj[char_to_num(v1)].push_back(v2);
            adj[char_to_num(v2)].push_back(v1);
        }

        int count = 0;

        int ii = 0;
        while (ii<v) { // percorre a lista de adjacência
            if (!vis[ii]) { // caso o vertice nao esteja visitado, executa dfs nele e conta
                dfs(adj, num_to_char(i), vis);
                count++;

                ii++;
            }
        }

        cout << count;
        
    }

    return 0;
}
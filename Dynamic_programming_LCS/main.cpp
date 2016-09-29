#include <iostream>
#include <string>
#include <vector>
using namespace std;

int LCS(string X, string Y, int m, int n){

    int L[m+1][n+1]; //Tabela para armazenamento dos resultados
    int i, j;

    for (i=0; i<=m; i++){

        for (j=0; j<=n; j++){

            if (i == 0 || j == 0)
                L[i][j] = 0; //Define as linhas(A0x) e colunas(Ax0) inicialmente como zero

            else if (X[i-1] == Y[j-1]) // Se letras forem iguais salva na matriz o valor 1 + O valor na coordenada [i-1][j-1]
                L[i][j] = L[i-1][j-1] + 1;// Na tabela pega o valor da celula diagonal mais próxima e a soma

            else
                L[i][j] = max(L[i-1][j], L[i][j-1]); //Se não, acha o máximo entre as combinações removendo as letras (Max entre célula ao lado e célula acima)
     }
   }

    return L[m][n];

}
int main()
{
    vector <string> string_data;
    string word;

    while (true){
        getline(cin,word);
        if(cin.eof()) break;
        string_data.push_back(word);

    }
   for(unsigned int i = 0; i < string_data.size() - 1; i++) {

    cout << "Length of LCS is " << LCS( string_data[i],string_data[i+1], string_data[i].length() , string_data[i+1].length() ) << endl;

   }


    return 0;
}

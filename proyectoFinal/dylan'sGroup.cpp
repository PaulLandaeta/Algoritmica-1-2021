#include <bits/stdc++.h>
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
#define length(x) (sizeof(x) / sizeof(x[0]))
#define INF 100000010
using namespace std;
string texto;
string encontrar;

int main()
{
    texto = "hola no me gusta algoritmica";
    encontrar = "holar";

    "aaab"
    "aab"
    /*
cout << texto << endl;
cout << encontrar << endl;
*/
    int cont = 0;
    bool encontrado = false;
    for (int i = 0; i < texto.size(); i++)
    {
        if (texto[i] == encontrar[cont])
        {
            cont++;
        }
        else
        {
            cont = 0;
        }
        if (cont == encontrar.size())
        {
            cout << "True" << endl;
            encontrado = true;
            break;
        }
    }
    if (!encontrado)
    {
        cout << "False" << endl;
    }
}
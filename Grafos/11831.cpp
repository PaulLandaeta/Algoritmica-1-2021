#include <bits/stdc++.h> // Para importar todas librerias
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std;

int N, M, S, contStickers;
int pos[2];
char newIns;
char currentCondition;
char d[4] = {'L', 'S', 'O', 'N'};
char e[4] = {'O', 'S', 'L', 'N'};
vector<string> mapa;
queue<char> instructions;


void moveRobot(){
    while(!instructions.empty()){
       newIns = instructions.front();
        instructions.pop();
        if(newIns == 'D'){
            bool changed = false;
            for (int i=0; i<3; i++){
                if (d[i] == currentCondition){
                    currentCondition = d[i+1];
                    changed = true;
                    break;
                }
            }
            if (!changed){
                currentCondition = d[0];
            }
        } else if(newIns == 'E'){
            bool changed = false;
            for (int i=0; i<3; i++){
                if (e[i] == currentCondition){
                    currentCondition = e[i+1];
                    changed = true;
                    break;
                }
            }
            if (!changed){
                currentCondition = e[0];
            }
        } else if(newIns == 'F'){
            if (currentCondition == 'N'){
                if (pos[0]-1 >= 0  && mapa[pos[0]-1][pos[1]] != '#'){
                    if (mapa[pos[0]-1][pos[1]] == '*'){
                        contStickers++;
                        mapa[pos[0]-1][pos[1]] = '.';
                        }
                        pos[0] = pos[0] -1;
                    }
                
            } else if (currentCondition == 'L'){
                if (pos[1]+1 < M  && mapa[pos[0]][pos[1]+1] != '#'){
                    if (mapa[pos[0]][pos[1]+1] == '*'){
                        contStickers++;
                        mapa[pos[0]][pos[1]+1] = '.';
                        }
                        pos[1] = pos[1] +1;
                    }
            } else if (currentCondition == 'S'){
                if (pos[0]+1 < N  && mapa[pos[0]+1][pos[1]] != '#'){
                    if (mapa[pos[0]+1][pos[1]] == '*'){
                        contStickers++;
                        mapa[pos[0]+1][pos[1]] = '.';
                        }
                        pos[0] = pos[0] +1;
                    }
                } else if (currentCondition == 'O'){
                    if (pos[1]-1 >=0  && mapa[pos[0]][pos[1]-1] != '#'){
                        if (mapa[pos[0]][pos[1]-1] == '*'){
                            contStickers++;
                            mapa[pos[0]][pos[1]-1] = '.';
                            }
                            pos[1] = pos[1] -1;
                        }
                    }
            }
        }
    }



int main(){
    input;
    output;
    while ((cin>>N>>M>>S) && (N || M || S)){
        for (int i=0; i<N; i++){
            string row;
            cin>>row;
            mapa.push_back(row);
        }
        for (int i=0; i<S; i++){
            char ins;
            cin>>ins;
            instructions.push(ins);
        }
        for (int i=0; i<N; i++){
            for (int j=0; j<mapa[i].size(); j++){
                if (mapa[i][j] == 'N' ||mapa[i][j] == 'S' ||mapa[i][j] == 'L'||mapa[i][j] == 'O'){
                    pos[0] = i;
                    pos[1] = j;
                    currentCondition = mapa[i][j];
                }
            }
           
        }
        contStickers = 0;
        moveRobot();
        cout<<contStickers<<endl;
        
        mapa.clear();
        
    }
}
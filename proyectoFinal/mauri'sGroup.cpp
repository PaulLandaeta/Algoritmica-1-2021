void pattSearch(string text, string pattern){
     
        int tSize = (int)text.length();
        int pSize = (int)pattern.length();
     
        
        char tArray[tSize + 1];
        char pArray[pSize + 1];
     
        
        strcpy(tArray, text.c_str());
        strcpy(pArray, pattern.c_str());
     
        for (int i = 0; i < tSize; i++)
            cout << tArray[i];
    
    cout<<endl;
        for (int i = 0; i < pSize; i++)
            cout << pArray[i];
    cout<<endl;
    
    for(int i = 0; i <= tSize; i++){
        for (int j = 0; j < pSize ; j++){
            if (tArray[i + j] != pArray[j]){
                break;
            }
            if (j == pSize - 1){
                cout<<"Encontrado en posicion: "<<i<<endl;
            }
        }
    }
    
    
}
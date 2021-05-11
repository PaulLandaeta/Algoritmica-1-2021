char texto[];
char patron[];
int v[];

bool cadena(){
    for (int i = 0; i < sizeof(patron)/sizeof(patron[0]); i++){
        for (int j= 0; i < sizeof(patron)/sizeof(patron[0]); j++){
            if(patron[i] == patron [j]){
                v[i] = j++;
                i++;
            } else {
                v[i++] = 0;
            }
        }
    }
}
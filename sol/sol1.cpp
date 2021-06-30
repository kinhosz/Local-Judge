#include <stdio.h>
#include <math.h>
#define MAXCAIXAS 100

typedef struct {
    int x;
    int y;
    int z;
    int ID;
}R3;

long long int Powah (int Num, int Exp){
    int i;
    long long int base = 1;
    for(i=0;i<Exp;i++){
        base = Num*base;
    }
    return base;
}
double DistCal (R3 C1, R3 C2){
    double longeza;
    long long int X,Y,Z;
    X=Powah((C1.x-C2.x),2);
    Y=Powah((C1.y-C2.y),2);
    Z=Powah((C1.z-C2.z),2);
    longeza = sqrt(X+Y+Z);
    return longeza;
}

int main(){
    int N,i,j;
    double DistTemp;
    R3 Caixa[MAXCAIXAS],KixaTemp;
    R3 Kamyamoto;
    //Colocando ID nas Caixas
    for(i=0;i<MAXCAIXAS;i++){
        Caixa[i].ID=(i+1);
    }
    while(scanf("%d", &N) && N!=0){
        //Inicializando Kamyamoto
        Kamyamoto.x=0;
        Kamyamoto.y=0;
        Kamyamoto.z=0;
        //Adquirindo Coordenadas de cada caixa
        for(i=0;i<N;i++){
            scanf("%d %d %d", &Caixa[i].x, &Caixa[i].y, &Caixa[i].z);
        }
        DistTemp = DistCal(Kamyamoto,Caixa[0]);
        for(i=0;i<N;i++){
            //Checando se há alguma Dist Menor
            for(j=i+1;j<N;j++){
                if(DistCal(Kamyamoto,Caixa[j])<DistTemp){
                    DistTemp=DistCal(Kamyamoto,Caixa[j]);
                    KixaTemp=Caixa[i];
                    Caixa[i]=Caixa[j];
                    Caixa[j]=KixaTemp;
                }
            }
            //Caixa[i] é a menor
            Kamyamoto = Caixa[i];//Kamyamoto assume as coordenadas daquela caixa
            if(i < N-1){
                printf("%d ", Caixa[i].ID);
            }
            else{
                printf("%d\n", Caixa[i].ID);
            }
        }
        //Zerando caixas
        for(i=0;i<MAXCAIXAS;i++){
            Caixa[i].x=0;
            Caixa[i].y=0;
            Caixa[i].z=0;
            Caixa[i].ID = i+1;
        }
    }
}
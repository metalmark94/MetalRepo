

#include <iostream>

using namespace std;

int main ()
{
    //DICHIARAZIONE VARIABILI e COSTANTI
    
    int nr=3;
    int nc=3;
    int tot=nr*nc;
    
    int A[nr][nc];
    int i, j, z, c;
    char risp; 
    
    //CARICAMENTO MATRICE
    
    for (i=1; i<=nr; i++)
    { 
        for (j=1; j<=nc; j++)
        { 
            cout<<"Inserisci in valore alla "<<i<<" riga della "<<j<<" colonna:"<<endl;
            cin>>A[i][j];
        }
    }
    
    //RICHIESTA TIPO DI BUBBLE SORT
    
    cout<<"Dichiara il tipo di Bubble Sort ( [z] per 'Zig-Zag' o [s] per 'Spirale' ): ";
    cin>>risp;
    
    //CONDIZIONI
    
    //CONDIZIONE ZIG-ZAG  
    if (risp=='z' || risp=='Z')
    {
        
        //BUBBLE SORT ZIG ZAG MATRICE
        
        for (z=1; z<=tot; z++) 
        {
            for (i=1; i<nr; i++)
            {
                if (i%2!=0)
                {
                    for (j=1; j<nc; j++)
                    {
                        if (A[i][j] > A[i][j++])
                        {
                            c = A[i][j];
                            A[i][j] = A[i][j++];
                            A[i][j++] = c;
                        }
                    }
                   if (i!=nr)
                    {
                        if(A[i][nc]>A[i++][nc])
                        {
                            c=A[i][nc];
                            A[i][nc]=A[i++][nc];
                            A[i++][nc]=c;
                        }
                    }
                }
                
                else
                {
                    for (j=nr; j>1; j--)
                    {
                        
                        if(A[i][j]>A[i][j--])
                        {
                            c=A[i][j];
                            A[i][j]=A[i][j--];
                            A[i][j--]=c;
                        }
                    }
                    
                     if (i!=nr)
                    {
                        if(A[i][1]>A[i++][1])
                        {
                            c=A[i][1];
                            A[i][1]=A[i++][1];
                            A[i++][1]=c;
                        }
                    }
               }
           }
       }
    //}
    
    //CONDIZIONE SPIRALE
    else if (risp=='s' || risp=='S')
    {
        cout<<"Funzione non ancora disponibile";
        
        
        
        
        
        
        
    }
    else 
    {
        cout<<"Hai inserito una risposta non valida";
    }
    
    //VISUALIZZAZZIONE MATRICE
    
    cout<<endl<<endl;
    
    for (i=1; i<=nr; i++)
    { 
        for (j=1; j<=nc; j++)
        { 
            cout<<"\t\t"<<A[i][j]<<"\t\t|";
        }
        cout<<endl;
    }
    
    
    return 0;
}
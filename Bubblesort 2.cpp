//
//  Bubblesort2.0.cpp
//  Matrix Bubblesort Algorithm
//
//  Created by Marco Parolin on 03/10/13.
//

#include <iostream>
#include <ctime>
using namespace std;

int main ()
{
    //DICHIARAZIONE VARIABILI e COSTANTI
    
    const int nr=15;
    const int nc=4;
    const int tot=nr*nc;
    
    int A[nr][nc];
    int i, j, z, num, c, col, rig, contatore;
    char risp; 
    
    int x, y, colonna, riga;
    
    rig=nr;
    col=nc;
    num=1;
    
    riga=nr;
    colonna=nc;
    x=0;
    y=2;
    contatore=0;
    
    
    //CARICAMENTO MATRICE
    srand (time(NULL));
    for (i=1; i<=nr; i++)
    {
        
        for (j=1; j<=nc; j++)
        {
            num++;
            //          cout<<"Inserisci in valore alla "<<i<<" riga della "<<j<<" colonna:"<<endl;
            //          cin>>A[i][j];
            
            A[i][j]=rand() % 1000;
        }
    }
    
    cout<<endl<<endl;
    
    for (i=1; i<=nr; i++)
    { 
        for (j=1; j<=nc; j++)
        { 
            cout<<"\t\t"<<A[i][j]<<"\t\t|";
        }
        cout<<endl;
    }
    
    //RICHIESTA TIPO DI BUBBLE SORT
    
    cout<<"Dichiara il tipo di Bubble Sort ( [z] per 'Zig-Zag' o [s] per 'Spirale' ): ";
    cin>>risp;
    
    //CONDIZIONI
    
    //CONDIZIONE ZIG-ZAG  
    if (risp=='z'||risp=='Z')
    {
        //BUBBLE SORT ZIG ZAG
        
        for (z=1; z<=tot; z++)
        {
            for (i=1; i<=nr; i++)
            {            
                if (i%2!=0)
                {
                    for (j=1; j<nc; j++)
                    {
                        if(A[i][j]>A[i][j+1])
                        {
                            c=A[i][j];
                            A[i][j]=A[i][j+1];
                            A[i][j+1]=c;
                        }
                        
                    } 
                    if (i!=rig)
                    {
                        if(A[i][col]>A[i+1][col])
                        {
                            c=A[i][col];
                            A[i][col]=A[i+1][col];
                            A[i+1][col]=c;
                        }
                    }
                }
                else
                {
                    for (j=nc; j>1; j--)
                    {
                        if(A[i][j]>A[i][j-1])
                        {
                            c=A[i][j];
                            A[i][j]=A[i][j-1];
                            A[i][j-1]=c;
                        }
                    }
                    if (i!=rig)
                    {
                        if(A[i][1]>A[i+1][1])
                        {
                            c=A[i][1];
                            A[i][1]=A[i+1][1];
                            A[i+1][1]=c;
                        }
                    }
                }
                
                
            }
        }
        //FINE BUBBLE SORT ZIG ZAG
        
    }       
    
    //CONDIZIONE SPIRALE
    else if (risp=='s'||risp=='S')
    {
        //BUBBLE SORT SPIRALE
        
        for (z=1; z<=tot; z++)
        {
            
            x=0;
            y=2;
            
            for (j=1; j<colonna; j++)                                                   //PRIMA RIGA
            {
                if (A[1][j]>A[1][j+1])
                {
                    c=A[1][j];
                    A[1][j]=A[1][j+1];
                    A[1][j+1]=c;
                }
            }
            
            do 
            {
                
                
                if (y%2==0)                                                                 //DA ALTO A BASSO
                {
                    for (j=x+1; j<riga-x; j++)
                    {
                        if (A[j][colonna-x]>A[j+1][colonna-x])
                        {
                            c=A[j][colonna-x];
                            A[j][colonna-x]=A[j+1][colonna-x];
                            A[j+1][colonna-x]=c;
                        }
                    }
                                                                                            //DA DX A SX
                    for (j=colonna-x; j>x+1; j--)
                    {
                        if (A[riga-x][j]>A[riga-x][j-1])
                        {
                            c=A[riga-x][j];
                            A[riga-x][j]=A[riga-x][j-1];
                            A[riga-x][j-1]=c;
                        }
                    }
                    
                }
                
                else if (y%2!=0)                                                            //DA BASSO A ALTO
                {
                    for (j=riga-x; j>x+1; j--)
                    {
                        if (A[j][x+1]>A[j-1][x+1])
                        {
                            c=A[j][x+1];
                            A[j][x+1]=A[j-1][x+1];
                            A[j-1][x+1]=c;
                        }
                    }
                                                                                            //DA SX A DX
                    for (j=x+1; j<colonna-x; j++)
                    {
                        if (A[x+1][j]>A[x+1][j+1])
                        {
                            c=A[x+1][j];
                            A[x+1][j]=A[x+1][j+1];
                            A[x+1][j+1]=c;
                        }
                    }
                    
                }
                
                else 
                {
                    cout<< "ERROR: WARNING...";
                }
                
                y++;
                x++;
            }
            
            while (x<riga && x<colonna);
        }
        
        //FINE BUBBLE SORT SPIRALE
    }
    
    //CONDIZIONE RISPOSTA NON PREVISTA
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
#include <iostream>
#include <string>
using namespace std;

void baralho(string **cartas, string **jogadores){
    
    string a[106] = {};
    string aj[44] = {}; 
    
    int cont_arr = 0;
    int cont_bar = 0;
    
    for(int i = 1; i < 3; i++)
    {
        for(int j = 1; j < 14; j++)
        {
            for(int k = 1; k < 5; k++)
            {
                cont_bar +=1;
                if(cont_bar == 53)
                {
                    cont_bar=1;
                }
                
                cont_arr+=1;
                
                if(to_string(j).size() < 2)
                {
                    cartas[i][cont_bar] = to_string(k)+'0'+to_string(j)+to_string(i);
                    a[cont_arr] = cartas[i][cont_bar];
                }
                else
                {
                    cartas[i][cont_bar] = to_string(k)+to_string(j)+to_string(i);
                    a[cont_arr] = cartas[i][cont_bar];
                }
                
            }
        }
        
    }
    
    srand(time(0));
    
    int c = 0;
    int ver = 0;
    while(c < 44)
    {
        string chave = a[rand()%106];
        ver = 0;
        
        if(chave != "")
        {
            for(int i=0;i<44;i++)
            {
                if(chave == aj[i])
                {
                    ver+=1;
                }
            }
            
            if(ver == 0)
            {
                aj[c] = chave;
                c++;
            }
        }
        
    }
    
    ver = 0;
    for(int i = 1; i < 5; ++i)
    {
        cout << "Jogador nº " << i << ": ";
        for(int j = 1; j< 12; ++j)
        {
            
            jogadores[i][j] = aj[ver];
            
            cout << jogadores[i][j] << " ";
            ver +=1;
        }
        
        cout << endl;
    }
    
    
}

int main(int argc, char** argv)
{
    
    string **bar;
    
    string **mao;
    
    bar = new string*[3];
    
    mao = new string*[5];
    
    for(int i = 1; i < 3; i++)
    {
        bar[i] = new string[53];
    }
    
    for(int i =1; i < 5; i++)
    {
        mao[i] = new string[12];
    }
    
    baralho(bar, mao);
    delete[] bar, mao;
    
    return 0;
}






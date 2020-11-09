#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <bitset>
#include <sstream>
#include <Windows.h>

using namespace std;

class Cesar
{
private:

public:

    Cesar(/* args */);
    ~Cesar();

    void chiffrement(string x){

        ifstream myFlux(x);

        int key; cout << "\nCle de chiffrement Cesar (exemple : 4) : "; cin >> key;

        if (myFlux)
        {
            int i;
            char tab[255];
            for (i = 0; i < 255; i++)
            {
                tab[i] = i;
            }
            
            char letter;
            string line;
            string crypt;   

            while (myFlux.get(letter))
            {
                line += letter;
                int n = 0;
                while (tab[n] != letter)
                {
                    n++;
                }
                crypt += tab[n+key];
            }
            
            int j;
            for (j = 1; j <= 5; j++)
            {
                
                if (j == 1)
                {  
                    cout << "\nChiffrement en cours .";
                    Sleep(1000);                    
                    
                }
                else if (j == 5)
                {
                    cout << "." << endl;
                    Sleep(1000);
                }
                else
                {
                    cout << ".";
                    Sleep(1000);
                }
                
            }
            

            ofstream myFlux2("C:/Users/MG_ByJfMarie/Documents/Code/Fichier/Chiffrement_chiffrer.txt");
            myFlux2 << crypt << endl;
        }
        else
        {
            cout << "ERREUR ! Impossible d'ouvrir le fichier à lire !" << endl;
        }
        
    }

    void dechiffrement(string x){
        
        ifstream myFlux(x);

        int key; cout << "\nCle de Dechiffrement Cesar (exemple : 4) : "; cin >> key;

        if (myFlux)
        {
            int i;
            char tab[255];
            for (i = 0; i < 255; i++)
            {
                tab[i] = i;
            }
            
            char letter;
            string line;
            string crypt;   

            while (myFlux.get(letter))
            {
                line += letter;
                int n = 0;
                while (tab[n] != letter)
                {
                    n++;
                }
                crypt += tab[n-key];
            }
            
            int j;
            for (j = 1; j <= 5; j++)
            {
                
                if (j == 1)
                {  
                    cout << "\nDechiffrement en cours .";
                    Sleep(1000);                    
                    
                }
                else if (j == 5)
                {
                    cout << "." << endl;
                    Sleep(1000);
                }
                else
                {
                    cout << ".";
                    Sleep(1000);
                }
                
            }
            

            ofstream myFlux2("C:/Users/MG_ByJfMarie/Documents/Code/Fichier/Dechiffrement_dechiffrer.txt");
            myFlux2 << crypt << endl;
        }
        else
        {
            cout << "ERREUR ! Impossible d'ouvrir le fichier à lire !" << endl;
        }

    }
};

Cesar::Cesar(/* args */)
{
}

Cesar::~Cesar()
{
}

//--------------------------------------------

class xOR
{
private:
    /* data */
public:
    xOR(/* args */);
    ~xOR();

    string stringToBinary(string str) {

    string bin;

    for (int i = 0; i < str.size(); i++) {

        bin += bitset<8>(str[i]).to_string();
    }

    return bin;
    }

    void chiffrement(string x){

        ifstream myFlux(x);

        string key; cout << "\nCle de chiffrement xOR (exemple : CLE) : "; cin >> key;
        string cleBinaire = stringToBinary(key);
        int compteurCle = 0;
        

        if (myFlux)
        {
            
            char tab[255];
            for (int i = 0; i < 255; i++)
            {
                tab[i] = i;
            }
            
            char letter;
            string line;
            string bins;
            string crypt;   

            while (myFlux.get(letter))
            {
                line += letter;
                int n = 0;
                while (tab[n] != letter)
                {
                    n++;
                }
                bins += bitset<8>(tab[n]).to_string();
                
            }

            

            for (int i = 0; i < bins.size(); i++)
            {
                
                if (compteurCle == cleBinaire.size())
                {
                    compteurCle = 0;
                }
                
                if (bins[i] == cleBinaire[compteurCle])
                {
                    crypt += "0";
                }
                else
                {
                    crypt += "1";
                }
                compteurCle++;
            }
                        
            for (int j = 1; j <= 5; j++)
            {
                
                if (j == 1)
                {  
                    cout << "\nChiffrement en cours .";
                    Sleep(1000);                    
                    
                }
                else if (j == 5)
                {
                    cout << "." << endl;
                    Sleep(1000);
                }
                else
                {
                    cout << ".";
                    Sleep(1000);
                }
                
            }
            

            ofstream myFlux2("C:/Users/MG_ByJfMarie/Documents/Code/Fichier/Chiffrement_binaire.txt");
            myFlux2 << crypt << endl;
        }
        else
        {
            cout << "ERREUR ! Impossible d'ouvrir le fichier à lire !" << endl;
        }
        
    }

    void dechiffrement(string x){
        
        ifstream myFlux(x);

        string key; cout << "\nCle de Dechiffrement xOR (exemple : CLE) : "; cin >> key;
        string cleBinaire = stringToBinary(key);
        int compteurCle = 0;

        if (myFlux)
        {
            char tab[255];
            for (int i = 0; i < 255; i++)
            {
                tab[i] = i;
            }
            
            char letter;
            string line;
            string crypt; 
            string bins;  

            while (myFlux.get(letter))
            {
                line += letter;
                int n = 0;
                while (tab[n] != letter)
                {
                    n++;
                }
                bins += tab[n];
            }


            for (int i = 0; i < bins.size(); i++)
            {
                if (compteurCle == cleBinaire.size())
                {
                    compteurCle = 0;
                }
                
                if (bins[i] == '0')
                {
                    crypt += cleBinaire[compteurCle];
                }
                else if (cleBinaire[compteurCle] == '0')
                {
                    crypt += '1';
                }
                else
                {
                    crypt += '0';
                }
                  
                compteurCle++;
            }

            stringstream sstream(crypt);
            string decrypt;
            while(sstream.good())
            {
                bitset<8> bits;
                sstream >> bits;
                char c = char(bits.to_ulong());
                decrypt += c;
            }

            for (int j = 1; j <= 5; j++)
            {
                
                if (j == 1)
                {  
                    cout << "\nDechiffrement en cours .";
                    Sleep(1000);                    
                    
                }
                else if (j == 5)
                {
                    cout << "." << endl;
                    Sleep(1000);
                }
                else
                {
                    cout << ".";
                    Sleep(1000);
                }
                
            }
            

            ofstream myFlux2("C:/Users/MG_ByJfMarie/Documents/Code/Fichier/Dechiffrement_dechiffrer_binary.txt");
            myFlux2 << decrypt << endl;
        }
        else
        {
            cout << "ERREUR ! Impossible d'ouvrir le fichier à lire !" << endl;
        }

    }
};

xOR::xOR(/* args */)
{
}

xOR::~xOR()
{
}



int main(){

    system("cls");

    int rep1;
    int rep2;

    cout << "\t\t\t\t/=========================================================\\" << endl;
	cout << "\t\t\t\t| Programme de chiffrement/dechiffrement  (par ByJfMarie) |" << endl;
	cout << "\t\t\t\t\\=========================================================/" << endl << endl;

    Cesar code1;
    xOR code;

    string file_d = "C:/Users/MG_ByJfMarie/Documents/Code/Fichier/Chiffrement_base.txt";
    string file_dc = "C:/Users/MG_ByJfMarie/Documents/Code/Fichier/Chiffrement_chiffrer.txt";
    string file_cb = "C:/Users/MG_ByJfMarie/Documents/Code/Fichier/Chiffrement_binaire.txt";
    string file_dcb = "C:/Users/MG_ByJfMarie/Documents/Code/Fichier/Dechiffrement_dechiffrer_binary.txt";
    string file_c = "C:/Users/MG_ByJfMarie/Documents/Code/Fichier/Dechiffrement_base.txt";
    

    cout << "Voulez vous : \n\n\t[1] -> Chiffrer/Dechiffrer en Cesar \n\n\t[2] -> Chiffrer/Dechiffrer en xOR \n\n\t[3] -> Chiffrer/Dechiffrer avec les deux chiffrements\n\nReponse : ";
    cin >> rep1;

    if (rep1 == 1)
    {
        cout << "\nVoulez vous : \n\n\t[1] -> Chiffrer \n\n\t[2] -> Dechiffrer \n\nReponse : ";
        cin >> rep2;

        if (rep2 == 1)
        {
            code1.chiffrement(file_d);
            Sleep(1000);
        }
        else if (rep2 == 2)
        {
            code1.dechiffrement(file_c);
            Sleep(1000);
        }
    }
    else if (rep1 == 2)
    {
        cout << "\nVoulez vous : \n\n\t[1] -> Chiffrer \n\n\t[2] -> Dechiffrer \n\nReponse : ";
        cin >> rep2;

        if (rep2 == 1)
        {
            code.chiffrement(file_d);
            Sleep(1000);
        }
        else if (rep2 == 2)
        {
            code.dechiffrement(file_cb);
            Sleep(1000);
        }
    }
    else
    {
        cout << "\nVoulez vous : \n\n\t[1] -> Chiffrer \n\n\t[2] -> Dechiffrer \n\nReponse : ";
        cin >> rep2;

        if (rep2 == 1)
        {
            code1.chiffrement(file_d);
            code.chiffrement(file_dc);
            Sleep(1000);
        }
        else if (rep2 == 2)
        {
            code.dechiffrement(file_cb);
            code1.dechiffrement(file_dcb);
            Sleep(1000);
        }
        
    }

    cout << "\nAppuer sur \"Enter\" pour continuer ..." << endl;
    cin.ignore();
    cin.get();
    return EXIT_SUCCESS;
}
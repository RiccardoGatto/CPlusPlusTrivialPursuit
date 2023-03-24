#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <time.h>
#include <Windows.h>
#include <process.h>

using namespace std;

int const NUMERODOMANDE = 30;
int const SINGOLADOMANDA = 5;

void stampaConDelay(string frase)
{
    for (int i = 0; i < frase.length(); i++)
    {
        cout << frase[i];
        Sleep(15);
    }
}
string *getDomanda(int numero)
{
    ifstream fileDomanda;
    fileDomanda.open("domande.txt");
    string quest;
    string *domanda = new string[SINGOLADOMANDA];
    while (fileDomanda.is_open() == false)
    {
        fileDomanda.open("domande.txt");
    }
    for (int i = 0; i <= numero * 5; i++)
    {
        getline(fileDomanda, quest);
    }
    domanda[0] = quest;
    for (int i = 1; i < SINGOLADOMANDA; i++)
    {
        getline(fileDomanda, domanda[i]);
    }
    return domanda;
}
string getRispostaEsatta(int numero)
{
    string ris;
    ifstream fileRisposta;
    fileRisposta.open("risposte.txt");
    while (fileRisposta.is_open() == false)
    {
        fileRisposta.open("risposte.txt");
    }
    for (int i = 0; i <= numero; i++)
    {
        getline(fileRisposta, ris);
    }
    return ris;
}
void ilMioPiccoloMain()
{
    int giocata = 5;
    int punti = 0;
    int risposta;
    cout << endl;
    bool domande[NUMERODOMANDE];
    for (int i = 0; i < NUMERODOMANDE; i++)
    {
        domande[i] = false;
    }
    for (int j = 0; j < giocata; j++)
    {
        srand(time(NULL));
        int indiceDomanda = rand() % NUMERODOMANDE;
        while (domande[indiceDomanda])
        {
            indiceDomanda = rand() % NUMERODOMANDE;
        }
        domande[indiceDomanda] = true;
        string *domanda = getDomanda(indiceDomanda);
        string rispostaEsatta = getRispostaEsatta(indiceDomanda);
        stampaConDelay(domanda[0] + "\n");
        stampaConDelay("-------------------------------------------------------------------\n");
        for (int i = 1; i < SINGOLADOMANDA; i++)
        {
            stampaConDelay(to_string(i) + ") ");
            stampaConDelay(domanda[i] + "\n");
        }
        stampaConDelay("-------------------------------------------------------------------\n");
        stampaConDelay("Qual e' la risposta esatta?  ");
        cin >> risposta;
        while ((risposta<1) or (risposta>4))
        {
            stampaConDelay("Cerca almeno di mettere un numero giusto... coglione... ");
            cin >> risposta;
        }
        if (rispostaEsatta == domanda[risposta])
        {
            stampaConDelay("GIUSTOOOOOO!!\n\n");
            punti += 10;
        }
        else
        {
            stampaConDelay("Sbagliato...\n\n");
        }
    }
    stampaConDelay("\nHai totalizzato......... ");
    cout << punti;
    stampaConDelay(" punti!");
}

int main()
{
    ilMioPiccoloMain();
}
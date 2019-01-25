//#include <LiquidCrystal.h>
int num, newnum;
int somma=0;
bool vittoria1=false;
bool vittoria2=false;
bool primo=true;
bool rifare=true;
char g;
int newmeta;
void setup() 
{
  Serial.begin(9600);  
}
void loop() 
{
    Serial.println("Premere 1 per far giocare prima il Giocatore 1. Premere 2 per far giocare prima il Giocatore 2.\nIl messaggio verrà ripetuto ogni 10 secondi per evitare l'inattività.");
    delay(500);
    g=(char)Serial.read();//la forzo come carattere, ricordarsi di cambiare
    switch(g){
      case '1':
      {
        newmeta=settaggio();      
        Serial.println(newmeta);
        delay(1000);
        gioco("Giocatore 1","Giocatore 2",newmeta);
        break;
      }
      case '2':
      {
        newmeta=settaggio(); 
        gioco("Giocatore 2","Giocatore 1",newmeta);
        break;
      }
      default:
      {
        Serial.println("Comando non valido.");
        break;
      }
    }
}
int settaggio()//funzione per impostare la meta come numero compreso tra 30 e 100
{
  int meta; 
      Serial.println("Inserisci il valore della meta compreso fra 30 e 100.");
      delay(5000);
      meta=(int)Serial.read();
      if((meta>=30)&&(meta<=100))
      return (int)meta;
}
void gioco(String g1, String g2, int meta)//turno principale
{
  int z=0;//variabile che contiene i totali
  int m=meta+1;
  int k=0;//variabile che contiene le puntate del giocatore 1
  int j=0;//variabile che contiene le puntate del giocatore 2
  while(z<settaggio())
  {
    Serial.println(g1+", inserisci un numero da 1 a 6.");
    k=Serial.read();//giocatore 1
    if((k>0) && (k<7) && (k!=j) && (k!=7-j))//verifica che la puntata sia tra 1 e 6 e che non sia uguale a quella precedente o all'equivalente dell'altra faccia del dado
    {
      z=z+k;
      if(z==meta)
      {
        Serial.println("Hai vinto!");
      }
      else
      {
        if(z>meta)
          Serial.println("Hai perso!");
        else
        {
          Serial.println(g2+", inserisci un numero da 1 a 6.");
          j=Serial.read();//giocatore 2
          if((j>0) && (j<7) && (j!=k) && (j!=7-k))//verifica che la puntata sia tra 1 e 6 e che non sia uguale a quella precedente o all'equivalente dell'altra faccia del dado
          {
            z=j+z;
            if(z==meta)
            {
              Serial.println("Hai vinto!");
            }
          }
        }
      }
    }
  }
}

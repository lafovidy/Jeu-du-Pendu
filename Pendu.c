/*VARIABLES:
    i:entiers
    j:entiers
    listemots[5][10]:chaine de caractere
    motsecret[10]:chaine de caractere
    motaffiche[10]:chaine de caractere
    lettretrouve:booleen
    victoire:booleen
    vies:entiers
    longueur:entiers
  DEBUT
    def choisirmot()
      DEBUT
        listemots[5][10]<-{'banane','corbeau','sauce','mozarella','pute'}
        indiceAuHasard<-HASARD(0,4)
        RETOURNER(listemots[indiceAuHasard]
      FIN
    def calculerLongueur(motsecret:chaine de caractere)
      DEBUT
         POUR(i<-0,motsecret[i]!='\0',i<-i+1)
          longueur<-i+1
        FINPOUR
        RETOURNER(longueur)
      FIN
    def initialisermotmasquer(motsecret[]:chaine de caractere,motaffiche[]:chaine de caractere)
      DEBUT
        POUR(i<-0,i<longueur,i<-i+1)
          motaffiche[i]<-'_'
        FINPOUR
      FIN
    def affichageInterface(motaffiche:chaine de caractere,vies)
      DEBUT
        AFFICHER("mot à deviner: "motaffiche)
        AFFICHER("Nombre de vie restant: ",vies)
      FIN
    def saisirLettre()
      DEBUT
        lettre:caractere
        AFFICHER("Entrez votre lettre: ")
        LIRE(lettre)
        RETOURNER(lettre)
      FIN
    def verification(motsecret:chaine de caractere,lettre:chaine de caractere)
      DEBUT
        lettretrouvee<-FAUX
        POUR(i<-0,i<longueur,i<-i+1)
          SI(lettre=motsecret[i])ALORS
            motaffiche[i]<-lettre
            lettretrouvee<-VRAI
          FINSI
        FINPOUR
        RETOURNER(lettretrouvee)
      FIN
    def testvictoire(motaffiche:chaine de caractere,motsecret:chaine de caractere)
      DEBUT
        POUR(i<-0,motaffiche[i]!='\0',i<-i+1)
          SI(motaffiche[i]='_')ALORS
            RETOURNER(FAUX)
          FINSI
        FINPOUR
        RETOURNER(VRAI)
      FIN
    def afficherFinDePartie(victoire,motsecret)
      DEBUT
        SI(victoire=VRAI)ALORS
          AFFICHER("BRAVO!")
        SINON
          AFFICHER("💀️PENDU!"
        FINSI
      FIN
    FIN*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
void choisirMot(char *motsecret);
int calculLongueur(char *motsecret);
void initialiserMasque(char *motsecret,char *motaffiche);
void afficherInterface(char *motaffiche,int *vie);
char saisirLettre();
int verifierLettre(char lettre,char *motsecret,char *motaffiche,int *vie);
int testerVictoire(char *motaffiche);
void afficherFinDePartie(int victoire,char *motsecret);
void choisirMot(char *motsecret)
{
  char listeMots[56][15]={
    "banane",
    "corbeau",
    "sauce",
    "pute",
    "mozarella",
    "beta",
    "bonjour",
    "miserable",
    "pasteur",
    "papa",
    "bonbon",
    "salace",
    "pervert",
    "sexe",
    "bebe",
    "caca",
    "puceau",
    "vierge",
    "lion",
    "scorpion",
    "batard",
    "capitale",
    "non",
    "oui",
    "corde",
    "gens",
    "enfer",
    "ciel",
    "paradis",
    "gentil",
    "iris",
    "asteque",
    "ange",
    "dieu",
    "rare",
    "espece",
    "genie",
    "maitresse",
    "bistro",
    "connard",
    "con",
    "pakistan",
    "dessin",
    "france",
    "angleterre",
    "jamaique",
    "malte",
    "equateur",
    "madagascar",
    "angola",
    "nigeria",
    "alcool",
    "janvier",
    "venezuela",
    "allemagne",
    "kazakstan"
  };
  int indiceAuHasard=rand()%56;
  strcpy(motsecret,listeMots[indiceAuHasard]);
}
int calculLongueur(char *motsecret)
{
  int i,longueur;
  longueur=0;
  for(i=0;motsecret[i]!='\0';i+=1)
  {
    longueur=i+1;
  }
  return(longueur);
}
void initialiserMasque(char *motsecret,char *motaffiche)
{
  int i;
  int longueur=calculLongueur(motsecret);
  for(i=0;i<longueur;i+=1)
  {
    motaffiche[i]='_';
  }
  motaffiche[i]='\0';
}
void afficherInterface(char *motaffiche,int *vie)
{
  system("clear");
  printf("=== JEU DU PENDU ===\n");
  int erreurs=6-*vie;
  if(erreurs>0)
  {
    switch(erreurs)
    {
      case 0:
        printf(" +---+\n");
        printf(" |   |\n");
        printf("     |\n");
        printf("     |\n");
        printf("     |\n");
        printf("     |\n");
        break;
      case 1:
        printf(" +---+\n");
        printf(" |   |\n");
        printf(" O   |\n");
        printf("     |\n");
        printf("     |\n");
        printf("     |\n");
        break;
      case 2:
        printf(" +---+\n");
        printf(" |   |\n");
        printf(" O   |\n");
        printf(" |   |\n");
        printf("     |\n");
        printf("     |\n");
        break; 
      case 3:
        printf("  +---+\n");
        printf("  |   |\n");
        printf("  O   |\n");
        printf(" /|   |\n");
        printf("      |\n");
        printf("      |\n");
        break; 
     case 4:
        printf("  +---+\n");
        printf("  |   |\n");
        printf("  O   |\n");
        printf(" /|\\  |\n");
        printf("      |\n");
        printf("      |\n");
        break; 
      case 5:
        printf("  +---+\n");
        printf("  |   |\n");
        printf("  O   |\n");
        printf(" /|\\  |\n");
        printf(" /    |\n");
        printf("      |\n");
        break; 
      case 6:
        printf("  +---+\n");
        printf("  |   |\n");
        printf("  O   |\n");
        printf(" /|\\  |\n");
        printf(" / \\  |\n");
        printf("      |\n");
        break; 
    }
    printf("C'EST PAS ÇA 😂️😂️\n");
  }
  else
  {
    printf("Pas d'erreur pour l'instant\n");
  }
  printf("====================\n\n");
  printf("Mot à deviner: %s\n",motaffiche);
  printf("Nombre de vie restant: %d\n",*vie);
}
char saisirLettre()
{
  char lettre;
  printf("Entrez votre lettre: ");
  scanf(" %c",&lettre);
  return(lettre);
}
int verifierLettre(char lettre,char *motsecret,char *motaffiche,int *vie)
{
  int lettretrouvee=0,i;
  for(i=0;motsecret[i]!='\0';i+=1)
  {
    if(lettre==motsecret[i])
    {
      motaffiche[i]=lettre;
      lettretrouvee=1;
    }
  }
  if(lettretrouvee==0)
  {
    *vie-=1;
  }
  return(lettretrouvee);
}
int testerVictoire(char *motaffiche)
{
  int i,victoire=1;
  for(i=0;motaffiche[i]!='\0';i+=1)
  {
    if(motaffiche[i]=='_')
    {
      victoire=0;
    }
  }
    return(victoire);
}
void afficherFinDePartie(int victoire,char *motsecret)
{
  if(victoire==1)
  {
    printf("BRAVO!\n");
  }
  else
  {
    printf("💀️ PENDU!\n");
    printf("En fait le mot était %s\n",motsecret);
  }
}
int main()
{
  char motsecret[20],motaffiche[20],lettre;
  int vie=6,victoire=0,longueur,lettretrouvee=0;
  srand(time(NULL));
  choisirMot(motsecret);
  longueur=calculLongueur(motsecret);
  initialiserMasque(motsecret,motaffiche);
  while(vie>0&&victoire==0)
  {
    afficherInterface(motaffiche,&vie);
    lettre=saisirLettre();
    lettretrouvee=verifierLettre(lettre,motsecret,motaffiche,&vie);
    victoire=testerVictoire(motaffiche);
  }
  afficherInterface(motaffiche,&vie);
  afficherFinDePartie(victoire,motsecret);
  return(0);
}
  
  
      

    
      
        
          
        
    
            
          
            

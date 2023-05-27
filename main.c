#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
 struct Etudiant
  {
      int NCIN;
      char NOM[20];
      char PRENOM[20];
      int age;
  };
  struct Etudiant Etud;
   struct  BACC
  {
      float MOYENNE;
      char SERIEBAC[20];
      float NOTEMATH;
      float NOTEPHY;
  };
  struct BACC BAC;
  struct CHOIX
  {
    char CHOIX1[200];
    char CHOIX2[200];
    char CHOIX3[200];
  };
  struct CHOIX CH;

  void CANDIDATURE()//procedure qui fait entrer les etudiants
  {
    FILE *fich;
    int rep;
    fich = fopen("etudiants.txt","a");
    fich = fopen("bac.txt","a");
    CHOIX1 ='INFORMATIQUE';
    fich = fopen("choix.txt","a");
    if(fich!=NULL)
    do{
      printf("--------INFORMATION SUR LE CANDIDAT--------");
      printf("Entrer le NCIN :\t");
      scanf("%d",&Etud.NCIN);
      printf("Entrer le NOM :\t");
      scanf("%s",&Etud.NOM);
      printf("Entrer le PRENOM :\t");
      scanf("%s",&Etud.PRENOM);
      printf("Entrer l'age :\t");
      scanf("%d",&Etud.age);
      printf("--------INFORMATION SUR LE BACALAUREAT--------");
      printf("Entrer la MOYENNE :\t");
      scanf("%f",&BAC.MOYENNE);
      printf("Entrer la SERIE :\t");
      scanf("%s",&BAC.SERIEBAC);
      printf("Entrer la NOTE DE MATHEMATIQUE :\t");
      scanf("%f",&BAC.NOTEMATH);
      printf("Entrer la NOTE DE PHYSIQUE :\t");
      scanf("%f",&BAC.NOTEPHY);
      printf("--------INFORMATION SUR LE CHOIX--------");
      printf("Entrer le DEUXIEME CHOIX :\t");
      scanf("%s",&CH.CHOIX2);
      printf("Entrer le troisieme choix :\t");
      scanf("%s",&CH.CHOIX3);
      fscanf(fich,"%d;%s;%s;%d\n",&Etud.NCIN,&Etud.NOM,&Etud.PRENOM,&Etud.age);
      fscanf(fich,"%f,%s;%f;%f\n",&BAC.MOYENNE,&BAC.SERIEBAC,&BAC.NOTEMATH,&BAC.NOTEPHY);
      fscanf(fich,"%s;%s\n",&CH.CHOIX2,&CH.CHOIX3);
      printf("Voulez-vous continuer ?");
      printf("1-OUI\n2-NON");
      scanf("%d",&rep);
    }while(rep==1);
    fclose(fich);
  }

  int recherche(int Numrech)//fonction qui recherche un etudiant cette fonction permet d'ajouter un etudiant que si son numero n'existe pas;
  {
    FILE *fich;
    fich = fopen("etudiants.txt","r");//chemin d'acess qu fichier "etudiants"
    do
    {
       fscanf(fich,"%d;%s;%s;%d\n",&Etud.NCIN,&Etud.NOM,&Etud.PRENOM,&Etud.age);//permet de lire ligne par lig
       fflush(stdin);//on libere la memoire
       if(Etud.NCIN == Numrech)//on verifie si le numero de l'etudiant est egale au numero recherche
       {
          fclose(fich);
          return 1;//le programme retourne 1 s'il trouve le numero recherche
       }
    }while(!feof(fich));
    fclose(fich);
    return -1;//dans le cas contraire il retourne -1
  }
  /*------------PROCEDURE D'AJOUT------------*/
  void AjouterEtudiant()
  {
    int NCIN;
    int rep;
    FILE *fich;
    fich=fopen("etudiants.txt","a");
    FILE *fich;
    fich = fopen("bac.txt","a");
    FILE *fich;
    fich = fopen("choix.txt","a");
    printf("\n Entrer le numero de la NCIN de l'etudiant a ajouter :\t");
    scanf("%d",&NCIN);
    fflush(stdin);//on libere la memoire
    while(recherche(Numrech)==1)//on verifie si l'etudiant entre existe deja
    {
      printf("\n Cette d'etudiant existe deja\n");
      printf("\nEntrer le NCIN d'un etudiant qui n'existe pas :");
      scanf("%d",&Numrech);
    }
    struct Etudiant Etud;
    struct CHOIX CH;
    struct BACC BAC;
    Etud.Numrech=NCIN;
    CHOIX1 = 'INFORMATIQUE';
    do{
    printf("--------INFORMATION SUR LE CANDIDAT--------");
    printf("\n Entrer le nom :\t");
    gets(Etud.NOM);
    fflush(stdin);//on libere la memoire
    printf("\n Entrer le prenom :\t");
    gets(Etud.PRENOM);
    fflush(stdin);//on libere la memoire
    printf("\n Entrer l'age :\t");
    scanf("%d",&Etud.age);
    fflush(stdin);
    printf("--------INFORMATION SUR LE CHOIX--------");
    printf("\n Entrer le CHOIX2 :");
    gets(CH.CHOIX2);
    fflush(stdin);
    printf("\n Entrer le CHOIX3 :");
    gets(CH.CHOIX3);
    fflush(stdin);
    printf("--------INFORMATION SUR LE BACALAUREAT--------");
    printf("\nEntrer la moyenne obtenue au bac :");
    scanf("%f",&BAC.MOYENNE);
    fflush(stdin);
    printf("\nEntrer la SERIEBACC :");
    gets(BAC.SERIEBAC);
    fflush(stdin);
    printf("\nEntrer la note de mathematique :");
    scanf("%f",&BAC.NOTEMATH);
    fflush(stdin);
    printf("\nEntrer la note en physique :");
    scanf("%f",&BAC.NOTEPHY);
    fflush(stdin);
    fprintf(fich,"%s;%s;%s\n",CH.CHOIX1,CH.CHOIX2,CH.CHOIX3);
    fprintf(fich,"%d;%s;%s;%d\n",Etud.NCIN,Etud.NOM,Etud.PRENOM,Etud.age);
    fprintf(fich,"%f;%s;%f;%f\n",BAC.MOYENNE,BAC.SERIEBAC,BAC.NOTEMATH,BAC.NOTEPHY);
    printf("Voulez vous continuer ?");
    scanf("%d",&rep);
  }while(rep == 1);
    fclose(fich);
}
/*-------------RECHERCHE ET AFFICHE-------------*/
/*void recherche()
{
   struct Etudiant Etud;
   struct BACC BAC;
   struct CHOIX CH;
  int NCINR;
  int rep;
  FILE*fich;
  fich = fopen("etudiants.txt","r");
  do{
    printf("\n Entrer le numero de l'Etudiant :\n");
    scanf("%d",&NCIN);


   do{
      fscanf("%d;%s;%s;%d\n",&Etud.NCIN,&Etud.NOM,&Etud.PRENOM,&Etud.age);
      if(NCINR == Etud.NCIN)
     {
      printf("----------Information sur l'etudiant :----------\n\n");
      printf("Numero du candidat\t: %d\n",Etud.NCIN);
      printf("Nom du candidat\t: %s\n",Etud.NOM);
      printf("Prenom du candidat\t: %s\n",Etud.PRENOM);
      printf("age du candidat\t: %d\n",Etud.age);
      printf("----------Information sur l'etudiant sur son BACALAUREAT :----------\n\n");
      printf("moyenne du candidat\t: %f\n",BAC.MOYENNE);
      printf("serie du bac du candidat\t: %s\n",BAC.SERIEBAC);
      printf("note de mathematique du candidat\t: %f\n",BAC.NOTEMATH);
      printf("note de physique du candidat\t: %f\n",BAC.NOTEPHY);
      printf("----------Information sur l'etudiant sur son CHOIX :----------\n\n");
      printf("CHOIX1 du candidat\t: %s\n",CHOIX1);
      printf("CHOIX2 du candidat\t: %s\n",CH.CHOIX2);
      printf("CHOIX3 du candidat\t: %s\n",CH.CHOIX3);
     }
   }while(!feof(fich));
   printf("Voulez vous continuer ?");
 }while(rep==1);
 */
}
int main()
{
    int choix,rep;
    do
    {
    printf("\t\t\t\t\tMENU :t\t\t\t\t\t");
    printf("1-creer une liste de selection\n");
    printf("2-Ajouter un etudiants\n");
    printf("entrer un choix :\t");
    scanf("%d",&choix);
    printf("voulez vous continuer :\t");
    printf("\n1-OUI\n2-NON\n");
    scanf("%d",&rep);
    }

  return 0;
}

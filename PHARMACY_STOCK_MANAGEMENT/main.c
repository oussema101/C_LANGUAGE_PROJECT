#include <stdio.h>
#include <stdlib.h>
#include <time.h>
  typedef struct date
        {
            int jour ;
            int mois ;
            int annee ;
        }date ;

typedef struct fournisseur
{
    char nomf[20];
    char adresse[20];
    int tele;
}fournisseur;

typedef struct lot
{
    char reference[20];
    date datf;
    date datp;
}lot;

typedef struct medicament
{
    int num;
    char nom[20];
    char labo[20];
    lot lo;
    int prix;
    int quantite;
    fournisseur four;
    int secteur;
}medicament;


    void ajouter_medicament ()

{FILE *f =fopen ("medicament.txt","a");
if (f==NULL)
exit(-1);
medicament x;
int nb;

    printf(" entrer le numero , le nom et le labo du mediacament:");
    scanf("%d %s %s",&x.num,&x.nom,&x.labo);


    printf("entrer la reference du lot du medicament:");
    scanf("%s",&x.lo.reference);



    printf("entrer la date de fabrication:");
    scanf("%d %d %d",&x.lo.datf.jour,&x.lo.datf.mois,&x.lo.datf.annee);



    printf("entrer la date de preomption:");
    scanf("%d %d %d",&x.lo.datp.jour,&x.lo.datp.mois,&x.lo.datp.annee);


    printf("entrer le prix du medicament");
    scanf("%d",&x.prix);

     printf("entrer la quantite du medicament");
    scanf("%d",&x.quantite);




    /*do {
        printf("entrer le nombre des fournisseurs");
        scanf("%d",&nf);
    } while(nf > 3);*/



    printf("enter les informations du fournisseur(nom/adresse/tele)");
    scanf("%s %s %d",&x.four.nomf,&x.four.adresse,&x.four.tele);



   do {
    printf("entrer le secteur de stockage");
    scanf("%d",&x.secteur);}
   while (x.secteur>5);

         fprintf(f,"%d %s %s %s %d %d %d %d %d %d %d %d %s %s %d %d",x.num,x.nom,x.labo,x.lo.reference,x.lo.datf.jour,x.lo.datf.mois,x.lo.datf.annee,x.lo.datp.jour,x.lo.datp.mois,x.lo.datp.annee,x.prix,x.quantite,x.four.nomf,x.four.adresse,x.four.tele,x.secteur);


     fclose(f);

}



void rechercher_numero()
{FILE *f =fopen ("medicament.txt","r");
if (f==NULL)
exit(-1);
char nom1[20] ;
medicament x;

 int test=1 ;
 printf("entrer le nom du medicament recherche");
scanf("%s",&nom1);
 while(! feof(f))
{
     fscanf(f,"%d %s %s %s %d %d %d %d %d %d %d %d %s %s %d %d",&x.num,&x.nom,&x.labo,&x.lo.reference,&x.lo.datf.jour,&x.lo.datf.mois,&x.lo.datf.annee,&x.lo.datp.jour,&x.lo.datp.mois,&x.lo.datp.annee,&x.prix,&x.quantite,&x.four.nomf,&x.four.adresse,&x.four.tele,&x.secteur);


if (strcmp(x.nom,nom1)==0)
{printf("le numero recherche est :%d\n",x.num);
test=0;
}

else{
printf("cet medicament n'est pas enregistre");}

}
fclose(f);
 }

 void affiche()
{FILE*f=fopen("medicament.txt","r");
if(f==NULL)
            exit(-1);
              medicament x;
              printf("-------------------------------------------------------------\n");
    printf("Num\tNom\tLab\tReflot\tDatePreemption\tPrix\tQuantite\n");
    printf("-------------------------------------------------------------\n");
        while(!feof(f))
        {
            //puts("bonjour");
 int nb ;
    fscanf(f,"%d %s %s %s %d %d %d %d %d %d %d %d %s %s %d %d",&x.num,&x.nom,&x.labo,&x.lo.reference,&x.lo.datf.jour,&x.lo.datf.mois,&x.lo.datf.annee,&x.lo.datp.jour,&x.lo.datp.mois,&x.lo.datp.annee,&x.prix,&x.quantite,&x.four.nomf,&x.four.adresse,&x.four.tele,&x.secteur);


    printf("%d\t",x.num);
    printf("%s\t",x.nom);
    printf("%s\t",x.labo);
    printf("%s\t",x.lo.reference);
    printf("%d %d %d\t         ",x.lo.datp.jour,x.lo.datp.mois,x.lo.datp.annee);
    printf("%d\t  ",x.prix);
    printf("%d\t\n",x.quantite);
        }
fclose(f);

}


void rechercher_medicament_par_numero()
{FILE *f =fopen ("medicament.txt","r");
if (f==NULL)
exit(-1);
int num1;
medicament x;

 int test=1 ;
 printf("entrer le numero du medicament recherche :");
scanf("%d",&num1);
 while(! feof(f))
{
     fscanf(f,"%d %s %s %s %d %d %d %d %d %d %d %d %s %s %d %d",&x.num,&x.nom,&x.labo,&x.lo.reference,&x.lo.datf.jour,&x.lo.datf.mois,&x.lo.datf.annee,&x.lo.datp.jour,&x.lo.datp.mois,&x.lo.datp.annee,&x.prix,&x.quantite,&x.four.nomf,&x.four.adresse,&x.four.tele,&x.secteur);


if (num1==x.num)
{   printf("le numero : %d\n",x.num);
    printf("le nom : %s\n",x.nom);
    printf("le nom du labo : %s\n",x.labo);
    printf("la reference : %s\n",x.lo.reference);
    printf("la date de fabrication :%d %d %d\n",x.lo.datf.jour,x.lo.datf.mois,x.lo.datf.annee);
    printf("la date de preemption est :%d %d %d\n",x.lo.datp.jour,x.lo.datp.mois,x.lo.datp.annee);
    printf("le prix est : %d\n",x.prix);
    printf("la quantite : %d\n",x.quantite);
    printf("les infos du fournisseur : %s %s %d\n",x.four.nomf,x.four.adresse,x.four.tele);
    printf("le secteur :%d\n",x.secteur);
test=0;
}

else{
printf("medicament inconnu!");}

}
fclose(f);
 }



 void rechercher_medicament_par_chaine()
{FILE *f =fopen ("medicament.txt","r");
if (f==NULL)
exit(-1);
char chaine[20] ;
medicament x;

 int test=1 ;
 int longueur;
 char nom2[20];
 printf("entrer les premiers caracteres du mediacement recherhe:");
scanf("%s",&chaine);
longueur=strlen(chaine);
int i;




 while(! feof(f))
{
     fscanf(f,"%d %s %s %s %d %d %d %d %d %d %d %d %s %s %d %d",&x.num,&x.nom,&x.labo,&x.lo.reference,&x.lo.datf.jour,&x.lo.datf.mois,&x.lo.datf.annee,&x.lo.datp.jour,&x.lo.datp.mois,&x.lo.datp.annee,&x.prix,&x.quantite,&x.four.nomf,&x.four.adresse,&x.four.tele,&x.secteur);
     //strncpy(nom2,x.nom,longueur);
     for( i=0;i<longueur;i++)
     {
         nom2[i]=x.nom[i];
     }
     nom2[i]='\0';


if (strcmp(nom2,chaine)==0)
{       printf("-------------------------------------------------------------\n");
    printf("Num\tNom\tLab\tReflot\tDatePreemption\tPrix\tQuantite\n");
    printf("-------------------------------------------------------------\n");
    printf("%d\t",x.num);
    printf("%s\t",x.nom);
    printf("%s\t",x.labo);
    printf("%s\t",x.lo.reference);
    printf("%d %d %d\t         ",x.lo.datp.jour,x.lo.datp.mois,x.lo.datp.annee);
    printf("%d\t  ",x.prix);
    printf("%d\t",x.quantite);

test=0;
}

else{
printf("cet medicament n'est pas enregistre");}

}
fclose(f);
 }




void affiche_quantite_null()    // resultat correct , boucle infini
{FILE *f =fopen ("medicament.txt","r");
if (f==NULL)
exit(-1);

medicament x;

 int test=1 ;

 while(! feof(f))
{
     fscanf(f,"%d %s %s %s %d %d %d %d %d %d %d %d %s %s %d %d",&x.num,&x.nom,&x.labo,&x.lo.reference,&x.lo.datf.jour,&x.lo.datf.mois,&x.lo.datf.annee,&x.lo.datp.jour,&x.lo.datp.mois,&x.lo.datp.annee,&x.prix,&x.quantite,&x.four.nomf,&x.four.adresse,&x.four.tele,&x.secteur);


if (x.quantite==0)
{
    printf("le nom : %s\n",x.nom);

test=0;
}

else{
printf("pas de medicament en rupture de stock !");}

}
fclose(f);
 }

void affiche_quantite_medicament()
{FILE *f =fopen ("medicament.txt","r");
if (f==NULL)
exit(-1);
char nom1[20];
medicament x;
printf("entrer le nom du medicament recherche:");
scanf("%s",&nom1);
 int test=1 ;


 while(! feof(f))
{

     fscanf(f,"%d %s %s %s %d %d %d %d %d %d %d %d %s %s %d %d",&x.num,&x.nom,&x.labo,&x.lo.reference,&x.lo.datf.jour,&x.lo.datf.mois,&x.lo.datf.annee,&x.lo.datp.jour,&x.lo.datp.mois,&x.lo.datp.annee,&x.prix,&x.quantite,&x.four.nomf,&x.four.adresse,&x.four.tele,&x.secteur);

if (strcmp(x.nom,nom1)==0)
{
    printf("la quantite est : %d \n",x.quantite);

test=0;
}

else{
printf("cet medicament n'est pas enregistre");}

}
fclose(f);
}

void affiche_fournisseurs_medicament()
{FILE *f =fopen ("medicament.txt","r");
if (f==NULL)
exit(-1);
int num1;
medicament x;
printf("entrer le numero du medicament recherche:");
scanf("%d",&num1);
 int test=1 ;


 while(! feof(f))
{

     fscanf(f,"%d %s %s %s %d %d %d %d %d %d %d %d %s %s %d %d",&x.num,&x.nom,&x.labo,&x.lo.reference,&x.lo.datf.jour,&x.lo.datf.mois,&x.lo.datf.annee,&x.lo.datp.jour,&x.lo.datp.mois,&x.lo.datp.annee,&x.prix,&x.quantite,&x.four.nomf,&x.four.adresse,&x.four.tele,&x.secteur);

if (x.num==num1)
{
    printf("le fournisseur est : %s \n",x.four.nomf);

test=0;
}

else{
printf("cet medicament n'est pas enregistre");}

}
fclose(f);
}


void affiche_ordonnance()
{FILE *f =fopen ("medicament.txt","r");
if (f==NULL)
exit(-1);
int num1[20];
int quant[20];
int nombre;
medicament x;
printf("combiende medicament voulez vous achetez?");
scanf("%d",&nombre);
for(int i=0;i<nombre;i++){
printf("entrer le numero du medicament recherche");
scanf("%d",&num1[i]);
printf("entrer la quantite du medicament recherche");
scanf("%d",&quant[i]);
}

int test=1 ;
int totale=0 ;
for(int i=0;i<nombre;i++){
        rewind(f);
 while(! feof(f))
{

     fscanf(f,"%d %s %s %s %d %d %d %d %d %d %d %d %s %s %d %d",&x.num,&x.nom,&x.labo,&x.lo.reference,&x.lo.datf.jour,&x.lo.datf.mois,&x.lo.datf.annee,&x.lo.datp.jour,&x.lo.datp.mois,&x.lo.datp.annee,&x.prix,&x.quantite,&x.four.nomf,&x.four.adresse,&x.four.tele,&x.secteur);

if ((quant[i]<=x.quantite)&&(num1[i]==x.num))
{   totale=totale+(x.prix*quant[i]);
    printf("-------------------------------------------------------------\n");
    printf("Num\tNom\tquantite\tprix unitaire\n");
    printf("-------------------------------------------------------------\n");
    printf("%d\t %s\t %d\t        %d\t",x.num,x.nom,quant[i],x.prix);
    printf("\n\n");
    printf("                            **********\n");
    printf("                            TOTALE :%d\n",totale);

test=0;
}}



}
fclose(f);
}




void affiche_medicament_perimee()
{FILE *f =fopen ("medicament.txt","r");
if (f==NULL)
exit(-1);
int jour, mois, an;
time_t now;


time(&now);


struct tm *local = localtime(&now);

jour = local->tm_mday;
mois = local->tm_mon + 1;
an = local->tm_year + 1900;



int test=1;
medicament x;

while(! feof(f))
{

        fscanf(f,"%d %s %s %s %d %d %d %d %d %d %d %d %s %s %d %d",&x.num,&x.nom,&x.labo,&x.lo.reference,&x.lo.datf.jour,&x.lo.datf.mois,&x.lo.datf.annee,&x.lo.datp.jour,&x.lo.datp.mois,&x.lo.datp.annee,&x.prix,&x.quantite,&x.four.nomf,&x.four.adresse,&x.four.tele,&x.secteur);
     if ((x.lo.datp.annee)<an)

     {
         printf("%s %s %d\n",x.nom,x.lo.reference,x.secteur);
     }

       else if((x.lo.datp.mois)<mois)
       {printf("%s %s %d\n",x.nom,x.lo.reference,x.secteur);}

        else if((x.lo.datp.jour)<jour )
            {printf("%s %s %d\n",x.nom,x.lo.reference,x.secteur);

     test=0;}


 else{
 printf("le medicament est encore valide\n");}

 }
 fclose(f);
 }




 void supprimer_medicament()
{FILE *f =fopen ("medicament.txt","r");
    FILE *fp =fopen ("medicament2.txt","w");
    if (f==NULL)
exit(-1);
    char ref[20] ;
    int jour, mois, an;
    int test=1;
time_t now;


time(&now);


struct tm *local = localtime(&now);

jour = local->tm_mday;
mois = local->tm_mon + 1;
an = local->tm_year + 1900;




    printf("entrer la reference du lot");
    scanf("%s",&ref);
    medicament x;
    while (! feof(f))
{
        fscanf(f,"%d %s %s %s %d %d %d %d %d %d %d %d %s %s %d %d",&x.num,&x.nom,&x.labo,&x.lo.reference,&x.lo.datf.jour,&x.lo.datf.mois,&x.lo.datf.annee,&x.lo.datp.jour,&x.lo.datp.mois,&x.lo.datp.annee,&x.prix,&x.quantite,&x.four.nomf,&x.four.adresse,&x.four.tele,&x.secteur);
if ((strcmp(x.lo.reference,ref)==0))
{
if (x.quantite==0)

test=0;
if ((x.lo.datp.annee)>an)
{
    test=0;
       }
 else
 {if (((x.lo.datp.annee)==an))
      {


          if((x.lo.datp.mois)<mois)
{
test=0;
}
else if ((x.lo.datp.mois)==mois)

    if((x.lo.datp.jour)<jour)
        {

     test=0;}}}}
     if (test)
        fprintf(fp,"%d %s %s %s %d %d %d %d %d %d %d %d %s %s %d %d",x.num,x.nom,x.labo,x.lo.reference,x.lo.datf.jour,x.lo.datf.mois,x.lo.datf.annee,x.lo.datp.jour,x.lo.datp.mois,x.lo.datp.annee,x.prix,x.quantite,x.four.nomf,x.four.adresse,x.four.tele,x.secteur);




     }


/* else{
 printf("le medicament ne peut pas etre supprime");}*/

fclose(f);
fclose(fp);
remove("medicament.txt");
rename("medicament2.txt","medicament.txt");

}


main()
{
    int choix;

do
{puts("1.ajouter un medicament");
 puts("2.rechercher le numero d'un medicament par son nom");
 puts("3.Afficher les medicaments");
 puts("4.rechercher un medicament par son numero");
 puts("5.rechercher un medicament par les premiers lettres");
 puts("6.afficher les medicament en rupture de stock");
 puts("7.afficher la quantite d'un medicament");
 puts("8.afficher les fourniseeur d'un medicament");
 puts("9.afficher une ordonnance");
 puts("10.afficher les medicaments perimee");
 puts("11.supprimer un medicament");
 printf("Donner Votre Choix:");
 scanf("%d",&choix);
 switch(choix)
 {case 1:   ajouter_medicament();
      break;
  case 2: rechercher_numero();

      break;
  case 3:affiche() ;

         break;
   case 4:rechercher_medicament_par_numero();

           break;
    case 5 :rechercher_medicament_par_chaine();
    break;
    case 6 :affiche_quantite_null();
    break;
    case 7 :affiche_quantite_medicament();
    break;
    case 8 :affiche_fournisseurs_medicament() ;
    break;
    case 9 :affiche_ordonnance();
    break;
    case 10 :affiche_medicament_perimee();
    break;
    case 11 :supprimer_medicament();
    break;
   default:if(choix!=12)
          printf("choix invalide");}}
while(choix!=12);

}

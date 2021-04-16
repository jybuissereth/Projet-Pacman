
#include "pac.h"


int main()
{
  int v,b,r;
  etat_t pacman;
  paquet_t paquet;
  etat_t etat = {fini:0};
  creerTableau();
  fixerTaille(1000,1000);
  
   //choisirCouleurFond(0,0,0);
  fixerModeBufferisation(1);
  EtatSourisClavier esc;
  Image im1= chargerImage("pacman.jpeg");
  Image im2= chargerImage("pacman2.jpeg");
  int dlt=0.5;
  while (esc.touchesClavier[44]!=1)
    {
      esc=lireEtatSourisClavier();
      if ( esc.touchesClavier[44]==0)
	{ afficherImage(im1, -20-tn_largeur(im1)/2, -300+tn_largeur(im1));
          dlt=0;
	  tamponner();

	  if (dlt<1)
	    {//attendreNms(650);
	      afficherImage(im2,-20-tn_largeur(im2)/2, -300+tn_largeur(im2));
	      tamponner();
	      dlt=dlt+0.5;
	  // attendreNms(250);
	    }
	}
    }
  
  choisirCouleurFond(0,0,0);
  etat.modele = initiale();
  apparition_b(&paquet);
  while (fini(etat)==0)
  {
     chargerPixelsEnMemoire();
     terrain();
     //lirePixel(0,0,&r,&v,&b);
     //printf("j'ai comme couleur %d\t%d\t%d\n",r,v,b);	
     EtatSourisClavier esc = lireEtatSourisClavier();
     double dt = delta_temps();
     etat = maj(etat,esc,dt);
     afficher_pacman(etat);
     tamponner();
     effacer_pacman(etat);
  }
  return EXIT_SUCCESS;
}


pac_t initiale()
{
  pac_t m ={ pacman: {p: {-5,-200}, v: {0,0}}};
  choisirTypeStylo(36,255,215,0);
  tracerPoint(m.pacman.p.x,m.pacman.p.y);
  return m;
}


void afficher_pacman(etat_t pacman)
{
   choisirTypeStylo(36,255,215,0);
   tracerPoint(pacman.modele.pacman.p.x,pacman.modele.pacman.p.y);// à compléter: tracer le ballon
}

void effacer_pacman(etat_t pacman)
{
   choisirTypeStylo(36,255,215,0);
   effacerPoint(pacman.modele.pacman.p.x,pacman.modele.pacman.p.y);// à compléter: tracer le ballon
}
 

etat_t maj ( etat_t etat, EtatSourisClavier esc, double dt)
{
    /*CoulPix cp;*/
    int rou1=0, ver1=0, ble1=0,rou2=0, ver2=0, ble2=0,rou3=0, ver3=0, ble3=0,rou4=0, ver4=0, ble4=0;
    chargerPixelsEnMemoire();
    if ( esc.sourisBoutonDroit)
      {
        etat.fini = 1;
      }
    coord_t a,b;
    if (esc.touchesClavier[80] )
      {
       lirePixel(etat.modele.pacman.p.x-20,etat.modele.pacman.p.y,&rou1,&ver1,&ble1);
       // lirePixel(etat.modele.pacman.p.x,etat.modele.pacman.p.y+20,&rou3,&ver3,&ble3);
       // lirePixel(etat.modele.pacman.p.x,etat.modele.pacman.p.y-20,&rou4,&ver4,&ble4);
       //       printf("gauche %d,%d,%d\n",rou,ver,ble);
       if (((rou1 != 0) || (ver1 != 127) || (ble1 != 255))&&((rou3 != 0) || (ver3 != 127) || (ble3 != 255))&&((rou4 != 0) || (ver4 != 127) || (ble4 != 255)))
	   if( etat.modele.pacman.p.x < -360 && etat.modele.pacman.p.y > -20 && etat.modele.pacman.p.y < 50)
                etat.modele.pacman.p.x = -etat.modele.pacman.p.x;
       
       else
	        etat.modele.pacman.p.x=etat.modele.pacman.p.x-4;

      
      }
    if (esc.touchesClavier[82])
    {
      // lirePixel(etat.modele.pacman.p.x-20,etat.modele.pacman.p.y,&rou1,&ver1,&ble1);
       // lirePixel(etat.modele.pacman.p.x+20,etat.modele.pacman.p.y,&rou2,&ver2,&ble2);
       lirePixel(etat.modele.pacman.p.x,etat.modele.pacman.p.y+20,&rou3,&ver3,&ble3);
       
	//   printf("haut %d,%d,%d\n",rou,ver,ble);
       if (((rou1 != 0) || (ver1 != 127) || (ble1 != 255))&&((rou2 != 0) || (ver2 != 127) || (ble2 != 255))&&((rou3 != 0) || (ver3 != 127) || (ble3 != 255)))
	   if( etat.modele.pacman.p.y > 300 && etat.modele.pacman.p.x > -50 && etat.modele.pacman.p.x < 40)
	     etat.modele.pacman.p.y = -etat.modele.pacman.p.y;

	   else
	     etat.modele.pacman.p.y=etat.modele.pacman.p.y+4;

    }
    if (esc.touchesClavier[81])
    {
	
      //lirePixel(etat.modele.pacman.p.x-20,etat.modele.pacman.p.y,&rou1,&ver1,&ble1);
      // lirePixel(etat.modele.pacman.p.x+20,etat.modele.pacman.p.y,&rou2,&ver2,&ble2);
       lirePixel(etat.modele.pacman.p.x,etat.modele.pacman.p.y-20,&rou4,&ver4,&ble4);
          if (((rou1 != 0) || (ver1 != 127) || (ble1 != 255))&&((rou2 != 0) || (ver2 != 127) || (ble2 != 255))&&((rou4 != 0) || (ver4 != 127) || (ble4 != 255)))
	     if( etat.modele.pacman.p.y < -300 && etat.modele.pacman.p.x > -50 && etat.modele.pacman.p.x < 40)
	       etat.modele.pacman.p.y = -etat.modele.pacman.p.y;
	
    	  else
	       etat.modele.pacman.p.y=etat.modele.pacman.p.y-4;

	 
 }
    
    if (esc.touchesClavier[79])
    {
       lirePixel(etat.modele.pacman.p.x+20,etat.modele.pacman.p.y,&rou2,&ver2,&ble2);
       //lirePixel(etat.modele.pacman.p.x,etat.modele.pacman.p.y+20,&rou3,&ver3,&ble3);
       //lirePixel(etat.modele.pacman.p.x,etat.modele.pacman.p.y-20,&rou4,&ver4,&ble4);

          if (((rou2 != 0) || (ver2 != 127) || (ble2 != 255))&&((rou3 != 0) || (ver3 != 127) || (ble3 != 255))&&((rou4 != 0) || (ver4 != 127) || (ble4 != 255)))
	     if( etat.modele.pacman.p.x > 360 && etat.modele.pacman.p.y > -20 && etat.modele.pacman.p.y < 50)
	       etat.modele.pacman.p.x = -etat.modele.pacman.p.x;
	
	else
	       etat.modele.pacman.p.x=etat.modele.pacman.p.x+4;

	  

    }
    return etat;
}



int fini(etat_t etat)
{
    return etat.fini;
}


/*int j;
while((*paquet).nb>=0)
  for(i=0, i<68, i++)
    { j=bonbon[i];
      if (j=(etat.modele.pacman.p.x)*(etat.modele.pacman.p.x)+(etat.modele.pacman.p.y)*(etat.modele.pacman.p.y)+36
	{
	  afficherImage;
	  choisirTypeStylo(36,255,215,0);
	  tracerPoint(bonbon[i].pbille.x,bonbon[i].pbille.y);
	}
     }*/

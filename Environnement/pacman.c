#include "pacman.h"

void terrain()
{     choisirTypeStylo(10,0,127,255);
 
  
      tracerSegment(-390,-290,-50,-290); /* trace le mur du bas */
      tracerSegment(40,-290,390,-290);
   
      tracerSegment(390,-290,390,-20);  /* trace le mur de droite */
      tracerSegment(390,50,390,290);
     
      tracerSegment(390,290,40,290);      /* trace le mur du haut */
      tracerSegment(-50,290,-390,290);

      tracerSegment(-390,-290,-390,-20);   /* trace le mur de gauche */
      tracerSegment(-390,50,-390,290);

   /*  tracerRectangle(-80, -40,80,80);*/  /* trace la maison de fantome */
      tracerSegment(-120,-100,-120,100); 
      tracerSegment(-120,-100,-70,-100); 
        tracerSegment(-120,100,-70,100); /* petit trait haut horizontal */
      tracerSegment(-70,-100,-70,-50);
       tracerSegment(-70,100,-70,50);
       tracerSegment(-70,50,-35,50);
      
       
      
      tracerSegment(-70,-50,70,-50);

      tracerSegment(70,-100,70,-50);
      tracerSegment(70,-100,120,-100);
      tracerSegment(120,-100,120,100);
      tracerSegment(120,100,70,100);
      tracerSegment(70,100,70,50);
       tracerSegment(70,50,35,50);
       
      tracerRectangle(-250, -70,-180,60); /* trace carré a coté maison fantome*/
      tracerRectangle(250, -70,180,60);
     
      /* tracerRectangle(-170, -170,170,-180);*/
      /*tracerRectangle(-170, 170,170,180);*/

      tracerSegment(-310,-150,-310,150); /* barre verticaux*/
       tracerSegment(310,-150,310,150);

       tracerSegment(-130,-230,130,-230); /* barre entre T*/
	      tracerSegment(-130,230,130,230);


      /*    tracerRectangle(-340, 170,-320,-180); /* trace rectangle verticaux */
      /*  tracerRectangle(340, 170,320,-180);
       */
      coord_t a= {-320,-230};
      coord_t b= { -190,-230 };

      coord_t c= {320,-230};
      coord_t d= { 190,-230 };

      coord_t e= {-320,230};
      coord_t f= { -190,230 };

      coord_t g= {320,230};
      coord_t h= { 190,230 };
      coord_t i= {-190,-170};
      coord_t j= {190,-180};
      coord_t k ={-190,170};
      coord_t l ={190,180};
        t3(i,j);
        t4(k,l); 
      
     t1(a,b);
      t1(c,d);
      t2(e,f);
      t2(g,h);
      /* l(b,v2(d,20));*/
      chargerPixelsEnMemoire();

}

void apparition_b (paquet_t *paquet){
  (*paquet).nb=0;
  score bonbon;
  bonbon.a=-230;
  bonbon.b=-205;
      /* while(bonbon.b>-350 && bonbon.b<350   )
	{  */
  while(bonbon.a>-255 && bonbon.a<255 )
    {
      choisirTypeStylo(10,255,215,0);
      tracerPoint(bonbon.a,bonbon.b); //bonbon avant dernier
      (*paquet).bonbon[(*paquet).nb].pbille.x=bonbon.a;
      (*paquet).bonbon[(*paquet).nb].pbille.y=bonbon.b;
      (*paquet).bonbon[(*paquet).nb].numero=(*paquet).nb;
      (*paquet).nb++;
      bonbon.a=bonbon.a+50;
    }
      /* bonbon.b=bonbon.b+10;
      bonbon.a=-230;
      printf("%lf%lf",bonbon.b,bonbon.a);
      */
      bonbon.a=230;
      bonbon.b=205;
 while(bonbon.a>-255 && bonbon.a<255 )
   {
     choisirTypeStylo(10,255,215,0);
     tracerPoint(bonbon.a,bonbon.b); //bonbon avant premier
     (*paquet).bonbon[(*paquet).nb].pbille.x=bonbon.a;
     (*paquet).bonbon[(*paquet).nb].pbille.y=bonbon.b;
     (*paquet).bonbon[(*paquet).nb].numero=(*paquet).nb;
     (*paquet).nb++;
     bonbon.a=bonbon.a-50;
   }
 bonbon.a=320;
 bonbon.b=255;
 while(bonbon.a>-325 && bonbon.a<325 )
   {
     choisirTypeStylo(10,255,215,0);
     tracerPoint(bonbon.a,bonbon.b); //bonbon de tout en haut
     (*paquet).bonbon[(*paquet).nb].pbille.x=bonbon.a;
     (*paquet).bonbon[(*paquet).nb].pbille.y=bonbon.b;
     (*paquet).bonbon[(*paquet).nb].numero=(*paquet).nb;
     (*paquet).nb++;
     bonbon.a=bonbon.a-50;
   }
 bonbon.a=-320;
 bonbon.b=-255;
 while(bonbon.a>-325 && bonbon.a<325 )            //bonbo de tout en bas
   {
     choisirTypeStylo(10,255,215,0);
     tracerPoint(bonbon.a,bonbon.b);
     (*paquet).bonbon[(*paquet).nb].pbille.x=bonbon.a;
     (*paquet).bonbon[(*paquet).nb].pbille.y=bonbon.b;
     (*paquet).bonbon[(*paquet).nb].numero=(*paquet).nb;
     (*paquet).nb++;
     bonbon.a=bonbon.a+50;     
   }
 bonbon.a=350;
 bonbon.b=195;
 while(bonbon.b>-245 && bonbon.b<200 )
   {
     choisirTypeStylo(10,255,215,0);         //vertical droite
     tracerPoint(bonbon.a,bonbon.b);
     (*paquet).bonbon[(*paquet).nb].pbille.x=bonbon.a;
     (*paquet).bonbon[(*paquet).nb].pbille.y=bonbon.b;
     (*paquet).bonbon[(*paquet).nb].numero=(*paquet).nb;
     (*paquet).nb++;
     bonbon.b=bonbon.b-50;
   }
 bonbon.a=-350;
 bonbon.b=195;
 while(bonbon.b>-245 && bonbon.b<200 )
   {
     choisirTypeStylo(10,255,215,0);         //vertical gauche
     tracerPoint(bonbon.a,bonbon.b);
     (*paquet).bonbon[(*paquet).nb].pbille.x=bonbon.a;
     (*paquet).bonbon[(*paquet).nb].pbille.y=bonbon.b;
     (*paquet).bonbon[(*paquet).nb].numero=(*paquet).nb;
     (*paquet).nb++;
     bonbon.b=bonbon.b-50;
   }
 bonbon.a=-230;
 bonbon.b=-205;
 while(bonbon.b>-225 && bonbon.b<-105  )
   {
     choisirTypeStylo(10,255,215,0);
     tracerPoint(bonbon.a,bonbon.b);    // petit bonbon
     (*paquet).bonbon[(*paquet).nb].pbille.x=bonbon.a;
     (*paquet).bonbon[(*paquet).nb].pbille.y=bonbon.b;
     (*paquet).bonbon[(*paquet).nb].numero=(*paquet).nb;
     (*paquet).nb++;
     bonbon.b=bonbon.b+50;
   }
 bonbon.a=-220;
 bonbon.b=155;
 (*paquet).bonbon[(*paquet).nb].pbille.x=bonbon.a;
 (*paquet).bonbon[(*paquet).nb].pbille.y=bonbon.b;
 (*paquet).bonbon[(*paquet).nb].numero=(*paquet).nb;
 (*paquet).nb++;
 choisirTypeStylo(10,255,215,0);             //petit bonbon
 tracerPoint(bonbon.a,bonbon.b);
 bonbon.a=220;
 bonbon.b=-205;
 while(bonbon.b>-225 && bonbon.b<-105  )
  {
    choisirTypeStylo(10,255,215,0);                  //petit bonbon
    tracerPoint(bonbon.a,bonbon.b);
    bonbon.b=bonbon.b+50;
  }

 bonbon.a=230;
 bonbon.b=155;
 (*paquet).bonbon[(*paquet).nb].pbille.x=bonbon.a;
 (*paquet).bonbon[(*paquet).nb].pbille.y=bonbon.b;
 (*paquet).bonbon[(*paquet).nb].numero=(*paquet).nb;
 (*paquet).nb++;
 choisirTypeStylo(10,255,215,0);              //petit bonbon
 tracerPoint(bonbon.a,bonbon.b);
}

void t1(coord_t x1, coord_t x2)
{ tracerSegment(x1.x,x1.y,x2.x,x1.y);
  tracerSegment((x1.x + x2.x)/2 ,x1.y ,(x1.x + x2.x)/2 , x1.y + 90);
}

void t3(coord_t x1, coord_t x2)
{ tracerSegment(x1.x,x1.y,x2.x,x1.y);
  tracerSegment((x1.x + x2.x)/2 ,x1.y ,(x1.x + x2.x)/2 , x1.y + 65);
}
void t4(coord_t x1, coord_t x2)
{ tracerSegment(x1.x,x1.y,x2.x,x1.y);
  tracerSegment((x1.x + x2.x)/2 ,x1.y ,(x1.x + x2.x)/2 , x1.y - 65);
}

void t2(coord_t x1, coord_t x2)
{ tracerSegment(x1.x,x1.y,x2.x,x1.y);
  tracerSegment((x1.x + x2.x)/2 ,x1.y ,(x1.x + x2.x)/2 , x1.y - 90);
}



/*
void manger(paquet_t (*paquet))
{int j,i;
  score bonbon;
while((*paquet).nb>=0)
  {  for(i=0; i<68; i++)
    { j=bonbon[i];
      if (j=(etat.modele.pacman.p.x)*(etat.modele.pacman.p.x)+(etat.modele.pacman.p.y)*(etat.modele.pacman.p.y)+36
	{
	  //afficherImage;
	  choisirTypeStylo(36,255,215,0);
	  tracerPoint(bonbon[i].pbille.x,bonbon[i].pbille.y);
	}
	
	}}}
*/

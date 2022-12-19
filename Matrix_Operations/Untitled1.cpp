#include <stdio.h>
#include <stdlib.h>
#incluse <string.h>

typedef struct{


    char adi[30];
    char soyadi[30];

    int no;
    

} Ogrenci;


	
	Ogrenci ogrOlustur(int no,  char a[30], char s[30] );
  //dosya yazma
    Ogrenci o;
    o.no=n;
    strcpy(o.ad=a;
    strcpy( o.soyadi=s;
    return o;
}

    void dosyaYaz(FILE *dosya, Ogrenci o){
    	 fseek(dosya,0, SEEK_END);
    	 fwrite(&ogr, sizeof(Ogrenci),1, dosya);
    	 
	}
	Ogrenci dosyadanOku(FILE *dosya, int num ){
		Ogrenci ogr;
		fseek(dosya,(num-1)*sizeof(Ogrenci),SEEK_SET);
		fread(&ogr, sizeof(Ogrenci),1, dosya);
		return ogr;
	}
	 void ogrYazdir(Ogrenci ogr){
	 	printf("Numara: %d , Adi: %s , Soyadi: %s", ogr.no,ogr.ad,ogr.soyad);
	 	puts("");
	 	
	 }
	 
	 Ogrenci onceki(FILE *dosya){
	 	Ogrenci ogr;
	 	fseek(dosya,(-2)*sizeof(Ogrenci),SEEK_CUR);
		fread(&ogr, sizeof(Ogrenci),1, dosya);
		return ogr;
	 	
	 }
   
int main(){
	
	Ogrenci ogr1=ogrOlustur(1,"Ali","Ak");
	Ogrenci ogr1=ogrOlustur(2,"irem","ercel");
	Ogrenci ogr1=ogrOlustur(3,"Ay","Ak");
	Ogrenci ogr1=ogrOlustur(4,"Aybuke","Ak");
	Ogrenci ogr1=ogrOlustur(5,"Ayda","Ak");
	
	
	FILE *dosya=fopen("veriler.dat", "a+b" );
	
	dosyaYaz(dosya,ogr1);
	dosyaYaz(dosya,ogr2);
	dosyaYaz(dosya,ogr3);
	dosyaYaz(dosya,ogr4);
	dosyaYaz(dosya,ogr5);
	
	Ogrenci oku1=dosyadanOku(dosya,2);
	ogrYazdir(oku1);
	Ogrenci oku2=onceki(dosya);
	OgrYazdir(oku2);
	oku2=sonraki(dosya);
	ogrYazdir(oku2);
	fclose(dosya);
	
	
}
    
    


#include "Proje1.h"

int	main(int argc, char **argv)
{
	struct Ders 	alinanDers;
	struct Ders 	*alinanDersler;
	struct Ders		*alinanDersler2;
	struct Ogrenci	ogr;
	struct Ogrenci	*ogrs;
	struct Ogrenci	*exondeneme;
	int				i;
	int				j;

	i = 0;
	j = 0;
	printf("--------------------- Ex01 ---------------------\n");
	alinanDers = derseVeriAta("Matematik", 5, 90);
	printf("------------------------------------------------\n");
	printf("--------------------- Ex02 ---------------------\n");
	alinanDersler = malloc(sizeof(struct Ders) * 11);
	alinanDersler2 = malloc(sizeof(struct Ders) * 11);
	alinanDersler[0] = derseVeriAta("Matematik", 5, 90);
	alinanDersler[1] = derseVeriAta("Turkce", 4, 75);
	alinanDersler[2] = derseVeriAta("Temel Elektronik", 4, 30);
	alinanDersler[3] = derseVeriAta("Yazilim", 4, 40);
	alinanDersler[4] = derseVeriAta("Inkilap", 4, 25);
	alinanDersler[5] = derseVeriAta("Makine", 4, 50);
	alinanDersler[6] = derseVeriAta("Insan iliskileri", 4, 10);
	alinanDersler[7] = derseVeriAta("Ingilizce", 4, 30);
	alinanDersler[8] = derseVeriAta("Bilisim", 4, 44);
	alinanDersler[9] = derseVeriAta("Muhasebe", 4, 33);
	alinanDersler2[0] = derseVeriAta("Matematik", 5, 22);
	alinanDersler2[1] = derseVeriAta("Turkce", 4, 11);
	alinanDersler2[2] = derseVeriAta("Temel Elektronik", 4, 60);
	alinanDersler2[3] = derseVeriAta("Yazilim", 4, 90);
	alinanDersler2[4] = derseVeriAta("Inkilap", 4, 15);
	alinanDersler2[5] = derseVeriAta("Makine", 4, 28);
	alinanDersler2[6] = derseVeriAta("Insan iliskileri", 4, 37);
	alinanDersler2[7] = derseVeriAta("Ingilizce", 4, 42);
	alinanDersler2[8] = derseVeriAta("Bilisim", 4, 76);
	alinanDersler2[9] = derseVeriAta("Muhasebe", 4, 85);
	ogr = ogrenciyeVeriAta("Irem", "Ercel", "Bilgisayar", alinanDersler);
	printf("------------------------------------------------\n");
	printf("--------------------- Ex03 ---------------------\n");
	ogrYazdir(ogr);
	printf("------------------------------------------------\n");
	printf("--------------------- Ex04 ---------------------\n");
	ogrs = malloc(sizeof(struct Ogrenci) * 3);
	ogrs[0] = ogrenciyeVeriAta("Irem", "Ercel", "Bilgisayar", alinanDersler);
	ogrs[1] = ogrenciyeVeriAta("Ahmet", "Yilmaz", "Matematik", alinanDersler2);
	ogrs[2] = ogrenciyeVeriAta("Aylin", "Gunes", "Ingilizce", alinanDersler2);
	ogrDiziYazdir(ogrs);
	printf("------------------------------------------------\n");
	printf("--------------------- Ex05 ---------------------\n");
	dersAdinaGoreAritmetikOrtalama(ogrs, "Matematik");
	printf("------------------------------------------------\n");
	printf("--------------------- Ex06 ---------------------\n");
	dersAdinaGoreStandartSapma(ogrs, "Matematik");
	printf("------------------------------------------------\n");
	printf("--------------------- Ex07 ---------------------\n");
	dersIcinKovaryansHesaplama(alinanDersler, alinanDersler2);
	printf("------------------------------------------------\n");
	printf("--------------------- Ex08 ---------------------\n");
	ortalamayiGecenOgrenciler(ogrs, "Turkce");
	printf("------------------------------------------------\n");
	printf("--------------------- Ex09 ---------------------\n");
	ogrencileriDosyayaYazdir(ogrs);
	printf("------------------------------------------------\n");
	printf("--------------------- Ex10 ---------------------\n");
	if (argc == 2)
	{
		exondeneme = dosyadanVeriAl(argv[1]);
		ogrDiziYazdir(exondeneme);
		freeogrs(exondeneme);
	}
	printf("------------------------------------------------\n");
	free(ogr.ogrAdi);
	free(ogr.ogrSoyadi);
	free(ogr.bolumu);
	freeDersler(ogr.aldigiDersler);
	free(alinanDers.dersAdi);
	freeogrs(ogrs);
	freeDersler(alinanDersler);
	freeDersler(alinanDersler2);
	system("leaks Proje1");
	return (0);
}

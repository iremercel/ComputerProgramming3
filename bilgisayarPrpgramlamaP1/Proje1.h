#ifndef PROJE1_H
# define PROJE1_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>
# include <fcntl.h>
# include <unistd.h>

struct Ders
{
	char				*dersAdi;
	unsigned short int	kredi;
	unsigned short int	puan;
};

struct Ogrenci
{
	char		*ogrAdi;
	char		*ogrSoyadi;
	char		*bolumu;
	float		ortalama;
	struct Ders	*aldigiDersler;
};

struct Ders		derseVeriAta(char *dersAdi, int kredi, int puan); // Ex01
struct Ogrenci	ogrenciyeVeriAta(char *ogrAdi, char *ogrSoyadi, char *bolumu, struct Ders *aldigiDersler); // Ex02
void			ogrYazdir(struct Ogrenci yazdirilacakogrenci); // Ex03
void			ogrDiziYazdir(struct Ogrenci *ogrs); // Ex04
float			dersAdinaGoreAritmetikOrtalama(struct Ogrenci *ogrs, char *dersAdi); // Ex05
float			dersAdinaGoreStandartSapma(struct Ogrenci *ogrs, char *dersAdi); // Ex06
float			dersIcinKovaryansHesaplama(struct Ders *ders1, struct Ders *ders2); // Ex07
void			ortalamayiGecenOgrenciler(struct Ogrenci *ogrs, char *dersAdi); // Ex08
void			ogrencileriDosyayaYazdir(struct Ogrenci *ogrs); // Ex09
struct Ogrenci	*dosyadanVeriAl(char *dosya); // Ex10
void			freeogrs(struct Ogrenci *ogrs); // Çoklu öğrenci structlarını freeler
void			freeDersler(struct Ders *dersler); // Çoklu ders structlarını freeler

#endif
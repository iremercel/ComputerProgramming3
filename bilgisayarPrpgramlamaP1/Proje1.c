#include "Proje1.h"

void	freeDersler(struct Ders *dersler) // Birden çok ders olduğunda bu ders structlarını freeler
{
	int	i;

	i = 0;
	while (dersler[i].dersAdi)
	{
		free(dersler[i].dersAdi);
		i++;
	}
	free(dersler);
}

void	freeogrs(struct Ogrenci *ogrs) // Birden çok öğrenci olduğunda bu ders structlarını freeler
{
	int	i;

	i = 0;
	while (ogrs[i].ogrAdi)
	{
		free(ogrs[i].ogrAdi);
		free(ogrs[i].ogrSoyadi);
		free(ogrs[i].bolumu);
		freeDersler(ogrs[i].aldigiDersler);
		i++;
	}
	free(ogrs);
}

char	*copystr(char *temp) // Bir stringi ötekine yeni yer açıp kopyalar. Dönüş değerinde de bu değeri alıp kullanabiliriz
{
	char	*str;
	int		index;

	index = 0;
	str = malloc(sizeof(char) * 256);
	while (temp[index])
	{
		str[index] = temp[index];
		index++;
	}
	str[index] = '\0';
	return (str);
}

float	ortalamaBul(struct Ders *alinanDersler) // Gönderilen öğrencinin dersleri structını alıp tüm derslerin notlarını toplayıp toplam kredi sayısına böler.
{
	float	ortalama;
	long	toplamnot;
	int		index;
	int		toplamkredi;

	index = 0;
	toplamnot = 0;
	toplamkredi = 0;
	while (alinanDersler[index].dersAdi)
	{
		toplamnot += alinanDersler[index].puan * alinanDersler[index].kredi;
		toplamkredi += alinanDersler[index].kredi;
		index++;
	}
	ortalama = toplamnot / toplamkredi;
	return (ortalama);
}

struct Ders	derseVeriAta(char *dersAdi, int kredi, int puan) // ders değişkeni oluşturur ve bu değişkenine veri ataması yapar.
{
	struct Ders	returnDers;

	returnDers.dersAdi = copystr(dersAdi);
	returnDers.kredi = kredi;
	returnDers.puan = puan;
	return (returnDers);
}

struct Ogrenci	ogrenciyeVeriAta(char *ogrAdi, char *ogrSoyadi, char *bolumu, struct Ders *aldigiDersler) // öğrenci değişkeni oluşturur ve bu değişkenine veri ataması yapar.
{
	struct Ogrenci	returnOgrenci;
	int				index;

	index = 0;
	returnOgrenci.aldigiDersler = malloc(sizeof(struct Ders) * 11);
	returnOgrenci.ogrAdi = copystr(ogrAdi);
	returnOgrenci.ogrSoyadi = copystr(ogrSoyadi);
	returnOgrenci.bolumu = copystr(bolumu);
	returnOgrenci.ortalama = ortalamaBul(aldigiDersler);
	while (aldigiDersler[index].dersAdi)
	{
		returnOgrenci.aldigiDersler[index].dersAdi = copystr(aldigiDersler[index].dersAdi);
		returnOgrenci.aldigiDersler[index].kredi = aldigiDersler[index].kredi;
		returnOgrenci.aldigiDersler[index].puan = aldigiDersler[index].puan;
		index++;
	}
	return (returnOgrenci);
}

void	ogrYazdir(struct Ogrenci yazdirilacakogrenci) // Öğrenci değişkeninin değerlerini ekrana yazar.
{
	int	index;

	index = 0;
	printf("Ogrenci Adi = %s\nOgrenci Soyadi = %s\nOgrenci Bolumu = %s\nOgrenci Ortalamasi = %f\n", yazdirilacakogrenci.ogrAdi, yazdirilacakogrenci.ogrSoyadi, yazdirilacakogrenci.bolumu, yazdirilacakogrenci.ortalama);
	while (yazdirilacakogrenci.aldigiDersler[index].dersAdi)
	{
		printf("\n------- Ders %d -------\n\n", index + 1);
		printf("Ders Adi = %s\n", yazdirilacakogrenci.aldigiDersler[index].dersAdi);
		printf("Ders Kredisi = %d\n", yazdirilacakogrenci.aldigiDersler[index].kredi);
		printf("Ders Notu = %d\n", yazdirilacakogrenci.aldigiDersler[index].puan);
		index++;
	}
}

void	ogrDiziYazdir(struct Ogrenci *ogrs) // Birden çok öğrenci varsa değerlerini ogrYazdir fonksiyonu yardımıyla ekrana yazar.
{
	int	index;

	index = 0;
	while (ogrs[index].ogrAdi)
	{
		printf("------- Ogrenci %d -------\n\n", index + 1);
		ogrYazdir(ogrs[index]);
		printf("\n");
		index++;
	}
}

float	dersAdinaGoreAritmetikOrtalama(struct Ogrenci *ogrs, char *dersAdi) // Bir dersi tüm öğrenciler arasında kıyaslama yaparak notlarını toplar ve aritmetik ortalamasını bulur.
{
	long	toplam;
	float	sonuc;
	int		i;
	int		j;
	int		derseGirenOgrenci;

	i = 0;
	j = 0;
	toplam = 0;
	sonuc = 0;
	derseGirenOgrenci = 0;
	while (ogrs[i].ogrAdi)
	{
		while (ogrs[i].aldigiDersler[j].dersAdi)
		{
			if (!strcmp(ogrs[i].aldigiDersler[j].dersAdi, dersAdi))
			{
				derseGirenOgrenci++;
				toplam += ogrs[i].aldigiDersler[j].puan;
			}
			j++;
		}
		j = 0;
		i++;
	}
	sonuc = toplam / derseGirenOgrenci;
	return (sonuc);
}

float	dersAdinaGoreStandartSapma(struct Ogrenci *ogrs, char *dersAdi) // Bir dersi tüm öğrenciler arasında kıyaslama yaparak notlarını toplar ve standart sapmasını ortalamasını bulur.
{
	float	sonuc;
	float	aritmetikOrtalama;
	long	temptoplam;
	int		i;
	int		j;
	int		derseGirenOgrenci;

	i = 0;
	j = 0;
	sonuc = 0;
	temptoplam = 0;
	derseGirenOgrenci = 0;
	aritmetikOrtalama = dersAdinaGoreAritmetikOrtalama(ogrs, dersAdi);
	while (ogrs[i].ogrAdi)
	{
		while (ogrs[i].aldigiDersler[j].dersAdi)
		{
			if (!strcmp(ogrs[i].aldigiDersler[j].dersAdi, dersAdi))
			{
				derseGirenOgrenci++;
				temptoplam += pow(ogrs[i].aldigiDersler[j].puan - aritmetikOrtalama, 2); // pow üs alma işlemi yapar
			}
			j++;
		}
		j = 0;
		i++;
	}
	sonuc = sqrt(temptoplam / derseGirenOgrenci); // sqrt karekök alma işlemi yapar.
	return (sonuc);
}

float	dersIcinKovaryansHesaplama(struct Ders *ders1, struct Ders *ders2) // alınan iki öğrencinin iki dersinin kovaryansını bulur.
{
	float	*toplamlar;
	float	sonuc;
	int		i;
	int		j;

	i = 0;
	j = 0;
	toplamlar = malloc(sizeof(float) * 2);
	while (ders1[i].dersAdi && i < 2)
	{
		while (ders2[j].dersAdi)
		{
			if (!strcmp(ders1[i].dersAdi, ders2[j].dersAdi))
			{
				toplamlar[i] = (((float)ders1[i].puan + (float)ders2[j].puan) / 2);
				break ;
			}
			j++;
		}
		j = 0;
		i++;
	}
	sonuc = ((ders1[0].puan - toplamlar[0]) * (ders1[1].puan - toplamlar[1])) / 2;
	free(toplamlar);
	return (sonuc);
}

void	ortalamayiGecenOgrenciler(struct Ogrenci *ogrs, char *dersAdi) // Yukarıdaki aritmetik ortalama hesaplama fonksiyonuyla ortalamayı bulup o puanı geçenleri ekrana bastırır.
{
	int	i;
	int	j;
	int	ort;

	i = 0;
	j = 0;
	ort = dersAdinaGoreAritmetikOrtalama(ogrs, dersAdi);
	while (ogrs[i].ogrAdi)
	{
		while (ogrs[i].aldigiDersler[j].dersAdi)
		{
			if (!strcmp(ogrs[i].aldigiDersler[j].dersAdi, dersAdi))
			{
				if (ogrs[i].aldigiDersler[j].puan > ort)
					printf("Adi = %s\tSoyadi = %s\n", ogrs[i].ogrAdi, ogrs[i].ogrSoyadi);
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void	ogrencileriDosyayaYazdir(struct Ogrenci *ogrs) // Öğrencileri fopen fonksiyonu yardımıyla dosya oluşturup ya da varsa sıfırlayıp yazdırır. (w = write)
{
	FILE	*fd;
	int		i;
	int		j;

	i = 0;
	j = 0;
	fd = fopen("ogrenciler.txt", "w");
	if (fd == NULL)
	{
		printf("Dosya hatasi!\n");
		exit(1);
	}
	while (ogrs[i].ogrAdi)
	{
		fprintf(fd, "ad=%s\n", ogrs[i].ogrAdi); // Dosyaya atama yaparken bazı anahtar kelimeler kullanıyorum. Bu sayede dosyayı okumak istediğimde hangi değer ne için atanmış olduğunu bilebilirim.
		fprintf(fd, "sa=%s\n", ogrs[i].ogrSoyadi); // ad = ad, sa = soyad, bo = bölüm, or = ortalama, da = ders adı, kr = kredi, pu = puan
		fprintf(fd, "bo=%s\n", ogrs[i].bolumu);
		fprintf(fd, "or=%f\n", ogrs[i].ortalama);
		while (ogrs[i].aldigiDersler[j].dersAdi)
		{
			fprintf(fd, "da=%s\n", ogrs[i].aldigiDersler[j].dersAdi);
			fprintf(fd, "kr=%d\n", ogrs[i].aldigiDersler[j].kredi);
			fprintf(fd, "pu=%d\n", ogrs[i].aldigiDersler[j].puan);
			j++;
		}
		j = 0;
		i++;
	}
	fclose(fd);
}

char	*satirbul(int fd) // Dosyayı harf harf okuyarak satır sonuna kadar okuma yapacağız
{
	char	*str;
	char	*temp;
	int		status;
	int		ifendfile;
	int		i;

	status = 0;
	ifendfile = 0;
	i = 0;
	str = malloc(sizeof(char) * 256);
	temp = malloc(sizeof(char) * 1);
	while (1)
	{
		status = read(fd, temp, 1); // dosyayı okuyup temp e atacak. kaç okuma yaptığını veya okuma yapıp yapamadığını status a int olarak atacak
		if (status > 0) // En az bir okuma yapıldığı durumda 1 e eşitliyorum
			ifendfile = 1;
		if (status == -1)
		{
			printf("Dosya acma hatasi!\n");
			exit(2);
		}
		if (status == 0)
		{
			if (ifendfile == 1) // Eğer bir okuma yapılmışsa break atıp o değeri alıyorum. Yapılmamışsa değişken değeri 0 gelip direkt NULL döndürecek
				break ;
			if (str)
				free(str);
			if (temp)
				free(temp);
			return (NULL);
		}
		if (temp[0] == '\n' || temp[0] == '\0')
			break ;
		str[i] = temp[0];
		i++;
	}
	str[i + 1] = '\0';
	if (temp)
		free(temp);
	return (str);
}

struct Ogrenci	*dosyadanVeriAl(char *dosya) // Dosyadan anahtar kelimelerine göre verileri ayrıştırarak verileri alır. Hatalı bir veri girildiği durumda hata verir.
{
	struct Ogrenci	*ogrs;
	int				fd;
	char			*satir;
	int				i;
	int				j;
	int				status;

	fd = open(dosya, O_RDWR); // Bu dosyayı fopen yerine open kullanarak açıyorum. Bunun sebebi dosya içeriğini read ile okuyacak olmam. O_RDWR = Read, D = bilmiyorum, W = Write, R = Read. Yani tüm yetkileri vermiş oldum.
	i = 0;
	j = 0;
	status = 0;
	if (fd == -1) // Dosyanın açılamama durumu
	{
		printf("Dosya acilamadi!\n");
		exit(1);
	}
	ogrs = malloc(sizeof(struct Ogrenci) * 10); // Yer açma işlemleri
	while (i < 10)
	{
		ogrs[i].aldigiDersler = malloc(sizeof(struct Ders) * 11);
		i++;
	}
	i = 0;
	while (i < 10) // Dosyayı satır satır okuyup ilk iki karakterine göre karşılaştırma yapıyorum ki ne olduğunu anlayabileyim.
	{
		if (satir && i != 0 && status == 0) // Döngü tekrar çalıştığında satırı freeler
			free(satir);
		if (status == 0) // Statusu kullanma sebebim bir kişi için 1 ders bile yazılsa 10 tane beklemeyip yeni kişiye geçebilmesi. Eğer 0 ise Tekrardan satır okumasına gerek yok çünkü aşağıda kontrol ederken okumuş oluyorum.
			satir = satirbul(fd);
		if (satir && (satir[0] == 'a' && satir[1] == 'd' && satir[2] == '=')) // Bu if else koşulları tamamen aynı. Anahtar kelimelerin olup olmadığını kontrol edip ona göre hata veriyor.
		{
			ogrs[i].ogrAdi = copystr(satir + 3);
			status = 0;
		}
		else
		{
			if (satir == NULL && i != 0) // Dosyanın bittiği durum
				break ;
			if (satir) // Dosyanın bitmediği ancak yanlış girdi olma durumu
				free(satir);
			printf("Girdi sirasi ya da yapisi yanlis!\n");
			exit(3);
		}
		free(satir);
		satir = satirbul(fd);
		if (satir && (satir[0] == 's' && satir[1] == 'a' && satir[2] == '='))
			ogrs[i].ogrSoyadi = copystr(satir + 3);
		else
		{
			if (satir)
				free(satir);
			printf("Girdi sirasi ya da yapisi yanlis!\n");
			exit(4);
		}
		free(satir);
		satir = satirbul(fd);
		if (satir && (satir[0] == 'b' && satir[1] == 'o' && satir[2] == '='))
			ogrs[i].bolumu = copystr(satir + 3);
		else
		{
			if (satir)
				free(satir);
			printf("Girdi sirasi ya da yapisi yanlis!\n");
			exit(5);
		}
		free(satir);
		satir = satirbul(fd);
		if (satir && (satir[0] == 'o' && satir[1] == 'r' && satir[2] == '='))
			ogrs[i].ortalama = atof(satir + 3);
		else
		{
			if (satir)
				free(satir);
			printf("Girdi sirasi ya da yapisi yanlis!\n");
			exit(6);
		}
		while (j != 10)
		{
			free(satir);
			satir = satirbul(fd);
			if (satir && satir[0] == 'a' && satir[1] == 'd' && satir[2] == '=') // Eğer 10 tane ders yoksa ve sonraki satırdaki anahtar kelime ad ise tekrardan yeni öğrenci ekliyor.
			{
				status = 1; // Bunu belirtmek için de 1 veriyorumki yukarıda tekrar satır alıp bu değeri kaybetmeyeyim.
				break ;
			}
			if (satir && (satir[0] == 'd' && satir[1] == 'a' && satir[2] == '='))
				ogrs[i].aldigiDersler[j].dersAdi = copystr(satir + 3);
			else
			{
				if (!satir && j != 0) // Dosyanın sonuna geldiğinde herhangi bir ders girilmişse sıkıntı çıkarmadan koda devam eder. Bir ders eklenmemişse hata verir.
					break ;
				if (satir)
					free(satir);
				printf("Girdi sirasi ya da yapisi yanlis!\n");
				exit(7);
			}
			free(satir);
			satir = satirbul(fd);
			if (satir && (satir[0] == 'k' && satir[1] == 'r' && satir[2] == '='))
				ogrs[i].aldigiDersler[j].kredi = atoi(satir + 3);
			else
			{
				if (satir)
					free(satir);
				printf("Girdi sirasi ya da yapisi yanlis!\n");
				exit(8);
			}
			free(satir);
			satir = satirbul(fd);
			if (satir && (satir[0] == 'p' && satir[1] == 'u' && satir[2] == '='))
				ogrs[i].aldigiDersler[j].puan = atoi(satir + 3);
			else
			{
				if (satir)
					free(satir);
				printf("Girdi sirasi ya da yapisi yanlis!\n");
				exit(9);
			}
			j++;
		}
		i++;
		j = 0;
	}
	close(fd);
	i = 0;
	while (ogrs[i].ogrAdi) // Kullanılmayan öğrenci indislerine indeksimi getiriyorum.
		i++;
	while (i < 10) // Kullanılmayan indisler için açtığım aldığı struct yerlerini freeliyorum.
	{
		free(ogrs[i].aldigiDersler);
		i++;
	}
	free(satir);
	return (ogrs);
}

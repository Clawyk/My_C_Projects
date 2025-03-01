#include <stdio.h>
#include <string.h>

int main() 
{
    FILE *dosya;
    
	char satir[1024];
    char aranan_zaman[20];
    
	int yil, ay, gun, saat;
    
	const char *aylar[] = {"", "Ocak", "Subat", "Mart", "Nisan", "Mayis", "Haziran", 
                           "Temmuz", "Agustos", "Eylul", "Ekim", "Kasim", "Aralik"};

    
    dosya = fopen("konya_hava_durumu.csv", "r");
    
	if (dosya == NULL)
	{
        printf("Dosya acilamadi!\n");
        
		return 1;
    }

    
    for (int i = 0; i < 4; i++) 
	{
        fgets(satir, 1024, dosya);
    }

	printf ("****KONYA HAVA DURUMU UYGULAMASINA HOSGELDINIZ****\n");

    printf("Hangi yili istiyorsunuz? (or: 2025): ");
    scanf("%d", &yil);
    
	if (yil != 2025) 
	{
        printf("Gecersiz yil! Yalnizca 2025 verisi mevcut.\n");
        fclose(dosya);
        
		return 1;
    }

    printf("Hangi ayi istiyorsunuz? (1-12): ");
    scanf("%d", &ay);
    
	if (ay < 1 || ay > 12) 
	{
        printf("Gecersiz ay! 1-12 arasinda bir deger girin.\n");
        fclose(dosya);
        
		return 1;
    }

    printf("Hangi gunu istiyorsunuz? (1-31): ");
    scanf("%d", &gun);
    if (gun < 1 || gun > 31) 
	{
        printf("Gecersiz gun! 1-31 arasinda bir deger girin.\n");
        fclose(dosya);
        
		return 1;
    }

    printf("Hangi saati istiyorsunuz? (0-23): ");
    scanf("%d", &saat);
    
	if (saat < 0 || saat > 23) 
	{
        printf("Gecersiz saat! 0-23 arasinda bir deger girin.\n");
        fclose(dosya);
        
		return 1;
    }

    
    sprintf(aranan_zaman, "%04d-%02d-%02dT%02d:00", yil, ay, gun, saat);

    
    while (fgets(satir, 1024, dosya) != NULL) 
	{
        char zaman[20];
        float sicaklik;
        
		sscanf(satir, "%[^,],%f", zaman, &sicaklik);

        if (strcmp(zaman, aranan_zaman) == 0) 
		{
            printf("%d %s %d Saat %02d:00 Tarihinde Konya Hava Durumu Su Sekilde; Sicaklik: %.1f Santigrat Derece\n", gun, aylar[ay], yil, saat, sicaklik);
            fclose(dosya);
            
			return 0;
        }
    }

    printf("Bu zamana ait veri bulunamadi!\n");
    fclose(dosya);
    
	return 0;
}
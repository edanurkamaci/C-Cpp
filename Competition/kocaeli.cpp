#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;
class Parca
{
private:
	string name;
public:
	string markaModel[6];
	vector<float>fiyat;
	Parca() {};
	void markAta(int);
};
class Islemler :public Parca
{
private:
	string tarih;
	string uyum;
	double satisFatura;
	double alisFatura;
	Parca parc[10];
public:

	Islemler()
	{
		satisFatura = 0;
		alisFatura = 0;
	}
	void setValues();
	int tercih();
	void urunSec();
	bool uyumluMu(string);
	void faturaYazdir(float a[], string b[],int);

};
int main()
{
	Islemler is;

	is.setValues();
	is.urunSec();

	std::cout << endl << endl;
	std::system("pause");
	return 0;
}
void Islemler::setValues()
{
	parc[0].markAta(1);
	parc[1].markAta(2);
	parc[2].markAta(3);
	parc[3].markAta(4);
	parc[4].markAta(5);
	parc[5].markAta(6);
	parc[6].markAta(7);
	parc[7].markAta(8);
	parc[8].markAta(9);
	parc[9].markAta(10);
}
int Islemler::tercih()
{
	int sec;
	cout << "[1]- Tek tek parca alinimi" << endl;
	cout << "[2]- PC toplama" << endl << endl;

	while (1)
	{
		cout << "Hangisini yapmak istiyorsunuz( 1 veya 2): ";
		cin >> sec;

		if (sec == 1 || sec == 2)
			break;
		else
			cout << "Hatali giris! Tekrar deneyiniz!";
	}
	system("cls");
	return sec;
}
void Parca::markAta(int number)
{
	if (number == 1)
	{
		name = "Anakart";
		markaModel[0] = "MSI X570-A PRO AM4 (AMD) DDR4 4400 mhz (Oc) 2 x M.2 USB 3.2                ";
		markaModel[1] = "MSI A320M-A PRO MAX AM4 (AMD) DDR4 3200(OC) DVI HDMI M.2 USB3.2            ";
		markaModel[2] = "Asus Prime H310M-K R2.0 Intel H310 2666MHz DDR4 Soket 1151 mATX      ";
		markaModel[3] = "Asus TUF B450-Pro Gaming AMD B450 DDR4 4400 MHz (OC) Am4 Atx         ";
		markaModel[4] = "Gigabyte B450M S2H AMD B450 2133MHz DDR4 Soket AM4 mATX              ";
		markaModel[5] = "Gigabyte Z490 Aorus Elite AC Intel ® Z490 5000 MHz DDR4 1200 Pin ATX  ";
		fiyat.push_back(1499); fiyat.push_back(529.01); fiyat.push_back(514.90); fiyat.push_back(1049); fiyat.push_back(633.69); fiyat.push_back(2992.02);

	}
	else if (number == 2)
	{
		name = "Islemci";
		markaModel[0] = "Intel Core i5-3470 3.2GHz 6MB Cache Tray         ";
		markaModel[1] = "Intel Core i5 10400F 2.90GHz LGA1200 12MB Cache  ";
		markaModel[2] = "Intel Core i7 10700F 2.9GHz LGA1200 16MB Cache   ";
		markaModel[3] = "Intel Core i7 10700K 3.8GHz LGA200 12MB Cache    ";
		markaModel[4] = "AMD Ryzen 5 3600 3,6GHz 35MB Cache Soket AM4     ";
		markaModel[5] = "AMD Ryzen 7 5800X 3.8GHz 36MB Cache Soket AM4    ";
		fiyat.push_back(555.15); fiyat.push_back(1498.99); fiyat.push_back(2869); fiyat.push_back(3499); fiyat.push_back(1899); fiyat.push_back(4299);
	}
	else if (number == 3)
	{
		name = "RAM";
		markaModel[0] = "Kingston 8GB 1600MHz DDR3 Notebook Sodimm    ";
		markaModel[1] = "Kingston ValueRam 8GB 1600MHz DDR3 Notebook  ";
		markaModel[2] = "Kingston 8GB 2400MHz DDR4                    ";
		markaModel[3] = "Corsair Vengeance LPX 8GB 3000MHz DDR4       ";
		markaModel[4] = "Corsair 16GB(2x8GB) DDR4 3200MHz CL16        ";
		markaModel[5] = "Adata XPG Gammix D30 8GB 3000MHz DDR4        ";
		fiyat.push_back(367.49); fiyat.push_back(349); fiyat.push_back(499.82); fiyat.push_back(439); fiyat.push_back(1099); fiyat.push_back(429);
	}
	else if (number == 4)
	{
		name = "Hard Disk";
		markaModel[0] = "Seagate Barracuda 1TB 3.5 7200RPM 64MB Cache Sata 3  ";
		markaModel[1] = "Seagate Barracuda 1TB 2.5 5400RPM 128MB Cache Sata 3 ";
		markaModel[2] = "Seagate Barracuda 1TB 2.5 5400RPM 128MB Cache Sata 3 ";
		markaModel[3] = "WD Purple 2TB Intellipower Sata 3.0 64Mb 3,5         ";
		markaModel[4] = "WD Blue 500GB 7200RPM 32MB 3,5 Sata 3.0              ";
		markaModel[5] = "WD Blue 1TB 7200RPM Sata 3.0 64Mb 3,5                ";
		fiyat.push_back(378.99); fiyat.push_back(398.79); fiyat.push_back(528.99); fiyat.push_back(498); fiyat.push_back(248.99); fiyat.push_back(378);

	}
	else if (number == 5)
	{
		name = "Kasa";
		markaModel[0] = "MSI MAG Forge 100M Temperli Cam 2x RGB Fan 120mm Fan ATX                         ";
		markaModel[1] = "m 2x A-RGB Fan 120mm Fan ATX                                                     ";
		markaModel[2] = "Asus GT301 TUF Gaming Tempered Glass RGB USB 3.1 ATX                             ";
		markaModel[3] = "Asus TUF Gaming GT501 MidTower                                                   ";
		markaModel[4] = "Dark Diamond PRO Mesh 4x12cm FRGB Fan, Full Akrilik Yan Panel, USB 3.0           ";
		markaModel[5] = "Corsair CC-9011151-EU SPEC-05 MidTower Oyuncu Kasa + VS550 550 Watt 80 Plus PSU  ";
		fiyat.push_back(539); fiyat.push_back(599); fiyat.push_back(898.99); fiyat.push_back(1539); fiyat.push_back(449); fiyat.push_back(795.5);
	}
	else if (number == 6)
	{
		name = "Ekran Karti";
		markaModel[0] = "MSI GeForce GTX 1650 D6 VENTUS XS OCV2 4GB 128Bit GDDR6 PCI-Express x16         ";
		markaModel[1] = "MSI NVIDIA GeForce GTX 1050 TI Gaming X 4G 4GB 128 bit GDDR5 DX(12) PCI-E 3.0   ";
		markaModel[2] = "MSI NVIDIA GeForce GT 710 2GD3H LP 2GB 64 bit DDR3 DX(12) PCI-E 2.0             ";
		markaModel[3] = "MSI 4GT LP Radeon RX 550 OC 4GB GDDR5 128Bit (DX12) PCI-E 3.0 X16               ";
		markaModel[4] = "Asus GT1030 PH-GT1030-O2G 2GB 64Bit GDDR5                                       ";
		markaModel[5] = "Asus GeForce GTX 1650 OC 4GB 1665MHz GDDR6 DX(12) PCI-Express 3.0               ";
		fiyat.push_back(4683.32); fiyat.push_back(4999); fiyat.push_back(613.68); fiyat.push_back(2399); fiyat.push_back(1058.87); fiyat.push_back(3650);
	}
	else if (number == 7)
	{
		name = "Guc Kaynagi";
		markaModel[0] = "Sharkoon SHP650 V2  650W 80+ 120 mm Fanlý ATX                   ";
		markaModel[1] = "Sharkoon Ss-Cool Zero 650W 80+ Gold Atx Güç Kaynað              ";
		markaModel[2] = "Sharkoon Silentstorm Cool Zero 850 W 80+ Gold Tam Modüler Psu   ";
		markaModel[4] = "GameTech GTP-500 500W 80 Plus Bronze Sertifikalý Power Supply   ";
		markaModel[5] = "Gametech GTP-550 550W 80 Plus Bronze Power Supply               ";
		markaModel[3] = "Gametech GTP-600 600W 80 Plus Bronze Power Supply               ";
		fiyat.push_back(369); fiyat.push_back(949); fiyat.push_back(1188.99); fiyat.push_back(369.90); fiyat.push_back(315.10); fiyat.push_back(344.65);
	}
	else if (number == 8)
	{
		name = "Monitor";
		markaModel[0] = "MSI Optix G241 23.8 144Hz 1ms(HDMI + Display) FreeSync Full HD IPS            ";
		markaModel[1] = "MSI Optix G241 23.8 144Hz 1ms(HDMI + Display) FreeSync Full HD IPS            ";
		markaModel[2] = "MSI OPTIX G27C5 FHD 27 VA 165HZ 1MS HDMI+DP Curved Gaming                     ";
		markaModel[3] = "Asus VP249QGR 23.8 144Hz 1ms(Analog + Display + HDMI) FreeSync Full HD IPS    ";
		markaModel[4] = "Asus Tuf Gaming VG24VQ 23.6 144Hz 1ms(HDMI + Display) Freesync Curved         ";
		markaModel[5] = "Asus TUF Gaming VG249Q1R 23.8 165Hz 1ms(HDMI + Display) FreeSync Full HD IPS  ";
		fiyat.push_back(1449); fiyat.push_back(1448); fiyat.push_back(1899); fiyat.push_back(1449); fiyat.push_back(1908.80); fiyat.push_back(1994.05);
	}
	else if (number == 9)
	{
		name = "Klavye";
		markaModel[0] = "Classone RGB10 Metal LED Iþýklý                                                    ";
		markaModel[1] = "Classone Wk628-U Classone Q Usb Multimedya Ultra Slim                              ";
		markaModel[2] = "Logitech K270 Kablosuz Klavye-Siyah                                                ";
		markaModel[3] = "Logitech K380 Bluetooth Siyah Klavye                                               ";
		markaModel[4] = "Logitech G G213 Prodigy Oyuncu Klavyesi - Siyah                                    ";
		markaModel[5] = "Rampage KB-R99 X-Coral Rainbow Aydýnlatmalý Metal Yüzeyli Gaming Oyuncu Klavyesi   ";
		fiyat.push_back(103.5); fiyat.push_back(59); fiyat.push_back(219); fiyat.push_back(298.40); fiyat.push_back(394.93); fiyat.push_back(124.5);
	}
	else if (number == 10)
	{
		name = "Fare";
		markaModel[0] = "Logitech M170 Kablosuz Mouse-Gri                               ";
		markaModel[1] = "Logitech M191 Kablosuz Mouse - Gri                             ";
		markaModel[2] = "Logitech G G102 Lightsync Gaming Mouse                         ";
		markaModel[3] = "Logitech M185 Kablosuz Mouse-Gri                               ";
		markaModel[4] = "Logitech M185 Kablosuz Mouse-Gri                               ";
		markaModel[5] = "Rampage SMX-R90 Sector USB 16000DPI RGB Macrolu Oyuncu Mouse   ";
		fiyat.push_back(92.67); fiyat.push_back(125.25); fiyat.push_back(189); fiyat.push_back(107.97); fiyat.push_back(146); fiyat.push_back(202.76);
	}
}
void Islemler::urunSec()
{
	int i = 0,k=0,flag=0;
	int secim;
	int alimSecim;
	string alinanlar[20];
	float fiyatlar[20];
	std::cout << fixed << showpoint;
	std::cout << setprecision(2);
	
	std::cout << "Lutfen Fatura Tarihini giriniz: ";
	std::cin >> tarih;

	std::system("cls");
	if (tercih() == 1)
	{
		while (1)
		{
			std::cout << "******** PARCALAR ********" << endl << endl
				<< "1. Anakart" << endl
				<< "2. Islemci" << endl
				<< "3. RAM" << endl
				<< "4. Hard Disk" << endl
				<< "5. Kasa" << endl
				<< "6. Ekran Karti" << endl
				<< "7. Guc Kaynagi" << endl
				<< "8. Monitor" << endl
				<< "9. Klavye" << endl
				<< "10. Fare" << endl<<endl;

			while (1)
			{
				std::cout << "Bakacaginiz urunun numarasini giriniz(cikmak icin sifira basiniz): ";
				cin >> secim;

				if (secim >=0 && secim < 11)
					break;
				else
					std::cout << "Hatali giris tekrar deneyiniz!" << endl << endl;
			}
			if (secim == 0)
				break;
			std::system("cls");
			std::cout << "********** MODELLER **********" << endl << endl;
			for (i = 0; i < 6; i++)
			{
				std::cout << i + 1 << ". " << parc[secim - 1].markaModel[i] << "------> Fiyat: " << parc[secim - 1].fiyat[i] << " TL" << endl;
			}
			while (1)
			{
				std::cout << endl << "Almak istediginiz urunun numarasini giriniz (Geri gitmek icin -1 giriniz): ";
				std::cin >> alimSecim;

				if ((alimSecim >0 && alimSecim < 7)||alimSecim==-1)
					break;
				else
					std::cout << "Hatali giris tekrar deneyiniz!" << endl << endl;
			}
			if (alimSecim != -1)
			{
				satisFatura += parc[secim - 1].fiyat[alimSecim - 1];
				alinanlar[k] = parc[secim - 1].markaModel[alimSecim - 1];
				fiyatlar[k] = parc[secim - 1].fiyat[alimSecim - 1];
				k++;
			}
			
			std::system("cls");
		}
	}
	else
	{
		while (1)
		{
			std::cout << "******** PARCALAR ********" << endl << endl
				<< "1. Anakart" << endl
				<< "2. Islemci" << endl
				<< "3. RAM" << endl
				<< "4. Hard Disk" << endl
				<< "5. Ekran Karti" << endl << endl;

			while (1)
			{
				std::cout << "Bakacaginiz urunun numarasini giriniz(cikmak icin sifira basiniz): ";
				cin >> secim;

				if (secim >= 0 && secim < 6)
					break;
				else
					std::cout << "Hatalý giris tekrar deneyiniz!" << endl << endl;
			}
			if (secim == 0)
				break;
			std::system("cls");
			std::cout << "********** MODELLER **********" << endl << endl;
			for (i = 0; i < 6; i++)
			{
				if (secim == 5)
				{
					std::cout << i + 1 << ". " << parc[secim].markaModel[i] << "------> Fiyat: " << parc[secim].fiyat[i] << " TL" << endl;
				}
				else
					std::cout << i + 1 << ". " << parc[secim - 1].markaModel[i] << "------> Fiyat: " << parc[secim - 1].fiyat[i] << " TL" << endl;
			}
			while (1)
			{
				std::cout <<endl<< "Almak istediginiz urunun numarasini giriniz(Geri gitmek icin -1 giriniz): ";
				std::cin >> alimSecim;

				if (alimSecim > 0 && alimSecim < 7)
				{
					if ((secim == 1 || secim == 2) && flag != 0)
					{
						if (uyumluMu(parc[secim - 1].markaModel[alimSecim - 1]) == 0 && flag == 1)
						{
							cout << "Sectiginiz cihaz uyumlu degildir. Baska bir sey tercih ediniz!" << endl << endl;
							continue;
						}
						else
							break;
					}
					else
						break;
				}
				else if (alimSecim == -1)
					break;
				else
					std::cout << "Hatali giris tekrar deneyiniz!" << endl << endl;
			}
			if (secim == 5)
			{
				satisFatura += parc[secim].fiyat[alimSecim - 1];
				alinanlar[k] = parc[secim].markaModel[alimSecim - 1];
				fiyatlar[k] = parc[secim].fiyat[alimSecim - 1];
				k++;
			}
	        else if(alimSecim!=-1)
			{
				if ((secim == 1 || secim == 2)&& flag==0)
				{
					if (parc[secim - 1].markaModel[alimSecim - 1].find("Intel") != std::string::npos)
					{
						uyum = "Intel";
					}
					else
						uyum = "AMD";
					flag = 1;
				}
			    satisFatura += parc[secim - 1].fiyat[alimSecim - 1];
			    alinanlar[k] = parc[secim - 1].markaModel[alimSecim - 1];
			    fiyatlar[k] = parc[secim - 1].fiyat[alimSecim - 1];
			    k++;
			}
			std::system("cls");
		}
	}

	faturaYazdir(fiyatlar,alinanlar,k);
}
bool Islemler::uyumluMu(string word)
{
	if (word.find(uyum) != std::string::npos)
		return 1;
	else
		return 0;
}
void Islemler::faturaYazdir(float a[],string b[],int size)
{
	int c;
	std::cout << endl << endl;
	
	for (c = 0; c < size; c++)
	{
		std::cout <<"*"<<setfill(' ')<<setw(100)<<left<<b[c] << setw(6) << right<<" Fiyat: " << a[c] << " TL" << endl;
	}

	std::cout << endl<< "Toplam tutar: " << setw(87) << left << satisFatura<< setw(6) << right<<" Tarih: "<<tarih;
}
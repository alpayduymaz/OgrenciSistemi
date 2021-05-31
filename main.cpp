#include <iostream>
#include <string>
#include <string.h>
using namespace std;
struct Ogrenci
{
string isim,harfnotu;
int ogrencino,*testnotlari;
double ortalama;
};
void veriAl(Ogrenci *ogr,int ogrencisayisi,int testsayisi);
double notHesapla(int *notPtr,int testadedi);
void goster(Ogrenci *ogr2,int ogrenciadedi,int testadedi);
void sil(Ogrenci *ogr3, int ogrencisayi);
int main()
{
    int ogrenciSayisi,testSayisi;
    cout << "Ogrenci sayisini giriniz :";
    cin >> ogrenciSayisi;
    cout << "Test sayisini giriniz :";
    cin >> testSayisi;

    Ogrenci *ogrenci = new Ogrenci[ogrenciSayisi];

    for(int i=0;i<ogrenciSayisi;i++)
        ogrenci[i].testnotlari = new int[testSayisi];  // Bellekten her ogrenci için test notlari sayýsýx4byte kadar yer ayrildi

    veriAl(&ogrenci[0],ogrenciSayisi,testSayisi);  // ogrenci arrayinin baslangic adresi parametrede ki pointera geçilerek tüm array üzerinde iþlem yapildi

    for(int i=0;i<ogrenciSayisi;i++)  // notHesapla fonksiyonu double bir deger döndürdüðü için o dönen deger ile burada her öðrenincinin harf notunu belirledik
    {
        ogrenci[i].ortalama = notHesapla(&ogrenci[i].testnotlari[0],testSayisi);  // Her öðrencinin test notlari için ayrýlan bellek adresi pointera gönderildi
        if(ogrenci[i].ortalama <= 100 && ogrenci[i].ortalama >= 85)
            ogrenci[i].harfnotu = "A";
        else if(ogrenci[i].ortalama <= 84 && ogrenci[i].ortalama >= 75)
            ogrenci[i].harfnotu = "B";
        else if(ogrenci[i].ortalama <= 74 && ogrenci[i].ortalama >= 65)
            ogrenci[i].harfnotu = "C";
        else if(ogrenci[i].ortalama <= 64 && ogrenci[i].ortalama >= 50)
            ogrenci[i].harfnotu = "D";
        else if(ogrenci[i].ortalama <= 50 && ogrenci[i].ortalama >= 0)
            ogrenci[i].harfnotu = "F";
    }

    goster(&ogrenci[0],ogrenciSayisi,testSayisi); // ogrenci arrayinin baslangic adresi parametrede ki pointera geçilerek tüm array üzerinde islem yapildi

    sil(&ogrenci[0], ogrenciSayisi); // ogrenci arrayinin baslangic adresi parametrede ki pointera geçilerek tüm array üzerinde iþlem yapildi

    return 0;
}

void veriAl(Ogrenci *ogr,int ogrencisayisi,int testsayisi) // Ogrenci bilgileri aliniyor
{
    for(int i=0;i<ogrencisayisi;i++)
    {
        cout << i+1 << ". ogrencinin adi: ";
        cin >> ogr[i].isim;
        cout << i+1 << ". ogrencinin numarasi: ";
        cin >> ogr[i].ogrencino;
        for(int j=0;j<testsayisi;j++)
        {
            cout << i+1 << ". ogrencinin " << j+1 << ". test notu : ";
            cin >> ogr[i].testnotlari[j];
        }
    }
}

double notHesapla(int *notPtr,int testadedi)
{
    double toplam=0;

    for(int i=0;i<testadedi;i++)
        toplam += notPtr[i];

    return toplam/testadedi;  // gelen ogrencinin notarrayindeki degerlerin ortalamasi geri döndürüldü
}

void goster(Ogrenci *ogr2,int ogrenciadedi,int testadedi)
{
    system("cls");  // Konsol temizlendi
    cout << "**** OGRENCI BILGILERI ****";
    for(int i=0;i<ogrenciadedi;i++)   // Her öðrenci için özellikler ekrana yazdirildi
    {
        cout << endl << i+1 << ". ogrencinin adi: " << ogr2[i].isim;
        cout << endl << i+1 << ". ogrencinin numarasi: " << ogr2[i].ogrencino;
        for(int j=0;j<testadedi;j++)  // Siradaki öðrencinin notlari birden fazla olabileceði için döngü kullanildi
        {
            cout << endl << i+1 << ". ogrencinin " << j+1 << ". test notu : " << ogr2[i].testnotlari[j];
        }
        cout << endl << i+1 << ". ogrencinin ortalamasi: " << ogr2[i].ortalama << endl << i+1 << ". ogrencinin harf notu: " << ogr2[i].harfnotu << endl;
    }
}

void sil(Ogrenci *ogr3, int ogrencisayi)
{
    delete[] ogr3;

    for(int i=0;i<ogrencisayi;i++)
        delete[] ogr3[i].testnotlari;  // her ögrenci için testnotlari arrayine ayrilan bellek geri birakildi
}

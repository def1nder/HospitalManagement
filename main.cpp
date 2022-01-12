/*  --------------------------------------------------------------------------------------------------------
 *   Created by Ferhad Abdulkerimov on 09.01.22.
 *
 *   5 işlem vardır: Database oluşturma, Doktor paneli, Hasta kaydı silme ve Hasta arama.
 *   Hasta silme ile arama fonksiyonum: Linear Search kavramı ile çalışmaktadır. İnputumuz küçük olduğundan
 *   Linear Search algoritması tercih edilmiştir. Eğer input büyük olsa idi Binary Search algoritmasını
 *   tercih ederdim.
 *
 *   --->>> Doktor girişi için şifre - 12345 <<<---
 *   -------------------------------------------------------------------------------------------------------
 */
#include <iostream>
#include <vector>
#define max 15
typedef long long ll;
using namespace std;

struct hasta {

    string sigorta, recete, name, age;
    ll tcID, telno;
    vector<int> sikayet;
    int a;

};

int num, tedaviUcretleri = 0, pass = 12345, pass2;
ll kontrol;
char sigortaDurumu, q;
hasta hast[max];

void showMenu();

void doctorPanel() {

    cout << " ------------------ DOKTORLAR İÇİN YÖNETİM PANELİ ------------------ \n";

    cout << "Doktor olarak giriş yapmak için password giriniz: " << "\n";
    cin >> pass2;

    if (pass2 == pass){
        for (int i = 0; i < num; i++) {

            cout << "Hastanın ismi: "
                 << hast[i].name << "\n";

            cout << "Hastanın TC numarasi: "
                 << hast[i].tcID << "\n";

            cout << "Hastanın telefon numarasi: "
                 << hast[i].telno << "\n";

            cout << "Hastanın yasi: "
                 << hast[i].age << "\n";

            cout << "Hastanın sigorta durumu: "
                 << hast[i].sigorta << "\n";
            /*
            if (hast[i].sikayet[i] == 1){
                cout << hast[i].name << " isimli hastamizin noroloji sikintilari vardir "
                                        "ve 100 tl tedavi odemesi yapildi." << "\n";
            }else if (hast[i].sikayet[i] == 2){
                cout << hast[i].name << " isimli hastamizin bas agrilari sikintilari vardir "
                                        "ve 200 tl tedavi odemesi yapildi." << "\n";
            }else if (hast[i].sikayet[i] == 3){
                cout << hast[i].name << " isimli hastamizin cilt sikintilari vardir "
                                        "ve 300 tl tedavi odemesi yapildi." << "\n";
            }
             */
            if (hast[i].a == 1){
                cout << hast[i].name << " isimli hastamızın nöroloji sıkıntıları vardır "
                                        "ve 100 tl tedavi odemesi yapıldı." << "\n";
            }else if(hast[i].a == 2){
                cout << hast[i].name << " isimli hastamızın baş ağrıları sıkıntıları vardır "
                                        "ve 200 tl tedavı odemesı yapıldı." << "\n";
            }else if(hast[i].a == 3){
                cout << hast[i].name << " isimli hastamızın cilt sıkıntıları vardır "
                                        "ve 300 tl tedavi ödemesi yapıldı." << "\n";
            }
            cout << "---------------------------------------" << "\n";
        }
        cout << "Reçete yazmak istediğiniz hastanın TC numarasını giriniz: " << "\n";

        cin >> kontrol;
        for (int i = 0; i < num; ++i) {
            if(hast[i].tcID == kontrol){

                cout << kontrol << " ile eşleşme başarılı!" << "\n";
                cout << "Reçete yazınız: " << "\n";
                cin >> hast[i].recete;
                cout << "Reçete yazma işlemi başarılı!" << "\n";
            }
        }
        cout << "Çıkış yapmak için Q harfine basınız. Eğer işlemlerinize devam etmek istiyorsanız D basınız: ";

        cin >> q;
        if (q == 'Q'){
            showMenu();
        }else{
            doctorPanel();
        }
    }
}
void database()
{
    cout << "Hasta database'i oluşturma oturumu\n";
    cout << "Maximum giriş "<< max << " olmalıdır.\n";

    cout << "Tabloda kaç hasta olucak ?: ";
    cin >> num;

    if (num > 15) {
        cout << "Maximum giriş "<< max << " ile sınırlıdır! - Database 15'e eşitlendi\n";
        num = 15;
    }
    cout << "Verileri giriniz:\n";

    for (int i = 0; i < num; i++) {

        cout << "\n";
        cout << i+1 << ". giriş" << "\n";
        cout << "Hastanın ismi: ";
        cin >> hast[i].name;

        cout << "Hastanın TC numarası: ";
        cin >> hast[i].tcID;

        cout << "Hastanın telefon numarası: ";
        cin >> hast[i].telno;
        cout << "Hastanın yaşı: ";
        cin >> hast[i].age;

        cout << "Sigortınız var ise 'E/e' basınız, aksi takdirde 'H/h' ";

        cin >> sigortaDurumu;
        if (sigortaDurumu == 'E' || sigortaDurumu == 'e'){

            cout << "Sigorta şirketinizin ismini giriniz: ";
            cin >> hast[i].sigorta;

            cout << "3 şikayetden seçtiğinize göre 1, 2 veya 3 diye veri giriniz\n"
                    "1(Nöroloji) - 2(Baş Ağrıları) - 3(Cildiye) ";
            int giris;
            cin >> giris;
            if (giris == 1){

                cout << "Randevu tarihiniz 17 Ocak, saat 15:00 diye berillendi.";
               // hast[i].sikayet.push_back(1);
                hast[i].a = 1;

            }else if(giris == 2){

                cout << "Randevu tarihiniz 17 Ocak, saat 17:00 diye berillendi. " << "\n";
               // hast[i].sikayet.push_back(2);
                hast[i].a = 2;

            }else if(giris == 3){

                cout << "Randevu tarihiniz 17 Ocak, saat 18:00 diye berillendi. " << "\n";
               // hast[i].sikayet.push_back(3);
                hast[i].a = 3;
            }
        }else if (sigortaDurumu == 'H' || sigortaDurumu == 'h'){

            hast[i].sigorta = "Sigorta yok";
            long bankaKarti;
            cout << "3 şikayetden seçtiğinize göre 1, 2 veya 3 diye veri giriniz\n"
                    "1(Nöroloji-100TL) - (Baş Ağrıları-200TL) - (Cildiye-300TL) ";
            int giris;
            cin >> giris;

            if (giris == 1){

               // hast[i].sikayet.push_back(1);
                hast[i].a = 1;
                cout << "Banka kartınızın numarasını giriniz: ";
                cin >> bankaKarti;
                tedaviUcretleri+=100;
                cout << "Banka kartınızdan tutar silindi. Randevu tarihiniz 18 Ocak, saat 10:00 diye berillendi." << "\n";

            }else if(giris == 2){

               // hast[i].sikayet.push_back(2);
                hast[i].a = 2;
                cout << "Banka kartınızın numarasını giriniz: ";
                cin >> bankaKarti;
                tedaviUcretleri+=200;
                cout << "Banka kartınızdan tutar silindi. Randevu tarihiniz 17 Ocak, saat 15:00 diye berillendi." << "\n";

            }else if(giris == 3){

               // hast[i].sikayet.push_back(2);
                hast[i].a = 3;
                cout << "Banka kartınızın numarasını giriniz: ";
                cin >> bankaKarti;
                tedaviUcretleri+=300;
                cout << "Banka kartınızdan tutar silindi. Randevu tarihiniz 19 Ocak, saat 09:00 diye berillendi." << "\n";
            }
        }
    }
    showMenu();
}
void deleteIndex(int i)
{
    for (int j = i; j < num - 1; j++) {
        hast[j].name = hast[j + 1].name;
        hast[j].tcID = hast[j + 1].tcID;
        hast[j].sigorta = hast[j + 1].sigorta;
        hast[j].recete = hast[j + 1].recete;
        hast[j].telno = hast[j + 1].telno;
        hast[j].age = hast[j + 1].age;
        hast[j].a = hast[j + 1].a;
    }
    return;
}
void hastaSil()
{
    cout << "Silmek istediğiniz hastanın TC numarasını giriniz: ";

    int code;
    cin >> code;

    for (int i = 0; i < num; i++) {
        if (hast[i].tcID == code) {
            deleteIndex(i);
            num--;
            break;
        }
    }
    showMenu();
}
void hastaAra()
{
    cout << "Aramak istediğiniz hastanın TC numarasını giriniz: ";

    int code;
    cin >> code;

    for (int i = 0; i < num; i++) {

        if (hast[i].tcID == code) {
            cout << "Hastanin ismi: "
            << hast[i].name << "\n";

            cout << "Hastanin TC numarasi: "
            << hast[i].tcID << "\n";

            cout << "Hastanin telefon numarasi: "
            << hast[i].telno << "\n";

            cout << "Hastanin yasi: "
            << hast[i].age << "\n";

            cout << "Hastanin sigorta durumu: "
            << hast[i].sigorta << "\n";

            cout <<"Hastanın reçetesi: "
            << hast[i].recete << "\n";

            if (hast[i].a == 1){
                cout << hast[i].name << " isimli hastamızın nöroloji sıkıntıları vardır "
                                       "ve 100 tl tedavi ödemesi yapıldı." << "\n";
            }else if(hast[i].a == 2){
                cout << hast[i].name << " isimli hastamızın baş ağrıları sıkıntıları  vardır "
                                       "ve 200 tl tedavi ödemesi yapıldı." << "\n";
            }else if(hast[i].a == 3){
                cout << hast[i].name << " isimli hastamızın cilt sıkıntıları  vardır "
                                       "ve 300 tl tedavi ödemesi yapıldı." << "\n";
            }
            break;
        }
    }
    showMenu();
}
void showMenu()
{

    cout << "--------------------------------" << " C++ v14" << " ----------------------------------\n";

    cout << "Mevcut seçenekler:\n";
    cout << "Database oluştur  -> (1)\n";
    cout << "Doktor oturumu    -> (2)\n";
    cout << "Hasta kaydı sil   -> (3)\n";
    cout << "Hasta ara (TC)	  -> (4)\n";
    cout << "Exit			  -> (5)\n";

    int option;
    cin >> option;

    if (option == 1) {
        database();
    }
    else if (option == 2) {
        doctorPanel();
    }
    else if (option == 3) {
        hastaSil();
    }
    else if (option == 4) {
        hastaAra();
    }
    else if (option == 5) {
        return;
    }
    else {
        cout << "Mevcut fonksiyonlarımız 1/2/3/4/5";
        showMenu();
    }
}
int main(){
    showMenu();
    return 0;
}
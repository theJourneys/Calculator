/*
    Program: Calculator
    Amaç: Kullanıcıdan alınan iki sayı üzerinde çeşitli matematiksel işlemler yapabilmeye yarar.
    Özellikler: Toplama, çıkarma, çarpma, bölme ve üs alma işlemleri yapılabilir.
    Sürüm: 1.0.0
    Yazar: Burhan Arıkan
*/

#include <iostream>
#include <cmath> // pow() fonksiyonunu kullanabilmek için gerekli kütüphane.
using namespace std;

int main() {
    char choice; // Kullanıcının devam etmek isteyip istemediğini tutar.

    do {
        double number1, number2, result; // Sayılar ve sonucu saklamak için değişkenler.
        char operation; // Kullanıcının seçtiği işlem türünü saklamak için.

        // Kullanıcıdan birinci sayıyı alır.
        cout << "Birinci sayıyı girin: ";
        cin >> number1;

        // Kullanıcıdan ikinci sayıyı alır.
        cout << "İkinci sayıyı girin: ";
        cin >> number2;

        // Kullanıcıdan yapmak istediği işlemi ifade etmesini ister ve operation değişkenine atar.
        cout << "Yapmak istediğiniz işlemi seçin (+, -, *, /, ^): ";
        cin >> operation;

        // Kullanıcının seçimine göre işlem yapar.
        switch (operation) {
            case '+': // Toplama işlemi
                result = number1 + number2;
                break;
            case '-': // Çıkarma işlemi
                result = number1 - number2;
                break;
            case '*': // Çarpma işlemi
                result = number1 * number2;
                break;
            case '/': // Bölme işlemi
                if (number2 != 0) { // Sıfıra bölme kontrolü
                    result = number1 / number2;
                } else {
                    cout << "Hata: Sıfıra bölme yapılamaz!" << endl;
                    return 1; // 0'a bölmeye çalışma hatası durumunda programı sonlandırır.
                }
                break;
            case '^': // Üs alma işlemi
                result = pow(number1, number2); // pow() fonksiyonu ile üs alma
                break;
            default: // Geçersiz işlem
                cout << "Geçersiz işlem!" << endl;
                return 2; // Geçersiz işaret girilmesi durumunda programı sonlandırır.
        }

        // İşlem sonucunu ekrana yazdırır.
        cout << "Sonuç: " << result << endl;

        // Kullanıcıya devam etmek isteyip istemediğini sorar.
        cout << "Başka bir işlem yapmak ister misiniz? (Y/N): ";
        cin >> choice;

    } while (choice == 'Y' || choice == 'y'); // Kullanıcı 'Y' ya da 'y' girerse döngü devam eder.

    cout << "Hesap Makinesi'ni kullandığınız için teşekkürler! Hoşça kalın!" << endl;

    return 0; // Programı başarılı bir şekilde sonlandırır.
}

/*
C++ Açıklamaları:
switch (değişken adı) {
    case "değer1": -> kontrol durumu
        değişkenin değeri değer1'e eşitse çalıştırılacak kodlar;
        break; -> case gerçekleşirse switch bloğundan çıkmaya yarar.
    default:
        hiç bir case eşleşmezse çalışacak kodlar;
}
            yani switch - case akışı 
                belirli bir değişkenin (örneğin operation) farklı değerlerine göre farklı kod bloklarını çalıştırmaya yarar.

pow(number1, number2); -> cmath` kütüphanesinden gelen bir fonksiyondur. 
    Bir sayının (number1) belirli bir kuvvetini (number2) hesaplar.
*/

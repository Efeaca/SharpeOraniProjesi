#include <stdio.h>
#include <stdlib.h>

int main() {
    system("chcp 65001 > nul");
    
    double yatirim_getirisi;
    double risksiz_faiz_orani;
    double standart_sapma;
    double sharpe_orani;
    
    printf("--- Sharpe Oranı Hesaplama Programı ---\n\n");

    
    printf("Lütfen yatırımın getirisini yüzde (%) olarak girin : ");
    scanf("%lf", &yatirim_getirisi);

    
    printf("Lütfen risksiz faiz oranını yüzde (%) olarak girin : ");
    scanf("%lf", &risksiz_faiz_orani);

    
    printf("Lütfen yatırımın standart sapmasını yüzde (%) olarak girin : ");
    scanf("%lf", &standart_sapma);

    // Girdileri ondalık formata çevir
    yatirim_getirisi = yatirim_getirisi / 100.0;
    risksiz_faiz_orani = risksiz_faiz_orani / 100.0;
    standart_sapma = standart_sapma / 100.0;

    
    // Standart sapmanın 0 olup olmadığını kontrol et
    if (standart_sapma == 0) {
        printf("\n HATA: Standart sapma 0 olamaz. Hesaplama yapılamıyor.\n");
    } else {
        
        sharpe_orani = (yatirim_getirisi - risksiz_faiz_orani) / standart_sapma;

        // Sonucu ekrana yazdır
        printf("\n------ SONUÇLAR ------\n");
        printf("Hesaplanan Sharpe Oranı: %.2f\n", sharpe_orani);

        // Sonucu yorumla
        if (sharpe_orani >= 3.0) {
            printf("YORUM: Mükemmel! Aldığınız her birim riske karşılık çok üstün bir getiri elde ediyorsunuz.\n");
        } else if (sharpe_orani >= 2.0) {
            printf("YORUM: Çok İyi! Risk-getiri dengesi oldukça başarılı.\n");
        } else if (sharpe_orani >= 1.0) {
            printf("YORUM: İyi. Yatırım, aldığı riske değecek bir getiri sağlıyor.\n");
        } else {
            printf("YORUM: Yetersiz. Yatırımın performansı, aldığı riske göre düşük kalıyor.\n");
        }
    }

    return 0; // Programın başarıyla bittiğini bildir
}
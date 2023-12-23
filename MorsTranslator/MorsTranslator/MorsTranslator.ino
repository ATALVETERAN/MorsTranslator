/* 
 *  Bu kodlar teensy 4.0 ve teensy 4.1 kartları için yazılmıştır.
 *  Arduino Uno ilede çalışır ama Ledin pinleri doğru bağlanmalıdır.
 *  Ve ona göre ayarlanmalıdır.
 *  Noktalar 0, Çizgiler 1 dir.
 *  Ledin uzun bacağı artı(+), kısa bacağı eksidir(-).
 *  Artı bacağı belirlenen pine bağlanırken eksi bacak Gndye bağlanır.
 *  Uyarı: Port adını exe dosyasına doğru giriniz.
*/
// Altdaki diziye alfabedeki harfleri ve rakamları ekledim
String alfabe[] = {"a", "b", "c", "ç", "d", "e", "f", "g","ğ", "h", "i", "ı", "j", "k", "l", "m","n","o", "ö", "p", "r", "s", "ş","t", "u", "ü","v", "y", "z", "q", "w", "x","1", "2", "3", "4", "5", "6", "7", "8","9", "0"};
// Altdaki diziye yukarıdaki tanımlanan değerlerin mors alfabesine karşılığını yazdım
String mors10[] = {"01", "1000", "1010", "1001", "100", "0", "0010", "110","1110", "0000", "0011", "00", "0111", "101", "0100", "11","10","111", "1101", "0110", "010", "000", "00100","1", "001", "0001","00001", "0101", "1100", "1011", "011", "1001","01111", "00111", "00011", "00001", "00000", "10000", "11000", "11100","11110", "11111"};
#define Led 13 // Burada ledin artı olan bacağına bağladığım pini ayarladım
void setup() {
  // gerekli ayarlar
  Serial.begin(9600);
  pinMode(Led, OUTPUT);
}

void loop() {
  if (Serial.available() > 0){ // input alınacak degerin gelip gelmediğini kontrol eder 
      String deger = Serial.readStringUntil('\n'); // gelen veriyi string olarak deger değişkenine atar
      int uzunluk1 = deger.length(); // deger değişkeninin uzunluğunu uzunluk1 değişkenine atar
      for (int i = 0; i < uzunluk1; i++){ // burası deger değişkeninin içindekini harf harf almak için
        if(deger[i] != ' '){ // eğer boşluk varsa atliyor işlem yapılmıyor
          String harf = deger[i]; // harfleri teker teker harf değişkenine atıyor
          for (int x = 0; x < 42; x++){ 
            if (harf == alfabe[x]){// harf değişkenindeki harf alfabe dizisinde bulunuyor
              String mors_harf = mors10[x]; // alfabe dizisinde denk gelen harfe denk gelen mors karşılığı bulunuyor ve değişkene ataniyor
              int uzunluk2 = mors_harf.length();// denk gelen harfin mors alfabesinin uzunluğu değişkene ataniyor
              for (int y = 0; y < uzunluk2; y++){
                if(mors_harf[y] == '0'){ // harfin mors hali harflere parçalanır ve 0 karakterine eşitse bu blok çalışır
                  digitalWrite(Led, HIGH);
                  delay(200);// lambanın yanık durma süresi
                  digitalWrite(Led,LOW);
                  delay(200);
                }
                else{ // if bloğu çalışmazsa bu blok çalışacak
                  digitalWrite(Led, HIGH);
                  delay(800);// lambanın yanık durma süresi
                  digitalWrite(Led,LOW);
                  delay(800);
                }  
              }
            }
          }
        }
      }
    }
}

#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <DHT.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
#define DHTPIN 16
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

//Seting Jaringan.
const char* ssid = "Redmi6";
const char* password = "DM0987654321";
const char* host = "192.168.43.60"; //Alamat IP server

//Deklarasi variabel sensor
float temp;
float hum;
int ldr;
// driver motor L298N
#define IN1 3 // deklarasi pin IN1
#define IN2 1  // deklarasi pin IN2

#define IN3 0  // deklarasi pin IN3
#define IN4 2  // deklarasi pin IN4

#define IN5 10
#define IN6 13

#define pwm_kipas 14 // deklarasi pin ENA
#define pwm_led 12  // deklarasi pin ENB
#define pwm_mistmaker 15 //


//Icon di arduino
byte termometru[8] = //icon for termometer
{
 B00100,
 B01010,
 B01010,
 B01110,
 B01110,
 B11111,
 B11111,
 B01110
};

byte picatura[8] = //icon for water droplet
{
 B00100,
 B00100,
 B01010,
 B01010,
 B10001,
 B10001,
 B10001,
 B01110,
};

byte light[8] = //icon for cahaya
{
  B00100,
  B01010,
  B01010,
  B10001,
  B10001,
  B01010,
  B01010,
  B00100,
};


//variabel fuzzy
float miu_suhu_1,miu_suhu_2,miu_suhu_3;
float miu_lembap_1,miu_lembap_2,miu_lembap_3;
float miu_cahaya_1,miu_cahaya_2,miu_cahaya_3;
float a, b, c;
float z1,z2,z3,z4,z5,z6,z7,z8,z9,z10,z11,z12,z13,z14,z15,z16,z17,z18,z19,
      z20,z21,z22,z23,z24,z25,z26,z27,z28,z29,z30,z31,z32,z33,z34,z35,z36,
      z37,z38,z39,z40,z41,z42,z43,z44,z45,z46,z47,z48,z49,z50,z51,z52,z53,z54;

float p1,p2,p3,p4,p5,p6,p7,p8,p9,p10,p11,p12,p13,p14,p15,p16,p17,p18,p19,
      p20,p21,p22,p23,p24,p25,p26,p27,p28,p29,p30,p31,p32,p33,p34,p35,p36,
      p37,p38,p39,p40,p41,p42,p43,p44,p45,p46,p47,p48,p49,p50,p51,p52,p53,p54;

float d_suhu;
float d_lembap;
float d_cahaya;



void setup() {
  // put your setup code here, to run once: 
//Serial.begin(115200);
lcd.begin();
dht.begin();

  //Driver Motor L298N
pinMode(IN1, OUTPUT); 
pinMode(IN2, OUTPUT);
pinMode(IN3, OUTPUT);
pinMode(IN4, OUTPUT);
pinMode(pwm_kipas, OUTPUT);
pinMode(pwm_led, OUTPUT);

pinMode(IN5, OUTPUT);
pinMode(IN6, OUTPUT);
pinMode(pwm_mistmaker, OUTPUT);


Serial.begin(115200);
//Setting koneksi Wifi 
WiFi.hostname("NodeMCU");
//Mulai Start Koneksi Wifi dengan memasukan sssid dan password
WiFi.begin(ssid, password);

//Cek Koneksi Wifi
//Selama wifi status konek wifinya tidak terkoneksi  
while(WiFi.status() != WL_CONNECTED)
{
  //led Mati
//  digitalWrite(PIN_LED,LOW);
  //NodeMcu terus mencoba koneksi 
  Serial.print(".");
  delay(500);
  }
  //Apabila berhasil terkoneksi
//  digitalWrite(PIN_LED, HIGH);
  //Tampilkan pesan di serial Wifi connected
  Serial.println("\nWifi Connected");
}

void loop() {
  // put your main code here, to run repeatedly:
getSensorData(); //membaca data input sensor   
tampilLcd(); //Menampilkan pada LCD
fuzzifikasi();
basis_rule();
inferensi(); 
defuzifikasi();
pwm();
}

//
void pwm(){
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  digitalWrite(IN5, HIGH);
  digitalWrite(IN6, LOW);
}


void getSensorData(){
  temp = dht.readTemperature();
  hum = dht.readHumidity();
  ldr = analogRead(A0);
  
Serial.println("\nNILAI SISTEM KUMBUNG JAMUR MERANG");   
Serial.print("Suhu = ");   
Serial.print(temp);   
Serial.println("°C");   
Serial.print("Kelembapan = ");   
Serial.print(hum);   
Serial.print("%");
Serial.print("\nCahaya = ");
Serial.print(ldr);
Serial.print("Lux");
Serial.println("\nHasil akhir Defuzifikasi Suhu :");
Serial.print(d_suhu);
Serial.println("\nHasil akhir Defuzifikasi Kelembapan :");
Serial.print(d_lembap);
Serial.println("\nHasil akhir Defuzifikasi Cahaya :");
Serial.print(d_cahaya);
//delay(2000);  

//  //process cek Koneksi ke server 
  WiFiClient client;
  //Jika Clinet tidak terkoneksi konek ke host
  if(!client.connect(host, 80))
  {
    Serial.println("\nConnect Failed");
    //Ulang kembali dari awal 
    return;
    }

  //Prosess Pengiriman data ke server 
  String Link;
  HTTPClient http;
  //saat mengeksekusi kirimdata.php maka dia mengirim nilai sensornya ke variabel sensornya
//Link = "http://192.168.43.60/IoT_Kumbung_Jamur/arduino/write.php?suhu=" + String(temp) + "&kelembapan=" + String(hum) + "&cahaya=" + String(ldr) + "&suhu_d=" + String(d_suhu) + "&kelembapan_d=" + String(d_lembap) + "&cahaya_d=" + String(d_cahaya);
Link = "http://" + String(host) + "/arduino/write.php?suhu=" + String(temp) + "&kelembapan=" + String(hum) + "&cahaya=" + String(ldr) + "&suhu_d=" + String(d_suhu) + "&kelembapan_d=" + String(d_lembap) + "&cahaya_d=" + String(d_cahaya);
  //Eksekusi Link
  http.begin(Link);
  //Mode Get
  http.GET();
  http.end();
       
  delay(2000);
}

void fuzzifikasi(){
  //suhu
  suhu_m(15,23,30);
  suhu_m(25,33,40);
  suhu_m(35,43,50);
  
  //kelembapan
  lembap_m(50,65,80);
  lembap_m(70,85,100);
  lembap_m(90,105,120);
  
  //cahaya
  cahaya_m(15,35,100);
  cahaya_m(50,200,350);
  cahaya_m(300,375,450);
}

  //rumus miu suhu
void suhu_m(float a, float b, float c){
    if ((temp >=a) && (temp <= b))
    {
     miu_suhu_1 = (temp - a)/(b-a);
    }
    if ((temp >=b) && (temp <= c))
    {
     miu_suhu_2 = (c - temp)/(c-b);
    }
    if ((temp < a) || (temp > c))
    {
     miu_suhu_3 = 0;
    }

}

  //rumus miu kelembapan
void lembap_m(float a, float b, float c){
    if ((hum >=a) && (hum <= b))
    {
     miu_lembap_1 = (hum - a)/(b-a);
    }
    if ((hum >=b) && (hum <= c))
    {
     miu_lembap_2 = (c - hum)/(c-b);
    }
    if ((hum < a) || (hum > c))
    {
     miu_lembap_3 = 0;
    }
}

 //rumus miu cahaya
void cahaya_m(float a, float b, float c){
    if ((ldr >=a) && (ldr <= b))
    {
     miu_cahaya_1 = (ldr - a)/(b-a);
    }
    if ((ldr >=b) && (ldr <= c))
    {
     miu_cahaya_2 = (c - ldr)/(c-b);
    }
    if ((ldr < a) || (ldr > c))
    {
     miu_cahaya_3 = 0;
    }
}


// 
void basis_rule(){
// suhu
  if (miu_suhu_1 < miu_lembap_1 < miu_cahaya_1){
p1 = miu_suhu_1;
}
if (miu_suhu_1 < miu_lembap_2 > miu_cahaya_1){
p2 = miu_suhu_1;
}
if (miu_suhu_1 < miu_lembap_3 > miu_cahaya_1){
p3 = miu_suhu_1;
}
if (miu_suhu_1 < miu_lembap_1 < miu_cahaya_2){
p4 = miu_suhu_1;
}
if (miu_suhu_1 < miu_lembap_2 < miu_cahaya_2){
p5 = miu_suhu_1;
}
if (miu_suhu_1 < miu_lembap_3 > miu_cahaya_2){
p6 = miu_suhu_1;
}
if (miu_suhu_1 < miu_lembap_1 < miu_cahaya_3){
p7 = miu_suhu_1;
}
if (miu_suhu_1 < miu_lembap_2 < miu_cahaya_3){
p8 = miu_suhu_1;
}
if (miu_suhu_1 < miu_lembap_3 < miu_cahaya_3){
p9 = miu_suhu_1;
}

if (miu_suhu_2 < miu_lembap_1 < miu_cahaya_1){
p10 = miu_suhu_2;
}
if (miu_suhu_2 < miu_lembap_2 > miu_cahaya_1){
p11 = miu_suhu_2;
}
if (miu_suhu_2 < miu_lembap_3 > miu_cahaya_1){
p12 = miu_suhu_2;
}
if (miu_suhu_2 < miu_lembap_1 < miu_cahaya_2){
p13 = miu_suhu_2;
}
if (miu_suhu_2 < miu_lembap_2 < miu_cahaya_2){
p14 = miu_suhu_2;
}
if (miu_suhu_2 < miu_lembap_3 > miu_cahaya_2){
p15 = miu_suhu_2;
}
if (miu_suhu_2 < miu_lembap_1 < miu_cahaya_3){
p16 = miu_suhu_2;
}
if (miu_suhu_2 < miu_lembap_2 < miu_cahaya_3){
p17 = miu_suhu_2;
}
if (miu_suhu_2 < miu_lembap_3 < miu_cahaya_3){
p18 = miu_suhu_2;
}


// Kelembapan
if (miu_lembap_1 < miu_suhu_1 < miu_cahaya_1){
p19 = miu_lembap_1;
}
if (miu_lembap_1 < miu_suhu_2 > miu_cahaya_1){
p20 = miu_lembap_1;
}
if (miu_lembap_1 < miu_suhu_3 > miu_cahaya_1){
p21 = miu_lembap_1;
}
if (miu_lembap_1 < miu_suhu_1 < miu_cahaya_2){
p22 = miu_lembap_1;
}
if (miu_lembap_1 < miu_suhu_2 < miu_cahaya_2){
p23 = miu_lembap_1;
}
if (miu_lembap_1 < miu_suhu_3 > miu_cahaya_2){
p24 = miu_lembap_1;
}
if (miu_lembap_1 < miu_suhu_1 < miu_cahaya_3){
p25 = miu_lembap_1;
}
if (miu_lembap_1 < miu_suhu_2 < miu_cahaya_3){
p26 = miu_lembap_1;
}
if (miu_lembap_1 < miu_suhu_3 < miu_cahaya_3){
p27 = miu_lembap_1;
}

if (miu_lembap_2 < miu_suhu_1 < miu_cahaya_1){
p28 = miu_lembap_2;
}
if (miu_lembap_2 < miu_suhu_2 > miu_cahaya_1){
p29 = miu_lembap_2;
}
if (miu_lembap_2 < miu_suhu_3 > miu_cahaya_1){
p30 = miu_lembap_2;
}
if (miu_lembap_2 < miu_suhu_1 < miu_cahaya_2){
p31 = miu_lembap_2;
}
if (miu_lembap_2 < miu_suhu_2 < miu_cahaya_2){
p32 = miu_lembap_2;
}
if (miu_lembap_2 < miu_suhu_3 > miu_cahaya_2){
p33 = miu_lembap_2;
}
if (miu_lembap_2 < miu_suhu_1 < miu_cahaya_3){
p34 = miu_lembap_2;
}
if (miu_lembap_2 < miu_suhu_2 < miu_cahaya_3){
p35 = miu_lembap_2;
}
if (miu_lembap_2 < miu_suhu_3 < miu_cahaya_3){
p36 = miu_lembap_2;
}



//Cahaya
if (miu_cahaya_1 < miu_suhu_1 < miu_lembap_1){
p37 = miu_cahaya_1;
}
if (miu_cahaya_1 < miu_suhu_2 > miu_lembap_1){
p38 = miu_cahaya_1;
}
if (miu_cahaya_1 < miu_suhu_3 > miu_lembap_1){
p39 = miu_cahaya_1;
}
if (miu_cahaya_1 < miu_suhu_1 < miu_lembap_2){
p40 = miu_cahaya_1;
}
if (miu_cahaya_1 < miu_suhu_2 < miu_lembap_2){
p41 = miu_cahaya_1;
}
if (miu_cahaya_1 < miu_suhu_3 > miu_lembap_2){
p42 = miu_cahaya_1;
}
if (miu_cahaya_1 < miu_suhu_1 < miu_lembap_3){
p43 = miu_cahaya_1;
}
if (miu_cahaya_1 < miu_suhu_2 < miu_lembap_3){
p44 = miu_cahaya_1;
}
if (miu_cahaya_1 < miu_suhu_3 < miu_lembap_3){
p45 = miu_cahaya_1;
}

if (miu_cahaya_2 < miu_suhu_1 < miu_lembap_1){
p46 = miu_cahaya_2;
}
if (miu_cahaya_2 < miu_suhu_2 > miu_lembap_1){
p47 = miu_cahaya_2;
}
if (miu_cahaya_2 < miu_suhu_3 > miu_lembap_1){
p48 = miu_cahaya_2;
}
if (miu_cahaya_2 < miu_suhu_1 < miu_lembap_2){
p49 = miu_cahaya_2;
}
if (miu_cahaya_2 < miu_suhu_2 < miu_lembap_2){
p50 = miu_cahaya_2;
}
if (miu_cahaya_2 < miu_suhu_3 > miu_lembap_2){
p51 = miu_cahaya_2;
}
if (miu_cahaya_2 < miu_suhu_1 < miu_lembap_3){
p52 = miu_cahaya_2;
}
if (miu_cahaya_2 < miu_suhu_2 < miu_lembap_3){
p53 = miu_cahaya_2;
}
if (miu_cahaya_2 < miu_suhu_3 < miu_lembap_3){
p54 = miu_cahaya_2;
}
  
}

void inferensi(){
//suhu
z1 = 1023 - (1023 * p1);
z2 = 1023 - (1023 * p2);
z3 = 1023 - (1023 * p3);
z4 = 1023 - (1023 * p4);
z5 = 1023 - (1023 * p5);
z6 = 1023 - (1023 * p6);
z7 = 1023 - (1023 * p7);
z8 = 1023 - (1023 * p8);
z9 = 1023 - (1023 * p9);

z10 = 0 + (1023 * p10);
z11 = 0 + (1023 * p11);
z12 = 0 + (1023 * p12);
z13 = 0 + (1023 * p13);
z14 = 0 + (1023 * p14);
z15 = 0 + (1023 * p15);
z16 = 0 + (1023 * p16);
z17 = 0 + (1023 * p17);
z18 = 0 + (1023 * p18);




//kelembapan
z19 = 0 + (1023 * p19);
z20 = 0 + (1023 * p20);
z21 = 0 + (1023 * p21);
z22 = 0 + (1023 * p22);
z23 = 0 + (1023 * p23);
z24 = 0 + (1023 * p24);
z25 = 0 + (1023 * p25);
z26 = 0 + (1023 * p26);
z27 = 0 + (1023 * p27);

z28 = 1023 - (1023 * p28);
z29 = 1023 - (1023 * p29);
z30 = 1023 - (1023 * p30);
z31 = 1023 - (1023 * p31);
z32 = 1023 - (1023 * p32);
z33 = 1023 - (1023 * p33);
z34 = 1023 - (1023 * p34);
z35 = 1023 - (1023 * p35);
z36 = 1023 - (1023 * p36);


//cahaya
z37 = 0 + (1023 * p37);
z38 = 0 + (1023 * p38);
z39 = 0 + (1023 * p39);
z40 = 0 + (1023 * p40);
z41 = 0 + (1023 * p41);
z42 = 0 + (1023 * p42);
z43 = 0 + (1023 * p43);
z44 = 0 + (1023 * p44);
z45 = 0 + (1023 * p45);

z46 = 1023 - (1023 * p46);
z47 = 1023 - (1023 * p47);
z48 = 1023 - (1023 * p48);
z49 = 1023 - (1023 * p49);
z50 = 1023 - (1023 * p50);
z51 = 1023 - (1023 * p51);
z52 = 1023 - (1023 * p52);
z53 = 1023 - (1023 * p53);
z54 = 1023 - (1023 * p54);

}
 

void defuzifikasi(){
  d_suhu = (p1 * z1 + p2 * z2 + p3 * z3 + p4 * z4 + p5 * z5 + p6 * z6 + p7 * z7 + p8 * z8 + p9 * z9 +
     p10 * z10 + p11 * z11 + p12 * z12 + p13 * z13 + p14 * z14 + p15 * z15 + p16 * z16 + p17 * z17 + p18 * z18)
/(p1 + p2 + p3 + p4 + p5 + p6 + p7 + p8 + p9 + p10 + p11 + p12 + p13 + p14 + p15 + p16 + p17 + p18);

analogWrite (pwm_kipas, d_suhu);


d_lembap = (p19 * z19 + p20 * z20 + p21 * z21 + p22 * z22 + p23 * z23 + p24 * z24 + p25 * z25 + p26 * z26 + p27 * z27 +
           p28 * z28 + p29 * z29 + p30 * z30 + p31 * z31 + p32 * z32 + p33 * z33 + p34 * z34 + p35 * z35 + p36 * z36)
          /(p19 + p20 + p21 + p22 + p23 + p24 + p25 + p26 + p27 + p28 + p29 + p30 + p31 + p32 + p33 + p34 + p35 + p36);

//analogWrite (pwm_mistmaker, d_lembap);
digitalWrite (pwm_mistmaker, HIGH);


d_cahaya = (p37 * z37 + p38 * z38 + p39 * z39 + p40 * z40 + p41 * z41 + p42 * z42 + p43 * z43 + p44 * z44 + p45 * z45 +
           p46 * z46 + p47 * z47 + p48 * z48 + p49 * z49 + p50 * z50 + p51 * z51 + p52 * z52 + p53 * z53 + p54 * z54)
          /(p37 + p38 + p39 + p40 + p41 + p42 + p43 + p44 + p45 + p46 + p47 + p48 + p49 + p50 + p51 + p52 + p53 + p54);

analogWrite (pwm_led, d_cahaya);

}

void tampilLcd(){
lcd.createChar(1, termometru); 
lcd.createChar(2, picatura);
lcd.createChar(3, light);

lcd.clear();
delay(1000);
 
         
lcd.setCursor (0, 0);   
lcd.write(1);   
lcd.setCursor(1,0);   
lcd.print(":");   
lcd.setCursor(2,0);   
lcd.print(temp);      
lcd.print("C"); 
lcd.setCursor (0,1);
  lcd.print("FIS: ");
  lcd.setCursor(4,1);
  lcd.print(d_suhu);
delay(2000);

lcd.clear();
delay(1000);
  
lcd.setCursor (0, 0);   
lcd.write(2);   
lcd.setCursor(1,0);   
lcd.print(":");   
lcd.setCursor(2,0);   
lcd.print(hum);   
lcd.print("%"); 
lcd.setCursor (0,1);
  lcd.print("FIS: ");
  lcd.setCursor(4,1);
  lcd.print(d_lembap);
delay(2000);

lcd.clear();
delay(1000);
  
lcd.setCursor (0, 0);   
lcd.write(3);   
lcd.setCursor(1,0);   
lcd.print(":");   
lcd.setCursor(2,0);   
lcd.print(ldr);   
lcd.print("Lux"); 
lcd.setCursor (0,1);
  lcd.print("FIS: ");
  lcd.setCursor(4,1);
  lcd.print(d_cahaya);  
delay(2000);
}

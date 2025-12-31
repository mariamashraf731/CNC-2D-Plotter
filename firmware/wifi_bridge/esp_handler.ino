//#include <ESP8266WebServer.h>
//#include <ESP8266WiFi.h>  
#include <ESP8266WiFi.h> 
#include <string.h>               
#include <FirebaseArduino.h>      
#define FIREBASE_HOST "icu-monitor-a5719-default-rtdb.firebaseio.com"      
#define FIREBASE_AUTH "Fld8iF6gLwkNdSZGf98PqEEDHYtrjXld5ikCMsDO"  




const char* WIFI_SSID = "STUDBME2";
const char* WIFI_PASSWORD = "BME2Stud";
int n; 

//ESP8266WebServer server(80);

//    void square_handler() {
//                          Serial.print('0');
////                          server.send(200, "text/plain","ok");
//                      }z
//                      
//    void triangle_handler() {
//                          Serial.print('1');
////                          server.send(200, "text/plain","ok");
//                      }
//
//    void H_handler() {
//                          Serial.print('2');
////                          server.send(200, "text/plain","ok");
//                      }
void setup() {
  Serial.begin(9600);           
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);                                  
//  Serial.print("Connecting to ");
//  Serial.print(WIFI_SSID);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
 
//  Serial.println();
//  Serial.print("Connected");
//  Serial.print("IP Address: ");
//  Serial.println(WiFi.localIP());                               //prints local IP address
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);                 // connect to the firebase
  
  }
 
void loop() {
  delay(1000);
  n=Firebase.getInt("label/shape");
  if (Firebase.failed()) 
    {
      Serial.print("pushing /logs failed:");
      Serial.println(Firebase.error()); 
  }
  Serial.print(n); 
  if (n==0) {  
      Serial.print('0');
  }  
   else if (n==1){  
   Serial.print('1');
 }
    else if ((n == 2)){  
   Serial.print('2');
 } 
// else if (n==3){  
//   Serial.print('0');
// } 
//  delay(2000);
}

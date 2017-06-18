#include <SoftwareSerial.h>
#include <DHT.h>

SoftwareSerial BTSerial(2, 3);
DHT dht (9, DHT11);
int bufferPosition;
int relay1 = 4;
int relay2 = 5;
int relay3 = 6;
int relay4 = 7;
char relay1state = 0;
char relay2state = 0;
char relay3state = 0;
char relay4state = 0;

  
void setup() {
  Serial.begin(9600);
  BTSerial.begin(9600);
  bufferPosition = 0;
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(relay3, OUTPUT);
  pinMode(relay4, OUTPUT);
}

void loop() {
  int err;
  float humi = dht.readHumidity();
  float tem = dht.readTemperature();
//  if(isnan(humi) || isnan(tem)){
//    String errMsg;
//    errMsg = "Error No : " + err + "\n";
//  }
    String dht11msg;
    dht11msg = humi;
    dht11msg += ";";
    dht11msg += tem;
//    dht11msg = " humi : ";
//    dht11msg += humi;
//    dht11msg += " % ";
//    dht11msg += "temp : ";
//    dht11msg += tem;
//    dht11msg += " 'C ";
    char msg[dht11msg.length()];
    dht11msg.toCharArray(msg, dht11msg.length());
    
  if (BTSerial.available()) {
    byte command = BTSerial.read();
    switch(command){
     case '1':
      digitalWrite(relay1, LOW);
      break;
    case '2':
      digitalWrite(relay1, HIGH);
      break;
    case '3':
      digitalWrite(relay2, LOW);
      break;
    case '4': 
      digitalWrite(relay2, HIGH);
      break;
    case '5':
      digitalWrite(relay3, LOW);
      break;
    case '6':
      digitalWrite(relay3, HIGH);
      break;
    case '7':
      digitalWrite(relay4, LOW);
      break;
    case '8':
      digitalWrite(relay4, HIGH);
      break;
    case '0':
      BTSerial.write(msg);
      break;  
  }
  }
}

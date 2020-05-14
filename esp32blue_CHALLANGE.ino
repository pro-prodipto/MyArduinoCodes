/*Program to control LED (ON/OFF) from ESP32 using Serial Bluetooth
 * Thanks to Neil Kolbans for his efoorts in adding the support to Arduino IDE
 * Turotial on: www.circuitdigest.com 
 */
#include "BluetoothSerial.h" //Header File for Serial Bluetooth, will be added by default into Arduino

BluetoothSerial ESP_BT; //Object for the Bluetooth

int incoming;  //integer to store the bluetooth input..
int LED_BUILTIN = 2;

void setup() 
{
  //Serial.begin(115200); //S

  pinMode (LED_BUILTIN, OUTPUT);//Specify that LED pin is output  
  Serial.begin(115200); //at the default baud
  ESP_BT.begin("Mrittika 🤗"); //Bluetooth device name
 
  Serial.print("\nWAIT");
  for(int i=1;i<=5;i+=1)
  {
    digitalWrite(LED_BUILTIN,HIGH);
    Serial.print(".");
    delay(50);
    digitalWrite(LED_BUILTIN,LOW);
    delay(100);
  }
  
  digitalWrite(LED_BUILTIN,HIGH);
  delay(500);
  digitalWrite(LED_BUILTIN,LOW);
  Serial.println("\nThe device has started, now you can pair it with Bluetooth..!!");

}

void loop() 
{
  
  if (ESP_BT.available()) //Check if we receive anything from Bluetooth
  {
    incoming = ESP_BT.read(); //Read what we receive 
    Serial.print("Received: "); 
    Serial.println(incoming);
    
    if (incoming == 49)
        {
        digitalWrite(LED_BUILTIN, HIGH);
        ESP_BT.println("LED turned ON");      
        }
        
    if (incoming == 48)
        {
        digitalWrite(LED_BUILTIN, LOW);
        ESP_BT.println("LED turned OFF");
        }     
  }
  
  delay(20); 
  
}

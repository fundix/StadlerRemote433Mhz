// wifi knihovny
#include <WiFiManager.h>

//RC 433MHz
#include <RCSwitch.h>

//casovace
#include <RBD_Timer.h>

//MQTT
#include <MQTTClient.h>

//hum temp
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>



void sendCommand(RCSwitch sender, int cmd);
void sendHumidity(RCSwitch sender, unsigned int hum);


void setup() {

  #ifdef DEBUG
    Serial.begin(74880);
    delay(100);
    Serial.println("Starting setup...");
  #endif

  dht.begin();
  
  // Transmitter is connected to Arduino Pin #10  
  mySwitch.enableTransmit(D1);
  
  // Optional set protocol (default is 1, will work for most outlets)
   mySwitch.setProtocol(1);

  // Optional set pulse length.
   mySwitch.setPulseLength(500);
  
  // Optional set number of transmission repetitions.
   mySwitch.setRepeatTransmit(3);

   SerialReadBuffer.reserve(8);


   timmer_sendhum.setTimeout(timme_hum);
   timmer_sendhum.restart();

  #ifdef DEBUG
   Serial.println("Setup ended");
  #endif
  
}


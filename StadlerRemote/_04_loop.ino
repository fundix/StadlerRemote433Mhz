
void loop() {

  

  while (Serial.available()) {                  // If Arduino's computer rx buffer has data
    SerialByteIn = Serial.read();               // Store each character in byteIn
    SerialReadBuffer += char(SerialByteIn);     // Write each character of byteIn to SerialReadBuffer
    if (SerialByteIn == '\n') {                 // Check to see if at the end of the line
      SerialEnd = true;                         // Set SerialEnd flag to indicate end of line
    }
  }

//      char charBuf[SerialReadBuffer.length() + 1];
//      SerialReadBuffer.toCharArray(charBuf, SerialReadBuffer.length());


   if (SerialEnd) { 

    Serial.println(SerialReadBuffer);

    if(SerialReadBuffer.toInt() == 1) {//on off
      sendCommand(mySwitch, 0);
    }
    else if(SerialReadBuffer.toInt() == 9) {//warm
      sendCommand(mySwitch, 3);
    }
     
    else if(SerialReadBuffer.toInt() == 2) {//40%
      sendHumidity(mySwitch, 40);
    }
    else if(SerialReadBuffer.toInt() == 3) { 
      sendHumidity(mySwitch, 45);
    }  
    else if(SerialReadBuffer.toInt() == 4) { 
      sendHumidity(mySwitch, 46);
    }
    
    else if(SerialReadBuffer.toInt() == 5) {
      sendHumidity(mySwitch, 51);
    }
    else if(SerialReadBuffer.toInt() == 6) {
      sendHumidity(mySwitch, 79);
    }
    else if(SerialReadBuffer.toInt() == 7) { //79
      sendHumidity(mySwitch, 10);
    }
    else if(SerialReadBuffer.toInt() == 8) { //78
      sendHumidity(mySwitch, 80);
    }    
    
    
    
    
    Serial.println("sent");
     
    SerialReadBuffer = "";                      // Clear SerialReadBuffer
    SerialEnd = false;  
//    
   }


  if (timmer_sendhum.onRestart()) {
    if(DHT_load()) {
//      Serial.print("sending: ");
//      Serial.println(humidity);
      sendHumidity(mySwitch, round(humidity));
    }
      
  }

}

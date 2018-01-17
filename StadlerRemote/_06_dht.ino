bool DHT_load() {
  
  sensors_event_t event;
  
  dht.temperature().getEvent(&event);


  
  if (isnan(event.temperature)) {
    
    #ifdef DEBUG
      Serial.println("Error reading temperature!");
    #endif

    return false;
  }
  else {
    temperature = event.temperature;

//    #ifdef DEBUG
//      Serial.print("Temperature: ");
//      Serial.print(temperature);
//      Serial.println(" *C");
//    #endif
    

//    if(client.publish(topic_temp, (String) temperature)) {
//      #ifdef DEBUG
//        Serial.println("MQTT: temp send");
//      #endif
//    }
//    else {
//      #ifdef DEBUG
//        Serial.println("MQTT: temp failed send");
//      #endif
//    }
  }

  // Get humidity event and print its value.
  dht.humidity().getEvent(&event);
  if (isnan(event.relative_humidity)) {

    #ifdef DEBUG
      Serial.println("Error reading humidity!");
    #endif

    return false;
  }
  else {
    
    humidity = event.relative_humidity;

    #ifdef DEBUG
      Serial.print("Humidity: ");
      Serial.print(humidity);
      Serial.println("%");
    #endif


//    if(client.publish(topic_hum, (String) humidity)) {
//      #ifdef DEBUG
//        Serial.println("MQTT: hum send");
//      #endif
//    }
//    
//    else {
//      #ifdef DEBUG
//        Serial.println("MQTT: hum failed send");
//      #endif
//    }
  }

  return true;
}


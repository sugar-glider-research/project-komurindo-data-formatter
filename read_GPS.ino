SIGNAL(TIMER0_COMPA_vect) {
  char c = GPS.read();
  #ifdef UDR0
    if (GPSECHO)
      if (c) UDR0 = c;  
      // writing direct to UDR0 is much much faster than Serial.print 
      // but only one character can be written at a time. 
  #endif
}

void useInterrupt(boolean v) {
  if (v) {
    OCR0A = 0xAF;
    TIMSK0 |= _BV(OCIE0A);
    usingInterrupt = true;
  } else {
    TIMSK0 &= ~_BV(OCIE0A);
    usingInterrupt = false;
  }
}

void gps_track(){
  if (! usingInterrupt) {
    char c = GPS.read();
    if (GPSECHO)
      if (c) Serial.print(c);
  }
  
  if (GPS.newNMEAreceived()) {
    if (!GPS.parse(GPS.lastNMEA()))
      return;  // we can fail to parse a sentence in which case we should just wait for another
  }

  if (timer > millis())  timer = millis();
  
  if (millis() - timer > 2000) { 
    timer = millis();
    if (GPS.fix) {
      //GPS.longitudeDegrees = 112.614510;
      //GPS.latitudeDegrees = -7.954625;
      //GPS.altitude = 1;
      //Serial.print("Location (in degrees, works with Google Maps): ");
      Serial.println(GPS.latitudeDegrees, 8);
      //Serial.print(", "); 
      Serial.println(GPS.longitudeDegrees, 8);
      //Serial.print("Altitude: "); 
      Serial.println(GPS.altitude);
      //Serial.print("Satellites: "); Serial.println((int)GPS.satellites);

      //lat[0] = abs(int(GPS.latitudeDegrees));
      //Serial.print(lat[0]); Serial.print(" ");
      lat[0] = abs(int((GPS.latitudeDegrees - int(GPS.latitudeDegrees)) * 60));
      Serial.print(lat[0]); Serial.print(" ");
      lat[1] = abs(int((
                  ((GPS.latitudeDegrees - int(GPS.latitudeDegrees)) * 60) 
                  - 
                  int((GPS.latitudeDegrees - int(GPS.latitudeDegrees)) * 60)) 
                  * 60));
      Serial.print(lat[1]); Serial.print(" ");
      lat[2] = abs(int((((((GPS.latitudeDegrees - int(GPS.latitudeDegrees)) * 60) - 
                  int((GPS.latitudeDegrees - int(GPS.latitudeDegrees)) * 60)) * 60)
                  - 
                  int((((GPS.latitudeDegrees - int(GPS.latitudeDegrees)) * 60) - 
                  int((GPS.latitudeDegrees - int(GPS.latitudeDegrees)) * 60)) * 60)) 
                  * 60));
      Serial.print(lat[2]); Serial.print(" ");
      if(GPS.latitudeDegrees < 0){
        lat[3] = 115;
      }else{
        lat[3] = 110;
      }
      Serial.print(lat[3]); Serial.println(" ");
      
      //lon[0] = abs(int(GPS.longitudeDegrees));
      //Serial.print(lon[0]); Serial.print(" ");
      lon[0] = abs(int((GPS.longitudeDegrees - int(GPS.longitudeDegrees)) * 60));
      Serial.print(lon[0]); Serial.print(" ");
      lon[1] = abs(int((((GPS.longitudeDegrees - int(GPS.longitudeDegrees)) * 60) - 
                int((GPS.longitudeDegrees - int(GPS.longitudeDegrees)) * 60)) * 60));
      Serial.print(lon[1]); Serial.print(" ");
      lon[2] = abs(int((((((GPS.longitudeDegrees - int(GPS.longitudeDegrees)) * 60) - 
                  int((GPS.longitudeDegrees - int(GPS.longitudeDegrees)) * 60)) * 60)
                  - 
                  int((((GPS.longitudeDegrees - int(GPS.longitudeDegrees)) * 60) - 
                  int((GPS.longitudeDegrees - int(GPS.longitudeDegrees)) * 60)) * 60)) 
                  * 60));
      Serial.print(lon[2]); Serial.print(" ");
      if(GPS.longitudeDegrees < 0){
        lon[3] = 119;
      }else{
        lon[3] = 101;
      }
      Serial.print(lon[3]); Serial.println(" ");

      alt = GPS.altitude;
      Serial.println(alt);
    }
  }
}

//done !!! no delay but per 2000ms/0,5Hz

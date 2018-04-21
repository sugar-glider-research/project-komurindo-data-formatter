#include <SoftwareSerial.h>
#include <Servo.h>
#include <Adafruit_GPS.h>

//brushless
Servo brushless;
int m_power = 0;

//GPS
Adafruit_GPS GPS(&Serial2);
#define GPSECHO  false
boolean usingInterrupt = false;
void useInterrupt(boolean); // Func prototype keeps Arduino 0023 happy
uint32_t timer = millis();

//penampung data
char format_data_12[33];
char format_image_init[7]; 
char format_data_60[641];

//data mentah
int initial = 111; //done
int acc[3] = {1,2,3}; //done
int gyro[3] = {4,5,6}; //done
int yaw = 7; //done
int t_orien[7] = {0,0,0,0,0,0,0}; //done

int row_rgb = 1;
int rgb[200][3];

int lon[4] = {13, 14, 15, 110}; //n = 110, s = 115 minus //done
int lat[4] = {16, 17, 18, 101}; //e = 101, w = 119 minus //done
int alt = 19; //done

boolean image_time = false;

char command;

void setup() {
  Serial.begin(57600);
  
  GPS.begin(9600);
  GPS.sendCommand(PMTK_SET_NMEA_OUTPUT_RMCGGA);
  GPS.sendCommand(PMTK_SET_NMEA_UPDATE_1HZ);
  GPS.sendCommand(PGCMD_ANTENNA);
  useInterrupt(false);
  delay(1000);
  Serial2.println(PMTK_Q_RELEASE); // Ask for firmware version

  Serial1.begin(57600);
  
  brushless.attach(9);

  Serial3.begin(57600);
  
  init(initial);
  space();
}

void loop() {
  //int start_time = millis();
  if(Serial3.available()){
    command = Serial3.read();
    //Serial.println(command);
  }

  if(command == '1'){
  //while(millis()-start_time<=12000){
    read_razor(); //Serial 1 : read acc xyz, gyro xyz and yaw for 1 line
    send_data_orient(); //Serial 3 : send formated 12 second data 1 line
    delay(200);
  }

  /*if(command == '2'){
  //while(millis()-start_time>12000 && millis()-start_time<=72000){ 
    if(image_time == true){
      //delay(3000);
      Serial.write("1");
      Serial.write("");
      while(Serial.available()){
        Serial.flush();
        //gps_track(); //Serial 2 : read lon lat alt for 1 line
        read_rgb(); //Serial 0 : read rgb for ... ???
        send_data_surv(); //Serial 3 : send formated 60 second data for 1 line
      }
    }else{  
      String _send_ (format_image_init);
      //Serial.println(_send_);
      Serial3.println(_send_); //Serial 3 : send image initial data for once
      image_time = true;
    }
  }*/
}

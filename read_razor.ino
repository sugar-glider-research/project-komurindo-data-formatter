void read_razor(){
  
  t_orien[0] = Serial1.parseInt();
  t_orien[1] = Serial1.parseInt();
  t_orien[2] = Serial1.parseInt();
  t_orien[3] = Serial1.parseInt();
  t_orien[4] = Serial1.parseInt();
  t_orien[5] = Serial1.parseInt();
  t_orien[6] = Serial1.parseInt();

  if(t_orien[0] <= 999 && t_orien[0] > 0){
    acc[0] = t_orien[0];
  }
  if(t_orien[1] <= 999 && t_orien[1] > 0){
    acc[1] = t_orien[1];
  }
  if(t_orien[2] <= 999 && t_orien[2] > 0){
    acc[2] = t_orien[2];
  }
  if(t_orien[3] <= 999 && t_orien[3] > 0){
    gyro[0] = t_orien[3];
  }
  if(t_orien[4] <= 999 && t_orien[4] > 0){
    gyro[1] = t_orien[4];
  }
  if(t_orien[5] <= 999 && t_orien[5] > 0){
    gyro[2] = t_orien[5];
  }
  if(t_orien[6] <= 999 && t_orien[6] > 0){
    yaw = t_orien[6] % 360;
  }
  /*Serial.print("Accel 0 : "); Serial.println(acc[0]);
  Serial.print("Accel 1 : "); Serial.println(acc[1]);
  Serial.print("Accel 2 : "); Serial.println(acc[2]);
  Serial.print("Gyro 0 : "); Serial.println(gyro[0]);
  Serial.print("Gyro 1 : "); Serial.println(gyro[1]);
  Serial.print("Gyro 2 : "); Serial.println(gyro[2]);
  Serial.print("Yaw : "); Serial.println(yaw);*/
  
  /*boolean tampung = false;
  boolean insert = false;
  
  int var_count = 0;
  int which_var = 0; //acc 1, ...2, ...3, gyro 1, ...2, ...3, y, p, r
  
  char temp[4];
  char data;
                        
  //hingga pindah baris
  while(data != '\n'){
    //baca data input
    if(Serial1.available()){
      data = Serial1.read();
    }

    //tampung data
    if(data == ','){
      if(Serial1.available()){
        data = Serial1.read();
      }
      tampung = true;
      var_count = 0;
      which_var++;
    }
    if(tampung == true){
      temp[var_count] = data;
      var_count++;
    }
    if(var_count == 3){
      var_count = 0;
      tampung = false;
      insert = true;
      if(which_var > 7){
        which_var = 1;
      }
    }
    
    //insert ke variable
    //penanggulangan nilai 0
    if(insert){
      if(atoi(temp) == 0){
        //...........
      }else{
        switch(which_var){
          case 1 : acc[0] = atoi(temp);
                  Serial.print("Accel 0 : "); 
                  Serial.println(acc[0]); 
                  break;
          case 2 : acc[1] = atoi(temp); 
                  Serial.print("Accel 1 : "); 
                  Serial.println(acc[1]); 
                  break;
          case 3 : acc[2] = atoi(temp); 
                  Serial.print("Accel 2 : "); 
                  Serial.println(acc[2]); 
                  break;
          case 4 : gyro[0] = atoi(temp); 
                  Serial.print("Gyro 0 : "); 
                  Serial.println(gyro[0]); 
                  break;
          case 5 : gyro[1] = atoi(temp); 
                  Serial.print("Gyro 1 : "); 
                  Serial.println(gyro[1]); 
                  break;
          case 6 : gyro[2] = atoi(temp); 
                  Serial.print("Gyro 2 : "); 
                  Serial.println(gyro[2]); 
                  break;
          case 7 : yaw = atoi(temp); 
                  Serial.print("Yaw : "); 
                  Serial.println(yaw); 
                  break;
          default : Serial.print("Error : "); 
                  Serial.println(which_var);
                  which_var = 0; 
                  break;
        }
      }    
      insert = false;
    }    
  }*/
}

//done !!! no delay but per 20ms/50Hz

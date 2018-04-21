void read_rgb(){
  int index = 4;

  for(int i = 0; i<200; i++){
    rgb[i][0] = int(Serial.parseInt());
    rgb[i][1] = int(Serial.parseInt());
    rgb[i][2] = int(Serial.parseInt());
  }
  
  for(int i = 0; i<200; i++){
    if(rgb[i][0] == 255){
      format_data_60[index] = 254;
    }else if(rgb[i][0] >= 0 && rgb[i][0] <= 32){
      format_data_60[index] = 33;
    }else{
      format_data_60[index] = rgb[i][0];
    }
    
    if(rgb[i][1] == 255){
      format_data_60[index+1] = 254;
    }else if(rgb[i][1] >= 0 && rgb[i][1] <= 32){
      format_data_60[index+1] = 33;
    }else{
      format_data_60[index+1] = rgb[i][1];
    }
    
    if(rgb[i][2] == 255){
      format_data_60[index+2] = 254;
    }else if(rgb[i][2] >= 0 && rgb[i][2] <= 32){
      format_data_60[index+2] = 33;
    }else{
      format_data_60[index+2] = rgb[i][2];
    }
    
    index = index + 3;
  }

  delay(200);
  
  //input saat read
  /*for(int i=4; i<603; i=i+3){
    if(format_data_60[index] == 0xFF){
      format_data_60[index] = 0xFE;
    }else if(format_data_60[index+1] == 0xFF){
      format_data_60[index+1] = 0xFE;
    }else if(format_data_60[index+2] == 0xFF){
      format_data_60[index+2] = 0xFE;
    }
  }*/
  
  /*boolean insert = false;
  
  int which_var = 0; //rgb[0], rgb[1], rgb[2]
  int index = 4;
  
  char temp[4];
  int data;
                        
  //hingga pindah baris
  while(data != 0x20){
    
    //baca data input
    if(Serial.available()) {
      data = Serial.read();
    }
  
    //validasi insert data
    if(data == 0xFF){
      insert = true;
      if(Serial.available()){
        data = Serial.read();
      }
    }
    if(insert == true){
      temp[which_var] = data;
      which_var++;
      if(which_var > 2){
        which_var = 0;
        format_data_60[index] = rgb[0];
        format_data_60[index+1] = rgb[1];
        format_data_60[index+2] = rgb[2];
        index=index+3;
      }
    }
  
    //insert ke variable
    if(insert){
      switch(which_var){
        case 1 : rgb[0] = data; 
                Serial.print("R : "); Serial.println(data);
                break;
        case 2 : rgb[1] = data; 
                Serial.print("G : "); Serial.println(data);
                break;
        case 3 : rgb[2] = data; 
                Serial.print("B : "); Serial.println(data);
                break;
        default : which_var = 0; break;
      }
    }    
  }
  insert = false;*/
}

//done !!!

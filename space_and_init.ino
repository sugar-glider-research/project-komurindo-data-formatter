void init(int initial){
  format_data_12[0] = 0x0D;
  format_image_init[0] = 0x0D;
  format_image_init[4] = 0xFF;
  format_image_init[5] = 0x0D;
  format_data_60[0] = 0xFF;
  if(initial<10){
    format_data_12[1] = '0';
    format_data_12[2] = '0';
    format_data_12[3] = '0' + initial;
    format_image_init[1] = '0';
    format_image_init[2] = '0';
    format_image_init[3] = '0' + initial;
  }else if(initial>=10 && initial<100){
    format_data_12[1] = '0';
    format_data_12[2] = '0' + (initial/10);
    format_data_12[3] = '0' + (initial%10);
    format_image_init[1] = '0';
    format_image_init[2] = '0' + (initial/10);
    format_image_init[3] = '0' + (initial%10);
  }else{
    format_data_12[1] = '0' + (initial/100);
    format_data_12[2] = '0' + ((initial%100)/10);
    format_data_12[3] = '0' + (initial%10);
    format_image_init[1] = '0' + (initial/100);
    format_image_init[2] = '0' + ((initial%100)/10);
    format_image_init[3] = '0' + (initial%10);
  }
}

void space(){
  for(int i=4; i<32; i=i+4){
    format_data_12[i] = 0x20;
  }
  for(int i=604; i<640; i=i+4){
    format_data_60[i] = 0x20;
  }
}

//done !!!

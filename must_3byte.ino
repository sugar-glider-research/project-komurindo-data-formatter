void must_3byte(int data, int index, int sesi){
  if(sesi == 1){
    if(data<10){
      format_data_12[index] = '0';
      format_data_12[index+1] = '0';
      format_data_12[index+2] = '0' + data;
    }else if(data>=10 && data<100){
      format_data_12[index] = '0';
      format_data_12[index+1] = '0' + (data/10);
      format_data_12[index+2] = '0' + (data%10);
    }else{
      format_data_12[index] = '0' + (data/100);
      format_data_12[index+1] = '0' + ((data%100)/10);
      format_data_12[index+2] = '0' + (data%10);
    }
  }else if(sesi == 2){
    if(data<10){
      format_data_60[index] = '0';
      format_data_60[index+1] = '0';
      format_data_60[index+2] = '0' + data;
    }else if(data>=10 && data<100){
      format_data_60[index] = '0';
      format_data_60[index+1] = '0' + (data/10);
      format_data_60[index+2] = '0' + (data%10);
    }else{
      format_data_60[index] = '0' + (data/100);
      format_data_60[index+1] = '0' + ((data%100)/10);
      format_data_60[index+2] = '0' + (data%10);
    }
  }
}

//done !!!

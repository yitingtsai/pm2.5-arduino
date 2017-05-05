void setup() {  //初始設定 (一次性)
  Serial.begin(9600);
  Serial.begin(9600);
}

void loop() {  //無限迴圈
  while(Serial.available()){
    CopeSerialData(Serial.read()); 
  }
  delay(1000);
}

char CopeSerialData(unsigned char ucData){
  static unsigned char ucRxBuffer[250];
  static unsigned char ucRxCnt = 0;
  static unsigned char toggle = 0;
  
  long  pmcf10=0,pmcf25=0,pmcf100=0;
  long  pmat10=0,pmat25=0,pmat100=0;
  long  pmcount03=0,pmcount05=0,pmcount10=0;
  long  pmcount25=0,pmcount50=0,pmcount100=0;
  long  HCHO=0, temp=0, humi=0;

  ucRxBuffer[ucRxCnt++]=ucData;
  
  if(ucRxBuffer[0]!=0x42&&ucRxBuffer[1]!=0x4D){
    ucRxCnt=0;
    return ucRxCnt;
  }
  
  if (ucRxCnt<32){  // PMS7003, PMS5003
    return ucRxCnt;
  }
  else{
 
    // --- G5 & G7
    pmcf10=(float)ucRxBuffer[4]*256+(float)ucRxBuffer[5];      //Serial.print("PM1.0_CF1:"); Serial.print(pmcf10);    Serial.print("   ");
    pmcf25=(float)ucRxBuffer[6]*256+(float)ucRxBuffer[7];      //Serial.print("PM2.5_CF1:"); Serial.print(pmcf25);    Serial.print("   ");
    pmcf100=(float)ucRxBuffer[8]*256+(float)ucRxBuffer[9];     Serial.print("PM10_CF1:");  Serial.println(pmcf100);
    pmat10=(float)ucRxBuffer[10]*256+(float)ucRxBuffer[11];    Serial.print("PM1.0_AT:");  Serial.print(pmat10);    Serial.print("   ");
    pmat25=(float)ucRxBuffer[12]*256+(float)ucRxBuffer[13];    Serial.print("PM2.5_AT:");  Serial.print(pmat25);    Serial.print("   ");
    pmat100=(float)ucRxBuffer[14]*256+(float)ucRxBuffer[15];   Serial.print("PM10_AT:");   Serial.println(pmat100);   
    //pmcount03=(float)ucRxBuffer[16]*256+(float)ucRxBuffer[17]; //Serial.print("PMcount0.3:");Serial.println(pmcount03); 
    //pmcount05=(float)ucRxBuffer[18]*256+(float)ucRxBuffer[19]; //Serial.print("PMcount0.5:");Serial.println(pmcount05); 
    //pmcount10=(float)ucRxBuffer[20]*256+(float)ucRxBuffer[21]; //Serial.print("PMcount1.0:");Serial.println(pmcount10); 
    //pmcount25=(float)ucRxBuffer[22]*256+(float)ucRxBuffer[23]; //Serial.print("PMcount2.5:");Serial.println(pmcount25); 
    //pmcount50=(float)ucRxBuffer[24]*256+(float)ucRxBuffer[25]; //Serial.print("PMcount5.0:");Serial.println(pmcount50); 
    //pmcount100=(float)ucRxBuffer[26]*256+(float)ucRxBuffer[27];//Serial.print("PMcount10:"); Serial.println(pmcount100);

    ucRxCnt=0;
    return ucRxCnt;
  }
}


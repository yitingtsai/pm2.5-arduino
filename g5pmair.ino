void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.begin(9600);
}

int sync=0;
byte packet[33];

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()) {
    packet[sync]=Serial.read();
    if ((sync==0) && (packet[sync]==0x42)) {
      sync=1;
      //Serial.println("sync1");
    }
    
    if ((sync==1) && (packet[sync]==0x4d)) {
      sync=2;
      //Serial.println("sync2");
    }   
    
    if ((sync==2) && (packet[sync]==0x00)) {
      sync=3;    
      //Serial.println("sync3");
    }
    
    if ((sync==3) && (packet[sync]==0x1c)) {
      sync=4;    
      //Serial.println("sync4");
    } 
    
    if (sync>=4) {     
      sync++;    
    }
            
    if (sync>32) {   
       for (int i=0; i<33; i++) {
          Serial.print(packet[i],HEX);
          Serial.print(" ");        
       }
       Serial.println(" ");
       Serial.print("PM1.0 = ");     Serial.print(packet[4]*256+packet[5]);
       Serial.print(",   PM2.5 = "); Serial.print(packet[6]*256+packet[7]);
       Serial.print(",   PM10 = ");  Serial.print(packet[8]*256+packet[9]);
       Serial.print(",   0.3um = "); Serial.print(packet[10]*256+packet[11]);
       Serial.print(",   0.5um = "); Serial.print(packet[12]*256+packet[13]);
       Serial.print(",   1.0um = "); Serial.print(packet[14]*256+packet[15]);
       Serial.print(",   2.5um = "); Serial.print(packet[16]*256+packet[17]);
       Serial.print(",   5.0um = "); Serial.print(packet[18]*256+packet[19]);
       Serial.print(",   10um = "); Serial.println(packet[20]*256+packet[21]);
       sync=0;
    }
  }
  delay(10);
}


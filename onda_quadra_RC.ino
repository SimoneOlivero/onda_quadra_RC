
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(13, OUTPUT); 
}

void loop() {
  float start = analogRead(A4)*5/1024.;
  if (start > 3.0) {
    unsigned long t0 = micros();
    unsigned long t = 1000;
    while(1){
      // put your main code here, to run repeatedly:
      digitalWrite(13, HIGH);
      int passo = 2;
      
      unsigned long startH = millis();
      while (fabs(millis()-startH < t)){
        unsigned long now = micros();
        Serial.print(now - t0);
        Serial.print(" ; ");
        float voltageIN = analogRead(A1)*5/1024.;
        Serial.print(voltageIN);
        Serial.print(" ; ");
        float voltageC = analogRead(A0)*5/1024.;
        Serial.println(voltageC);    
      }
      digitalWrite(13, LOW);
     
      unsigned long startL = millis(); 
      while (fabs(millis()-startL < t)){
        unsigned long now = micros();
        Serial.print(now - t0);
        Serial.print(" ; ");
        float voltageIN = analogRead(A1)*5/1024.;
        Serial.print(voltageIN);
        Serial.print(" ; ");
        float voltageC = analogRead(A0)*5/1024.;
        Serial.println(voltageC);
      }
    }
  }  
}

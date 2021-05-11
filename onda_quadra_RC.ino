
void setup() {
  // attivo il monitor seriale e l'uscita digitale 13
  Serial.begin(9600);
  pinMode(13, OUTPUT); 
}

void loop() {
  // utlizzo l'input analogico A4 come starer (quando premo il pulsante rileva una tensione e farà partire il programma)
  float start = analogRead(A4)*5/1024.;
  if (start > 3.0) {
    unsigned long t0 = micros(); // rilevo il momento in cui inizia il cilo
    unsigned long t = 700; // t é uguale al periodo/2
   
    
    // 
    for(int T=0;T<3;T++) { // il numero di periodi (5) per cui diamo in uscita l'onda quadra
    
      digitalWrite(13, HIGH); // imposto il pin 13 su HIGH, fronira una tensione di 5V
      unsigned long startH = millis(); // rilevo il momento in cui il pin 13 passa allo stato HIGH

      // l'arduino stampa nel monitor seriale i dati della tensione sul PIN 13 e ai capi del condensatore finchè il tempo trascorso è minore di t impostato in precedenza
      while (fabs(millis()-startH < t)){ // l'arduino stampa nel monitor seriale i dati della tensione sul PIN 13 e ai capi del condensatore 
        unsigned long now = micros();
        Serial.print(now - t0);
        Serial.print(" ; ");
        float voltageIN = analogRead(A1)*5/1024.;
        Serial.print(voltageIN);
        Serial.print(" ; ");
        float voltageC = analogRead(A0)*5/1024.;
        Serial.println(voltageC);    
      }
      digitalWrite(13, LOW); // imposto il pin 13 su LOW, fronira una tensione di 0V
      unsigned long startL = millis(); // rilevo il momento in cui il pin 13 passa allo stato LOW
      
      // l'arduino stampa nel monitor seriale i dati della tensione sul PIN 13 e ai capi del condensatore finchè il tempo trascorso è minore di t impostato in precedenza
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
    while(1){ // ciclo infinito in cui l'arduino scrive sul monitor seriale i dati, ma non genera nessuna tensione in uscita
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
   

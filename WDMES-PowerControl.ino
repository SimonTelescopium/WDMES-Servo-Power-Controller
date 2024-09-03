/* WDMES SERVO CONTROLLER POWER BOARD

By Simon Dawes & Thomas Hunt 2024-06-25 

PROBLEM STATEMENT: Server controller boards when powered up all try to connect to 
wifi at the same time, this invariably results in some servor boards timing out 
and the servo controllers fall back to Can bus operation.
SOLUTION: This software drives an Arduino connected to an 8x relay board, these relays
power-up the servo controller boards one at a time with a delay between each 
(see below to set this).

Connect the relay control lines to digital pins 3-10 on the Arduino. 
*/ 

// Set-up
#define DELAY 4000 //delay in mS between each relay turning on
#define SERIALBAUD 9600
//setup ends

void setup() {
  // put your setup code here, to run once:
for (int pin = 3; pin <=10; pin++){
  pinMode (pin, OUTPUT);
  digitalWrite (pin,HIGH);
}

  Serial.begin(SERIALBAUD);
  RelaysAllOn();
  Serial.println("All done :-)");
}

void loop() {
  // put your main code here, to run repeatedly:

}

void RelaysAllOn(){
 for (int pin = 3; pin <=10; pin++){
  digitalWrite (pin,LOW);
  Serial.print("Pin ");
  Serial.print(pin);
  Serial.println(" LOW");
  delay(DELAY);
} 


}
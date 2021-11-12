#include <ModbusIP.h>
#include <Modbus.h>
#include <Ethernet.h>
#include <SPI.h>

int setPoint;
const int setPoint_IR = 100;
ModbusIP mb;

void setup() {
  Serial.begin(9600);

  byte mac[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED};
  byte ip[] = {10, 100, 1, 204};
  mb.config (mac, ip);

  mb.addIreg(setPoint_IR); 
}

void loop() {
  mb.task();
  setPoint = analogRead(A0);
  mb.Ireg (setPoint_IR, setPoint);
  DisplaySetPointValues();
  delay(500);
}

void DisplaySetPointValues(){
  String Printstr;
  Printstr = "SetPoint Values = " + String(setPoint);
  Serial.println(Printstr);
  
}

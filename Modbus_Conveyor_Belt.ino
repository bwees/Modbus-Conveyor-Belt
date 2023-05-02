
#include <WebServer_WT32_ETH01.h>
#include <ModbusIP_ESP8266.h>

// Conveyor Speed Registers: A: 100, B: 200

IPAddress myIP(10, 0, 1, 100);
IPAddress myGW(10, 0, 1, 1);
IPAddress mySN(255, 255, 255, 0);
IPAddress myDNS(8, 8, 8, 8);

ModbusIP mb;
  
void setup() {
 
  WT32_ETH01_onEvent();
  ETH.begin(ETH_PHY_ADDR, ETH_PHY_POWER);
  ETH.config(myIP, myGW, mySN, myDNS);
  WT32_ETH01_waitForConnect();
  
  mb.server();
  mb.addHreg(100, 0); // Setup Conveyor 1 Register
  mb.addHreg(200, 0); // Setup Conveyor 1 Register
}
 
void loop() {
   mb.task();
   delay(10);
}

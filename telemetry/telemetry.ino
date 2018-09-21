/*
      Wiring
 
      433MHz 100mw
       RF modules                                       NodeMCU
      +-----------+                                  +----------+
      |        TX +------+ RX (PIN 5)    TX   +------+ PIN 5    |
      |           |                                  |          |
      |        RX +------+ TX (PIN 4)    RX   +------+ PIN 4    |
      |           |                                  |      USB +--------+ TERMINAL
      |        5V +------+ 5V                        |          |
      |           |                                  |          |
      |        GND+------+ GND           GND  +------+ GND      |
      +-----------+                                  +----------+
      +-----------+                                  +----------+
      |        TX +------+ RX (PIN 5)    TX   +------+ PIN 5    |
      |           |                                  |          |
      |        RX +------+ TX (PIN 4)    RX   +------+ PIN 4    |
      |           |                                  |      USB +--------+ TERMINAL
      |        5V +------+ 5V                        |          |
      |           |                                  |          |
      |        GND+------+ GND           GND  +------+ GND      |
      +-----------+                                  +----------+
 */

#include <SoftwareSerial.h>

SoftwareSerial mySerial(5, 4); // RX, TX

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  Serial.println("Formula Telemetry v0.1");
  Serial.println("COM Baud rate 9600");
  Serial.println("RF Baud rate 57600");

  // set the data rate for the SoftwareSerial port
  mySerial.begin(57600);
}

void loop() { // run over and over
  if (mySerial.available()) {
    Serial.write(mySerial.read());
  }
  if (Serial.available()) {
    mySerial.write(Serial.read());
  }
}

/*********************************
 * name:buzzer
 * function: you should hear the buzzer make sounds.
 *************************************/
//Email: info@primerobotics.in
//Website: www.rimerobotics.in
// https://maker.pro/arduino/projects/buzzer
/************************************/
int buzzer = 12;  //the pin of the active buzzer

#include <U8g2lib.h>
#include <Wire.h>

U8G2_SH1106_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, U8X8_PIN_NONE);

void setup() {
  // start serial port at 9600 bps and wait for port to open:
  Serial.begin(9600);
  establishContact();
  u8g2.begin();
  pinMode(buzzer, OUTPUT);  //initialize the buzzer pin as an output
}

void establishContact() {
  int incomingByte = 0;
  Serial.println("Proszę czekać");  // send an initial string
  while (!Serial) {
    delay(100);
    Serial.println("Proszę czekać");  // send an initial string
                                      // read the incoming byte:
    delay(300);
  }
  Serial.println("Witaj w arduino, hakerze!");  // send an initial string
  delay(100);
}

void loop() {

  Serial.println("stem4dziewczynek!");
  delay(100);
  Serial.println("hello Anna, Ania!");
  delay(50);

  u8g2.clearBuffer();                       // Clean the device buffer
  u8g2.setFont(u8g2_font_t0_11_tf);         // Select the font for the screen
  char *name = "Maja";                      // Let's be lazy and use a variable
  char *message = "";                       // Custom message to show on the screen
  Serial.println(name);                     // Will show the message in the serial monitor (serial output)
  u8g2.drawStr(0, 16, "ArtesEdu");          // Ask the display to write a string at (X,Y) coordinates on the screen
  u8g2.drawStr(0, 32, "stem4dziewczynek");  // Ask the display to write a string at (X,Y) coordinates on the screen
  u8g2.drawStr(5, 48, name);                // Ask the display to write a string at (X,Y) coordinates on the screen
  u8g2.drawStr(5, 56, message);             // This should be a variable, but does not work
  u8g2.sendBuffer();                        // Send
  delay(20);

  exit(0);
}

// unsigned char i;
// //output an frequency
// for (i = 0; i < 80; i++) {
//   digitalWrite(buzzer, HIGH);
//   delay(1);  //wait for 1ms
//   digitalWrite(buzzer, LOW);
//   delay(1);  //wait for 1ms
// }
// //output another frequency
// for (i = 0; i < 100; i++) {
//   digitalWrite(buzzer, HIGH);
//   delay(2);  //wait for 2ms
//   digitalWrite(buzzer, LOW);
//   delay(2);  //wait for 2ms
// }
// }

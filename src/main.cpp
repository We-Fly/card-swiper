#include "main.h"

int freq = 2000;//设置频率
int channel = 0;//通道号，取值0 ~ 15
int resolution = 8;//计数位数，2的8次幂=256

int ledState = LOW;               // ledState used to set the LED
int previousButtonLState = LOW;    // will store last time button was updated
int previousButtonRState = LOW;    // will store last time button was updated
unsigned long previousMillis = 0; // will store last time LED was updated

int signUpMode = 0;

Adafruit_PN532 nfc(PN532_IRQ, PN532_RESET);

void setup(void)
{
  // set the digital pin as output:
  pinMode(NETWORK_LED, OUTPUT);
  pinMode(CARD_LED, OUTPUT);

  // set the digital pin as an input:
  pinMode(BUTTON_PIN_L, INPUT);
  pinMode(BUTTON_PIN_R, INPUT);

  // Set up buzzer
  ledcSetup(channel, freq, resolution);
  ledcAttachPin(BUZZER_PIN, channel);

  Serial.begin(115200);
  while (!Serial)
    delay(10); // for Leonardo/Micro/Zero
  Serial.println("Hello!\n");

  // I2C_0.begin(SDA_0 , SCL_0 , I2C_Freq);
  oledInit();

  pn532Init();
  initWiFi();
  getRRSI();
}

void loop()
{
  // check to see if it's time to blink the LED; that is, if the difference
  // between the current time and last time you blinked the LED is bigger than
  // the interval at which you want to blink the LED.
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= BLINK_INTERVAL)
  {
    if (WiFi.status() == WL_CONNECTED)
    {
      // if the LED is off turn it on and vice-versa:
      ledState = (ledState == LOW) ? HIGH : LOW;
      // set the LED with the ledState of the variable:
      digitalWrite(NETWORK_LED, ledState);
      // save the last time you blinked the LED
      previousMillis = currentMillis;
    }
    else
    {
      ledState = LOW;
      digitalWrite(NETWORK_LED, ledState);
      previousMillis = currentMillis;
    }
  }
  // check button L state's change
  int currentButtonLState = digitalRead(BUTTON_PIN_L);
  if (currentButtonLState != previousButtonLState)
  {
    // print out the state of the button:
    Serial.println("Button L = " + currentButtonLState);
    // save the last state of button
    signUpMode = (ledState == 0) ? 1 : 0;
    previousButtonLState = currentButtonLState;
  }
  // check button R state's change
  int currentButtonRState = digitalRead(BUTTON_PIN_L);
  if (currentButtonRState != previousButtonRState)
  {
    // print out the state of the button:
    Serial.println("Button R = " + currentButtonRState);
    // save the last state of button
    previousButtonRState = currentButtonRState;
  }
  // DO OTHER WORKS HERE
  if (pn532Scan())
  {
    
    vTaskDelay(100);

  }
}
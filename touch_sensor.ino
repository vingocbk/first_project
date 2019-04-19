/*
   Nikhil.P.Lokhande
   Project: ESP32 Touch Controled LED, using PWM
   Board: ESP32 Dev Module
   Touch Sensor Pin Layout
   T0 = GPIO4
   T1 = GPIO0
   T2 = GPIO2
   T3 = GPIO15
   T4 = GPIO13
   T5 = GPIO12
   T6 = GPIO14
   T7 = GPIO27
   T8 = GPIO33
   T9 = GPIO32 */


uint8_t led = 27;
uint8_t count = 0;
 
int buff(int pin)                                       //Function to handle the touch raw sensor data
{

  int out = (50 - touchRead(pin));                         //  Scale by n, value very sensitive currently
  // change to adjust sensitivity as required
  if (out > 0 )
  {
    return (out + 2);
  }
  else
  {
    return 0;                                        //Else, return 0
  }

}

void setup()
{
  ledcAttachPin(led, 1);                                                    //Configure variable led, pin 18 to channel 1
  ledcSetup(1, 12000, 8);                                                  // 12 kHz PWM and 8 bit resolution
  ledcWrite(1, 100);                                                       // Write a test value of 100 to channel 1
  Serial.begin(115200);
  Serial.println("Testing ledc 12 channel 1");




}
void loop()
{
  Serial.print("Touch sensor value:");
  int value = buff(T5);
  if(value > 30){
    count++;
  }
  Serial.print(value);
  Serial.print("\t\t");
  Serial.println(count);


  {
    ledcWrite(1, value);                 // Using T0 for touch data
  }

  delay(100);
}

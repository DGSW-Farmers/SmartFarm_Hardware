#define PH1 A3
#define PH2 A4
#define PH3 A5

float adc_resolution = 1024.0;

float ph(float voltage)
{
  return 7 + ((2.5 - voltage) / 0.18);
}

float get_ph1_value()
{
  int PH1_value = analogRead(PH1);
  float voltage1 = 5 / adc_resolution * PH1_value;
  return ph(voltage1);
}

float get_ph2_value()
{
  int PH2_value = analogRead(PH2);
  float voltage2 = 5 / adc_resolution * PH2_value;
  return ph(voltage2);
}

float get_ph3_value()
{
  int PH3_value = analogRead(PH3);
  float voltage3 = 5 / adc_resolution * PH3_value;
  return ph(voltage3);
}

void print_ph_value()
{
  Serial.print("ph1 = ");
  Serial.println(get_ph1_value());
  Serial.print("ph2 = ");
  Serial.println(get_ph2_value());
  Serial.print("ph3 = ");
  Serial.println(get_ph3_value());   Serial.println("\n");
}

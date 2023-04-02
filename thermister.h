#define ONE_WIRE_BUS1 2
#define ONE_WIRE_BUS2 3
#define ONE_WIRE_BUS3 4

// Setup a oneWire instance to communicate with any OneWire device
OneWire oneWire1(ONE_WIRE_BUS1);
OneWire oneWire2(ONE_WIRE_BUS2);
OneWire oneWire3(ONE_WIRE_BUS3);

// Pass oneWire reference to DallasTemperature library
DallasTemperature thermister1(&oneWire1);
DallasTemperature thermister2(&oneWire2);
DallasTemperature thermister3(&oneWire3);

float get_thermister1_value()
{
  float in_value = thermister1.getTempCByIndex(0);
  return in_value;
}

float get_thermister2_value()
{
  float in_value = thermister2.getTempCByIndex(0);
  return in_value;
}

float get_thermister3_value()
{
  float in_value = thermister3.getTempCByIndex(0);
  return in_value;
}

void print_temp()
{
  //print the temperature in Celsius
  Serial.print("Temperature1: ");
  Serial.print(thermister1.getTempCByIndex(0));
  Serial.print((char)176);//shows degrees character
  Serial.println("C  |  ");
  Serial.print("Temperature2: ");
  Serial.print(thermister2.getTempCByIndex(0));
  Serial.print((char)176);//shows degrees character
  Serial.println("C  |  ");
  Serial.print("Temperature3: ");
  Serial.print(thermister3.getTempCByIndex(0));
  Serial.print((char)176);//shows degrees character
  Serial.println("C  |  \n");

  //print the temperature in Fahrenheit
  /*Serial.print((sensors.getTempCByIndex(0) * 9.0) / 5.0 + 32.0);
    Serial.print((char)176);//shows degrees character
    Serial.println("F");*/
}

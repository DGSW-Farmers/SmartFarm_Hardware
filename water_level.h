#define WATER1_PIN 5
#define WATER2_PIN 6
#define WATER3_PIN 7
#define WATER_TANK_PIN 8

int get_water_1_level()
{
  return digitalRead(WATER1_PIN);
}

int get_water_2_level()
{
  return digitalRead(WATER2_PIN);
}

int get_water_3_level()
{
  return digitalRead(WATER3_PIN);
}

int get_water_tank_level()
{
  return digitalRead(WATER_TANK_PIN);
}


void print_water_level()
{
  Serial.print("Water1 : ");
  Serial.println(digitalRead(WATER1_PIN));
  Serial.print("Water2 : ");
  Serial.println(digitalRead(WATER2_PIN));
  Serial.print("Water3 : ");
  Serial.println(digitalRead(WATER3_PIN));
  Serial.print("Water_tank : ");
  Serial.println(digitalRead(WATER_TANK_PIN));
}

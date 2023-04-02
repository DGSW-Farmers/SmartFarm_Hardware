#define DHT11_PIN A2

//create dht11 object
DHT11 dht11(DHT11_PIN);
float humi, temp;

void get_dht_value()
{
  dht11.read(humi, temp);
}

float get_humidity_value()
{
  return humi;
}

float get_temperature_value()
{
  return temp;
}

void print_dht_value()
{
  get_dht_value();
  Serial.print("h : ");
  Serial.println(humi);
  Serial.print("t : ");
  Serial.println(temp);
}

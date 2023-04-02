#include <DHT11.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include "CDS.h"
#include "DHT.h"
#include "ph.h"
#include "pump.h"
#include "thermister.h"
#include "water_level.h"
#include "led.h"
#include "fan.h"
#include "SerialCommand.h"
#include "SerialSend.h"

#define CDS A1
#define DHT11_PIN A2
#define PH1 A3
#define PH2 A4
#define PH3 A5
#define ONE_WIRE_BUS1 2
#define ONE_WIRE_BUS2 3
#define ONE_WIRE_BUS3 4
#define WATER1_PIN 5
#define WATER2_PIN 6
#define WATER3_PIN 7
#define WATER_TANK_PIN 8
#define led1 9
#define led2 10
#define fan1 11
#define fan2 12
#define PUMP1_1 14
#define PUMP1_2 15
#define PUMP2_1 16
#define PUMP2_2 17
#define PUMP3_1 18
#define PUMP3_2 19

void setup()
{
  pinMode(CDS, INPUT);
  pinMode(DHT11_PIN, INPUT);
  pinMode(WATER1_PIN, INPUT);
  pinMode(WATER2_PIN, INPUT);
  pinMode(WATER3_PIN, INPUT);
  pinMode(WATER_TANK_PIN, INPUT);
  pinMode(PUMP1_1, OUTPUT);
  pinMode(PUMP1_2, OUTPUT);
  pinMode(PUMP2_1, OUTPUT);
  pinMode(PUMP2_2, OUTPUT);
  pinMode(PUMP3_1, OUTPUT);
  pinMode(PUMP3_2, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(fan1, OUTPUT);
  pinMode(fan2, OUTPUT);

  Serial.begin(9600);
  thermister1.begin();  // Start up the library
  thermister2.begin();  // Start up the library
  thermister3.begin();  // Start up the library
}

unsigned long prev_millis = 0;
int cds;
int water1LVL, water2LVL, water3LVL, watertankLVL;
float humidity, temperature;
float ph1, ph2, ph3;
float thermister1value, thermister2value, thermister3value;
void loop()
{
  unsigned long curr_millis = millis();
  if (curr_millis - prev_millis >= 1000)
  {

    prev_millis = curr_millis;

    get_dht_value();  //DHT값 읽기
    thermister1.requestTemperatures(); //써미스터 값 읽기
    thermister2.requestTemperatures();
    thermister3.requestTemperatures();

    get_sensor_value(); //센서값 읽기
    Send_sensor_value_to_Serial();  //센서값 시리얼 출력
    //print_sensor_value();   //테스트용 센서값 출력
  }
  serialCommand();  //커맨드값 받기
}

void print_sensor_value()
{
  Serial.print("CDS : ");
  Serial.println(cds);
  Serial.print("water 1 lvl : ");
  Serial.println(water1LVL);
  Serial.print("water 2 lvl : ");
  Serial.println(water2LVL);
  Serial.print("water 3 lvl : ");
  Serial.println(water3LVL);
  Serial.print("water tank lvl : ");
  Serial.println(watertankLVL);
  Serial.print("humidity : ");
  Serial.print(humidity);
  Serial.print("   temperature : ");
  Serial.println(temperature);
  Serial.print("ph1 : ");
  Serial.print(ph1);
  Serial.print("  ph2 : ");
  Serial.print(ph2);
  Serial.print("  ph3 : ");
  Serial.println(ph3);
  Serial.print("water 1 temp :"); 
  Serial.println(thermister1value);
  Serial.print("water 2 temp :"); 
  Serial.println(thermister2value);
  Serial.print("water 2 temp :"); 
  Serial.println(thermister3value);
  Serial.println("=============================");
}

void get_sensor_value()
{
  cds = get_cds_value();
  water1LVL = get_water_1_level();
  water2LVL = get_water_2_level();
  water3LVL = get_water_3_level();
  watertankLVL = get_water_tank_level();
  humidity = get_humidity_value();
  temperature = get_temperature_value();
  ph1 = get_ph1_value();
  ph2 = get_ph2_value();
  ph3 = get_ph3_value();
  thermister1value = get_thermister1_value();
  thermister2value = get_thermister2_value();
  thermister3value = get_thermister3_value();
}

void Send_sensor_value_to_Serial()
{
  //물온도1|물온도2|물온도3|산성도1|산성도2|산성도3|수위1|수위2|수위3|수위탱크|온도|습도|조도
  Serial.print(thermister1value);  Serial.print('|');
  Serial.print(thermister2value);  Serial.print('|');
  Serial.print(thermister3value);  Serial.print('|');
  Serial.print(ph1);  Serial.print('|');
  Serial.print(ph2);  Serial.print('|');
  Serial.print(ph3);  Serial.print('|');
  Serial.print(water1LVL);  Serial.print('|');
  Serial.print(water2LVL);  Serial.print('|');
  Serial.print(water3LVL);  Serial.print('|');
  Serial.print(watertankLVL);  Serial.print('|');
  Serial.print(temperature);  Serial.print('|');
  Serial.print(humidity);  Serial.print('|');
  Serial.print(cds);
}

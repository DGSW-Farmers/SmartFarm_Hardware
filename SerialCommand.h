String readStr;  //수신 Serial data 저장 변수
int i = 0;

void serialCommand()
{
  if (Serial.available())
  {
    readStr = Serial.readString();
    if (readStr == "p111") pump_control(1, 1, 1); //pump_level : 1 ~ 3, pump_num : 1 ~ 2, pump1_command : 0 ~ 1
    else if (readStr == "p110")  pump_control(1, 1, 0);
    else if (readStr == "p121")  pump_control(1, 2, 1);
    else if (readStr == "p120")  pump_control(1, 2, 0);
    //----------------------------------
    else if (readStr == "p211")  pump_control(2, 1, 1);
    else if (readStr == "p210")  pump_control(2, 1, 0);
    else if (readStr == "p221")  pump_control(2, 2, 1);
    else if (readStr == "p220")  pump_control(2, 2, 0);
    //----------------------------------
    else if (readStr == "p311")  pump_control(3, 1, 1);
    else if (readStr == "p310")  pump_control(3, 1, 0);
    else if (readStr == "p321")  pump_control(3, 2, 1);
    else if (readStr == "p320")  pump_control(3, 2, 0);
    //----------------------------------
    else if (readStr == "l11")  led_control(1, 1);
    else if (readStr == "l10")  led_control(1, 0);
    //----------------------------------
    else if (readStr == "l21")  led_control(2, 1);
    else if (readStr == "l20")  led_control(2, 0);
    //----------------------------------
    else if (readStr == "f11")  fan_control(1, 1);
    else if (readStr == "f10")  fan_control(1, 0);
    //----------------------------------
    else if (readStr == "f21")  fan_control(2, 1);
    else if (readStr == "f20")  fan_control(2, 0);
  }
}

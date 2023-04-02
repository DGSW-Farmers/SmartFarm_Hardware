#define PUMP1_1 14
#define PUMP1_2 15
#define PUMP2_1 16
#define PUMP2_2 17
#define PUMP3_1 18
#define PUMP3_2 19

void pump_number_error()
{
  Serial.println("pump_number error : undefined value inserted");
}

void pump_command_error()
{
  Serial.println("pump_command error : undefined command inserted");
}

void pump_control(int pump_level, int pump_num, int pump_command)
{
  //               pump_level : 1 ~ 3, pump_num : 1 ~ 2, pump1_command : 0 ~ 1
  //=========================================
  if (pump_level == 1)
  {
    if (pump_num == 1)
    {
      if (pump_command == 1)  digitalWrite(PUMP1_1, HIGH);
      else if (pump_command == 0) digitalWrite(PUMP1_1, LOW);
      else  pump_command_error();
    }
    else if (pump_num == 2)
    {
      if (pump_command == 1)  digitalWrite(PUMP1_2, HIGH);
      else if (pump_command == 0) digitalWrite(PUMP1_2, LOW);
      else  pump_command_error();
    }
    else pump_number_error();
  }

  //=========================================

  else if (pump_level == 2)
  {
    if (pump_num == 1)
    {
      if (pump_command == 1)  digitalWrite(PUMP2_1, HIGH);
      else if (pump_command == 0) digitalWrite(PUMP2_1, LOW);
      else  pump_command_error();
    }
    else if (pump_num == 2)
    {
      if (pump_command == 1)  digitalWrite(PUMP2_2, HIGH);
      else if (pump_command == 0) digitalWrite(PUMP2_2, LOW);
      else  pump_command_error();
    }
    else pump_number_error();
  }

  //=========================================

  else if (pump_level == 3)
  {
    if (pump_num == 1)
    {
      if (pump_command == 1)  digitalWrite(PUMP3_1, HIGH);
      else if (pump_command == 0) digitalWrite(PUMP3_1, LOW);
      else  pump_command_error();
    }
    else if (pump_num == 2)
    {
      if (pump_command == 1)  digitalWrite(PUMP3_2, HIGH);
      else if (pump_command == 0) digitalWrite(PUMP3_2, LOW);
      else  pump_command_error();
    }
    else pump_number_error();
  }
  else  Serial.println("pump_level error : undefined value inserted");
}

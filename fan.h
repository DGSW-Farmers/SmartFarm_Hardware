#define fan1 11
#define fan2 12

void fan_control(int fan_num, int fan_control)
{
  if (fan_num == 1)
  {
    if (fan_control == 1)
    {
      digitalWrite(fan1, HIGH);
      //Serial.println("fan1 ON");
    }
    else if (fan_control == 0)
    {
      digitalWrite(fan1, LOW);
      //Serial.println("fan1 OFF");
    }
    else
    {
      Serial.println("fan_control error : invalid command inserted");
    }
  }
  else if (fan_num == 2)
  {
    if (fan_control == 1)
    {
      digitalWrite(fan2, HIGH);
    }
    else if (fan_control == 0)
    {
      digitalWrite(fan2, LOW);
    }
    else  
    {
      Serial.println("fan_control error : invalid command inserted");
    }
  }
  else Serial.println("fan_number error : invalid number inserted");
}

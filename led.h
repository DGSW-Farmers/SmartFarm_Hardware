#define led1 9
#define led2 10


void led_control(int led_num, int led_control)
{
  if (led_num == 1)
  {
    if (led_control == 1)
    {
      digitalWrite(led1, HIGH);
    }
    else if (led_control == 0)
    {
      digitalWrite(led1, LOW);
    }
    else
    {
      Serial.println("led_control error : invalid command inserted");
    }
  }
  else if (led_num == 2)
  {
    if (led_control == 1)
    {
      digitalWrite(led2, HIGH);
    }
    else if (led_control == 0)
    {
      digitalWrite(led2, LOW);
    }
    else 
    {
      Serial.println("led_control error : invalid command inserted");
    }
  }
  else  Serial.println("led_number error : invalid number inserted");
}

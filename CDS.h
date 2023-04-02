#define CDS A1

void print_cds_value()
{
  Serial.println(analogRead(CDS));
}

int get_cds_value()
{
  int cds_in_value = analogRead(CDS);
  return cds_in_value;
}

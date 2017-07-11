void displaygpsInfo()
{ 
  Serial.print(F("Location: ")); 
  String st="http://maps.google.com/?q=";
  String lati,langi;
  if (gps.location.isValid())
  {
    lati=String(gps.location.lat(), 6);
    langi=String(gps.location.lng(), 6);
    Serial.print(gps.location.lat(), 6);
    Serial.print(F(","));
    Serial.print(gps.location.lng(), 6);
    st=st+lati+","+langi;
  }
  else
  {
    Serial.print(F("INVALID"));
  }
  Serial.print("    ");
  Serial.println(st);
  if(digitalRead(sensepin)==LOW && flag==0)
  {
  SendMessage(st);
  flag=1;
  }
}

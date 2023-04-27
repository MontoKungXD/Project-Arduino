#include <Wire.h>//เรียกใช้ library Wire
#include <LiquidCrystal_I2C.h>//เรียกใช้ library LCD I2C
LiquidCrystal_I2C lcd(0x27, 16, 2);//กำหนดขนาดหน้าจอ LCD
void setup() 
{
  lcd.begin();//เริ่มต้นใช้งาน LCD
  lcd.backlight();//เปิด backlight
  lcd.noCursor();//ปิด Cursor
  lcd.noBlink();//ปิด Blink
  pinMode(3, OUTPUT); //กำหนด pin 3 เป็น output (ลำโพง)
}

void loop() 
{
  lcd.clear();//เคลียร์หน้าจอ
  lcd.setCursor(0,0);//กำหนดcursorที่ตำแหน่ง(0,0)
  lcd.print((String("WaterLevel : ")+String(analogRead(0))));//แสดงผลทางหน้าจอในรูปแบบ"WaterLevel : + ค่าที่อ่านได้จากpinA0(WaterLevelSensor)"
  if(analogRead(0)>=400)//ถ้าค่าที่อ่านจากpinA0>=400
  {
    tone (3,500);
    //เสียงลำโพงที่ pin 3 จะดังที่ความถี่ 440
  }
  else if(analogRead(0)>=200)//ถ้าค่าที่อ่านจากpinA0>=200
  {
    tone (3,500);
    //เสียงลำโพงที่ pin 3 จะดังที่ความถี่ 220
  }
  else //ถ้าค่าที่อ่านจากpinA0<200
  {
    noTone(3);
    //หยุดเสียงลำโพงที่ pin 3
  }
  delay(1000);//ดีเลย์1วินาที
}

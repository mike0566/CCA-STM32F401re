#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "DHT.h"

LiquidCrystal_I2C lcd(0x27, 20, 4);
DHT dht;

byte whiteChar[] = {
  B00000,
  B00000,
  B00000,
  B00100,
  B00100,
  B00000,
  B00000,
  B00000,
};
byte blackChar[] = {
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
};

byte super00[] = {
  B00000,
  B00000,
  B00111,
  B00111,
  B01011,
  B01111,
  B00111,
  B00010,

};
byte super10[] = {

  B00000,
  B00000,
  B11111,
  B10001,
  B00000,
  B11000,
  B11111,
  B11111,

};
byte super20[] = {
  B00000,
  B00000,
  B11000,
  B11100,
  B11010,
  B00010,
  B11100,
  B11000,
};
byte super01[] = {
  B00011,
  B00001,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
};
byte super11[] = {
  B00000,
  B11111,
  B11001,
  B01010,
  B00100,
  B00000,
  B00000,
  B00000,
};
byte super21[] = {
  B11000,
  B10000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
};

void setup() {


  lcd.init();
  lcd.createChar(0, super00);
  lcd.createChar(1, super10);
  lcd.createChar(2, super20);
  lcd.createChar(3, super01);
  lcd.createChar(4, super11);
  lcd.createChar(5, super21);
  lcd.backlight();
  lcd.home();
  delay(dht.getMinimumSamplingPeriod());
  dht.setup(2);
  Serial.begin(9600);

}
void loop()
{

  char str[] = "Hello World";

  veille_32();
  veille_3();
  veille_1();
  veille_2();
  putstr_center(str, 2);
  delay(5000);
  lcd.clear();
  lcd.setCursor((20 - strlen(str)) / 2, 1);
  putstr_delay(str, 1000);
  lcd.clear();

}

void veille_32()
{
  int a;
  int rand_nb;
  int rand_nb2;
  int rand_nb3;
  char str[] = "Bravo";


  for (a = 0; a < 18; a++)
  {
    float temperature = dht.getTemperature();
    rand_nb = random(3);
    rand_nb2 = random(2);
    rand_nb3 = random(2, 4);
    lcd.setCursor(a, rand_nb);
    lcd.write(byte(0));
    lcd.write(byte(1));
    lcd.write(byte(2));
    lcd.setCursor(a, rand_nb + 1);
    lcd.write(byte(3));
    lcd.write(byte(4));
    lcd.write(byte(5));
    if (a < 13)
    {
      if (rand_nb == 2)
      {
        lcd.setCursor(a, rand_nb2);
        lcd.print(temperature);
        lcd.print(" ");
        lcd.print(char(223));
        lcd.print("C");
      }
      if (rand_nb == 0)
      {
        lcd.setCursor(a, rand_nb3);
        lcd.print(temperature);
        lcd.print(" ");
        lcd.print(char(223));
        lcd.print("C");
      }

    }
    delay(500);
    lcd.clear();
  }
  lcd.clear();
  for (a = 16; a >= 0; a--)
  {
    float humidity = dht.getHumidity();
    rand_nb = random(3);
    rand_nb2 = random(2);
    rand_nb3 = random(2, 4);
    lcd.setCursor(a, rand_nb);
    lcd.write(byte(0));
    lcd.write(byte(1));
    lcd.write(byte(2));
    lcd.setCursor(a, rand_nb + 1);
    lcd.write(byte(3));
    lcd.write(byte(4));
    lcd.write(byte(5));
    if (a < 13)
    {
      if (rand_nb == 2)
      {
        lcd.setCursor(a, rand_nb2);
        lcd.print(humidity);
        lcd.print(" ");
        lcd.print("%h");
      }
      if (rand_nb == 0)
      {
        lcd.setCursor(a, rand_nb3);
        lcd.print(humidity);
        lcd.print(" ");
        lcd.print("%h");
      }
    }
    delay(500);
    lcd.clear();
  }

}


void veille_3()
{
  int a;
  int rand_nb;


  for (a = 0; a < 18; a++)
  {
    rand_nb = random(3);
    lcd.setCursor(a, rand_nb);
    lcd.write(byte(0));
    lcd.write(byte(1));
    lcd.write(byte(2));
    lcd.setCursor(a, rand_nb + 1);
    lcd.write(byte(3));
    lcd.write(byte(4));
    lcd.write(byte(5));
    delay(500);
    lcd.clear();
  }
  for (a = 17; a >= 0; a--)
  {
    rand_nb = random(3);
    lcd.setCursor(a, rand_nb);
    lcd.write(byte(0));
    lcd.write(byte(1));
    lcd.write(byte(2));
    lcd.setCursor(a, rand_nb + 1);
    lcd.write(byte(3));
    lcd.write(byte(4));
    lcd.write(byte(5));
    delay(500);
    lcd.clear();
  }

}

void veille_1()
{
  int a;

  for (a = 0; a < 18; a++)
  {
    float temperature = dht.getTemperature();
    lcd.setCursor(a, 1);
    lcd.write(byte(0));
    lcd.write(byte(1));
    lcd.write(byte(2));
    lcd.setCursor(a, 2);
    lcd.write(byte(3));
    lcd.write(byte(4));
    lcd.write(byte(5));
    lcd.setCursor(12, 3);
    lcd.print(temperature);
    lcd.print(" ");
    lcd.print(char(223));
    lcd.print("C");
    delay(500);
    lcd.clear();
  }
  for (a = 17; a >= 0; a--)
  {
    float humidity = dht.getHumidity();
    lcd.setCursor(a, 1);
    lcd.write(byte(0));
    lcd.write(byte(1));
    lcd.write(byte(2));
    lcd.setCursor(a, 2);
    lcd.write(byte(3));
    lcd.write(byte(4));
    lcd.write(byte(5));
    lcd.setCursor(0, 3);
    lcd.print(humidity);
    lcd.print(" ");
    lcd.print("%h");
    delay(500);
    lcd.clear();
  }
}

void veille_2()
{
  int a;
  lcd.clear();
  lcd.setCursor(9, 2);
  lcd.write(byte(0));
  lcd.write(byte(1));
  lcd.write(byte(2));
  lcd.setCursor(9, 3);
  lcd.write(byte(3));
  lcd.write(byte(4));
  lcd.write(byte(5));


  for (a = 0; a < 13; a++)
  {

    float temperature = dht.getTemperature();
    float humidity = dht.getHumidity();

    if (a >= 1)
    {
      lcd.setCursor(a - 1, 0);
      lcd.print(" ");
      lcd.setCursor(a - 1, 1);
      lcd.print(" ");
    }
    lcd.setCursor(a, 0);
    lcd.print(temperature);
    lcd.print(" ");
    lcd.print(char(223));
    lcd.print("C");
    lcd.print(" ");
    lcd.setCursor(12 - a, 1);
    lcd.print(humidity);
    lcd.print(" ");
    lcd.print("%h");
    lcd.print(" ");

    delay(500);
  }
  for (a = 0; a < 13; a++)
  {
    float temperature = dht.getTemperature();
    float humidity = dht.getHumidity();

    if (a >= 1)
    {
      lcd.setCursor(a - 1, 0);
      lcd.print(" ");
      lcd.setCursor(a - 1, 1);
      lcd.print(" ");
    }
    lcd.setCursor(12 - a, 0);
    lcd.print(temperature);
    lcd.print(" ");
    lcd.print(char(223));
    lcd.print("C");
    lcd.print(" ");
    lcd.setCursor(a, 1);
    lcd.print(humidity);
    lcd.print(" ");
    lcd.print("%h");
    lcd.print(" ");
    delay(500);
  }
  lcd.clear();

}

void putstr_center(char *str, int row)
{
  int col;
  char error[] = "error 42";

  col = strlen(str);
  col = 10 - (col / 2);
  if (strlen(str) > 20)
  {
    putstr_center(error, 1);
  }
  else
  {
    lcd.setCursor(col, row);
    lcd.print(str);
  }
}

void  putstr_delay(char *str, int Delay)
{
  int a;
  a = 0;
  while (str[a] != '\0')
  {
    lcd.print(str[a]);
    a++;
    delay(Delay);
  }
}

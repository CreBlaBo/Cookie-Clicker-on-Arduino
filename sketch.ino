#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

long cookies = 0;
int clickmulti = 1;
int clicklock = 0;
int clicker = 0;
int granny = 0;
int upgradetimer = 0;
int pricemulti = 200;
int priceclicker = 50;
int pricegranny = 150;
int cursor = 13;
int buttonmulti = 3;
int buttonclicker = 2;
int buttongranny = 4;

void setup() 
{
  Serial.begin(9600);

  lcd.init();
  lcd.backlight();
  
  pinMode(cursor, INPUT); //Cookie Clicker button
  pinMode(buttonmulti, INPUT);  //Multiplier shop
  pinMode(buttonclicker, INPUT);  //Clicker shop
  pinMode(buttongranny, INPUT);  //Granny shop

  lcd.setCursor(0, 0);
  lcd.print("Cookie Clicker");
  lcd.setCursor(0, 1);
  lcd.print("V1.0");
  delay(2000);
  lcd.init();
}


void loop() 
{
  //Displays all the information there is to display
  Serial.println(upgradetimer);
  //Shows Current Cookies
  lcd.setCursor(0, 0);
  lcd.print("Cookies:");
  lcd.setCursor(8, 0);
  lcd.print(cookies);
  //Shows Multiplier
  lcd.setCursor(0, 1);
  lcd.print("M:");
  lcd.setCursor(2, 1);
  lcd.print(clickmulti);
  //Shows Clickers
  lcd.setCursor(5, 1);
  lcd.print("C:");
  lcd.setCursor(7, 1);
  lcd.print(clicker);
  //Shows Grannys
  lcd.setCursor(11, 1);
  lcd.print("G:");
  lcd.setCursor(13, 1);
  lcd.print(granny);


  //Adds Cookie(s) once you click the button
  if(digitalRead(cursor)==HIGH)
  {
    if(clicklock==0)  //Prevents the counter to add multiple Cookies that shouldnt be added with a single button presss
    {
      cookies = cookies + clickmulti;
      clicklock = clicklock + 1;
    }
    else
    {
    }
  }
  else
  {
    clicklock = 0;
  }


  //Shop to buy things
  //Multiplier
  if(digitalRead(buttonmulti)==HIGH)
  {
    if(cookies>=pricemulti)
    {
      clickmulti = clickmulti + 1;
      cookies = cookies - pricemulti;
      pricemulti = pricemulti * 1.5;
      lcd.setCursor(8, 0);
      lcd.print("        ");
      lcd.setCursor(8, 0);
      lcd.print(cookies);
      lcd.setCursor(0, 1);
      lcd.print("                ");
      lcd.setCursor(0, 1);
      lcd.print("Upgraded Cursor!");
      delay(1000);
      lcd.setCursor(0, 1);
      lcd.print("                ");
    }
    else
    {
      lcd.setCursor(0, 0);
      lcd.print("                ");
      lcd.setCursor(0, 1);
      lcd.print("                ");
      lcd.setCursor(0, 0);
      lcd.print("Too Expensive!");
      lcd.setCursor(0, 1);
      lcd.print("Price:");
      lcd.setCursor(7, 1);
      lcd.print(pricemulti);
      delay(1000);
      lcd.setCursor(0, 0);
      lcd.print("                ");
      lcd.setCursor(0, 1);
      lcd.print("                ");
    }
  }
  else
  {
  }

  //Clicker
  if(digitalRead(buttonclicker)==HIGH)
  {
    if(cookies>=priceclicker)
    {
      clicker = clicker + 1;
      cookies = cookies - priceclicker;
      priceclicker = priceclicker * 1.5;
      lcd.setCursor(8, 0);
      lcd.print("        ");
      lcd.setCursor(8, 0);
      lcd.print(cookies);
      lcd.setCursor(0, 1);
      lcd.print("                ");
      lcd.setCursor(0, 1);
      lcd.print("Upgraded Clickr!");
      delay(1000);
      lcd.setCursor(0, 1);
      lcd.print("                ");
    }
    else
    {
      lcd.setCursor(0, 0);
      lcd.print("                ");
      lcd.setCursor(0, 1);
      lcd.print("                ");
      lcd.setCursor(0, 0);
      lcd.print("Too Expensive!");
      lcd.setCursor(0, 1);
      lcd.print("Price:");
      lcd.setCursor(7, 1);
      lcd.print(priceclicker);
      delay(1000);
      lcd.setCursor(0, 0);
      lcd.print("                ");
      lcd.setCursor(0, 1);
      lcd.print("                ");
    }
  }
  else
  {
  }

  //Granny
  if(digitalRead(buttongranny)==HIGH)
  {
    if(cookies>=pricegranny)
    {
      granny = granny + 1;
      cookies = cookies - pricegranny;
      pricegranny = pricegranny * 1.5;
      lcd.setCursor(8, 0);
      lcd.print("        ");
      lcd.setCursor(8, 0);
      lcd.print(cookies);
      lcd.setCursor(0, 1);
      lcd.print("                ");
      lcd.setCursor(0, 1);
      lcd.print("Upgraded Granny!");
      delay(1000);
      lcd.setCursor(0, 1);
      lcd.print("                ");
    }
    else
    {
      lcd.setCursor(0, 0);
      lcd.print("                ");
      lcd.setCursor(0, 1);
      lcd.print("                ");
      lcd.setCursor(0, 0);
      lcd.print("Too Expensive!");
      lcd.setCursor(0, 1);
      lcd.print("Price:");
      lcd.setCursor(7, 1);
      lcd.print(pricegranny);
      delay(1000);
      lcd.setCursor(0, 0);
      lcd.print("                ");
      lcd.setCursor(0, 1);
      lcd.print("                ");
    }
  }
  else
  {
  }


  //Adds extra cookies if you buy PowerUps without user clicking button
  if(upgradetimer>=25)
  {
    upgradetimer = 0;
    cookies = cookies + (granny + 0) * 2;
    cookies = cookies + clicker;
  }
  else
  {
    upgradetimer = upgradetimer + 1;
  }


  delay(1); //Delay to tell time by counting code cycles
}

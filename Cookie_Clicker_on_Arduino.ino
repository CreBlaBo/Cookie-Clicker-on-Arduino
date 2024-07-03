#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);


////Setting up all required Variables////

long cookies = 0;       //Counts cookies
int clickmulti = 1;     //Amount of click multiplier
int clicker = 0;        //Amount of clickers
int granny = 0;         //Amount of grannys
int clicklock = 0;      //Prevents a single button press to give more cookies than its supposed to give
long pricemulti = 200;  //Price for a multiplier
long priceclicker = 50; //Price for a clicker
long pricegranny = 150; //Price for a granny
int cursor = 13;        //Button for getting cookies
int buttonmulti = 3;    //Shop button for buying multiplier
int buttonclicker = 2;  //Shop button for buying clicker
int buttongranny = 4;   //Shop button for buying grannys
long upgradetimer = 0;  //Counts time
long time = 0;          //Time itself


////Custom symbol////

byte cookie[] = 
{
  B00000,
  B01110,
  B10111,
  B11101,
  B11011,
  B01110,
  B00000,
  B00000
};


void setup() //Setup
{
  Serial.begin(9600); //Opening the serial monitor


  ////Starting LCD////

  lcd.init();
  lcd.backlight();
  

  ////Setting up pin modes////

  pinMode(cursor, INPUT); //Cookie Clicker button
  pinMode(buttonmulti, INPUT);  //Multiplier shop
  pinMode(buttonclicker, INPUT);  //Clicker shop
  pinMode(buttongranny, INPUT);  //Granny shop


  ////Intro////

  lcd.setCursor(0, 0);
  lcd.print("Cookie Clicker");
  lcd.setCursor(0, 1);
  lcd.print("V1.1      By Cre");
  lcd.createChar(1,cookie);
  lcd.setCursor(15, 0);
  lcd.write(1);
  delay(2000);
  lcd.setCursor(0, 0);
  lcd.print("                ");
  lcd.setCursor(0, 1);
  lcd.print("                ");
}

void loop() //Loop
{
  time = millis();        //Time itself
  Serial.println(time);   //Just for displaying some debug info


  ////Displays all the information there is to display////
  
      //Shows Current Cookies//

  lcd.setCursor(0, 0);
  lcd.print("Cookies:");
  lcd.setCursor(8, 0);
  lcd.print(cookies);
  lcd.setCursor(15, 0);
  lcd.write(1);
  
      //Shows Multiplier//

  lcd.setCursor(0, 1);
  lcd.print("M:");
  lcd.setCursor(2, 1);
  lcd.print(clickmulti);
  
      //Shows Clickers//

  lcd.setCursor(5, 1);
  lcd.print("C:");
  lcd.setCursor(7, 1);
  lcd.print(clicker);
  
      //Shows Grannys//

  lcd.setCursor(11, 1);
  lcd.print("G:");
  lcd.setCursor(13, 1);
  lcd.print(granny);


  ////Adds Cookie(s) once you click the button////

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


  ////Shop to buy things////

      //Multiplier//
  
  if(digitalRead(buttonmulti)==HIGH)
  {
    if(cookies>=pricemulti)
    {
      clickmulti = clickmulti + 1;
      cookies = cookies - pricemulti;
      pricemulti = pricemulti * 1.3;
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

      //Clicker//
  
  if(digitalRead(buttonclicker)==HIGH)
  {
    if(cookies>=priceclicker)
    {
      clicker = clicker + 1;
      cookies = cookies - priceclicker;
      priceclicker = priceclicker * 1.3;
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

      //Granny//

  if(digitalRead(buttongranny)==HIGH)
  {
    if(cookies>=pricegranny)
    {
      granny = granny + 1;
      cookies = cookies - pricegranny;
      pricegranny = pricegranny * 1.3;
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


  ////Adds extra cookies if you buy PowerUps without user clicking button////

  time = time - upgradetimer;

  if(time>=1000)
  {
    upgradetimer = upgradetimer + 1000;
    cookies = cookies + (granny + 0) * 2;
    cookies = cookies + clicker;
  }
  else
  {
  }

}

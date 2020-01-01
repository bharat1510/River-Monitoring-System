  #include <Keypad.h>
   
  #include <LiquidCrystal.h> 

  LiquidCrystal lcd(A0,A1,A2,A3,A4,A5);

  const byte ROWS = 4; // Four rows

  const byte COLS = 4; // Four columns

  char keys[ROWS][COLS] = 

  {
  {'1','2','3','A'},


  {'4','5','6','B'},
  
  
  {'7','8','9','C'},

   
  {'*','0','#','D'}

  };

  byte rowPins[ROWS] = { 9,8,7,6 };
  
  byte colPins[COLS] = { 5,4,3,2 }; 

  int tempreture=0,ph=0,tds=0,turbidity=0;

  char temstr[3]={0},phstr[3]={0},tdsstr[3]={0},turstr[3]={0};

  Keypad kpd = Keypad( makeKeymap(keys), rowPins,
  colPins, ROWS, COLS );

 int getNumber(char s[],int k)
{
  lcd.setCursor(0,1);
    lcd.print(s);
   
   int num = 0,i=0;
   char key = kpd.getKey();
   while(key != '#')
   {
      switch (key)
      {
         case NO_KEY:
            break;

         case '0': case '1': case '2': case '3': case '4':
         case '5': case '6': case '7': case '8': case '9':
            lcd.print(key);
            num = num * 10 + (key - '0');
            if(k==1)
              temstr[i]=key;
            if(k==2)
              phstr[i]=key;
            if(k==3)
              tdsstr[i]=key;
            if(k==4)
              turstr[i]=key;
            i++;
            break;

         case '*':
            num = 0;
            lcd.clear();
            break;
      }

      key = kpd.getKey();
   }

   return num;
}

void clearSec(){
  lcd.setCursor(0,1);
  for(int i=0;i<16;i++)
    lcd.print(' ');
   lcd.setCursor(0,1);
}
  void setup() 

  {

  Serial.begin(9600);
  lcd.begin(16, 2);

   
  lcd.print("  RIVER WATER");
  lcd.setCursor(0,1);
  lcd.print("MONITOR SYSTEM");
  delay(2000);
  lcd.clear();
  lcd.print("  ENTER DATA");
  lcd.setCursor(0,1);
 
  }

  void loop() 

  {
   

  clearSec();
  tempreture = getNumber("TEMPRETURE:",1);
  Serial.println(tempreture);
  clearSec();
  ph = getNumber("pH:",2);
  Serial.println(ph);
  clearSec();
  tds = getNumber("TDS:",3);
  Serial.println(tds);
  clearSec();
  turbidity = getNumber("turbidity:",4);
  Serial.println(turbidity);
  lcd.clear();
  lcd.print("PROCESSING...........");
  delay(10000);
  lcd.clear();
  lcd.print("  ENTER DATA");
}

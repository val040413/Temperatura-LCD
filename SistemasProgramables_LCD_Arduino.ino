//Mario Javier Cadena Cabrera

#include <LiquidCrystal.h>
#define red 10
#define green 9
#define blue 8
#define rele 11
#define frio 15
#define templado 20

LiquidCrystal lcd(7, 6, 5, 4, 3, 2); 
String messaje="";

void setup(){


  pinMode(red,OUTPUT);
  pinMode(green,OUTPUT);
  pinMode(blue,OUTPUT);
  pinMode(rele,OUTPUT);
  digitalWrite(rele,LOW);
  lcd.begin(16, 2); 
  lcd.print("Clima C=");
  Serial.begin(9600);
}

void loop(){
  int caracters = 0;
  float c = to_celcius();

  if(c <= frio) digitalWrite(rele,LOW);
  else digitalWrite(rele,HIGH);
  
  
  if(c <= frio)
  {
    digitalWrite(red,LOW);
    digitalWrite(green,LOW);
    digitalWrite(blue,HIGH);
  }
  else if(c > frio && c<= templado)
  {
    digitalWrite(red,LOW);
    digitalWrite(green,HIGH);
    digitalWrite(blue,LOW);
  }
  else if(c > templado)
  {
    digitalWrite(red,HIGH);
    digitalWrite(green,LOW);
    digitalWrite(blue,LOW);
  }
  lcd.setCursor(9,0);
  lcd.print(c); 
   
  messaje=""; 
  lcd.clear();
  Serial.print(messaje+"aqui estoy");
  
  while (Serial.available()>0)
  {       
      messaje=messaje+Decimal_to_ASCII(Serial.read()); 
  }

  caracters = messaje.length(); 
  
  if (messaje!="")
  {
    lcd.setCursor(0,0);
    lcd.print("Clima C=");
    lcd.setCursor(10,0);
    lcd.print(c); 
    lcd.setCursor(0,1);
    lcd.print(messaje);
  }

  for (int i = 0; i < messaje.length(); i++) 
  {
    lcd.scrollDisplayLeft();
    delay(250);
  }
  for (int i = 0; i < messaje.length(); i++) 
  {
    lcd.scrollDisplayRight();
    delay(250);
  }
  delay(1000);
}

float to_celcius()
{
  int dataLM35 = analogRead(A0);
  float c = (500.0 * dataLM35)/1023;
  return (c);
}
 
char Decimal_to_ASCII(int entrada){
  char salida=' ';
  switch(entrada){
  case 32: 
  salida=' '; 
  break; 
  case 33: 
  salida='!'; 
  break; 
  case 34: 
  salida='"'; 
  break; 
  case 35: 
  salida='#'; 
  break; 
  case 36: 
  salida='$'; 
  break; 
  case 37: 
  salida='%'; 
  break; 
  case 38: 
  salida='&'; 
  break; 
  case 39: 
  salida=' '; 
  break; 
  case 40: 
  salida='('; 
  break; 
  case 41: 
  salida=')'; 
  break; 
  case 42: 
  salida='*'; 
  break; 
  case 43: 
  salida='+'; 
  break; 
  case 44: 
  salida=','; 
  break; 
  case 45: 
  salida='-'; 
  break; 
  case 46: 
  salida='.'; 
  break; 
  case 47: 
  salida='/'; 
  break; 
  case 48: 
  salida='0'; 
  break; 
  case 49: 
  salida='1'; 
  break; 
  case 50: 
  salida='2'; 
  break; 
  case 51: 
  salida='3'; 
  break; 
  case 52: 
  salida='4'; 
  break; 
  case 53: 
  salida='5'; 
  break; 
  case 54: 
  salida='6'; 
  break; 
  case 55: 
  salida='7'; 
  break; 
  case 56: 
  salida='8'; 
  break; 
  case 57: 
  salida='9'; 
  break; 
  case 58: 
  salida=':'; 
  break; 
  case 59: 
  salida=';'; 
  break; 
  case 60: 
  salida='<'; 
  break; 
  case 61: 
  salida='='; 
  break; 
  case 62: 
  salida='>'; 
  break; 
  case 63: 
  salida='?'; 
  break; 
  case 64: 
  salida='@'; 
  break; 
  case 65: 
  salida='A'; 
  break; 
  case 66: 
  salida='B'; 
  break; 
  case 67: 
  salida='C'; 
  break; 
  case 68: 
  salida='D'; 
  break; 
  case 69: 
  salida='E'; 
  break; 
  case 70: 
  salida='F'; 
  break; 
  case 71: 
  salida='G'; 
  break; 
  case 72: 
  salida='H'; 
  break; 
  case 73: 
  salida='I'; 
  break; 
  case 74: 
  salida='J'; 
  break; 
  case 75: 
  salida='K'; 
  break; 
  case 76: 
  salida='L'; 
  break; 
  case 77: 
  salida='M'; 
  break; 
  case 78: 
  salida='N'; 
  break; 
  case 79: 
  salida='O'; 
  break; 
  case 80: 
  salida='P'; 
  break; 
  case 81: 
  salida='Q'; 
  break; 
  case 82: 
  salida='R'; 
  break; 
  case 83: 
  salida='S'; 
  break; 
  case 84: 
  salida='T'; 
  break; 
  case 85: 
  salida='U'; 
  break; 
  case 86: 
  salida='V'; 
  break; 
  case 87: 
  salida='W'; 
  break; 
  case 88: 
  salida='X'; 
  break; 
  case 89: 
  salida='Y'; 
  break; 
  case 90: 
  salida='Z'; 
  break; 
  case 91: 
  salida='['; 
  break; 
  case 92: 
  salida=' '; 
  break; 
  case 93: 
  salida=']'; 
  break; 
  case 94: 
  salida='^'; 
  break; 
  case 95: 
  salida='_'; 
  break; 
  case 96: 
  salida='`'; 
  break; 
  case 97: 
  salida='a'; 
  break; 
  case 98: 
  salida='b'; 
  break; 
  case 99: 
  salida='c'; 
  break; 
  case 100: 
  salida='d'; 
  break; 
  case 101: 
  salida='e'; 
  break; 
  case 102: 
  salida='f'; 
  break; 
  case 103: 
  salida='g'; 
  break; 
  case 104: 
  salida='h'; 
  break; 
  case 105: 
  salida='i'; 
  break; 
  case 106: 
  salida='j'; 
  break; 
  case 107: 
  salida='k'; 
  break; 
  case 108: 
  salida='l'; 
  break; 
  case 109: 
  salida='m'; 
  break; 
  case 110: 
  salida='n'; 
  break; 
  case 111: 
  salida='o'; 
  break; 
  case 112: 
  salida='p'; 
  break; 
  case 113: 
  salida='q'; 
  break; 
  case 114: 
  salida='r'; 
  break; 
  case 115: 
  salida='s'; 
  break; 
  case 116: 
  salida='t'; 
  break; 
  case 117: 
  salida='u'; 
  break; 
  case 118: 
  salida='v'; 
  break; 
  case 119: 
  salida='w'; 
  break; 
  case 120: 
  salida='x'; 
  break; 
  case 121: 
  salida='y'; 
  break; 
  case 122: 
  salida='z'; 
  break; 
  case 123: 
  salida='{'; 
  break; 
  case 124: 
  salida='|'; 
  break; 
  case 125: 
  salida='}'; 
  break; 
  case 126: 
  salida='~'; 
  break; 
  }
  return salida;
 }

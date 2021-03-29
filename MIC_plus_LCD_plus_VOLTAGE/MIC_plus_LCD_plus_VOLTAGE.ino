#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

//LCD
// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);

int MIC = 2;
int LED = 3;
int VALOR;
int ESTADO;

void setup()
{
  // initialize the LCD
  lcd.begin();

  pinMode(MIC, INPUT);
  pinMode(LED, OUTPUT);

}

void loop()
{
  
  VALOR = digitalRead(MIC);
  if (VALOR == HIGH) {
    ESTADO = digitalRead(LED);
    digitalWrite(LED, !ESTADO);

    
    
    if(ESTADO){
      lcd.clear(); //limpia la pantalla LCD
      lcd.print("ENCENDIDO"); //imprime primer renglon del LCD
    }else{
      lcd.clear(); //limpia la pantalla LCD
      lcd.print("APAGADO");
    }
      
    delay(1000);
  }
 
}

#include <LiquidCrystal.h>
#include <Keypad.h>


const byte FILAS = 4;    
const byte COLUMNAS = 3; 

char keys[FILAS][COLUMNAS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};


byte rowPins[FILAS] = {9, 8, 7, 6}; 
byte colPins[COLUMNAS] = {5, 4, 3}; 

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, FILAS, COLUMNAS);


LiquidCrystal lcd(A0, A1, A2, A3, A4, A5);

String textoIngresado = ""; 

void setup() {
  lcd.begin(16, 2);
  lcd.print("Teclado Listo");
  delay(1500);
  
  actualizarPantalla();
}

void loop() {
  char tecla = keypad.getKey(); 

  if (tecla) {
    if (tecla == '*') {
      
      textoIngresado = "";
    } 
    else if (tecla == '#') {
      
      if (textoIngresado.length() > 0) {
        textoIngresado.remove(textoIngresado.length() - 1);
      }
    } 
    else {
     
      if (textoIngresado.length() < 16) {
        textoIngresado += tecla;
      }
    }

   
    actualizarPantalla();
  }
}


void actualizarPantalla() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Valor:");
  lcd.setCursor(0, 1);
  lcd.print(textoIngresado);
}

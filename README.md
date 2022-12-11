# Como utilizar un digispark para que actue como RubberDucky 

Este script de DigiSpark descarga y ejecuta el script de PowerShell Invoke-PowerShellTcpOneLine.ps1 que esencialmente abre una shell inversa de netcat desde una máquina con Windows a la computadora host en aproximadamente en 5 segundos. 

# Intrucciones:
# En la máquina host (supongo que está usando Kali Linux para esto):

1. Descargar Drivers para el controlador Attiny85 junto con el IDE de arduino

Link Drivers : https://kawaii-tech.com/instalando-drivers-para-digispark-2/

Arduino IDE : https://www.arduino.cc/en/software

2. Descargar libreria en español para Digikeyboard y el teclado lo reconozca en dicho idioma (Solo seguir los pasos que mencionan en este repositorio)

Link Libreria : https://github.com/ernesto-xload/DigisparkKeyboard/blob/master/Readme.md

3. Abra un oyente de netcat en un puerto (el script usa el puerto 443 de forma predeterminada puede modificar el puerto):```nc -nlvp 443``` 

4. Descargue y modifique ```Invoke-PowerShellTcpOneLine.ps1``` eliminando el comentario de la primera línea y cambiando la dirección IP a la de su máquina host y el puerto al que eligió anteriormente.

5. Ahora necesita alojar la carga útil en un servidor web para que pueda descargarse en la computadora con Windows. En un servidor coloque el script donde se hara la shell inversa en mi caso use un pastebin donde colocarlo(Invoke-PowerShellTcpOneLine.ps1)

6. Descargar y editar el ```Reverse_Shell.ino```Secuencia de comandos de DigiSpark para que coincida con la dirección donde se aloja la secuencia de comandos de PowerShell de ps1 y se compila y carga Reverse_Shell.ino su DigiSpark.



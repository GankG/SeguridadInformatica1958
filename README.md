Keylogger
Trabajo de Ryan Monroy Picazo para la materia de Seguridad Informática
Este proyecto consiste en un keylogger básico programado en lenguaje C. El propósito del programa es capturar las pulsaciones de teclas en un entorno Linux y guardarlas en un archivo de registro. Este keylogger ha sido desarrollado con fines exclusivamente educativos y debe ser utilizado únicamente en entornos controlados.

Contenidos
Requisitos
Instrucciones de Uso
Supuestos del Programa
Casos de Uso
Advertencias Legales
Requisitos
Sistema Operativo: Linux (se ha probado en Ubuntu)
Compilador: GCC
Permisos: Es necesario tener permisos de superusuario para acceder al dispositivo de entrada del teclado.
Instrucciones de Uso
Compilación
Para compilar el programa, asegúrate de contar con GCC instalado en tu sistema. Luego, abre una terminal y ejecuta el siguiente comando:

bash
Copiar código
gcc Keylogger.c -o Keylogger
Ejecución
Debido a que el programa necesita acceder a dispositivos de entrada que requieren permisos elevados, es necesario ejecutarlo como superusuario:

bash
Copiar código
sudo ./Keylogger
Una vez iniciado, el keylogger comenzará a registrar todas las pulsaciones de teclas en un archivo de log ubicado en /tmp/keylogger.txt.

Visualización del Log
En cualquier momento, puedes revisar el contenido del archivo de log utilizando el siguiente comando:

bash
Copiar código
cat /tmp/keylogger.txt
Detener el Programa
Para detener la ejecución del keylogger, puedes presionar Ctrl + C en la terminal donde se está ejecutando. Alternativamente, si el programa se está ejecutando en segundo plano, puedes detenerlo utilizando comandos como kill.

Supuestos del Programa
Dispositivo del Teclado: El programa asume que el dispositivo de entrada del teclado está correctamente identificado y es accesible en /dev/input/eventX.
Formato del Log: El archivo de registro guardará cada tecla presionada en un formato fácilmente comprensible. Las teclas especiales como ENTER, BACKSPACE y SHIFT aparecerán representadas por etiquetas como [ENTER] o [SHIFT].
Entorno Controlado: Este programa está diseñado para ejecutarse en un entorno controlado, como una máquina virtual con fines educativos.
Casos de Uso
Educación y Seguridad: Este keylogger puede ser utilizado para comprender el funcionamiento de los keyloggers y cómo proteger un sistema frente a ellos.
Auditoría de Seguridad: Es útil en entornos de prueba para verificar la seguridad de un sistema y estudiar métodos de detección de keyloggers.
Desarrollo de Software: Los desarrolladores pueden utilizar este código como base para crear herramientas de monitoreo de teclas en sistemas Linux.
Advertencias Legales
Este software ha sido creado con fines educativos y no debe utilizarse para monitorear teclados sin el consentimiento del usuario. El uso de keyloggers en entornos no autorizados es ilegal y antiético. El autor no se hace responsable del mal uso de este software.

Créditos
Este proyecto no habría sido posible sin la ayuda de las siguientes personas y recursos:

ChatGPT: Asistencia en la creación del README.
Documentación de Linux: Referencia utilizada para comprender el manejo de eventos de entrada.
Artículo de ItsFOSS: Guía utilizada para compilar en Ubuntu.
Stack Overflow: Plataforma de preguntas y respuestas que proporcionó soluciones a problemas específicos durante el desarrollo.
Clase del profesor Daniel Fernando Palma López: Materia de Seguridad Informática.

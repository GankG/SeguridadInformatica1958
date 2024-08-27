Nexus Mods Phishing Education Project
Este proyecto es una réplica educativa de la página de inicio de sesión de Nexus Mods, diseñada para enseñar a los usuarios sobre los peligros del phishing. Este ejemplo incluye un sistema de CAPTCHA, animaciones y otras técnicas que suelen emplearse en ataques de phishing reales. Es importante destacar que este proyecto es solo con fines educativos y no debe usarse para actividades malintencionadas.

Índice
Descripción
Funcionalidades
Requisitos
Instalación
Uso
Consideraciones
Casos de Uso
Asunciones
Referencias Legales
Licencia
Descripción
Este proyecto recrea la página de inicio de sesión de Nexus Mods para educar a los usuarios sobre cómo los ciberdelincuentes pueden intentar robar credenciales mediante técnicas de phishing. El proyecto incluye elementos interactivos como un sistema CAPTCHA y la simulación de una redirección a una página engañosa tras un inicio de sesión "exitoso".

Funcionalidades
Formulario de Inicio de Sesión: Simulación del formulario de inicio de sesión de Nexus Mods.
Sistema de CAPTCHA: Verificación del usuario mediante un botón que simula la funcionalidad de "No soy un robot".
Redirección a una Página de Engaño: Tras la supuesta autenticación, los usuarios son redirigidos a una página con una imagen y sonido de "KEKW" como demostración.
Guardado de Datos en Google Drive: Los datos ingresados se guardan en un archivo de texto en Google Drive.
Botón de Retorno: Permite volver al ejemplo de phishing tras la redirección.
Requisitos
Un navegador moderno (Chrome, Firefox, Edge).
Cuenta de Google para la configuración del script de Google Apps.
Conexión a Internet.
Instalación
Clona el repositorio:

bash
Copiar código
git clone https://github.com/tu_usuario/nexus-mods-phishing.git
Navega a la carpeta del proyecto:

bash
Copiar código
cd nexus-mods-phishing
Configura Google Apps Script:

Crea un nuevo script en Google Apps y copia el código correspondiente para guardar los datos en Google Drive.
Autoriza la ejecución del script y actualiza la URL en el archivo script.js.
Configura tu entorno local:

Coloca los archivos kekw.png y kekw.mp3 en el directorio raíz del proyecto.
Abre index.html en un navegador web para probar la página.
Uso
Abre index.html en tu navegador.
Ingresa un email o nombre de usuario y una contraseña en el formulario.
Completa la verificación del CAPTCHA.
Haz clic en el botón de inicio de sesión, lo que redirigirá a la página de engaño con la imagen y sonido "KEKW".
Consideraciones
Propósito Educativo: Este proyecto está diseñado exclusivamente para la educación sobre la ciberseguridad y no debe ser utilizado con fines maliciosos.
Google Apps Script: Asegúrate de que los permisos de Google Apps Script están correctamente configurados para evitar problemas de CORS.
Comportamiento Realista: El sistema CAPTCHA y la redirección imitan el comportamiento de sistemas de phishing reales para educar a los usuarios sobre estos riesgos.
Casos de Uso
Educación sobre Ciberseguridad: Utilizado en cursos o talleres para demostrar cómo funciona un ataque de phishing.
Simulaciones de Phishing: Crear entornos seguros donde los usuarios puedan aprender a identificar intentos de phishing.
Entrenamiento de Personal: Capacitar a empleados sobre la importancia de no ingresar información personal en sitios no verificados.
Asunciones
Autenticidad de los Datos: El proyecto asume que los usuarios ingresan información real en el formulario de inicio de sesión, pero esta no se usa para nada más que fines educativos.
Redirección Exitosa: Se asume que la redirección a la página de "KEKW" funcionará correctamente en cualquier entorno de navegador.
Acceso a Internet: Se requiere conexión a internet para la funcionalidad de Google Apps Script.
Referencias Legales
Este proyecto está protegido bajo las leyes de derechos de autor y se distribuye bajo los términos de la Licencia MIT. Al usar este proyecto, el usuario se compromete a no utilizarlo para actividades maliciosas ni para la recopilación de datos personales sin el consentimiento explícito de las personas involucradas.

Ley de Protección de Datos Personales y Garantía de los Derechos Digitales (LOPD-GDD)
General Data Protection Regulation (GDPR)
Licencia
Este proyecto está licenciado bajo la Licencia MIT. Consulta el archivo LICENSE para obtener más detalles.

# P9-Patrones

## Descripcion final del sistema

El sistema esta compuesto por tres bloques principales: los sensores simulados, la base de datos de usuarios, y la interfaz de usuario.

![Captura de pantalla de 2023-01-18 23-14-35](https://user-images.githubusercontent.com/90764534/213307165-a1ab8f21-644d-476a-b060-b91066562807.png)

### Sensores

La simulacion de sensores tiene una clase básica Sensor, que utiliza rand() para generar numeros aleatorios entre los valores definidos para el sensor. De esa clase derivan cuatro sensores diseñados para generar e interpretar los datos especificos Calidad de Aire, Temperatura, Humdead e Iluminacion. Estas clases derivadas tienen su propia forma de imprimir informacion por pantalla, especifica con las unidades y el formato concreto. Además, tienen una funcion dataCheck() que proporciona al usuario informacion adicional sobre los datos "medidos" por el sensor.


![inherit_graph_5](https://user-images.githubusercontent.com/90764534/213307592-11e98078-b4c9-40c2-81c3-5b83c9858e88.png)

### Database

Por otra parte, la base de datos esta implementada con una estructura de datos set, de objetos de clase Cuenta. La clase Cuenta tiene sus atributos privados, de forma que solo se pueden leer llamando a sus funciones que los muestran, y solo se pueden modificar accediendo a las funciones que los manejan. De estas funciones, las cuentas normales solo tienen login() y logoff(), mientras que las cuentas de administrador además tienen acceso a las funciones changeName() y changePassword().

![admin_8cpp__incl](https://user-images.githubusercontent.com/90764534/213308660-53e7c10d-beff-4ea2-88f4-6464e5348b13.png)


La base de datos se encarga de administrar este set de cuentas, usando un fichero para generarlo al inicializarse, escribiendo en ese fichero, añadiendo cuentas al set, modificándolas o eliminándolas segun requiera el usuario. Para realizar todas estas acciones correctamente durante la ejecución del programa, la base de datos tiene el atributo Actual, una cuenta proxy donde realiza todas las modificaciones antes de aplicarlas al set, y donde monitoriza el estado del usuario como si la sesion esta inciada, o el usuario posee permisos de administrador.

![database_8cpp__incl](https://user-images.githubusercontent.com/90764534/213307745-be7f6cf5-5299-4f39-81e8-31d74dedfd2e.png)

### Interfaz

El usuario no accede a la base de datos directamente, sino que usa una clase interfaz, que se encarga de mostrar por pantalla la información que el usuario solicite/requiera, y que transmite a la base de datos y al menu manager las instrucciones del usuario. Esta clase se encarga de imprimir mensajes por pantalla, y de guiar al usuario en su interacción con el programa. Muestra menús, solicita inputs, y muestra informacion relativa a la base de datos y el estado del usuario.

Finalmente, el menu manager es una clase que implementa la lógica de navegación por los tres menús del programa. El menú de inicio de sesión, el menú de sensores, y el menú de administrador. Mediante la información que recibe de la interfaz, determina que menú mostrar. Si la sesión no esta iniciada, navega por el menu de inicio de sesión. Una vez se inicia sesión, el usuario accede al menú de sensores, y si el usuario es administrador y desea acceder al menú de administrador, se le da acceso. Los inputs numéricos del usuario a traves de la interfaz determinan la navegación por los menús, y el menu manager llama a funciones de la interfaz o los sensores para realizar las acciones que el usuario solicita.

![classmenuManager__coll__graph](https://user-images.githubusercontent.com/90764534/213308399-b01ca820-1e03-4cc0-9be8-1b686bd865e1.png)

De esta forma, el usuario puede interactuar con el programa fácil e intuitivamente, ya que toda la información necesaria se le mostrará en pantalla, y el programa comunica en todo momento las acciones que disponibles. Además, el programa informará al usuario de cualquier uso erróneo.

## Descripción de los patrones de diseño implementados

En este proyecto he implementado varios patrones de diseño, siendo los más relevantes un MVC encapsulando la base de datos, la interfaz y el menu manager, un proxy en la base de datos, y una facade en la implementación del programa en main.cpp.

### MVC

La interfaz, la base de datos y el menu manager funcionan siguendo el modelo MVC, donde el usuario interactúa únicamente con la interfaz, que se comunica con la base de datos y el menu manager para llevar a cabo las instrucciones del usuario. La interfaz por tanto, sería la vista, el menu manager el controlador, y la interfaz y los sensores los modelos a los que el usuario no accede directamente. Además, tanto el menu manager como la interfaz delegan funcionalidades a los modelos, en funciones como displayCurrent() o displayUsers(), donde es necesario acceder a atributos privados de la clase database, y por tanto cuando el usuario necesita esa información, la interfaz a su vez solicita a la base de datos que la muestre por pantalla.

### Proxy

La base tiene un atributo privado, Actual, que es una cuenta proxy de la cuenta a la que accede el usuario cuando incia sesión. De esta forma, todas las modificaciones que el usario realiza sobre la cuenta actual, se llevan a cabo sobre la cuenta proxy, y una vez la base de datos quiere guardar esa información de la cuenta, extrae la cuenta original del set e inserta la cuenta actual. En la base de datos también se delegan algunas funcionalidades a las propias cuentas. Puesto que todos los atributos de las cuentas son protected, cualquier modificación de los mismos se lleva a cabo llamando a funciones de la propia cuenta. Ejemplos de esto son las funciones logoff(), chusername() y chpassword().

![classDatabase__coll__graph](https://user-images.githubusercontent.com/90764534/213308832-dabd4a7b-6e95-4cfc-8bad-4034587776d2.png)

### Facade

Finalmente, la clase main tiene una implementación muy simple, crea un objeto de tipo menuManager y llama a su función run(). El menu manager incluye a todos los sensores, la interfaz, y la base de datos que necesita el programa para funcionar, y se comunica con ellos a través de las intrucciones que recibe del usuario a través de la interfaz. Cuando recibe la instrcción de salir, termina su ejecución, guarda todo y devuelve el control a main, que libera la memoria y cierra el programa.

![main_8cpp__incl](https://user-images.githubusercontent.com/90764534/213308743-31ce385e-30fe-4759-addf-049529f10292.png)

## Compilación y ejecución

La compilación se lleva a cabo usando el comando "$make all" dentro del directorio root del proyecto. Esto creará todos los objetos, y pondrá un ejecutable main en el directorio build/main/ y un vínculo a ese ejecutable en root. Ese ejecutable lanza el programa. Una vez dentro, la navegación por los menús se realiza mediante inputs numéricos y cualquer otra acción, como introducir nombres de usuario y contraseñas será notificada por el programa. El comando "$make clean" borrará todos los objetos y ejecutables. La información de los usuarios existentes está en el documento users.dat. Se advierte no modificar este documento manualmente, ya que la lectura del mismo requiere del uso de un formato específico.

## Visualización de la documentación

La documentación se generará con el comando "$doxygen Doxyfile", si no está ya generada. Se puede visualizar en html abriendo el documento doc/doxygen-doc/html/index.html con un navegador, o en pdf ejecutando el comando "$make refman.pdf" en el directorio doc/doxygen-doc/latex y abriendo el archivo refman.pdf generado. La documentación UML se puede encontrar en el directorio doc/ en formato umlx y pdf.


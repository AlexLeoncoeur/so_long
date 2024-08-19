# 🕹️ Proyecto So_Long - Explicación de Funciones

Este README proporciona una explicación detallada de las funciones clave utilizadas en el proyecto So_Long. El propósito es ayudar a comprender el flujo del programa y cómo se maneja la lógica del juego, desde la carga de imágenes hasta la interacción del usuario.

## 🚀 Función `main`

### Descripción:
Función principal del programa, que inicializa el juego, carga los recursos, y comienza el bucle de eventos.

### Detalles:
- **Inicialización del juego:** Configura la estructura del juego y carga el mapa.
- **Carga de imágenes:** Utiliza `ft_load_img` para cargar los recursos gráficos.
- **Renderizado inicial:** Dibuja el mapa inicial y asocia los controles del jugador.
- **Bucle de juego:** Entra en el bucle principal de MiniLibX para manejar los eventos hasta que el jugador gane o salga.

## 📦 Función `ft_load_img`

### Descripción:
Esta función se encarga de cargar y convertir las texturas de imágenes en imágenes manipulables por MiniLibX. Si alguna imagen no se carga correctamente, la función termina el programa.

### Detalles:
- **Carga de texturas:** Se cargan las imágenes desde las rutas especificadas usando `mlx_load_png`.
- **Conversión a imágenes:** Se convierte cada textura en una imagen utilizable en MiniLibX mediante `mlx_texture_to_image`.
- **Verificación de errores:** Si alguna carga o conversión falla, se llama a `ft_exit` o `ft_puterrorstr` para manejar el error.
- **Liberación de memoria:** Se libera la memoria utilizada por las texturas después de convertirlas a imágenes.

## 🗺️ Función `ft_read_map`

### Descripción:
Esta función lee el mapa del juego desde un archivo `.ber`, lo almacena en una matriz de caracteres y maneja posibles errores en el formato del mapa.

### Detalles:
- **Apertura de archivo:** Se abre el archivo de mapa y se verifica que no esté vacío.
- **Lectura y concatenación de líneas:** Cada línea se lee y se concatena en `full_map`.
- **Verificación de formato:** Se verifica que todas las líneas tengan la misma longitud, y si no, se maneja el error.
- **Almacenamiento del mapa:** Finalmente, el mapa se divide en una matriz de caracteres y se hace una copia para otras operaciones.

## 🖼️ Función `ft_render_map`

### Descripción:
Renderiza el mapa en la ventana del juego colocando las imágenes correspondientes en las coordenadas adecuadas.

### Detalles:
- **Iteración sobre el mapa:** Se recorre cada posición de la matriz del mapa.
- **Colocación de imágenes:** Dependiendo del carácter en cada posición ('P', 'C', 'E', '1'), se coloca la imagen correspondiente en la ventana.
- **Escalado y desplazamiento:** Las coordenadas se calculan considerando el escalado y el desplazamiento del mapa.

## ⌨️ Función `ft_controls_hook`

### Descripción:
Gestiona la interacción del jugador con el teclado y ejecuta las acciones correspondientes (moverse, salir, etc.).

### Detalles:
- **Captura de eventos de teclado:** Detecta las teclas presionadas, como las flechas o WASD para el movimiento.
- **Ejecución de movimientos:** Llama a las funciones de movimiento dependiendo de la tecla presionada.
- **Condiciones de victoria:** Comprueba si se cumplen las condiciones de victoria (recoger todos los objetos y llegar a la salida).

## 🎮 Función `ft_move_right`

### Descripción:
Mueve el personaje hacia la derecha y actualiza el estado del juego, incluyendo la recolección de objetos y la detección de colisiones.

### Detalles:
- **Cálculo de coordenadas:** Se calculan las coordenadas actuales y las nuevas tras el movimiento.
- **Verificación de colisiones:** Se verifica si el siguiente bloque es una pared ('1'), un objeto ('C'), o una salida ('E').
- **Actualización del mapa:** Se actualiza la posición del personaje y se renderiza nuevamente la escena.





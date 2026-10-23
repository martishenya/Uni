import vista.Menu;

/*
 * Clase principal del programa.
 *
 * Main será el punto de entrada de la aplicación. Intentamos que esta clase
 * tenga muy poco código, porque su función principal es arrancar el programa.
 *
 * La lógica de la aplicación no la vamos a colocar aquí. Para organizar mejor
 * el proyecto, cada parte tendrá su responsabilidad dentro de los paquetes
 * modelo, vista y controlador.
 */
public class Main {

    public static void main(String[] args) {

        /*
         * Creamos un objeto de la clase Menu.
         *
         * Menu se encuentra en el paquete vista, ya que será la clase encargada
         * de mostrar información al usuario y pedirle los datos necesarios.
         *
         * Para poder utilizar una clase que está en otro paquete necesitamos
         * importarla previamente:
         *
         * import vista.Menu;
         */
        Menu menu = new Menu();

        /*
         * Llamamos al método iniciar() del menú.
         *
         * De esta forma Main no necesita conocer cómo está construido el menú
         * ni qué opciones tiene. Simplemente crea el objeto y le indica que
         * comience la ejecución de la aplicación.
         */
        menu.iniciar();

    }
}
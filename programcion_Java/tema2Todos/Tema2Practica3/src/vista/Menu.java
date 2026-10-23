package vista;

import controlador.Builder;
import controlador.GestorLiga;

import java.util.Objects;
import java.util.Scanner;

/*
 * La clase Menu pertenece al paquete vista.
 *
 * Su responsabilidad es comunicarse con el usuario:
 * - mostrar las opciones disponibles;
 * - pedir los datos necesarios;
 * - recoger las respuestas del usuario;
 * - mostrar los mensajes de resultado.
 *
 * De esta forma evitamos mezclar la interacción con el usuario
 * con la lógica de gestión de la liga.
 *
 * La clase GestorLiga será la encargada de decidir si una operación
 * puede realizarse o no.
 */
public class Menu {

    /*
     * Referencia al objeto GestorLiga.
     *
     * La vista necesita comunicarse con el controlador para poder
     * solicitar operaciones como crear equipos, crear jugadores
     * o mostrar los datos almacenados.
     */
    private GestorLiga liga;

    /*
     * Scanner permite leer los datos que escribe el usuario
     * mediante el teclado.
     *
     * Lo declaramos como atributo porque lo vamos a utilizar
     * en varios métodos de la clase.
     */
    private Scanner sc;

    /*
     * CONSTRUCTOR DE MENU
     *
     * No recibe parámetros.
     *
     * Su función es preparar todo lo necesario para que el menú
     * pueda empezar a funcionar.
     */
    public Menu() {

        /*
         * Creamos el Scanner asociado a System.in.
         *
         * System.in representa la entrada estándar del programa,
         * que normalmente será el teclado.
         */
        sc = new Scanner(System.in);

        /*
         * Pedimos al usuario el nombre de la liga.
         */
        System.out.println("Dime el nombre de la liga");

        /*
         * nextLine() lee una línea completa de texto.
         *
         * Guardamos el valor introducido en una variable local
         * llamada nombreLiga.
         */
        String nombreLiga = sc.nextLine();

        /*
         * Creamos el objeto GestorLiga.
         *
         * Le pasamos el nombre que acaba de introducir el usuario.
         *
         * A partir de este momento, la variable liga nos permitirá
         * acceder a todas las operaciones de gestión.
         */
        liga = new GestorLiga(nombreLiga);

        Builder.inicializarDatos(liga);

    }

    /*
     * MÉTODO iniciar
     *
     * Su función es mostrar continuamente el menú principal
     * y ejecutar la opción seleccionada por el usuario.
     *
     * No recibe parámetros.
     *
     * No devuelve ningún valor porque su función consiste en controlar
     * la interacción con el usuario, por eso utilizamos void.
     */
    public void iniciar() {

        /*
         * Esta variable almacenará la opción seleccionada.
         *
         * La declaramos fuera del do-while porque necesitamos utilizarla
         * también en la condición final del bucle.
         */
        int opcion;

        /*
         * Utilizamos un do-while porque queremos que el menú se muestre
         * al menos una vez.
         *
         * Después de ejecutar una opción, volverá a mostrarse mientras
         * el usuario no elija la opción 0.
         */
        do {

            /*
             * Mostramos las distintas opciones disponibles.
             *
             * Algunas opciones todavía no existen porque iremos
             * desarrollando el programa poco a poco.
             */
            System.out.println("\n--- MENÚ ---");
            System.out.println("1. Crear equipo");
            System.out.println("2. Crear jugador");
            System.out.println("3. Fichar jugador");
            System.out.println("5. Mostrar equipos");
            System.out.println("6. Mostrar jugadores");
            System.out.println("0. Salir");
            System.out.print("Selecciona una opción: ");

            /*
             * nextInt() lee un número entero introducido por el usuario.
             */
            opcion = sc.nextInt();

            /*
             * nextInt() lee el número, pero deja pendiente el salto de línea
             * que se produce al pulsar Enter.
             *
             * Como después vamos a utilizar nextLine(), debemos consumir
             * ese salto de línea para evitar que la siguiente lectura
             * se salte automáticamente.
             */
            sc.nextLine();

            /*
             * Utilizamos switch porque tenemos varias acciones posibles
             * dependiendo del valor de una misma variable: opcion.
             */
            switch (opcion) {

                /*
                 * Si el usuario selecciona 1, llamamos al método
                 * crearEquipo().
                 *
                 * Ese método se encargará de pedir todos los datos
                 * necesarios para crear el equipo.
                 */
                case 1:
                    crearEquipo();
                    break;

                /*
                 * Si selecciona 2, pedimos los datos para crear
                 * un nuevo jugador.
                 */
                case 2:
                    crearJugador();
                    break;

                case 3:
                    ficharJugador();
                    break;

                /*
                 * En este caso no necesitamos pedir ningún dato.
                 *
                 * Llamamos directamente al método mostrarEquipos()
                 * del GestorLiga.
                 */
                case 5:
                    liga.mostrarEquipos();
                    break;

                /*
                 * Mostramos los jugadores registrados.
                 */
                case 6:
                    liga.mostrarJugadores();
                    break;

                /*
                 * La opción 0 se utiliza para terminar el programa.
                 *
                 * No es necesario hacer nada especial para salir del bucle,
                 * porque después el while comprobará que opcion vale 0.
                 */
                case 0:
                    System.out.println("Saliendo del programa...");
                    break;

                /*
                 * default se ejecuta cuando el usuario introduce
                 * una opción que no coincide con ninguno de los casos
                 * anteriores.
                 */
                default:
                    System.out.println("Opción no válida");
            }

            /*
             * El menú se repite mientras la opción sea distinta de 0.
             */
        } while (opcion != 0);
    }

    /*
     * MÉTODO crearEquipo
     *
     * Este método pertenece a Menu porque su función principal
     * es pedir al usuario los datos necesarios para crear un equipo.
     *
     * No recibe parámetros porque obtiene los datos directamente
     * mediante Scanner.
     *
     * No devuelve ningún valor porque muestra directamente
     * el resultado de la operación.
     */
    private void crearEquipo() {

        System.out.println("\n--- CREAR EQUIPO ---");

        /*
         * Pedimos el ID.
         *
         * En este caso necesitamos un int, por lo que utilizamos nextInt().
         */
        System.out.print("ID del equipo: ");
        int id = sc.nextInt();

        /*
         * Después de nextInt() limpiamos el salto de línea pendiente
         * antes de empezar a utilizar nextLine().
         */
        sc.nextLine();

        /*
         * Pedimos el resto de los datos como cadenas de texto.
         */
        System.out.print("Nombre del equipo: ");
        String nombre = sc.nextLine();

        System.out.print("Presidente: ");
        String presidente = sc.nextLine();

        System.out.print("Fecha de fundación: ");
        String fecha = sc.nextLine();

        /*
         * Una vez recogidos todos los datos, se los enviamos
         * al controlador.
         *
         * Menu no decide si el equipo puede crearse o no.
         * Esa responsabilidad pertenece a GestorLiga.
         *
         * crearEquipo() devuelve un boolean:
         *
         * true  -> el equipo se ha creado.
         * false -> ya existía un equipo con ese ID.
         */
        boolean resultado = liga.crearEquipo(
                id,
                nombre,
                presidente,
                fecha
        );

        /*
         * La vista interpreta el resultado devuelto por el controlador
         * y muestra un mensaje comprensible para el usuario.
         */
        if (resultado) {
            System.out.println("Equipo creado correctamente.");
        } else {
            System.out.println("Error: ya existe un equipo con ese ID.");
        }
    }

    /*
     * MÉTODO crearJugador
     *
     * Su función es pedir al usuario los datos necesarios
     * para registrar un nuevo jugador.
     *
     * No recibe parámetros porque los datos se obtienen mediante Scanner.
     *
     * No devuelve ningún valor porque muestra directamente al usuario
     * el resultado de la operación.
     */
    private void crearJugador() {

        System.out.println("\n--- CREAR JUGADOR ---");

        /*
         * Todos los datos que estamos pidiendo en este método
         * se almacenan como String.
         *
         * Por eso podemos utilizar directamente nextLine()
         * para cada uno de ellos.
         */
        System.out.print("NIF: ");
        String nif = sc.nextLine();

        System.out.print("Nombre: ");
        String nombre = sc.nextLine();

        System.out.print("Fecha de nacimiento: ");
        String fechaNacimiento = sc.nextLine();

        System.out.print("Posición: ");
        String posicion = sc.nextLine();

        /*
         * Enviamos los datos al GestorLiga.
         *
         * El controlador será quien compruebe si ya existe
         * otro jugador con el mismo NIF.
         *
         * El método devuelve:
         *
         * true  -> el jugador se ha creado correctamente.
         * false -> el jugador ya estaba registrado.
         */
        boolean resultado = liga.crearJugador(
                nif,
                nombre,
                fechaNacimiento,
                posicion
        );

        /*
         * Dependiendo del valor devuelto por GestorLiga,
         * mostramos al usuario el mensaje correspondiente.
         */
        if (resultado) {
            System.out.println("Jugador creado correctamente.");
        } else {
            System.out.println("Error: ya existe un jugador con ese NIF.");
        }
    }

    private void ficharJugador() {

        System.out.println("\n--- FICHAR JUGADOR ---");

        System.out.print("ID del equipo: ");
        int idEquipo = sc.nextInt();
        sc.nextLine();

        System.out.print("NIF del jugador: ");
        String nif = sc.nextLine();

        int resultado = liga.ficharJugador(idEquipo, nif);

        switch (resultado) {

            case 0:
                System.out.println("Jugador fichado correctamente.");
                break;

            case -1:
                System.out.println("Error: no existe un equipo con ese ID.");
                break;

            case -2:
                System.out.println("Error: no existe un jugador con ese NIF.");
                break;

            default:
                System.out.println("Error desconocido.");
        }
    }


}
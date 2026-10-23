package controlador;

import modelo.Equipo;
import modelo.Jugador;

import java.util.ArrayList;

/*
 * La clase GestorLiga pertenece al paquete controlador.
 *
 * Su responsabilidad es gestionar la información de la liga y coordinar
 * operaciones como crear equipos, crear jugadores o mostrar los datos
 * almacenados.
 *
 * Separamos esta lógica del menú para no mezclar la parte que pregunta datos
 * al usuario con la parte que decide qué hacer con esos datos.
 */
public class GestorLiga {

    /*
     * Almacena el nombre de la liga.
     *
     * Es un atributo del objeto porque cada GestorLiga representa
     * una liga concreta y necesitamos conservar ese dato mientras
     * el programa está funcionando.
     */
    private String nombreLiga;

    // ArrayList que almacena todos los equipos creados en la liga.
    private ArrayList<Equipo> equipos;

    //ArrayList que almacena todos los jugadores registrados.
    private ArrayList<Jugador> jugadores;

    /*
     * CONSTRUCTOR DE GESTORLIGA
     *
     * Recibe:
     * - nombreLiga: nombre que tendrá la liga.
     *
     * No devuelve ningún valor porque los constructores nunca tienen
     * tipo de retorno.
     *
     * Su función es crear e inicializar correctamente un objeto GestorLiga.
     */
    public GestorLiga(String nombreLiga) {

        /*
         * Guardamos en el atributo nombreLiga el valor recibido
         * como parámetro.
         *
         * Utilizamos this.nombreLiga para referirnos al atributo
         * del objeto actual.
         */
        this.nombreLiga = nombreLiga;

        /*
         * Inicializamos la lista de equipos.
         *
         * Declarar una variable ArrayList no crea automáticamente
         * una lista vacía. Por eso necesitamos utilizar new.
         *
         * A partir de este momento podremos utilizar métodos como
         * add(), isEmpty(), etc.
         */
        this.equipos = new ArrayList<>();

        /*
         * Hacemos lo mismo con la lista de jugadores.
         *
         * Cuando se crea la liga, todavía no hay jugadores registrados,
         * por lo que la lista comienza vacía.
         */
        this.jugadores = new ArrayList<>();
    }

    /*
     * MÉTODO crearEquipo
     *
     * Su función es crear un nuevo equipo y añadirlo a la liga.
     *
     * Recibe:
     * - ID: número que identifica de forma única al equipo.
     * - nombre: nombre del equipo.
     * - presidente: nombre del presidente.
     * - fechaFundacion: fecha de fundación.
     *
     * Devuelve:
     * - true si el equipo se ha podido crear correctamente.
     * - false si ya existe otro equipo con el mismo ID.
     *
     * Utilizamos boolean porque solo necesitamos comunicar dos posibles
     * resultados: éxito o error.
     */
    public boolean crearEquipo(int ID,
                               String nombre,
                               String presidente,
                               String fechaFundacion) {

        /*
         * Creamos un objeto Equipo utilizando los datos recibidos.
         *
         * Todavía no lo añadimos directamente al ArrayList porque primero
         * debemos comprobar que no exista ya un equipo con el mismo ID.
         */
        Equipo e = new Equipo(ID, nombre, presidente, fechaFundacion);

        /*
         * Recorremos todos los equipos que ya existen en la liga.
         *
         * Este tipo de for se llama for-each.
         *
         * En cada iteración, eAux contiene una referencia a uno de los
         * objetos Equipo almacenados dentro del ArrayList equipos.
         */
        for (Equipo eAux : equipos) {

            /*
             * Podríamos comprobar directamente si los ID son iguales:
             *
             * if (eAux.getID() == ID) return false;
             *
             * Sin embargo, hemos definido el método equals() en la clase
             * Equipo para establecer cuándo consideramos que dos equipos
             * son iguales.
             *
             * En nuestro caso, dos equipos se consideran iguales
             * cuando tienen el mismo ID.
             *
             * Esto nos permite comparar los dos objetos utilizando equals().
             */
            // if (eAux.getID() == ID) return false;

            if (eAux.equals(e)) {

                /*
                 * Si encontramos un equipo igual, significa que ese ID
                 * ya está siendo utilizado.
                 *
                 * Devolvemos false y el método termina inmediatamente.
                 *
                 * Por tanto, el nuevo equipo no se añade a la lista.
                 */
                return false;
            }
        }

        /*
         * Si hemos terminado de recorrer toda la lista y no hemos encontrado
         * ningún equipo igual, significa que el ID está disponible.
         *
         * Añadimos el nuevo objeto Equipo al ArrayList.
         */
        equipos.add(e);

        /*
         * Devolvemos true para indicar que la operación se ha realizado
         * correctamente.
         *
         * La clase Menu podrá utilizar este valor para mostrar al usuario
         * un mensaje de éxito o de error.
         */
        return true;
    }

    /*
     * MÉTODO crearJugador
     *
     * Su funcionamiento es similar a crearEquipo.
     *
     * Su función es crear un nuevo jugador y almacenarlo en la lista
     * de jugadores de la liga.
     *
     * Recibe:
     * - nif: identificador del jugador.
     * - nombre: nombre del jugador.
     * - fechaNacimiento: fecha de nacimiento.
     * - posicion: posición en la que juega.
     *
     * Devuelve:
     * - true si el jugador se ha creado correctamente.
     * - false si ya existe un jugador con el mismo NIF.
     */
    public boolean crearJugador(String nif,
                                String nombre,
                                String fechaNacimiento,
                                String posicion) {

        /*
         * Creamos un nuevo objeto Jugador utilizando los datos recibidos.
         *
         * En este momento el jugador todavía no pertenece a ningún equipo.
         * Según el enunciado, el equipo se asignará posteriormente
         * cuando se realice el fichaje.
         */
        Jugador j = new Jugador(nif, nombre, fechaNacimiento, posicion);

        /*
         * Recorremos todos los jugadores que ya están registrados
         * para comprobar que no exista otro jugador igual.
         */
        for (Jugador jAux : jugadores) {

            /*
             * Utilizamos equals() porque en la clase Jugador hemos definido
             * cómo queremos determinar si dos jugadores son iguales.
             *
             * En nuestro caso, esa comparación se realizará utilizando
             * el NIF.
             */
            if (jAux.equals(j)) {

                /*
                 * Si ya existe un jugador con el mismo NIF,
                 * devolvemos false.
                 *
                 * Al ejecutar return, el método termina en ese momento
                 * y no se añade el jugador a la lista.
                 */
                return false;
            }
        }

        /*
         * Si no hemos encontrado ningún jugador repetido,
         * añadimos el nuevo jugador al ArrayList.
         */
        jugadores.add(j);

        /*
         * Devolvemos true para indicar que el jugador se ha creado
         * correctamente.
         */
        return true;
    }

    /*
     * MÉTODO mostrarEquipos
     *
     * Su función es mostrar por pantalla todos los equipos
     * registrados en la liga.
     *
     * No recibe parámetros porque trabaja directamente con el ArrayList
     * equipos que pertenece al propio GestorLiga.
     *
     * Tampoco devuelve ningún valor, por eso su tipo de retorno es void.
     */
    public void mostrarEquipos() {

        /*
         * Antes de intentar recorrer la lista comprobamos si está vacía.
         *
         * isEmpty() devuelve true cuando el ArrayList no contiene
         * ningún elemento.
         */
        if (equipos.isEmpty()) {

            /*
             * Si no hay equipos, mostramos un mensaje para informar
             * al usuario.
             */
            System.out.println("No hay equipos registrados.");

            /*
             * return hace que termine inmediatamente la ejecución
             * de este método.
             *
             * Como el método es void, no devolvemos ningún dato.
             * Simplemente evitamos ejecutar el resto del código.
             */
            return;
        }

        /*
         * Mostramos un encabezado para que el listado sea más legible.
         */
        System.out.println("\n--- LISTADO DE EQUIPOS ---");

        /*
         * Recorremos todos los objetos Equipo almacenados en la lista.
         *
         * En cada vuelta del bucle, la variable equipo hace referencia
         * a uno de esos objetos.
         */
        for (Equipo equipo : equipos) {

            /*
             * Imprimimos directamente el objeto Equipo.
             *
             * Cuando utilizamos println() con un objeto, Java llama
             * automáticamente al método toString() de ese objeto.
             *
             * Por tanto, el formato con el que se muestra cada equipo
             * depende del toString() que hayamos definido en Equipo.
             */
            System.out.println(equipo);
        }

        /*
         * Mostramos una línea final para separar visualmente el listado.
         */
        System.out.println("--------------------");
    }

    /*
     * MÉTODO mostrarJugadores
     *
     * Su función es mostrar por pantalla todos los jugadores
     * registrados en la liga.
     *
     * No recibe parámetros porque utiliza directamente el ArrayList
     * jugadores de esta clase.
     *
     * No devuelve ningún valor porque únicamente muestra información,
     * por eso utilizamos void.
     */
    public void mostrarJugadores() {

        /*
         * Comprobamos si la lista de jugadores está vacía.
         */
        if (jugadores.isEmpty()) {

            /*
             * Si todavía no existe ningún jugador, mostramos un mensaje.
             */
            System.out.println("No hay jugadores registrados.");

            /*
             * Terminamos el método para evitar recorrer una lista vacía
             * y mostrar un encabezado sin contenido.
             */
            return;
        }

        /*
         * Mostramos el encabezado del listado.
         */
        System.out.println("\n--- LISTADO DE JUGADORES ---");

        /*
         * Recorremos todos los jugadores almacenados utilizando un for-each.
         *
         * En cada iteración, jugador contiene una referencia a uno
         * de los objetos Jugador de la lista.
         */
        for (Jugador jugador : jugadores) {

            /*
             * Al imprimir el objeto Jugador, Java llama automáticamente
             * a su método toString().
             *
             * Esto nos permite decidir en la clase Jugador cómo queremos
             * que aparezca representado por pantalla.
             */
            System.out.println(jugador);
        }

        /*
         * Línea final para mejorar la presentación del listado.
         */
        System.out.println("--------------------");
    }

    public int ficharJugador(int ID , String NIF){

        Jugador j = buscarJugador(NIF);
        Equipo e = buscarEquipo(ID);


        if( e == null ) return -1;
        if( j == null) return -2;

        if(j.getEquipo() != null){

            j.getEquipo().eliminarJugador(j);

        }

        j.setEquipo(e);

        e.ficharJugador(j);

        return 0;
    }

    public Jugador buscarJugador(String NIF){

        for( Jugador j: jugadores ){
            if( j.getNif().equals(NIF)){
                return j;
            }
        }
        return null;
    }

    public Equipo buscarEquipo(int ID){

        for( Equipo e : equipos){
            if( e.getID() == ID){
                return e;
            }
        }
        return null;
    }
}
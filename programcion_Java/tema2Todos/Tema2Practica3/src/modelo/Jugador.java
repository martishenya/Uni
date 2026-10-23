package modelo;

import java.util.Objects;

/*
 * La clase Jugador pertenece al paquete modelo.
 *
 * Su función es representar a un jugador de la liga.
 *
 * En esta clase almacenamos los datos propios del jugador y definimos
 * operaciones relacionadas directamente con él.
 */
public class Jugador {

    /*
     * Atributos del jugador.
     *
     * Los declaramos como private para aplicar encapsulación.
     * De esta forma otras clases no pueden modificar directamente
     * los datos internos del objeto.
     *
     * Para consultar o modificar determinados valores utilizaremos
     * métodos get y set.
     */
    private String nif;
    private String nombre;
    private String fechaNacimiento;
    private String posicion;

    /*
     * Este atributo no almacena el nombre del equipo como un String.
     *
     * Guarda una referencia a un objeto Equipo.
     *
     * Esto permite relacionar objetos entre sí. Gracias a ello, desde
     * un jugador podremos acceder posteriormente a información de su equipo,
     * por ejemplo:
     *
     * jugador.getEquipo().getNombre()
     */
    private Equipo equipo;

    /*
     * CONSTRUCTOR DE JUGADOR
     *
     * Su función es crear un nuevo objeto Jugador.
     *
     * Recibe:
     * - nif: identificador del jugador.
     * - nombre: nombre del jugador.
     * - fechaNacimiento: fecha de nacimiento.
     * - posicion: posición en la que juega.
     *
     * No recibe un equipo porque, según el enunciado, cuando se crea
     * un jugador todavía no tiene por qué estar fichado por ningún equipo.
     */
    public Jugador(String nif,
                   String nombre,
                   String fechaNacimiento,
                   String posicion) {

        /*
         * Guardamos cada parámetro recibido en el atributo correspondiente.
         *
         * Utilizamos this para distinguir el atributo del objeto
         * del parámetro recibido por el constructor.
         */
        this.nif = nif;
        this.nombre = nombre;
        this.fechaNacimiento = fechaNacimiento;
        this.posicion = posicion;

        /*
         * Inicializamos equipo a null.
         *
         * null significa que, en este momento, la variable no hace
         * referencia a ningún objeto Equipo.
         *
         * Esto representa exactamente el estado de un jugador
         * que todavía no ha sido fichado.
         */
        this.equipo = null;
    }

    /*
     * MÉTODO getNif
     *
     * Permite consultar el NIF del jugador.
     *
     * No recibe parámetros porque simplemente devuelve un dato
     * almacenado en el propio objeto.
     */
    public String getNif() {
        return nif;
    }

    /*
     * MÉTODO getNombre
     *
     * Devuelve el nombre del jugador.
     */
    public String getNombre() {
        return nombre;
    }

    /*
     * MÉTODO getFechaNacimiento
     *
     * Devuelve la fecha de nacimiento del jugador.
     *
     * De momento la almacenamos como String, aunque más adelante
     * podría utilizarse una clase específica para fechas.
     */
    public String getFechaNacimiento() {
        return fechaNacimiento;
    }

    /*
     * MÉTODO getPosicion
     *
     * Devuelve la posición en la que juega.
     */
    public String getPosicion() {
        return posicion;
    }

    /*
     * MÉTODO getEquipo
     *
     * Devuelve la referencia al objeto Equipo al que pertenece el jugador.
     *
     * Puede devolver:
     * - un objeto Equipo, si el jugador está fichado;
     * - null, si todavía no pertenece a ningún equipo.
     *
     * Es importante recordar que no devuelve un String con el nombre,
     * sino el objeto Equipo completo.
     */
    public Equipo getEquipo() {
        return equipo;
    }

    /*
     * MÉTODO setPosicion
     *
     * Permite modificar la posición de un jugador ya creado.
     *
     * Recibe:
     * - posicion: nueva posición que queremos asignarle.
     *
     * No devuelve ningún valor porque únicamente modifica
     * el estado interno del objeto.
     */
    public void setPosicion(String posicion) {
        this.posicion = posicion;
    }

    /*
     * MÉTODO setEquipo
     *
     * Permite asignar un equipo al jugador o cambiar el equipo
     * al que pertenece.
     *
     * Recibe un objeto Equipo, no el nombre del equipo.
     *
     * Más adelante utilizaremos este método cuando implementemos
     * la funcionalidad de fichar jugadores.
     */
    public void setEquipo(Equipo equipo) {
        this.equipo = equipo;
    }

    /*
     * MÉTODO equals
     *
     * Define cuándo consideramos que dos objetos Jugador son iguales.
     *
     * En nuestro programa utilizamos el NIF como identificador,
     * por lo que dos jugadores serán iguales si tienen el mismo NIF.
     *
     * Recibe:
     * - o: otro objeto con el que queremos comparar este jugador.
     *
     * Devuelve:
     * - true si ambos jugadores tienen el mismo NIF.
     * - false en caso contrario.
     */
    @Override
    public boolean equals(Object o) {

        /*
         * Primero comprobamos que el objeto recibido exista
         * y que sea de la misma clase.
         *
         * Si o es null, no puede ser igual a este jugador.
         *
         * Si pertenece a otra clase, tampoco debemos compararlos
         * como si ambos fueran jugadores.
         */
        if (o == null || getClass() != o.getClass()) {
            return false;
        }

        /*
         * equals() recibe un Object porque este método procede
         * de la clase Object.
         *
         * Como ya sabemos que o es realmente un Jugador,
         * realizamos un casting para poder tratarlo como tal.
         */
        Jugador jugador = (Jugador) o;

        /*
         * Comparamos los NIF.
         *
         * Utilizamos Objects.equals() porque estamos comparando Strings.
         * Este método también evita problemas si alguno de los valores
         * fuera null.
         */
        return Objects.equals(nif, jugador.nif);
    }

    /*
     * MÉTODO hashCode
     *
     * Siempre que redefinimos equals(), debemos redefinir también hashCode().
     *
     * Si dos jugadores son iguales según equals(), deben generar también
     * el mismo hashCode().
     *
     * Como nuestro criterio de igualdad utiliza el NIF,
     * generamos el hashCode a partir de ese mismo atributo.
     */
    @Override
    public int hashCode() {
        return Objects.hashCode(nif);
    }



    /*
     * MÉTODO toString
     *
     * Define cómo queremos representar un objeto Jugador mediante texto.
     *
     * Este método se utiliza automáticamente, por ejemplo, cuando hacemos:
     *
     * System.out.println(jugador);
     *
     * Queremos mostrar también el equipo del jugador, pero debemos tener
     * en cuenta que un jugador recién creado puede no tener equipo.
     */
    @Override
    public String toString() {

        /*
         * Creamos una variable auxiliar donde guardaremos el texto
         * que queremos mostrar para el equipo.
         */
        String nombreEquipo;

        /*
         * Antes de acceder al equipo comprobamos si es null.
         *
         * Esto es importante porque intentar hacer:
         *
         * equipo.getNombre()
         *
         * cuando equipo vale null provocaría un NullPointerException.
         */
        if (equipo == null) {

            /*
             * Si no existe ningún objeto Equipo asociado,
             * mostramos un texto que indique claramente que el jugador
             * todavía no pertenece a ningún equipo.
             */
            nombreEquipo = "Sin equipo";

        } else {

            /*
             * Si el jugador sí tiene equipo, obtenemos su nombre
             * utilizando el getter de Equipo.
             *
             * No imprimimos directamente el objeto Equipo porque en este
             * listado solo queremos mostrar su nombre.
             */
            nombreEquipo = equipo.getNombre();
        }

        /*
         * Devolvemos una representación sencilla y legible del jugador.
         *
         * Ejemplos:
         *
         * 12345678A - Ana Pérez - Delantera - Salamanca FC
         *
         * o, si todavía no tiene equipo:
         *
         * 12345678A - Ana Pérez - Delantera - Sin equipo
         */
        return nif + " - " + nombre +
                " - " + posicion +
                " - " + nombreEquipo;
    }
}
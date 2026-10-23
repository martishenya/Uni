package modelo;

import java.util.ArrayList;
import java.util.Objects;

/*
 * La clase Equipo pertenece al paquete modelo.
 *
 * Su función es representar un equipo de la liga.
 *
 * En el modelo almacenamos los datos propios del objeto y definimos
 * cómo se comporta ese objeto.
 *
 * De momento todavía no hemos añadido la lista de jugadores ni
 * la lista de partidos. Esas funcionalidades se incorporarán
 * más adelante a medida que avance el ejercicio.
 */
public class Equipo {

    /*
     * Atributos del equipo.
     *
     * Los declaramos como private para aplicar encapsulación:
     * otras clases no pueden acceder directamente a estos datos.
     *
     * Para consultar o modificar los valores utilizaremos métodos
     * get y set.
     */
    private int ID;
    private String nombre;
    private String presidente;
    private String fecha;

    private ArrayList<Jugador> jugadores;

    /*
     * CONSTRUCTOR DE EQUIPO
     *
     * Su función es crear un nuevo objeto Equipo con sus datos iniciales.
     *
     * Recibe:
     * - ID: identificador numérico del equipo.
     * - nombre: nombre del equipo.
     * - presidente: nombre del presidente.
     * - fecha: fecha de fundación.
     *
     * Los constructores no tienen tipo de retorno.
     *
     * Cada valor recibido se guarda en el atributo correspondiente
     * del objeto que estamos creando.
     */
    public Equipo(int ID, String nombre, String presidente, String fecha) {

        /*
         * Utilizamos this para diferenciar el atributo del objeto
         * del parámetro recibido.
         *
         * Por ejemplo:
         *
         * this.nombre = nombre;
         *
         * significa:
         * "guarda en el atributo nombre de este objeto el valor recibido
         * en el parámetro nombre".
         */
        this.ID = ID;
        this.nombre = nombre;
        this.presidente = presidente;
        this.fecha = fecha;

        jugadores = new ArrayList<>();
    }

    /*
     * MÉTODO getID
     *
     * Devuelve el identificador del equipo.
     *
     * No recibe ningún parámetro porque simplemente consulta
     * un dato que ya pertenece al objeto.
     *
     * Devuelve un int porque ID es un número entero.
     */
    public int getID() {
        return ID;
    }

    /*
     * MÉTODO getNombre
     *
     * Permite consultar el nombre del equipo desde otras clases.
     *
     * Devuelve un String porque el nombre se almacena como texto.
     */
    public String getNombre() {
        return nombre;
    }

    /*
     * MÉTODO getPresidente
     *
     * Devuelve el nombre del presidente del equipo.
     */
    public String getPresidente() {
        return presidente;
    }

    /*
     * MÉTODO getFecha
     *
     * Devuelve la fecha de fundación.
     *
     * De momento estamos utilizando String para almacenar fechas.
     * Más adelante podría sustituirse por una clase específica
     * para trabajar con fechas.
     */
    public String getFecha() {
        return fecha;
    }

    /*
     * MÉTODO setNombre
     *
     * Permite modificar el nombre de un equipo ya creado.
     *
     * Recibe:
     * - nombre: nuevo nombre que queremos asignar.
     *
     * No devuelve ningún valor porque únicamente modifica
     * el estado interno del objeto.
     */
    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    /*
     * MÉTODO setPresidente
     *
     * Permite cambiar el presidente del equipo.
     *
     * Recibe el nuevo valor y lo almacena en el atributo presidente.
     */
    public void setPresidente(String presidente) {
        this.presidente = presidente;
    }

    /*
     * MÉTODO setFecha
     *
     * Permite modificar la fecha de fundación almacenada.
     */
    public void setFecha(String fecha) {
        this.fecha = fecha;
    }

    /*
     * MÉTODO toString
     *
     * toString() permite decidir cómo queremos representar un objeto
     * Equipo mediante texto.
     *
     * Este método se ejecuta automáticamente, por ejemplo, cuando hacemos:
     *
     * System.out.println(equipo);
     *
     * En lugar de mostrar una representación poco legible del objeto,
     * devolvemos una cadena con los datos que nos interesa visualizar.
     *
     * El formato elegido es:
     *
     * Nombre (ID) - Presidente - Fecha
     *
     * Ejemplo:
     *
     * Salamanca FC (3) - Ana García - 12/05/1995
     */
    @Override
    public String toString() {

        String texto = nombre + " (" + ID + ") - " + presidente + " - " + fecha;

        texto += "\nJugadores:";

        if (jugadores.isEmpty()) {
            texto += " Sin jugadores";
        } else {
            for (Jugador jugador : jugadores) {
                texto += "\n - " + jugador.getNombre() + " (" + jugador.getPosicion() + ")";
            }
        }

        return texto;
    }

    /*
     * MÉTODO equals
     *
     * equals() sirve para definir cuándo consideramos que dos objetos
     * Equipo son iguales.
     *
     * Por defecto, Java compara si dos variables hacen referencia
     * exactamente al mismo objeto en memoria.
     *
     * En nuestro programa queremos otro criterio:
     * dos equipos se consideran iguales cuando tienen el mismo ID.
     *
     * Este método recibe:
     * - o: otro objeto con el que queremos comparar este equipo.
     *
     * Devuelve:
     * - true si ambos equipos tienen el mismo ID.
     * - false en caso contrario.
     */
    @Override
    public boolean equals(Object o) {

        /*
         * Primero comprobamos dos situaciones en las que los objetos
         * no pueden considerarse iguales.
         *
         * o == null:
         * el objeto recibido no existe.
         *
         * getClass() != o.getClass():
         * el objeto recibido no pertenece a la misma clase.
         *
         * Por ejemplo, un Equipo no debe considerarse igual
         * a un Jugador.
         */
        if (o == null || getClass() != o.getClass()) {
            return false;
        }

        /*
         * El parámetro o es de tipo Object porque equals() se hereda
         * de la clase Object.
         *
         * Como ya hemos comprobado que realmente es un Equipo,
         * hacemos un casting para poder acceder a sus atributos.
         */
        Equipo equipo = (Equipo) o;

        /*
         * Dos equipos se consideran iguales si tienen el mismo ID.
         *
         * Esto nos permite utilizar después:
         *
         * eAux.equals(e)
         *
         * para comprobar si un equipo ya existe en la liga.
         */
        return ID == equipo.ID;
    }

    /*
     * MÉTODO hashCode
     *
     * Cuando redefinimos equals(), también debemos redefinir hashCode().
     *
     * Java utiliza hashCode() en determinadas estructuras de datos
     * para identificar y organizar objetos.
     *
     * La regla importante es que si dos objetos son iguales según equals(),
     * deben producir también el mismo hashCode().
     *
     * Como nuestro criterio de igualdad utiliza el ID, generamos
     * también el hashCode a partir del ID.
     */
    @Override
    public int hashCode() {
        return Objects.hashCode(ID);
    }

    public void ficharJugador(Jugador jugador){
        jugadores.add(jugador);
    }

    public void eliminarJugador(Jugador jugador){
        jugadores.remove(jugador);
    }
}
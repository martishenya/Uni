package modelo;

import java.util.Objects;

public class Jugador {

    private String NIF;
    private String nombre;
    private String fecha;
    private String pos;
    private Equipo equipo;

    public Jugador(String NIF, String nombre, String pos, String fecha, Equipo equipo) {

        this.NIF = NIF;
        this.nombre = nombre;
        this.pos = pos;
        this.fecha = fecha;

        this.equipo = null;

    }

//    no se si hay que crear todos los gets y sets para futuro como en classe Equipo pero lo dejo para luego

    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        Jugador jugador = (Jugador) o;
        return Objects.equals(NIF, jugador.NIF);
    }

    @Override
    public int hashCode() {
        return Objects.hashCode(NIF);
    }


    @Override
    public String toString() {
        return "Jugador{" +
                "NIF='" + NIF + '\'' +
                ", nombre='" + nombre + '\'' +
                ", fecha='" + fecha + '\'' +
                ", pos='" + pos + '\'' +
                ", equipo=" + equipo +
                '}';
    }
}

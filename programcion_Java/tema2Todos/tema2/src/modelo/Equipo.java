package modelo;

import java.util.Objects;

public class Equipo {

    private int ID;
    private String nombre;
    private String presidente;
    private String fecha;

    public Equipo(int ID, String nombre, String presidente, String fecha) {
        this.ID = ID;
        this.nombre = nombre;
        this.presidente = presidente;
        this.fecha = fecha;
    }

    public int getID() {
        return ID;
    }

    public String getNombre() {
        return nombre;
    }

    public String getPresidente() {
        return presidente;
    }

    public String getFecha() {
        return fecha;
    }


    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    public void setPresidente(String presidente) {
        this.presidente = presidente;
    }

    public void setFecha(String fecha) {
        this.fecha = fecha;
    }


    @Override
    public String toString() {
        return "Equipo{" +
                "ID=" + ID +
                ", nombre='" + nombre + '\'' +
                ", presidente='" + presidente + '\'' +
                ", fecha='" + fecha + '\'' +
                '}';
    }

    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        Equipo equipo = (Equipo) o;
        return ID == equipo.ID;
    }

    @Override
    public int hashCode() {
        return Objects.hashCode(ID);
    }
}

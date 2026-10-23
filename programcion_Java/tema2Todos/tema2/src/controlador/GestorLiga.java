package controlador;

import modelo.Equipo;
import modelo.Jugador;

import java.util.ArrayList;

public class GestorLiga {

    private String nombreLiga;
    private ArrayList<Equipo> equipos;

    private ArrayList<Jugador> jugadores;


    public GestorLiga(String nombreLiga) {
        this.nombreLiga = nombreLiga;
        this.equipos = new ArrayList<>();

        this.jugadores = new ArrayList<>();
    }



    public boolean crearEquipo(int ID,
                               String nombre,
                               String presidente,
                               String fecha){

        Equipo e = new Equipo(ID, nombre, presidente, fecha);


        for (Equipo eAux : equipos){

            //if( eAux.getID() == ID) return false;
            if(eAux.equals(e) ) return false;

        }

        equipos.add(e);
        return true;

    };

    public boolean crearJugador(String NIF,
                               String nombre,
                               String pos,
                               String fecha
                               ){

        Jugador jug = new Jugador(NIF, nombre, pos, fecha, null);


        for (Jugador jugAux : jugadores){

            //if( eAux.getID() == ID) return false;
            if(jugAux.equals(jug) ) return false;

        }

        jugadores.add(jug);
        return true;

    };


    public void mostrarEquipos() {

        if (equipos.isEmpty()) {
            System.out.println("No hay equipos registrados.");
            return;
        }

        System.out.println("\n--- LISTADO DE EQUIPOS ---");

        for (Equipo equipo : equipos) {
            System.out.println(equipo);
        }
        System.out.println("--------------------");
    }

    public void mostrarJugadores() {

        if (jugadores.isEmpty()) {
            System.out.println("No hay jugadores registrados.");
            return;
        }

        System.out.println("\n--- LISTADO DE jugadores ---");

        for (Jugador jugador : jugadores) {
            System.out.println(jugador);
        }
        System.out.println("--------------------");
    }

}

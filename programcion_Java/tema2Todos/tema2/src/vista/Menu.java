package vista;

import controlador.GestorLiga;

import java.util.Scanner;

public class Menu {


    private GestorLiga liga;
    private Scanner sc;

    public Menu() {

        sc = new Scanner(System.in);

        System.out.println("Dime el nombre de la liga");
        String nombreLiga = sc.nextLine();

        liga = new GestorLiga(nombreLiga);





        }
    public void iniciar(){
        int opcion;

        do {
            System.out.println("\n--- MENÚ ---");
            System.out.println("1. Crear equipo");
            System.out.println("2. Crear jugador");
            System.out.println("4. Mostrar jugadores");
            System.out.println("5. Mostrar equipos");
            System.out.println("0. Salir");
            System.out.print("Selecciona una opción: ");

            opcion = sc.nextInt();
            sc.nextLine(); // Limpiamos el salto de línea pendiente

            switch (opcion) {

                case 1:
                    crearEquipo();
                    break;
                case 2:
                    crearJugador();
                    break;
                case 4:
                    liga.mostrarJugadores();
                    break;
                case 5:
                    liga.mostrarEquipos();
                    break;

                case 0:
                    System.out.println("Saliendo del programa...");
                    break;

                default:
                    System.out.println("Opción no válida");
            }

        } while (opcion != 0);
    }

    private void crearEquipo() {

        System.out.println("\n--- CREAR EQUIPO ---");

        System.out.print("ID del equipo: ");
        int id = sc.nextInt();
        sc.nextLine();

        System.out.print("Nombre del equipo: ");
        String nombre = sc.nextLine();

        System.out.print("Presidente: ");
        String presidente = sc.nextLine();

        System.out.print("Fecha de fundación: ");
        String fecha = sc.nextLine();

        boolean resultado = liga.crearEquipo(id, nombre, presidente, fecha);

        mostrarResultadoCrearEquipo(resultado);
    }

    private void crearJugador() {

        System.out.println("\n--- CREAR JUGADOR ---");

        System.out.print("NIF: ");
        String nif = sc.nextLine();

        System.out.print("Nombre: ");
        String nombre = sc.nextLine();

        System.out.print("Posición: ");
        String posicion = sc.nextLine();

        System.out.print("Fecha de nacimiento: ");
        String fecha = sc.nextLine();

        boolean resultado = liga.crearJugador(nif, nombre, posicion, fecha);

        if (resultado) {
            System.out.println("Jugador creado correctamente.");
        } else {
            System.out.println("Error: ya existe un jugador con ese NIF.");
        }


    }

    private void mostrarResultadoCrearEquipo(boolean resultado) {

        if (resultado) {
            System.out.println("Equipo creado correctamente.");
        } else {
            System.out.println("Error: ya existe un equipo con ese ID.");
        }
    }

}

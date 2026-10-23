package controlador;


public class Builder {

    public static void inicializarDatos(GestorLiga liga) {

        liga.crearEquipo(1, "Peña Bolística La Encina", "Javier Fernández", "1982");
        liga.crearEquipo(2, "Club Bolos El Roble", "Miguel Suárez", "1975");
        liga.crearEquipo(3, "Peña Bolística San Mateo", "Lucía González", "1991");
        liga.crearEquipo(4, "Bolos Villa del Norte", "Carlos Menéndez", "1988");
        liga.crearEquipo(5, "Peña Bolística El Prau", "Marcos Álvarez", "1969");
        liga.crearEquipo(6, "Club Bolístico La Casona", "Ana Rodríguez", "1997");

        liga.crearJugador("11111111A", "Daniel García", "12/03/1994", "Jugador");
        liga.crearJugador("11111112B", "Pablo Martínez", "21/07/1989", "Jugador");
        liga.crearJugador("11111113C", "Sergio López", "05/11/1996", "Jugador");

        liga.crearJugador("22222221D", "Iván Fernández", "18/02/1992", "Jugador");
        liga.crearJugador("22222222E", "Adrián Suárez", "30/09/1987", "Jugador");
        liga.crearJugador("22222223F", "Hugo González", "14/06/1995", "Jugador");

        liga.crearJugador("33333331G", "Mario Álvarez", "08/01/1991", "Jugador");
        liga.crearJugador("33333332H", "Rubén Díaz", "17/05/1993", "Jugador");
        liga.crearJugador("33333333J", "Álvaro Menéndez", "27/10/1988", "Jugador");

        liga.crearJugador("44444441K", "Diego Rodríguez", "02/04/1990", "Jugador");
        liga.crearJugador("44444442L", "Jorge Blanco", "11/08/1997", "Jugador");
        liga.crearJugador("44444443M", "Víctor Iglesias", "25/12/1992", "Jugador");

        liga.crearJugador("55555551N", "Samuel García", "09/03/1995", "Jugador");
        liga.crearJugador("55555552P", "Raúl Fernández", "16/07/1986", "Jugador");
        liga.crearJugador("55555553Q", "Óscar Suárez", "22/11/1994", "Jugador");

        liga.crearJugador("66666661R", "Borja Martínez", "06/02/1993", "Jugador");
        liga.crearJugador("66666662S", "Andrés López", "19/06/1989", "Jugador");
        liga.crearJugador("66666663T", "Guillermo Pérez", "28/09/1996", "Jugador");


        liga.ficharJugador(1, "11111111A");
        liga.ficharJugador(1, "11111112B");
        liga.ficharJugador(1, "11111113C");

        liga.ficharJugador(2, "22222221D");
        liga.ficharJugador(2, "22222222E");
        liga.ficharJugador(2, "22222223F");

        liga.ficharJugador(3, "33333331G");
        liga.ficharJugador(3, "33333332H");
        liga.ficharJugador(3, "33333333J");

        liga.ficharJugador(4, "44444441K");
        liga.ficharJugador(4, "44444442L");
        liga.ficharJugador(4, "44444443M");

        liga.ficharJugador(5, "55555551N");
        liga.ficharJugador(5, "55555552P");
        liga.ficharJugador(5, "55555553Q");

        liga.ficharJugador(6, "66666661R");
        liga.ficharJugador(6, "66666662S");
        liga.ficharJugador(6, "66666663T");
    }
}

import java.util.Scanner;

public class Tema1Ej2 {
    public static void main(String[] args){

        String dni;

        String letrasCadena = "TRWAGMYFPDXBNJZSQVHLCKE";

        Scanner sc = new Scanner(System.in);

        do {

            System.out.println("Introduce el DNI:...");

            dni = sc.next();

        }while(dni.length() != 8);

//        hay que comprobar tambien que es numero sino va a tirar el error en parseInt

        int numDni = Integer.parseInt(dni);

        int i = numDni % 23;

        String w = letrasCadena.substring(i, i+1);

        w = dni + w;

        System.out.printf("%nTu NIF es %s", w);

    }
}

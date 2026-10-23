import java.util.Scanner;

public class Menu {

    public static void main(String[] args){

        Scanner sc = new Scanner(System.in);

        System.out.print("Limite de libros por socio: ");

        int lim = sc.nextInt();
        sc.nextLine();

        Biblioteca biblioteca = new Biblioteca(lim);

        int opcion;

        do {

            System.out.println("\n----- BIBLIOTECA -----");
            System.out.println("1. Añadir libro");
            System.out.println("2. Añadir socio");
            System.out.println("3. Sacar libro");
            System.out.println("4. Devolver libro");
            System.out.println("5. Mostrar socios");
            System.out.println("0. Salir");

            System.out.print("Opcion: ");
            opcion = sc.nextInt();
            sc.nextLine();

            switch (opcion) {

                case 1: {
                    System.out.print("ISBN: ");
                    String isbn = sc.nextLine();

                    System.out.print("Titulo: ");
                    String titulo = sc.nextLine();

                    int resultado = biblioteca.addLibro(isbn, titulo);

                    outputs(resultado);

                    break;
                }

                case 2: {
                    System.out.print("DNI: ");
                    String dni = sc.nextLine();

                    System.out.print("Nombre: ");
                    String nombre = sc.nextLine();

                    System.out.print("Password: ");
                    String password = sc.nextLine();

                    int resultado = biblioteca.addSocio(dni, nombre, password);

                    outputs(resultado);

                    break;
                }

                case 3: {
                    System.out.print("DNI: ");
                    String dni = sc.nextLine();

                    System.out.print("Password: ");
                    String password = sc.nextLine();

                    System.out.print("ISBN: ");
                    String isbn = sc.nextLine();

                    int resultado = biblioteca.sacarLibro(dni, password, isbn);

                    outputs(resultado);



                    break;
                }

                case 4: {
                    System.out.print("ISBN: ");
                    String isbn = sc.nextLine();

                    int resultado = biblioteca.devolverLibro(isbn);

                    outputs(resultado);

                    break;
                }

                case 5:
                    biblioteca.showSocios();
                    break;

                case 0:
                    System.out.println("Fin del programa");
                    break;

                default:
                    System.out.println("Opcion incorrecta");
            }

        } while (opcion != 0);





    }

    public static void outputs(int out){

       switch (out){

           case 0 -> System.out.println("Operacion realizada correctamente");
           case -1 -> System.out.println("ERROR. Ya hay registrado otro libro con el mismo ISBN");
           case -2 -> System.out.println("ERROR. Ya hay registrado otro socio con el mismo DNI");
           case -3 -> System.out.println("ERROR: El socio no existe");
           case -4 -> System.out.println("ERROR: Contraseña incorrecta");
           case -5 -> System.out.println("ERROR: El socio ha alcanzado el limite de libros");
           case -6 -> System.out.println("ERROR: El libro no existe");
           case -7 -> System.out.println("ERROR: El libro no esta disponible");
           case -8 -> System.out.println("ERROR. El libro a devolver no ha sido prestado (su estado actual es\n" +
                   "disponible)");

       }

    }


}

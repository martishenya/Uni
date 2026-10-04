import java.util.Scanner;

public class Tema1Ej4 {
    public static void main(String[] args){

        Scanner sc = new Scanner(System.in);
        String isbnP;

        int indISBN = -1;
        String opc;




        System.out.println("Cuantos libros va a contener el catalogo de la libreria:");
        int numLibr = sc.nextInt();

        String[] isbn = new String[numLibr];
        int[] numIsbn = new int[numLibr];

        int numIsbnAux;

        System.out.println("Ahora introduce el ISBN para cada uno:");

        for(int i = 0; i < numLibr; i++){



            do{

                System.out.printf("%n[%d]: ", i+1);

                isbnP = sc.next();

                if(buscarISBN(isbn, isbnP) != -1) {

                    System.out.println("isbn introducido ya existe en la tienda");

                }

            }while(buscarISBN(isbn, isbnP) != -1);

            isbn[i] = isbnP;

        }

        for(int i = 0; i < numLibr; i++){

            System.out.printf("Ahora introduce el numero de libros que hay del numero %s: ", isbn[i]);
            numIsbn[i] = sc.nextInt();

        }


        do{
            do{

                System.out.println("Ahora introduce el ISBN que quieres comprar: ");
                isbnP = sc.next();

                indISBN = buscarISBN(isbn, isbnP);

                if(indISBN == -1){

                    System.out.println("No hay libro/-s del ISBN introducido, prueba otra vez..");

                }else if(numIsbn[indISBN] == 0){

                    System.out.println("No se puede realizar la compra de este ISBN porque no hay libros en stock");

                }

            }while(indISBN == -1 || numIsbn[indISBN] == 0);




            do{

                System.out.println("El numero de libros que quieres comprar: ");
                numIsbnAux = sc.nextInt();



                if(numIsbnAux < 1){

                    System.out.println("El numero introducido es incorrecto, prueba otra vez..");

                }else if(numIsbnAux > numIsbn[indISBN] ){

                    System.out.println("El numero introducido es mayor que hay libros en stock");

                }

            }while(numIsbnAux > numIsbn[indISBN] || numIsbnAux < 1);


            numIsbn[indISBN] -= numIsbnAux;


            System.out.println("Deseas realizar otra compra?[SI/NO]");
            opc = sc.next();

        }while(opc.equalsIgnoreCase("SI"));

        System.out.println("Final stock: ");

        for(int j = 0; j < numLibr; j++){

            System.out.printf("%nISBN: %s, numero de libros: %d", isbn[j], numIsbn[j]);

        }



    }

    public static int buscarISBN(String[] isbnF, String isbnPF){

        for(int i = 0; i < isbnF.length; i++){

            if(isbnPF.equals(isbnF[i])){

                return i;

            }

        }

        return -1;

    }
}

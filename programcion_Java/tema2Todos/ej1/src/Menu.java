import java.util.Scanner;

public class Menu {

    private Scanner sc;
    private Tienda tienda;

    public Menu() {
        sc = new Scanner(System.in);
        tienda = new Tienda();
    }

    public void iniciar(){

        int opc;

        do{

            System.out.println("****************** MENU ******************");
            System.out.println("Elige la opcion: ");

            System.out.println("1. Introducir nuevo producto ");
            System.out.println("2. Actualizar el stock del producto ");
            System.out.println("3. Mostrar catalogo ");
            System.out.println("4. Comprar el producto ");
            System.out.println("5. Mostrar catalogo por categorias ");
            System.out.println("0. Salir");

            opc = sc.nextInt();
            sc.nextLine();

            switch (opc){
                case 1 -> {

                    System.out.print("Código: ");

                    int codigo = sc.nextInt();
                    sc.nextLine();

                    System.out.print("Nombre: ");
                    String nombre = sc.nextLine();

                    System.out.print("Categoría: ");
                    String categoria = sc.nextLine();

                    System.out.print("Precio: ");
                    double precio = sc.nextDouble();
                    sc.nextLine();

                    int res = tienda.addProducto(codigo, nombre, categoria, precio);

                    if (res == 0) {

                        System.out.println("Se ha añadido el articulo correctamente!");


                    } else {

                        System.out.println("El código del artículo esta repetido");

                    }
                }
                case 2 -> {

                    System.out.print("Código: ");

                    int codigo = sc.nextInt();
                    sc.nextLine();

                    System.out.print("Stock: ");

                    double stock = sc.nextDouble();
                    sc.nextLine();

                    int res = tienda.addStock(codigo, stock);

                    if (res == 0) {

                        System.out.println("Se ha actualizado el stock correctamente");


                    } else if(res == -2){

                        System.out.println("El código del articulo no existe");

                    } else {

                        System.out.println("El stock no puede ser negativo");

                    }

                }

                case 3 -> {

                    tienda.mostrarCatalogo();

                }

                case 4 -> {

                    System.out.print("Código: ");

                    int codigo = sc.nextInt();
                    sc.nextLine();

                    System.out.print("Kilogramos: ");

                    double kg = sc.nextDouble();
                    sc.nextLine();

                    int res = tienda.vender(codigo, kg);

                    if (res == 0) {

                        System.out.println("Se ha realizado la venta correctamente");


                    } else if(res == -2){

                        System.out.println("El código del articulo no existe");

                    } else {

                        System.out.println("No hay stock suficiente");

                    }

                }

                case 5 -> {

                    tienda.mostrarCatalogoPorCategoria();

                }

                case 0 -> {
                    System.out.println("Hasta luego!");
                }

                default ->{
                    System.out.println("El valor introducido no es correcto, prueba otra vez");
                }
            }
        }while(opc != 0);

    }

}

import java.util.ArrayList;

public class Tienda {

    private ArrayList<Producto> productos;

    public Tienda() {
        this.productos = new ArrayList<>();
    }

    public int addProducto(int codigo, String nombre, String categoria, double precio){

        for(Producto p : productos){

            if (p.getCodigo() == codigo){

                return(-1);

            }

        }

        Producto product = new Producto(codigo, nombre, categoria, precio);

        productos.add(product);

        return 0;
    }


    public int addStock(int codigo, double stock){

        if(stock < 0){

            return(-3);

        }

            for(Producto p : productos){

            if(p.getCodigo() == codigo){

                p.setStock(p.getStock() + stock);

                return(0);
            }

        }

        return(-2);


    }

    public void mostrarCatalogo(){

        for(Producto p : productos){

            System.out.println(p);

        }
    }

    public int vender(int codigo, double kilogramos){

        for(Producto p : productos){

            if(p.getCodigo() == codigo){

                if(p.getStock() < kilogramos){

                    return -4;
                }else{

                    p.setStock(p.getStock() - kilogramos);
                    System.out.printf("%nEl precio de la venta: %.2f", kilogramos * p.getPrecio());

                    return 0;
                }

            }

        }
        return -2;

    }

    public void mostrarCatalogoPorCategoria(){

         String[] categorias =
                {"legumbres", "arroz", "pasta", "especias", "cereales"};

        for(String c : categorias){

            int counter = 0;

            for(Producto p : productos){

                if(c.equalsIgnoreCase(p.getCategoria())){

                    counter++;

                    if(counter == 1){

                        System.out.println(c.toUpperCase());

                    }

                    System.out.println(p.toStringSinCategoria());

                }

            }

        }
    }

}

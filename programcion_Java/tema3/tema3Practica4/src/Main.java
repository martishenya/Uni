import Controlador.FiltroPrendas;
import condiciones.CondAnd;
import condiciones.CondTallaIgual;
import condiciones.Condicion;
import modelo.Color;
import modelo.Prenda;
import modelo.Talla;
import modelo.Tipo;

import java.util.ArrayList;

//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class Main {
    public static void main(String[] args) {

        ArrayList<Prenda> prendas = new ArrayList<>();

        prendas.add(new Prenda("Zara", 29.99, Tipo.CAMISA, Color.AZUL, Talla.M));
        prendas.add(new Prenda("Mango", 49.95, Tipo.PANTALON, Color.VERDE, Talla.L));
        prendas.add(new Prenda("Patrizia Pepe", 139.90, Tipo.FALDA, Color.VERDE, Talla.S));
        prendas.add(new Prenda("Massimo Dutti", 89.99, Tipo.CHAQUETA, Color.AMARILLO, Talla.M));
        prendas.add(new Prenda("Zara", 19.99, Tipo.CAMISA, Color.ROJO, Talla.XS));
        prendas.add(new Prenda("Patrizia Pepe", 175.00, Tipo.FALDA, Color.VERDE, Talla.M));
        prendas.add(new Prenda("Levi's", 79.95, Tipo.PANTALON, Color.AZUL, Talla.L));
        prendas.add(new Prenda("Mango", 59.99, Tipo.CHAQUETA, Color.ROJO, Talla.L));
        prendas.add(new Prenda("Zara", 35.50, Tipo.FALDA, Color.AMARILLO, Talla.S));
        prendas.add(new Prenda("Patrizia Pepe", 120.00, Tipo.FALDA, Color.VERDE, Talla.L));

        //Condicion c = new CondTallaIgual( Talla.L );
        //Condicion c1 = Condicion.talla( Talla.L );
        //Condicion c2 = Condicion.precioMayor(50);

        //Condicion c = new CondAnd(c1,c2);

        Condicion c = Condicion.talla( Talla.L )
                .and( Condicion.precioMayor(50) );


        ArrayList<Prenda> prendasFiltradas = FiltroPrendas.filtrar(prendas,c);

        for ( Prenda prenda : prendasFiltradas){
            System.out.println(prenda);
        }

    }
}
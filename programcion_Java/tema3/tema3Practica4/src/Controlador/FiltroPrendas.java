package Controlador;

import condiciones.Condicion;
import modelo.Prenda;

import java.util.ArrayList;

public class FiltroPrendas {

    public static ArrayList<Prenda> filtrar(ArrayList<Prenda> prendas, Condicion c){
        ArrayList<Prenda> filtradas = new ArrayList<>();

        //Filtro
        for(Prenda prenda : prendas){
            if( c.apply(prenda) ){
                filtradas.add(prenda);
            }
        }

        return filtradas;
    }
}

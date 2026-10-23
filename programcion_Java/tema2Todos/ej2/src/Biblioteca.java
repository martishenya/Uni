import java.util.ArrayList;
import java.util.Scanner;

public class Biblioteca {

    private ArrayList<Libro> librosBib;

    private ArrayList<Socio> socios;

    private int limLibr;

    public Biblioteca( int limLibr) {
        librosBib = new ArrayList<Libro>();
        socios = new ArrayList<Socio>();
        this.limLibr = limLibr;
    }

    private Libro buscarLibro(String isbn){

        for (Libro l : librosBib){

            if(l.getIsbn().equalsIgnoreCase(isbn)){
                return l;
            }

        }
        return null;
    }

    private Socio buscarSocio(String dni){

        for (Socio s : socios){

            if(s.getDni().equalsIgnoreCase(dni)){
                return s;
            }

        }
        return null;
    }


    public int addLibro(String isbn, String titulo){

        if(buscarLibro(isbn) != null){

            return -1;

        }else{

            Libro l = new Libro(isbn, titulo);

            librosBib.add(l);

            return 0;
        }

    }


    public int addSocio(String dni, String nombre, String contrasena){


        if(buscarSocio(dni) != null){

            return -2;

        }else{

            Socio s = new Socio(dni, nombre, contrasena);

            socios.add(s);

            return 0;
        }

    }


    public int sacarLibro(String dni,String contr, String isbn){

        Socio socio = buscarSocio(dni);

        Libro libro = buscarLibro(isbn);


        if(socio == null){

            return -3;

        }else if(!socio.getPassword().equals(contr) ){

            return -4;

        }else if(socio.countLibrosPrestados() >= limLibr){

            return -5;

        }else if(libro == null){


            return -6;
        }else if(!libro.isDisponible()){

            return -7;

        }else{


            libro.setDisponible(false);
            libro.setSocio(socio);
            socio.addLibroPrestado(libro);

            return 0;
        }

    }

    public int devolverLibro(String isbn){

        Libro libro = buscarLibro(isbn);

        if(libro == null){


            return -6;
        }else if(libro.isDisponible()){

            return -8;

        }else{

            Socio socio = libro.getSocio();

            libro.setDisponible(true);
            libro.setSocio(null);

            socio.removeLibroPrestado(libro);

            return 0;

        }

    }

    public void showSocios(){

        for (Socio s : socios) {
            System.out.println(s);
        }

    }


//

}

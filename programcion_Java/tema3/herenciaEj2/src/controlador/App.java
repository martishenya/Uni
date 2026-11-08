package controlador;

import vehiculos.Automovil;
import vehiculos.Camion;
import vehiculos.Motocicleta;
import vehiculos.Vehiculo;

import java.util.ArrayList;
import java.util.Scanner;

public class App {

    private ArrayList<Vehiculo> vehiculos;

    public App() {
        this.vehiculos = new ArrayList<>();
    }

    public int addVehiculo(Vehiculo v) {

        vehiculos.add(v);
        return 0;
    }

    public void listarVehiculo() {

        for (Vehiculo v : vehiculos) {

            System.out.println(v.obtenerDiscripcion());

        }
    }


    public Vehiculo buscarVehiculo(String marca, String modelo) {

        for (Vehiculo v : vehiculos) {

            if (v.getMarca().equalsIgnoreCase(marca) && v.getModelo().equalsIgnoreCase(modelo)) {

                return v;
            }
        }
        return null;
    }


    public int eliminarVehiculo(String marca, String modelo) {

        Vehiculo vehiculo = buscarVehiculo(marca, modelo);

        if (vehiculo == null) {
            return -1;
        } else {
            vehiculos.remove(vehiculo);
            return 0;

        }

    }

//    queria hacer el metodo de modificar sin usar el Scanner dentro del App
//    y decidi hacerlo a traves de sobrecarga de metodos
//    ahora lo tengo bastante largo, perdon, pero espero que es mas correcto hacerlo asi

    //este es para automovil
    public int modificarV(String marca,
                          String modelo,
                          String marcaN,
                          String modeloN,
                          int annoN,
                          String combustibleN,
                          int puertasN) {


        Vehiculo v = buscarVehiculo(marca, modelo);

        if (v == null) {
            return -1;
        } else if (!(v instanceof Automovil)) {
            return -2;
        } else {

//            este metodo esta en el Vehiculo y cambia lo que esta en comun
            v.modificarVehiculo(marcaN, modeloN, annoN);

//            este metodo cada clase especifico tiene su propio
            ((Automovil) v).modificar(combustibleN, puertasN);

            return 0;
        }
    }

//    motocicleta
    public int modificarV(String marca,
                          String modelo,
                          String marcaN,
                          String modeloN,
                          int annoN,
                          int cilindradoN) {

        Vehiculo v = buscarVehiculo(marca, modelo);

        if (v == null) {
            return -1;
        } else if (!(v instanceof Motocicleta)) {
            return -2;
        } else {

            v.modificarVehiculo(marcaN, modeloN, annoN);

            ((Motocicleta) v).modificar(cilindradoN);

            return 0;
        }


    }

//    camion
    public int modificarV(String marca,
                          String modelo,
                          String marcaN,
                          String modeloN,
                          int annoN,
                          int cargaN,
                          int ejesN) {

        Vehiculo v = buscarVehiculo(marca, modelo);

        if (v == null) {
            return -1;
        } else if (!(v instanceof Camion)) {
            return -2;
        } else {

            v.modificarVehiculo(marcaN, modeloN, annoN);
//       cambio el tipo al especifico para poder pasar lo al metodo correspondiente
//            Camion с = (Camion) v;
            ((Camion) v).modificar(cargaN, ejesN);

            return 0;
        }

    }

}


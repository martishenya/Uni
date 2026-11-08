import controlador.App;
import vehiculos.Automovil;
import vehiculos.Camion;
import vehiculos.Motocicleta;

public class Main {
    public static void main(String[] args){

        App app = new App();

        app.addVehiculo(new Automovil("Opel", "Corsa", 2010, "Diesel", 5));
        app.addVehiculo(new Motocicleta("Yamaha", "Virago", 2001, 512));
        app.addVehiculo(new Camion("Volvo", "Truck", 2222, 3, 2));
        app.listarVehiculo();
    }
}

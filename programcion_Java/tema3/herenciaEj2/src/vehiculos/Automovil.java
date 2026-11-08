package vehiculos;

public class Automovil extends Vehiculo{

    private String combustible;
    private int puertas;

    public Automovil(String marca, String modelo, int anno, String combustible, int puertas) {
        super(marca, modelo, anno);
        this.combustible = combustible;
        this.puertas = puertas;
    }

    public void setCombustible(String combustible) {
        this.combustible = combustible;
    }

    public void setPuertas(int puertas) {
        this.puertas = puertas;
    }

    public void modificarAutomovil(String combustible, int puertas){

        this.combustible = combustible;
        this.puertas = puertas;

    }

    public void modificar(String combustible, int puertas){

        this.combustible = combustible;
        this.puertas = puertas;

    }

    @Override
    public String obtenerDiscripcion() {
        return marca + " " + modelo;
    }
}

package vehiculos;

public class Motocicleta extends Vehiculo{

    private int cilindrado;

    public Motocicleta(String marca, String modelo, int anno, int cilindrado) {
        super(marca, modelo, anno);
        this.cilindrado = cilindrado;
    }

    public void setCilindrado(int cilindrado) {
        this.cilindrado = cilindrado;
    }

    public void modificar(int cilindrado){

        this.cilindrado = cilindrado;

    }

    @Override
    public String obtenerDiscripcion() {
        return marca + " " + modelo + " " + cilindrado;
    }
}

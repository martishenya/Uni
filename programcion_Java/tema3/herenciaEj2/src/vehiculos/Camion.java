package vehiculos;

public class Camion extends Vehiculo{

    private int carga;
    private int ejes;

    public Camion(String marca, String modelo, int anno, int carga, int ejes) {
        super(marca, modelo, anno);
        this.carga = carga;
        this.ejes = ejes;
    }

    public void setCarga(int carga) {
        this.carga = carga;
    }

    public void setEjes(int ejes) {
        this.ejes = ejes;
    }

    public void modificar(int carga, int ejes){

        this.carga = carga;
        this.ejes = ejes;

    }

    @Override
    public String obtenerDiscripcion() {
        return modelo + " " + marca + " " + anno + " " + carga + " " + ejes + " ";
    }
}

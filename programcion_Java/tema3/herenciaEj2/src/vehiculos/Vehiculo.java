package vehiculos;

public abstract class Vehiculo {

    protected String marca;
    protected String modelo;
    protected int anno;

    public Vehiculo(String marca, String modelo, int anno) {
        this.marca = marca;
        this.modelo = modelo;
        this.anno = anno;
    }



    public abstract String obtenerDiscripcion();

    public String getMarca() {
        return marca;
    }

    public String getModelo() {
        return modelo;
    }
}

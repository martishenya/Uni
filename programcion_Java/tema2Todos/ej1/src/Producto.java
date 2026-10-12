
public class Producto{

    private int codigo;
    private String nombre;
    private String categoria;
    private double precio;
    private double stock;

    public Producto(int codigo, String nombre, String categoria, double precio) {
        this.codigo = codigo;
        this.nombre = nombre;
        this.categoria = categoria;
        this.precio = precio;
        this.stock = 0;
    }

    public int getCodigo() {
        return codigo;
    }

//    public void setCodigo(int codigo) {
//        this.codigo = codigo;
//    }

    public String getNombre() {
        return nombre;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    public String getCategoria() {
        return categoria;
    }

    public void setCategoria(String categoria) {
        this.categoria = categoria;
    }

    public double getPrecio() {
        return precio;
    }

    public void setPrecio(double precio) {
        this.precio = precio;
    }

    public double getStock() {
        return stock;
    }

    public void setStock(double stock) {
        this.stock = stock;
    }

    @Override
    public String toString() {
        return String.format("%d - %s%n%s%nStock: %f Kg%nPrecio: %f Eur/Kg", codigo, nombre, categoria, stock, precio);
    }

    public String toStringSinCategoria() {
        return String.format("%d - %s%nStock: %f Kg%nPrecio: %f Eur/Kg", codigo, nombre, stock, precio);
    }
}
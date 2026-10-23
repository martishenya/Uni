import java.util.ArrayList;

public class Socio {

    private String dni;
    private String nombre;
    private String password;

    private ArrayList<Libro> librosSoc;

    public Socio(String dni, String nombre,String password) {
        this.dni = dni;
        this.nombre = nombre;
        this.password = password;
        librosSoc = new ArrayList<>();
    }

    public String getDni() {
        return dni;
    }

    public void setDni(String dni) {
        this.dni = dni;
    }

    public String getPassword() {
        return password;
    }

    public void setPassword(String password) {
        this.password = password;
    }

    public String getNombre() {
        return nombre;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    public ArrayList<Libro> getLibrosPrestados(){

        return librosSoc;
    }

    public int countLibrosPrestados(){

        return librosSoc.size();

    }

    public void addLibroPrestado(Libro libro){
        librosSoc.add(libro);
    }

    public void removeLibroPrestado(Libro libro){

        librosSoc.remove(libro);

    }

    @Override
    public String toString() {

        String output = dni + " - " + nombre + "\n";

        for(Libro l : librosSoc){

            output += "\t" + l.getIsbn() + ": " + l.getTitulo()+ "\n";

        }

        output += "\n";


        return output;
    }
}

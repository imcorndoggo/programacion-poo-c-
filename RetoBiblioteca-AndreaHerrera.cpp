//Andrea Nicole Herrera Cienfuegos
//Reto: Biblioteca
#include <iostream>
#include <string>
#include <vector>
#include <limits>   


class Libro {
public:
    std::string titulo;
    std::string autor;
    int anioPublicacion;
    bool estaDisponible; 

    Libro()
        : anioPublicacion(0), estaDisponible(true) {}

    Libro(const std::string& t, const std::string& a, int anio, bool disponible = true)
        : titulo(t), autor(a), anioPublicacion(anio), estaDisponible(disponible) {}

    void mostrarDetallesCompletos() const {
        std::cout << "___________________\n";
        std::cout << "Titulo: " << titulo << "\n";
        std::cout << "Autor: " << autor << "\n";
        std::cout << "Año: " << anioPublicacion << "\n";
        std::cout << "Estado: " << (estaDisponible ? "Disponible" : "Prestado") << "\n";
    }
};


class Biblioteca {
private:
    std::vector<Libro> coleccion;

    static bool mismosTitulos(const std::string& a, const std::string& b) {
        return a == b; 
    }

public:

    void agregarLibro(const Libro& nuevoLibro) {
        if (buscarLibro(nuevoLibro.titulo) != nullptr) {
            std::cout << "No se agrego. Ya existe un libro con el titulo \""
                      << nuevoLibro.titulo << "\".\n";
            return;
        }
        coleccion.push_back(nuevoLibro);
        std::cout << "Libro agregado correctamente.\n";
    }

    void mostrarInventario() const {
        if (coleccion.empty()) {
            std::cout << "La biblioteca esta vacia.\n";
            return;
        }
        std::cout << "\n--- INVENTARIO ---\n";
        for (const auto& libro : coleccion) {
            libro.mostrarDetallesCompletos();
        }
    }

    
    Libro* buscarLibro(const std::string& tituloBuscado) {
        for (auto& libro : coleccion) {
            if (mismosTitulos(libro.titulo, tituloBuscado)) {
                return &libro;
            }
        }
        return nullptr;
    }

    void prestarLibro(const std::string& tituloPrestamo) {
        Libro* libro = buscarLibro(tituloPrestamo);
        if (libro == nullptr) {
            std::cout << "No se encontro el libro \"" << tituloPrestamo << "\".\n";
            return;
        }
        if (!libro->estaDisponible) {
            std::cout << "El libro \"" << libro->titulo << "\" ya esta prestado.\n";
            return;
        }
        libro->estaDisponible = false;
        std::cout << "Prestamo realizado: \"" << libro->titulo << "\".\n";
    }

    void devolverLibro(const std::string& tituloDevolucion) {
        Libro* libro = buscarLibro(tituloDevolucion);
        if (libro == nullptr) {
            std::cout << "No se encontro el libro \"" << tituloDevolucion << "\".\n";
            return;
        }
        if (libro->estaDisponible) {
            std::cout << "El libro \"" << libro->titulo << "\" ya estaba disponible.\n";
            return;
        }
        libro->estaDisponible = true;
        std::cout << "Devolucion registrada: \"" << libro->titulo << "\".\n";
    }
};


void limpiarBuffer() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}


int main() {
    Biblioteca miBiblioteca;
    int opcion = 0;

   
    miBiblioteca.agregarLibro(Libro("El Hobbit", "J.R.R. Tolkien", 1937));
    miBiblioteca.agregarLibro(Libro("Cien años de soledad", "Gabriel Garcia Marquez", 1967));
    miBiblioteca.agregarLibro(Libro("1984", "George Orwell", 1941));
    miBiblioteca.agregarLibro(Libro("2001: Odisea en el Espacio", "Artur C. Clarke", 1968));
    miBiblioteca.agregarLibro(Libro("The catcher in the rye", "J.D. Salinger", 1951));
    miBiblioteca.agregarLibro(Libro("To kill a mockingbird", "Harper Lee", 1960));

    while (true) {
        std::cout << "\n--- BIBLIOTECA DIGITAL ---\n";
        std::cout << "1. Anadir libro\n";
        std::cout << "2. Mostrar inventario\n";
        std::cout << "3. Prestar libro\n";
        std::cout << "4. Devolver libro\n";
        std::cout << "5. Salir\n";
        std::cout << "Seleccione una opcion: ";
        if (!(std::cin >> opcion)) {
            std::cin.clear();
            limpiarBuffer();
            std::cout << "Opcion invalida.\n";
            continue;
        }
        limpiarBuffer();

        if (opcion == 1) {
            std::string titulo, autor;
            int anio = 0;
            std::cout << "Titulo: ";
            std::getline(std::cin, titulo);
            std::cout << "Autor: ";
            std::getline(std::cin, autor);
            std::cout << "Año de publicacion: ";
            if (!(std::cin >> anio)) {
                std::cin.clear();
                limpiarBuffer();
                std::cout << "Año invalido. Operacion cancelada.\n";
                continue;
            }
            limpiarBuffer();

            miBiblioteca.agregarLibro(Libro(titulo, autor, anio, true));

        } else if (opcion == 2) {
            miBiblioteca.mostrarInventario();

        } else if (opcion == 3) {
            std::string titulo;
            std::cout << "Titulo del libro a prestar: ";
            std::getline(std::cin, titulo);
            miBiblioteca.prestarLibro(titulo);

        } else if (opcion == 4) {
            std::string titulo;
            std::cout << "Titulo del libro a devolver: ";
            std::getline(std::cin, titulo);
            miBiblioteca.devolverLibro(titulo);

        } else if (opcion == 5) {
            std::cout << "Hasta luego.\n";
            break;

        } else {
            std::cout << "Opcion invalida.\n";
        }
    }

    return 0;
}

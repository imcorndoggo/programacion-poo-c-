//Andrea Nicole Herrera Cienfuegos 000032
//Reto: Herencias 

#include <iostream>
#include <string>

class Instrumento {
protected: // accesible para esta clase y sus hijas
    std::string marca;
    std::string modelo;

public:
    Instrumento(const std::string& marca, const std::string& modelo)
        : marca(marca), modelo(modelo) {
        std::cout << "Se ha creado un instrumento generico."<<std::endl;
    }

    void conectar() {
        std::cout << "El instrumento " << marca << " " << modelo << " esta conectado."<<std::endl;
    }

    void desconectar() {
        std::cout << "El instrumento " << marca << " " << modelo << " esta desconectado."<<std::endl;
    }
};

class Guitarra : public Instrumento {
private:
    int numeroDeCuerdas;

public:
    Guitarra(const std::string& marca, const std::string& modelo, int cuerdas)
        : Instrumento(marca, modelo), numeroDeCuerdas(cuerdas) {
        std::cout << "Y se ha especificado que es una Guitarra."<<std::endl;
    }

    void afinar() {
        std::cout << "La " << marca << " " << modelo << " esta afinando... "<<std::endl;
    }

    void mostrarDetalles() const {
        std::cout << "--- Detalles de la Guitarra ---";
        std::cout << "Marca:   " << marca << " "<<std::endl;
        std::cout << "Modelo:  " << modelo << " "<<std::endl;
        std::cout << "Cuerdas: " << numeroDeCuerdas << " "<<std::endl;
    }
};

//Ish quería hacer uno de Transformers, pero pense que me vería muy nerd ( >^<)

int main() {
    std::cout << "Creando una Guitarra..."<<std::endl;
    Guitarra miGuitarra("Fender", "Stratocaster", 6);

    std::cout << "Probando metodos..."<<std::endl;
    miGuitarra.conectar();
    miGuitarra.afinar();
    miGuitarra.mostrarDetalles();
    miGuitarra.desconectar();

    return 0;
}

//Andrea Nicole Herrera Cienfuegos
//Reto 2: Gestión de Vehículos de una Concesionaria


#include <iostream>
#include <string>
#include <vector>
#include <iomanip> 


class Vehiculo {
protected:
    std::string marca;
    std::string modelo;
    int anio;
    double precioBase;

public:
    Vehiculo(const std::string& marca, const std::string& modelo, int anio, double precioBase)
        : marca(marca), modelo(modelo), anio(anio), precioBase(precioBase) {}

    virtual ~Vehiculo() = default; 

    virtual double calcularPrecioFinal() const = 0;

    
    const std::string& getMarca()  const { return marca; }
    const std::string& getModelo() const { return modelo; }
    int  getAnio() const { return anio; }
    double getPrecioBase() const { return precioBase; }
};

//ish estudie aparte y aún así la mitad de estas cosas son muy confusas ( ;>[]<)

class Auto : public Vehiculo {
    int numeroPuertas;

public:
    Auto(const std::string& marca, const std::string& modelo, int anio, double precioBase, int numeroPuertas)
        : Vehiculo(marca, modelo, anio, precioBase), numeroPuertas(numeroPuertas) {}

    double calcularPrecioFinal() const override {
        
        return precioBase * 1.15;
    }

    int getNumeroPuertas() const { return numeroPuertas; }
};

//estará bien esto?? pregunto de manera seria, así me decian los de stack ( >^<)

class Moto : public Vehiculo {
    int cilindrada; 

public:
    Moto(const std::string& marca, const std::string& modelo, int anio, double precioBase, int cilindrada)
        : Vehiculo(marca, modelo, anio, precioBase), cilindrada(cilindrada) {}

    double calcularPrecioFinal() const override {
        return precioBase * 1.10;
    }

    int getCilindrada() const { return cilindrada; }
};


class Camion : public Vehiculo {
    double capacidadToneladas;

public:
    Camion(const std::string& marca, const std::string& modelo, int anio, double precioBase, double capacidadToneladas)
        : Vehiculo(marca, modelo, anio, precioBase), capacidadToneladas(capacidadToneladas) {}

    double calcularPrecioFinal() const override {
        return precioBase * 1.20;
    }

    double getCapacidadToneladas() const { return capacidadToneladas; }
};

int main() {
    std::cout << std::fixed << std::setprecision(2);

    
    std::vector<Vehiculo*> inventario;

    
    Vehiculo* a1 = new Auto("Toyota", "Corolla", 2020, 15000.0, 4);
    Vehiculo* m1 = new Moto("Yamaha", "MT-03", 2022, 5200.0, 321);

    inventario.push_back(a1);
    inventario.push_back(m1);


    for (const Vehiculo* v : inventario) {
        std::cout << v->getMarca() << " " << v->getModelo()
                  << " (" << v->getAnio() << ")  "
                  << "Precio base: $" << v->getPrecioBase()
                  << "  ->  Precio final: $" << v->calcularPrecioFinal()
                  << " ";
    }

    for (Vehiculo* v : inventario) {
        delete v;
    }
    inventario.clear();

    return 0;
}

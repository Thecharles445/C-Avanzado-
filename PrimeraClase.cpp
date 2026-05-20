#include<iostream>
//Primer Ejercicio: 
//1) Crear una clase llamada Persona con atributos como nombre, edad y genero.
//2) Crear sus metodos o funciones correspondientes.
//3) Métodos para calcular el IMC y el estado nutricional

using namespace std;

class Persona {
    //Variable privada para almcenar datos que no se pueden cambiar
    private: 
    string nombre;
    int edad;
    string genero;
    double peso;   // en kg
    double altura; // en metros
    
    //Variables publicas que si se pueden cambiar 
    public: 
    Persona(string nombre, int edad, string genero, double peso, double altura){
        this->nombre = nombre;
        this->edad = edad;
        this->genero = genero;
        this->peso = peso;
        this->altura = altura;
    }
    //Funciones get para poder llamar la variable
    string getNombre(){
        return this->nombre;
    }
    int getEdad(){
        return this->edad;
    }
    string getGenero(){
        return this->genero;
    }
    
    double getPeso(){
        return this->peso;
    }
    double getAltura(){
        return this->altura;
    }
    
    //Funciones eet para poder cambiar el valor de la variable
    void setNombre(string nombre){
        this->nombre = nombre;
    }
    void setEdad(int edad){
        this->edad = edad;
    }
    void setGenero(string genero){
        this->genero = genero;
    }
    void setPeso(double peso){
        this->peso = peso;
    }
    void setAltura(double altura){
        this->altura = altura;
    }

    // Metodo que calcula el valor numerico del IMC (Peso / Altura^2)
    double calcularIMC() {
        if (this->altura <= 0) {
            return 0; // Validacion por si la altura es 0 y evitar error de división
        }
        return this->peso / (this->altura * this->altura);
    }

    // Método que evalua el IMC y devuelve una categoria en texto
    string estadoNutricional() {
        double imc = calcularIMC();
        
        if (imc < 18.5) {
            return "Bajo peso";
        } else if (imc >= 18.5 && imc < 25.0) {
            return "Peso normal";
        } else if (imc >= 25.0 && imc < 30.0) {
            return "Sobrepeso";
        } else {
            return "Obesidad";
        }
    }
};

int main(){
    // Creamos un objeto de la clase Persona
    Persona p1("Carlos", 25, "Masculino", 75.5, 1.78);

    // Mostramos los resultados en la consola
    cout << "--- Datos de la Persona ---" << endl;
    cout << "Nombre: " << p1.getNombre() << endl;
    cout << "Edad: " << p1.getEdad() << " anos" << endl;
    cout << "Peso: " << p1.getPeso() << " kg" << endl;
    cout << "Altura: " << p1.getAltura() << " m" << endl;
    cout << "\n--- Resultados de Salud ---" << endl;
    cout << "Su IMC es: " << p1.calcularIMC() << endl;
    cout << "Estado nutricional: " << p1.estadoNutricional() << endl;

    return 0;
}
// Ejercicio evaluatorio 3er bimestre
/*
  Integrantes
    Nombre: Alejandro
    Apellido: Kretzig
    Curso: 3TIC C
    
    Nombre: Tobias
    Apellido: German
    Curso: 3TIC C
  
Congisgnas
  Conexionado:
    En la protoboard, conectar 4 LEDs para que cada uno pueda ser controlado individualmente. Cada LED deberá tener su respectiva resistencia.
    Se debe conectar tambien, un pulsador que permita recibir información de un usuario.
    Indicar a continuación los pines a los cuales se conectó cada elemento y el valor de resistencias utilizado:
      Pines:
        Boton: 8
        LED1: 2
        LED2: 3
        LED3: 4
        LED4: 5
      Valor:
        R_boton: 5,6K
        R_LEDs: 330

  Progamas:
    Se deben entregar un programa distinto por cada punto. Los programas son una modificación entre ellos.
    El código deberá estar comentado indicando qué se propone hacer con cada línea de código
    1.  El primer programa sirve para corroborar la correcta conexión de los elementos de hardware.
        El mismo deberá encender TODOS los LEDs cuando se presione el pulsador y apagarlos cuando éste se suelte.
    2.  En el siguiente programa se deberá prender de a UN LED POR VEZ.
        Por cada pulsación se deberá apagar el LED prendido y prender el LED más próximo de la derecha.
        En caso de no haber, se deberá volver a empezar la vuelta, empezando desde el LED de la izquierda.
    3.  A continnuación se desea fabricar un contador binario de 4 bits.
        El programa deberá contar de 0 a 15 mostrando la cuenta actual a través de los 4 LEDs.
        Se interpreta 0 si el LED está apagado y 1 si el LED está prendido. 
        La cuenta aumenta cada vez que el pulsador es presionado, al llegar a 15 deberá volver a empezar en 0.
        IMPORTANTE: la cuenta debe aumentar UNA SOLA VEZ por cada pulsación.
    4. Opcional:
        Utilizando comunicación serie, se desea crear un programa que muestre mediante los LEDs, el nro ingresado en el monitor serie.
        El programa deberá mostrar el número binario prendiendo los LEDs según el criterio del programa 3.
        El nro mostrado será ingresado por el usuario mediante el monitor serie.
        IMPORTANTE: si el nro es mayor a 15 se deberá enviar un mensaje de error. 

*/ 

#define LED1 2
#define LED2 3
#define LED3 4
#define LED4 5

#define BOTON 8

bool ultimoEstado = false;
int numero = 0;

void setup() {
  pinMode(BOTON, INPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) { // si el serial esta disponible
    numero = Serial.readString().toInt(); // leer el numero del serial
    if (numero > 15) {
      Serial.println("El numero debe ser menor a 15");
    }
    Serial.println(numero);
    digitalWrite(LED4, bitRead(numero, 0));
    digitalWrite(LED3, bitRead(numero, 1));
    digitalWrite(LED2, bitRead(numero, 2));
    digitalWrite(LED1, bitRead(numero, 3));
  }
}


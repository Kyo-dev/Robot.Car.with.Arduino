#include <SoftwareSerial.h>

// CONTROL DEL MOTOR DERECHO
int Contor_In1 = 7;
int Contor_In2 = 6;

// CONTROL DEL MOTOR IZQUIERDO
int Contor_In3 = 5;
int Contor_In4 = 4;

// VARIABLES PARA CONTROLAR EL SENSOR ULTRASONICO O DE PROXIMIDAD
long dist;
long time;
int ledPrueba = 13;

//BT
SoftwareSerial BT1(10, 11); // RX | TX
int estado = 'g'; 

void setup() {
  // PIN DE LOS MOTORES
  pinMode(Contor_In1, OUTPUT);
  pinMode(Contor_In2, OUTPUT);
  pinMode(Contor_In3, OUTPUT);
  pinMode(Contor_In4, OUTPUT);

  // PIN PARA EL SENSOR DE PROXIMIDAD
  Serial.begin(9600);
  pinMode(9,INPUT); //9 ENTRADA DE DATOS ECCO
  pinMode(8, OUTPUT); //8 SALIDA DE DATOS TRIGGER
  pinMode (13,OUTPUT); // LED DEL PIN 13

  // FUNCIONES BT

  BT1.begin(9600); // inicia el puerto serial para comunicacion con el Bluetooth
  Serial.println("Esperando comandos AT:");
  Serial.println("Activando el modulo HC-04");

  // LEDS
  pinMode (3, OUTPUT); // Luz de freno
  pinMode (2, OUTPUT); // Luz blanca
  pinMode (12, OUTPUT); // Intermitente Izquierda
  pinMode (13, OUTPUT); // Intermitente Derecha
}

void loop() {
  Run();
  Sensor();
  bt();
}
// FUNCIONALIDAD DEL SENSOR
void Sensor(){
  digitalWrite(8,LOW);
  delayMicroseconds(5);
  digitalWrite(8, HIGH);
  delayMicroseconds(10);
  time = pulseIn(9, HIGH);
  dist = (0.017*time); // REVISAR LA FORMULA (CREO QUE SE TIENE QUE DIVIR ENTRE 2)
  delay(10);
  Serial.print("Distancia: ");
  Serial.print(dist);
  Serial.println(" cm/hr");
  if(dist <= 90){
    Stop();
    delay(1000);
    Reverse();
    delay(1000);
    int d = random(0, 3);
    if(d == 2){ 
      Serial.println("Girar a la izquierda");
      Serial.println(d);
      Left();
      delay(1000);
      Stop();
      delay(700);
    } else if (d == 1){
      Serial.println("Girar a la derecha");
      Serial.println(d);
      Right();
      delay(1000);
      Stop();
      delay(700);
    }
  } 
}

// FUNCIONALIDAD DE LOS MOTORES
void Run(){
  digitalWrite (2, HIGH);
  digitalWrite (3, LOW);
  digitalWrite(Contor_In1, HIGH);
  digitalWrite(Contor_In2, LOW);
  digitalWrite(Contor_In3, LOW);
  digitalWrite(Contor_In4, HIGH);
  
}

void Reverse(){
  digitalWrite (3, LOW);
  digitalWrite(Contor_In1, LOW);
  digitalWrite(Contor_In2, HIGH);
  digitalWrite(Contor_In3, HIGH);
  digitalWrite(Contor_In4, LOW);
}

void Stop(){
  digitalWrite (3, HIGH);
  digitalWrite (12, LOW);
  digitalWrite (13, LOW);
  digitalWrite(Contor_In1, LOW);
  digitalWrite(Contor_In2, LOW);
  digitalWrite(Contor_In3, LOW);
  digitalWrite(Contor_In4, LOW);
}

void Right(){
   for (int i= 0; i<= 5; i++){
    digitalWrite (13, HIGH);
    delay(200);
    digitalWrite (13, LOW);
    delay(200);
  }
  digitalWrite (3, LOW);
  digitalWrite(Contor_In1, HIGH);
  digitalWrite(Contor_In2, LOW);
  digitalWrite(Contor_In3, LOW);
  digitalWrite(Contor_In4, LOW);
}

void Left(){
  for (int i= 0; i<= 5; i++){
    digitalWrite (12, HIGH);
    delay(200);
    digitalWrite (12, LOW);
    delay(200);
  }
  digitalWrite (3, LOW);
  digitalWrite(Contor_In1, LOW);
  digitalWrite(Contor_In2, LOW);
  digitalWrite(Contor_In3, LOW);
  digitalWrite(Contor_In4, HIGH);
}

// CONDEXION BT

void bt (){
   if(BT1.available()>0){        // lee el bluetooth y almacena en estado
      estado = BT1.read();
      Serial.write(BT1.read()); //opcional
   }
   
   if(estado=='a'){           // Boton desplazar al Frente
     Run();
   }
  
  if(estado=='b'){          // Boton IZQ 
     Left();   

  }
  
  if(estado=='c'){         // Boton Parar
     Stop();
  }
  
  if(estado=='d'){          // Boton DER
     Right(); 
  } 
  
  if(estado=='e'){          // Boton Reversa
     Reverse();
  }
  
  if (estado =='f'){        // Boton ON se mueve sensando distancia 
 
  }
  
  if  (estado=='g'){        // Boton OFF, detiene los motores no hace nada 
  }
}


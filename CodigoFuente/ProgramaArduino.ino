// CONTROL DEL MOTOR DERECHO
int Contor_In1 = 7;
int Contor_In2 = 6;

// CONTROL DEL MOTOR IZQUIERDO
int Contor_In3 = 3;
int Contor_In4 = 4;
// CONTROL DEL MOTOR DERECHO
int Contor_In1 = 7;
int Contor_In2 = 6;

// CONTROL DEL MOTOR IZQUIERDO
int Contor_In3 = 3;
int Contor_In4 = 4;

// VARIABLES PARA CONTROLAR EL SENSOR ULTRASONICO O DE PROXIMIDAD
long dist;
long time;
int ledPrueba = 13;

void setup() {
  // PIN DE LOS MOTORES
  pinMode(Contor_In1, OUTPUT);
  pinMode(Contor_In2, OUTPUT);
  pinMode(Contor_In3, OUTPUT);
  pinMode(Contor_In4, OUTPUT);

  // PIN PARA EL SENSOR DE PROXIMIDAD
  Serial.begin(9600);
  pinMode(9,INPUT); //9 ENTRADA DE DATOS ECCO
  pinMode(8, OUTPUT); //10 SALIDA DE DATOS TRIGGER
  pinMode (13,OUTPUT); // LED DEL PIN 13
}

void loop() {
  // put your main code here, to run repeatedly:
  // Run();
  Sensor();
}
// FUNCIONALIDAD DEL SENSOR
void Sensor(){ // No esta instanciado en looP
  digitalWrite(8,LOW);
  delayMicroseconds(5);
  digitalWrite(8, HIGH);
  delayMicroseconds(10);
  time = pulseIn(9, HIGH);
  dist = (0.017*time); // REVISAR LA FORMULA (CREO QUE SE TIENE QUE DIVIR ENTRE 2)
  Serial.print("Distancia: ");
  Serial.print(dist);
  Serial.println(" cm/hr");
  delay(1000);
  if(dist < 50){
    digitalWrite(13,HIGH);
  } else{
    digitalWrite(13,LOW);
  }
}

// FUNCIONALIDAD DE LOS MOTORES
void Run(){
  digitalWrite(Contor_In1, HIGH);
  digitalWrite(Contor_In2, LOW);
  digitalWrite(Contor_In3, HIGH);
  digitalWrite(Contor_In4, LOW);
}

void Stop(){
  digitalWrite(Contor_In1, LOW);
  digitalWrite(Contor_In2, LOW);
  digitalWrite(Contor_In3, LOW);
  digitalWrite(Contor_In4, LOW);
}

void Right(){
  digitalWrite(Contor_In1, LOW);
  digitalWrite(Contor_In2, HIGH);
  digitalWrite(Contor_In3, HIGH);
  digitalWrite(Contor_In4, LOW);
}

void Left(){
  digitalWrite(Contor_In1, HIGH);
  digitalWrite(Contor_In2, LOW);
  digitalWrite(Contor_In3, LOW);
  digitalWrite(Contor_In4, HIGH);
}

// CODIGO BLUETOOTH
//VARIABLES DEL SENSOR
long dist;
long tiempo;

// MOTOR IZQUIERDO
int IN3 = 5; 
int IN4 = 4;

//MOTOR DERECHERO
int IN1 = 3;
int IN2 = 2;

void setup()
{
  Serial.begin(9600);
  pinMode(8,INPUT);
  pinMode(9, OUTPUT);
  pinMode (13,OUTPUT);
  pinMode (IN4, OUTPUT);
  pinMode (IN3, OUTPUT);
  pinMode (IN2, OUTPUT);
  pinMode (IN1, OUTPUT);
}
void loop()
{
  Motor();
  // Sensor();
}
void Motor()
{ 
  // Motor gira en un sentido
  digitalWrite (IN4, HIGH);
  digitalWrite (IN2, HIGH);
  digitalWrite (IN1, LOW); 
  delay(2000);
  // Motor no gira
  digitalWrite (IN4, LOW); 
  delay(500);
  // Motor gira en sentido inverso
  digitalWrite (IN3, HIGH);
  delay(2000);
  // Motor no gira
  digitalWrite (IN3, LOW); 
  delay(500); 
}


void Sensor(){ // No esta instanciado en loop
  //SENSOR ULTRASONICO
  digitalWrite(9,LOW);
  delayMicroseconds(5);
  digitalWrite(9, HIGH);
  delayMicroseconds(5);
  tiempo = pulseIn(8, HIGH);
  dist = int (0.017*tiempo); // REVISAR LA FORMULA (CREO QUE SE TIENE QUE DIVIR ENTRE 2)
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

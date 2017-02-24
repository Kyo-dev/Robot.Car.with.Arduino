long dist;
long tiempo;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(8,INPUT);
  pinMode(9, OUTPUT);
  pinMode (13,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

}

void Sensor(){ // No esta instanciado en loop
  //sensor ultrasonico
  
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
// FUNCIONALIDAD DE LOS MOTORES



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
  Sensor();
}
void Sensor(){
  //sensor ultrasonico
  
  digitalWrite(9,LOW);
  delayMicroseconds(5);
  digitalWrite(9, HIGH);
  delayMicroseconds(10);
  tiempo = pulseIn(8, HIGH);
  dist = int (0.017*tiempo);
  Serial.println("Distancia: ");
  Serial.println(dist);
  Serial.println(" cm");
  delay(1000);
  if(dist < 20){
    digitalWrite(13,HIGH);
  } else{
    digitalWrite(13,LOW);
  }
}


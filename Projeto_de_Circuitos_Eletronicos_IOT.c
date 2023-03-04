//          ****** Projeto de Circuitos Eletrônicos - IoT ******


const int TMP36 = A0; //Entrada do sensor na porta analógica do arduino: A0
float temperatura;  //Variável tipo float - inicia no 0
const int Buzzer = 12;  //Entrada do Buzzer na porta digital 12 do Arduino
const int led_11 = 11; // Entrada do led na porta digital 11 do Arduino 
const int Motor = 10; // Entrada do Motor na porta 10 do Arduino


void setup()
{
  Serial.begin(9600); // Taxa de comunicação da placa com o computador
  pinMode(Buzzer, OUTPUT);
  pinMode(led_11, OUTPUT);
  pinMode(Motor, OUTPUT);
}

void loop()
{
  temperatura = (float(analogRead(TMP36))*5/(1023))/0.01;
  delay(2000);
 
  
  Serial.print("Temperatura = ");
  Serial.print(temperatura);
  Serial.println(" *C"); 
    
if (temperatura >= 30)// Condição para ligar o motor
{ 
  digitalWrite(Motor, HIGH);
                               }
               
else
               
{ 
  digitalWrite(Motor, LOW);
                               }

if (temperatura >= 50) // Condição para ligar a buzina/Led
{
  digitalWrite(Buzzer, HIGH); // Aciona a buzina
  digitalWrite(led_11, HIGH); // Aciona o led
} 
  
else
  
{ digitalWrite(Buzzer, LOW); // Desativa a buzina
  digitalWrite(led_11, LOW); // Desativa o led
               
}
}

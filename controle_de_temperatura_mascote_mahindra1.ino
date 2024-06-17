int BOTAO = 3; 
int ESTADO_B1 = 0;
int MODO = 0;

int LED_VM = 13;
int LED_AM = 10;
int LED_VD = 8;

int RELE = 4;

int LM35 = A5;
int VALOR_ADC = 0;
float Volts = 0;
float Temperatura = 0;

void setup()
{
  	pinMode(BOTAO,INPUT);
  	pinMode(LM35, INPUT);
 	pinMode(LED_VM,OUTPUT);
    pinMode(LED_AM,OUTPUT);
    pinMode(LED_VD,OUTPUT);
    pinMode(RELE,OUTPUT);
  	Serial.begin(9600);
   
}

void loop()
{
  	ESTADO_B1 = digitalRead(BOTAO);
  	Serial.print("O Estado do Botao eh: ");
    Serial.println(ESTADO_B1);
  	
  	if(ESTADO_B1 == HIGH)
    {
      	MODO = !MODO;
      	delay(300);
    }
  
  	Serial.print("O MODO atual eh: ");
    Serial.println(MODO);
  
  	if(MODO == 1)
    {
        Serial.println("Modo Start Ativado");
           
        VALOR_ADC = analogRead(LM35);
      	Serial.print("O ADC eh: ");
   	    Serial.println(VALOR_ADC);
      
      	Volts = (VALOR_ADC * 5.0) / 1023.0;
        Serial.print("A Tensao eh: ");
   	    Serial.println(Volts);
      
      	Temperatura = Volts * 100.0;
        Serial.print("A Temperatura eh: ");
   	    Serial.println(Temperatura);
      
      	if(Temperatura >=32.0)
        {
           digitalWrite(RELE, HIGH);
           Serial.println("Refrigeracao Ativada");
        }
      
     	if(Temperatura < 20.0)
        {
           digitalWrite(RELE, LOW);
           Serial.println("Refrigeracao Desativada");
        }
      
      	if(Temperatura > 28)
        {
           digitalWrite(LED_VM,HIGH);
           digitalWrite(LED_AM,LOW);
           digitalWrite(LED_VD,LOW);
        }
      	
        if(Temperatura > 24 && Temperatura <= 28)
        {
           digitalWrite(LED_VM,LOW);
           digitalWrite(LED_AM,HIGH);
           digitalWrite(LED_VD,LOW);
        }
      
        if(Temperatura <= 24)
        {
           digitalWrite(LED_VM,LOW);
           digitalWrite(LED_AM,LOW);
           digitalWrite(LED_VD,HIGH);
        }
      
      
    }
  	else
    {
        Serial.println("Modo Stop Ativado");
     	digitalWrite(LED_VM,HIGH);
        digitalWrite(LED_AM,HIGH);
        digitalWrite(LED_VD,HIGH);
     	digitalWrite(RELE, LOW);
    }
  
  delay(300);
  
}
const int ledPisoInferior = 8;
const int ledPrimeiroAndar = 9;
const int ledPisoSuperior = 10;

// const int botaoPisoInferior = 2;   piso inferior
// const int botaoPrimeiroAndar = 3;  primeiro andar
// const int botaoPisoSuperior = 4;   piso superior

int andarAtual = 0; // Começa no piso inferior

bool subindo = true; // Começa subindo

void setup() {
  pinMode(ledPisoInferior, OUTPUT);
  pinMode(ledPrimeiroAndar, OUTPUT);
  pinMode(ledPisoSuperior, OUTPUT);

  // pinMode(botaoPisoInferior, INPUT_PULLUP);
  // pinMode(botaoPrimeiroAndar, INPUT_PULLUP);
  // pinMode(botaoPisoSuperior, INPUT_PULLUP);
  
  digitalWrite(ledPisoInferior, LOW);
  digitalWrite(ledPrimeiroAndar, LOW);
  digitalWrite(ledPisoSuperior, LOW);

  Serial.begin(9600);
}


// void loop() {
 // if (digitalRead(botaoPisoInferior) == LOW && andarAtual > 0) {
 //   andarAtual = 0;  // Vai para o piso inferior
 //   delay(500); // Debounce
 // } 
 // else if (digitalRead(botaoPrimeiroAndar) == LOW && andarAtual != 1) {
 //   andarAtual = 1;  // Vai para o primeiro andar
 //   delay(500); // Debounce
 // } 
 // else if (digitalRead(botaoPisoSuperior) == LOW && andarAtual < 2) {
 //   andarAtual = 2;  // Vai para o piso superior
 //   delay(500); // Debounce
 // }

void loop() {
  atualizaLEDs(andarAtual);

  Serial.println("Andar atual: " + String(andarAtual));

  delay(2000); // 2 segundos para cada troca de andar

  if (subindo) {
    andarAtual++;
    if (andarAtual > 2) { // Se chegou ao piso superior, inverte a direção
      andarAtual = 2;
      subindo = false;
    }
  } else {
    andarAtual--;
    if (andarAtual < 0) { // Se chegou ao piso inferior, inverte a direção
      andarAtual = 0;
      subindo = true;
    }
  }
}

void atualizaLEDs(int andar) {
  digitalWrite(ledPisoInferior, andar == 0 ? HIGH : LOW);
  digitalWrite(ledPrimeiroAndar, andar == 1 ? HIGH : LOW);
  digitalWrite(ledPisoSuperior, andar == 2 ? HIGH : LOW);
}


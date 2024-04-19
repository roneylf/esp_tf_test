// importe o arquivo c++ gerado na etapa anterior
#include "seno.h"

void setup() {
    Serial.begin(115200);

    while (!modelo_seno.begin()) {
        Serial.print("Erro ao carregar modelo_seno: ");
      //  Serial.println(modelo_seno.getErrorMessage());
    }
}

void loop() {
    for (int i = 0; i < 20; i++) {
        // escolha aleatória entre 0 e pi
        float x = 3.14f * i / 20.0f;
        // criando array
        float input[1] = { x };

        // gerar valor real do seno do número
        float y_true = sin(x);
        // gerando valor do seno a partir do modelo
        float y_pred = modelo_seno.predict(input);

        // printar o valor real do seno e o valor gerador pelo modelo para comparação
        Serial.print("seno de ");
        Serial.print(x);
        Serial.print(" = ");
        Serial.print(y_true);
        Serial.print("\t seno previsto: ");
        Serial.println(y_pred);
        delay(1000);
    }
}
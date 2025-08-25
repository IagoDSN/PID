# Controle PID em Robô Seguidor de Linha

## 📌 Descrição do Projeto
Este projeto apresenta a implementação de um **controlador PID (Proporcional–Integral–Derivativo)** aplicado a um robô seguidor de linha utilizando sensores LDR (Light Dependent Resistor) e motores de corrente contínua.  

O objetivo principal é permitir que o robô acompanhe uma linha no solo de forma estável, corrigindo desvios com rapidez e reduzindo oscilações, de modo a demonstrar a eficiência do controlador PID em sistemas de controle embarcados.

---

## ⚙️ Funcionamento do Sistema

### 1. Sensoriamento
   Dois sensores LDR realizam a leitura da luminosidade do solo. A diferença entre essas leituras indica o desvio em relação à linha a ser seguida.

### 2 Cálculo do Erro
   O erro é definido como:  
   ```cpp
   err = leitura1 - leitura2;
   ```
### 3 A lei de controle do PID é definida por:

$$
u(t) = K_p \cdot e(t) \;+\; K_i \int e(t)\,dt \;+\; K_d \frac{de(t)}{dt}
$$

**Proporcional (Kp):** atua proporcionalmente ao erro atual.<br>
**Integral (Ki):** corrige erros acumulados ao longo do tempo.<br>
**Derivativo (Kd):** reage às variações do erro, antecipando mudanças.<br>

### 4 Ajuste da Velocidade dos Motores
A velocidade base definida pelo parâmetro velo é ajustada conforme a ação do controlador:

```cpp
x1 = velo + pid;
x2 = velo - pid;
```

Dessa forma, quando ocorre um desvio, um motor acelera e o outro desacelera, resultando em uma curva de correção.

## 🛠️ Componentes Utilizados

Placa Arduino (UNO, Nano ou compatível)<br>
2 sensores LDR com resistores para divisor de tensão<br>
2 motores de corrente contínua com ponte H (driver de motor)<br>
Fonte de energia (bateria)<br>

# Escornabot Luci - Electrónica

Este é o esquema de conexións de **Luci**:

![Conexionado Luci](Luci_conexi%C3%B3ns.svg)

Está feito con [Fritzing](https://fritzing.org) e tes o ficheiro editable [dispoñible para descarga](Luci_conexi%C3%B3ns.fzz).

Este é o resumo de conexións entre os pins de cada **dispositivo** (á esquerda) e os pins do **Arduino Nano** (á dereita):

* **Motor Esquerdo**:
	* `IN1 ⟶ D4`
	* `IN2 ⟶ D5`
	* `IN3 ⟶ D6`
	* `IN4 ⟶ D7`
	* `GND ⟶ GND`
	* `VCC ⟶ 5V`
* **Motor Dereito**:
	* `IN1 ⟶ D8`
	* `IN2 ⟶ D9`
	* `IN3 ⟶ D10`
	* `IN4 ⟶ D11`
	* `GND ⟶ GND`
	* `VCC ⟶ 5V`
* **Teclado**:
	* `SIG ⟶ A0`
	* `GND ⟶ GND`
* **Buzzer**:
	* `PIN1 ⟶ GND`
	* `PIN2 ⟶ D2`
* **Neopixel**:
	* `IN  ⟶ D12`
	* `GND ⟶ GND`
	* `VCC ⟶ 5V`
* **PowerBANK-DIY**:
	* `5V  ⟶ 5V`
	* `GND ⟶ GND`

Para poder ter suficientes puntos de conexión para 5V e GND, hai un par de cables (os que están horizontais) que levan estes pins a cada unha das columnas laterais da *mini-breadboard*.

## Arduino Nano

**Luci** emprega un microncontrolador Arduino Nano como *cerebro* para o seu funcionamento. Aquí tes unha referencia dos pins do mesmo:

![Arduino Nano pins](Nano-pinout-complete.png)


## LICENZA

Este traballo está suxeito á licenza [GNU General Public v3.0 License](../LICENSE-GPLV30). Todos os ficheiros multimedia e de datos que non sexan código fonte están suxeitos á licenza [Creative Commons Attribution 4.0 BY-SA license](../LICENSE-CCBYSA40).

Máis información acerca destas licenzas en [licenzas Opensource](https://opensource.org/licenses/) e [licenzas Creative Commons](https://creativecommons.org/licenses/).

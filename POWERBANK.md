# PowerBank-DIY

Unha pequena *intro* aos **PowerBank-DIY** (_**D**o **I**t **Y**ourself_ = Faino Ti Mesma): son kits para fabricarte as túas propias *baterías-recargables* empregando -tipicamente- celas estándar 18650 Li-ion. O kit trae unha caixa contenedora (normalmente de ABS) cunha tapa autopechante. Ten espazo para unha cela 18650 (**NON INCLUÍDA**) e leva incorporada unha pequena circuitería electrónica (con **dous portos USB** distintos) que se encarga de toda a xestión.

![powerbank-diy](imaxes/powerbank-diy.jpg)

A **carga** do PowerBank-DIY efectúase a través do porto **micro-USB**, empregando -por exemplo- un cargador de móbil (dos antigos). A nerxía extráese (**descarga**) a través do porto USB estándar, que proporciona **~5.1V** e **~0.8A**, ideais para **Luci**.


## ELECTRÓNICA

Atopamos que prácticamente tódolos *powerbanks* deste formato están baseados
nos chips electrónicos de dous fabricantes, con características similares e
varios mecanismos de protección incorporados moi interesantes (cortacircuito,
sobre-carga, sobre-descarga etc.):

* [HOTCHIP HT4928S](datasheet/HT4928S-HOTCHIP.pdf)
* [TPOWER TP4333](datasheet/TP4333-TPOWER.pdf)

A caixa contenedora é idéntica (ou prácticamente) entre distintos proveedores (imaxinamos que todos se copian entre si), o cal é moi convinte para poder cumprir algún dos requisitos iniciais. Por certo, a pesar da apariencia, a caixa non é rectangular senón lixeiramente prismática (propio da fabricación por moldes de inxección).

Na carpeta `3D`, o modelo 3D de **Luci** contén un submodelo bastante preciso (dimensionalmente falando) deste PowerBank-DIY.


## MODIFICACIÓN

[Nesta páxina de ROBOteach](https://www.roboteach.es/modificacion-power-bank/) temos unha guía para modificar o PowerBank-DIY e **dotalo dun par de cables dupont**, o que nos permitirá conectalo á nosa **Luci** (ou calqueira outro proxecto).

<img src="https://www.roboteach.es/wp-content/uploads/2021/12/powerBank-mod-007-1024x888.jpg" width="50%"><img src="https://www.roboteach.es/wp-content/uploads/2021/12/powerBank-mod-008-1024x819.jpg" width="50%">

Require dun soldador, un pouco de estaño e algo de habilidade, pero nada esaxerado.


## CONSIDERACIÓNS

Escollimos este sistema porque é económico (o propio kit pode rondar os 2 €), é simple, e funciona bastante ben, proporcionando unha nova e **mellorada experiencia de uso** co Escornabot.

Ademáis, é bastante seguro:

* O contenedor plástico coa tapa autopechante proporciona unha capa de aillamento/protección adicional fronte a unha posible avaría da cela Li-ion 18650.
* O circuitería electrónica trae incorporadas múltiples proteccións:
	* **Anti-curtacircuito**: non pasa nada ainda que conectes os termináis dupont entre sí, xa que a electrónica desconéctase automáticamente ao detectalo (aforro dun fusible!)
	* **Anti-conexión inversa**: non pasa nada se conectamos os cables coa polaridade invertida
	* **Sobre-descarga**: o sistema evita que a batería se descargue mais aló do punto crítico (~3.4V)
	* **Sobre-carga**: tamén evita que se poida sobrecargar, xa que detén o proceso ao alcanzar a voltaxe máxima (~4.2V)
* E tamén algunhas funcións adicionais:
	* **Información de estado**: a través de dous LEDs, para indicarnos que está ocorrendo
	* **Reactivación de cela**: é capaz de recuperar unha cela 18650 totalmente descargada empregando o método *trickle-charge*
	* **Desconexión automática**: cando non hai consumo\*\*, para aforrar enerxía

\*\* Isto acabou converténdose nun [problema con **Luci**](DESENVOLVEMENTO.md#autoapagado), que xa foi resolto.


## LICENZA

Este traballo está suxeito á licenza [GNU General Public v3.0 License](LICENSE-GPLV30). Todos os ficheiros multimedia e de datos que non sexan código fonte están suxeitos á licenza [Creative Commons Attribution 4.0 BY-SA license](LICENSE-CCBYSA40).

Máis información acerca destas licenzas en [licenzas Opensource](https://opensource.org/licenses/) e [licenzas Creative Commons](https://creativecommons.org/licenses/).
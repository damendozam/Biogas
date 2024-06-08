# Materiales de construcción
## Sensores
| Tipo  | Referencia |Descripción|
| ------------- | ------------- |-----|
| CO2   | MQ135  | Se usa para medir la calidad del aire, por lo que mediria la suma de varios gases incluyendo el Metano|
| CH4   | MQ4  | Se usa para solo medir concentracion de Metano
| Temperatura, Humedad, Presión | TARJ BME280 | Se usa para medir temperatura y humedad para ajustar la medición de concentración de gases y de presión |

## Calibración
### Plataforma de adquisición de datos
MDF 40x40 https://www.homecenter.com.co/homecenter-co/product/306118/tablero-40x40-cm-mdf-25-mm-escolar/306118/
Corte laser: Corte Laser Willows
Tornillo para unir base y tapa: https://www.homecenter.com.co/homecenter-co/product/592728/tornillo-estufa-cilindrico-tuerca-m5-x-20-mm2u/592728/

### MQ-135
```
A=-0.3513615;
B=-0.0025928;
C=-0.0010671;
D=0.8343359;

yy=1;
z=20;
u=85;

x=(yy*10**(-(B*z+C*u+D)))**(1/A)

disp(x)
```
### MQ-4
```
A=-0.3532477;
B=-0.0014940;
C=-0.00136591;
D=1.17718719;

yy=0.95;
z=20;
u=65;

x=(yy*10**(-(B*z+C*u+D)))**(1/A)

disp(x)
```
## Tanque de Biodigestor
Conector tanque: https://www.homecenter.com.co/homecenter-co/product/567540/conector-tanque-de-1-pulg-rosca-hembra/567540/

## Cargador de biogas
Materiales utilizados para el invento:

Compresor de nevera: Lo puedes comprar muy barato en una chatarrería
Bidón 220l.: https://amzn.to/3fMCjML

Grifo:  https://amzn.to/3tdVCBo

Filtro con regulador:  https://amzn.to/3EhrJGI

Racores para el bidón:  https://amzn.to/3GiGE5d

Válvula y tubo Gas:  https://amzn.to/3fP7g2C

Presostato sin modificar y válvula de alivio de presión:  https://amzn.to/3UfuDkZ

Tubo neumático y racores:  https://amzn.to/3UCLWgd


# Banco de pruebas calibración sensores de gas
## Bomba de vacio
https://articulo.mercadolibre.com.co/MCO-2207965998-bomba-electrica-intex-azul-_JM?matt_tool=70147493&matt_word=&matt_source=google&matt_campaign_id=14633851809&matt_ad_group_id=122277564930&matt_match_type=&matt_network=g&matt_device=c&matt_creative=545410559217&matt_keyword=&matt_ad_position=&matt_ad_type=pla&matt_merchant_id=271865458&matt_product_id=MCO2207965998&matt_product_partition_id=2163484155018&matt_target_id=aud-2199636707971:pla-2163484155018&cq_src=google_ads&cq_cmp=14633851809&cq_net=g&cq_plt=gp&cq_med=pla&gad_source=1&gclid=Cj0KCQjwxqayBhDFARIsAANWRnSR_-6E2IsPF67Obf33ysD9fS35cblABTZvo1QI3dMpGl2bcRwtiUEaAjs6EALw_wcB

## Concentración de gases

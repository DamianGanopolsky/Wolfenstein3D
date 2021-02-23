# Wolfenstein 3D - TP final
## Taller de Programación I
### 2do cuatrimestre de 2020

### Correcciones hechas para la entrega final  
Se encuentran en la carpeta Docs del repositorio  
\
**Tutor:** Martín Di Paola \
\
**Integrantes:** \
Bauni Chiara - 102981 - cbauni@fi.uba.ar\
Damián Ganopolsky - 101168 - dganopolsky@fi.uba.ar\


## Documentación
- [Manual de usuario](https://github.com/DamianGanopolsky/TDPWolfenstein/blob/main/Docs/Manual_de_Usuario.pdf)
- [Documentación Técnica](https://github.com/DamianGanopolsky/TDPWolfenstein/blob/main/Docs/Documentacion_tecnica.pdf)
- [Manual de proyecto](https://github.com/DamianGanopolsky/TDPWolfenstein/blob/main/Docs/Manual_de_Proyecto.pdf)

## El juego

![alt text](https://github.com/DamianGanopolsky/TDPWolfenstein/blob/main/Docs/Captura%20de%20pantalla%20de%202021-02-23%2019-35-59.png "Pantalla de comienzo")

![alt text](https://github.com/DamianGanopolsky/TDPWolfenstein/blob/main/Docs/Captura%20de%20pantalla%20de%202021-02-23%2019-36-29.png "Vista al iniciar el juego")

![alt text](https://github.com/DamianGanopolsky/TDPWolfenstein/blob/main/Docs/Captura%20de%20pantalla%20de%202021-02-23%2019-36-41.png "Barra inferior con informacion del jugador")

![alt text](https://github.com/DamianGanopolsky/TDPWolfenstein/blob/main/Docs/Captura%20de%20pantalla%20de%202021-02-23%2019-37-58.png "Vista enemigo portando cañon de cadena")

![alt text](https://github.com/DamianGanopolsky/TDPWolfenstein/blob/main/Docs/Captura%20de%20pantalla%20de%202021-02-23%2019-39-38.png "Vista enemigo muerto")

![alt text](https://github.com/DamianGanopolsky/TDPWolfenstein/blob/main/Docs/Captura%20de%20pantalla%20de%202021-02-23%2019-41-51.png "Pantalla final")

## El editor

![alt text](https://github.com/DamianGanopolsky/TDPWolfenstein/blob/main/Docs/Captura%20de%20pantalla%20de%202021-02-23%2019-49-37.png "Pantalla de comienzo")

![alt text](https://github.com/DamianGanopolsky/TDPWolfenstein/blob/main/Docs/Captura%20de%20pantalla%20de%202021-02-23%2019-49-58.png "VIsta para editar")

## Instalación
1- Abrir una terminal en la raíz del juego\
2- Ejecutar el siguiente archivo: 
```
./install.sh
```
3- Si no se poseen las dependencias y desea instalarlas junto al juego presione la opcion 3. \
Si ya posee las dependencias y unicamante desea instalar el juego presione la opcion 2. \

4- Una vez instalado el juego entre a la carpeta build. \
Para ejecutar el editor utilice el siguiente comando: 
```
./editor
```
Para ejecutar el servidor utilice el siguiente comando: 
```
./server <port> <map_name>  
e.g: ./server 8082 Maze_2
```
Para ejecutar el servidor utilice el siguiente comando: 
```
./client <host> <port> <player_name>  
e.g: ./client 127.0.0.1 8082 Jorge
```





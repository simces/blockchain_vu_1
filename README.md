# Blokų grandinių technologijos, pirma užduotis: Hash generatoriaus kūrimas.
## Užduoties formuluotė
* Maišos funkcijos įėjimas (angl. input) gali būti bet kokio dydžio simbolių eilutė (angl. string).
* Maišos funkcijos išėjimas (angl. output) visuomet yra to paties, fiksuoto, dydžio rezultatas (pageidautina 256 bit'ų ilgio, t.y., 64 simbolių hex'as).
* Maišos funkcija yra deterministinė, t. y., tam pačiam įvedimui (input'ui) išvedimas (output'as) visuomet yra tas pats.
* Maišos funkcijos reikšmė/kodas (hash‘as) bet kokiai input'o reikšmei yra apskaičiuojamas greitai - efektyviai.
* Iš hash funkcijos rezultato (output'o) praktiškai neįmanoma atgaminti pradinio įvedimo (input'o).
* Maišos funkcija yra atspari "kolizijai" (angl. collision resistance), t.y., praktiškai neįmanoma surasti tokių dviejų skirtingų argumentų, kad jiems gautume tą patį hash'ą
* Bent minimaliai pakeitus įvedimą, pvz.vietoj "Lietuva" pateikus "lietuva", maišos funkcijos rezultatas-kodas turi skirtis iš esmės, t.y., tenkinamas taip vadinamas lavinos efektas. 

## Programos paleidimas
* Atsisiųsti programos kodą iš "releases";
* Kodą išarchyvuoti naujame aplanke;
* Aplanką atsidaryti naudojantis Jums patinkantį IDE, arba terminalą (pavaizduota apačioje).


![image](https://user-images.githubusercontent.com/78842398/152876688-05ffba81-0197-4ba2-a969-c37f1c8d8d0a.png)

* Kodą sukompiliuoti, o po to paleisti .exe failą naudojantis šias komandas:

```
g++ main.cpp functions.cpp includes/md5.cpp includes/sha1.cpp includes/sha256.cpp -o programa
```
```
./programa
```

## Eksperimentinis tyrimas-analizė
* ### Palyginame dviejų inputų gaunamus hex'us, žiūrime ar jie skirtingi:
![image](https://user-images.githubusercontent.com/78842398/152878215-cd0a0bed-f1e1-441a-9926-34f27c9c9ce8.png)
* ### Tikriname dviejų vienodų inputų gaunamus rezultatus, žiūrime, ar jie vienodi:
```
Your input: qwertyuiop. c8dafbcc40445193711dddfbc5635d77fc4d71660c4c09bd771e8574c8c8aae6
```
 #### Iš naujo paleidžiame programą ir įvedame tokį patį tekstą, žiūrime į rezultatus:
```
Your input: qwertyuiop. c8dafbcc40445193711dddfbc5635d77fc4d71660c4c09bd771e8574c8c8aae6
```
![image](https://user-images.githubusercontent.com/78842398/152880685-9b8fff38-d5c9-4495-8876-d694f65cdfd7.png)

* ### Tikriname, ar maišos funkcija tenkina "Avalanche effect":

![image](https://user-images.githubusercontent.com/78842398/152880974-9c8bb57b-30b3-4e40-b755-94848800037f.png)












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
```
Your input: h
2c5f1b1bd70ac6cce8a4c66682b5d7713d6082824e7793335f1b3dd793c6e888
Your input: m
a4d793c682b571aac682a4446093b55f1b4e60935f88a444602c4ee8a4d7f999
```
* ### Tikriname dviejų vienodų inputų gaunamus rezultatus, žiūrime, ar jie vienodi:
```
Your input: qwertyuiop. c8dafbcc40445193711dddfbc5635d77fc4d71660c4c09bd771e8574c8c8aae6
```
 #### Iš naujo paleidžiame programą ir įvedame tokį patį tekstą, žiūrime į rezultatus:
```
Your input: qwertyuiop. c8dafbcc40445193711dddfbc5635d77fc4d71660c4c09bd771e8574c8c8aae6
```
* ### Lyginame du inputus sudarytus iš 1500 simbolių, kurie skiriasi tik vienu simbolyje maždaug viduryje teksto:
![image](https://user-images.githubusercontent.com/78842398/152882767-a62ece4a-d20c-4af2-8884-f4b4fa184243.png)
```
test1.txt: 2c55d77793cc4eee0acc4eee0a33b55571aa2ccce81193335f1193335f880aaa
test2.txt: 1ab45e446f0a09b5600999b4a8e791bb3c42c6771a2ab9bd71b4e7924de799a2
```

* ### Tikriname, ar maišos funkcija tenkina "Avalanche effect":

```
                               hex     bits
Minimum difference in pairs:   48      61
Maximum difference in pairs:   64      171
Average difference in pairs:   93.8%   50.1%
```

## Išvada











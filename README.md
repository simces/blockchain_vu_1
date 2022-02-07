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






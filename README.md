<h1>1: Работа със SVG файлове</h1>
<p>В рамките на този проект трябва да се разработи приложение, което работи с SVG файлове.
Приложението трябва да може да зарежда фигури от файла, да извършва върху тях дадени
операции, след което да може да записва промените обратно на диска.
За улеснение, в рамките на проекта ще работим само с основните фигури (basic shapes) в SVG.
Приложението ви трябва да поддържа поне три от тях. Например можете да изберете да се
поддържат линия, кръг и правоъгълник. За повече информация за това кои са базовите фигури,
вижте https://www.w3.org/TR/SVG/shapes.html.
<p>Също така, за улеснение считаме, че координатната система, в която работим е тази по
подразбиране: положителната ос X сочи надясно, а положителната ос Y сочи надолу.
vДизайнът на приложението трябва да е такъв, че да позволява при нужда лесно да можете да
добавите поддръжка на нови фигури.
<p>Когато зареждате съдържанието на един SVG файл, трябва да прочетете само фигурите, които
приложението ви поддържа и можете да игнорирате всички останали SVG елементи.
<p>След като заредите фигурите, потребителят трябва да може да изпълнява дадените в
следващия раздел команди, които добавят, изтриват или променят фигурите.
<p>Когато записвате фигурите във файл, трябва да генерирате валиден SVG файл
<p>Операции
<p>Print Извежда на екрана всички фигури.
<p>Create Създава нова фигура.
<p>Erase Изтрива фигура
<p>Translate Транслира една или всички фигури. Ако потребителят не посочи конкретна
фигура се транслират всички фигури; ако се посочи конкретна – променя се
само тя.
<p>Within Извежда на екрана всички фигури, които попадат в даден регион.
<p>Потребителят може да укаже какъв да бъде регионът – кръг или
правоъгълник
<p>Примерен SVG файл figures.svg
<p><?xml version="1.0" standalone="no"?>
<p><!DOCTYPE svg PUBLIC "-//W3C//DTD SVG 1.1//EN"
 <p>"http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd">
<p><svg>
 <p><rect x="5" y="5" width="10" height="10" fill="green" />
 <p><circle cx="5" cy="5" r="10" fill="blue" />
 <p><rect x="100" y="60" width="10" height="10" fill="red" />
<p></svg>
<p> Пример за работа на програмата
<p>> open figures.svg
<p>Successsfully opened figures.svg
<p>> print
<p>1. rectangle 5 5 10 10 green
<p>2. circle 5 5 10 blue
<p>3. rectangle 100 60 10 10 red
<p>> create rectangle -1000 -1000 10 20 yellow
<p>Successfully created rectangle (4)
<p>> print
<p>1. rectangle 1 1 10 20 green
<p>2. circle 5 5 10 blue
<p>3. rectangle 100 60 10 10 red
<p>4. rectangle 1000 1000 10 20 yellow
<p>> within rectangle 0 0 30 30
<p>1. rectangle 5 5 10 10 green
<p>2. circle 5 5 10 blue
<p>> within circle 0 0 5
<p>No figures are located within circle 0 0 5
<p>> erase 2
<p>Erased a circle (2)
<p>> erase 100
<p>There is no figure number 100!
<p>> print
<p>1. rectangle 5 5 10 10 green
<p>2. rectangle 100 60 10 10 red
<p>3. rectangle 1000 1000 10 20 yellow
<p>> translate vertical=10 horizontal=100
<p>Translated all figures
<p>> print
<p>1. rectangle 105 15 10 10 green
<p>2. rectangle 200 70 10 10 red
<p>3. rectangle 1100 1010 10 20 yellow
<p>> save
<p>Successfully saved the changes to figures.svg
<p>> exit
<p>Exit

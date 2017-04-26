# sort-tester
Projeto desenvolvido em parceria com o Erick Akio, para a disciplina de AED.

Compara os tempos de execução dos seguintes algoritmos:

	Quicksort,
	Heapsort,
	Mergesort,
	Sort C++,
	Quicksort C.
  
O estudo empírico foi feito da seguinte maneira:
	
Para cada um dos algoritmos, foram feitas várias medições de tempo utilizando tamanhos diferentes de vetores:

		10000, 30000, 90000,
		270000, 810000,	2430000,
		7290000, 21870000, 65610000.
	
Para cada tamanho de vetor, usamos 6 seeds diferentes na geração de seus elementos.

O resultado final está no arquivo output.txt, onde estão as medições de tempo dos métodos.

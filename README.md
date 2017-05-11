# sort-tester

Projeto desenvolvido em parceria com o Erick Akio, para a disciplina de AED.

## O projeto

Compara os tempos de execução dos seguintes algoritmos:

	Quicksort (pivo mediano),
	Heapsort,
	Mergesort,
	Sort C++,
	Quicksort C.

Os 3 primeiros algoritmos foram implementados pelos alunos, enquanto os ultimos 2 foram utilizados de bibliotecas

### Metodologia

O estudo empírico foi feito da seguinte maneira:
	
Para cada um dos algoritmos, foram feitas várias medições de tempo utilizando tamanhos diferentes de vetores:

	10000, 30000, 90000,
	270000, 810000,	2430000,
	7290000, 21870000, 65610000.
	
Para cada tamanho de vetor, usamos 6 seeds diferentes na geração de seus elementos. É importante observar que as seeds utilizadas foram as mesmas para todos os métodos, então todos foram testados com exatamente os mesmos vetores.

A análise do tempo para cada método foi feita calculando a média de tempo que levou para ordenar cada tamanho de vetor, sendo que cada tamanho de vetor foi testado com 6 seeds diferentes.

## Testes de execução

O exemplo a baixo é o resultado da execução do algoritmo em um computador pessoal. Cada linha representa uma seed diferente, e cada coluna um tamanho de vetor diferente. O tempo foi medido em ms.

	HeapSort: 
	3, 11, 37, 133, 433, 1592, 6073, 20781, 70530, 
	3, 11, 38, 138, 463, 1628, 5871, 19863, 66286, 
	3, 11, 37, 126, 424, 1597, 5515, 19169, 67498, 
	3, 11, 37, 128, 456, 1602, 5700, 18942, 65685, 
	3, 11, 37, 125, 442, 1570, 5459, 18805, 66256, 
	3, 11, 37, 131, 431, 1649, 5708, 19289, 65670, 

	QuickSort: 
	2, 7, 22, 74, 237, 759, 2428, 7690, 24183, 
	2, 6, 22, 72, 239, 759, 2443, 7642, 24091, 
	2, 6, 22, 73, 235, 773, 2414, 7735, 24360, 
	2, 8, 23, 73, 237, 752, 2447, 7842, 24144, 
	2, 6, 22, 74, 239, 763, 2435, 7864, 24249, 
	2, 6, 22, 72, 235, 753, 2473, 7763, 24182, 

	MergeSort: 
	3, 9, 30, 98, 344, 1037, 3409, 10709, 34132, 
	2, 8, 29, 97, 319, 1037, 3346, 10794, 34324, 
	2, 8, 29, 97, 325, 1040, 3377, 10896, 34719, 
	2, 8, 30, 98, 335, 1121, 3447, 10882, 34750, 
	2, 10, 29, 100, 322, 1056, 3351, 10765, 34363, 
	3, 10, 32, 97, 316, 1028, 3302, 10743, 34288, 

	SortC++: 
	3, 10, 32, 108, 349, 1146, 3667, 11769, 37322, 
	3, 9, 33, 108, 353, 1147, 3638, 11943, 38003, 
	3, 10, 33, 108, 353, 1154, 3737, 11710, 37824, 
	3, 9, 32, 108, 351, 1187, 3665, 11967, 36987, 
	3, 10, 33, 109, 351, 1153, 3686, 11922, 37678, 
	3, 9, 32, 108, 353, 1151, 3663, 11978, 37426, 

	QuickSortC: 
	2, 7, 23, 76, 256, 852, 2634, 8574, 26563, 
	2, 6, 22, 75, 248, 801, 2577, 8335, 26610, 
	2, 7, 23, 75, 246, 802, 2579, 8357, 26591, 
	2, 7, 22, 75, 246, 803, 2578, 8344, 26627, 
	2, 6, 22, 75, 246, 801, 2575, 8335, 26581, 
	2, 6, 22, 75, 246, 801, 2575, 8340, 26553, 

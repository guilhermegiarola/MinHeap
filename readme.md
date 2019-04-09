The algorithm "heapify" above works for every node above the "leaves of the heap".
	So, we have:
	
	For the first level of numbers above, we have (n/2) * height (h) iterations.
	For the second level, we have (n/4) * (h+1) iterations, and so on.
	Therefore, we have:
	
	(n/2)*0 + (n/4)*1 + (n/8)*2 + (n/16)*3... + 1*h. (h being log n)
	
	We know that (1/2) + (1/4) + (1/8) +... = sum(1/2^n) from i = 1 to infinity.
	
	.: So, the results of sum(i/2^n) is equal to 1 (MONTEIRO, Martha). (https://www.ime.usp.br/~martha/somas-infinitas.pdf)
	
	Using Taylor's series, we can solve the following equation: https://stackoverflow.com/questions/9755721/how-can-building-a-heap-be-on-time-complexity
	
	.: Therefore, we have that the complexity is equal to n.

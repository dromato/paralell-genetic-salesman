# paralell-genetic-salesman #
=========================

Implementation of Genetic Algorithm used to solve Travelling Salesman Problem.
Paralellized using OpenMP (probably in not very correct way... It's my first try with OpenMP).

Example output.

Data:
* Number of cities - 100
* Generations - 15k
* Population size - 40
* Mutation rate - 5%
* Number of elites preserved - 2

Results:


| Generation | Mean of gen. | Best of gen. |
|------------|--------------|--------------|
| 0 | 8683.69 | 4994.16 |
| 50 | 9676.08 | 3724.89 |
| 100 | 12573.6 | 3137.19 |
| 150 | 7599.37 | 2837.22 |
| 200 | 8981.1 | 2639.86 |
| 250 | 6157.73 | 2530.78 |
| 300 | 5615.72 | 2289.29 |
| 350 | 5283.17 | 2127.32 |
| 400 | 8303.31 | 2073.82 |
| 450 | 5464.89 | 1965.07 |
| 500 | 7630.24 | 1866.74 |
| 1000 | 4282.95 | 1463.5 |
| 1500 | 3349.5 | 1320.45 |
| 2000 | 2444.22 | 1187.39 |
| 2500 | 2022.88 | 1119 |
| 3000 | 4331.43 | 1082.86 |
| 3500 | 4221.26 | 1049.13 |
| 4000 | 2335.44 | 999.557 |
| 4500 | 3907.04 | 969.25 |
| 5000 | 2417.8 | 956.677 |
| 5500 | 2803.07 | 940.221 |
| 6000 | 2797.55 | 930.561 |
| 6500 | 3663.74 | 914.836 |
| 7000 | 3668.26 | 906.981 |
| 8000 | 3228.73 | 893.834 |
| 9000 | 2688.91 | 888.497 |
| 10000 | 2223.49 | 876.403 |
| 11000 | 2931.86 | 875.204 |
| 12000 | 3507.05 | 871.828 |
| 13000 | 2488.14 | 869.118 |
| 14000 | 2104.88 | 869.118 |
| 15000 | 3550.99 | 865.85 |

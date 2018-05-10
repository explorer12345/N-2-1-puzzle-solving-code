# N-2-1-puzzle-solving-code
C++ code for solving N^2-1 puzzle  

Input Format:
First line contains N
The input will consist of N^2 space-separated integers in row-major order.

Note: 0 in input denotes empty square.

Output Format:
First line is number of moves to reach the final state
From the second line - the move(s) is(are) printed in order with space separation starting from given configuration to the final configuration. Move donotes movement of the empty square.
R - Right, U - Up, D- Down, L- Left

Print -1 if not solvable

Code description:
This code uses A* algorithm to solve the puzzle. It uses manhattan heuristic to implement the A* algorithm. Due to mnahattan heuristic the code solves the N=3 puzzle within seconds but takes a lot of time for higher N-valued puzzles. 



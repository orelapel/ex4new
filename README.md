# ex4new
# SEARCHING ALGORITHMS SERVER
The program was written in an advanced programming course in 2020.


# AUTHORS
-Orel Lichtenstein (orellicht@gmail.com)
-Noa Rotem(noavvv@gmail.com)


# INTRODUCTION
The project has been written on CLion environment, in C++.
Writing this program made us learn about various design patterns, the use of threads and the use of generic types

# DESCRIPTION
The project opens a server that listens to 10 clients in parallel
Each client sends a problem (a matrix with a starting point and goal point) and the server solve it and return the
solution back to the client.
But before the server will start resolving the problem, it will checks to see if the solution exists in our cache,
if the soloution exist-the server send it to the client ,other-  the server will solve the problem and send the solution back to the client
Solving the problem is done by four search algorithms:
- A* (A Star)
- Best First Search
- DFS
- BFS

We looked at all four search algorithms for each of the 10 matrices considering the number of vertices in the path and the price of the trajectory
and we found that the A Star is the best algorithm Considering this parameters.
Therefore, in the main function we made the parallel server use the A Star algorithm to solve the client's problems.

*The project also support in serial server that run each time on one client.

# LINKS
- Our link to GitHub project:
https://github.com/orelapel/ex4new

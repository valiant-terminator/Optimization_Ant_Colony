# Optimization_Ant_Colony
A C language program to optimize the gas pipeline path to solve travelling salesman situation using Ant Colony Optimization Algorithm

This program makes and optimizes a single path for gas pipeline laying including all the stations of the pipeline.

This program includes a corodinate matrix with having all the coordinates of the stations that the pipeline have to visit.
                                                    |
                                                    |
                                                    V
Then from the coordinate matrix a distance matrix is calculated from the eucledian distance formula from each point to each other point.
                                                    |
                                                    |
                                                    V
From the Distance Matrix the Eta matrix, Pheromone Matrix are calculated to calculate the visibility for each Ant.
                                                    |
                                                    |
                                                    V
Now 5 ants were initialized, and their respective paths were calculated, with their respective distances they travelled.
                                                    |
                                                    |
                                                    V
Now the path with the least path distance is chosen and according to the parameters the number of booster pumps are calculated.

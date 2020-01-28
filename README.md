# Neural networks for Self-Driven Cars

Project where several Neural Networks competes each other to learn to drive on an obstacle track.

# About the Project

The idea is to use an "artificial selection" to evolve the weights of various neural networks, in order to find the best combination and thus obtain the best behavior for cars.

The simulator was built from scratch (without engines) using the **Programming Interface Gaming (PIG)** graphics library, which in turn is based on the traditional **Simple DirectMedia Layer (SDL)**.

# The Artificial Neural Network used was a Perceptron Multilayer with 3 layers!

   - Input layer with 18 sensors + 1 bias, totaling 19 neurons
   - Hidden layer with 6 neurons + 1 bias, totaling 7 neurons
   - Output layer with 4 neurons (Accelerate, Reverse, Turn Left, Turn Right)
   - The activation function used in all neurons was ReLU.
   - The learning method is commonly called "Random Mutations".
   - The population size I used was 1000 individuals.
   - The learning time varied between 5 ~ 20 minutes.



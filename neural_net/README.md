# Feedforward Neural Network with Back Propogation
This takes given example data from information in figure 18.3
(excluding hungry attribute) from textbook cited in top of prob1.cpp
(artificial intelligence modern approach - by russell) and implements
& trains a feedforward neural net using the back prop algorithm in the same textbook
(figure 18.24)

## Details
After initializing example data from examples.txt, the training on
the neural network begins. Weights between each neuron are initially
assigned a random floating point number (at the start of each training
iteration throughout the example data). Values for each neuron are then 
calculated and fed forward before the neuron is activated. Once the output
neuron is activated, error is calculated and backpropogated through the weights
of the network. This is a form of supervised learning. 

It's worth noting that this project is meant to be a conceptual tool used to 
assist in understanding of neural networks. In reality, the example set is much
too small to be of reliable accuracy.

Development was done on linux.
## Use
```
make
./nndemo
...
make clean
```
## Sources
More specific sources are cited in comments.

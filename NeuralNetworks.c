#include <gsl/gsl_rng.h>
#include <math.h>
#include <time.h>

#define LEARNING_RATE    (0.1)
#define INITIAL_WEIGHT   (1.0)
#define BIAS                1



#define HiddenActivation(X)        relu(X)
#define HiddenOutput(X)          relu(X)

typedef struct neuron
{
    double* Weight;
    double  Error;
    double  Output;

    int NumberOfConnections;

}   Neuron;

typedef struct layer
{
    Neuron* Neurons;

    int NumberofNeurons;

}   Layer;

typedef struct redeNeural
{
    Layer  EnterLayer;
    Layer* HiddenLayer;
    Layer  OutputLayer;

    int HiddenNumber;

}   NeuralNetowk;

    gsl_rng*        Generator;

double func(double X)
{
    if(X == 0)
    {
        return 0;
    }
    if(X < 0)
    {
        return -1;
    }
    if(X > 0)
    {
        return 1;
    }
}

double relu(double X)
{
    if(X < 0)
    {
        return 0;
    }
    else
    {
        if(X < 10000)
        {
            return X;
        }
        else
        {
            return 10000;
        }
    }
}

double reluDx(double X)
{
    if(X < 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

void RNA_CopyVectorForLayers(NeuralNetowk* Network, double* Vector)
{
    int j,k,l;

    j = 0;

    for(int i=0; i<Network->HiddenNumber; i++)
    {
        for(k=0; k<Network->HiddenLayer[i].NumberofNeurons; k++)
        {
            for(l=0; l<Network->HiddenLayer[i].Neurons[k].ConectionsNumber; l++)
            {
                Network->HiddenLayer[i].Neurons[k].Weight[l] = Vector[j];
                j++;
            }
        }
    }

    for(k=0; k<Network->OutputLayer.NumberofNeurons; k++)
    {
        for(l=0; l<Network->OutputLayer.Neurons[k].ConectionsNumber; l++)
        {
            Network->OutputLayer.Neurons[k].Weight[l] = Vector[j];
            j++;
        }
    }
}

void RNA_CopyLayersForVector(NeuralNetowk* Network, double* Vector)
{
    int j,k,l;

    j = 0;

    for(int i=0; i<Network->HiddenNumber; i++)
    {
        for(k=0; k<Network->HiddenLayer[i].NumberofNeurons; k++)
        {
            for(l=0; l<Network->HiddenLayer[i].Neurons[k].ConectionsNumber; l++)
            {
                Vector[j] = Network->HiddenLayer[i].Neurons[k].Weight[l];
                j++;
            }
        }
    }

    for(k=0; k<Network->OutputLayer.NumberofNeurons; k++)
    {
        for(l=0; l<Network->OutputLayer.Neurons[k].ConectionsNumber; l++)
        {
            Vector[j] = Network->OutputLayer.Neurons[k].Weight[l];
            j++;
        }
    }
}



void RNA_Copy(NeuralNetowk* Network, double* InitialVector)
{
    int i;

    for(i=0; i<Network->InitialLayer.QuantidadeNeuronios - BIAS; i++)
    
        Network->InitialLayer.Neurons[i].Output = InitialVector[i];
    }
}

int RNA_NumberOfWeight(NeuralNetowk* Network)
{
    int Sum = 0;
    for(int i=0; i<Network->NumberOfHiddens; i++)
    {
        for(int j=0; j<Network->HiddenLayer[i].NumberOfNeurons; j++)
        {
            Sum = Sum + Network->HiddenLayer[i].Neurons[j].NumberOfConnections;
        }
    }

    for(int i=0; i<Network->OutputLayer.NumberOfNeurons; i++)
    {
        Sum = Sum + Network->OutputLayer.Neurons[i].NumberOfConnections;
    }
    return Sum;
}

void RNA_CopyOutput(NeuralNetwork* Network, double* OutputVector)
{
    int i;

    for(i=0; i<Network->OutputLayer.NumberOfNeurons; i++)
    {
        OutputVector[i] = Network->OutputLayer.Neurons[i].Output;
    }
}

// stoped here


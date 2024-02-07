import numpy as np
import matplotlib.pyplot as plt
from sklearn.datasets import make_classification
import pandas as pd

X, y = make_classification(n_features=2, n_redundant=0, n_informative=2, random_state=1, n_clusters_per_class=2, class_sep=0.5)


plt.scatter(X[:, 0], X[:, 1], c=y)
plt.show()

def entropy(Y: pd.Series) -> float:
    """
    Function to calculate the entropy
    """
    # Count the occurrences of each unique value in the series
    value_counts = Y.value_counts()

    # Calculate the total number of samples
    total_samples = len(Y)

    # Calculate the entropy
    entropy = 0
    for count in value_counts:
        probability = count / total_samples
        entropy -= probability * np.log2(probability)

    return entropy

y_series = pd.Series(y)

# Calculate the entropy
dataset_entropy = entropy(y_series)

print("Entropy of the dataset:", dataset_entropy)